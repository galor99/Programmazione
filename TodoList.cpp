//
// Created by Lorenzo on 14/03/2023.
//

#include "TodoList.h"
#include <iostream>
#include <sstream>
#include <limits>

void TodoList::addTask() {
    std::string desc, input;
    int choice, d, m, y;
    bool prio;

    std::cout << std::endl << "Dai una descrizione al tuo Task: ";
    std::cin >> std::ws;
    std::getline(std::cin, desc);
    std::cout << std::endl;

    std::cout << "Il tuo Task ha un'alta priorita'?" << std::endl << "0) No" << std::endl << "1) Si" << std::endl;       //TODO fare controllo della scelta entro il range
    std::cin >> choice;
    if(choice==1) prio=true;
    else prio=false;

    std::cout << "Inserisci la data di scadenza del Task nel formato gg/mm/aaaa (altrimenti premi invio per saltare)" << std::endl;
    std::cin.ignore();
    std::getline(std::cin, input);

    if(input.empty() == true){
        Task* t = new Task(desc, Date(9999,9999,9999), prio);
        list.push_back(t);
        std::cout << std::endl << std::endl;
    } else{
        std::istringstream ss(input);
        char delimiter;
        ss >> d >> delimiter >> m >> delimiter >> y;
        Task* t = new Task(desc, Date(d, m, y), prio);
        list.push_back(t);
    }

    std::cout << "Il Task e' stato aggiunto correttamente!" << std::endl << std::endl;

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
    for(auto it = list.begin(); it != list.end(); it++){
        std::cout << c << " | ";
        (*it)->viewTask();
        c++;
    }
}

void TodoList::updateFile(){
    std::remove("list.txt");

    std::ofstream file("list.txt");

    for(auto it = list.begin(); it != list.end(); it++){
        file << (*it)->getDescription() << "," << (*it)->getDueDate().getDay() << "," << (*it)->getDueDate().getMonth() << "," << (*it)->getDueDate().getYear() << "," << (*it)->isPriority() << "," << (*it)->isCompleted() << "\n";
    }
    file.close();
}

void TodoList::readFile() {
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
