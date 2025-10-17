// Operator overloads for Task and Scheduler-level utilities
#pragma once

#include <ostream>
#include "../Task/Task.h"

namespace chrono_core
{

    inline std::ostream &operator<<(std::ostream &os, const Task &t)
    {
        os << "Task{id=" << t.getId() << ", prio=" << t.getPriority() << "}";
        return os;
    }

    inline bool operator==(const ITask &a, const ITask &b)
    {
        return a.getPriority() == b.getPriority();
    }

    // '+' combines priorities (illustrative); returns new priority value.
    inline int operator+(const ITask &a, const ITask &b)
    {
        return a.getPriority() + b.getPriority();
    }

} // namespace chrono_core
