/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Derived.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 11:16:59 by hgandar           #+#    #+#             */
/*   Updated: 2024/07/19 13:48:31 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Derived.hpp"

A::A()
{
	std::cout << "A constructor" << std::endl;
}

A::~A()
{}

B::B()
{
	std::cout << "B constructor" << std::endl;
}

B::~B()
{}


C::C()
{
	std::cout << "C constructor" << std::endl;
}

C::~C()
{}


Base * generate(void)
{
	int i = rand() % 3;
	
	if (i == 0)
		return (new A());
	if (i == 1)
		return (new B());
	return (new C());
}
// permet d'effectuer un cast sécurisé 
//(en temps d'exécution) entre des types polymorphes
// Contrairement à un cast statique (avec static_cast), 
//dynamic_cast vérifie à l'exécution si la conversion est possible. 
//Si le cast n'est pas possible, il renvoie un pointeur NULL 
//(pour les pointeurs) ou lance une exception std::bad_cast (pour les références).

void identify(Base* p)
{
	if (A* a = dynamic_cast<A*>(p))
		std::cout << "Is A" << std::endl;
	else if (B* b = dynamic_cast<B*>(p))
		std::cout << "Is B" << std::endl;
	else if (C* c = dynamic_cast<C*>(p))
		std::cout << "Is C" << std::endl;
	else
		std::cout << "Error in downcasting" << std::endl;
}

// & ne permet pas une comparaison booléene du coup je suis obligée
// de faire avec un try et catch dans cette configuration
void identify(Base& p)
{
	try
	{
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "Is A" << std::endl;
	}
	catch (std::bad_cast&)
	{
		try
		{
			B& b = dynamic_cast<B&>(p);
			(void)b;
			std::cout << "Is B" << std::endl;
		}
		catch (std::bad_cast&)
		{
			try
			{
				C& c = dynamic_cast<C&>(p);
				(void)c;
				std::cout << "Is C" << std::endl;
			}
			catch (std::bad_cast&)
			{
				std::cout << "Error in downcasting" << std::endl;
			}
		}
	}
}