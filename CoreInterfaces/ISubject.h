// ChronoCore - Core Interfaces: ISubject
// Subject contract for managing observers and broadcasting events.
// Demonstrates: Abstraction for the Observer pattern.

#pragma once

#include <vector>
#include "IObserver.h"

namespace chrono_core
{

    class ISubject
    {
    public:
        virtual ~ISubject() = default; // Virtual destructor for safe polymorphic deletion

        // Register an observer to receive updates.
        virtual void addObserver(IObserver *obs) = 0;

        // Unregister a previously added observer.
        virtual void removeObserver(IObserver *obs) = 0;

        // Notify all observers with the given event.
        virtual void notifyAll(const Event &e) = 0;
    };

} // namespace chrono_core
