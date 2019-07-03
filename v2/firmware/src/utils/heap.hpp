#pragma once

#include <stdint.h>
#include <stdlib.h>

template <class T>
class Heap {
private:
    T* heapStore;
    uint8_t count;
    uint8_t size;

    const uint8_t LChild(const uint8_t index) {
        return (2 * index) + 1;
    }

    const uint8_t RChild(const uint8_t index) { 
        return (2 * index) + 2;
    }

    const uint8_t Parent(const uint8_t index) { 
        return (index - 1) / 2;
    }

    void BubbleUp(const uint8_t index);
    void BubbleDown(const uint8_t index);
    void Swap(const uint8_t a, const uint8_t b);
public:
    Heap() {
        Resize(0);
    }

    ~Heap() {
        free(heapStore);
    }

    T& Top() { 
        return heapStore[0]; 
    }

    void Pop() { 
        Swap(0, count - 1);
        count = count - 1;
        BubbleDown(0);
    }

    void Insert(T value) {
        heapStore[count] = value;
        BubbleUp(count);
        count++;
    }

    const uint8_t Count() { 
        return count; 
    }

    const uint8_t Size() { 
        return size; 
    }

    void Resize(const uint8_t size);
};
