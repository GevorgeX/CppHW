#include <iostream>
#include <vector>
#include <unordered_map>

#include "Heap.h"
class Compare {
public:
    bool operator()(std::pair<int, int>& a, std::pair<int, int>& b)
    {
        return a.first> b.first;
    }
};

std::vector<int> writeFunctionName(std::vector<int> &arr, int k) {
    std::unordered_map<int, int> map;
    MaxHeap<std::pair<int, int>, Compare > maxHeap;
    std::vector<int> res;
    for (int i = 0; i < arr.size(); i++) {
        if (!map.contains(arr[i])) {
            map[arr[i]] = 1;
        }
        else {
            map[arr[i]]++;
        }
    }
    for (auto i = map.begin(); i != map.end(); ++i) {
        maxHeap.insert({i->first, i->second});
    }
    for (auto i = 0; i < k; ++i) {
        res.push_back(maxHeap.extractMax().first);
    }
    return res;
}

int main(){
    int k = 2;
    std::vector<int> arr = {1, 3, 2, 1, 2, 1};

    auto t = writeFunctionName(arr, k);
    for (int i = 0; i < t.size(); i++) {
        std::cout << t[i] << ", ";
    }
    std::cout << std::endl;

    k = 3;
    arr = {4, 1, 1, 3, 3, 3, 4, 5, 5, 6};
    t = writeFunctionName(arr, k);
    for (int i = 0; i < t.size(); i++) {
        std::cout << t[i] << ", ";
    }
    std::cout << std::endl;
}
