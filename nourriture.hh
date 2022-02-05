#include<iostream>
#include<string>
using namespace std; 

class nourriture{

   private:
    string nom; //nourriture
    double quantity; //quantity

    public:
    nourriture(string a, double b)//constructeur
    {
        nom = a;
        quantity = b;
    }
    nourriture(){}


    //getter
string get_nom()//getter de la temperature 
{
    return nom;
}
double get_quantity()//getter de l'humidite
{
    return quantity;
}
//seter
void set_nom(string nom)//seter; //setter 
{
    this->nom = nom;
}
void set_quantity(double quantity)//(double humidity);
{
    this->quantity = quantity;
}
};