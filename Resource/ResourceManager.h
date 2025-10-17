// ResourceManager: composition of Resource objects, provides simple allocate/release across pool
#pragma once

#include <vector>
#include <memory>
#include <iostream>

#include "Resource.h"

namespace chrono_core
{

    class ResourceManager
    {
        std::vector<std::unique_ptr<Resource>> resources_;

    public:
        void add(std::unique_ptr<Resource> r) { resources_.push_back(std::move(r)); }

        Resource *acquireFirstAvailable();
        void releaseAll();
    };

} // namespace chrono_core
