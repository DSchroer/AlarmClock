#pragma once

#include <stdlib.h>



template <typename T>
class Vector {
public:
    Vector(){
        data = new T[0];
    }

    template<typename... Args>
    Vector(Args... list) {
        Vector();
        (Add(list), ...);
    }

    Vector(const Vector<T>& other){
        data = new T[other.Count];
        Count = other.Count;
        CopyData(other.data, other.Count, data, Count);
    }

    Vector(Vector<T>&& other){
        data = new T[other.Count];
        Count = other.Count;
        CopyData(other.data, other.Count, data, Count);
        delete [] other.data;
    }

    Vector& operator=(const Vector& other){
        data = new T[other.Count];
        Count = other.Count;
        CopyData(other.data, other.Count, data, Count);
        return *this;
    }

    ~Vector(){
        delete [] data;
    }

    void Add(T value){
        Resize(Count + 1);
        data[Count - 1] = value;
    }

    void Remove(uint8_t index){
        data[index] = data[Count - 1];
        Resize(Count - 1);
    }

    void Clear(){
        Count = 0;
        Resize(Count);
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

    void Resize(uint8_t newSize){
        auto newData = new T[newSize];
        CopyData(data, Count, newData, newSize);
        delete [] data;

        data = newData;
        Count = newSize;
    }

    static void CopyData(T* source, uint8_t sLen, T* dest, uint8_t dLen){
        uint8_t minSize = sLen <= dLen ? sLen : dLen;
        for(uint8_t i =0; i < minSize; i++){
            dest[i] = source[i];
        }
    }
};