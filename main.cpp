#include <iostream>
#include <sstream>
#include <fstream>
#include "TodoList.h"


int main() {
    std::string desc, input;
    int c, choice, choice2, choice3, d, m, y;
    bool valid, prio;

    TodoList mainTodoList = TodoList();

    std::cout << "Benvenuto!" << std::endl;

    std::ifstream file("list.txt");
    if(file.peek() != std::ifstream::traits_type::eof()) {       //Controlla se il file non e' vuoto, nel caso non lo sia legge i dati al suo interno
        file.close();
        mainTodoList.readFile();
    }

    do{
        std::ifstream file("list.txt");
        if(file.peek() == std::ifstream::traits_type::eof()){       //Se il file e' vuoto, chiede di inserire il primo task alla lista
            file.close();

            std::cout << "La tua " << mainTodoList.getName() << " e' vuota!" << std::endl << "Inizia inserendo il tuo primo Task!" << std::endl;

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
                } else
                    valid = true;

                if(choice==1)
                    prio=true;
                else
                    prio=false;

            } while(valid != true);

            std::cin.ignore();

            do {
                std::cout << "Inserisci la data di scadenza del Task nel formato gg/mm/aaaa (altrimenti premi invio per saltare)" << std::endl;
                std::getline(std::cin, input);

                if (input.empty() == true) {        //Se non si e' inserito niente
                    Task *t = new Task(desc, Date(9999, 9999, 9999), prio);
                    mainTodoList.addTask(t);
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
                            mainTodoList.addTask(t);
                        }

                    } catch (const std::invalid_argument& e) {
                        std::cout << e.what() << std::endl;
                        valid = false;
                    }
                }
            } while(valid != true);

            std::cout << "Il Task e' stato aggiunto correttamente!" << std::endl << std::endl;
            mainTodoList.updateFile();


        }

        do {        //PRIMO WHILE
            std::cout << "La tua " << mainTodoList.getName() << " ha " << mainTodoList.getListSize() << " Tasks di cui " << mainTodoList.getTasksToComplete() << " da completare." << std::endl;
            std::cout << "Lista delle cose da fare:";
            std::cout << mainTodoList.toString();
            std::cout << std::endl;

            std::cout << "0) Esci" << std::endl;
            std::cout << "1) Aggiungi un Task alla lista" << std::endl;
            std::cout << "2) Rimuovi un Task dalla lista" << std::endl;
            std::cout << "3) Modifica un Task della lista" << std::endl;

            std::cin >> c;

            if (c < 0 || c > 3) {     //controllo scelta non valida
                valid = false;
                std::cout << "La scelta inserita non e' valida, riprova!" << std::endl;
            } else {
                valid = true;
            }
        } while(valid != true);

        switch (c) {

            case 1:     //aggiunta di un task alla lista

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
                    } else
                        valid = true;

                    if(choice==1)
                        prio=true;
                    else
                        prio=false;

                } while(valid != true);

                std::cin.ignore();

                do {
                    std::cout << "Inserisci la data di scadenza del Task nel formato gg/mm/aaaa (altrimenti premi invio per saltare)" << std::endl;
                    std::getline(std::cin, input);

                    if (input.empty() == true) {        //Se non si e' inserito niente
                        Task *t = new Task(desc, Date(9999, 9999, 9999), prio);
                        mainTodoList.addTask(t);
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
                                mainTodoList.addTask(t);
                            }

                        } catch (const std::invalid_argument& e) {
                            std::cout << e.what() << std::endl;
                            valid = false;
                        }
                    }
                } while(valid != true);

                std::cout << "Il Task e' stato aggiunto correttamente!" << std::endl << std::endl;
                mainTodoList.updateFile();

                break;

            case 2:     //rimozione di un task dalla lista
                std::cout << std::endl << "Lista delle cose da fare:";
                std::cout << mainTodoList.toString();
                std::cout << std::endl;
                do{
                    std::cout << "Inserisci l'indice del Task da rimuovere dalla lista: ";
                    std::cin >> choice2;
                    if(choice2 < 0 || choice2 >= mainTodoList.getListSize()){
                        std::cout << "L'indice inserito non e' valido, riprova!" << std::endl;
                        valid = false;
                    } else{
                        valid = true;
                    }
                } while(valid != true);

                mainTodoList.removeTask(choice2);
                mainTodoList.updateFile();
                break;

            case 3:     //modifica di un task della lista
                std::cout << std::endl << "Lista delle cose da fare:";
                std::cout << mainTodoList.toString();
                std::cout << std::endl;
                do{
                    std::cout << "Inserisci l'indice del Task da modificare nella lista: ";
                    std::cin >> choice2;
                    if(choice2 < 0 || choice2 >= mainTodoList.getListSize()){
                        std::cout << "L'indice inserito non e' valido, riprova!" << std::endl;
                        valid = false;
                    } else{
                        valid = true;
                    }
                } while(valid != true);

                auto it = mainTodoList.getList().begin();
                std::advance(it,choice2);
                std::cout << std::endl;
                std::cout << (*it)->toString();

                do{
                    std::cout << std::endl;
                    std::cout << "Come vuoi modificare il Task?" << std::endl;
                    std::cout << "0) Indietro" << std::endl;
                    std::cout << "1) Contrassegna come completato" << std::endl;
                    std::cout << "2) Modifica la descrizione" << std::endl;
                    std::cout << "3) Cambia La priorita'" << std::endl;
                    std::cout << "4) Modifica la data di scadenza"<< std::endl;
                    std::cin >> choice3;
                    std::cout << std::endl << std::endl;
                    if(choice3 < 0 || choice3 > 4){
                        std::cout << "La scelta inserita non e' valida, riprova!" << std::endl;
                        valid = false;
                    } else
                        valid = true;

                } while(valid != true);

                switch(choice3) {
                    case 1:     //Modifica della completezza
                        if ((*it)->isCompleted() == false)
                            mainTodoList.completed(choice2);
                        else std::cout << "Il Task e' gia' contrassegnato come completato!" << std::endl;
                        mainTodoList.updateFile();

                        break;

                    case 2:     //Modifica della descrizione
                        std::cout << "Inserisci la nuova descrione del Task: ";
                        std::cin.ignore();
                        std::getline(std::cin, desc);
                        std::cout << std::endl;
                        (*it)->editDescription(desc);
                        std::cout << "La descrizione e' stata modificata correttamente!" << std::endl;
                        mainTodoList.updateFile();
                        break;

                    case 3:     //Modifica della priorita'
                        if ((*it)->isPriority() == true) (*it)->setPriority(false);
                        else (*it)->setPriority(true);
                        std::cout << "La priorita' del Task e' stata cambiata correttamente!" << std::endl;
                        mainTodoList.updateFile();
                        break;

                    case 4:     //Modifica della data di scadenza
                        std::cin.ignore();
                        do {
                            std::cout
                                    << "Inserisci la nuova data di scadenza del Task nel formato gg/mm/aaaa (altrimenti premi invio per saltare)"
                                    << std::endl;

                            std::getline(std::cin, input);

                            if (input.empty() == true) {        //se non si e' inserito nulla
                                Date dd = Date(9999, 9999, 9999);
                                (*it)->editDueDate(dd);
                                mainTodoList.updateFile();
                                valid = true;
                            } else {
                                valid = true;
                                std::istringstream ss(input);
                                char delimiter;
                                ss >> d >> delimiter >> m >> delimiter >> y;
                                try {
                                    Date dd = Date(d, m, y);
                                    (*it)->editDueDate(dd);
                                    mainTodoList.updateFile();
                                } catch (const std::invalid_argument &e) {
                                    std::cout << e.what() << std::endl;
                                    valid = false;
                                }
                            }
                        } while (valid != true);
                        break;
                }

                break;

        }
    } while(c!=0);     //CHIUSURA PRIMO SWITCH

    std::cout << "Buona Giornata!" << std::endl;
    return 0;
}
