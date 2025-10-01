#include <string.h>
#include <iostream>

using namespace std;

int main() {
    int age;
    double poids;
    char nom[50];
    bool sexe; // 0 pour féminin, 1 pour masculin

    cout << "Entrez votre nom, votre age, votre poids et votre sexe (0 pour féminin, 1 pour masculin) : ";
    cin >> nom >> age >> poids >> sexe;
    cout << "Bonjour " << nom << ", vous avez " << age << "ans, vous pesez " << poids << "kg et vous êtes de sexe " <<((sexe) ? "masculin.":"feminin.");
    cout << endl;
    return 0;
}