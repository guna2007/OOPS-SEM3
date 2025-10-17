// HybridTask: combines dependency handling and recurring execution.
#pragma once

#include "DependentTask.h"
#include "RecurringTask.h"

namespace chrono_core
{

    class HybridTask : public DependentTask, public RecurringTask
    {
    public:
        HybridTask(int id, int priority, std::vector<int> deps, int times);
        void execute() override;
    };

} // namespace chrono_core
