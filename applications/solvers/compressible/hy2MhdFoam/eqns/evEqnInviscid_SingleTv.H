
thermalRelaxModelVT().correct();

// --- Solve vibrational energy equations, INVISCID
volScalarField QVT = thermalRelaxModelVT().QVT(0);
volScalarField QCV = reaction->Scv(0) + reaction->Seiir(0);

for(int speciei = 1; speciei < noSolvedVibEq; speciei++)
{
    if(composition.noVibrationalTemp(speciei) != 0)
    {
        QVT += thermalRelaxModelVT().QVT(speciei);
    }
    
    if(composition.particleType(speciei) == 2)
    {
        QCV += reaction->Scv(speciei) + reaction->Seiir(speciei);
    }
} 

if(containsElectrons)
{
    thermalRelaxModelHE().correct();
    QVT += thermalRelaxModelHE().QHE();
}

fvScalarMatrix rhoEvInviscid
(
    fvm::ddt(rhoEv) 
  + fvc::div(phiEvk[0]) 
  - QVT
  - QCV
);

if(containsElectrons)
{ 
    rhoEvInviscid += (fvc::grad(composition.pP("e-")) & U);
}

rhoEvInviscid.solve
(
    mesh.solver("rhoEv")
);

ev.correctBoundaryConditions();
rhoEv.boundaryFieldRef() = rho.boundaryField()*ev.boundaryField();
     
thermo.correctHEVK();

ev = rhoEv/rho;

