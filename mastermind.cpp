#include <iostream>
#include <string>
#include <random>

using namespace std;

int main()
{

	cout << "Color list: " << "red, blue, purple, yellow, orange, green, black, white.\n\n";
	//red pin means that there is a color that is correct and its in the correct place
	//white pin means that there is a correct pin in the incorrect place
	//code breaker gets 10 guesses

	string colorOne; //the sequence that must be guessed
	string guessOne, guessTwo, guessThree, guessFour; //the guesses for each turn
	const int numTurns = 10;

	random_device dev;
	mt19937 rng(dev());								//eight colors
	uniform_int_distribution<mt19937::result_type> color(0,7); 

	string colorCombo[4]; //4 slots for 4 colors


	for (int i = 0; i < 4; ++i) //4 is num of slots
	{
		//generate 4 random numbers:
		int randomNum1 = color(rng); //pick a random number

		switch (randomNum1)
			{
				case 0: 
				colorOne = "red";
				break;

				case 1:
				colorOne = "blue";
				break;

				case 2:
				colorOne = "purple";
				break;

				case 3:
				colorOne = "yellow";
				break;

				case 4:
				colorOne = "orange";
				break;

				case 5:
				colorOne = "green";
				break;

				case 6:
				colorOne = "black";
				break;

				case 7:
				colorOne = "white"; //not: green yellow white
				break;
			}

		colorCombo[i] = colorOne; //fills an array with colors (strings)

		}
	
			//FOR DEBUG: PRINT COLORS

			// for (int i = 0; i < 4; ++i)
			// {
			// 	cout << colorCombo[i] << " "; //prints the colors in the comp's array
			// }
			// cout << endl; 
	

		

	//cout << colorOne << colorTwo << colorThree << colorFour << endl; //prints out selected colors

	
	for (int t = 1; t < numTurns+1; ++t) //10 turns, the whole game is in here
	{
		cout << "TURN NUM: " << t << endl << endl;
		cout << "Enter four colors from left to right: ";
		cin >> guessOne >> guessTwo >> guessThree >> guessFour; //collect 4 guesses each turn
		cout << endl;

		

		string guesses[4] = {guessOne, guessTwo, guessThree, guessFour}; //reads all guesses into an array

		int correctCount = 0;
		
		for (int i = 0; i < 4; ++i)
		{

			for (int j = 0; j < 4; ++j)
			{

				//matching position...   matching color from guess
				if (i == j && colorCombo[i] == guesses[j]) //if the color and position is the same as the guess
				{
					cout << "CORRECT COLOR AND PLACE.\n";
					correctCount++;
					
				}
						//matching color from guess...  color is not a duplicate...  guessed color is not a duplicate.
				else if (colorCombo[i] == guesses[j] && colorCombo[i] != colorCombo[j] && colorCombo[i] != colorCombo[i-1] && guesses[i] != guesses[j]) //prevents duplicate messages
				{
					cout << "CORRECT COLOR, WRONG PLACE.\n"; //should only print out once per color
				}

				if (correctCount == 4)
				{
					cout << "\nYOU CRACKED THE CODE!\n";
					cout << "TURNS: " << t << endl;
					t = 11; //ends game (t > 11)
				}
				
			}
			
		}


	} //end game
	
			cout << "\nThe code was: ";
			for (int i = 0; i < 4; ++i)
			{
				cout << colorCombo[i] << " "; //prints the colors in the comp's array
			}

	 		cout << endl; 

	

	 		return 0;
}