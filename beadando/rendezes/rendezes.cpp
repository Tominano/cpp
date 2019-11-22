/*Készíts egy tömböt, amit feltöltesz véletlenszerű értékekkel.
Rendezd a tömb elemeit növekvő számsorrendbe.*/

#include <cstdlib>  
#include <iostream>
#include <vector>
#include <random>
#include <ctime>

using namespace std;

int LongUp(const vector<int>& myvec)
{
    int uplength = 0;
    for (vector<int>::const_iterator i = myvec.begin(); i!= myvec.end()-1; ++i)
    {
        if(*i < *next(i) or *i == *next(i))
            ++uplength;
    }
    return uplength;
}

void rend(vector<int> &myvec, int size)
{   cout << "The ordered vector elements are: " ;
        do {
            for (vector<int>::iterator i = myvec.begin(); i != myvec.end()-1; ++i)
                {
                if(*i > *next(i)) 
                    iter_swap(myvec.begin()+ (i - myvec.begin()),myvec.begin() + (i+1 - myvec.begin()));
                }        
            }
            while(LongUp(myvec) < size -1);
        if(LongUp(myvec) + 1 == size-1);
            {
            for (vector<int>::iterator i=myvec.begin(); i!=myvec.end() ; i++)
                cout << *i << ",";
            }    
        cout << endl;
}


int main() 
{ 
    int size;
    cout << "Number of elements: ";
    cin >> size;

    vector<int> myvec(size);
    
    srand(time(0));
    for( int j = 0; j < size; ++j )
        myvec[j] = rand() % 100 + 1;
  
    cout << "Vektor elements are: " ;
    for (vector<int>::const_iterator i = myvec.begin(); i != myvec.end(); ++i)
        cout << *i << ",";
    cout << endl;
 
    rend(myvec, size);
}