// EventConsoleLogger: basic observer that writes events to stdout.
#pragma once

#include <iostream>
#include "../CoreInterfaces/IObserver.h"

namespace chrono_core
{

    class EventConsoleLogger : public IObserver
    {
    public:
        void update(const Event &e) override
        {
            std::cout << "[Log] type=" << e.type << ", src=" << e.source << ", msg=" << e.message << '\n';
        }
    };

} // namespace chrono_core
