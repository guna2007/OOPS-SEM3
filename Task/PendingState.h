// Pending state: task is queued and not yet running.
#pragma once

#include "TaskStateBase.h"
#include "Task.h"

namespace chrono_core
{

    class PendingState : public TaskStateBase
    {
    public:
        const char *name() const override { return "Pending"; }
        void handle(Task &task) override;
    };

} // namespace chrono_core
