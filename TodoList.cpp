//
// Created by Lorenzo on 14/03/2023.
//

#include "TodoList.h"
#include <iostream>
#include <sstream>
#include <limits>

void TodoList::addTask() {      //Metodo per aggiungere un task alla lista
    std::string desc, input;
    int choice, d, m, y;
    bool prio, valid;

    std::cout << std::endl << "Dai una descrizione al tuo Task: ";
    std::cin >> std::ws;
    std::getline(std::cin, desc);
    std::cout << std::endl;

    do{
        std::cout << "Il tuo Task ha un'alta priorita'?" << std::endl << "0) No" << std::endl << "1) Si" << std::endl;
        std::cin >> choice;
        if(choice < 0 || choice > 1){
            std::cout << "Hai inserito un valore non valido, riprova!" << std::endl;
            valid = false;
        } else{
            valid = true;
        }
        if(choice==1) prio=true;
        else prio=false;
    } while(valid != true);

    std::cin.ignore();

    do {
        std::cout << "Inserisci la data di scadenza del Task nel formato gg/mm/aaaa (altrimenti premi invio per saltare)" << std::endl;
        std::getline(std::cin, input);

        if (input.empty() == true) {        //Se non si e' inserito niente
            Task *t = new Task(desc, Date(9999, 9999, 9999), prio);
            list.push_back(t);
            std::cout << std::endl << std::endl;
            valid = true;
        } else {
            std::istringstream ss(input);
            char delimiter;
            ss >> d >> delimiter >> m >> delimiter >> y;
            try{
                valid = true;
                Date dueDate = Date(d, m, y);
                if(valid == true) {
                    Task *t = new Task(desc, dueDate, prio);
                    list.push_back(t);
                }

            } catch (const std::invalid_argument& e) {
                std::cout << e.what() << std::endl;
                valid = false;
            }
        }
    } while(valid != true);

    std::cout << "Il Task e' stato aggiunto correttamente!" << std::endl << std::endl;

}

void TodoList::removeTask(int pos) {        //Metodo per rimuovere un task dalla lista
    auto it = list.begin();
    std::advance(it,pos);
    list.erase(it);
    std::cout << std::endl << "Il Task e' stato rimosso correttamente!" << std::endl << std::endl;
}

void TodoList::viewList() const {       //Metodo per visualizzare tutti i task della lista
    int c=0;
    for(auto it = list.begin(); it != list.end(); it++){
        std::cout << c << " | ";
        (*it)->viewTask();
        c++;
    }
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

const std::string &TodoList::getName() const {
    return name;
}
