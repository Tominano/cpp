/*
Készíts egy programot, ami telefonhívási eseményeket kezel.

hivas 235 Peter -> Tamas
hivas 643 Tamas -> Kata
hivas 921 Janos -> Tamas
beszel 643
beszel 123

A fenti forgatókönyv azt mutatja, hogy három hívás történt. Az adott nap 235-ik
percében Péter felhívta Tamást.

2. Készíts egy Hivasok nevű osztályt, ami az adott nap hívásait tartalmazza.
Készíts egy metódust a hívások beszúrására, egy másik metódust pedig, ami
visszaadja a hívót és hívottat egy párként a paraméterül megadott percben. Ha
nem volt az adott percben hívás, akkor a pár mindkét komponense üres string
legyen.

3. Olvasd be a "hivas" és "beszel" parancsokat a fájlból, és ezek alapján szúrd
be az eseményeket egy Hivasok típusú objektumba. A "beszel" utasítás hatására
írd ki a standard kimenetre az akkor történt hívást.

4. Oldd meg, hogy egy adott perchez több hívás is tárolható legyen a Hivasok
típusú objektumban.

5. Készíts egy print() metódust a Hivasok osztályhoz, ami kiírja az összes
tárolt hívást az alábbi formátumban:

3:55 am, Peter -> Tamas
10:43 am, Tamas -> Kata
3:21 pm, Janos -> Tamas*/


#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <time.h> 

using namespace std;

class Hivasok
{
public:
    vector<string> data;
    string input;
    vector<string> hivas_most;
    vector<string> hivas_felek;
    

void add()
{
    int hivas;
    cout << "Ha hívást szeretne bevinni nyomja meg az 1 -est.";
    cin >> hivas;
    if(hivas == 1)
        {
        data.push_back("hivas");

        string szam;
        cout << "Mikor hívta: ";
        cin >> szam;
        data.push_back(szam);

        string ki;
        cout << "Ki hívta: ";
        cin >> ki;
        data.push_back(ki);

    
        data.push_back("->");

        string kit;
        cout << "Kit hívott: ";
        cin >> kit;
        data.push_back(kit);
        }

}
void printpar(string szam)
{ 
    for(vector<string>::const_iterator i = data.begin(); i!= data.end(); ++i)
       {
        if(szam == *i)
            { 
                cout << "A kért hívást a következő két fél folytatta: ";
                for(vector<string>::const_iterator j = i; j!= i + 4; ++j)
                    {
                        cout << *j << " ";
                    }
                cout << endl;

            }

       }
}

vector<string> printpar2(string szam)
{ 
    vector<string> emb;

    for(vector<string>::const_iterator i = data.begin(); i!= data.end(); ++i)
       {
        if(szam == *i)
            { 
                emb.push_back(data[i - data.begin() + 1]);
                emb.push_back(data[i - data.begin() + 3]);

            }
        else 
            {
            emb.push_back("");
            emb.push_back("");
           } 
        return emb;
       }
}

void print()
{   
    int tomb[3];
    int hour;
    int min;

    tomb[0] = stoi(data[1]);
    tomb[1] = stoi(data[6]);
    tomb[2] = stoi(data[11]);

    for(int i = 0; i < 3; ++i)
    {   

            hour = tomb[i]/60;
            min = tomb[i]%60;
            
            cout << hour << ":" << min;

            if(hour < 12 or hour == 12)
                cout << " am, ";
            
            if(hour > 12)
                cout << " pm, ";

            if(i == 0)
            {
                cout << data[2] << " -> " << data[4] << endl;
            }

            if(i == 1)
            {
                cout << data[7] << " -> " << data[9] << endl;
            }
            if(i == 2)
            {
                cout << data[12] << " -> " << data[14] << endl;
            }
    
    }
}

void newprint()
{    
    for(vector<string>::iterator j = data.begin(); j!= data.end(); j+=5)
    {
        for(vector<string>::iterator i = 0 + j; i!= j + 5; ++i)
        {
            cout << *i << " ";
        }
    cout << "  " << endl;
    }   
}

void current()
{
    for(int i = 0; i < data.size(); ++i)
    {
        if(data[i].compare("hivas") == 0);
        {
            for(int j = i; j = i + 4; ++j)
                hivas_felek.push_back(data[j]);
        } 
        if(data[i].compare("beszel")==0)
        {
            for(int j = i; j = 2; ++j)
                hivas_most.push_back(data[j]);
        } 
    }

    for(int k = 0; k < hivas_most.size(); ++k)
    {   for(int l = 0; l = 2; )
        cout << hivas_most[k + l] << endl;
    }


}


};


main()
{
    Hivasok hiv;
    
    ifstream file("hiv.dat");

    while (file >> hiv.input)
        hiv.data.push_back(hiv.input);
    file.close();

    
    hiv.printpar("235");
    hiv.printpar2("235");
   
    hiv.print();
    hiv.add();
    hiv.newprint();
    
   // hiv.current();
}