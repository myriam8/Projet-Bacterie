#include<iostream>

class petri{

    public:
    petri(unsigned int initrayon);//constructeur
    ~petri();//destructeur
    unsigned int getrayon() const { return rayon; }; //getter
    unsigned int perimetre() const { return 2*(rayon)*3.14; }; //caclul du périmètre
    unsigned int surface() const { return rayon*rayon*3.14; }; //calcul de la surface
    void setLargeur(unsigned int newrayon) { rayon = newrayon; };

    petri::petri(unsigned int initrayon) //constructeur
{
  rayon = initrayon;
  
}

    petri::~petri()//destructeur
{
}

    private:
    unsigned int rayon;




};