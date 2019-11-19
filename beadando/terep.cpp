#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <fstream>

using namespace std;

int main(){
ifstream file("szintek.dat");

int word;
while (file >> word)
words.insert(word);

file.close();

cout << "Benne van " << words.size() << "szó " << endl;

return 0;
}