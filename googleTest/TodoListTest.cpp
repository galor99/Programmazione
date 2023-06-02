//
// Created by Lorenzo on 15/05/2023.
//

#include <gtest/gtest.h>
#include "../TodoList.h"

TEST(TodoList, AddTaskTest){        //Test sull'aggiunta di un task alla lista
    TodoList l;

    std::istringstream input("Description\n0\n10/12/2025\n");       //simulo input da console
    std::cin.rdbuf(input.rdbuf());

    l.addTask();        //aggiungo l'oggetto alla lista con i dati inseriti prima
    auto it = l.list.begin();
    ASSERT_EQ(1, l.list.size());        //controllo se tutti i valori dati in input corrispondono a quelli presenti nella lista
    ASSERT_EQ("Description", (*it)->getDescription());
    ASSERT_EQ(10, (*it)->getDueDate().getDay());
    ASSERT_EQ(12, (*it)->getDueDate().getMonth());
    ASSERT_EQ(2025, (*it)->getDueDate().getYear());
    ASSERT_FALSE((*it)->isPriority());

    std::cin.rdbuf(std::cin.rdbuf());
}

TEST(TodoList, RemoveTaskTest){     //Test sulla rimozione di un task dalla lista
    TodoList l;

    std::istringstream input("Description\n1\n15/8/2024\n");        //simulo l'input da console
    std::cin.rdbuf(input.rdbuf());
    l.addTask();        //aggiungo il task alla lista

    l.removeTask(0);        //rimuovo il task dalla lista
    ASSERT_EQ(0, l.getListSize());      //controllo se la dimensione della lista e' corretta dopo la rimozione del task

    std::cin.rdbuf(std::cin.rdbuf());
}