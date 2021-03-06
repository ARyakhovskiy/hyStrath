
// --- Output at write time
rarefactionParameters().write();
transport().write();
composition.write();
volVectorField F = mhd->F(U);
volScalarField Qmag = mhd->Q(U);
F.write();
Qmag.write();
//mhd->conductivity().write();

//- Write diffusion fluxes
if(not hyLight) 
{
    volVectorField sumDiffusiveFluxes = speciesDiffusion().sumDiffusiveFluxes();
    sumDiffusiveFluxes.write();
    forAll(Y, speciei) 
    {
        volVectorField Jnc = speciesDiffusion().J(speciei);
        Jnc.write();
        
        volVectorField Jc
        (
            IOobject
            (
                "J_" + composition.species()[speciei],
                runTime.timeName(),
                mesh,
                IOobject::NO_READ,
                IOobject::NO_WRITE
            ),
            speciesDiffusion().Jcorr(speciei)
        );
        Jc.write();
    }
}
         
if(not downgradeSingleT)
{
    if(not hyLight) 
    {
        thermo.T().write();
        
        if(noSolvedVibEq > 1)
        {
            thermo.Tv().write();
        }
    }
}

if(downgradeSingleTv)
{
    thermo.Tv().write();
}


if(hyDev)
{
    //tauMC.write();
    if(heatFluxVector)
    {
        heatFluxVector->write();
    }
}

if(writeHeatFluxes)
{
    if(convectiveHeatFlux and diffusiveHeatFlux)
    {
        *convectiveHeatFlux = turbulence->kappaEff()*fvc::grad(thermo.Tt());
        forAll(Y, speciei)
        {
            *convectiveHeatFlux += transport().kappave(speciei)*fvc::grad(composition.Tv(speciei));
        }

        *diffusiveHeatFlux = speciesDiffusion().multiSpeciesHeatSource();

        convectiveHeatFlux->write();
        diffusiveHeatFlux->write();
    }
}

if(writeWallHeatFlux) 
{       
    surfaceScalarField heatFlux = -fvc::interpolate(turbulence->alphaEff())*fvc::snGrad(et);
    forAll(Y, speciei)
    {
        heatFlux -= fvc::interpolate(transport().alphave(speciei))*fvc::snGrad(hevk[speciei]);
    }   

    const surfaceScalarField::Boundary& patchHeatFlux = heatFlux.boundaryField();

    Info<< "\nWall heat fluxes [W]" << endl;
    forAll(patchHeatFlux, patchi)
    {
        if (isA<wallFvPatch>(mesh.boundary()[patchi]))
        {
            wallHeatFlux.boundaryFieldRef()[patchi] = patchHeatFlux[patchi];

            Info<< "Patch " << patchi
                << " named " << patchHeatFlux[patchi].patch().name()
                << ": "
                << gSum
                   (
                       mesh.magSf().boundaryField()[patchi]
                      *patchHeatFlux[patchi]
                   )
                << endl;
        }
    }
    Info<< endl;

    wallHeatFlux.write();
}


if(reaction->lookupOrDefault<bool>("applyChangesAtWriteTime", false))
{
    return true;
}

if(reaction->lookupOrDefault<bool>("applyChangesAtWriteTimeAndWait", false))
{
    label restartIn = reaction->lookupOrDefault<label>("restartIn", 120);
    
    Info << "Waiting " << restartIn << " seconds before restart\n\n\n";
         
    Foam::sleep(restartIn);     
    
    return true;
}

