#include "Task.h"

namespace chrono_core
{

    Task::Task(int id, int priority)
        : id_(id), priority_(priority), status_(TaskStatus::Pending) {}

    void Task::setState(std::unique_ptr<TaskStateBase> next)
    {
        currentState_ = std::move(next);
    }

} // namespace chrono_core
