// EventManager implements ISubject, manages observers and broadcasts events.
#pragma once

#include <vector>
#include <algorithm>
#include "../CoreInterfaces/ISubject.h"

namespace chrono_core
{

    class EventManager : public ISubject
    {
        std::vector<IObserver *> observers_;

    public:
        void addObserver(IObserver *obs) override
        {
            if (obs)
                observers_.push_back(obs);
        }
        void removeObserver(IObserver *obs) override
        {
            observers_.erase(std::remove(observers_.begin(), observers_.end(), obs), observers_.end());
        }
        void notifyAll(const Event &e) override
        {
            for (auto *obs : observers_)
            {
                obs->update(e);
            }
        }
    };

} // namespace chrono_core
