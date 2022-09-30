# C7Engine_AppTemplate

## Building on Windows + Visual Studio



REQUIREMENTS: The C7Engine (https://github.com/Carloschi7/C7Engine.git) needs to be installed and built,
the paths to the source dir and the binary dir
(the dir which contains your build) will be asked below



#### Building with the GUI



1) git clone https://github.com/Carloschi7/C7Engine_AppTemplate.git



2) Open the CMake GUI



3) Insert the binary path and the installation path for the current app



4) In the CMake variable section, set the variables ENGINE_PATH and ENGINE_BUILD_PATH to
respectively the engine's installation path and binary path (optionally you can set APP_NAME
if you want a custom name)



5) Configure (with Win32) and Generate



6) Open the generated Visual Studio solution, and set the app proj as the starting one
by right clicking on the project icon



7) Goto RightClick the solution -> Add project -> existing project, and browse the 
C7Engine.vcxproj you have built earlier



8) Right click the App project -> Set project build dependencies -> Add, and tick the C7Engine
project



9) Build the App and the demo shoul pop up


#### Building with the console (Windows)



1) `git clone https://github.com/Carloschi7/C7Engine_AppTemplate.git`



2) `cd C7Engine_AppTemplate`



3) `mkdir build`



4) `cd build`



(Make sure to insert your paths here, e.g. -DENGINE_PATH=D:/Engine -D...)

5) `cmake -DENGINE_PATH="YourEngineSourcePath" -DENGINE_BUILD_PATH="YourEngineBinaryPath" -A Win32 ..`




6) `"YourProjectName".sln` (which opens up the project in Visual Studio, then you can follow the previous
points from 5) to the end)



## Building on Linux Ubuntu

Execute the following commands(make sure to have your Ubuntu C7ENgine installation ready)


1) `git clone https://github.com/Carloschi7/C7Engine_AppTemplate.git`



2) `mkdir build && cd build`



3) `cmake -DENGINE_PATH="YourEngineInstallationPath" -DENGINE_BUILD_PATH="YourEngineBinaryPath" ..`



4) `make`



5) `./"YourAppName"` to run it



Enjoy!
