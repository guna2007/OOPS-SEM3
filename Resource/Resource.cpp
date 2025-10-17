#include "Resource.h"

namespace chrono_core
{

    bool Resource::allocate()
    {
        if (!available_)
        {
            std::cout << "[Resource] " << name_ << " is not available" << '\n';
            return false;
        }
        available_ = false;
        std::cout << "[Resource] Allocated " << typeName() << ": " << name_ << '\n';
        return true;
    }

    void Resource::release()
    {
        available_ = true;
        std::cout << "[Resource] Released " << typeName() << ": " << name_ << '\n';
    }

} // namespace chrono_core
