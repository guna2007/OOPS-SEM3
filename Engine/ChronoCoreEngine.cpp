#include "ChronoCoreEngine.h"

#include <iostream>

namespace chrono_core
{

    ChronoCoreEngine *ChronoCoreEngine::instance_ = nullptr;

    ChronoCoreEngine::ChronoCoreEngine() = default;

    ChronoCoreEngine &ChronoCoreEngine::getInstance()
    {
        if (!instance_)
            instance_ = new ChronoCoreEngine();
        return *instance_;
    }

    void ChronoCoreEngine::initialize()
    {
        std::cout << "[Engine] Initializing...\n";
        // Observers
        eventManager_.addObserver(&ui_);
        eventManager_.addObserver(&logger_);

        // Resources
        resourceManager_.add(std::make_unique<CPUResource>("CPU-ENG"));

        // Scheduler via factory
        scheduler_ = SchedulerFactory::create("priority");

        // Create tasks via factory
        tasks_.push_back(TaskFactory::create("simple", 1, 4));
        tasks_.push_back(TaskFactory::create("dependent", 2, 8));
        tasks_.push_back(TaskFactory::create("recurring", 3, 5));

        // Hook notifier
        for (auto &t : tasks_)
        {
            t->setNotifier(&eventManager_);
            scheduler_->addTask(t.get());
        }
    }

    void ChronoCoreEngine::runSimulation()
    {
        std::cout << "[Engine] Running simulation...\n";
        initialize();
        scheduler_->scheduleTasks();
        resourceManager_.releaseAll();
        std::cout << "[Engine] Simulation complete.\n";
    }

} // namespace chrono_core
