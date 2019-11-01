#include <iostream>
#include <cstdlib>

using namespace std;

int * even(int t[], int size){
	for (int i = 0; i < size; ++i)
		while (t[i]%2 == 0){
			return &t[i];
		}
}


int main(){ 

int size = rand() % 100 +1;
int t[size];

for (int i = 0; i < size; ++i)
		t[i] = rand() % 100 +1;

int *p = even(t, size);
cout << p << endl;

return 0;

}

