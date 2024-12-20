#ifndef HEAP_H
#define HEAP_H
#include <vector>
#include <iostream>
#include <functional>

template <typename T, class Compare = std::less<T>>
class MaxHeap {
    std::vector<T> m_heap;
    Compare comp; // Instance of the comparator

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
        if (comp(m_heap[parent], m_heap[i])) { // Use comparator
            std::swap(m_heap[i], m_heap[parent]);
            heapifyUp(parent);
        }
    }

    void heapifyDown(size_t i) {
        size_t left = getLeftIndex(i);
        size_t right = getRightIndex(i);
        size_t best = i;

        if (left < m_heap.size() && comp(m_heap[best], m_heap[left]))
            best = left;

        if (right < m_heap.size() && comp(m_heap[best], m_heap[right]))
            best = right;

        if (best != i) {
            std::swap(m_heap[i], m_heap[best]);
            heapifyDown(best);
        }
    }

    size_t size() const {
        return m_heap.size();
    }

    T getMax() const {
        if (!m_heap.empty()) {
            return m_heap[0];
        }
        throw std::runtime_error("MaxHeap is empty");
    }

    T extractMax() {
        T t = getMax();
        m_heap[0] = m_heap[m_heap.size() - 1];
        m_heap.pop_back();
        heapifyDown(0);
        return t;
    }

    void insert(T key) {
        m_heap.push_back(key);
        heapifyUp(m_heap.size() - 1);
    }

    void erase(size_t i) {
        m_heap[i] = m_heap[m_heap.size() - 1];
        m_heap.pop_back();
        heapifyDown(i);
    }

    void print() const {
        for (const auto &i : m_heap) {
            std::cout << i << " ";
        }
    }

    void printHeapTree(size_t index = 0, const std::string& prefix = "", bool isLeft = true) const {
        if (index >= m_heap.size()) return;

        // Print the current node
        std::cout << prefix;
        std::cout << (isLeft ? "├── " : "└── ");
        std::cout << m_heap[index] << std::endl;

        // Determine the next prefix
        std::string newPrefix = prefix + (isLeft ? "│   " : "    ");

        // Calculate left and right child indices
        size_t leftIndex = getLeftIndex(index);
        size_t rightIndex = getRightIndex(index);

        // Recursively print left and right children
        if (leftIndex < m_heap.size() || rightIndex < m_heap.size()) {
            printHeapTree(leftIndex, newPrefix, true);
            printHeapTree(rightIndex, newPrefix, false);
        }
    }
};

#endif // HEAP_H
