#include <iostream>
#include <cstdlib>
#include <complex>
using namespace std;

struct Point
{
    double x,y;
};

struct Circle
{

private:
    Point origo;
    double r;

public:
    Circle(){//konstruktor
    if (r>0)
        r = 0;
    else r = 1;

    origo.x = 0;
    origo.y = 0;
    }
    double area(){
        return r * r * 3.14; // de nem kell kiirni a this-t ha nem írok semmit akkor is azt jelenti hogy this->
    }

    double resize(double r){
        if (r<0) // nem lehet beállítani negatívra  asugarat
        this->r =r ;
    }
    void move(double x, double y){
    this->origo.x = x; // mindíg arra mutat amire meghívtam a c. al a kört this-> ugyan azt jelenti
    this->origo.y = y;
    }

    bool is_inside(const Point& p){
        const Point& corig = this->origo;
        return pow(corig.x - p.x, 2) + pow(corig.y - p.y, 2) < pow(r,2);

    }
};

int count_inside(Circle t[], int size, const Point p){

}

Circle random_circle(){

}

int main(){
    
    Circle circles[10];

    for (int i = 0; i < 10; ++i)
        circles[i] = random_circle();
    
    Point p;
    p.x = 1;
    p.y = 2; //.. a függvények is privátak mostmár....de ha public... akkor azt használható struct on kívülről is

 //   c.x = 0;
 //   c.y = 0;
 //   c.r = 5;
 
    c.move(1,2);// mert a struct-on belül van ezért c. el hivatkozol
    c.resize(5);
    c.is_inside(p);
 
 if(c.is_inside(p)){
    cout << "Benne van" << endl;}
 else{
    cout << "Nincsen benne" << endl;}

cout << "Terület: " << c.area() << endl; 
cout << count_inside << endl;
}

// 3 kritérium hogy oop-legyen
// típus invariáns... nem módosíthatók az adattagok (adatelrejtés elve... private, nem hivatkozható le a structurán kívülről)......
// Egységbezárás elve... a függvények is privátak mostmár....de ha public... akkor azt használható struct on kívülről is

//1. Véletlen kört gyártő fv, 