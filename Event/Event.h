// Event definition for ChronoCore. We reuse the Event struct declared in CoreInterfaces/IObserver.h
#pragma once

#include "../CoreInterfaces/IObserver.h"

namespace chrono_core
{

    // Optional typed constants for common event types/sources.
    namespace EventTypes
    {
        static constexpr const char *TaskStateChange = "TaskStateChange";
    }

    namespace EventSources
    {
        static constexpr const char *Task = "Task";
    }

} // namespace chrono_core
