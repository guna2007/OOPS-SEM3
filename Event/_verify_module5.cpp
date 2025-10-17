#include "EventManager.h"
#include "UIController.h"
#include "EventConsoleLogger.h"
#include "../Task/SimpleTask.h"

using namespace chrono_core;

int main()
{
    EventManager em;
    UIController ui;
    EventConsoleLogger log;
    em.addObserver(&ui);
    em.addObserver(&log);

    SimpleTask s(1, 3);
    s.setNotifier(&em);
    s.execute();
    return 0;
}
