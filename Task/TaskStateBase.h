// ChronoCore - Task State Pattern: Base
// Abstract base for Task state objects. Concrete states implement transitions.

#pragma once

#include <string>

namespace chrono_core
{

    class Task; // forward declaration

    class TaskStateBase
    {
    public:
        virtual ~TaskStateBase() = default;
        virtual const char *name() const = 0;
        // Handle is invoked by Task to progress its lifecycle within a given state.
        virtual void handle(Task &task) = 0;
    };

} // namespace chrono_core
