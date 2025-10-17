#include <iostream>
#include "TaskFactory.h"
#include "SchedulerFactory.h"
#include "Operators.h"
#include "../Event/EventManager.h"
#include "Logger.h"

using namespace chrono_core;

int main()
{
    // Factories
    auto t1 = TaskFactory::create("simple", 1, 3);
    auto t2 = TaskFactory::create("recurring", 2, 7);
    auto t3 = TaskFactory::create("dependent", 3, 5);
    auto sch = SchedulerFactory::create("priority");

    // Logger
    Logger<std::string> l;
    l.log("hello");

    // Operators
    std::cout << *t1 << " ==? " << *t3 << " => " << ((*t1 == *t3) ? "true" : "false") << "\n";
    std::cout << "prio sum = " << (*t1 + *t2) << "\n";

    // Use scheduler to execute
    sch->addTask(t1.get());
    sch->addTask(t2.get());
    sch->addTask(t3.get());
    sch->scheduleTasks();
    return 0;
}
