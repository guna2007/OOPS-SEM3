// Scheduler base implementing IScheduler; holds a queue of tasks and optional ResourceManager pointer (aggregation).
#pragma once

#include <vector>
#include <iostream>

#include "../CoreInterfaces/IScheduler.h"

namespace chrono_core
{

    class ResourceManager; // forward declaration (Module 4)

    class Scheduler : public IScheduler
    {
    protected:
        std::vector<ITask *> taskQueue_;
        ResourceManager *resourceManager_{nullptr}; // aggregation: not owning
    public:
        virtual ~Scheduler() = default;

        void addTask(ITask *task) override { taskQueue_.push_back(task); }
        virtual void scheduleTasks() override = 0;

        void setResourceManager(ResourceManager *rm) { resourceManager_ = rm; }
        ResourceManager *getResourceManager() const { return resourceManager_; }
    };

    // Free function operator< leveraging task priority for sorting.
    inline bool operator<(const ITask &lhs, const ITask &rhs)
    {
        return lhs.getPriority() < rhs.getPriority();
    }

} // namespace chrono_core
