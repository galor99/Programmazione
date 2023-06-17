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
    std::list<Task*> list;
public:
    TodoList(std::string name = "Todolist") : name(name) {}

    const std::string &getName() const;
    const std::list<Task *> &getList() const;

    void addTask(Task* t);     //Metodo per aggiungere un task alla lista
    void removeTask(int pos);       //Metodo per rimuovere un task dalla lista
    std::string toString() const;      //Metodo per convertire gli attributi in un unica stringa
    void updateFile();      //Metodo per aggiornare il file
    void readFile();        //Metodo per leggere il file
    int getListSize();      //Metodo che ritorna il numero di elementi della lista
    int getTasksToComplete();       //Metodo che ritorna quanti Task devono essere completati
    void completed(int pos);        //Metodo che rimuove dalla lista un task completato
};


#endif //PROGETTO_TODOLIST_H
