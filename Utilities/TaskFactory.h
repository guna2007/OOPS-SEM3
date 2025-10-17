// TaskFactory: creates tasks by type string
#pragma once

#include <memory>
#include <string>
#include <vector>

#include "../Task/SimpleTask.h"
#include "../Task/DependentTask.h"
#include "../Task/RecurringTask.h"
#include "../Task/HybridTask.h"

namespace chrono_core
{

    class TaskFactory
    {
    public:
        static std::unique_ptr<Task> create(const std::string &type, int id, int prio)
        {
            if (type == "simple")
                return std::make_unique<SimpleTask>(id, prio);
            if (type == "dependent")
                return std::make_unique<DependentTask>(id, prio, std::vector<int>{});
            if (type == "recurring")
                return std::make_unique<RecurringTask>(id, prio, 3);
            if (type == "hybrid")
                return std::make_unique<HybridTask>(id, prio, std::vector<int>{}, 2);
            return nullptr;
        }
    };

} // namespace chrono_core
