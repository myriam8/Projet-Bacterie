#include<iostream>
#include "bacterie.hh"
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;
#include <random>


class E_coli : public bacterie{  // hérite de la classe bacterie

   public:
   int r;
   int g;
   int b;

   E_coli (double a,double b,double t, nourriture* f, conditions cond): bacterie(a,b,t,f,cond,"carre"){
       std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(1,255); // distribution in range [1, 6] pour generer une couleur aléatoirement 


      this->r=dist6(rng);
      this->g=dist6(rng);
      this->b=dist6(rng);
   }

   // je survie tant que le food c fd1 la quantité >5 et conditions bonnes
   bool survie(){
     if(this->food.get_nom()=="fd1" && this->food.get_quantity()>5 && condi.get_temperature()>35 && condi.get_humidity()>20){
        std::cout<<"i am live"<<std::endl;
        return true;
     }
     else{
         std::cout<<"je suis dead"<<std::endl;
        //this->taille=0;
        return false;
     }
   }


   void update(nourriture* lmakla){
      this->taille=lmakla->get_quantity();
   }

      // draw spécial pour cette classe 
   void draw(Mat image){

     
      // Coin supérieur gauche
      //std::cout<<"x :"<<this->x<<" y: "<<this->y<<std::endl;
         Point p1(this->x, this->y);

         // Coin inférieur droit
         Point p2(this->x+this->taille, this->y+this->taille);
         int thickness = -1;
      //std::cout<<"r :"<<this->r<<" g: "<<this->g<<std::endl;
         // Dessiner le rectangle
         rectangle(image, p1, p2,
                  Scalar(r, g, b),
                  thickness, LINE_8);

 
       
   }



};