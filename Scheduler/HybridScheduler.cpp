#include "HybridScheduler.h"

namespace chrono_core
{

    void HybridScheduler::scheduleTasks()
    {
        std::cout << "[Schedule] Hybrid: priority then fifo" << '\n';
        // First, use priority behavior
        PriorityScheduler::scheduleTasks();
        // Then, follow with FIFO to show combined strategy effect on same queue
        FIFOScheduler::scheduleTasks();
    }

} // namespace chrono_core
