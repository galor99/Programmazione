//
// Created by Lorenzo on 14/03/2023.
//

#include <iostream>
#include "Date.h"

Date::Date(int day, int month, int year) {      //Costruttore che fa partire il metodo isValidDate per verificare se i valori inseriti sono validi, nel caso non lo siano lancia un eccezione
    bool valid = isValidDate(day, month, year);
    if (valid == false)
        throw std::invalid_argument("La data inserita non e' valida, riprova!");
    this->day = day;
    this->month = month;
    this->year = year;

}

int Date::getDay() const {
    return day;
}

int Date::getMonth() const {
    return month;
}

int Date::getYear() const {
    return year;
}


bool Date::isValidDate(int day, int month, int year) {      //Metodo per verificare se la data inserita è valida
    if(day != 9999 && month != 9999 && year != 9999) {
        if (day < 1 || day > 31 || month < 1 || month > 12 || year < 0) {       //Controllo su range dei valori
            return false;
        }

        if (month == 2) {     //Controlli per il mese di febbraio
            int maxDay = 28;

            if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {        //Controllo anno bisestile
                maxDay = 29;
            }

            if (day > maxDay) {
                return false;
            }
        }

        if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {        //Controllo dei i mesi con 30 giorni
            return false;
        }

        time_t t = time(nullptr);           //Controllo se la data inserita e' antecedente a quella attuale
        tm tm = *localtime(&t);
        int currentYear = tm.tm_year + 1900;
        int currentMonth = tm.tm_mon + 1;
        int currentDay = tm.tm_mday;
        if (year < currentYear || (year == currentYear && month < currentMonth) || (year == currentYear && month == currentMonth && day < currentDay)) {
            return false;
        }
        return true;
    }
}


void Date::viewDate() const {     //Metodo per stampare la data
    std::cout << " | Data di scadenza: " << day << "/" << month << "/" << year;
}



