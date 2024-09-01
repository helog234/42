/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomisateur.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 08:06:31 by hgandar           #+#    #+#             */
/*   Updated: 2024/08/29 08:38:36 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

// Fonction pour mélanger les éléments d'un vecteur et attribuer les éléments mélangés
template <typename T>
std::vector<T> shuffleAndAssign(const std::vector<T>& items) {
    // Créer une copie du vecteur original
    std::vector<T> shuffledItems = items;
    
    // Créer un générateur aléatoire basé sur l'horloge système
    std::random_device rd;
    std::mt19937 g(rd());
    
    // Mélanger les éléments du vecteur
    std::shuffle(shuffledItems.begin(), shuffledItems.end(), g);
    
    return shuffledItems;
}

int main() {
    // Définir les parties du projet
    std::vector<std::string> projectParts;
    projectParts.push_back("Server init et config");
    projectParts.push_back("HTTP requests");
    projectParts.push_back("Parsing + CGI");
    
    // Définir les personnes
    std::vector<std::string> people;
    people.push_back("Baptiste");
    people.push_back("Alex");
    people.push_back("Hélène");
    
    // Mélanger les parties du projet
    std::vector<std::string> assignedParts = shuffleAndAssign(projectParts);
    
    // Assigner les parties du projet aux personnes
    std::vector<std::pair<std::string, std::string>> assignments;
    for (size_t i = 0; i < people.size(); ++i) {
        assignments.push_back(std::make_pair(people[i], assignedParts[i]));
    }
    
    // Afficher les résultats
    for (const std::pair<std::string, std::string>& assignment : assignments) {
        std::cout << assignment.first << " sera responsable de: " << assignment.second << std::endl;
    }
    
    return 0;
}

