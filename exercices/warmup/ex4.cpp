#include <iostream>
#include <typeinfo>
using namespace std;

int main() {
    // Début exercices 21 à 30
    int n;
    cin.exceptions(ios::failbit); // Activer les exceptions sur cin
    try{
    cout << "Entrez la taille du tableau :"<< endl;
    cin >> n;
    } catch (ios::failure& e) {
        cerr << "Erreur de saisie : entrée non valide." << endl;
        return 1;
    }
    int *tab = new int[n];
    for(int i=0; i<n; i++){
        tab[i] = i*i;
        cout << "tab[" << i << "] = " << tab[i] << endl;
    }
    
    return 0;

}