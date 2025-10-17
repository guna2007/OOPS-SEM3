#include "SimpleTask.h"
#include "PendingState.h"

#include <iostream>

namespace chrono_core
{

    SimpleTask::SimpleTask(int id, int priority)
        : Task(id, priority)
    {
        setState(std::make_unique<PendingState>());
    }

    void SimpleTask::execute()
    {
        std::cout << "[Execute] SimpleTask id=" << getId() << ", priority=" << getPriority() << "\n";
        if (getState())
        {
            // Drive through states for demonstration
            const_cast<TaskStateBase *>(getState())->handle(*this);
            const_cast<TaskStateBase *>(getState())->handle(*this);
        }
    }

} // namespace chrono_core
