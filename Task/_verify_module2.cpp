#include <memory>
#include "SimpleTask.h"
#include "DependentTask.h"
#include "RecurringTask.h"
#include "HybridTask.h"

using namespace chrono_core;

int main()
{
    SimpleTask s(1, 5);
    DependentTask d(2, 10, {1});
    RecurringTask r(3, 2, 3);
    HybridTask h(4, 7, {2, 3}, 2);

    s.execute();
    d.execute();
    r.execute();
    h.execute();
    return 0;
}
