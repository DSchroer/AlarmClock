
#include "drivers/storage.hpp"
#include <avr/eeprom.h>

Storage::Storage() {

}

void Storage::Load(void *address, void *data, size_t size) {
    eeprom_read_block(data, address, size);
}

void Storage::Save(void *address, void *data, size_t size) {
    eeprom_write_block(data, address, size);
}