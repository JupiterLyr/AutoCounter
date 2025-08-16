cmake_minimum_required(VERSION 3.16)

project(auto_counter VERSION 1.0 LANGUAGES CXX)
set(PROJECT_NAME auto_counter)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 设置 Qt 的安装目录
set(CMAKE_PREFIX_PATH "D:/Qt/6.9.1/mingw_64/lib/cmake")

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

# 设置头文件目录
include_directories(${PROJECT_SOURCE_DIR}/includes)
# 添加源文件
aux_source_directory(${PROJECT_SOURCE_DIR}/srcs SRC_FILES)
# 其他配置文件
set(RC_FILES ${PROJECT_SOURCE_DIR}/icon_config.rc)
# 添加可执行文件
add_executable(${PROJECT_NAME} ${SRC_FILES} ${RC_FILES})

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

# # ==================== 安装规则 ====================
# # 1. 设定安装目录
# set(CMAKE_INSTALL_PREFIX "Release" CACHE PATH "")

# # 2. 安装规则
# install(TARGETS ${PROJECT_NAME}
#         RUNTIME DESTINATION .)
# install(DIRECTORY resource
#         DESTINATION .)

# # 3. Qt 官方提供的自动拷贝运行时库/插件
# #    需要 CMake ≥ 3.14，Qt ≥ 5.14
# include(GNUInstallDirs)
# qt_generate_deploy_app_script(
#     TARGET ${PROJECT_NAME}
#     OUTPUT_SCRIPT deploy_script.cmake
#     NO_UNSUPPORTED_PLATFORM_ERROR
# )

# install(SCRIPT "${CMAKE_CURRENT_BINARY_DIR}/deploy_script.cmake")

# add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
#     COMMAND ${CMAKE_COMMAND} --install . --config $<CONFIG>
#     COMMENT "Installing ${PROJECT_NAME} to ${CMAKE_INSTALL_PREFIX}"
# )

qt_finalize_executable(${PROJECT_NAME})
