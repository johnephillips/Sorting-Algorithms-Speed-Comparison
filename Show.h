//
// Created by John on 2017-05-16.
//

#ifndef COMPARINGSORTS_SHOW_H
#define COMPARINGSORTS_SHOW_H

#include <iostream>
#include <fstream>
#include <cstdlib>

//Attendance,Capacity,Day,Full,Gross,Gross Potential,Month,Name,Performances,Theatre,Type,Year is the file template
//Full is the full date, and it is ignored.
struct Show {
    int attendance, capacity, day, month, year, gross, grossPotential, performances;
    std::string name, theatre, type;
};

void readIn(std::ifstream &fin, int &val);
void readIn(std::ifstream &fin, int &val, const char &delim);
void readIn(std::ifstream &fin, std::string &str);
void parseLine(std::ifstream &fin, Show &s);
void print(Show s);

#endif //COMPARINGSORTS_SHOW_H
