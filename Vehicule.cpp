/*
Auteur: Janie Bérubé
Date: 2025-01-02
Description: Exemple 1 - Intro à la programmation orientée objet
*/

#include <iostream>
using namespace std;

// Classe de base
class Vehicule
{
public:
    string marque;
    string modele;
    int annee;
    bool estElectrique;

    // Constructeur
    Vehicule(string pMarque, string pModele, int pAnnee, bool pEstElectrique)
        : marque(pMarque), modele(pModele), annee(pAnnee), estElectrique(pEstElectrique) {}

    // Méthode
    virtual void demarrer()
    {
        cout << "Le vehicule demarre." << endl;
    }

    // Destructeur
    ~Vehicule() {
        cout << "Destruction du vehicule" << endl;
    }
};

// Classe Sedan dérivée de Vehicule
class Sedan : public Vehicule
{
private:
    string messageBienvenue;
    const int nombrePortes = 4;

public:
    Sedan(string pMarque, string pModele, int pAnnee, bool pEstElectrique)
        : Vehicule(pMarque, pModele, pAnnee, pEstElectrique) {}

    // Méthodes d'accès (getters)
    int getNombrePortes() const { return nombrePortes; }
    string getMessageBienvenue() const { return messageBienvenue; }

    // Méthodes de modification (setters)
    void setMessageBienvenue(const string& message) { messageBienvenue = message; }

    // Redéfinir la méthode demarrer
    void demarrer() override
    {
        cout << "La berline demarre." << endl;
    }
};

// Classe Camion dérivée de Vehicule
class Camion : public Vehicule
{
private:
    int capaciteDeCharge;
    bool estDiesel;

public:
    Camion(string pMarque, string pModele, int pAnnee, bool pEstElectrique, int pCapaciteDeCharge, bool pEstDiesel)
        : Vehicule(pMarque, pModele, pAnnee, pEstElectrique), capaciteDeCharge(pCapaciteDeCharge), estDiesel(pEstDiesel) {}

    // Getters et setters
    int getCapaciteDeCharge() const { return capaciteDeCharge; }
    bool getEstDiesel() const { return estDiesel; }
    void setCapaciteDeCharge(int cap) { capaciteDeCharge = cap; }
    void setEstDiesel(bool diesel) { estDiesel = diesel; }

    // Redéfinir la méthode demarrer
    void demarrer() override
    {
        if (estDiesel)
        {
            cout << "Vroom Vroom! Le camion diesel demarre!" << endl;
        }
        else if (estElectrique)
        {
            cout << "Le camion démarre silencieusement." << endl;
        }
    }
};

// Méthode main
int main()
{
    cout << "Informations sur les vehicules" << endl << "******************************" << endl << endl;

    // Exemple Vehicule
    Vehicule monVehicule("Ford", "Fiesta", 2012, false);
    cout << "Marque: " << monVehicule.marque << endl << "Modele: " << monVehicule.modele << endl
        << "Annee: " << monVehicule.annee << endl << "Est electrique: " << (monVehicule.estElectrique ? "Oui" : "Non") << endl << endl;

    // Exemple Sedan
    Sedan monSedan("Nissan", "Versa", 2024, false);
    cout << "Marque: " << monSedan.marque << endl << "Modele: " << monSedan.modele << endl
        << "Annee: " << monSedan.annee << endl << "Est electrique: " << (monSedan.estElectrique ? "Oui" : "Non") << endl
        << "Nombre de portes: " << monSedan.getNombrePortes() << endl
        << "Message de bienvenue: " << monSedan.getMessageBienvenue() << endl;

    monSedan.setMessageBienvenue("Bienvenue dans votre vehicule!");
    cout << "Message de bienvenue revise: " << monSedan.getMessageBienvenue() << endl << endl;

    // Exemple Camion
    Camion monCamion("Chevrolet", "Silverado 1500", 2021, false, 2230, true);
    cout << "Marque: " << monCamion.marque << endl << "Modele: " << monCamion.modele << endl
        << "Annee: " << monCamion.annee << endl << "Capacite de charge: "
        << monCamion.getCapaciteDeCharge() << " lbs" << endl;

    monCamion.setCapaciteDeCharge(2500);
    cout << "Capacite de charge: " << monCamion.getCapaciteDeCharge() << " lbs" << endl;

    cout << "Est electrique : " << (monCamion.estElectrique ? "Oui" : "Non") << "     "
        << "Est diesel: " << (monCamion.getEstDiesel() ? "Oui" : "Non") << "     Demarrer: ";
    monCamion.demarrer();

    monCamion.setEstDiesel(false);
    cout << "Est electrique : " << (monCamion.estElectrique ? "Oui" : "Non") << "     "
        << "Est diesel: " << (monCamion.getEstDiesel() ? "Oui" : "Non") << "     Demarrer: ";
    monCamion.demarrer();

    cout << endl;

    return 0;
}


