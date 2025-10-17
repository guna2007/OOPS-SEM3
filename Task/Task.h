// ChronoCore - Task Hierarchy: Task (abstract base)
// Encapsulates common data and behavior for all tasks.
// Demonstrates: Inheritance from ITask, Encapsulation via private members, State pattern via TaskStateBase.

#pragma once

#include <memory>
#include <string>
#include <iostream>

#include "../CoreInterfaces/ITask.h"
#include "TaskStateBase.h"
#include "../CoreInterfaces/ISubject.h"

namespace chrono_core
{

    class Task : public ITask
    {
    protected:
        int id_;
        int priority_;
        TaskStatus status_;
        std::unique_ptr<TaskStateBase> currentState_;
        ISubject *notifier_{nullptr}; // aggregation: notify on state changes

    public:
        Task(int id, int priority);
        virtual ~Task() = default; // Polymorphic deletion

        // ITask interface
        int getPriority() const override { return priority_; }
        TaskStatus getStatus() const override { return status_; }

        // Accessors
        int getId() const { return id_; }
        void setPriority(int p) { priority_ = p; }
        void setStatus(TaskStatus s) { status_ = s; }

        // State management
        void setState(std::unique_ptr<TaskStateBase> next);
        const TaskStateBase *getState() const { return currentState_.get(); }

        // Event notifier hookup
        void setNotifier(ISubject *n) { notifier_ = n; }
        ISubject *getNotifier() const { return notifier_; }

        // Execute remains abstract for concrete subclasses to implement custom behavior.
        void execute() override = 0;
    };

} // namespace chrono_core
