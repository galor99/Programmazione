//
// Created by Lorenzo on 14/03/2023.
//

#include <iostream>
#include "Date.h"

Date::Date(int day, int month, int year) : day(day), month(month), year(year) {
    isValidDate();
}


int Date::getDay() const {
    return day;
}

void Date::setDay(int day) {
    Date::day = day;
}

int Date::getMonth() const {
    return month;
}

void Date::setMonth(int month) {
    Date::month = month;
}

int Date::getYear() const {
    return year;
}

void Date::setYear(int year) {
    Date::year = year;
}



bool Date::isValidDate() {      //Metodo per verificare se la data inserita è valida
    if(day != 9999 && month != 9999 && year != 9999) {
        if (day < 1 || day > 31 || month < 1 || month > 12 || year < 0) {
            return false;
        }

        if (month == 2) {     //Controlli per il mese di febbraio
            int maxDay = 28;

            if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
                maxDay = 29;
            }

            if (day > maxDay) {
                return false;
            }
        }

        if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {        //Controllo per i mesi con 30 giorni
            return false;
        }

        time_t t = time(nullptr);           //Controllo se la data inserita e' antecedente a quella attuale
        tm tm = *localtime(&t);
        int currentYear = tm.tm_year + 1900;
        int currentMonth = tm.tm_mon + 1;
        int currentDay = tm.tm_mday;
        if (year < currentYear || (year == currentYear && month < currentMonth) || (year == currentYear && month == currentMonth && day < currentDay)) {
            //throw std::invalid_argument("Data non valida: la data inserita e' antecedente a quella di oggi");
            return false;
        }
        return true;
    }
}


void Date::viewDate() const {     //Metodo per stampare la data
    std::cout << " | Data di scadenza: " << day << "/" << month << "/" << year;
}


bool Date::operator<(const Date &d) const {         //Metodo per il confronto tra date
    if (year < d.year){
        return true;
    } else if(year > d.year){
        return false;
    } else {
        if(month < d.month){
            return true;
        } else if(month > d.month){
            return false;
        } else {
            if(month < d.month){
                return true;
            } else {
                return false;
            }
        }
    }
}

