#include <iostream>
#include <sstream>
#include "TodoList.h"


int main() {
    std::string desc, input;
    int choice, choice2, d, m, y;
    bool prio = false;

    TodoList mainTodoList = TodoList();

    std::cout << "Benvenuto!" << std::endl;

    if(mainTodoList.list.empty()==true){
        std::cout << "La tua lista di cose da fare e' vuota!" << std::endl << "Inizia inserendo il tuo primo Task!" << std::endl << std::endl;

        std::cout << "Dai una descrizione al tuo Task: ";
        std::getline(std::cin, desc);
        std::cout << std::endl;

        std::cout << "Il tuo Task ha un'alta priorita'?" << std::endl << "0) No" << std::endl << "1) Si" << std::endl;       //TODO fare controllo della scelta entro il range
        std::cin >> choice2;
        if(choice2==1) prio=true;

        std::cout << "Inserisci la data di scadenza del Task nel formato gg/mm/aaaa (altrimenti premi invio per saltare)" << std::endl;
        std::cin.ignore();
        std::getline(std::cin, input);

        if(input.empty() == true){
            Task* t = new Task(desc, prio);
            mainTodoList.addTask(t);
            std::cout << std::endl << std::endl;
        } else{
            std::istringstream ss(input);
            char delimiter;
            ss >> d >> delimiter >> m >> delimiter >> y;
            Date dueDate(d, m, y);
            Task* t = new Task(desc, prio, dueDate);
            mainTodoList.addTask(t);
        }

    }

    do{
        std::cout << "Lista delle cose da fare:" << std::endl;
        mainTodoList.viewList();
        std::cout << std::endl;

        std::cout << "0) Esci" << std::endl;
        std::cout << "1) Aggiungi un Task alla lista" << std::endl;
        std::cout << "2) Rimuovi un Task dalla lista" << std::endl;
        std::cout << "3) Modifica un Task della lista" << std::endl;

        std::cin >> choice;

        switch (choice) {

            case 1:
                std::cout << std::endl << "Dai una descrizione al tuo Task: ";
                std::cin.ignore();
                std::getline(std::cin, desc);
                std::cout << std::endl;

                std::cout << "Il tuo Task ha un'alta priorita'?" << std::endl << "0) No" << std::endl << "1) Si" << std::endl;       //TODO fare controllo della scelta entro il range
                std::cin >> choice2;
                if(choice2==1) prio=true;

                std::cout << "Inserisci la data di scadenza del Task nel formato gg/mm/aaaa (altrimenti premi invio per saltare)" << std::endl;
                std::cin.ignore();
                std::getline(std::cin, input);

                if(input.empty() == true){
                    Task* t = new Task(desc, prio);
                    mainTodoList.addTask(t);
                    std::cout << std::endl << std::endl;
                } else{
                    std::istringstream ss(input);
                    char delimiter;
                    ss >> d >> delimiter >> m >> delimiter >> y;
                    Date dueDate(d, m, y);
                    Task* t = new Task(desc, prio, dueDate);
                    mainTodoList.addTask(t);
                }

                break;

            case 2:
                std::cout << std::endl << "Lista delle cose da fare:" << std::endl;
                mainTodoList.viewList();
                std::cout << std::endl;
                std::cout << "Inserisci l'indice del Task da rimuovere dalla lista: ";
                std::cin >> choice2;
                mainTodoList.removeTask(choice2);
                break;

            case 3:
                std::cout << std::endl << "Lista delle cose da fare:" << std::endl;
                mainTodoList.viewList();
                std::cout << std::endl;
                std::cout << "Inserisci l'indice del Task da modificare nella lista: ";
                std::cin >> choice2;

                auto it = mainTodoList.list.begin();
                std::advance(it,choice2);
                (*it)->viewTask();

                std::cout << std::endl;
                std::cout << "Come vuoi modificare il Task?" << std::endl;
                std::cout << "0) Indietro" << std::endl;
                std::cout << "1) Contrassegna come completato" << std::endl;
                std::cout << "2) Modifica la descrizione" << std::endl;
                std::cout << "3) Cambia La priorita'" << std::endl;
                std::cout << "4) Modifica la data di scadenza"<< std::endl;
                std::cin >> choice2;
                std::cout << std::endl << std::endl;

                (*it)->editTask(choice2);
                break;

        }
    } while(choice!=0);

    std::cout << "Buona Giornata!" << std::endl;
    return 0;
}
