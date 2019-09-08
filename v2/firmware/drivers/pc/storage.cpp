
#include <cstdio>
#include <unitypes.h>
#include "drivers/storage.hpp"

Storage::Storage() {

}

void Storage::Load(void *address, void *data, size_t size) {
}

void Storage::Save(void *address, void *data, size_t size) {
    printf("Storing: ");
    for(uint8_t i = 0; i < size; i++){
        printf("%x", ((uint8_t*)data)[i]);
    }
    printf("\n");
}