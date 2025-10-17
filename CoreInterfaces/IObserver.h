// ChronoCore - Core Interfaces: IObserver
// Observer contract for receiving event notifications.
// Demonstrates: Abstraction for Observer pattern integration.

#pragma once

#include <string>

namespace chrono_core
{

    // Minimal event structure forward-declared as a string-based payload for core layer.
    // A richer Event type will be introduced in the Event module.
    struct Event
    {
        std::string type;
        std::string source;
        std::string message;
    };

    class IObserver
    {
    public:
        virtual ~IObserver() = default; // Virtual destructor for polymorphism

        // Receive an event broadcast by a Subject.
        virtual void update(const Event &e) = 0;
    };

} // namespace chrono_core
