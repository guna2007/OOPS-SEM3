ChronoCore — OOP Task Scheduling & Execution Engine

Overview
ChronoCore is a purely object-oriented C++ simulation that showcases advanced OOP concepts while implementing a modular task scheduling and execution engine. It focuses on clean interfaces, inheritance hierarchies, design patterns, and clear console-driven behavior. No GUI or database is involved.

Build & Run (CMake)
Prerequisites: CMake >= 3.16, a C++17 compiler (MSVC/Clang/GCC).

Steps:

1. Configure and build
   - Create a build directory and run CMake configure + build.
2. Module verification executables are added as we progress.

Module 1 — Core Interfaces
Folder: CoreInterfaces/
Files:

- ITask.h: Abstraction for executable tasks with priority and status. Includes TaskStatus enum.
- IScheduler.h: Abstraction for scheduling tasks with addTask() and scheduleTasks().
- IResource.h: Abstraction for allocatable resources.
- IObserver.h: Observer interface receiving Event notifications.
- ISubject.h: Subject interface to manage observers and broadcast events.

OOP Concepts Demonstrated

- Abstraction via pure virtual interfaces
- Polymorphism and virtual destructors on polymorphic bases
- Clear namespacing (namespace chrono_core)

Verification

- A tiny translation unit CoreInterfaces/\_verify_module1.cpp includes all headers.
- Target verify_module1 ensures headers compile cleanly.

Next Modules
Subsequent modules will add concrete task hierarchies, schedulers, resources, an event system, utilities (logger/factories/operators), the ChronoCore engine singleton, and a main simulation driver. This README will be expanded after each module with compile/run instructions and sample outputs.

Module 2 — Task Hierarchy
Folder: Task/
Files:

- Task.h/cpp: Abstract base implementing ITask, stores id/priority/status, and holds a TaskStateBase.
- State classes: TaskStateBase.h, PendingState.h, RunningState.h, CompletedState.h, FailedState.h with simple transitions.
- SimpleTask.h/cpp: Basic one-shot execution with state transitions and console output.
- DependentTask.h/cpp: Simulated dependency list with console output.
- RecurringTask.h/cpp: Repeats execution for N cycles then transitions state.
- HybridTask.h/cpp: Multiple inheritance (virtual via base Task on parents) combining dependent and recurring behavior.

OOP Concepts Demonstrated

- Inheritance and Polymorphism via execute() overrides
- State pattern driving status changes
- Encapsulation of task data via getters/setters
- Multiple inheritance with virtual base to avoid diamond duplication

Verification

- Target verify_module2 runs a small harness creating 4 task types and executing them.
- Expected console prints: task type/id, state transitions, and cycles for recurring/hybrid.

Build targets (caution: ensure CMake is installed)

- verify_module1: header compilation sanity for CoreInterfaces
- verify_module2: compiles and runs task execution demo
- verify_module3: compiles and runs scheduling strategies demo
- verify_module4: compiles and runs resource allocation demo
- verify_module5: compiles and runs event/observer demo
- verify_module6: compiles and runs utilities (logger, factories, operators)
- chronocore_main: full simulation binary

Try it (Windows, bash with MinGW g++)
Optional if CMake is not available:

```bash
g++ -std=gnu++17 -I c:/Users/lanka/OneDrive/Desktop/projects/oops/OOPS_project \
	-o c:/Users/lanka/OneDrive/Desktop/projects/oops/OOPS_project/build_verify_module2.exe \
	c:/Users/lanka/OneDrive/Desktop/projects/oops/OOPS_project/Task/_verify_module2.cpp \
	c:/Users/lanka/OneDrive/Desktop/projects/oops/OOPS_project/Task/Task.cpp \
	c:/Users/lanka/OneDrive/Desktop/projects/oops/OOPS_project/Task/States.cpp \
	c:/Users/lanka/OneDrive/Desktop/projects/oops/OOPS_project/Task/SimpleTask.cpp \
	c:/Users/lanka/OneDrive/Desktop/projects/oops/OOPS_project/Task/DependentTask.cpp \
	c:/Users/lanka/OneDrive/Desktop/projects/oops/OOPS_project/Task/RecurringTask.cpp \
	c:/Users/lanka/OneDrive/Desktop/projects/oops/OOPS_project/Task/HybridTask.cpp

c:/Users/lanka/OneDrive/Desktop/projects/oops/OOPS_project/build_verify_module2.exe
```

Module 3 — Scheduler Hierarchy
Folder: Scheduler/
Files:

- Scheduler.h: Base class implementing IScheduler (queue, addTask) and aggregation pointer to ResourceManager.
- FIFOScheduler.h/cpp: Schedules in insertion order.
- PriorityScheduler.h/cpp: Sorts by task priority using operator< overload on ITask.
- RoundRobinScheduler.h/cpp: Simulated round-robin single pass.
- HybridScheduler.h/cpp: Demonstrates multiple inheritance to combine strategies (priority then FIFO).

OOP Concepts Demonstrated

- Strategy pattern via different scheduling policies
- Composition/Aggregation with ResourceManager pointer
- Operator overloading: global operator<(const ITask&, const ITask&)
- Multiple inheritance in HybridScheduler with virtual bases to avoid ambiguity

Verification

- Target verify_module3 builds and runs a harness scheduling three tasks with each strategy, printing order and executing tasks.

Try it (Windows, bash with MinGW g++)

```bash
g++ -std=gnu++17 -I c:/Users/lanka/OneDrive/Desktop/projects/oops/OOPS_project \
	-o c:/Users/lanka/OneDrive/Desktop/projects/oops/OOPS_project/build_verify_module3.exe \
	c:/Users/lanka/OneDrive/Desktop/projects/oops/OOPS_project/Scheduler/_verify_module3.cpp \
	c:/Users/lanka/OneDrive/Desktop/projects/oops/OOPS_project/Task/Task.cpp \
	c:/Users/lanka/OneDrive/Desktop/projects/oops/OOPS_project/Task/States.cpp \
	c:/Users/lanka/OneDrive/Desktop/projects/oops/OOPS_project/Task/SimpleTask.cpp \
	c:/Users/lanka/OneDrive/Desktop/projects/oops/OOPS_project/Task/DependentTask.cpp \
	c:/Users/lanka/OneDrive/Desktop/projects/oops/OOPS_project/Task/RecurringTask.cpp \
	c:/Users/lanka/OneDrive/Desktop/projects/oops/OOPS_project/Task/HybridTask.cpp \
	c:/Users/lanka/OneDrive/Desktop/projects/oops/OOPS_project/Scheduler/FIFOScheduler.cpp \
	c:/Users/lanka/OneDrive/Desktop/projects/oops/OOPS_project/Scheduler/PriorityScheduler.cpp \
	c:/Users/lanka/OneDrive/Desktop/projects/oops/OOPS_project/Scheduler/RoundRobinScheduler.cpp \
	c:/Users/lanka/OneDrive/Desktop/projects/oops/OOPS_project/Scheduler/HybridScheduler.cpp

c:/Users/lanka/OneDrive/Desktop/projects/oops/OOPS_project/build_verify_module3.exe
```

Module 4 — Resource System
Folder: Resource/
Files:

- Resource.h/cpp: Abstract base implementing IResource; handles availability and logs allocate/release.
- CPUResource.h, MemoryResource.h: Concrete resources.
- ResourceManager.h/cpp: Composition of Resource objects; provides acquireFirstAvailable and releaseAll.
- ResourcePool.h: Template pool for generic resource handling with predicate-based acquire.

OOP Concepts Demonstrated

- Abstraction and encapsulation in Resource, polymorphism for concrete types
- Composition in ResourceManager, templates in ResourcePool

Verification

- Target verify_module4 builds and runs a simple allocation/release demo and template pool usage.

Try it (Windows, bash with MinGW g++)

```bash
g++ -std=gnu++17 -I c:/Users/lanka/OneDrive/Desktop/projects/oops/OOPS_project \
	-o c:/Users/lanka/OneDrive/Desktop/projects/oops/OOPS_project/build_verify_module4.exe \
	c:/Users/lanka/OneDrive/Desktop/projects/oops/OOPS_project/Resource/_verify_module4.cpp \
	c:/Users/lanka/OneDrive/Desktop/projects/oops/OOPS_project/Resource/Resource.cpp \
	c:/Users/lanka/OneDrive/Desktop/projects/oops/OOPS_project/Resource/ResourceManager.cpp

c:/Users/lanka/OneDrive/Desktop/projects/oops/OOPS_project/build_verify_module4.exe
```

Module 5 — Event System
Folder: Event/
Files:

- Event.h: Adds typed constants for event types/sources; Event struct is shared from CoreInterfaces.
- EventManager.h: Implements ISubject; manages observers and broadcasts events.
- UIController.h, EventConsoleLogger.h: Observers that print to console.

OOP Concepts Demonstrated

- Observer pattern: subjects, observers, notifications
- Aggregation: tasks hold a notifier pointer and emit events on state changes

Verification

- Target verify_module5 attaches observers and runs a task to produce event logs.

Try it (Windows, bash with MinGW g++)

```bash
g++ -std=gnu++17 -I c:/Users/lanka/OneDrive/Desktop/projects/oops/OOPS_project \
	-o c:/Users/lanka/OneDrive/Desktop/projects/oops/OOPS_project/build_verify_module5.exe \
	c:/Users/lanka/OneDrive/Desktop/projects/oops/OOPS_project/Event/_verify_module5.cpp \
	c:/Users/lanka/OneDrive/Desktop/projects/oops/OOPS_project/Task/SimpleTask.cpp \
	c:/Users/lanka/OneDrive/Desktop/projects/oops/OOPS_project/Task/Task.cpp \
	c:/Users/lanka/OneDrive/Desktop/projects/oops/OOPS_project/Task/States.cpp

c:/Users/lanka/OneDrive/Desktop/projects/oops/OOPS_project/build_verify_module5.exe
```

Module 6 — Utilities (Logger, Factory, Operators)
Folder: Utilities/
Files:

- Logger.h: Template Logger<T> with log() and IObserver update() for events.
- TaskFactory.h: Creates tasks by type string.
- SchedulerFactory.h: Creates scheduler by type string.
- Operators.h: Stream << for Task, == and + for ITask comparisons.

OOP Concepts Demonstrated

- Templates in Logger and generic operator usage
- Factory pattern for tasks and schedulers
- Operator overloading for intuitive diagnostics

Verification

- Target verify_module6 logs strings, creates tasks/scheduler via factories, uses operators, and executes scheduling.

Try it (Windows, bash with MinGW g++)

```bash
g++ -std=gnu++17 -I c:/Users/lanka/OneDrive/Desktop/projects/oops/OOPS_project \
	-o c:/Users/lanka/OneDrive/Desktop/projects/oops/OOPS_project/build_verify_module6.exe \
	c:/Users/lanka/OneDrive/Desktop/projects/oops/OOPS_project/Utilities/_verify_module6.cpp \
	c:/Users/lanka/OneDrive/Desktop/projects/oops/OOPS_project/Task/Task.cpp \
	c:/Users/lanka/OneDrive/Desktop/projects/oops/OOPS_project/Task/States.cpp \
	c:/Users/lanka/OneDrive/Desktop/projects/oops/OOPS_project/Task/SimpleTask.cpp \
	c:/Users/lanka/OneDrive/Desktop/projects/oops/OOPS_project/Task/DependentTask.cpp \
	c:/Users/lanka/OneDrive/Desktop/projects/oops/OOPS_project/Task/RecurringTask.cpp \
	c:/Users/lanka/OneDrive/Desktop/projects/oops/OOPS_project/Task/HybridTask.cpp \
	c:/Users/lanka/OneDrive/Desktop/projects/oops/OOPS_project/Scheduler/FIFOScheduler.cpp \
	c:/Users/lanka/OneDrive/Desktop/projects/oops/OOPS_project/Scheduler/PriorityScheduler.cpp \
	c:/Users/lanka/OneDrive/Desktop/projects/oops/OOPS_project/Scheduler/RoundRobinScheduler.cpp \
	c:/Users/lanka/OneDrive/Desktop/projects/oops/OOPS_project/Scheduler/HybridScheduler.cpp

c:/Users/lanka/OneDrive/Desktop/projects/oops/OOPS_project/build_verify_module6.exe
```

Module 7 — ChronoCore Engine
Folder: Engine/
Files:

- ChronoCoreEngine.h/cpp: Singleton engine that initializes observers, resources, scheduler, creates tasks via factories, wires notifier, and orchestrates scheduling and execution.

OOP Concepts Demonstrated

- Singleton pattern, composition/aggregation across modules

Verification

- Built as part of chronocore_main; console output shows lifecycle across tasks, events, and resource handling.

Module 8 — Main Simulation Driver
Folder: Main/
Files:

- main.cpp: Entry point invoking ChronoCoreEngine::getInstance().runSimulation().

Run (Windows, bash with MinGW g++)

```bash
g++ -std=gnu++17 -I c:/Users/lanka/OneDrive/Desktop/projects/oops/OOPS_project \
	-o c:/Users/lanka/OneDrive/Desktop/projects/oops/OOPS_project/chronocore_main.exe \
	c:/Users/lanka/OneDrive/Desktop/projects/oops/OOPS_project/Main/main.cpp \
	c:/Users/lanka/OneDrive/Desktop/projects/oops/OOPS_project/Engine/ChronoCoreEngine.cpp \
	c:/Users/lanka/OneDrive/Desktop/projects/oops/OOPS_project/Task/Task.cpp \
	c:/Users/lanka/OneDrive/Desktop/projects/oops/OOPS_project/Task/States.cpp \
	c:/Users/lanka/OneDrive/Desktop/projects/oops/OOPS_project/Task/SimpleTask.cpp \
	c:/Users/lanka/OneDrive/Desktop/projects/oops/OOPS_project/Task/DependentTask.cpp \
	c:/Users/lanka/OneDrive/Desktop/projects/oops/OOPS_project/Task/RecurringTask.cpp \
	c:/Users/lanka/OneDrive/Desktop/projects/oops/OOPS_project/Task/HybridTask.cpp \
	c:/Users/lanka/OneDrive/Desktop/projects/oops/OOPS_project/Scheduler/FIFOScheduler.cpp \
	c:/Users/lanka/OneDrive/Desktop/projects/oops/OOPS_project/Scheduler/PriorityScheduler.cpp \
	c:/Users/lanka/OneDrive/Desktop/projects/oops/OOPS_project/Scheduler/RoundRobinScheduler.cpp \
	c:/Users/lanka/OneDrive/Desktop/projects/oops/OOPS_project/Scheduler/HybridScheduler.cpp \
	c:/Users/lanka/OneDrive/Desktop/projects/oops/OOPS_project/Resource/Resource.cpp \
	c:/Users/lanka/OneDrive/Desktop/projects/oops/OOPS_project/Resource/ResourceManager.cpp

c:/Users/lanka/OneDrive/Desktop/projects/oops/OOPS_project/chronocore_main.exe
```
