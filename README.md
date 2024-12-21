## Summary
This repository contains code from DVH group to similate S-TI-S JJ properties. A Labview based GUI is also included.
## License
The code is under The University of Illinois/NCSA Open Source License. See details in LICENSE.md file.
## To setup compile Code:
1. install VS2022 with C++ support, install intel oneapi library base AND the HPC toolkits. (the intel C++ classical will generate fastest code)
2. open the soluation file
3. build ygdll project, build other project. Before build setup in each project:
- VC++ directories->Include Directories
- VC++ directories->Library Directories
- Set project as startup project to run the debug from GUI button
- Choose right compiler: intel compiler C++ classic in latest version
3. check comments
4. run example to test and learn
- Diffraction pattern calculation (generate regular diffraction)
- Extended JJ washboard potential (plot CPR and washboard potential)
- Ic and disorder (Ic variation vs geometry disorder)
- Ic distribution project (demo of Ic distribution simulation, see LabView GUI for full function)

## Benchmark:
1. 2023.08.02 Guang Desktop in office: 
- Intel Core I5-13400F Regular diffraction pattern calculation
- FluxRange 5.0 Nflux 10001
- setparameters(0, 1001, 4.0, 1001, 0, 0.5,0.2, NULL,0);
- results:
	- VC 14.292 Sec
	- Intel 2023 13.909
	- Intel-no-openmp 68.9
1. 2024.1.29
- Intel Core I5-13400F Regular diffraction pattern calculation
- FluxRange 5.0 Nflux 10001
- setparameters(0, 1001, 4.0, 1001, 0, 0.5,0.2, NULL,0);
- results:
	- VC 13.77 Sec
	- Intel 2024 14.10
## Changelog:
The initial import commit contains old code from box folder.
There is LabView GUI from other repository in github.
2024.1
update to use intal oneapi 2024, visual studio 2022


