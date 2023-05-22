//
// Created by Lorenzo on 15/05/2023.
//

#include <gtest/gtest.h>
#include "../TodoList.h"

TEST(TodoList, AddTaskTest){
    TodoList l;

    std::istringstream input("Description\n0\n10/12/2025\n");
    std::cin.rdbuf(input.rdbuf());

    l.addTask();
    auto it = l.list.begin();
    std::advance(it,1);
    ASSERT_EQ(1, l.list.size());
    ASSERT_EQ("Description", (*it)->getDescription());
    ASSERT_EQ(10, (*it)->getDueDate().getDay());
    ASSERT_EQ(12, (*it)->getDueDate().getMonth());
    ASSERT_EQ(2025, (*it)->getDueDate().getYear());
    ASSERT_FALSE((*it)->isPriority());

    std::cin.rdbuf(std::cin.rdbuf());
}

TEST(TodoList, RemoveTaskTest){
    TodoList l;

    std::istringstream input("Description\n1\n15/8/2024\n");
    std::cin.rdbuf(input.rdbuf());
    l.addTask();

    l.removeTask(0);
    ASSERT_EQ(0, l.list.size());

    std::cin.rdbuf(std::cin.rdbuf());
}