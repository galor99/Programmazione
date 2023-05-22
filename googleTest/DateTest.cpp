//
// Created by Lorenzo on 15/05/2023.
//

#include <gtest/gtest.h>
#include "../Date.h"

TEST(Date, ValidDateTest){      //Test sulla validita' della data
    Date d(12, 3, 2025);        //Data valida
    EXPECT_TRUE(d.isValidDate());

    Date d2(20, 15, 2023);      //Data non valida
    EXPECT_FALSE(d2.isValidDate());

    Date d3(10, 5, 1980);       //data non valida
    EXPECT_FALSE(d3.isValidDate());
}

TEST(Date, ViewDateTest){       //Test sulla corretta visualizzazione della data
    Date d(17, 12, 2027);

    std::stringstream output;
    std::streambuf* oldCoutBuffer = std::cout.rdbuf(output.rdbuf());
    d.viewDate();
    std::cout.rdbuf(oldCoutBuffer);

    std::string expectedOutput = " | Data di scadenza: 17/12/2027";
    ASSERT_EQ(output.str(), expectedOutput);
}