cmake_minimum_required(VERSION 3.13)
# Project information
project(Mat-v4
	VERSION 1.0
	DESCRIPTION "MATLAB binary mat file v4 C++ interface"
	LANGUAGES CXX
)
# Fetch eigen
include(FetchContent)
FetchContent_Declare(
	eigen
	GIT_REPOSITORY 	git@gitlab.com:bolderflight/software/eigen.git
	GIT_TAG					v1.0.0
)
FetchContent_MakeAvailable(eigen)

# Add the library target
add_library(mat-v4 INTERFACE)
# Link libraries
target_link_libraries(mat-v4
	INTERFACE
		eigen
)
# Setup include directories 
target_include_directories(mat-v4 INTERFACE include/)
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
			mat-v4
	)
	# # Fetch google test
	# include(FetchContent)
	# FetchContent_Declare(
	# 	googletest
	# 	GIT_REPOSITORY 	https://github.com/google/googletest.git
	# 	GIT_TAG					release-1.10.0
	# )
	# FetchContent_MakeAvailable(googletest)
	# enable_testing()
	# include(GoogleTest)
	# # Add the test target
	# add_executable(circle_buf_test tests/circle_buf_test.cc)
	# # Add the includes
	# target_include_directories(circle_buf_test PUBLIC 
	# 	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	# 	$<INSTALL_INTERFACE:include>
	# )
	# # Link libraries to the test target
	# target_link_libraries(circle_buf_test
	# 	PRIVATE 
	# 		circle_buf
	# 		gtest_main 
	# 		gtest
	# 		gmock
	# )
	# # Discover unit tests
	# gtest_discover_tests(circle_buf_test)
endif()


