#include <iostream>
#include <sstream>
#include <fstream>
#include "TodoList.h"


int main() {
    std::string desc, input;
    int choice, choice2;

    TodoList mainTodoList = TodoList();

    std::cout << "Benvenuto!" << std::endl;

    std::ifstream file("list.txt");
    if(file.peek() != std::ifstream::traits_type::eof()) {       //Controlla se il file non e' vuoto
        file.close();
        mainTodoList.readFile();
    }

    do{
        std::ifstream file("list.txt");
        if(file.peek() == std::ifstream::traits_type::eof()){       //Controlla se il file e' vuoto
            file.close();

            std::cout << "La tua lista di cose da fare e' vuota!" << std::endl << "Inizia inserendo il tuo primo Task!" << std::endl;
            mainTodoList.addTask();
            mainTodoList.updateFile();

        }

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
                mainTodoList.addTask();
                mainTodoList.updateFile();
                break;

            case 2:
                std::cout << std::endl << "Lista delle cose da fare:" << std::endl;
                mainTodoList.viewList();
                std::cout << std::endl;
                std::cout << "Inserisci l'indice del Task da rimuovere dalla lista: ";
                std::cin >> choice2;
                mainTodoList.removeTask(choice2);
                mainTodoList.updateFile();
                //mainTodoList.sortByDates();       //TODO non funziona
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
                mainTodoList.updateFile();
                //mainTodoList.sortByDates();       //TODO non funziona
                break;

        }
    } while(choice!=0);

    std::cout << "Buona Giornata!" << std::endl;
    return 0;
}
