#include "CPUResource.h"
#include "MemoryResource.h"
#include "ResourceManager.h"
#include "ResourcePool.h"

using namespace chrono_core;

int main()
{
    ResourceManager rm;
    rm.add(std::make_unique<CPUResource>("CPU-0"));
    rm.add(std::make_unique<MemoryResource>("MEM-0"));

    auto *r1 = rm.acquireFirstAvailable();
    (void)r1;
    rm.releaseAll();

    ResourcePool<CPUResource> pool;
    pool.add(std::make_unique<CPUResource>("CPU-1"));
    pool.add(std::make_unique<CPUResource>("CPU-2"));
    CPUResource *cpu = pool.acquire([](const CPUResource &)
                                    { return true; });
    (void)cpu;
    pool.releaseAll();
    return 0;
}
