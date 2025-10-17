// Running state: task is currently executing.
#pragma once

#include "TaskStateBase.h"
#include "Task.h"

namespace chrono_core
{

    class RunningState : public TaskStateBase
    {
    public:
        const char *name() const override { return "Running"; }
        void handle(Task &task) override;
    };

} // namespace chrono_core
