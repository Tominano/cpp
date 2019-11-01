#include <iostream>

using namespace std;

int main(){

	const char c[6]="hello";  /* igy néz ki 'h' 'e' 'l' 'l' 'o' \0 */
	int t[10];
	cout << c << endl; //itt is pointerré konvertálódik de még is kiirja a szöveget és nem az első elemre mutató memóriacímet
	cout << *c << endl; //karakterre mutató pointerre konvertálódik, egy h betűt ír ki
	cout << c + 2 << endl; //ez egy pointer lesz ami 2 vel az első után van  kiíródik hogy llo, 
//KARAKTER POINTER MINDIG RENDHAGYÓ
	cout << *(c+2) << endl;;// itt kiírja hogy l

return 0;
}
