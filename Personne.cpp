/*
Auteur: Janie Bérubé
Date: 2025-01-02
Description: Exemple 3 - Constructeurs et Destructeurs (Allocation et libération de la mémoire)

Constructeur:   Initialise les champs d'un objet
Destructeur:    Libère la mémoire occupée par l'instance de l'objet
*/

#include <iostream>
using namespace std;

class Personne {
private:
    string nom;
    int age;

public:
    // Constructeur avec des valeurs par défaut
    Personne(string pNom = "Inconnu", int pAge = 0) : nom(pNom), age(pAge) {
        cout << "Creation de Personne (nom: " << nom << ", age: " << age << ")" << endl;
    }

    // Méthode pour afficher les informations de la personne
    void afficher() {
        cout << "Nom: " << nom << ", Age: " << age << endl;
    }
};

int main() {
    // Appelle le constructeur par défaut (fournis par le compilateur)
    Personne p1;

    // Appelle le constructeur avec un argument (nom)
    Personne p2("Alice");

    // Appelle le constructeur avec deux arguments (nom et âge)
    Personne p3("Bob", 25);

    // Affichage des informations
    p1.afficher();  // Affiche: Nom: Inconnu, Âge: 0
    p2.afficher();  // Affiche: Nom: Alice, Âge: 0
    p3.afficher();  // Affiche: Nom: Bob, Âge: 25

    return 0;
}