//
// Created by tjooris on 1/13/26.
//

#ifndef CPP_MODULE_06_SERIALIZER_HPP
#define CPP_MODULE_06_SERIALIZER_HPP

#include <iostream>
#include "Data.hpp"
#include <stdint.h>

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer &other);
		Serializer &operator=(const Serializer &other);
		~Serializer();
	public:
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};


#endif //CPP_MODULE_06_SERIALIZER_HPP