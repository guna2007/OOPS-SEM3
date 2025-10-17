// SchedulerFactory: creates scheduler instances by type
#pragma once

#include <memory>
#include <string>

#include "../Scheduler/FIFOScheduler.h"
#include "../Scheduler/PriorityScheduler.h"
#include "../Scheduler/RoundRobinScheduler.h"
#include "../Scheduler/HybridScheduler.h"

namespace chrono_core
{

    class SchedulerFactory
    {
    public:
        static std::unique_ptr<IScheduler> create(const std::string &type)
        {
            if (type == "fifo")
                return std::make_unique<FIFOScheduler>();
            if (type == "priority")
                return std::make_unique<PriorityScheduler>();
            if (type == "rr")
                return std::make_unique<RoundRobinScheduler>(1);
            if (type == "hybrid")
                return std::make_unique<HybridScheduler>();
            return nullptr;
        }
    };

} // namespace chrono_core
