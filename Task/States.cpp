#include <iostream>
#include "../Event/Event.h"

#include "PendingState.h"
#include "RunningState.h"
#include "CompletedState.h"
#include "FailedState.h"

namespace chrono_core
{

    void PendingState::handle(Task &task)
    {
        std::cout << "[State] Task " << task.getId() << " transitioning: Pending -> Running\n";
        task.setStatus(TaskStatus::Running);
        task.setState(std::make_unique<RunningState>());
        if (auto *n = task.getNotifier())
        {
            n->notifyAll(Event{EventTypes::TaskStateChange, EventSources::Task, "Task " + std::to_string(task.getId()) + " Running"});
        }
    }

    void RunningState::handle(Task &task)
    {
        std::cout << "[State] Task " << task.getId() << " transitioning: Running -> Completed\n";
        task.setStatus(TaskStatus::Completed);
        task.setState(std::make_unique<CompletedState>());
        if (auto *n = task.getNotifier())
        {
            n->notifyAll(Event{EventTypes::TaskStateChange, EventSources::Task, "Task " + std::to_string(task.getId()) + " Completed"});
        }
    }

    void CompletedState::handle(Task &task)
    {
        std::cout << "[State] Task " << task.getId() << " is already Completed.\n";
    }

    void FailedState::handle(Task &task)
    {
        std::cout << "[State] Task " << task.getId() << " is in Failed state.\n";
    }

} // namespace chrono_core
