#include<iostream>
#include"E_coli.hh"
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;
#include <vector>
#include <random>


const int max_value_H = 800;
const int max_value = 800;
const String window_detection_name = "Décisions";
int low_H =100, low_S = 0, low_V = 0;
int high_H = max_value_H, high_S = max_value, high_V = max_value;


static void on_low_H_thresh_trackbar(int, void *)
{
    low_H = min(high_H-1, low_H);
    setTrackbarPos("quantité de bouffe", window_detection_name, low_H);
}



/////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////








int main(){
  //nb bactéries

  std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(1,850); // distribution in range [1, 6]

    std::random_device dev1;
      std::mt19937 rng1(dev1());
      std::uniform_int_distribution<std::mt19937::result_type> dist7(1,100); // distribution in range [1, 6]


  srand (time(NULL));
  srand(unsigned(time(0)));
  double nb = rand() % 10 + 1;
  std::cout<<"nb de bacteries: "<<nb<<std::endl;



  std::cout<< "veuilliez choisir une nourriture et tappez son chiffre"<<std::endl;
  std::cout<< " fd1 : 1 /// fd2 : 2"<<std::endl;

  int chiffre(0) ;


     cin >> chiffre ;
string nomNourriture;
if (chiffre==1){
  nomNourriture="fd1";
}
else{
  nomNourriture="fd2";
}
std::cout<<"choisir la quantité"<<std::endl;
int quanti(0) ;
   cin >> quanti ;
low_H=quanti;

nourriture* fd1= new nourriture(nomNourriture,quanti);

conditions qiw(36,25);

vector<E_coli> listeBac;
for(int i=0;i<nb;i++){
  double x = dist6(rng);
  double y = dist6(rng);

  double t=dist7(rng1);
  E_coli eco(x,y,t,fd1,qiw);

  listeBac.push_back(eco);

}

while(true){
  namedWindow(window_detection_name);
createTrackbar("quantité de bouffe", window_detection_name, &low_H, max_value_H, on_low_H_thresh_trackbar);

  // Creating a blank image with
     // white background
    Mat image(800, 800, CV_8UC3,Scalar(255, 255, 255));



fd1->set_quantity(low_H);

//std::cout<<fd1->get_quantity()<<std::endl;
for(int i=0;i<nb;i++){

  listeBac[i].update(fd1);
  listeBac[i].survie();
  listeBac[i].draw(image);

}

imshow("Output", image);


waitKey(0);
}

//

};
