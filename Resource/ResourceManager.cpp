#include "ResourceManager.h"

namespace chrono_core
{

    Resource *ResourceManager::acquireFirstAvailable()
    {
        for (auto &r : resources_)
        {
            if (r->isAvailable() && r->allocate())
            {
                return r.get();
            }
        }
        std::cout << "[ResourceManager] No available resources" << '\n';
        return nullptr;
    }

    void ResourceManager::releaseAll()
    {
        for (auto &r : resources_)
        {
            if (!r->isAvailable())
            {
                r->release();
            }
        }
    }

} // namespace chrono_core
