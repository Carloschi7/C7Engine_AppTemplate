cmake_minimum_required(VERSION 3.12)

if("${APP_NAME}" STREQUAL "")
	set(APP_NAME Application)
endif()

if("${ENGINE_PATH}" STREQUAL "" OR "${ENGINE_BUILD_PATH}" STREQUAL "")
	message(FATAL_ERROR ": You need to define the vars ENGINE_PATH and ENGINE_BUILD_PATH, Check out the Github page to see what they should be bound to")
endif()

project(${APP_NAME})
add_executable(${PROJECT_NAME} src/Application.cpp)

target_link_libraries(${PROJECT_NAME}
	opengl32.lib
	${ENGINE_PATH}/Dependencies/ASSIMP/bin/assimp-vc143-mtd.lib
	${ENGINE_PATH}/Dependencies/GLEW/lib/Release/Win32/glew32s.lib
	${ENGINE_PATH}/Dependencies/GLFW/lib-vc2019/glfw3.lib
	${ENGINE_BUILD_PATH}/Debug/C7Engine.lib)

target_include_directories(${PROJECT_NAME} PUBLIC
	${ENGINE_PATH}/engine 
	${ENGINE_PATH}/Dependencies/ASSIMP/include
	${ENGINE_PATH}/Dependencies/GLM
	${ENGINE_PATH}/Dependencies/stbi
	${ENGINE_PATH}/Dependencies/GLFW
	${ENGINE_PATH}/Dependencies/GLEW)

file(COPY ${PROJECT_SOURCE_DIR}/assimpdll/assimp-vc143-mtd.dll DESTINATION ${PROJECT_BINARY_DIR})

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)