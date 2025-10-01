#include <iostream>
using namespace std;

int factorial(int n){
    if (n <= 1) return 1;
    return n * factorial(n -1);
}

int main(){
    int nombre;
    int arr[] = {0, 0, 0, 0, 0, 0 ,0, 0, 0, 0};
    
    cout << "Entrez dix nombres entiers : "<< endl;
    cin >> arr[0] >> arr[1] >> arr[2] >> arr[3] >> arr[4] >> arr[5] >> arr[6] >> arr[7] >> arr[8] >> arr[9];
    for(auto i=0; i<9; i++){
        if(arr[i]>arr[i+1]){
            int temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
            i = -1; // Redémarrer le tri depuis le début
        }

    }
    cout << "Les nombres dans l'ordre croissant sont : " << arr[0] << ", " << arr[1] << ", " << arr[2] << "," << arr[3] << ", " << arr[4] << ", " << arr[5] << ", " << arr[6] << ", " << arr[7] << ", " << arr[8] << ", " << arr[9] << endl;

    //cout << "Entrez un nombre entier : ";
    //cin >> nombre;
    /*cout << ((nombre % 2 == 0)? "Le nombre est pair." : "Le nombre est impair.") <<endl;

    for  (auto i = 1; i!=11; i++){
        cout << i << " x " << nombre << " = " << (i * nombre) << endl; 
    } */
   //cout << factorial(nombre)<<endl; 


    return 0;
}