// ChronoCore - Core Interfaces: IResource
// Abstract resource type (e.g., CPU, Memory). Schedulers/tasks may request resources before execution.
// Demonstrates: Abstraction and polymorphic deletion safety.

#pragma once

namespace chrono_core
{

    class IResource
    {
    public:
        virtual ~IResource() = default; // Ensure derived destructors run

        // Attempt to allocate the resource; returns true if allocation succeeded.
        virtual bool allocate() = 0;

        // Release the resource back to the pool.
        virtual void release() = 0;

        // Query current availability without mutating state.
        virtual bool isAvailable() const = 0;
    };

} // namespace chrono_core
