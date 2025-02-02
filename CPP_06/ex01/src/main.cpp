#include "../include/Serializer.hpp"

int main()
{
	Data ptr;
	ptr.name = "Carlos";
	ptr.number = 21;

	std::cout << "Here is the original structs:" << std::endl <<
	"\taddress: " << &ptr << std::endl <<
	"\tname: " << ptr.name << std::endl <<
	"\tage: " << ptr.number << std::endl;

    uintptr_t   aux = Serializer::serialize(&ptr);

    std::cout << std::endl << "Serialized variable " << aux << std::endl << std::endl;
	Data *reserialized_struct = Serializer::deserialize(aux);

	std::cout << "Here is the reserialized structs:" << std::endl <<
	"\taddress: " << reserialized_struct << std::endl <<
	"\tname: " << reserialized_struct->name << std::endl <<
	"\tage: " << reserialized_struct->number << std::endl;
	return (0);
}