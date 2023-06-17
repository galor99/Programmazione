//
// Created by Lorenzo on 15/05/2023.
//

#include <gtest/gtest.h>
#include "../TodoList.h"

TEST(TodoList, AddTaskTest){        //Test sull'aggiunta di un task alla lista
    TodoList l;
    Task* t = new Task("prova", Date(12, 5, 2030), true);

    l.addTask(t);        //aggiungo l'oggetto alla lista con i dati inseriti prima
    auto it = l.getList().begin();
    ASSERT_EQ(1, l.getList().size());        //controllo se tutti i valori dati in input corrispondono a quelli presenti nella lista
    ASSERT_EQ("prova", (*it)->getDescription());
    ASSERT_EQ(12, (*it)->getDueDate().getDay());
    ASSERT_EQ(5, (*it)->getDueDate().getMonth());
    ASSERT_EQ(2030, (*it)->getDueDate().getYear());
    ASSERT_TRUE((*it)->isPriority());
}

TEST(TodoList, RemoveTaskTest){     //Test sulla rimozione di un task dalla lista
    TodoList l;
    Task* t = new Task("description", Date(15, 8, 2024), true);

    l.addTask(t);        //aggiungo il task alla lista

    l.removeTask(0);        //rimuovo il task dalla lista
    ASSERT_EQ(0, l.getListSize());      //controllo se la dimensione della lista e' corretta dopo la rimozione del task
}

TEST(TodoList, CompletedTest){      //Test sulla completezza di un test
    TodoList l;
    Task* t = new Task("description", Date(15, 8, 2024), true);

    l.addTask(t);        //aggiungo il task alla lista

    l.completed(0);        //segno il task come completato
    ASSERT_EQ(0, l.getListSize());      //controllo se la dimensione della lista e' corretta dopo la rimozione del task data la sua completezza
}

TEST(TodoList, TaskToCompleteTest){
    TodoList l;
    Task* t = new Task("description", Date(20, 8, 2024), true, true);
    Task* t2 = new Task("description2", Date(15, 4, 2026), true);
    Task* t3 = new Task("description3", Date(28, 8, 2030), true);

    l.addTask(t);        //aggiungo il task alla lista
    l.addTask(t2);        //aggiungo il task alla lista
    l.addTask(t3);        //aggiungo il task alla lista

    int c = l.getTasksToComplete();
    ASSERT_EQ(2, c);
}

TEST(TodoList, ListSizeTest){
    TodoList l;
    Task* t = new Task("description", Date(20, 8, 2024), true, true);
    Task* t2 = new Task("description2", Date(15, 4, 2026), true);
    Task* t3 = new Task("description3", Date(28, 8, 2030), true);

    l.addTask(t);        //aggiungo il task alla lista
    l.addTask(t2);        //aggiungo il task alla lista
    l.addTask(t3);        //aggiungo il task alla lista

    int c = l.getListSize();
    ASSERT_EQ(3, c);
}

