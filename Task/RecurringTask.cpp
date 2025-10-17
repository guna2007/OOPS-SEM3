#include "RecurringTask.h"
#include "PendingState.h"

#include <iostream>

namespace chrono_core
{

    RecurringTask::RecurringTask(int id, int priority, int times)
        : Task(id, priority), times_(times)
    {
        setState(std::make_unique<PendingState>());
    }

    void RecurringTask::execute()
    {
        std::cout << "[Execute] RecurringTask id=" << getId() << ", priority=" << getPriority() << ", times=" << times_ << "\n";
        for (int i = 0; i < times_; ++i)
        {
            std::cout << "  cycle " << (i + 1) << "/" << times_ << "\n";
        }
        if (getState())
        {
            const_cast<TaskStateBase *>(getState())->handle(*this);
            const_cast<TaskStateBase *>(getState())->handle(*this);
        }
    }

} // namespace chrono_core
