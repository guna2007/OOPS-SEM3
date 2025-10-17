=== ChronoCore Agentic Prompt Dictionary ===

---

# Prompt 0 — Project Context Awareness

**Prompt Name:** ChronoCore_ContextAwareness

**Prompt Text:**

```
You are tasked with implementing "ChronoCore" — a purely OOP-based Task Scheduling & Execution Engine.

Before coding, you must understand:

1. **Project Goal:**  
   - Showcase advanced OOP concepts (Abstraction, Encapsulation, Inheritance, Polymorphism, Composition, Aggregation, Multiple Inheritance, Operator Overloading, Templates, Virtual Destructors, Design Patterns).  
   - Modular, clean, and academically presentable system that simulates task scheduling and execution.

2. **Project Structure:**  
   The project has 8 modules:  
   M1: Core Interfaces  
   M2: Task Hierarchy  
   M3: Scheduler Hierarchy  
   M4: Resource System  
   M5: Event System  
   M6: Utilities (Logger, Factories, Templates)  
   M7: ChronoCore Engine  
   M8: Main Simulation Driver  

   Each module has **its own folder**, headers (.h), and source (.cpp) files.  
   Relationships:
   - Base classes are in Core Interfaces.  
   - Derived classes inherit appropriately.  
   - Composition/aggregation is correctly used.  
   - Virtual destructors on polymorphic base classes.  
   - Templates for generic components.  
   - Observer, State, Strategy, Factory, Singleton, and Decorator patterns integrated where applicable.

3. **Coding Rules:**  
   - Each file must have clear namespace: `chrono_core`.  
   - Modular: one class per file (exceptions allowed for tightly coupled small classes).  
   - Avoid unnecessary dependencies between modules.  
   - Do not implement GUI or database; simple console simulation is enough.  
   - Operator overloads and template usage should only exist where meaningful (e.g., task comparison, resource pools).  
   - Keep function signatures strictly as per interface design.  
   - Include detailed comments explaining OOP reasoning.

4. **Verification:**  
   After implementing each module, test for:  
   - Correct class relationships  
   - Correct interface implementation  
   - Correct inheritance, polymorphism, virtual destructors  
   - No compilation errors  
   - Clear console output for simulation

5. **Output:**  
   - Maintain **clean headers, source files**, namespaces, and comments.  
   - Ready-to-run modular project with compilation instructions.  

Do not start coding yet. Only confirm that you understand the project structure, goals, and coding rules.
```

---

# Module Implementation and Verification Prompts

## Module 1 — Core Interfaces

**Prompt Name:** ChronoCore_Module1_Implementation

```
Implement **Core Interfaces** module of ChronoCore.

1. **Folder:** `CoreInterfaces/`  
2. **Files:**  
   - `ITask.h` → declares pure virtual `execute()`, `getPriority()`, `getStatus()`  
   - `IScheduler.h` → declares pure virtual `scheduleTasks()`, `addTask(ITask*)`  
   - `IResource.h` → declares pure virtual `allocate()`, `release()`, `isAvailable()`  
   - `IObserver.h` → declares `update(Event e)`  
   - `ISubject.h` → declares `addObserver()`, `removeObserver()`, `notifyAll()`  

3. **Requirements:**  
   - Use `namespace chrono_core`.  
   - All base classes must have **virtual destructors**.  
   - Do not add implementation logic, only declarations.  
   - Include proper include guards or `#pragma once`.  
   - Comment purpose of each interface.

4. **OOP Focus:**  
   - Abstraction  
   - Virtual destructors  
   - Interface design
```

**Prompt Name:** ChronoCore_Module1_Verification

```
Verify **Core Interfaces module**:

1. Compile all headers (no .cpp needed yet) to check syntax.  
2. Confirm all pure virtual functions exist and have correct return types.  
3. Check that all base classes have virtual destructors.  
4. Confirm namespaces are consistent (`chrono_core`).  
5. Ensure no implementation logic in headers.  
6. Comment checks: verify each interface has a comment explaining its role.  

Return: "Module 1 Verified ✅" if all checks pass.
```

---

## Module 2 — Task Hierarchy

**Prompt Name:** ChronoCore_Module2_Implementation

```
Implement **Task Hierarchy** module.

1. **Folder:** `Task/`  
2. **Files:**  
   - `Task.h` / `Task.cpp` → implements abstract `Task` class inheriting `ITask`  
   - `SimpleTask.h` / `SimpleTask.cpp` → inherits `Task`  
   - `DependentTask.h` / `DependentTask.cpp` → inherits `Task`  
   - `RecurringTask.h` / `RecurringTask.cpp` → inherits `Task`  
   - `HybridTask.h` / `HybridTask.cpp` → inherits `DependentTask` and `RecurringTask`  
   - `TaskStateBase.h` → abstract base for State pattern  
   - `PendingState.h` / `RunningState.h` / `CompletedState.h` / `FailedState.h`  

3. **Requirements:**  
   - `Task` stores `id`, `priority`, `status` (private), use getters/setters.  
   - Implement **State pattern** using `TaskStateBase* currentState`.  
   - `execute()` overridden in each subclass with console print simulation.  
   - Multiple inheritance in `HybridTask` should use virtual inheritance.  
   - Include detailed comments explaining OOP concepts.

4. **OOP Focus:**  
   - Inheritance  
   - Polymorphism  
   - State pattern  
   - Encapsulation  
   - Multiple inheritance
```

**Prompt Name:** ChronoCore_Module2_Verification

```
Verify Task Hierarchy:

1. Compile all Task headers and source files.  
2. Ensure `Task` correctly inherits `ITask`.  
3. Each subclass overrides `execute()` with polymorphic behavior.  
4. State pattern correctly integrated; each state class has `handle(Task*)`.  
5. HybridTask uses virtual inheritance.  
6. Getters and setters encapsulate private members.  
7. Console simulation of `execute()` prints task type and id.  

Return: "Module 2 Verified ✅" if all checks pass.
```

---

## Module 3 — Scheduler Hierarchy

**Prompt Name:** ChronoCore_Module3_Implementation

```
Implement **Scheduler Hierarchy** module.

1. **Folder:** `Scheduler/`  
2. **Files:**  
   - `Scheduler.h` / `Scheduler.cpp` → base class implementing `IScheduler`  
   - `FIFOScheduler.h` / `FIFOScheduler.cpp`  
   - `PriorityScheduler.h` / `PriorityScheduler.cpp`  
   - `RoundRobinScheduler.h` / `RoundRobinScheduler.cpp`  
   - `HybridScheduler.h` / `HybridScheduler.cpp`  

3. **Requirements:**  
   - Base class has `std::vector<ITask*> taskQueue`.  
   - `addTask(ITask*)` adds to queue.  
   - `scheduleTasks()` overridden in each subclass.  
   - PriorityScheduler uses operator overload `<` to sort tasks.  
   - HybridScheduler demonstrates multiple inheritance if combining strategies.  
   - Scheduler can reference ResourceManager via aggregation (pointer).  
   - Include console output for scheduled task order.

4. **OOP Focus:**  
   - Polymorphism  
   - Strategy pattern  
   - Composition and aggregation  
   - Operator overloading
```

**Prompt Name:** ChronoCore_Module3_Verification

```
Verify Scheduler Hierarchy:

1. Compile Scheduler headers/source.  
2. Check `Scheduler` correctly implements `IScheduler`.  
3. Each subclass overrides `scheduleTasks()`.  
4. Operator overloading works in PriorityScheduler.  
5. HybridScheduler demonstrates intended multiple inheritance.  
6. Console output for task order shows correct scheduling.  

Return: "Module 3 Verified ✅"
```

---

## Module 4 — Resource System

**Prompt Name:** ChronoCore_Module4_Implementation

```
Implement **Resource System** module.

1. **Folder:** `Resource/`  
2. **Files:**  
   - `Resource.h` / `Resource.cpp` → base abstract class implementing `IResource`  
   - `CPUResource.h` / `CPUResource.cpp`  
   - `MemoryResource.h` / `MemoryResource.cpp`  
   - `ResourceManager.h` / `ResourceManager.cpp` → manages a pool of Resource*  
   - Optional: template `ResourcePool<T>` for generic resource handling  

3. **Requirements:**  
   - CPUResource and MemoryResource encapsulate their availability.  
   - ResourceManager uses composition to hold Resource objects.  
   - Allocate/release functions update resource state.  
   - Include console messages on allocation/release.  
   - Use template for generic ResourcePool<T>.

4. **OOP Focus:**  
   - Abstraction, encapsulation, composition, aggregation, templates
```

**Prompt Name:** ChronoCore_Module4_Verification

```
Verify Resource System:

1. Compile Resource module.  
2. Ensure Resource classes correctly inherit IResource.  
3. ResourceManager correctly allocates/releases resources.  
4. Template ResourcePool<T> works as intended.  
5. Console output shows allocation/release messages.  

Return: "Module 4 Verified ✅"
```

---

## Module 5 — Event System

**Prompt Name:** ChronoCore_Module5_Implementation

```
Implement **Event System** module.

1. **Folder:** `Event/`  
2. **Files:**  
   - `Event.h` → holds event type, source, message  
   - `IObserver.h`, `ISubject.h` already exist in M1  
   - `EventManager.h` / `EventManager.cpp` → implements ISubject  
   - Observers: Logger, UIController → implement IObserver  

3. **Requirements:**  
   - EventManager notifies all observers on event.  
   - Observers react to event (console print/log).  
   - Task state changes trigger events.  

4. **OOP Focus:**  
   - Observer pattern  
   - Aggregation  
   - Polymorphism
```

**Prompt Name:** ChronoCore_Module5_Verification

```
Verify Event System:

1. Compile Event module.  
2. EventManager correctly manages observers.  
3. Observers react correctly on notification.  
4. Task state changes trigger events.  
5. Console output correctly shows event messages.  

Return: "Module 5 Verified ✅"
```

---

## Module 6 — Utilities (Logger, Factory, Templates)

**Prompt Name:** ChronoCore_Module6_Implementation

```
Implement **Utilities** module.

1. **Folder:** `Utilities/`  
2. **Files:**  
   - `Logger.h` / `Logger.cpp` → template Logger<T>, implements IObserver  
   - `TaskFactory.h` / `TaskFactory.cpp`  
   - `SchedulerFactory.h` / `SchedulerFactory.cpp`  
   - Operator overloads: <<, <, ==, + for Task & Scheduler  

3. **Requirements:**  
   - Logger<T>::log() logs any data type.  
   - TaskFactory creates appropriate Task subclass given type string.  
   - SchedulerFactory creates appropriate Scheduler subclass.  
   - Include console prints for all factory creations.  
   - Operator overloads enable intuitive task comparisons and display.  

4. **OOP Focus:**  
   - Templates  
   - Factory pattern  
   - Operator overloading  
   - Observer integration
```

**Prompt Name:** ChronoCore_Module6_Verification

```
Verify Utilities module:

1. Compile Utilities module.  
2. Logger<T> logs correctly for multiple types.  
3. Factories return correct subclass objects.  
4. Operator overloads work as intended (task comparison, printing).  
5. Console messages show object creation and logging.  

Return: "Module 6 Verified ✅"
```

---

## Module 7 — ChronoCore Engine

**Prompt Name:** ChronoCore_Module7_Implementation

```
Implement **ChronoCore Engine** module.

1. **Folder:** `Engine/`  
2. **Files:**  
   - `ChronoCoreEngine.h` / `ChronoCoreEngine.cpp`  

3. **Requirements:**  
   - Singleton pattern for engine.  
   - Holds pointers to TaskManager, SchedulerManager, ResourceManager, EventManager, Logger.  
   - Initializes all components via factories.  
   - Orchestrates flow: task creation → scheduling → execution → resource management → event notifications → logging.  
   - Console prints simulation steps.  

4. **OOP Focus:**  
   - Singleton pattern  
   - Composition & Aggregation  
   - Integration of all OOP modules
```

**Prompt Name:** ChronoCore_Module7_Verification

```
Verify ChronoCore Engine:

1. Compile Engine module.  
2. Singleton pattern enforced (private constructor, static getInstance()).  
3. Engine correctly initializes all managers.  
4. Orchestration flow works: task creation → scheduling → execution → events → logging.  
5. Console output clearly simulates task lifecycle.  

Return: "Module 7 Verified ✅"
```

---

## Module 8 — Main Simulation Driver

**Prompt Name:** ChronoCore_Module8_Implementation

```
Implement **Main Simulation Driver**.

1. **Folder:** `Main/`  
2. **Files:** `main.cpp`  

3. **Requirements:**  
   - Includes ChronoCoreEngine.h.  
   - Calls ChronoCoreEngine::getInstance()->runSimulation().  
   - Simple CLI to choose scheduling strategy (optional).  
   - Demonstrates at least 5 tasks with different types and priorities.  
   - Outputs console logs showing full lifecycle: creation → scheduling → execution → events → logging.

4. **OOP Focus:**  
   - Demonstrates project orchestration  
   - Clean usage of all implemented OOP modules  
   - Ready-to-run simulation
```

**Prompt Name:** ChronoCore_Module8_Verification

```
Verify Main Simulation Driver:

1. Compile main.cpp with all modules.  
2. Run simulation: tasks created, scheduled, executed with correct console output.  
3. Event notifications trigger observer logs.  
4. Task priorities, states, and outputs reflect correct OOP behavior.  
5. No compilation errors, no warnings.  

Return: "Module 8 Verified ✅"
```

---

# ✅ Summary Table

| Prompt # | Name                              | Purpose                            |
| -------- | --------------------------------- | ---------------------------------- |
| 0        | ChronoCore_ContextAwareness       | Project context and rules          |
| 1        | ChronoCore_Module1_Implementation | Core Interfaces implementation     |
| 2        | ChronoCore_Module1_Verification   | Core Interfaces verification       |
| 3        | ChronoCore_Module2_Implementation | Task Hierarchy implementation      |
| 4        | ChronoCore_Module2_Verification   | Task Hierarchy verification        |
| 5        | ChronoCore_Module3_Implementation | Scheduler Hierarchy implementation |
| 6        | ChronoCore_Module3_Verification   | Scheduler Hierarchy verification   |
| 7        | ChronoCore_Module4_Implementation | Resource System implementation     |
| 8        | ChronoCore_Module4_Verification   | Resource System verification       |
| 9        | ChronoCore                        |                                    |
