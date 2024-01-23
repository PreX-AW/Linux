# cmake version
cmake_minimum_required(VERSION 3.16.3)
# project name
project(MYSHELL)
#[[
PROJECT_SOURCE_DIR cmake 后输入的目录，一般也是根目录
PROJECT_BINARY_DIR 执行cmake命令的目录
CMAKE_CURRENT_SOURCE_DIR 当前处理的CMakeLists.txt所在路径
CMAKE_CURRENT_BINARY_DIR target编译目录
EXECUTABLE_OUTPUT_PATH 可执行文件生成存放位置
LIBRARY_OUTPUT_PATH 重定义连接库文件生成存放位置
PROJECT_NAME 通过project返回的项目名
CMAKE_BINARY_DIR 项目实际构建的路径，目前的理解是使用make命令的路径
]]

# set c++ version
set(CMAKE_CXX_STANDARD 11)
# set source file
#set(SRC_LIST myShell_simple.c myShell_simple.h)
# include dir add,split by<space>
# include_directories()

# link dir add
# link_directories()
# add source
#file(GLOB SRC_LIST ${CMAKE_CURRENT_SOURCE_DIR}/src/myShe*.c)
#set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
#include_directories(${PROJECT_SOURCE_DIR}/include)
## set executable_output_path
#add_library(myShell_lib src/saparate_Command.c src/print_Sub_command.c src/myShell_simple.c)
#link_directories(${PROJECT_SOURCE_DIR}/lib)
#link_libraries(myShell_lib)
#add_executable(shell ${SRC_LIST})
#set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
#set(EXECUTABLE_OUTPUT_PATH ../bin)
# error version
#set(EXECUTABLE_OUTPUT_PATH ../testcmake/bin)

file(GLOB C_SRC ${PROJECT_SOURCE_DIR}/src/*.c)
include_directories(${PROJECT_SOURCE_DIR}/include)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
add_library(my_Shell_lib SHARED    ${C_SRC})
link_directories(${PROJECT_SOURCE_DIR}/lib)
link_libraries(my_Shell_lib)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
add_executable(myShell ${C_SRC})
target_link_libraries(myShell my_Shell_lib)
#[[
CMake 编写流程
1. 版本要求
2. 项目名称
3. 查找所有源文件，并设置变量，存储到其中
4. 添加头文件目录
5. 设置库文件生成路径
6. 生成库文件
    1. 静态库使用`STATIC`，动态库使用`SHARED`
7. 包含库文件目录
8. 链接库文件
9. 设置可执行文件生成路径
10. 生成库文件
    1.  如果使用动态库链接需要加上target_link_libraries，并且要在其前包含库文件的目录

]]