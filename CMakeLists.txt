cmake_minimum_required(VERSION 3.25.1)

project(connect_to_ctp)

add_executable(${PROJECT_NAME} main.cpp )

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/ctp/traderapi)

add_library(thosttraderapi_sm SHARED IMPORTED)
set_target_properties(
	thosttraderapi_sm
	PROPERTIES
	IMPORTED_IMPLIB "${PROJECT_SOURCE_DIR}/ctp/traderapi/thosttraderapi_sm.so"
	IMPORTED_LOCATION "${PROJECT_SOURCE_DIR}/ctp/traderapi/thosttraderapi_sm.so"
	INTERFACE_INCLUDE_DIRECTORIES "${PROJECT_SOURCE_DIR}/ctp/traderapi"
)


target_link_libraries(${PROJECT_NAME} thosttraderapi_sm)
set(CMAKE_BUILD_TYPE Debug)