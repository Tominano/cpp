/* 
1.
bemegy egy tömb, ami egy pointert ad vissza az 
!!első páros elemre!! és a másik!!barátságos számokat ad vissza!! 
[https://hu.wikipedia.org/wiki/Bar%C3%A1ts%C3%A1gos_sz%C3%A1mok],
 ha nincen páros akkor 0pointert ad vissza
&i[] mondom meg a pointer
int i = (1,2,3); vessző - operátor ennek a változónak az esz az értéke ami az utolsó vessző utáni érték
2.
prímszámra is legyen

3.
String hossz számláló
*/

#include <iostream>
#include <cstdlib>

using namespace std;

int * prime(int t[], int size){
	for (int i = 0; i < size; ++i)
	while(t[i]%1==0 and t[i]%t[i]==0){
		return &t[i];
	}
}

int * even(int t[], int size){
	for (int i = 0; i < size; ++i)
		while (t[i]%2 == 0){
			return &t[i];
		}
}

int friendly(int t[], int size){
	int f = 0;
	for (int i = 0; i < size ; ++i)
		while(int j = t[i])
			for(j = 1; j < t[i]; ++j)
				

}

int main(){ 

int size = 10;
int t[size];

for (int i = 0; i < size; ++i)
		t[i] = rand() % 100 +1;

int *e = even(t, size);
cout << e << endl;

int *p = prime(t, size);
cout << p << endl;

return 0;

}

