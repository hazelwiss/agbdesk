#include"agbdesk.h"
#include<memory>

AGBDesk::AGBDesk(){
    this->memory = std::vector<uint8_t>(GBAInfo::MEMORY_SIZE,0);
}