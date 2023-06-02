//
// Created by Lorenzo on 15/05/2023.
//

#include <gtest/gtest.h>
#include "../Date.h"

TEST(Date, ConstructorTest){
    ASSERT_NO_THROW(Date d = Date(12, 5, 2026));        //Controllo se il costruttore non lancia eccezioni
}

TEST(Date, ValidDateTest){      //Test sulla validita' della data
    bool valid;
    Date date = Date();     //Data valida
    Date date2 = Date();       //Data non valida
    Date date3 = Date();        //Data non valida

    valid = date.isValidDate(12, 3 ,2025);
    ASSERT_TRUE(valid);     //Controllo se la data e' effettivamente valida
    valid = date2.isValidDate(20, 15, 2023);
    ASSERT_FALSE(valid);        //Controllo se la data e' effettivamente non valida
    valid = date3.isValidDate(10, 5, 1980);
    ASSERT_FALSE(valid);        //Controllo se la data e' effettivamente non valida
}

TEST(Date, ViewDateTest){       //Test sulla corretta visualizzazione della data
    Date d = Date(17, 12, 2027);

    std::stringstream output;
    std::streambuf* oldCoutBuffer = std::cout.rdbuf(output.rdbuf());
    d.viewDate();
    std::cout.rdbuf(oldCoutBuffer);     //Leggo l'output generato dal metodo

    std::string expectedOutput = " | Data di scadenza: 17/12/2027";
    ASSERT_EQ(output.str(), expectedOutput);        //confronto l'output generato dal metodo con quello previsto
}