// RoundRobin Scheduler: cycles through tasks in a circular fashion (simulated).
#pragma once

#include "Scheduler.h"

namespace chrono_core
{

    class RoundRobinScheduler : public Scheduler
    {
        int quantum_{1};

    public:
        explicit RoundRobinScheduler(int quantum = 1) : quantum_(quantum) {}
        void scheduleTasks() override;
    };

} // namespace chrono_core
