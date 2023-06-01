//
// Created by Lorenzo on 14/03/2023.
//

#ifndef PROGETTO_TASK_H
#define PROGETTO_TASK_H

#include <string>
#include "Date.h"
#include <fstream>


class Task {
private:
    std::string description;
    bool completed, priority;
    Date dueDate;

public:
    Task(const std::string& desc, Date dd, bool prio = false, bool comp = false) : description(desc), dueDate(dd), priority(prio), completed(comp) {}
    virtual ~Task() {}

    const std::string &getDescription() const;
    bool isCompleted() const;
    bool isPriority() const;
    const Date &getDueDate() const;

    void viewTask() const;      //metodo per visualizzare un Task
    void editTask(int choice);      //metodo per la modifica degli attributi di un Task
};


#endif //PROGETTO_TASK_H
