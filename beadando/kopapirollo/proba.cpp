#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
 
    srand (time(NULL));
    int num = rand()% 3;

	const char  str1[][10] = {"Stone","Paper","Scissor"};
 
	//const char * str2 = str1[num];
 
	// Check if both strings are equal
	int result = strcmp(str1[1], str1[num]);
    cout << str1[num] << endl;
	// strcmp() returns 0 if both strings are exactly equal.
	if (result == 0)
		std::cout << "Both Strings are equal" << std::endl;
	else
		std::cout << "Both Strings are not equal";
 
 
	return 0;
}