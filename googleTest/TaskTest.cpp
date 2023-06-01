//
// Created by Lorenzo on 15/05/2023.
//

#include <gtest/gtest.h>
#include "../Task.h"

TEST(Task, ViewTaskTest){       //Test sulla corretta visualizzazione di un task
    Task t("prova", Date(20, 11, 2026), true);

    std::stringstream output;
    std::streambuf* oldCoutBuffer = std::cout.rdbuf(output.rdbuf());
    t.viewTask();
    std::cout.rdbuf(oldCoutBuffer);

    std::string expectedOutput = "prova | Data di scadenza: 20/11/2026 | PRIORITA' ALTA | Da fare\n";
    ASSERT_EQ(output.str(), expectedOutput);
}

TEST(Task, EditTaskTest){       //Test sulla modifica di un test
    Task t("prova", Date(10, 10, 2025), true);

    t.editTask(1);      //Test sulla corretta modifica della completezza
    ASSERT_EQ(true, t.isCompleted());

    t.editTask(3);      //Test sulla corretta modifica della priorita'
    ASSERT_EQ(false, t.isPriority());
}