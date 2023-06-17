//
// Created by Lorenzo on 14/03/2023.
//

#include "TodoList.h"
#include <iostream>
#include <sstream>

void TodoList::addTask(Task* t) {      //Metodo per aggiungere un task alla lista
    list.push_back(t);

}

void TodoList::removeTask(int pos) {        //Metodo per rimuovere un task dalla lista
    auto it = list.begin();
    std::advance(it,pos);
    list.erase(it);
    std::cout << std::endl << "Il Task e' stato rimosso correttamente!" << std::endl << std::endl;
}

std::string TodoList::toString() const {       //Metodo per convertire gli attributi in un unica stringa
    std::stringstream ss;
    int c=0;
    for(auto it = list.begin(); it != list.end(); it++){
        ss << "\n" << c << " | ";
        ss << (*it)->toString();
        c++;
    }
    return ss.str();
}

void TodoList::updateFile(){        //Metodo per aggiornare il file
    std::remove("list.txt");

    std::ofstream file("list.txt");

    for(auto it = list.begin(); it != list.end(); it++){
        file << (*it)->getDescription() << "," << (*it)->getDueDate().getDay() << "," << (*it)->getDueDate().getMonth() << "," << (*it)->getDueDate().getYear() << "," << (*it)->isPriority() << "," << (*it)->isCompleted() << "\n";
    }
    file.close();
}

void TodoList::readFile() {     //Metodo per leggere il file
    std::ifstream file("list.txt");
    std::string line, desc;
    int d, m, y;
    bool prio, completed;

    while(std::getline(file, line)){
        std::istringstream iss(line);
        std::getline(iss, desc, ',');
        iss >> d;
        iss.ignore();   //ignore la ,
        iss >> m;
        iss.ignore();
        iss >> y;
        iss.ignore();
        int temp;
        iss >> temp;
        if(temp == 1) prio = true;
        else prio = false;
        iss.ignore();
        iss >> temp;
        if(temp == 1) completed = true;
        else completed = false;
        Task* t = new Task(desc, Date(d, m, y), prio, completed);
        list.push_back(t);
    }
    file.close();
}

int TodoList::getListSize() {       //Metodo che ritorna il numero di elementi della lista
    return list.size();
}

int TodoList::getTasksToComplete() {        //Metodo che ritorna quanti Task devono essere completati
    int c=0;
    for(auto it = list.begin(); it != list.end(); it++){
        if((*it)->isCompleted() == false)
            c++;
    }
    return c;
}

void TodoList::completed(int pos) {     //Metodo che rimuove dalla lista un task completato
    removeTask(pos);
    std::cout << "Il task e' stato completato!" << std::endl << std::endl;
}


const std::string &TodoList::getName() const {
    return name;
}

const std::list<Task *> &TodoList::getList() const {
    return list;
}


