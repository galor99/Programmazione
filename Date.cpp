//
// Created by Lorenzo on 14/03/2023.
//

#include <iostream>
#include "Date.h"

Date::Date(int day, int month, int year) : day(day), month(month), year(year) {
    isValidDate(day, month, year);
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



void Date::isValidDate(int d, int m, int y) {      //Metodo per verificare se la data inserita è valida
    if(d < 1 || d > 31 || m < 1 || m > 12 || y < 0){
        throw std::invalid_argument("Data non valida");
    }

    if(m == 2){     //Controlli per il mese di febbraio
        int max_day = 28;

        if((y % 4 == 0 && y % 100 != 0) || y % 400 == 0){
            max_day = 29;
        }

        if(d > max_day){
            throw std::invalid_argument("Data non valida");
        }
    }

    if((m == 4 || m == 6 || m == 9 || m == 11) && d > 30){        //Controllo per i mesi con 30 giorni
        throw std::invalid_argument("Data non valida");
    }

    day = d;
    month = m;
    year = y;
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

