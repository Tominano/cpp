#include <iostream>
#include <map>
#include <fstream>

using namespace std;

int main(){
    map<string, int> m;
    m["hello"] = 42;
    m["dfdf"] = 5;
    m["rtg"] = 34;
    m["hello"] = 43;
    // felülírható

    cout << m.size() << endl;

    for(map<string, int>::iterator i = m.begin(); i != m.end(); ++i)
        cout << (*i).first << ' ' << (*i).second << endl;

}
//Hányszor szerepel egy szó... ?

/*
Kacsacsőr szerinte rendez és párokat tárolunk, párokra mutat a pointer szerűség*/