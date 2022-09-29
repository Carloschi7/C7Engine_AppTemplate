#THIS FILE NEEDS TO BE RUN IN ADMINISTRATOR MODE(for the dir symlink defined below)
cmake_minimum_required(VERSION 3.12)

if("${APP_NAME}" STREQUAL "")
	set(APP_NAME Application)
endif()

if("${ENGINE_PATH}" STREQUAL "" OR "${ENGINE_BUILD_PATH}" STREQUAL "")
	message(FATAL_ERROR ": You need to define the vars ENGINE_PATH and ENGINE_BUILD_PATH, Check out the Github page to see what they should be bound to")
endif()

string(SUBSTRING "${CMAKE_GENERATOR}" 0 13 VISUAL_STUDIO_DEF)

#Visual studio is only availabe on Windows, so no need to check for anything else
if("${VISUAL_STUDIO_DEF}" STREQUAL "Visual Studio")
	set(C7ENGINE_LIB_PATH ${ENGINE_BUILD_PATH}/$(Configuration)/C7Engine.lib)
else()
	#default linux for now
	set(C7ENGINE_LIB_PATH ${ENGINE_BUILD_PATH}/C7Engine.a)
endif()

project(${APP_NAME})
add_executable(${PROJECT_NAME} src/Application.cpp)

target_link_libraries(${PROJECT_NAME}
	opengl32.lib
	${ENGINE_PATH}/Dependencies/ASSIMP/bin/assimp-vc143-mtd.lib
	${ENGINE_PATH}/Dependencies/GLEW/lib/Release/Win32/glew32s.lib
	${ENGINE_PATH}/Dependencies/GLFW/lib-vc2019/glfw3.lib
	${C7ENGINE_LIB_PATH})

target_include_directories(${PROJECT_NAME} PUBLIC
	${ENGINE_PATH}/engine 
	${ENGINE_PATH}/Dependencies/ASSIMP/include
	${ENGINE_PATH}/Dependencies/GLM
	${ENGINE_PATH}/Dependencies/stbi
	${ENGINE_PATH}/Dependencies/GLFW
	${ENGINE_PATH}/Dependencies/GLEW)

file(COPY ${PROJECT_SOURCE_DIR}/assimpdll/assimp-vc143-mtd.dll DESTINATION ${PROJECT_BINARY_DIR})

file(MAKE_DIRECTORY ${PROJECT_BINARY_DIR}/assets/shaders)
#Copies the assets to the project workspace
file(COPY assets/shaders DESTINATION assets)
file(COPY assets/skyboxes DESTINATION assets)
file(COPY assets/images DESTINATION assets)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)