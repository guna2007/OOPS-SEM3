// MemoryResource concrete resource
#pragma once

#include "Resource.h"

namespace chrono_core
{

    class MemoryResource : public Resource
    {
    public:
        explicit MemoryResource(const std::string &name) : Resource(name) {}
        const char *typeName() const override { return "Memory"; }
    };

} // namespace chrono_core
