#include "pch.h"
#include <iostream>

using namespace std;

int main() {
    Stockage* obj = new Stockage();

    char User_entry;
    cout << "Voulez-vous calculer les côtés d'un rectangle ou d'un cube ? (entrez 'r'/'R' ou 'c'/'C') :" << endl;
    cin >> User_entry;

    if (User_entry == 'R' || User_entry == 'r') {
        int L, l;
        cout << "Veuillez entrer une longueur : ";
        cin >> L;
        cout << "Veuillez entrer une largeur : ";
        cin >> l;

        Rectangle* O1 = new Rectangle(L, l);
        obj->ajouterAtTail(O1);
        O1->afficheInfo();
        delete O1;  
    }

    if (User_entry == 'C' || User_entry == 'c') {
        int c;
        cout << "Veuillez entrer un cote : ";
        cin >> c;

        Cube* O2 = new Cube(c);
        O2->afficheInfo();
        obj->ajouterAtTail(O2);
        delete O2;  
    }

    obj->afficherInfos();
    delete obj;

    return 0;
}
