#include <iostream>
using namespace std;

int main(){
    int temp;
    char unit;
    cout<< "Bienvenue dans le convertisseur de temperature Celsius et Farenheit. Appuyez sur 'c' pour Celsius ou 'f' pour Farenheit:"<<endl;
    cin>> unit;
    while(unit != 'c' && unit != 'f'){
        cout << "Unité invalide. Veuillez entrer 'c' pour Celsius ou 'f' pour Farenheit: "<<endl;
        cin >> unit;
    }

    if(unit == 'c'){
        cout << "Entrez la temperature en Celsius: "<<endl;
        cin >> temp;
        float farenheit = (temp * 9.0/5.0) + 32;
        cout << temp << " degrés Celsius est égal à " << farenheit << " degrés Farenheit." << endl; 
    }else{
        cout << "Entrez la temperature en Farenheit: "<<endl;
        cin >> temp;
        float celsius = (temp - 32) * 5.0/9.0;
        cout << temp << "degrés Farenheit est égal à " << celsius << " degrés Celsius." << endl;
    }



/*  cin >> val1 >> val2 >> val3; 
    int mean = (val1+ val2 + val3) /3;
    cout << "La moyenne est de : " << mean << endl;*/
    return 0;
}