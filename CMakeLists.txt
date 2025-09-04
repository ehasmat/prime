cmake_minimum_required(VERSION 3.10)

# Set the C++ standard to C++23
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# used internally by CMake to identify your project
project(prime)

# Include the directory headers are located
include_directories(${CMAKE_SOURCE_DIR}/include)

# Add the main executable
add_executable(prime src/main.cpp src/prime.cpp)

####################################################

# Add the test executable
add_executable(my_test src/prime.cpp tests/test.cpp)

# Include directories for the test target
target_include_directories(my_test PRIVATE ${PROJECT_SOURCE_DIR}/include)

# Enable testing
enable_testing()

# Register the test executable with CTest (optional)
add_test(NAME my_test COMMAND my_test)




cmake_minimum_required(VERSION 3.10)
project(PrimeCheck)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library(prime prime.cpp)

add_executable(main main.cpp)
target_link_libraries(main prime)

add_executable(test test.cpp)
target_link_libraries(test prime)
