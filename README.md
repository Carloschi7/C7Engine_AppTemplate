# C7Engine_AppTemplate
Template to get started with the C7Engine



REQUIREMENTS: The C7Engine (https://github.com/Carloschi7/C7Engine.git) needs to be installed and built,
the paths to the source dir and the binary dir
(the dir which contains your build) will be asked below



Building from terminal (requires cmake to function as a terminal command, 
the executable needs to be linked to the PATH section of Windows' environmental variables):



1) (In a chosen dir) git clone https://github.com/Carloschi7/C7Engine_AppTemplate.git



2) mkdir build



3) cd build



(Make sure to insert your paths here, e.g. -DENGINE_PATH=D:/Engine -D...)
4) cmake -DENGINE_PATH=<YourEngineSourcePath> -DENGINE_BUILD_PATH=<YourEngineBinaryPath> -A Win32 ..



(Depending on which method you prefer according to your configuration)




5) make (needs to be installed)



(For Windows + Visual Studio)
  
5) <YourProjectName>.sln (which opens up the project in Visual Studio, then you can follow the previous
points from 5) to the end)
