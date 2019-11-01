#include <iostream>
#include <cstdlib>
using namespace std;


void fv(int i){
    i = 42;
}
// referenciák
void f(int& r){ //referencia
    r =42;
}

//void f(const int& r){ //referencia de íg már lefordul az is ha f(5); el hívom meg
//}

// Ökölszab... konstans referencia paramétereket használjunk. de az alaptípusokat lehet értékszerint átadni

void g(int* p){
    *p = 42;
}

void h(int& r){ //ez a referencia típusu változó.... állneve egy már létező definiciónak(ugyanazon a memória területen van)
    r = 42;
}

int main(){
    int  i = 0;
    fv(i);// igy is megy, ha !!! fv(3); már nem mert L value error !!!
    // 3 = 5; //ha objektumokról van szó annak van típusa és kategóriája is... jobb(nem bal) és bal(szerepelhet értékadás bal oldalán) érték
           // hibaüzenetnél L value- nál erről van szó
    f(i);
    cout << i << endl;
    g(&i); //it az & címlekérdező operátor
    cout << i << endl;
    h(i);
    cout << i << endl;
}