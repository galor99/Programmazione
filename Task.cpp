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


void Task::viewTask() const {       //metodo per visualizzare un Task
    std::cout << description;
    if(dueDate.getYear() != 9999) dueDate.viewDate();
    if(priority==true)  std::cout << " | PRIORITA' ALTA";
    if(completed==true) std::cout << " | Fatto!";
    else std::cout << " | Da fare";
    std::cout << std::endl;
}

void Task::editTask(int choice) {       //metodo per la modifica degli attributi di un Task
    std::string newDesc;
    std::string input;
    int d , m, y;

    switch(choice){
        case 1:     //Modifica della completezza
            if(completed==false){
                completed=true;
                std::cout << "Il Task e' stato contrassegnato come completato!" << std::endl;
            } else std::cout << "Il Task e' gia' contrassegnato come completato!" << std::endl;

            break;

        case 2:     //Modifica della descrizione
            std::cout << "Inserisci la nuova descrione del Task: ";
            std::cin.ignore();
            std::getline(std::cin, newDesc);
            std::cout << std::endl;
            description=newDesc;
            std::cout << "La descrizione e' stata modificata correttamente!" << std::endl;
            break;

        case 3:     //Modifica della priorita'
            if(priority== true) priority=false;
            else priority= true;
            std::cout << "La priorita' del Task e' stata cambiata correttamente!" << std::endl;
            break;

        case 4:     //Modifica della data di scadenza
            std::cin.ignore();
            bool valid;
            do {
                std::cout << "Inserisci la nuova data di scadenza del Task nel formato gg/mm/aaaa (altrimenti premi invio per saltare)" << std::endl;

                std::getline(std::cin, input);

                if (input.empty() == true) {        //se non si e' inserito nulla
                    dueDate = Date(9999, 9999, 9999);
                    valid = true;
                } else {
                    std::istringstream ss(input);
                    char delimiter;
                    ss >> d >> delimiter >> m >> delimiter >> y;
                    try{
                        Date dd = Date(d, m, y);
                        valid = dd.isValidDate(d, m, y);
                    } catch (const std::invalid_argument& e) {
                        std::cout << e.what() << std::endl;
                    }
                }
            } while(valid != true);
            break;
    }
}


