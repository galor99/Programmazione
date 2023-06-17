//
// Created by Lorenzo on 15/05/2023.
//

#include <gtest/gtest.h>
#include "../Date.h"

TEST(Date, ConstructorTest){
    ASSERT_NO_THROW(Date d = Date(12, 5, 2026));        //Controllo se il costruttore non lancia eccezioni
}

TEST(Date, ValidDateTest){      //Test sulla validita' della data
    ASSERT_NO_THROW(Date date = Date(12, 3 ,2025));      //Data valida
    ASSERT_THROW(Date date2 = Date(20, 15, 2023), std::invalid_argument);       //Data non valida
    ASSERT_THROW(Date date3 = Date(10, 5, 1980), std::invalid_argument);        //Data non valida
}

TEST(Date, ViewDateTest){       //Test sulla corretta visualizzazione della data
    Date d = Date(17, 12, 2027);

    std::string s = d.toString();

    std::string expectedOutput = "17/12/2027";
    ASSERT_EQ(s, expectedOutput);        //confronto l'output generato dal metodo con quello previsto
}