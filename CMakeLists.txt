cmake_minimum_required( VERSION 3.25 )
project( ESP32_CPU_Memory_Info )

set( CMAKE_CXX_STANDARD 14 )

include_directories( . )

add_executable( ESP32_CPU_Memory_Info
		ESP32_CPU_Memory_Info.ino )

set_target_properties( ESP32_CPU_Memory_Info PROPERTIES LINKER_LANGUAGE CXX )
