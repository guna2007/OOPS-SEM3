// DependentTask: executes after dependencies complete.
#pragma once

#include <vector>
#include "Task.h"

namespace chrono_core
{

    class DependentTask : public virtual Task
    { // virtual inheritance to support HybridTask diamond
    protected:
        std::vector<int> dependencies_; // store dependency task IDs for simulation
    public:
        DependentTask(int id, int priority, std::vector<int> deps);
        void execute() override;
    };

} // namespace chrono_core
