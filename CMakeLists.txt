cmake_minimum_required(VERSION 3.16)

project(auto_counter VERSION 1.0 LANGUAGES CXX)
set(PROJECT_NAME auto_counter)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

# 设置 Qt 的安装目录
set(CMAKE_PREFIX_PATH "D:/Qt/6.9.1/mingw_64/lib/cmake")

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

# 设置头文件目录
include_directories(${PROJECT_SOURCE_DIR}/includes)
# 添加源文件
aux_source_directory(${PROJECT_SOURCE_DIR}/srcs SRC_FILES)
# 添加可执行文件
add_executable(${PROJECT_NAME} ${SRC_FILES})

# 链接 Qt 库
target_link_libraries(
    ${PROJECT_NAME} PRIVATE
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Widgets
)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            "${CMAKE_CURRENT_SOURCE_DIR}/resource"
            "$<TARGET_FILE_DIR:${PROJECT_NAME}>/resource"
    COMMENT "Copying resource/ to $<TARGET_FILE_DIR:${PROJECT_NAME}>"
)

qt_finalize_executable(auto_counter)
