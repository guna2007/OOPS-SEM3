#include "HybridTask.h"
#include "PendingState.h"

#include <iostream>

namespace chrono_core
{

    HybridTask::HybridTask(int id, int priority, std::vector<int> deps, int times)
        : Task(id, priority), DependentTask(id, priority, std::move(deps)), RecurringTask(id, priority, times)
    {
        setState(std::make_unique<PendingState>());
    }

    void HybridTask::execute()
    {
        std::cout << "[Execute] HybridTask id=" << getId() << ", priority=" << getPriority() << "\n";
        // Simulate dependency acknowledgment
        std::cout << "  honoring dependencies and recurring cycles\n";
        for (int i = 0; i < RecurringTask::times_; ++i)
        {
            std::cout << "  hybrid cycle " << (i + 1) << "/" << RecurringTask::times_ << "\n";
        }
        if (getState())
        {
            const_cast<TaskStateBase *>(getState())->handle(*this);
            const_cast<TaskStateBase *>(getState())->handle(*this);
        }
    }

} // namespace chrono_core
