// Template ResourcePool<T>: generic pool handler
#pragma once

#include <vector>
#include <memory>
#include <functional>
#include <type_traits>

namespace chrono_core
{

    template <typename T>
    class ResourcePool
    {
        // Constrain T to be derived from chrono_core::Resource
        static_assert(std::is_base_of<chrono_core::Resource, T>::value, "T must derive from Resource");
        std::vector<std::unique_ptr<T>> pool_;

    public:
        void add(std::unique_ptr<T> r) { pool_.push_back(std::move(r)); }

        template <typename Pred>
        T *acquire(Pred p)
        {
            for (auto &r : pool_)
            {
                if (p(*r) && r->isAvailable() && r->allocate())
                {
                    return r.get();
                }
            }
            return nullptr;
        }

        void releaseAll()
        {
            for (auto &r : pool_)
            {
                if (!r->isAvailable())
                    r->release();
            }
        }
    };

} // namespace chrono_core
