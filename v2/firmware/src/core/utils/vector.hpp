#pragma once

#include <cstdlib>

template <typename T>
class Vector {
public:
    Vector(){
        data = (T*)malloc(0);
    }
    ~Vector(){
        free(data);
    }

    void Add(T value){
        Count++;
        data = (T*)realloc(data, sizeof(T) * Count);
        data[Count - 1] = value;
    }

    void Remove(uint8_t index){
        Count--;
        data[index] = data[Count];
        data = realloc(data, sizeof(T) * Count);
    }

    void Clear(){
        Count = 0;
        data = (T*)realloc(data, 0);
    }

    T& Get(uint8_t index){
        return data[index];
    }

    T& operator[](uint8_t index){ return Get(index); }

    uint8_t Count = 0;
private:
    T* data = nullptr;
};