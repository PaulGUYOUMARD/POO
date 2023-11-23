#ifndef PCH_H
#define PCH_H
#include <string>

class Objet2D
{
public :
	Objet2D();
	Objet2D(int tdim1, int tdim2);
	virtual int getPerimetre();
	virtual int getAire();
	virtual void afficheInfo();
	void setSuivant(Objet2D* Obj_exemple); // m�thode ou nous allons faire pointer "Suivant" sur l'objet de la classe "Objet2D"
	Objet2D* getSuivant(); // on return ce que pointe "Suivant"

protected :
	int dim1;
	int dim2;

private:
	Objet2D* Suivant; // cr�ation du pointeur "Suivant" en attribut priv�
};

class Rectangle : public Objet2D 
{
public :
	Rectangle();
	Rectangle(int tdim1, int tdim2);
	int getLongueur();
	int getLargeur();
	virtual int getPerimetre();
	virtual int getAire();
	virtual void afficheInfo();
};

class Cube : public Rectangle
{
public:
	Cube();
	Cube(int tcode);
	int getCote();
	int getPerimetre();
	int getAire();
	void afficheInfo();
};

class Stockage
{
public:
	Stockage();
	void ajouterAtHead(Objet2D* Objet_exemple); // m�thode qui va faire pointer "Head" sur la t�te de la chaine
	void ajouterAtTail(Objet2D* Objet_exemple); // m�thode qui va faire pointer "Tail" sur la queue de la chaine
	void ajouterAtIndex(Objet2D* Objet_exemple, int index_exemple); // m�thode qui va 
	void supprimerAtHead(); 
	void supprimerAtTail();
	void supprimerAtIndex(int index_exemple);
	void afficherInfos();
	~Stockage();

private:
	Objet2D* Head; // cr�ation de l'attribut "Head" qui va pointer sur la "t�te" de la cha�ne
	Objet2D* Tail; // cr�ation de l'attribut "Tail" qui va pointer sur la "queue" de la cha�ne
};

#endif //PCH_H
