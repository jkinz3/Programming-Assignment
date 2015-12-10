#include <iostream>
#include <random>

#define ArraySize  100

using namespace std;

int main()
{
	int randArray[15];


	for (int i = 0; i < ArraySize; i++)
	{
		randArray[i] = rand() % 100 + 1;
	}


	system("Pause");
	return 0;
}