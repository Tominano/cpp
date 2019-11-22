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
    public:
    vector<string> data;
    string input;
};

    void add(string)
    {
    }

    int size(const vector<string>& data)
    {
        int max = 0;
        for (vector<string>::const_iterator i = data.begin()+1; i!= data.end(); ++i)
            {
            if (max < i - data.begin())
                max = i - data.begin() +1 ; //mivel a 0-tól megy azt nem adta hozzá
            }
        return max;
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

    int getLongest(const vector<string>& data)
    {   
        int longest = 0;for (vector<string>::const_iterator i = data.begin(); i != data.end(); ++i)
        for (vector<string>::const_iterator i = data.begin(); i != data.end(); ++i)
        {
            if (longest < i->length())
                longest = i->length();
        }
        return longest;
    }

    int getShortest(const vector<string>& data)
    {
        int shortest = getLongest(data);
        for (vector<string>::const_iterator i = data.begin(); i != data.end(); ++i)
        {
            if (shortest > i->length())
                shortest = i->length();
        }
        return shortest;
    }

    void longerThan(const vector<string>& data){
        int size;
        cout << "Longer than: ";
        cin >> size;
        for (vector<string>::const_iterator i = data.begin(); i != data.end(); ++i)
        {
            if (size < i->length())
                cout << *i << ", ";
        }  
        cout << endl;
    }

    void numUnique(){

    }
    void mostFrequent(){

    }

main(){
    
    TextStat stat;

    ifstream file("szovegstat.cpp");

    
    while (file >> stat.input)
        stat.data.push_back(stat.input);
    file.close();

    cout << getShortest(stat.data) << endl;
    cout << getLongest(stat.data) << endl;
    cout << size(stat.data) << endl;
    longerThan(stat.data);
   // print(stat.data);
}