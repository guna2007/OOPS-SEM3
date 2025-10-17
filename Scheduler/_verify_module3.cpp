#include "../Task/SimpleTask.h"
#include "../Task/DependentTask.h"
#include "../Task/RecurringTask.h"
#include "FIFOScheduler.h"
#include "PriorityScheduler.h"
#include "RoundRobinScheduler.h"
#include "HybridScheduler.h"

using namespace chrono_core;

int main()
{
    SimpleTask s(1, 5);
    DependentTask d(2, 10, {1});
    RecurringTask r(3, 2, 2);

    FIFOScheduler fifo;
    fifo.addTask(&s);
    fifo.addTask(&d);
    fifo.addTask(&r);
    fifo.scheduleTasks();

    PriorityScheduler prio;
    prio.addTask(&s);
    prio.addTask(&d);
    prio.addTask(&r);
    prio.scheduleTasks();

    RoundRobinScheduler rr(1);
    rr.addTask(&s);
    rr.addTask(&d);
    rr.addTask(&r);
    rr.scheduleTasks();

    HybridScheduler hy;
    hy.addTask(&s);
    hy.addTask(&d);
    hy.addTask(&r);
    hy.scheduleTasks();

    return 0;
}
