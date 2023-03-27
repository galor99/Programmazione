//
// Created by Lorenzo on 14/03/2023.
//

#ifndef PROGETTO_DATE_H
#define PROGETTO_DATE_H

class Date {
private:
    int day, month, year;

public:
    explicit Date() : day(9999), month(9999), year(9999) {}
    Date(int day, int month, int year);

    int getDay() const;

    void setDay(int day);

    int getMonth() const;

    void setMonth(int month);

    int getYear() const;

    void setYear(int year);

    void isValidDate(int d, int m, int y);     //Metodo per verificare se la data inserita è valida
    void viewDate() const;        //Metodo per stampare la data

    bool operator<(const Date& d) const;
};


#endif //PROGETTO_DATE_H
