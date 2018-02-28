# hyStrath

##### Hypersonic code developments in OpenFOAM released under license GPL-3.0
###### Hosting the *hyFoam* (supersonic combusting flows) and *hy2Foam* (hypersonic reacting flows) CFD solvers  
###### Hosting the *dsmcFoam+* (direct simulation Monte Carlo) solver  

---  
## Available for OpenFOAM versions

###### Master branch (CFD and DSMC)  
+ v1612+: https://www.openfoam.com/releases/openfoam-v1612+  

###### OF-2.4.0 branch (CFD only)   
+ 2.4.0-MNF: https://github.com/MicroNanoFlows/OpenFOAM-2.4.0-MNF  
+ 2.4.0: http://openfoam.org/download/2-4-0-ubuntu  
+ 2.3.0: http://openfoam.org/download/2-3-0-ubuntu  



**Please check out the [_hyStrath_ Wiki page](https://github.com/vincentcasseau/hyStrath/wiki)**   

**Pre-requirements: Good knowledge of OpenFOAM and the rhoCentralFoam/reactingFoam solvers**  


<div class="paragraph"><p><br>
<br></p></div>


###### Installation  
OF-v1612+:  
+ git clone https://github.com/vincentcasseau/hyStrath.git --branch master --single-branch && cd hyStrath/   
+ CFD & DSMC: ./install-all.sh _#nCPUs_ > logInstall &
+ CFD: ./install-CFD.sh _#nCPUs_ > logInstall &
+ DSMC: ./install-DSMC.sh _#nCPUs_ > logInstall &   
 

OF-2.4.0-MNF, OF-2.4.0, OF-2.3.0:  
+ git clone https://github.com/vincentcasseau/hyStrath.git --branch OF-2.4.0 --single-branch && cd hyStrath/   
+ CFD: ./install.sh


<div class="paragraph"><p><br>
<br></p></div>

---  
## [Release history](https://github.com/vincentcasseau/hyStrath/wiki/Release-history)  
### 17 Feb 2018: 'Concordia' release, Master branch  
+ CFD upgrade  

#### 5 Dec 2017: 'Cairn' release, Master branch  
+ Introduction of the _dsmcFoam+_ solver  


<div class="paragraph"><p><br>
<br></p></div>

---
## [Publications](https://github.com/vincentcasseau/hyStrath/wiki/Publications)


<div class="paragraph"><p><br>
<br></p></div>

---  

###### CFD  
Lead developer: Dr Vincent Casseau    
Contributors: Daniel E.R. Espinoza and Dr Thomas J. Scanlon              
Acknowledgements: Jimmy-John O.E. Hoste, Dr Rodrigo C. Palharini and Prof Richard E. Brown
  
   
###### DSMC        
Current developers: Dr Craig White and Dr Vincent Casseau    
Contributors: Daniel E.R. Espinoza and Dr Thomas J. Scanlon  
Acknowledgements: Dr Rodrigo C. Palharini



**Enquiries: hy2Foam@gmail.com**

<div class="paragraph"><p><br>
<br></p></div>

---  
### You may also be interested in:  
+ **_dsmcFoam+_** for OF-2.4.0-MNF   
the direct simulation Monte Carlo code from the Universities of Strathclyde and Glasgow  
hosted by Dr Craig White (https://github.com/MicroNanoFlows/OpenFOAM-2.4.0-MNF/tree/devel-craig)


<div class="paragraph"><p><br>
<br></p></div>

---  
### _hyStrath_ also features:  
+ **_blockMeshDG_** by Akidess (https://openfoamwiki.net/index.php/Contrib_blockMeshDG)  
+ **_makeAxialMesh_** by Bernhard Gschaider (http://openfoamwiki.net/index.php/Contrib/MakeAxialMesh)


