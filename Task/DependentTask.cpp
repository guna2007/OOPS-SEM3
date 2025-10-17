#include "DependentTask.h"
#include "PendingState.h"

#include <iostream>

namespace chrono_core
{

    DependentTask::DependentTask(int id, int priority, std::vector<int> deps)
        : Task(id, priority), dependencies_(std::move(deps))
    {
        setState(std::make_unique<PendingState>());
    }

    void DependentTask::execute()
    {
        std::cout << "[Execute] DependentTask id=" << getId() << ", priority=" << getPriority() << ", deps=" << dependencies_.size() << "\n";
        if (getState())
        {
            const_cast<TaskStateBase *>(getState())->handle(*this);
            const_cast<TaskStateBase *>(getState())->handle(*this);
        }
    }

} // namespace chrono_core
