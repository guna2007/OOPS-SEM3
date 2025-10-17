// FIFO Scheduler: schedules in arrival order.
#pragma once

#include "Scheduler.h"

namespace chrono_core
{

    class FIFOScheduler : public virtual Scheduler
    {
    public:
        void scheduleTasks() override;
    };

} // namespace chrono_core
