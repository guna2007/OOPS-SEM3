// Priority Scheduler: schedules tasks by descending priority.
#pragma once

#include <algorithm>
#include "Scheduler.h"

namespace chrono_core
{

    class PriorityScheduler : public virtual Scheduler
    {
    public:
        void scheduleTasks() override;
    };

} // namespace chrono_core
