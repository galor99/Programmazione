//
// Created by Lorenzo on 14/03/2023.
//

#ifndef PROGETTO_TODOLIST_H
#define PROGETTO_TODOLIST_H

#include <list>
#include "Task.h"


class TodoList {
private:
    std::string name;
public:
    std::list<Task*> list;

    TodoList(std::string name = "Todolist") : name(name) {}
    virtual ~TodoList() {}

    const std::string &getName() const;

    void addTask();     //Metodo per aggiungere un task alla lista
    void removeTask(int pos);       //Metodo per rimuovere un task dalla lista
    void viewList() const;      //Metodo per visualizzare tutti i task della lista
    void updateFile();      //Metodo per aggiornare il file
    void readFile();        //Metodo per leggere il file
    int getListSize();      //Metodo che ritorna il numero di elementi della lista
    int getTasksToComplete();       //Metodo che ritorna quanti Task devono essere completati
};


#endif //PROGETTO_TODOLIST_H
