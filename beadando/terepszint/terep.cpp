/*
Egy repülő elhalad egy terep felett, és kilométerenként megméri a föld tengerszint feletti magasságát. Tener fölött repülve az értékek értelemszerűen negatívak. A mért értékeket kérd be a felhasználótól, és tárold el egy tömbben. A tömbben tárolt értékek alapján válaszold meg az következő kérdéseket:

Melyik volt a legmagasabb mért pont?
Melyik volt a legmagasabb zátony (a legmagasabb tengerszint alatti pont)?
Hány kilométer hosszú a leghosszabb (tengerszint fölötti) síkság?
Hány kilométeren keresztül tartott a leghosszabb emelkedő?
Hányadik kilométernél van a legmagasabb hegycsúcs?
Mind az öt kérdés megválaszolására írj 1-1 függvényt. Ezen függvények törzsében ne írj ki semmit a kimenetre, hanem visszatérési értékként adják meg a választ.

Egy kis adalék: síkságnak nevezzük az egymás utáni, ugyanolyan magas értékeket. Illetve hegynek akkor nevezünk egy csúcsot, ha a két szomszédos érték szigorúan kisebb a csúcsnál. Tehát 0 2 3 5 4 8 8 8 2 -3 -1 1 esetben az 5-ös érték a csúcs, nem pedig a 8-as.

Az előbbi példára egyébként az alábbi kimenetet kell adni:

Legmagasabb mért pont: 8
Legmagasabb zátony: -1
Leghosszabb síkság: 2
Leghosszabb emelkedő: 3
Legmagasabb hegycsúcs helye: 4*/

#include <iostream>
#include <vector>
#include <fstream>


using namespace std;

int MaxPoint(const vector<int> &data)
{
    int max_peek = data[0];
    for (vector<int>::const_iterator i = data.begin(); i != data.end(); ++i)
    {
        if (max_peek < *i)
            max_peek = *i;
    }
    return max_peek;
}

int MinPoint(const vector<int> &data)
{
    int min = data[0];
    for (vector<int>::const_iterator i = data.begin(); i != data.end(); ++i)
    {
        if (min > *i)
            min = *i;
    }
    return min;
}

int MaxShallow(const vector<int> &data)
{
    if (MinPoint(data) < 0)
    {
        int max_shall = -1;
        for (vector<int>::const_iterator i = data.begin(); i != data.end(); ++i)
        {
            if (max_shall > *i)
                max_shall = *i;
            return max_shall;
        }
    }
    else
    {
        cout << "Dont have any shallow, the lowest point is: ";
        return MinPoint(data);
    }
}

int LongPlain(const vector<int> &data)
{
    if (MaxPoint(data) > 0)
    {
        int plainLength = 0;
        for (vector<int>::const_iterator i = data.begin(); i != data.end(); ++i)
        {
            if (*i == *next(i))
            {
                ++plainLength;
            }
        }
        return plainLength;
    }
}

int LongUp(const vector<int>& data)
{
    int uplength_one = 0, uplength_two = 0;
    for (vector<int>::const_iterator i = data.begin(); i!= data.end(); ++i)
    {
        if(*i < *next(i))
            ++uplength_one;
        
        else
        {
            if (uplength_two < uplength_one)
                uplength_two = uplength_one;
            uplength_one = 0;
        }
    }
    //if (uplength_two == uplength_one and uplength_one != 0)
    //    uplength_two = uplength_one;


    return uplength_two;
}

int WhereMaxPoint(const vector<int>& data)
{
    int where_max_peek = 0;
    
    for (vector<int>::const_iterator i = data.begin()+1; i!= data.end()-1; ++i)
    {
        if(*prev(i) < *i and *i > *next(i))
            where_max_peek = i - data.begin();

    }

    return where_max_peek;
}


int main()
{

    ifstream file("szintek.dat");
    int input;
    vector<int> data;

    while (file >> input)
        data.push_back(input);
    file.close();

    for (int i = 0; i < data.size(); i++)
        cout << data[i] << ", ";
    cout << endl;

    cout << "The highest point is: " << MaxPoint(data) << endl;
    cout << "The highest shallow is: "<< MaxShallow(data) << endl;
    cout << "The longest plain is: "<< LongPlain(data) << endl;
    cout << "The longest uphill is: "<< LongUp(data) << endl;
    cout << "The highest point is at the: " << WhereMaxPoint(data) << ". km"<< endl;
}