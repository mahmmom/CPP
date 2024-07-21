#include "Serializer.hpp"

/*
======================================= Constructor & Destructors ===========================================
*/
Serializer::Serializer() {}

Serializer::Serializer(const Serializer &other)
{
	*this = other;
}

Serializer &Serializer::operator=(const Serializer &other)
{
	if(this != &other) {}
	return *this;
}

Serializer::~Serializer() {}


/*
======================================= Member Functions ===========================================
*/

uintptr_t Serializer::serialize(Data *ptr)
{
	uintptr_t newData = reinterpret_cast<uintptr_t>(ptr);
	return newData;
}

Data *Serializer::deserialize(uintptr_t raw)
{
	Data* newData = reinterpret_cast<Data*>(raw);
	return newData;
}
