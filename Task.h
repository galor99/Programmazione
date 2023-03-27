//
// Created by Lorenzo on 14/03/2023.
//

#ifndef PROGETTO_TASK_H
#define PROGETTO_TASK_H

#include <string>
#include "Date.h"


class Task {
private:
    std::string description;
    bool completed, priority;
    Date dueDate;

public:
    explicit Task(std::string description, bool priority=false, Date dueDate=Date(), bool completed=false) : description(description), priority(priority), dueDate(dueDate), completed(completed) {}
    virtual ~Task() {}

    const std::string &getDescription() const;
    void setDescription(const std::string &description);
    bool isCompleted() const;
    void setCompleted(bool completed);
    bool isPriority() const;
    void setPriority(bool priority);

    void viewTask() const;      //metodo per visualizzare un Task
    void editTask(int choice);
};


#endif //PROGETTO_TASK_H
