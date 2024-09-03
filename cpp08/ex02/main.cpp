/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 11:01:07 by hgandar           #+#    #+#             */
/*   Updated: 2024/09/02 10:16:50 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

//main exercice
/* int main()
{
MutantStack<int> mstack;
mstack.push(5);
mstack.push(17);
std::cout << mstack.top() << std::endl;
mstack.pop();
std::cout << mstack.size() << std::endl;
mstack.push(3);
mstack.push(5);
mstack.push(737);
//[...]
mstack.push(0);
MutantStack<int>::iterator it = mstack.begin();
MutantStack<int>::iterator ite = mstack.end();
++it;
--it;
while (it != ite)
{
std::cout << *it << std::endl;
++it;
}
std::stack<int> s(mstack);
return 0;
} */


int main(void) 
{
//mine
	MutantStack<int> mutant;
	mutant.push(1);
	mutant.push(2);
	mutant.push(4);
	mutant.push(8);
	
	std::cout << "check empty()" << std::endl;
	std::cout << mutant.empty() << std::endl;
	std::cout << "check size()" << std::endl;
	std::cout << mutant.size() << std::endl;
	std::cout <<"------" << std::endl;
	std::cout << std::endl;

	MutantStack<int>::iterator it = mutant.begin();
	MutantStack<int>::iterator ite = mutant.end();

	std::cout << "while mutant" << std::endl;
	while (it != ite) 
	{
		std::cout << *it << std::endl;
		++it;
	}
	it = mutant.begin();
	std::cout << "mutant begin()" << std::endl;
	std::cout << *it << std::endl;
	std::cout << "mutant end()" << std::endl;
	std::cout << *ite << std::endl;

	std::cout << "check top()" << std::endl;
	std::cout << mutant.top() << std::endl;
	std::cout <<"------" << std::endl;
	std::cout << std::endl;
	
	std::cout << "check pop()" << std::endl;
	mutant.pop();
	std::cout << mutant.top() << std::endl;
	std::cout <<"------" << std::endl;
	std::cout << std::endl;
	
	MutantStack<int> mutant2;
	mutant2.push(32);
	mutant2.push(16);
	std::cout << "check swap()" << std::endl;
	mutant2.swap(mutant);
	std::cout << "**mutant2 begin()**" << std::endl;
	MutantStack<int>::iterator it2 = mutant2.begin();
	std::cout << *it2 << std::endl;
	std::cout << "**mutant2 end()**" << std::endl;
	MutantStack<int>::iterator ite2 = mutant2.end();
	std::cout << *ite2 << std::endl;
	std::cout << "mutant2" << std::endl;
	while (it2 != ite2) 
	{
		std::cout << *it2 << std::endl;
		++it2;
	} 
	it = mutant.begin();
	ite = mutant.end();
	std::cout << "mutant begin()" << std::endl;
	std::cout << *it << std::endl;
	std::cout << "mutant end()" << std::endl;
	std::cout << *ite << std::endl;
	std::cout << "mutant" << std::endl;
	while (it != ite) 
	{
		std::cout << *it << std::endl;
		++it;
	}
	
	return (0);
}

//main pour list
/* int main(void) 
{
	std::list<int> mutant;
	mutant.push_back(1);
	mutant.push_back(2);
	mutant.push_back(4);
	mutant.push_back(8);
	

	std::cout << "check empty()" << std::endl;
	std::cout << mutant.empty() << std::endl;
	std::cout << "check size()" << std::endl;
	std::cout << mutant.size() << std::endl;
	std::cout <<"------" << std::endl;
	std::cout << std::endl;

	std::list<int>::iterator it = mutant.begin();
	std::list<int>::iterator ite = mutant.end();
	std::cout << "while mutant" << std::endl;
	while (it != ite) 
	{
		std::cout << *it << std::endl;
		++it;
	}
	it = mutant.begin();
	std::cout << "mutant begin()" << std::endl;
	std::cout << *it << std::endl;
	std::cout << "mutant end()" << std::endl;
	std::cout << *ite << std::endl;

	//enlever pour liste
	std::cout << "check top()" << std::endl;
	std::cout << mutant.back() << std::endl;
	std::cout <<"------" << std::endl;
	std::cout << std::endl;
	
	std::cout << "check pop()" << std::endl;
	mutant.pop_back();
	std::cout << mutant.back() << std::endl;
	std::cout <<"------" << std::endl;
	std::cout << std::endl;
	
	return (0);
} */
