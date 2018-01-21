//
// Created by John on 2017-05-17.
//

#include "Sort.h"

namespace sort {
    void insertionSort(std::vector<Show> &show, long long &comparisons, long long &moves){
        for (int i = 1; i < show.size(); i++){
            Show x = show[i];
            int j = i-1;
            while (j >= 0 && show[j].attendance > x.attendance) {
                comparisons++;
                moves++;
                show[j+1] = show[j];
                j--;
            }
            moves++;
            show[j+1] = x;
        }
    }
    void mergesort(std::vector<Show> &show, long long &comparisons, long long &moves) {
        std::vector<Show> temp(show);
        splitMerge(temp, 0, show.size(), show, comparisons, moves);
    }
    void splitMerge(std::vector<Show> &temp, int left, int right, std::vector<Show> &show, long long &comparisons, long long &moves) {
        if (right - left <= 1) {
            return;
        }
        int mid = (left + right)/2;
        splitMerge(show, left, mid, temp, comparisons, moves);
        splitMerge(show, mid, right, temp, comparisons, moves);
        merge(temp, left, mid, right, show, comparisons, moves);
    }
    void merge(std::vector<Show> &temp, int left, int mid, int right, std::vector<Show> &show, long long &comparisons, long long &moves) {
        int i = left, j = mid;
        for (int k = left; k < right; k++) {
            comparisons++;
            moves++;
            if (i < mid && (j >= right || temp[i].attendance <= temp[j].attendance)) {
                show[k] = temp[i];
                i++;
            } else {
                show[k] = temp[j];
                j++;
            }
        }
    }
    void quicksort(std::vector<Show> &show, long long &comparisons, long long &moves) {
        recurseQuicksort(show, 0, show.size()-1, comparisons, moves);
    }
    void recurseQuicksort(std::vector<Show> &show, int left, int right, long long &comparisons, long long &moves) {
        if (left < right) {
            int pivot = splitQuick(show, left, right, comparisons, moves);
            recurseQuicksort(show, left, pivot-1, comparisons, moves);
            recurseQuicksort(show, pivot+1, right, comparisons, moves);
        }
    }

    int splitQuick(std::vector<Show> &show, int left, int right, long long &comparisons, long long &moves) {
        int p = (left + right)/2;
        int pivot = show[p].attendance;
        while (left <= right) {
            comparisons++;
            if (show[left].attendance <= pivot) {
                left++;
            }
            else if (show[right].attendance >= pivot) {
                right--;
            }
            else {
                moves += 2;
                swap(show[left], show[right]);
                left++;
                right--;
            }
        }

        moves += 2;
        if (p < right) {
            swap(show[p], show[right]);
            p = right;
        }
        else if (p > left) {
            swap(show[p], show[left]);
            p = left;
        }
        return p;
    }
    void swap(Show &a, Show &b) {
        Show temp = a;
        a = b;
        b = temp;
    }
}
