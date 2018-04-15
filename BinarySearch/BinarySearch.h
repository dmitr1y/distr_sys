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

    static unsigned int GetCoresCount();

    void Search(std::vector<int> array, unsigned int start, unsigned int end, int key);

public:
    BinarySearch(std::vector<int> array, std::vector<int> search_keys);

    void PrintArray();

    void Search();
};


#endif //DISTR_SYS_BINARYSEARCH_H
