#ifndef HEAP_H
#define HEAP_H
#include <vector>
#include <iostream>

class MaxHeap {
    std::vector<size_t> m_heap;
public:
    MaxHeap() = default;

    static size_t getLeftIndex(size_t i) {
        return 2 * i + 1;
    }

    static size_t getRightIndex(size_t i) {
        return 2 * i + 2;
    }

    static size_t getParentIndex(size_t i) {
        return (i - 1) / 2;
    }

    void heapifyUp(size_t i) {
        if (i == 0) return;
        size_t parent = getParentIndex(i);
        if (m_heap[i] > m_heap[parent]) {
            std::swap(m_heap[i], m_heap[parent]);
            heapifyUp(parent);
        }
    }

    void heapifyDown(size_t i) {
        size_t left = getLeftIndex(i);
        size_t right = getRightIndex(i);
        size_t largest = i;
        if (left < m_heap.size() && m_heap[left] > m_heap[largest])
            largest = left;

        if (right < m_heap.size() && m_heap[right] > m_heap[largest])
            largest = right;

        if (largest != i) {
            std::swap(m_heap[i], m_heap[largest]);

            heapifyDown(largest);
        }
        if (largest != i) {
            heapifyDown(largest);
        }
    }


    size_t size() const {
        return m_heap.size();
    }

    size_t getMax() const {
        if (!m_heap.empty()) {
            return m_heap[0];
        }
        throw std::runtime_error("MaxHeap is empty");
    }

    size_t extratMax()  {
        auto t=  getMax();
        m_heap[0] = m_heap[m_heap.size() - 1];
        m_heap.pop_back();
        heapifyDown(0);

        return t;
    }

    void insert(int key) {
        m_heap.push_back(key);
        heapifyUp(m_heap.size() - 1);
    }

    void erase(size_t i) {
        m_heap[i] = m_heap[m_heap.size() - 1];
        m_heap.pop_back();
        heapifyDown(i);
    }

    void print() const {
        for (auto &i: m_heap) {
            std::cout << i << " ";
        }
    }

    void printHeapTree( size_t index = 0, const std::string& prefix = "", bool isLeft = true) {
        if (index >= m_heap.size()) return;

        // Print the current node
        std::cout << prefix;
        std::cout << (isLeft ? "├── " : "└── ");
        std::cout << m_heap[index] << std::endl;

        // Determine the next prefix
        std::string newPrefix = prefix + (isLeft ? "│   " : "    ");

        // Calculate left and right child indices
        size_t leftIndex = 2 * index + 1;
        size_t rightIndex = 2 * index + 2;

        // Recursively print left and right children
        if (leftIndex < m_heap.size() || rightIndex < m_heap.size()) {
            printHeapTree( leftIndex, newPrefix, true);
            printHeapTree( rightIndex, newPrefix, false);
        }
    }
};

#endif //HEAP_H
