//
// Created by Lorenzo on 14/03/2023.
//

#ifndef PROGETTO_DATE_H
#define PROGETTO_DATE_H

class Date {
private:
    int day, month, year;

public:
    Date(int day, int month, int year);

    int getDay() const;
    int getMonth() const;
    int getYear() const;

    bool isValidDate(int day, int month, int year);     //Metodo per verificare se la data inserita è valida
    std::string toString() const;      //Metodo per convertire gli attributi in un unica stringa

};


#endif //PROGETTO_DATE_H
