#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstring>

using namespace std;

vector<int> lottoNum()
{
    vector<int> randvec;
    
    srand(time(0));
    
    for(int k = 1; k < 7; ++k)
       randvec.push_back(rand()%91);
    
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

int main()
{
    vector<int> num;
	vector<int> numbers;

    int number;
    int input2;

    
    cout << "Kérem az enter lenyomásával egyenként adjon 5 különböző számot 1 és 90 között: " << endl;
    
    int i = 0;
    while (i++ != 5) 
    {
        cin >> input2;
        num.push_back(input2);
    }
    

   // mostFrequent();
    lottoNumPrint();
    
    //cout << "Ön " << won() << "db számot talált el."<< endl;
}  
