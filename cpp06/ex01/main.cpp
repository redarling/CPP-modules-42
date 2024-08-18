#include "Serializer.hpp"

#include <iostream>

int main(void)
{
    Data someData;

    someData.floating = 1.5;
    someData.integer = 42;
    someData.text = "Hello";

    std::cout << "Before serialization: " << someData.floating << " "
              << someData.integer << " " << someData.text << std::endl;
    
    uintptr_t raw = Serializer::serialize(&someData);
    
    Data* someTestData = Serializer::deserialize(raw);

    std::cout << "After deserialization: " << someTestData->floating << " "
              << someTestData->integer << " " << someTestData->text << std::endl;
    return (0);
}