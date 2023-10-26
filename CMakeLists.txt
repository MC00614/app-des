cmake_minimum_required(VERSION 3.5)

project(app-hu LANGUAGES CXX)

set(INSTALL_DIRECTORY /usr/bin/${PROJECT_NAME})

add_subdirectory(library)
add_subdirectory(instrument_cluster)

if (BUILD_CONF)
    file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/config/runtime/
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/config/)
    install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/config/
        DESTINATION ${INSTALL_DIRECTORY}
        FILE_PERMISSIONS OWNER_READ GROUP_READ WORLD_READ)
endif()
