#include "utile.hh" // fichier pour l'image et le trackbar

const int max_value_H = 800;
        const int max_value = 800;
        const String window_detection_name = "Décisions";
        int low_H =100, low_S = 0, low_V = 0;
        int high_H = max_value_H, high_S = max_value, high_V = max_value;


void utile::on_low_H_thresh_trackbar(int, void *){
        low_H = min(high_H-1, low_H); 
        setTrackbarPos("quantité de bouffe", window_detection_name, low_H);
}


void utile::opencv(){  // overture d'une fenetre grace a opencv
        namedWindow(window_detection_name);
        createTrackbar("quantité de bouffe", window_detection_name, &low_H, max_value_H, on_low_H_thresh_trackbar);
}