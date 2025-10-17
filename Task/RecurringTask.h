// RecurringTask: executes on a repeated schedule (simulation prints multiple cycles).
#pragma once

#include "Task.h"

namespace chrono_core
{

    class RecurringTask : public virtual Task
    { // virtual inheritance supports HybridTask
    protected:
        int times_;

    public:
        RecurringTask(int id, int priority, int times);
        void execute() override;
    };

} // namespace chrono_core
