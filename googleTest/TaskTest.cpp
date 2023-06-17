//
// Created by Lorenzo on 15/05/2023.
//

#include <gtest/gtest.h>
#include "../Task.h"

TEST(Task, ViewTaskTest){       //Test sulla corretta visualizzazione di un task
    Task t("prova", Date(20, 11, 2026), true);

    std::string s = t.toString();

    std::string expectedOutput = "prova | 20/11/2026 | ALTA PRIORITA' ";
    ASSERT_EQ(s, expectedOutput);        //confronto l'output generato dal metodo con quello previsto
}

TEST(Task, editDescriptionTest){        //Test sulla modifica della descrizione di un task
    Task t("prova", Date(10, 10, 2025), true);
    std::string s = "prova2";
    t.editDescriprion(s);
    ASSERT_EQ(s, t.getDescription());
}

TEST(Task, editDueDateTest){        //Test sulla modifica della data di un task
    Task t("prova", Date(10, 10, 2025), true);
    Date d = Date(20, 12, 2028);
    t.editDueDate(d);
    ASSERT_EQ(20, t.getDueDate().getDay());     //Verifico se il giorno e' stato cambiato
    ASSERT_EQ(12, t.getDueDate().getMonth());       //Verifico se il mese e' stato cambiato
    ASSERT_EQ(2028, t.getDueDate().getYear());      //Verifico se l'anno e' stato cambiato
}
