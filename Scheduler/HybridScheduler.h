// HybridScheduler: demonstrates combining strategies (composition/multiple inheritance if needed).
#pragma once

#include "PriorityScheduler.h"
#include "FIFOScheduler.h"

namespace chrono_core
{

    class HybridScheduler : public PriorityScheduler, public FIFOScheduler
    {
    public:
        void scheduleTasks() override;
    };

} // namespace chrono_core
