#include <iostream>
#include <vector>
#include <algorithm>
#include "BinarySearch/BinarySearch.h"

int main() {
//    std::vector<int> array = {1, 4, 5, 6, 7, 0};
//    std::vector<int> array = {1, 2, 3, 4, 5, 6, 7, 8, 9, 20, 22, 30, 44, 57, 59, 60, 67, 70, 77};
//    std::vector<int> array = {1, 2, 3, 4, 5, 6, 7, 8, 9, 20, 50, 22, 30, 44, 57, 59, 60, 67, 70, 77};
//    std::vector<int> keys = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25,
//                             26, 27, 28, 29, 30, 31};
//    std::vector<int> keys = {1, 6, 4, 77};
//
    std::vector<int> array10k(10000);
    std::vector<int> array20k(20000);
    std::vector<int> array40k(40000);
    std::vector<int> array80k(80000);
    std::vector<int> array160k(160000);
    std::vector<int> array320k(320000);
    std::vector<int> array640k(640000);
    std::vector<int> array1000k(1000000);
    std::vector<int> keys5k(5000);

    std::generate(array80k.begin(), array80k.end(), std::rand);
    std::generate(keys5k.begin(), keys5k.end(), std::rand);

    BinarySearch binarySearch(array80k, keys5k);
//    binarySearch.Sort();
    for (int j = 0; j < 8; ++j) {
        std::cout << std::endl << "cpu count: " << binarySearch.cpuCount << std::endl;
        for (int i = 0; i < 10; ++i) {
            binarySearch.Search();
        }
        binarySearch.cpuCount--;
    }

//    binarySearch.SearchSingleThread();
    return 0;
}