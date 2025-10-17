// Resource System: Base Resource (abstract) implementing IResource
#pragma once

#include <string>
#include <iostream>
#include "../CoreInterfaces/IResource.h"

namespace chrono_core
{

    class Resource : public IResource
    {
    protected:
        std::string name_;
        bool available_{true};

    public:
        explicit Resource(std::string name) : name_(std::move(name)) {}
        virtual ~Resource() = default;

        bool allocate() override;
        void release() override;
        bool isAvailable() const override { return available_; }

        const std::string &name() const { return name_; }
        virtual const char *typeName() const = 0; // keeps class abstract
    };

} // namespace chrono_core
