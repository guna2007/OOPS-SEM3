#include "PriorityScheduler.h"

namespace chrono_core
{

    void PriorityScheduler::scheduleTasks()
    {
        std::cout << "[Schedule] Priority order (desc):" << '\n';
        std::vector<ITask *> sorted = taskQueue_;
        std::sort(sorted.begin(), sorted.end(), [](ITask *a, ITask *b)
                  { return *b < *a; });
        for (auto *t : sorted)
        {
            std::cout << "  task prio=" << t->getPriority() << '\n';
            t->execute();
        }
    }

} // namespace chrono_core
