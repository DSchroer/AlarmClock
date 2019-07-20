#pragma once

#include <stdint.h>
#include <stdlib.h>

template <class T>
class Heap {
private:
    T* heapStore = nullptr;
    uint8_t count = 0;
    uint8_t size = 0;

    const uint8_t LChild(const uint8_t index) {
        return (2 * index) + 1;
    }

    const uint8_t RChild(const uint8_t index) { 
        return (2 * index) + 2;
    }

    const uint8_t Parent(const uint8_t index) { 
        return (index - 1) / 2;
    }

    void BubbleUp(const uint8_t index){
        if(index == 0){
            return;
        }

        auto parentIndex = Parent(index);

        if(heapStore[index] > heapStore[parentIndex]){
            Swap(index, parentIndex);
            BubbleUp(parentIndex);
        }
    }

    void BubbleDown(const uint8_t index){
        auto lChildIndex = LChild(index);
        auto rChildIndex = RChild(index);

        if(lChildIndex >= count){
            return;
        }

        auto largerChild = lChildIndex;
        if(rChildIndex < count && heapStore[lChildIndex] < heapStore[rChildIndex]){
            largerChild = rChildIndex;
        }

        if(heapStore[index] < heapStore[largerChild]){
            Swap(index, largerChild);
            BubbleDown(largerChild);
        }
    }

    void Swap(const uint8_t a, const uint8_t b){
        auto tmp = heapStore[a];
        heapStore[a] = heapStore[b];
        heapStore[b] = tmp;
    }

    void Resize(const uint8_t newSize){
        if(heapStore == nullptr){
            heapStore = (T*)malloc(sizeof(T) * newSize);
        }else{
            heapStore = (T*)realloc(heapStore, sizeof(T) * newSize);
        }

        size = newSize;
    }

public:
    Heap() {
        Resize(1);
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

        auto smallerSize = ((size + 1) / 2) - 1;
        if(count <= smallerSize){
            Resize(smallerSize);
        }
    }

    void Insert(T value) {
        if(count >= size){
            Resize((size * 2) + 1);
        }

        heapStore[count] = value;
        BubbleUp(count);
        count++;
    }

    const uint8_t Count() { 
        return count; 
    }
};
