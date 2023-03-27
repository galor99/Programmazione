//
// Created by Lorenzo on 14/03/2023.
//

#ifndef PROGETTO_TODOLIST_H
#define PROGETTO_TODOLIST_H

#include <list>
#include "Task.h"


class TodoList {
public:
    std::list<Task*> list;

    TodoList() {}
    virtual ~TodoList() {}

    void addTask(Task* t);
    void removeTask(int pos);
    void viewList() const;
};


#endif //PROGETTO_TODOLIST_H
