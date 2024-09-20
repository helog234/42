/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 16:53:12 by hgandar           #+#    #+#             */
/*   Updated: 2024/07/18 17:33:12 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

// reinterpret_cast conversion est le seul type de conversion qui permet de 
// reinterprèter le schema de bit d'un pointer
// Comme Data est un struct, créer par nous, il faut pouvoir le réinterpreter correctement
// Contrairement à d'autres formes de cast comme static_cast qui peuvent convertir des types compatibles,
// reinterpret_cast ne convertit pas les données elles-mêmes. 
//Il est purement utilisé pour changer la manière dont les données sont interprétées
// par le programme, sans altérer les données sous-jacentes.
// reinterpret_cast peut être dangereux pour des raisons de sécurité
//(reinterpret_cast ignore ces règles en interprétant les bits sous-jacents comme un autre type
// et cela peut conduire à des accès mémoire non autorisés )
// et de portabilité (différents compilateurs différentes règles donc le type 
// n'étant pas stabilisé il peut produire des comportements inattendus
// d'un compilateur à l'autre)

uintptr_t Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}

Serializer::Serializer()
{}

Serializer::~Serializer()
{}
Serializer::Serializer(const Serializer &other)
{
	(void)other;
}

Serializer& Serializer::operator=(const Serializer &other)
{
	(void)other;
	return (*this);
}