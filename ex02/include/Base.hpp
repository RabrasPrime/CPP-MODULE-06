//
// Created by tjooris on 1/13/26.
//

#ifndef CPP_MODULE_06_BASE_HPP
#define CPP_MODULE_06_BASE_HPP

#include <iostream>

class Base
{
	public:
		virtual ~Base();
};

Base	*generate(void);
void	identify(Base* p);
void	identify(Base& p);

#endif //CPP_MODULE_06_BASE_HPP