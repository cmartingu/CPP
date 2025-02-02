#include "../include/Serializer.hpp"

Serializer::Serializer(void)
{
    std::cout << "Default Serializer constructor called" << std::endl;
}

Serializer::Serializer(Serializer const &copy)
{
    std::cout << "Serializer copy constructor called" << std::endl;
    *this = copy;
}

Serializer::~Serializer(void)
{
    std::cout << "Serializer destructor called" << std::endl;
}

Serializer &Serializer::operator=(Serializer const &copy)
{
    std::cout << "Serializer assignment operator called" << std::endl;
    //     *this = copy;
    // *this = copy;
    if (this != &copy)
        return *this;
    return *this;
}

uintptr_t Serializer::serialize(Data *ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data *Serializer::deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data *>(raw));
}