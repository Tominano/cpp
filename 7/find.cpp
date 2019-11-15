#include <iostream>
#include <map>
#include <fstream>

using namespace std;

int main(){
    map<string, int> words;

    ifstream file("map.cpp");

    string word;
    while (file >> word)
        if (words.find(word) == words.end())
            words[word] = 1;
        else
            ++words[word];
        

    for(map<string, int>::iterator i = words.begin(); i != words.end(); ++i)
        cout << (*i).first << ' ' << (*i).second << endl;

}
//Hányszor szerepel egy szó... ?

/*
Kacsacsőr szerinte rendez és párokat tárolunk, párokra mutat a pointer szerűség*/