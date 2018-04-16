//
// Created by dmitriy on 15.04.18.
//

#ifndef DISTR_SYS_BINARYSEARCH_H
#define DISTR_SYS_BINARYSEARCH_H


#include <vector>

class BinarySearch {
private:
    std::vector<int> array;
    std::vector<int> search_keys;

private:

    void PrintArray(std::vector<int> array);

    bool IsSorted(std::vector<int> array);


    void SimpleSearch(unsigned int start, unsigned int end);

    void BinSearch(unsigned int start, unsigned int end, int key);

    void BinSearchManyKeys(std::vector<int> keys);

public:
    BinarySearch(std::vector<int> array, std::vector<int> search_keys);

    void PrintArray();

    void Sort();

    void Search();

    void SearchSingleThread();

    int cpuCount;
};


#endif //DISTR_SYS_BINARYSEARCH_H
