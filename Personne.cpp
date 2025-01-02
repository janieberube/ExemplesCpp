/*
Auteur: Janie B�rub�
Date: 2025-01-02
Description: Exemple 3 - Constructeurs et Destructeurs (Allocation et lib�ration de la m�moire)

Constructeur:   Initialise les champs d'un objet
Destructeur:    Lib�re la m�moire occup�e par l'instance de l'objet
*/

#include <iostream>
using namespace std;

class Personne {
private:
    string nom;
    int age;

public:
    // Constructeur avec des valeurs par d�faut
    Personne(string pNom = "Inconnu", int pAge = 0) : nom(pNom), age(pAge) {
        cout << "Creation de Personne (nom: " << nom << ", age: " << age << ")" << endl;
    }

    // M�thode pour afficher les informations de la personne
    void afficher() {
        cout << "Nom: " << nom << ", Age: " << age << endl;
    }
};

int main() {
    // Appelle le constructeur par d�faut (fournis par le compilateur)
    Personne p1;

    // Appelle le constructeur avec un argument (nom)
    Personne p2("Alice");

    // Appelle le constructeur avec deux arguments (nom et �ge)
    Personne p3("Bob", 25);

    // Affichage des informations
    p1.afficher();  // Affiche: Nom: Inconnu, �ge: 0
    p2.afficher();  // Affiche: Nom: Alice, �ge: 0
    p3.afficher();  // Affiche: Nom: Bob, �ge: 25

    return 0;
}