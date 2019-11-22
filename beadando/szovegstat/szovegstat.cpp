/*
Szöveg statisztika
Készíts egy osztályt TextStat néven, amely egy szöveg szavait kezeli, és statisztikát ad róluk.
Az osztály az alábbi tagfüggvényekkel rendelkezik:

- add(std::string): Új szó hozzáadása a gyűjteményhez.
- size(): Megadja a szavak számát.
- print(): Kiírja a szavakat.
- getLongest(): Megadja a gyűjtemény leghosszabb szavát.
- getShortest(): Megadja a gyűjtemény legrövidebb szavát.
- longerThan(int): Megadja az n karakternél hosszabb szavakat.
- numUnique(): Megadja az egyedi szavak számát.
            Például: alma, korte, alma, narancs, narancs, alma -> 3.
- mostFrequent(): Megadja a gyűjtemény leggyakoribb szavát.
            Például: alma, korte, alma, narancs, narancs, alma -> alma.
- Olvass be néhány szót a standard bemenetről vagy fájlból, és helyezd el egy TextStat objektumban.
            Hívd meg a fenti függvényeket a teszteléshez.*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class TextStat{
};

    void add(string){
    }

    void size(const vector<string> data)
    {
        int max = 0;
        for (vector<string>::const_iterator i = data.begin()+1; i!= data.end(); ++i)
            {
            if (max < i - data.begin())
                max = i - data.begin() +1 ; //mivel a 0-tól megy azt nem adta hozzá
            }
        cout << max << endl;
        cout << data.size() << endl; //a beépítettel ellenörzöm
    }

    void print(const vector<string>& data)
    {
        for (vector<string>::const_iterator i = data.begin()+1; i!= data.end(); ++i)
        {
            cout << *i << ", " ;
        }
        cout << endl;
    }

    void getLongest(){

    }
    void getShortest(){

    }
    void longerThan(int){

    }
    void numUnique(){

    }
    void mostFrequent(){

    }

main(){
    
    TextStat stat;

    ifstream file("szovegstat.cpp");
    string input;
    vector<string> data;
    
    while (file >> input)
        data.push_back(input);
    file.close();

    size(data);
    print(data);
}