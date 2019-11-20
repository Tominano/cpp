#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <fstream>

using namespace std;

/*STL- konténerek, algoritmusok, iterátorok, pointer szerű aminek okos a ++ múvelete.. 
mindig megtalálja a linked list-ben
is a következő elemet
cppreference.com*/

//linkedlist.... [] nincsen ilyen operátor

list<int> l;

vector<int>::const_iterator contains(const vector<int>& v, int x){ //megkérem az elejét a v.begin(), v.end() a vége
    for (vector<int>::const_iterator i = v.begin(); i!= v.end(); ++i)// ezzel kérek egy iterátort ami végig megy az elemeken
                                // mindent lehet vele csinálni amit egy pointerrel
        if(*i ==x)
            return i;
    return v.end();
}
// ha más adatszerkezeten akarok keresni akkor a vector helyett cska mást kell beírni pl: list....
//begin()end() bal zárt, jobb nyilt intervallum

//konténerben keres bármint amit iterátortípussal adunk meg
/*template <typename Cont, typename T>

Cont<int>::const_iterator find(const Cont& v, const T& x){ 
    for (Cont::const_iterator i = v.begin(); i!= v.end(); ++i)
        if(*i ==x)
            return i;
        return v.end();
}*/

/*
map adatszerkezet*/


int main(){

//Halmaz
set<string> words;

ifstream file("stl.cpp");

string word;
while (file >> word)
words.insert(word);

file.close();

cout << "Benne van " << words.size() << "szó " << endl;

    return 0;
}