#include "Serializer.hpp"

int main(){
    Data data;
    data.id = 42;
    data.name = "jaouad belkerf";

    std::cout << "=== Before Serialization ===" << std::endl;
    std::cout << "Original pointer : " << &data << std::endl;
    std::cout << "id               : " << data.id << std::endl;
    std::cout << "name             : " << data.name << std::endl;

    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "\n=== Serialized ===" << std::endl;
    std::cout << "Raw integer      : " << raw << std::endl;

    Data* returned = Serializer::deserialize(raw);
    std::cout << "\n=== After Deserialization ===" << std::endl;
    std::cout << "Returned pointer : " << returned << std::endl;
    std::cout << "id               : " << returned->id << std::endl;
    std::cout << "name             : " << returned->name << std::endl;

    std::cout << "\n=== Comparison ===" << std::endl;
    if (returned == &data)
        std::cout << "Pointers match! Serialization works correctly." << std::endl;
    else
        std::cout << "Pointers do NOT match. Something went wrong." << std::endl;

    return 0;
}