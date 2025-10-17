cmake_minimum_required(VERSION 3.16)
project(ChronoCore LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(chrono_core_interfaces INTERFACE)
target_include_directories(chrono_core_interfaces INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

# A tiny verify target that includes each header to ensure syntax correctness.
add_executable(verify_module1 CoreInterfaces/_verify_module1.cpp)
target_link_libraries(verify_module1 PRIVATE chrono_core_interfaces)

# Module 2: Task Hierarchy
add_library(chrono_core_task
	Task/Task.cpp
	Task/States.cpp
	Task/SimpleTask.cpp
	Task/DependentTask.cpp
	Task/RecurringTask.cpp
	Task/HybridTask.cpp)
target_link_libraries(chrono_core_task PRIVATE chrono_core_interfaces)
target_include_directories(chrono_core_task PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(verify_module2 Task/_verify_module2.cpp)
target_link_libraries(verify_module2 PRIVATE chrono_core_task)

# Module 3: Scheduler Hierarchy
add_library(chrono_core_scheduler
	Scheduler/FIFOScheduler.cpp
	Scheduler/PriorityScheduler.cpp
	Scheduler/RoundRobinScheduler.cpp
	Scheduler/HybridScheduler.cpp)
target_include_directories(chrono_core_scheduler PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(chrono_core_scheduler PRIVATE chrono_core_task chrono_core_interfaces)

add_executable(verify_module3 Scheduler/_verify_module3.cpp)
target_link_libraries(verify_module3 PRIVATE chrono_core_scheduler chrono_core_task)

# Module 4: Resource System
add_library(chrono_core_resource
	Resource/Resource.cpp
	Resource/ResourceManager.cpp)
target_include_directories(chrono_core_resource PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(chrono_core_resource PRIVATE chrono_core_interfaces)

add_executable(verify_module4 Resource/_verify_module4.cpp)
target_link_libraries(verify_module4 PRIVATE chrono_core_resource)

# Module 6: Utilities
add_executable(verify_module6 Utilities/_verify_module6.cpp)
target_include_directories(verify_module6 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(verify_module6 PRIVATE chrono_core_task chrono_core_scheduler chrono_core_interfaces)

# Module 7: Engine
add_library(chrono_core_engine Engine/ChronoCoreEngine.cpp)
target_include_directories(chrono_core_engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(chrono_core_engine PRIVATE chrono_core_task chrono_core_scheduler chrono_core_resource)

# Module 8: Main
add_executable(chronocore_main Main/main.cpp)
target_link_libraries(chronocore_main PRIVATE chrono_core_engine)
