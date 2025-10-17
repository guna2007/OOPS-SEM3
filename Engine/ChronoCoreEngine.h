// ChronoCoreEngine: Singleton orchestrating tasks, scheduling, resources, events, and logging.
#pragma once

#include <memory>
#include <vector>
#include "../Utilities/TaskFactory.h"
#include "../Utilities/SchedulerFactory.h"
#include "../Resource/ResourceManager.h"
#include "../Resource/CPUResource.h"
#include "../Event/EventManager.h"
#include "../Event/UIController.h"
#include "../Utilities/Logger.h"

namespace chrono_core
{

    class ChronoCoreEngine
    {
        // Singleton
        ChronoCoreEngine();
        static ChronoCoreEngine *instance_;

        // Components
        std::unique_ptr<IScheduler> scheduler_;
        ResourceManager resourceManager_;
        EventManager eventManager_;
        UIController ui_;
        Logger<std::string> logger_;
        std::vector<std::unique_ptr<Task>> tasks_;

    public:
        static ChronoCoreEngine &getInstance();
        void initialize();
        void runSimulation();
    };

} // namespace chrono_core
