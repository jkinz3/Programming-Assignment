//John Kinzel
//Computer Organization and System Programming
//2015

#include <iostream>
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


void PrintFrames(int frames[ARRAY_SIZEY][ARRAY_SIZEX])
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


int SearchFrames(int frames[ARRAY_SIZEY][ARRAY_SIZEX], int x, int replace, int first)
{
	
	if (x > 0)
	{

		frames[0][x] = frames[0][x - 1];
		frames[1][x] = frames[1][x - 1];
		frames[2][x] = frames[2][x - 1];
		frames[3][x] = frames[3][x - 1];
	}

	

	for (int i = 0; i < 4; i++)
	{


		

		if (frames[i][x] == replace)
		{
			return -1;
			break;
			
		}
		if (frames[i][x] == -1)
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

	int collisions = 0;

	int input; //catch user input

	int y; //the Y of each row to swap

	queue<int> fillFrames; //this queue keeps track of the numbers that were entered so we can fill up the frames that were written before.

	queue<int> firstReplace; //keeps track of which rows were replaced
	firstReplace.push(0); //first replacement will be 0 by default so this will get the algorithm started.

	int Frames[ARRAY_SIZEY][ARRAY_SIZEX];//the frames to be replaced

	for (int i = 0; i < ARRAY_SIZEY; i++)
	{
		for (int j = 0; j < ARRAY_SIZEX; j++)
		{
			Frames[i][j] = -1;
		}
	}



	cout << "Hello! We are going to do some FIFO! Remember that -1 means Empty:\n\n";

	
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
			default:
				Frames[y][count] = input;
				cout << "Replacing the frame that was entered first\n\n";
				collisions++;
				
				if (firstReplace.size() == 4)
				{
					firstReplace.pop();//remove the first.
				}
				firstReplace.push(y);//push y onto queue
				PrintFrames(Frames);
				count++;
				break;
			}
		
			if (count == 10)
			{
				cout << "\n\n\nYou are done!\n" << "Number of collisions: " << collisions << endl;
				cout << "Thank you!";
			}
	}while (count < 11);
	



	system("Pause");
	return 0;
}