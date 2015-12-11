//John Kinzel
//Computer Organization and System Programming
//2015

#include <iostream>
#include <random>
#include <algorithm>
#include <queue>
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


int SearchFrames(int frames[][4], int x, int replace, int first)
{
	
	for (int i = 0; i < 4; i++)
	{	
		if (frames[x][i] == replace)
		{
			return -1;
			break;
			
		}
		if (frames[x][i] == -1)
		{
			return i;
			break;
		}
		
	}
	return first;


	


}






int main()
{
	
	int again = 0; //test for input to enter multiple values

	int count = 0;//keep count of the number of inputs. this will decided which column to edit

	int input; //catch user input

	int y; //the Y of each row to swap

	queue<int> fillFrames; //this queue keeps track of the numbers that were entered so we can fill up the frames that were written before.

	queue<int> firstReplace; //keeps track of which rows were replaced
	firstReplace.push(0); //first replacement will be 0 by default so this will get the algorithm started.

	int Frames[ARRAY_SIZEX][ARRAY_SIZEY];//the frames to be replaced

	for (int i = 0; i < ARRAY_SIZEX; i++)
	{
		for (int j = 0; j < ARRAY_SIZEY; j++)
		{
			Frames[i][j] = -1;
		}
	}



	cout << "Hello! We are going to do some FIFO! Remember that -1 means EMPTY\n\n";

	PrintFrames(Frames);


	do{//repeat until 10 numbers are used

		

		

	//This block secures an input from the user and keeps asking until the input is an integer
			cout << "\n\nPlease enter a page request as a positive integer: ";
			cin >> input;
			while (cin.fail() || input < 0)
			{
				cout << "Please enter a positive integer: \n";
				cin.clear();
				cin.ignore(256, '\n');
				cin >> input;
			}


		
//We have the input. Now it's time to search through the frames to decide which number to replace
		
		
			y = SearchFrames(Frames, count, input, firstReplace.front());//call function to search for  which row to swap

			

			switch (y)
			{
			case -1:
				cout << "The number already exists in this row. No entry needed\n\n";
				PrintFrames(Frames);
				count++;
				break;
			case -2:
				cout << "Empty space found. No replacement needed\n\n";
				Frames[count][y] = input;
				firstReplace.push(y);//push y onto queue
				firstReplace.pop();//remove the first
				PrintFrames(Frames);
				count++;
				break;
			default:
				Frames[count][y] = input;
				cout << "No space found. Replacing the frame that was entered first\n\n";
				firstReplace.push(y);//push y onto queue
				firstReplace.pop();//remove the first.
				PrintFrames(Frames);
				count++;
				break;
			}
		
			if (count == 10)
			{
				cout << "\n\n\nYou are done! Thank you!\n\n";
			}
	}while (count < 11);
	



	system("Pause");
	return 0;
}