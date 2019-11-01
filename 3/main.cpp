#include <iostream>
using namespace std;

void f(int i)
{
	i = 42;
}

int fib(int n)
{
	if (n==0 || n==1)
	return fib(n-1)+fib(n-2);
}

int fib2(int n)
{
	int a = 0;
	int b = 1;

	for (int i; i < n; ++i){
		int c = a+b;
		a = b;
		b = c;
	}
	return b;
}


int main()
{
	const int size = 10;
	int t[size];
//tömb random számokkal
	for (int i =0; i << size; ++i)
		t[i] = rand() % 100 +1;

//összedjuk a t9mb elemit
	int s = 0;
	for (int i = 0; i < size; ++i)
		s += t[i];
	cout << s << endl;
// maximum keresés
	int m = t[0];
	for (int i = 0; i < size; ++i)
			if (t[0]>m)
				m = t[i];

//harmadik
//for (int i =1;i <= 10; ++i)
//cout << fib(i) << endl;
// második
//	int x = 0;
//	f(x);
//	cout << x << endl;
// elsőrész	
//	int t[10];
//	t[0] = 42;
//	cout << t[1];
//	cout << sizeof(int) << endl;
//	cout << sizeof(t) << endl;
}
