#include "bacterie.hh"

using namespace std;
void bacterie::deplace(double dx,double dy) // fonction pour le deplacemnet des bacteries
{
	
	x = x+dx;

	y = y+dy;

}

void bacterie::affiche()
{
	cout<<"les coordonnées sont:"<<endl;
	cout<<"x="<<x<<endl;
	cout<<"y="<<y<<endl;
}