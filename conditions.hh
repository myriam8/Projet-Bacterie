#include<iostream>

class conditions{
    private:
    double temperature; // les conditions du milieu de la bacterie
    double humidity;


    public:
    conditions(double temperature, double humidity)//constructeur
    {
         this->temperature = temperature;
         this->humidity = humidity;
        
    }
    conditions(){}


//surcharge d'operateur
conditions & operator=( conditions &source)
{
    temperature = source.get_temperature();
    humidity = source.get_humidity();
    return *this;
}



    //getter
double get_temperature()//getter de la temperature 
{
    return temperature;
}
double get_humidity()//getter de l'humidite
{
    return humidity;
}
//seter
void set_temperature(double temperature)//setter 
{
    temperature = temperature;
}
void set_humidity(double humidity)
{
    humidity = humidity;
}

};