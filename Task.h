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

    const std::string &getDescription() const;
    bool isCompleted() const;
    bool isPriority() const;
    void setPriority(bool priority);
    const Date &getDueDate() const;

    void editDescription(const std::string& newDesc);
    void editDueDate(const Date& newDueDate);
    std::string toString() const;       //Metodo per convertire gli attributi in un unica stringa
};


#endif //PROGETTO_TASK_H
