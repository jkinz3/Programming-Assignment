//John Kinzel
//Computer Organization and System Programming
//2015

#include <iostream>
#include <random>

/*
This program will use the FIFO algorithm to mimic page replacement

For the frames, -1 means empty
*/

#define ArraySize  100

using namespace std;


#define ARRAY_SIZEX 10
#define ARRAY_SIZEY 4


void PrintFrames(int frames[][4])
{

	cout << "Here are the frames!\n\n";

	for (int i = 0; i < ARRAY_SIZEY; i++)
	{
		for (int j = 0; j < ARRAY_SIZEX; j++)
		{
			cout << frames[i][j] << "\t";
		}
		cout << "\n";
	}


}


int SearchFrames(int frames[][4], int x)
{



}





int main()
{
	
	int Frames[10][4];//the frames to be replaced

	for (int i = 0; i < ARRAY_SIZEX; i++)
	{
		for (int j = 0; j < ARRAY_SIZEY; j++)
		{
			Frames[i][j] = 0;
		}
	}



	int again = 0; //test for input to enter multiple values

	int count = 0;//keep count of the number of inputs. this will decided which column to edit

	int input; //catch user input

	int y; //the Y of each row to swap

	do{

		cout << "Hello! We are going to do some FIFO!\n\n";

		PrintFrames(Frames);

		

	//This block secures an input from the user and keeps asking until the input is an integer
			cout << "\n\nPlease enter a page request as an integer: ";
			cin >> input;
			while (cin.fail())
			{
				cout << "Please enter an integer: \n";
				cin.clear();
				cin.ignore(256, '\n');
				cin >> input;
			}


		
//We have the input. Now it's time to search through the frames to decide which number to replace
		
		
			y = SearchFrames(Frames, count);//call function to search for  which row to swap

			Frames[count][y] = input; // swap it

		
		

	}while (again == 0);
	



	system("Pause");
	return 0;
}