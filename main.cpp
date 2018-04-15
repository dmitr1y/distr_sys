#include <iostream>
#include <vector>
#include "BinarySearch/BinarySearch.h"

int main() {
    std::vector<int> array = {1, 4, 5, 6, 7, 0};
    std::vector<int> keys = {1, 6};
    BinarySearch binarySearch(array, keys);
    binarySearch.PrintArray();
    return 0;
}