#pragma once

#include <stdlib.h>

template <typename T>
class Vector {
public:
    Vector(){
        data = (T*)malloc(0);
    }

    template<typename... Args>
    Vector(Args... list) {
        Vector();
        (Add(list), ...);
    }

    ~Vector(){
        free(data);
    }

    void Add(T value){
        Count++;
        Resize();
        data[Count - 1] = value;
    }

    void Remove(uint8_t index){
        Count--;
        data[index] = data[Count];
        Resize();
    }

    void Clear(){
        Count = 0;
        Resize();
    }

    T& Get(uint8_t index){
        return data[index];
    }

    int16_t IndexOf(T* pointer){
        for(uint8_t i = 0; i < Count; i++){
            if(pointer == &data[i]){
                return i;
            }
        }
        return -1;
    }

    T& operator[](uint8_t index){ return Get(index); }

    uint8_t Count = 0;
protected:
    T* data = nullptr;

    void Resize(){
        data = (T*)realloc(data, sizeof(T) * Count);
    }
};