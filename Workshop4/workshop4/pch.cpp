
#include "pch.h"
#include <iostream>
#include <string>

using namespace std;
using namespace System;

Objet2D::Objet2D()
{
	dim1 = 0;
	dim2 = 0;
}

Objet2D::Objet2D(int tdim1, int tdim2)
{
	dim1 = tdim1;
	dim2 = tdim2;
}

void Objet2D::setSuivant(Objet2D* Obj_example)
{
    Suivant = Obj_example; 
}

Objet2D* Objet2D::getSuivant()
{
	return Suivant;
}

int Objet2D::getPerimetre()
{
	return dim1 + dim2;
}

int Objet2D::getAire()
{
	return dim1 * dim2;
}

void Objet2D::afficheInfo()
{
	cout << "le perimetre est de :" << getPerimetre() << "et l'aire est de :" << getAire() << endl;
}

Rectangle::Rectangle()
{
	dim1 = 0;
	dim2 = 0;
}

Rectangle::Rectangle(int tdim1, int tdim2)
{
	dim1 = tdim1;
	dim2 = tdim2;
}

int Rectangle::getLongueur()
{
	return dim1;
}

int Rectangle::getLargeur()
{
	return dim2;
}

int Rectangle::getPerimetre()
{
	return (dim1 + dim2)*2;
}

int Rectangle::getAire()
{
	int aire = dim1 * dim2;
		return aire;
}

void Rectangle::afficheInfo()
{
	cout << "longueur =" << getLongueur() << endl;
	cout << "largeur =" << getLargeur() << endl;
	cout << "perimetre =" << getPerimetre() << endl;
	cout << "aire =" << getAire() << endl;
}

Cube::Cube()
{
	dim1 = 0;
}

Cube::Cube(int tcode)
{
	dim1 = tcode;
}

int Cube::getCote()
{
	return dim1;
}

int Cube::getPerimetre()
{
	return dim1 * 4;
}

int Cube::getAire()
{
	int aire = dim1 * dim1;
		return aire;
}

void Cube::afficheInfo()
{
	cout << "cote =" << getCote() << endl;
	cout << "perimetre" << getPerimetre() << endl;
	cout << "aire =" << getAire() << endl;
}

Stockage::Stockage()
{
    Head = nullptr;
    Tail = nullptr;
}

void Stockage::ajouterAtHead(Objet2D* Objet_exemple)
{
    Objet_exemple->setSuivant(Head);
    Head = Objet_exemple;
    if (Tail == nullptr)
    {
        Tail = Head;
    }
}

void Stockage::ajouterAtTail(Objet2D* Objet_exemple)
{
    Objet_exemple->setSuivant(nullptr);
    if (Tail != nullptr)
    {
        Tail->setSuivant(Objet_exemple);
    }
    else
    {
        Head = Objet_exemple;
        Tail = Objet_exemple;
    }
}

void Stockage::ajouterAtIndex(Objet2D* Objet_exemple, int index_exemple)
{
    if (index_exemple < 0)
    {
        cerr << "Index must be non-negative." << endl;
        return;
    }

    if (index_exemple == 0)
    {
        ajouterAtHead(Objet_exemple);
        return;
    }

    int i = 0;
    Objet2D* Objet_tempo = Head;
    while (i < index_exemple - 1 && Objet_tempo != nullptr)
    {
        Objet_tempo = Objet_tempo->getSuivant();
        i++;
    }

    if (Objet_tempo == nullptr)
    {
        cerr << "Index out of bounds." << endl;
        return;
    }

    Objet_exemple->setSuivant(Objet_tempo->getSuivant());
    Objet_tempo->setSuivant(Objet_exemple);
}

void Stockage::supprimerAtHead()
{
    if (Head == nullptr)
    {
        cerr << "List is empty." << endl;
        return;
    }

    Objet2D* Objet_tempo = Head;
    Head = Head->getSuivant();
    delete Objet_tempo;

    if (Head == nullptr)
    {
        Tail = nullptr;
    }
}

void Stockage::supprimerAtTail()
{
    if (Head == nullptr)
    {
        cerr << "List is empty." << endl;
        return;
    }

    if (Head == Tail)
    {
        delete Head;
        Head = Tail = nullptr;
        return;
    }

    Objet2D* Objet_tempo = Head;
    while (Objet_tempo->getSuivant() != Tail)
    {
        Objet_tempo = Objet_tempo->getSuivant();
    }

    delete Tail;
    Tail = Objet_tempo;
    Tail->setSuivant(nullptr);
}

void Stockage::supprimerAtIndex(int index_exemple)
{
    if (index_exemple < 0)
    {
        cerr << "Index must be non-negative." << endl;
        return;
    }

    if (Head == nullptr)
    {
        cerr << "List is empty." << endl;
        return;
    }

    if (index_exemple == 0)
    {
        supprimerAtHead();
        return;
    }

    int i = 0;
    Objet2D* Objet_tempo1 = Head;
    while (i < index_exemple - 1 && Objet_tempo1 != nullptr)
    {
        Objet_tempo1 = Objet_tempo1->getSuivant();
        i++;
    }

    if (Objet_tempo1 == nullptr || Objet_tempo1->getSuivant() == nullptr)
    {
        cerr << "Index out of bounds." << endl;
        return;
    }

    Objet2D* Objet_tempo2 = Objet_tempo1->getSuivant();
    Objet_tempo1->setSuivant(Objet_tempo2->getSuivant());
    delete Objet_tempo2;
}

void Stockage::afficherInfos()
{
    Objet2D* Objet_tempo = Head;
    int i = 0;
    while (Objet_tempo != nullptr)
    {
        cout << "Objet numero " << i + 1 << ": ";
        Objet_tempo->afficheInfo();
        Objet_tempo = Objet_tempo->getSuivant();
        i++;
    }
}

Stockage::~Stockage()
{
    Objet2D* Objet_tempo;
    while (Head != nullptr)
    {
        Objet_tempo = Head;
        Head = Objet_tempo->getSuivant();
        delete Objet_tempo;
    }
}

