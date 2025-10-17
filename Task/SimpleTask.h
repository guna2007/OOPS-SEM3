// SimpleTask: basic one-shot task.
#pragma once

#include "Task.h"

namespace chrono_core
{

    class SimpleTask : public Task
    {
    public:
        SimpleTask(int id, int priority);
        void execute() override;
    };

} // namespace chrono_core
