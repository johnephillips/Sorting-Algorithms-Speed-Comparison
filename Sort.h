//
// Created by John on 2017-05-17.
//

#ifndef COMPARINGSORTS_SORT_H
#define COMPARINGSORTS_SORT_H

#include <vector>
#include "Show.h"

namespace sort {
    void insertionSort(std::vector<Show> &show, long long &comparisons, long long &moves);
    void mergesort(std::vector<Show> &show, long long &comparisons, long long &moves);
    //left is inclusive, right is exclusive
    void splitMerge(std::vector<Show> &temp, int left, int right, std::vector<Show> &show, long long &comparisons, long long &moves);
    void merge(std::vector<Show> &temp, int left, int mid, int right, std::vector<Show> &show, long long &comparisons, long long &moves);
    void quicksort(std::vector<Show> &show, long long &comparisons, long long &moves);
    void recurseQuicksort(std::vector<Show> &show, int left, int right, long long &comparisons, long long &moves);
    int splitQuick(std::vector<Show> &show, int left, int right, long long &comparisons, long long &moves);
    void swap(Show &a, Show &b);
}

#endif //COMPARINGSORTS_SORT_H
