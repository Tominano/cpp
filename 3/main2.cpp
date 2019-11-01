#include <iostream>

using namespace std;
int sum (int* t, int size)
{
int s = 0;

for (int i = 0; i < size; ++i)
	s += t[i]; // ugyan az mint s += *(t+i)
return s;
}

//pointer
int main()
{
	int t[10];
	int* p = t; //tömbről konvertálódik pointerre, a tömb nulladik elemére mutat
	cout << &t << endl;
	cout << p << endl;
	for (int i = 0; i < 10; ++i)
		t[i] = 10*i;
/*
	int = 42;
	cout << &i << endl;

	int* p = &i;
	*p = 43; // tülöl irhatom p értékét
	cout << *p << endl; //dereferáló müvelet... a p-n milyen érték van
	*/
	return 0;
}
