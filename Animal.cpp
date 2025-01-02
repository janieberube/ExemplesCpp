/*
Auteur: Janie B�rub�
Date: 2024-12-29
Description: Exemple 2 - Encapsulation, h�ritage et polymorphisme
*/

#include <iostream>
using namespace std;

// ===================== Encapsulation =====================

// La classe Animal regroupe les propri�t�s d'un animal
class Animal {
private:
    string name;  
    int age;      

public:
    // M�thodes pour d�finir les propri�t�s (encapsulation)
    void setNom(string n) { name = n; }
    void setAge(int a) { age = a; }
    string getNom() { return name; }
    int getAge() { return age; }

    // M�thode pour afficher les informations de l'animal
    void montrerInfo() {
        cout << "Type d'animal: " << name << endl;
        cout << "Age de l'animal: " << age << " ans" << endl;
    }

    // Fonction virtuelle pour le polymorphisme (� red�finir dans les sous-classes)
    virtual void son() {
        cout << "L'animal fait un bruit." << endl;
    }
};

// ===================== H�ritage =====================

// La classe Chien h�rite de la classe Animal
class Chien : public Animal {
public:
    // M�thode pour afficher le son du chien (red�finit la m�thode de la classe de base)
    void son() override {
        cout << "Le chien aboie." << endl;
    }
};

// La classe Chat h�rite de la classe Animal
class Chat : public Animal {
public:
    // M�thode pour afficher le son du chat (red�finit la m�thode de la classe de base)
    void son() override {
        cout << "Le chat miaule." << endl;
    }
};


// M�thode main
int main()
{
    // ===================== Encapsulation =====================
    Animal myAnimal;  // Cr�ation d'un objet Animal

    // D�finir le nom et l'�ge de l'animal via les m�thodes de modification
    myAnimal.setNom("Lion");
    myAnimal.setAge(5);

    // Afficher les informations de l'animal
    myAnimal.montrerInfo();

    // ===================== H�ritage =====================
    // Cr�ation des objets Chien et Chat qui h�ritent de la classe Animal
    Chien myDog;
    Chat myCat;

    // D�finir les donn�es pour le Chien et le Chat en utilisant les m�thodes de la classe de base (H�ritage)
    myDog.setNom("Buddy");
    myDog.setAge(3);
    myCat.setNom("Whiskers");
    myCat.setAge(2);

    // Afficher les informations sur le Chien et le Chat (H�ritage)
    cout << "\nInformations sur le Chien:" << endl;
    myDog.montrerInfo();
    cout << "\nInformations sur le Chat:" << endl;
    myCat.montrerInfo();

    // ===================== Polymorphisme =====================
    // Utiliser le polymorphisme pour appeler la m�thode son red�finie
    Animal* animalPtr;

    animalPtr = &myDog;
    animalPtr->son();  // Le chien aboie (Polymorphisme)

    animalPtr = &myCat;
    animalPtr->son();  // Le chat miaule (Polymorphisme)

    return 0;
}


