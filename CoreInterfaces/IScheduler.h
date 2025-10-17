// ChronoCore - Core Interfaces: IScheduler
// Abstraction for scheduling tasks using various strategies (FIFO, Priority, RoundRobin, etc.).
// Demonstrates: Abstraction, Polymorphism, virtual destructor.

#pragma once

#include "ITask.h"
#include <vector>

namespace chrono_core
{

    class IScheduler
    {
    public:
        virtual ~IScheduler() = default; // Virtual destructor for polymorphic use

        // Add a task for future scheduling.
        virtual void addTask(ITask *task) = 0;

        // Compute and optionally execute/emit the scheduling order.
        virtual void scheduleTasks() = 0;
    };

} // namespace chrono_core
