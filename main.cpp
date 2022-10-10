#include <iostream>
#include <vector>
#include <algorithm>

#include "DataStruct.h"

size_t SIZE = 5;

void doEnter(std::vector<DataStruct> &arr){
    std::cout << "Enter: " << std::endl;
    for(auto & i : arr){
        std::cin >> i;
    }
}

int main() {
    std::vector<DataStruct> arr(SIZE);
    std::ostream_iterator<DataStruct> out(std::cout);
    doEnter(arr);
    std::sort(arr.begin(),arr.end());
    std::cout << std::endl;
    std::copy(arr.begin(), arr.end(), out);
    return 0;
}
