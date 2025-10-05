#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(){
    struct Etudiant{
        string prenom;
        string nom;
        int age;
        char note;
        string cours;
    };
    int nombreEtudiants;
    cout << "Entrez le nombre d'etudiants: ";
    cin >> nombreEtudiants;
    cin.ignore(); // Vider le buffer avant getline
    Etudiant* etudiants = new Etudiant[nombreEtudiants];
    for (int i = 0; i < nombreEtudiants; ++i) {
        cout << "Entrez le prenom: ";
        getline(cin, etudiants[i].prenom);
        cout << "Entrez le nom: ";
        getline(cin, etudiants[i].nom);
        cout << "Entrez l'age: ";
        cin >> etudiants[i].age;
        cin.ignore(); // Vider le buffer avant getline
        cout << "Entrez la note: ";
        cin >> etudiants[i].note;
        cin.ignore(); // Vider le buffer avant getline
        cout << "Entrez le cours: ";
        getline(cin, etudiants[i].cours);
    }

    ofstream fichier("etudiants.txt", ios::app);
    if(fichier.is_open()) {


        for(int i = 0; i < nombreEtudiants; ++i) {
            fichier << "Etudiant " << i + 1 << ": " << etudiants[i].prenom << " " << etudiants[i].nom
                    << ", Age: " << etudiants[i].age << ", Note: " << etudiants[i].note
                    << ", Cours: " << etudiants[i].cours << endl;
        }
        fichier.close();
    } else {
        cout << "Impossible d'ouvrir le fichier pour ecriture." << endl;
    }
    delete[] etudiants;
    return 0;
}