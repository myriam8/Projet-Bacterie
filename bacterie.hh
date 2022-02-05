#include<iostream>
#include "nourriture.hh"
#include "conditions.hh"
class bacterie{
protected:
    double x; //emplacement de la bacterie dans la boite (x,y)
	double y;
	double taille;
	bool vie; // a partir d'un certain seuil 
    nourriture food;
	conditions condi;
	string forme;

public:
    bacterie(double a,double b,double t, nourriture* f, conditions cond, string form)
{
x=a;
y=b;
taille=t;
vie = true;
food = *f;
condi = cond;
forme = form;

} 
nourriture get_nourriture(){  
	return food;
}

double get_x(){return x;}
double get_y(){return y;}

double get_taille(){return taille;}

void set_food(nourriture f)
{
	food = f;
}

void set_condi(conditions cond)
{
	condi = cond;
}

void affiche(); //pour afficher
virtual bool survie()=0; //methode virtuelle

void deplace(double dx, double dy); // pour le deplacement de la bacterie




 /*
void set_x(double xpr) //setter 
{
	x=xpr;
}

void set_y(double ypr)
{
	y=ypr;
}
void set_taille(double t)
{
taille = t;
}
*/


};