#include "Heap.h"

int main(){
    MaxHeap maxHeap;
    maxHeap.insert(40); maxHeap.insert(20); maxHeap.insert(30); maxHeap.insert(10); maxHeap.insert(40);
    maxHeap.insert(60); maxHeap.insert(50); maxHeap.insert(90); maxHeap.insert(70); maxHeap.insert(20);
    maxHeap.insert(55); maxHeap.insert(80), maxHeap.insert(45); maxHeap.insert(100);

    maxHeap.printHeapTree();
    maxHeap.extratMax();
    maxHeap.extratMax();
    maxHeap.extratMax();
    std::cout<<"----------------------------------\n\n";
    maxHeap.printHeapTree();
}