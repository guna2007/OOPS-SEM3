// Translation unit that simply includes Core Interfaces to validate syntax during build.
#include "ITask.h"
#include "IScheduler.h"
#include "IResource.h"
#include "IObserver.h"
#include "ISubject.h"

int main()
{
    // No runtime behavior needed for verification.
    return 0;
}
