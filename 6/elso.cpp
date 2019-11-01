/*
1,beolvasás file-ból, megszámolni, hogy hány különböző szó van a file-ban.
new int         - heep-en hozza létre az integert return-olni is lehet vele, és a memóriacímet is vissza ad ha nem adok meg neki értéket, 
int* p = new int;
*p = 42;

ugyan az ez is.... int* p = new int(42); ha [42] írok akkor 42 elemű tömböt hozok létre és a delete-nél figyelni kell tömbre mutat a pointerem
akkor delete[] x; töröljed

return p; -> 42 re mutató p* ami a heap-en van,
H a heapen, létrehozom akkor delete-el le is kell törölni onnan, nincen G.collector

*/
/*
Konstruktor
*/
#include <iostream>
#include <cstdlib>
#include <complex>
#include <fstream>

using namespace std;

struct Set{
    public:
        Set(){
            counter = 0;
            s = new double[100];
        }
        
        ~Set(){
            delete[] s; //dekonstruktor
        }

        bool contains(const double& number){
            return find(number) != 0;
        }
        
        void add(const double& number){
            if (counter == 100)
            return;
            
            if(!contains(number)){
                s[counter] = number;
                ++counter;
            }
        }

        int size(){
            return counter;
        }

 /*       void remove(const double& number){
            double* p = find(number);

            if (p != 0){
                *p = s[counter - 1];
                --counter;
            }
        }*/
    private:
        double* s;
        int counter;

        double* find(const double& number){
            for (int i = 0; i < counter; ++i)
                if(s[i] == number)
                    return &s[i];
            return 0;
        }
};


main(){
    
    Set numbers;

    ifstream file("elso.cpp"); // beolvasok egy file-ból, írni pedig ofstream
    double number;

    while (file >> number){ // << nak van egy bool visszatérési értéke
        numbers.add(number); //itt teszem be a halmazba
        cout << number << endl;
    }
    file.close();  //be is kell zárnia file-t
    cout << "A halmaz mérete: " << numbers.size() << endl;

    return 0;
}