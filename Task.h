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
    //Task(std::string description, Date dueDate, bool priority=false, bool completed=false) : description(description), dueDate(dueDate), priority(priority), completed(completed) {}
    Task(std::string desc, Date dd, bool prio = false, bool comp = false) : description(desc), dueDate(dd), priority(prio), completed(comp) {}
    virtual ~Task() {}

    const std::string &getDescription() const;
    void setDescription(const std::string &description);
    bool isCompleted() const;
    void setCompleted(bool completed);
    bool isPriority() const;
    void setPriority(bool priority);
    const Date &getDueDate() const;
    void setDueDate(const Date &dueDate);

    void viewTask() const;      //metodo per visualizzare un Task
    void editTask(int choice);
};


#endif //PROGETTO_TASK_H
