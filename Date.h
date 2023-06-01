//
// Created by Lorenzo on 14/03/2023.
//

#ifndef PROGETTO_DATE_H
#define PROGETTO_DATE_H

class Date {
private:
    int day, month, year;

public:
    Date() {}
    Date(int day, int month, int year);

    int getDay() const;
    int getMonth() const;
    int getYear() const;

    bool isValidDate(int day, int month, int year);     //Metodo per verificare se la data inserita è valida
    void viewDate() const;        //Metodo per stampare la data

};


#endif //PROGETTO_DATE_H
