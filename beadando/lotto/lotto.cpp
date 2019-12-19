/*
Az otos.txt fájl 1957-ig visszamenőleg tartalmazza az 5-ös lottó nyerőszámait.
A fájl első sorában egy szám szerepel, ami megadja, hogy hány további sor van a fájlban.
Minden sor egy hét kihúzott lottószámait tartalmazza növekvő számsorrendben.
Az alábbi feladatokat ezen fájl alapján kell megoldani.

1.Kérj be a felhasználótól öt számot 1 és 90 között. Ellenőrizd le,
hogy mindegyik a megengedett [1; 90] intervallumból való-e. Ha nem, akkor kérd újra, vagy lépj ki a programból.

2.Írd ki a bekért számokat növekvő számsorrendben.

3.Határozd meg az otos.txt alapján, hogy melyik számot húzták ki a legtöbbször.

4.Készíts egy függvényt, ami paraméterül két darab, öt elemű vektort vár
 Az első vektor tetszőleges öt számot tartalmaz 1 és 90 között, a második pedig legyen a felhasználótól
 bekért öt szám. A függvény adja meg eredményül, hogy hány számot találtunk el az első vektor számaiból.

5.Az otos.txt alapján adjuk meg, hogy ha minden héten megjátsszuk a felhasználótól beolvasott számokat,
akkor összesen hány 5-ös, 4-es, 3-as, 2-es, illetve 1-es találatunk lenne.

6.Írasd ki a jövőheti lottószámokat :)
*/


#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <random>
#include <ctime>

using namespace std;

class Lotto
{
public:
    vector<int> num;
	vector<int> numbers;

    int number;
    int input2;
    
    int coun0 = 0;
    int coun1 = 0;
    int coun2 = 0;
    int coun3 = 0;
    int coun4 = 0;
    int coun5 = 0;
    int counAll = 0;
    


void nyeremeny()
{
    for(int j = 1; j < numbers.size() - 6; j +=5)
        {
        for(int k = 0; k < 5; ++k)    
            {   
                if(num[k] == numbers[j + k])              
                    ++counAll;        
            }
        }
        if(counAll == 0)
            ++coun0;
        else if(counAll == 1)
            ++coun1;
        else if(counAll == 2)
            ++coun2;
        else if(counAll == 3)
            ++coun3;
        else if(counAll == 4)
            ++coun4;
        else if(counAll == 5)
            ++coun5;

    cout << coun0 << endl;
    cout << coun1 << endl;
    cout << coun2 << endl;
    cout << coun3 << endl;
    cout << coun4 << endl;
    cout << coun5 << endl;



}

vector<int> lottoNum()
{
    vector<int> randvec;
    
    srand(time(0));
    
    for( int k = 0; k < 6; ++k )
       randvec.push_back(rand()%(90) + 1);
    
    return randvec;
}

void lottoNumPrint()
{
    vector<int> print = lottoNum();
    cout << "A Lottószámok a következők: ";
    for(vector<int>::iterator j = print.begin(); j!= print.end()-1; ++j)
    {
        cout<< *j << ", ";
    }
        cout << endl;
}

int won()
{   int counter = 0;
    vector<int> print2 = lottoNum();
    for(vector<int>::iterator i = num.begin(); i!= num.end(); ++i)
    {
      for(vector<int>::iterator j = print2.begin(); j!= print2.end(); ++j)

        if(*i == *j)
            ++counter;
    }
    return counter;
}

int LongUp(vector<int> num)
{
    int uplength = 0;
    for(vector<int>::const_iterator i = num.begin(); i!= num.end()-1; ++i)
    {
        if(*i < *next(i) or *i == *next(i))
            ++uplength;
    }
    return uplength;
}

vector<int> rend(vector<int> num)
{   
    do 
    {
    for (vector<int>::iterator i = num.begin(); i != num.end()-1; ++i)
        {
        if(*i > *next(i)) 
            iter_swap(num.begin()+ (i - num.begin()),num.begin() + (i+1 - num.begin()));
        }        
    }
    while(LongUp(num) < 4);
            
    if(LongUp(num) + 1 == 5)
    {
        return num;
    } 
}

int test()
{   
    int counter2 = 0;
    vector<int> done2 = rend(lottoNum());
    vector<int> done = rend(num);

        for (vector<int>::iterator i = done.begin(); i != done.end() - 1; ++i){
            if(*i == *next(i))
            {
                cout << "Kérem adja meg helyesen a számokat! Indítsa el újra a programot." << endl;
                exit(0);
            }

        }
        for (vector<int>::iterator i = done2.begin(); i != done2.end() - 1; ++i){
            if(*i == *next(i))
            {
                cout << "A generátor egyforma számokat adott lottószámoknak! Indítsa el újra a programot." << endl;
                exit(0);
            }

        }    

    for (vector<int>::iterator i = done.begin(); i != done.end(); ++i)
    {
        if(*i > 90 or *i < 1)
        {
            cout << "Kérem adja meg helyesen a számokat! Indítsa el újra a programot." << endl;
            exit(0);
        }
        else
        {
            counter2++;
        }
    }
    return counter2;
}

void print()
{
    vector<int> p = rend(num);
    if(test() == 5)
        cout << "Az ön számai növekvő sorrendben: " ;
        for (vector<int>::iterator i = p.begin(); i != p.end(); ++i)
        {
            cout << *i << ", ";
        }
        cout << endl;
}

void mostFrequent(){
    vector<int> most; vector<int> done;
    int int_most = 0, int_most2 = 0, max_element = 0;
    for (vector<int>::iterator i = numbers.begin(); i != numbers.end(); ++i)
        {
        for (vector<int>::iterator j = numbers.begin(); j != numbers.end(); ++j)
        {
            if(*i == *j)
                ++int_most;
        }
        most.push_back(int_most);
            
            if (i - numbers.end() == most.size())
                int_most = int_most2;
            int_most = 0;
            }

        for (vector<int>::const_iterator j = most.begin(); j != most.end(); ++j)
        {
            if (max_element < *j)
                max_element = *j;
        }   
        
        for (vector<int>::iterator k = most.begin(); k != most.end(); ++k)
        { 
            if (max_element == *k)
            {
              done.push_back(numbers[k - most.begin()]);
            }
        }

        sort(done.begin(), done.end());
        done.erase(unique(done.begin(), done.end()), done.end());
        cout << "A legtöbbször előforduló szám a belovasott adatokban: ";
        for (vector<int>::iterator k = done.begin(); k != done.end(); ++k)
        {
            cout << *k << ", ";
        }
        cout << endl;
    }




};



main()
{
    Lotto lot;
	ifstream in("lotto.dat");

        while (in >> lot.number) {
			lot.numbers.push_back(lot.number);
	}
	in.close();
    
    cout << "Kérem az enter lenyomásával egyenként adjon 5 különböző számot 1 és 90 között: " << endl;
    
    int i = 0;
    while (i++ != 5) 
    {
        cin >> lot.input2;
        lot.num.push_back(lot.input2);
    }
    

    lot.print();
    lot.mostFrequent();
    lot.lottoNumPrint();
    lot.nyeremeny();
    
    cout << "Ön most " << lot.won() << " db számot talált el."<< endl;
}