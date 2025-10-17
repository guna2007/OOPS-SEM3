// CPUResource concrete resource
#pragma once

#include "Resource.h"

namespace chrono_core
{

    class CPUResource : public Resource
    {
    public:
        explicit CPUResource(const std::string &name) : Resource(name) {}
        const char *typeName() const override { return "CPU"; }
    };

} // namespace chrono_core
