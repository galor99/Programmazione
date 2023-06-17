//
// Created by Lorenzo on 14/03/2023.
//

#include <iostream>
#include <sstream>
#include "Task.h"


const std::string &Task::getDescription() const {
    return description;
}

bool Task::isCompleted() const {
    return completed;
}

bool Task::isPriority() const {
    return priority;
}

const Date &Task::getDueDate() const {
    return dueDate;
}

std::string Task::toString() const {        //Metodo per convertire gli attributi in un unica stringa
    std::stringstream ss;
    ss << description << " | ";
    if(dueDate.getDay() != 9999 && dueDate.getMonth() != 9999 && dueDate.getYear() != 9999)
        ss << dueDate.toString() << " | ";
    if(priority == true)
        ss << "ALTA PRIORITA' ";
    return ss.str();
}

void Task::editDescriprion(std::string& newDesc) {
    description=newDesc;
}

void Task::editDueDate(Date newDueDate) {
    dueDate = newDueDate;
}

void Task::setPriority(bool priority) {
    Task::priority = priority;
}


