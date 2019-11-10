#include <iostream>

using namespace std;
int n;

int factorial(int n){
    if(n <=0)
        return 1;
    else
        return n * factorial(n - 1);
}
 
//paraméter átadás pointerrel
void swapP(int* a, int* b) {
int tmp = *a;
*a = *b;
*b = tmp;
}

int main(){
    
    cout << "Hello World!" << endl; // operator<<(cout; "Hello World!")
    cout << "Give mee a number for calculate factorial:" << endl;
    cin >> n;
    cout << n << "factorial is: " << factorial(n) << endl;
    //Tömbök
    int i = 5;
    int t[] = {5,4,3,2,1};
    cout << "Size of int i = 5 is: " << sizeof(i) << endl;
    cout << "Size of int t[] = {5,4,3,2,1} is: " << sizeof(t) << endl;
    //Hivatkozás a tömb elemire, 2D tömb
    /*Az első [] jelek közt nincs méret, mert a fordító az inicializáció
    alapján meg tudja állapítani. 
    A második dimenzió méretének megadása viszont kötelező.*/
    int p[][3] = {{1,2,3},{4,5,6}};
    cout << p[0][1] << endl;
    //Paraméter átadás -- érték szerint történik.. megcserélni csak pointerekkel tudjuk
    int c = 5, d = 8;
    swapP(&c, &d);
    cout << c << " " << d << endl;
    return 0;
}