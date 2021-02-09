cmake_minimum_required(VERSION 3.13)
# Project information
project(Mat_v4
	VERSION 1.0.3
	DESCRIPTION "MATLAB binary mat file v4 C++ interface"
	LANGUAGES CXX
)
# Fetch eigen
include(FetchContent)
FetchContent_Declare(
	eigen
	GIT_REPOSITORY 	https://github.com/bolderflight/eigen.git
	GIT_TAG v1.0.0
)
FetchContent_MakeAvailable(eigen)

# Add the library target
add_library(mat_v4 INTERFACE)
# Link libraries
target_link_libraries(mat_v4
	INTERFACE
		eigen
)
# Setup include directories 
target_include_directories(mat_v4 INTERFACE include/)
# Example and test if this project is built separately
if (PROJECT_NAME STREQUAL CMAKE_PROJECT_NAME)
	# Add the example target
	add_executable(mat_example examples/mat_example.cc)
	# Add the includes
	target_include_directories(mat_example PUBLIC 
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:include>
	)
	# Link libraries to the example target
	target_link_libraries(mat_example
		PRIVATE 
			mat_v4
	)
endif()


