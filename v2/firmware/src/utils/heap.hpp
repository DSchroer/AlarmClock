#pragma once

#include <stdint.h>

template <class T>
class Heap {
private:
    T* heapStore;

    const uint8_t LChild(const uint8_t index);
    const uint8_t RChild(const uint8_t index);

    void BubbleUp(const uint8_t index);
    void BubbleDown(const uint8_t index);
public:
    Heap();
    ~Heap();

    T Pop();
    void Insert(T value)
    const uint8_t Count();
    
    void Resize(const uint8_t size);
    const uint8_t Size();
};

template <class T>
Heap<T>::Heap(){

}
