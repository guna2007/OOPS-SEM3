// Template Logger<T>: logs arbitrary data and listens to events
#pragma once

#include <iostream>
#include "../CoreInterfaces/IObserver.h"

namespace chrono_core
{

    template <typename T>
    class Logger : public IObserver
    {
    public:
        void log(const T &value)
        {
            std::cout << "[Logger] " << value << '\n';
        }

        void update(const Event &e) override
        {
            std::cout << "[Logger<Event>] type=" << e.type << ", src=" << e.source << ", msg=" << e.message << '\n';
        }
    };

} // namespace chrono_core
