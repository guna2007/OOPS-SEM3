// ChronoCore - Core Interfaces: ITask
// Abstraction for a task unit that can be scheduled and executed.
// Demonstrates: Abstraction, Polymorphism via pure virtuals, and virtual destructor for safe polymorphic deletion.

#pragma once

namespace chrono_core
{

    // Forward-looking: Provide a common status enum for tasks across the system.
    enum class TaskStatus
    {
        Pending,
        Running,
        Completed,
        Failed
    };

    // ITask defines the minimal behavior required by any executable task.
    class ITask
    {
    public:
        virtual ~ITask() = default; // Virtual destructor to enable proper cleanup via base pointer

        // Execute the task's work. Implementations will provide concrete behavior.
        virtual void execute() = 0;

        // Priority is used by schedulers to order tasks.
        virtual int getPriority() const = 0;

        // Status allows observers/schedulers to reason about lifecycle.
        virtual TaskStatus getStatus() const = 0;
    };

} // namespace chrono_core
