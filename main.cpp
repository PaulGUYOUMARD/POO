#include "Point.hpp"
#include <iostream>

using namespace std;

int main() {
    int xUser, yUser;

    cout << "Entrez un x : ";
    cin >> xUser;
    cout << "Entrez un y : ";
    cin >> yUser;

    Point P1(xUser, yUser);
    cout << "Point entre : ";
    P1.get_position();

    int xUser2, yUser2;
    cout << "Entrez un x : ";
    cin >> xUser2;
    cout << "Entrez un y : ";
    cin >> yUser2;

    Point* P2 = new Point(xUser2, yUser2);
    cout << "Point entre : ";
    P2->get_position();

    cout << "distance separant les 2 points : " << P2->distance(xUser, xUser2, yUser, yUser2) << endl;

    delete P2;

    return 0;
}