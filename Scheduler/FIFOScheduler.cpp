#include "FIFOScheduler.h"

namespace chrono_core
{

    void FIFOScheduler::scheduleTasks()
    {
        std::cout << "[Schedule] FIFO order:" << '\n';
        for (auto *t : taskQueue_)
        {
            std::cout << "  task prio=" << t->getPriority() << '\n';
            t->execute();
        }
    }

} // namespace chrono_core
