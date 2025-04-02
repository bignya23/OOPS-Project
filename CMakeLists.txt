cmake_minimum_required(VERSION 3.10)
project(TaskManagerApp)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)

# Include the headers directory for header files
include_directories(headers)

# Add the executable with specified source files
add_executable(TaskManagerApp main.cpp src/ui.cpp src/Task.cpp src/TaskManager.cpp src/User.cpp src/UserManager.cpp src/FileHandling.cpp)


if(MINGW)
    target_link_options(TaskManagerApp PRIVATE "-mconsole")
endif()