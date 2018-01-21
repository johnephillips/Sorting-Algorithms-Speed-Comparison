/*****************************************************************************
 *	John Phillips                                                            *
 *	Course: ICS 4U                                                           *
 *	Date: May 24, 2017                                                       *
 *	                                                                         *
 *	Purpose: Compare speed of insertion, merge and quicksort on a csv file   *
 *	                                                                         *
 *	Usage: Just run.                                                         *
 *																			 *
 *	Revision History:                                                        *
 *	                                                                         *
 *	Known Issues: Can't choose which parameter to sort by                    *
 *                                                                           *
 *	                                                                         *
 *****************************************************************************/

#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <thread>
#include "Show.h"
#include "Sort.h"

int main () {
    const std::string file = "broadway.csv";
    std::ifstream fin(file);
    if (!fin) {
        std::cerr << "error opening " << file << std::endl;
    }

    std::vector<Show> show;

    Show tempShow;

    //Read in and ignore template line
    std::string line;
    getline(fin, line);

    //Read in all the show information
    while (fin.good()) {
        parseLine(fin, tempShow);
        show.push_back(tempShow);
    }

    std::vector<Show> toSort(show);
    long long comparisons = 0;
    long long moves = 0;
    //Create reference time point
    std::chrono::high_resolution_clock::time_point epoch = std::chrono::high_resolution_clock::now();

    sort::mergesort(toSort, comparisons, moves);


    std::chrono::duration<float> elapsed = std::chrono::high_resolution_clock::now()-epoch;
    std::cout << "Mergesort: " << elapsed.count() << "s" << std::endl;
    std::cout << "Comparisons: " << comparisons << std::endl;
    std::cout << "Moves: " << moves << std::endl;


    toSort = show;

    epoch = std::chrono::high_resolution_clock::now();

    comparisons = 0;
    moves = 0;

    std::cout << "Takes ~70 seconds, please be patient" << std::endl;
    sort::insertionSort(toSort, comparisons, moves);

    elapsed = std::chrono::high_resolution_clock::now()-epoch;
    std::cout << "Insertion sort: " << elapsed.count() << "s" << std::endl;
    std::cout << "Comparisons: " << comparisons << std::endl;
    std::cout << "Moves: " << moves << std::endl;

    toSort = show;

    epoch = std::chrono::high_resolution_clock::now();

    comparisons = 0;
    moves = 0;
    sort::quicksort(toSort, comparisons, moves);

    elapsed = std::chrono::high_resolution_clock::now()-epoch;
    std::cout << "Quicksort: " << elapsed.count() << "s" << std::endl;
    std::cout << "Comparisons: " << comparisons << std::endl;
    std::cout << "Moves: " << moves << std::endl;

    system("PAUSE");

    return 0;
}