/*
Auteur: Janie Bérubé
Date: 2024-12-29
Description: Exemple 2 - Encapsulation, héritage et polymorphisme
*/

#include <iostream>
using namespace std;

// ===================== Encapsulation =====================

// La classe Animal regroupe les propriétés d'un animal
class Animal {
private:
    string name;  
    int age;      

public:
    // Méthodes pour définir les propriétés (encapsulation)
    void setNom(string n) { name = n; }
    void setAge(int a) { age = a; }
    string getNom() { return name; }
    int getAge() { return age; }

    // Méthode pour afficher les informations de l'animal
    void montrerInfo() {
        cout << "Type d'animal: " << name << endl;
        cout << "Age de l'animal: " << age << " ans" << endl;
    }

    // Fonction virtuelle pour le polymorphisme (à redéfinir dans les sous-classes)
    virtual void son() {
        cout << "L'animal fait un bruit." << endl;
    }
};

// ===================== Héritage =====================

// La classe Chien hérite de la classe Animal
class Chien : public Animal {
public:
    // Méthode pour afficher le son du chien (redéfinit la méthode de la classe de base)
    void son() override {
        cout << "Le chien aboie." << endl;
    }
};

// La classe Chat hérite de la classe Animal
class Chat : public Animal {
public:
    // Méthode pour afficher le son du chat (redéfinit la méthode de la classe de base)
    void son() override {
        cout << "Le chat miaule." << endl;
    }
};


// Méthode main
int main()
{
    // ===================== Encapsulation =====================
    Animal myAnimal;  // Création d'un objet Animal

    // Définir le nom et l'âge de l'animal via les méthodes de modification
    myAnimal.setNom("Lion");
    myAnimal.setAge(5);

    // Afficher les informations de l'animal
    myAnimal.montrerInfo();

    // ===================== Héritage =====================
    // Création des objets Chien et Chat qui héritent de la classe Animal
    Chien myDog;
    Chat myCat;

    // Définir les données pour le Chien et le Chat en utilisant les méthodes de la classe de base (Héritage)
    myDog.setNom("Buddy");
    myDog.setAge(3);
    myCat.setNom("Whiskers");
    myCat.setAge(2);

    // Afficher les informations sur le Chien et le Chat (Héritage)
    cout << "\nInformations sur le Chien:" << endl;
    myDog.montrerInfo();
    cout << "\nInformations sur le Chat:" << endl;
    myCat.montrerInfo();

    // ===================== Polymorphisme =====================
    // Utiliser le polymorphisme pour appeler la méthode son redéfinie
    Animal* animalPtr;

    animalPtr = &myDog;
    animalPtr->son();  // Le chien aboie (Polymorphisme)

    animalPtr = &myCat;
    animalPtr->son();  // Le chat miaule (Polymorphisme)

    return 0;
}


