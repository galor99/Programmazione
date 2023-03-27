//
// Created by Lorenzo on 14/03/2023.
//

#include "TodoList.h"
#include <iostream>

void TodoList::addTask(Task *t) {
    list.push_back(t);
    std::cout << std::endl << "Il Task e' stato aggiunto correttamente!" << std::endl << std::endl;
}

void TodoList::removeTask(int pos) {
    //TODO gestire eccezione posizione out of range tramite if
    auto it = list.begin();
    std::advance(it,pos);
    list.erase(it);     //possibili problemi di aggiustamento della posizione della lista
    std::cout << std::endl << "Il Task e' stato rimosso correttamente!" << std::endl << std::endl;
}

void TodoList::viewList() const {
    int c=0;
    for(auto it=list.begin(); it != list.end(); it++){
        std::cout << c << " | ";
        (*it)->viewTask();
        c++;
    }
}
