// UIController observer: prints event to console (simulation of UI reaction)
#pragma once

#include <iostream>
#include "../CoreInterfaces/IObserver.h"

namespace chrono_core
{

    class UIController : public IObserver
    {
    public:
        void update(const Event &e) override
        {
            std::cout << "[UI] event type=" << e.type << ", src=" << e.source << ", msg=" << e.message << '\n';
        }
    };

} // namespace chrono_core
