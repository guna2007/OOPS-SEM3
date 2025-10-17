#include "RoundRobinScheduler.h"

namespace chrono_core
{

    void RoundRobinScheduler::scheduleTasks()
    {
        std::cout << "[Schedule] RoundRobin (quantum=" << quantum_ << "):" << '\n';
        // For simulation, just one pass executing each task once
        for (auto *t : taskQueue_)
        {
            std::cout << "  task prio=" << t->getPriority() << '\n';
            t->execute();
        }
    }

} // namespace chrono_core
