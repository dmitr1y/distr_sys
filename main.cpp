#include <iostream>
#include <vector>
#include "BinarySearch/BinarySearch.h"

int main() {
//    std::vector<int> array = {1, 4, 5, 6, 7, 0};
    std::vector<int> array = {1, 2, 3, 4, 5, 6, 7, 8, 9, 20, 22, 30, 44, 57, 59, 60, 67, 70, 77};
//    std::vector<int> keys = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25,
//                             26, 27, 28, 29, 30, 31};
    std::vector<int> keys = {1, 6, 4};
    BinarySearch binarySearch(array, keys);
    binarySearch.Search();
    return 0;
}