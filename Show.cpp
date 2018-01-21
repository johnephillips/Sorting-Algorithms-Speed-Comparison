//
// Created by John on 2017-05-16.
//

#include "Show.h"

void readIn(std::ifstream &fin, int &val) {
    std::string temp;
    getline(fin, temp, ',');
    val = (int)atof(temp.c_str());
}

void readIn(std::ifstream &fin, int &val, const char &delim) {
    std::string temp;
    getline(fin, temp, delim);
    val = (int)atof(temp.c_str());
}

void readIn(std::ifstream &fin, std::string &str) {
    getline(fin, str, ',');
}

void parseLine(std::ifstream &fin, Show &s) {
    readIn(fin, s.attendance);
    readIn(fin, s.capacity);
    readIn(fin, s.day);
    std::string garbage;
    readIn(fin, garbage);
    readIn(fin, s.gross);
    readIn(fin, s.grossPotential);
    readIn(fin, s.month);
    readIn(fin, s.name);
    readIn(fin, s.performances);
    readIn(fin, s.theatre);
    readIn(fin, s.type);
    readIn(fin, s.year, '\n');
}

void print(Show s) {
    std::cout << s.attendance << ", " << s.capacity << ", " << s.day << ", " << s.gross << ", " <<
              s.grossPotential << ", " << s.month << ", " << s.name << ", " <<
              s.performances << ", " << s.theatre << ", " << s.type << ", " << s.year << std::endl;
}