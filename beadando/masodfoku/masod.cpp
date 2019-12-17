/*
Készíts egy függvényt, amely megoldja az ax2+bx+c=0 egyenletet.
A függvény első három paraméterében adhassuk meg az egyenlet együtthatóit,
és a negyedik és ötödik paraméteren keresztül adjuk vissza az x1, x2 eredményeket.
A függvény visszatérési értéke egy bool típusú logikai érték legyen, attól függően,
hogy az egyenletnek van-e legalább egy megoldása, vagy nincs.*/


#include <iostream>
#include <math.h>

using namespace std;
float a,b,c;
float x1, x2;

bool solve(float a, float b, float c)
{   
    
    if((b*b - 4*a*c) > 0)
    {
        float x1 = (-b + sqrt(b*b - 4*a*c))/2;
        float x2 = (-b - sqrt(b*b - 4*a*c))/2;
        
        cout << "x1 értéke: " << x1 << endl;
        cout << "x2 értéke: " << x2 << endl;
        
        return true;
    }
    else 
    {   
        cout << "Az egyenletnek nincsen valós megoldása." << endl;
        return false;
    }
}

main()
{
cout << "Kérem az 'a' paramétert" << endl;
cin >> a;
cout << "Kérem az 'b' paramétert" << endl;
cin >> b;
cout << "Kérem az 'c' paramétert" << endl;
cin >> c;
cout << "A számolást az " << a <<"x^2+" << b << "x+" << c << "=0" << " egyenleten végeztük." << endl;

solve(a,b,c);

}