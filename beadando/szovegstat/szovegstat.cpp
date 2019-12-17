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
#include <algorithm>


using namespace std;

class TextStat
{
  public:
    vector<string> data;
    string input;

    void add()
    {   string word;
        cout << "Write the word(s) what you want to add: ";
        cin >> word;
        data.push_back(word);
        for (vector<string>::const_iterator i = data.begin()+1; i!= data.end(); ++i)
            {
                cout << *i << ", ";
            }
        cout << endl;
    }

    int size()
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

    void print()
    {
        for (vector<string>::const_iterator i = data.begin()+1; i!= data.end(); ++i)
        {
            cout << *i << ", " ;
        }
        cout << endl;
    }

    int getLongest()
    {   
        int longest = 0;for (vector<string>::const_iterator i = data.begin(); i != data.end(); ++i)
        for (vector<string>::const_iterator i = data.begin(); i != data.end(); ++i)
        {
            if (longest < i->length())
                longest = i->length();
        }
        return longest;
    }

    int getShortest()
    {
        int shortest = getLongest();
        for (vector<string>::const_iterator i = data.begin(); i != data.end(); ++i)
        {
            if (shortest > i->length())
                shortest = i->length();
        }
        return shortest;
    }

    void longerThan(){
        int size;
         vector<string> longer;
        cout << "Longer than: ";
        cin >> size;
        for (vector<string>::const_iterator i = data.begin(); i != data.end(); ++i)
        {
            if (size < i->length())
                longer.push_back(*i);
        }
        sort(longer.begin(), longer.end());
        longer.erase(unique(longer.begin(), longer.end()), longer.end());
        cout << "These are longer than " << size << ": ";
        
        for (vector<string>::const_iterator k = longer.begin(); k != longer.end(); ++k)
        {
            cout << *k << ", ";
        }
        cout << endl;
    }

    void numUnique()
    {   
        vector<string> unic_one;
        for (vector<string>::const_iterator k = data.begin(); k != data.end(); ++k)
        {
            unic_one.push_back(*k);
        }
        sort(unic_one.begin(), unic_one.end());
        unic_one.erase(unique(unic_one.begin(), unic_one.end()), unic_one.end());
        cout << "Unique number of words in the file : " << unic_one.size()<< endl;
    }

    void mostFrequent(){
        vector<int> most; vector<string> done;
        int int_most = 0, int_most2 = 0, max_element = 0;
        for (vector<string>::const_iterator i = data.begin(); i != data.end(); ++i)
            {
                for (vector<string>::const_iterator j = data.begin(); j != data.end(); ++j)
                {
                    if(operator==(*i,*j))
                        ++int_most;
                }
            most.push_back(int_most);
            
            if (i - data.end() == most.size())
                int_most = int_most2;
            int_most = 0;
            }

        for (vector<int>::const_iterator j = most.begin(); j != most.end(); ++j)
        {
            if (max_element < *j)
                max_element = *j;
        }   
        
        for (vector<int>::const_iterator k = most.begin(); k != most.end(); ++k)
        { 
            if (max_element == *k)
            {
              done.push_back(data[k - most.begin()]);
            }
        }

        sort(done.begin(), done.end());
        done.erase(unique(done.begin(), done.end()), done.end());
        cout << "The most frequent world(s): ";
        for (vector<string>::const_iterator k = done.begin(); k != done.end(); ++k)
        {
            cout << *k << ", ";
        }
        cout << endl;
    }
    
      
  };

main(){
    
    TextStat stat;
    ifstream file("proba2.dat");

    while (file >> stat.input)
        stat.data.push_back(stat.input);
    file.close();


    cout << "The shortest word in the file is: " << stat.getShortest() << " character short." << endl;
    cout << "The longest worls in the file is: " << stat.getLongest() << " character long" << endl;
    cout <<  "The sum of the file's words is: " << stat.size() << endl;
    stat.longerThan();
    stat.add();
    stat.print();
    stat.mostFrequent();
    stat.numUnique();
}