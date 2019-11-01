#include <iostream>

using namespace std;

void f(int i[]){ //ugyan az mintha int *i -t írnék

}

int main(){
int x[10];
x[0] = 42;
f(x);
cout << x[0] << endl;
// ha függvényen belül módosítom a tömböt az kint is 

return 0;
}

/*
láthatóság-- blokkon belül látszik, belső blokkban el lehet fedni
mikor kerül be a memóriában és mikor deallokálódik... meddig él egy változó? .. blokkon belül
forban deklarált változó a cikluson belül és és látszik*/
