#include <iostream>
#include <string>
#include <ctime>
#include <conio.h>
#include <windows.h>
//////////
using namespace std;
//Functions:
void maindrawer();
void humanfill();
void player1logic();
void maindrawer2();
void starter();
// main arrays
char memory1[11][11];
char memory2[11][11];
// Main codes
//Go to a cordinate
void gotoxy(short x, short y)
{
	COORD coord = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
//Colorozing text


//To get a random value(1,0)
bool random(){
	int a = rand() % 10;
	if (a % 2 == 0){
		return 1;
	}
	else return 0;
}
//This is the cordinates filled with X,Y
struct bonuses{
	int carrier[5][2];
	int battleship[4][2];
	int cruiser[3][2];
	int destroyer[2][2];
	int
		carrierx = 0,
		battleshipx = 0,
		cruiserx = 0,
		destroyerx = 0,
		win = 0;
	bool
		carrierb = 0,
		battleshipb = 0,
		cruiserb = 0,
		destroyerb = 0;
}lucky, lucky2;
//This is computer's memory to play
struct computer
{
	int count = 0;
	int x, y;
	int x1, y1;
	bool level = 0; // 0 - random 1 - advanced
	bool hit = false;
	int go = 1;// 1 - horizontalr,2 - horizontall,3 - verticalr,4 - verticall
	bool
		horizontalr = true,
		horizontall = true,
		verticalr = true,
		verticall = true;
	int miss = 0;

}computer;
//This is for making an exact sequence 
struct temp{
	int a = 0;
	bool sequence = false;
	bool sequence2 = false;
	int cnt = 0;
	bool compvscomp = false;
}sequence;
//Cleaning main variables for a new game
void clearing()
{
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			memory1[i][j] = '\0';
			memory2[i][j] = '\0';
		}
	}
	/// LUCKY 1
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			lucky.carrier[i][j] = 0;
			lucky.battleship[i][j] = 0;
			lucky.cruiser[i][j] = 0;
			lucky.destroyer[i][j] = 0;
		}
	}
	lucky.carrierx = 0,
		lucky.battleshipx = 0,
		lucky.cruiserx = 0,
		lucky.destroyerx = 0,
		lucky.win = 0;
	lucky.carrierb = 0,
		lucky.battleshipb = 0,
		lucky.cruiserb = 0,
		lucky.destroyerb = 0;
	/// LUCKY 1

	/// LUCKY 2
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			lucky2.carrier[i][j] = 0;
			lucky2.battleship[i][j] = 0;
			lucky2.cruiser[i][j] = 0;
			lucky2.destroyer[i][j] = 0;
		}
	}
	lucky2.carrierx = 0,
		lucky2.battleshipx = 0,
		lucky2.cruiserx = 0,
		lucky2.destroyerx = 0,
		lucky2.win = 0;
	lucky2.carrierb = 0,
		lucky2.battleshipb = 0,
		lucky2.cruiserb = 0,
		lucky2.destroyerb = 0;
	/// LUCKY 2

	/// COMPUTER
	computer.count = 0;
	computer.x = 0;
	computer.y = 0;
	computer.x1 = 0;
	computer.y1 = 0;
	computer.level = 0;
	computer.hit = false;
	computer.go = 1;
	computer.horizontalr = true,
		computer.horizontall = true,
		computer.verticalr = true,
		computer.verticall = true;
	computer.miss = 0;
	/// COMPUTER

	/// TEMP
	sequence.a = 0;
	sequence.sequence = false;
	sequence.sequence2 = false;
	sequence.cnt = 0;
	sequence.compvscomp = false;

	/// TEMP
}
//Shows winner,clearing values;
void winner(int a)
{
	if (a == 1)
	{
		system("cls");
		system("color f0");
		cout << "PLAYER ONE WON!!!";

	}
	if (a == 2)
	{
		system("cls");
		system("color f0");
		cout << "PLAYER TWO WON!!!";

	}


	cout << "\nCLICK SOMETHING TO EXIT" << endl;
	clearing();
	_getch();

}
//This function defines random cordinates for battleships
void fillerbonuses(){
	// 0 -y
	// 1 -x


	//Carrier
	lucky.carrier[0][0] = rand() % 10; // - yandaki
	lucky.carrier[0][1] = rand() % 10; // - yuxaridaki
	int a = random();
	int b = random();
	for (;;)
	{
		if (a == 0)
		{
			if (b == 0)
			{
				if (lucky.carrier[0][0] + 4 <= 9)
				{
					for (int i = 1; i < 5; i++)
					{
						lucky.carrier[i][1] = lucky.carrier[0][1];
						lucky.carrier[i][0] = lucky.carrier[0][0] + i;
					}
					break;
				}
				else b = 1;
			}
			if (b == 1)
			{
				if (lucky.carrier[0][0] - 4 >= 0)
				{
					for (int i = 1; i < 5; i++)
					{
						lucky.carrier[i][1] = lucky.carrier[0][1];
						lucky.carrier[i][0] = lucky.carrier[0][0] - i;
					}
					break;
				}
				else b = 0;
			}
		}
		if (a == 1)
		{
			if (b == 0)
			{
				if (lucky.carrier[0][1] + 4 <= 9)
				{
					for (int i = 1; i < 5; i++)
					{
						lucky.carrier[i][0] = lucky.carrier[0][0];
						lucky.carrier[i][1] = lucky.carrier[0][1] + i;
					}
					break;
				}
				else b = 1;
			}
			if (b == 1)
			{
				if (lucky.carrier[0][1] - 4 >= 0)
				{
					for (int i = 1; i < 5; i++)
					{
						lucky.carrier[i][0] = lucky.carrier[0][0];
						lucky.carrier[i][1] = lucky.carrier[0][1] - i;
					}
					break;
				}
				else b = 0;
			}
		}

	}
	//battleship
	lucky.battleship[0][0] = rand() % 10; // - yandaki
	lucky.battleship[0][1] = rand() % 10; // - yuxaridaki
	a = random();
	b = random();
	//filler
	for (;;)
	{
		if (a == 0)
		{ // This part works with 0 cordinate
			if (b == 0)
			{
				if (lucky.battleship[0][0] + 3 <= 9)
				{ // asagi vertical
					for (int i = 1; i < 4; i++)
					{
						lucky.battleship[i][1] = lucky.battleship[0][1];
						lucky.battleship[i][0] = lucky.battleship[0][0] + i;
					}
					break;
				}
				else b = 1;
			}
			if (b == 1)
			{
				if (lucky.battleship[0][0] - 3 >= 0)
				{
					for (int i = 1; i < 4; i++)
					{ // yuxari vertical
						lucky.battleship[i][1] = lucky.battleship[0][1];
						lucky.battleship[i][0] = lucky.battleship[0][0] - i;
					}
					break;
				}
				else b = 0;
			}
		}



		if (a == 1)
		{ // This part works with 1 cordinate
			if (b == 0)
			{
				if (lucky.battleship[0][1] + 3 <= 9)
				{
					for (int i = 1; i < 4; i++)
					{
						lucky.battleship[i][0] = lucky.battleship[0][0];
						lucky.battleship[i][1] = lucky.battleship[0][1] + i;
					}
					break;
				}
				else b = 1;
			}

			if (b == 1)
			{
				if (lucky.battleship[0][1] - 3 >= 0)
				{
					for (int i = 1; i < 4; i++)
					{
						lucky.battleship[i][0] = lucky.battleship[0][0];
						lucky.battleship[i][1] = lucky.battleship[0][1] - i;
					}
					break;
				}
				else b = 0;
			}
		}
	}


	//Stop crossing
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (lucky.carrier[i][0] == lucky.battleship[j][0] && lucky.carrier[i][1] == lucky.battleship[j][1])
			{
				fillerbonuses();
			}
		}
	}

	// Crusier
	lucky.cruiser[0][0] = rand() % 10;
	lucky.cruiser[0][1] = rand() % 10;
	a = random();
	b = random();

	for (;;)
	{
		if (a == 0)
		{ // Works with 0 cordinate
			if (b == 0)
			{
				if (lucky.cruiser[0][0] + 2 <= 9)
				{
					for (int i = 1; i < 3; i++)
					{
						lucky.cruiser[i][1] = lucky.cruiser[0][1];
						lucky.cruiser[i][0] = lucky.cruiser[0][0] + i;
					}
					break;
				}
				else b = 1;
			}
			if (b == 1)
			{
				if (lucky.cruiser[0][0] - 2 >= 0)
				{
					for (int i = 1; i < 3; i++)
					{
						lucky.cruiser[i][1] = lucky.cruiser[0][1];
						lucky.cruiser[i][0] = lucky.cruiser[0][0] - i;
					}
					break;
				}
				else b = 0;
			}
		}
		if (a == 1)
		{ // WOrks with cordinate 0
			if (b == 0)
			{
				if (lucky.cruiser[0][1] + 2 <= 9)
				{
					for (int i = 1; i < 3; i++)
					{
						lucky.cruiser[i][0] = lucky.cruiser[0][0];
						lucky.cruiser[i][1] = lucky.cruiser[0][1] + i;
					}
					break;
				}
				else b = 1;
			}
			if (b == 1)
			{
				if (lucky.cruiser[0][1] - 2 >= 0)
				{
					for (int i = 1; i < 3; i++)
					{
						lucky.cruiser[i][0] = lucky.cruiser[0][0];
						lucky.cruiser[i][1] = lucky.cruiser[0][1] - i;
					}
					break;
				}
				else b = 0;
			}
		}

	}

	// stop cruiser crossing
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i != 4)
			{
				if (lucky.battleship[i][0] == lucky.cruiser[j][0] && lucky.battleship[i][1] == lucky.cruiser[j][1])
				{
					fillerbonuses();
				}
			}
			if (lucky.carrier[i][0] == lucky.cruiser[j][0] && lucky.carrier[i][1] == lucky.cruiser[j][1])
			{
				fillerbonuses();
			}
		}
	}
	for (;;)
	{
		// Destroyer
		lucky.destroyer[0][0] = rand() % 10;
		lucky.destroyer[0][1] = rand() % 10;
		a = random();
		b = random();
		for (;;)
		{
			if (a == 0)
			{ // Works with 0 cordinate
				if (b == 0)
				{
					if (lucky.destroyer[0][0] + 1 <= 9)
					{
						lucky.destroyer[1][1] = lucky.destroyer[0][1];
						lucky.destroyer[1][0] = lucky.destroyer[0][0] + 1;
						break;
					}
					else b = 1;
				}
				if (b == 1)
				{
					if (lucky.destroyer[0][0] - 1 >= 0)
					{
						lucky.destroyer[1][1] = lucky.destroyer[0][1];
						lucky.destroyer[1][0] = lucky.destroyer[0][0] - 1;
						break;
					}
					else b = 0;
				}
			}
			if (a == 1)
			{ // Works with 1 cordinate
				if (b == 0)
				{
					if (lucky.destroyer[0][1] + 1 <= 9)
					{
						lucky.destroyer[1][0] = lucky.destroyer[0][0];
						lucky.destroyer[1][1] = lucky.destroyer[0][1] + 1;
						break;
					}
					else b = 1;
				}
				if (b == 1)
				{
					if (lucky.destroyer[0][1] - 1 >= 0)
					{
						lucky.destroyer[1][0] = lucky.destroyer[0][0];
						lucky.destroyer[1][1] = lucky.destroyer[0][1] - 1;
						break;
					}
					else b = 0;
				}
			}
		}
		//
		bool plsBreak = false;
		//	Stop destroyer crossing
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (lucky.destroyer[i][0] == lucky.carrier[j][0] && lucky.destroyer[i][1] == lucky.carrier[j][1])
				{
					plsBreak = false; break;
				}
				else if (lucky.destroyer[i][0] == lucky.battleship[j][0] && lucky.destroyer[i][1] == lucky.battleship[j][1])
				{
					plsBreak = false; break;
				}
				// else if (lucky.destroyer[i][0] == lucky.cruiser[j][0] && lucky.destroyer[i][1] == lucky.cruiser[j][1])
				// {
				// 	cout << "Cruiser crossed" << endl;
				// } //Islememelidir amma isleyir (bura gel)
				else plsBreak = true;

			}
			if (plsBreak == false)break;
		}
		if (plsBreak == true)break;
		else continue;
	}
}
//This function defines random cordinates for battleships(But this is your cordinates)
void fillerbonuseshuman()
{
	//Carrier
	lucky2.carrier[0][0] = rand() % 10; // - yandaki
	lucky2.carrier[0][1] = rand() % 10; // - yuxaridaki
	int a = random();
	int b = random();
	for (;;)
	{
		if (a == 0)
		{
			if (b == 0)
			{
				if (lucky2.carrier[0][0] + 4 <= 9)
				{
					for (int i = 1; i < 5; i++)
					{
						lucky2.carrier[i][1] = lucky2.carrier[0][1];
						lucky2.carrier[i][0] = lucky2.carrier[0][0] + i;
					}
					break;
				}
				else b = 1;
			}
			if (b == 1)
			{
				if (lucky2.carrier[0][0] - 4 >= 0)
				{
					for (int i = 1; i < 5; i++)
					{
						lucky2.carrier[i][1] = lucky2.carrier[0][1];
						lucky2.carrier[i][0] = lucky2.carrier[0][0] - i;
					}
					break;
				}
				else b = 0;
			}
		}
		if (a == 1)
		{
			if (b == 0)
			{
				if (lucky2.carrier[0][1] + 4 <= 9)
				{
					for (int i = 1; i < 5; i++)
					{
						lucky2.carrier[i][0] = lucky2.carrier[0][0];
						lucky2.carrier[i][1] = lucky2.carrier[0][1] + i;
					}
					break;
				}
				else b = 1;
			}
			if (b == 1)
			{
				if (lucky2.carrier[0][1] - 4 >= 0)
				{
					for (int i = 1; i < 5; i++)
					{
						lucky2.carrier[i][0] = lucky2.carrier[0][0];
						lucky2.carrier[i][1] = lucky2.carrier[0][1] - i;
					}
					break;
				}
				else b = 0;
			}
		}

	}
	//battleship
	lucky2.battleship[0][0] = rand() % 10; // - yandaki
	lucky2.battleship[0][1] = rand() % 10; // - yuxaridaki
	a = random();
	b = random();
	//filler
	for (;;)
	{
		if (a == 0)
		{ // This part works with 0 cordinate
			if (b == 0)
			{
				if (lucky2.battleship[0][0] + 3 <= 9)
				{ // asagi vertical
					for (int i = 1; i < 4; i++)
					{
						lucky2.battleship[i][1] = lucky2.battleship[0][1];
						lucky2.battleship[i][0] = lucky2.battleship[0][0] + i;
					}
					break;
				}
				else b = 1;
			}
			if (b == 1)
			{
				if (lucky2.battleship[0][0] - 3 >= 0)
				{
					for (int i = 1; i < 4; i++)
					{ // yuxari vertical
						lucky2.battleship[i][1] = lucky2.battleship[0][1];
						lucky2.battleship[i][0] = lucky2.battleship[0][0] - i;
					}
					break;
				}
				else b = 0;
			}
		}



		if (a == 1)
		{ // This part works with 1 cordinate
			if (b == 0)
			{
				if (lucky2.battleship[0][1] + 3 <= 9)
				{
					for (int i = 1; i < 4; i++)
					{
						lucky2.battleship[i][0] = lucky2.battleship[0][0];
						lucky2.battleship[i][1] = lucky2.battleship[0][1] + i;
					}
					break;
				}
				else b = 1;
			}

			if (b == 1)
			{
				if (lucky2.battleship[0][1] - 3 >= 0)
				{
					for (int i = 1; i < 4; i++)
					{
						lucky2.battleship[i][0] = lucky2.battleship[0][0];
						lucky2.battleship[i][1] = lucky2.battleship[0][1] - i;
					}
					break;
				}
				else b = 0;
			}
		}
	}


	//Stop crossing
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (lucky2.carrier[i][0] == lucky2.battleship[j][0] && lucky2.carrier[i][1] == lucky2.battleship[j][1])
			{
				fillerbonuses();
			}
		}
	}

	// Crusier
	lucky2.cruiser[0][0] = rand() % 10;
	lucky2.cruiser[0][1] = rand() % 10;
	a = random();
	b = random();

	for (;;)
	{
		if (a == 0)
		{ // Works with 0 cordinate
			if (b == 0)
			{
				if (lucky2.cruiser[0][0] + 2 <= 9)
				{
					for (int i = 1; i < 3; i++)
					{
						lucky2.cruiser[i][1] = lucky2.cruiser[0][1];
						lucky2.cruiser[i][0] = lucky2.cruiser[0][0] + i;
					}
					break;
				}
				else b = 1;
			}
			if (b == 1)
			{
				if (lucky2.cruiser[0][0] - 2 >= 0)
				{
					for (int i = 1; i < 3; i++)
					{
						lucky2.cruiser[i][1] = lucky2.cruiser[0][1];
						lucky2.cruiser[i][0] = lucky2.cruiser[0][0] - i;
					}
					break;
				}
				else b = 0;
			}
		}
		if (a == 1)
		{ // WOrks with cordinate 0
			if (b == 0)
			{
				if (lucky2.cruiser[0][1] + 2 <= 9)
				{
					for (int i = 1; i < 3; i++)
					{
						lucky2.cruiser[i][0] = lucky2.cruiser[0][0];
						lucky2.cruiser[i][1] = lucky2.cruiser[0][1] + i;
					}
					break;
				}
				else b = 1;
			}
			if (b == 1)
			{
				if (lucky2.cruiser[0][1] - 2 >= 0)
				{
					for (int i = 1; i < 3; i++)
					{
						lucky2.cruiser[i][0] = lucky2.cruiser[0][0];
						lucky2.cruiser[i][1] = lucky2.cruiser[0][1] - i;
					}
					break;
				}
				else b = 0;
			}
		}

	}

	// stop cruiser crossing
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i != 4)
			{
				if (lucky2.battleship[i][0] == lucky2.cruiser[j][0] && lucky2.battleship[i][1] == lucky2.cruiser[j][1])
				{
					fillerbonuses();
				}
			}
			if (lucky2.carrier[i][0] == lucky2.cruiser[j][0] && lucky2.carrier[i][1] == lucky2.cruiser[j][1])
			{
				fillerbonuses();
			}
		}
	}


	for (;;)
	{
		// Destroyer
		lucky2.destroyer[0][0] = rand() % 10;
		lucky2.destroyer[0][1] = rand() % 10;
		a = random();
		b = random();
		for (;;)
		{
			if (a == 0)
			{ // Works with 0 cordinate
				if (b == 0)
				{
					if (lucky2.destroyer[0][0] + 1 <= 9)
					{
						lucky2.destroyer[1][1] = lucky2.destroyer[0][1];
						lucky2.destroyer[1][0] = lucky2.destroyer[0][0] + 1;
						break;
					}
					else b = 1;
				}
				if (b == 1)
				{
					if (lucky2.destroyer[0][0] - 1 >= 0)
					{
						lucky2.destroyer[1][1] = lucky2.destroyer[0][1];
						lucky2.destroyer[1][0] = lucky2.destroyer[0][0] - 1;
						break;
					}
					else b = 0;
				}
			}
			if (a == 1)
			{ // Works with 1 cordinate
				if (b == 0)
				{
					if (lucky2.destroyer[0][1] + 1 <= 9)
					{
						lucky2.destroyer[1][0] = lucky2.destroyer[0][0];
						lucky2.destroyer[1][1] = lucky2.destroyer[0][1] + 1;
						break;
					}
					else b = 1;
				}
				if (b == 1)
				{
					if (lucky2.destroyer[0][1] - 1 >= 0)
					{
						lucky2.destroyer[1][0] = lucky2.destroyer[0][0];
						lucky2.destroyer[1][1] = lucky2.destroyer[0][1] - 1;
						break;
					}
					else b = 0;
				}
			}
		}
		//
		bool plsBreak = false;
		//	Stop destroyer crossing
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (lucky2.destroyer[i][0] == lucky2.carrier[j][0] && lucky2.destroyer[i][1] == lucky2.carrier[j][1])
				{
					plsBreak = false; break;
				}
				else if (lucky2.destroyer[i][0] == lucky2.battleship[j][0] && lucky2.destroyer[i][1] == lucky2.battleship[j][1])
				{
					plsBreak = false; break;
				}
				// else if (lucky2.destroyer[i][0] == lucky2.cruiser[j][0] && lucky2.destroyer[i][1] == lucky2.cruiser[j][1])
				// {
				// 	cout << "Cruiser crossed" << endl;
				// } //Islememelidir amma isleyir (bura gel)
				else plsBreak = true;

			}
			if (plsBreak == false)break;
		}
		if (plsBreak == true)break;
		else continue;
	}

}
//With this function you can fill your bonuses randomly
void humanfill()
{
	char memoryforfill[11][11]{};
	bool stop = false;
	char selection;
	int b = 0; int x, y;
	for (;;)
	{
		system("cls");
		system("color 0F");
		cout << "HUMAN FILL : " << endl;
		//First table
		cout << "    ";
		for (int i = 0; i < 10; i++)
		{
			cout << i << " | ";
		}
		cout << endl;
		// --------- 
		for (int i = 0; i < 43; i++)
		{
			cout << char(196);
		}
		cout << endl;
		//
		for (int i = 0; i < 10; i++)
		{
			cout << i;
			for (int j = 0; j < 11; j++)
			{
				cout << " | ";
				cout << memoryforfill[i][j];
			}
			cout << endl;
			for (int x = 0; x < 43; x++)
			{
				cout << char(196);
			}
			cout << endl;
		} // PRINTING	


		if (sequence.a == 0) // Carrier
		{
			if (b == 0)
			{
				cout << "Select first cordinate for Carrier(5 pieces)\n";
				for (;;)
				{
					cin >> x >> y;
					if (cin.fail())
					{
#undef max
						cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						cout << "Please select true cordinate." << endl;
						continue;
					}
					else break;
				}
			}
			if (x <= 9 && y <= 9)
			{
				if (b == 0)
				{
					lucky2.carrier[0][0] = x;
					lucky2.carrier[0][1] = y;
					memoryforfill[x][y] = char(4);
					b++;
					continue;
				}
				else if (b == 1)
				{
					cout << "CARRIER : " << endl;
					cout << "Vertical(V) or Horizontal(H)?";
					cin >> selection;
					if (selection == 'V' || selection == 'v')
					{
						cout << "High(H) or Down(D)?"; cin >> selection;
						for (;;)
						{
							if (selection == 'H' || selection == 'h')
							{
								if (lucky2.carrier[0][0] - 4 >= 0)
								{
									for (int i = 1; i < 5; i++)
									{
										lucky2.carrier[i][1] = lucky2.carrier[0][1];
										lucky2.carrier[i][0] = lucky2.carrier[0][0] - i;
										memoryforfill[lucky2.carrier[i][0]][lucky2.carrier[i][1]] = char(4);
									}
									sequence.a++;
									b = 0;
									break;
								}
								else
								{
									cout << "YOU CANT SELECT HIGH,ONLY DOWN(Program automaticly selected Down)";
									selection = char(254);
									Sleep(1000);
								}
							}
							if (selection == char(254) || selection == char(254))
							{
								if (lucky2.carrier[0][0] + 4 <= 9)
								{
									for (int i = 1; i < 5; i++)
									{
										lucky2.carrier[i][1] = lucky2.carrier[0][1];
										lucky2.carrier[i][0] = lucky2.carrier[0][0] + i;
										memoryforfill[lucky2.carrier[i][0]][lucky2.carrier[i][1]] = char(4);
									}
									sequence.a++;
									b = 0;
									break;
								}
								else
								{
									cout << "YOU CANT SELECT DOWN,ONLY HIGH(Program automaticly selected High)";
									selection = 'H';
									Sleep(1000);
								}
							}
						}
					}
					else if (selection == 'H' || selection == 'h')
					{
						cout << "Right(R) or Left?(L)"; cin >> selection;
						for (;;)
						{
							if (selection == 'R' || selection == 'r')
							{
								if (lucky2.carrier[0][1] + 4 <= 9)
								{
									for (int i = 1; i < 5; i++)
									{
										lucky2.carrier[i][0] = lucky2.carrier[0][0];
										lucky2.carrier[i][1] = lucky2.carrier[0][1] + i;
										memoryforfill[lucky2.carrier[i][0]][lucky2.carrier[i][1]] = char(4);
									}
									sequence.a++;
									b = 0;
									break;
								}
								else
								{
									cout << "YOU CANT SELECT RIGHT,ONLY LEFT(Program automaticly selected Left)";
									selection = 'L';
									continue;
								}
							}
							if (selection == 'L' || selection == 'l')
							{
								if (lucky2.carrier[0][1] - 4 >= 0)
								{
									for (int i = 1; i < 5; i++)
									{
										lucky2.carrier[i][0] = lucky2.carrier[0][0];
										lucky2.carrier[i][1] = lucky2.carrier[0][1] - i;
										memoryforfill[lucky2.carrier[i][0]][lucky2.carrier[i][1]] = char(4);
									}
									sequence.a++;
									b = 0;
									break;
								}
								else
								{
									cout << "YOU CANT SELECT LEFT,ONLY RIGHT(Program automaticly selected RIGHT)";
									selection = 'R';
									continue;
								}
							}
						}
					}
				}
			}
			else
			{
				cout << "SELECT CORDINATES LESS THAN 10" << endl;
				Sleep(1000);
				continue;
			}
		}

		if (sequence.a == 1) // Battleship
		{
			if (b == 0)
			{
				b++;
				continue;
			}
			if (b == 1)
			{

				cout << "Select first cordinate for Battleship(4 pieces)\n";
				for (;;)
				{
					cin >> x >> y;
					if (cin.fail())
					{
#undef max
						cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						cout << "Please select true cordinate." << endl;
						continue;
					}
					else break;
				}
				if (x > 9 || y > 9)
				{

					cout << "Select Cordinates less than 10!!!";

					Sleep(2000);
					continue;
				}

				if (memoryforfill[x][y] == char(4))
				{
					cout << "CROSSING!" << endl;
					Sleep(1000);
					continue;
				}
				b++;
			}

			if (b == 2)
			{
				lucky2.battleship[0][0] = x;
				lucky2.battleship[0][1] = y;
				memoryforfill[x][y] = char(4);
				b++;
				continue;
			}
			else if (b == 3)
			{
				cout << "BATTLESHIP : " << endl;
				cout << "Vertical(V) or Horizontal(H)?";
				cin >> selection;
				if (selection == 'V' || selection == 'v')
				{
					cout << "High(H) or Down(D)?"; cin >> selection;
					for (;;)
					{
						if (selection == 'H' || selection == 'h')
						{
							for (int i = 1; i < 4; i++)
							{
								if (memoryforfill[x - i][y] == char(4))
								{
									stop = true;
								}
							}
							if (stop == false)
							{
								if (lucky2.battleship[0][0] - 3 >= 0)
								{

									for (int i = 1; i < 4; i++)
									{
										lucky2.battleship[i][1] = lucky2.battleship[0][1];
										lucky2.battleship[i][0] = lucky2.battleship[0][0] - i;
										memoryforfill[lucky2.battleship[i][0]][lucky2.battleship[i][1]] = char(4);
									}
									sequence.a++;
									b = 0;
									break;
								}
								else
								{
									cout << "YOU CANT SELECT HIGH,ONLY DOWN(Program automaticly selected Down)";
									Sleep(1000);
									selection = char(254);
									Sleep(1000);
								}
							}
							else break;

						}
						if (selection == char(254) || selection == char(254))
						{
							for (int i = 1; i < 4; i++)
							{
								if (memoryforfill[x + i][y] == char(4))
								{
									stop = true;
								}
							}

							if (stop == false)
							{
								if (lucky2.battleship[0][0] + 3 <= 9)
								{
									for (int i = 1; i < 4; i++)
									{
										lucky2.battleship[i][1] = lucky2.battleship[0][1];
										lucky2.battleship[i][0] = lucky2.battleship[0][0] + i;
										memoryforfill[lucky2.battleship[i][0]][lucky2.battleship[i][1]] = char(4);
									}
									sequence.a++;
									b = 0;
									break;
								}
								else
								{
									cout << "YOU CANT SELECT DOWN,ONLY HIGH(Program automaticly selected High)";
									Sleep(1000);
									selection = 'H';
									Sleep(1000);
								}
							}
							else break;
						}
					}
				}
				else if (selection == 'H' || selection == 'h')
				{
					cout << "Right(R) or Left?(L)"; cin >> selection;
					for (;;)
					{
						if (selection == 'R' || selection == 'r')
						{
							for (int i = 1; i < 4; i++)
							{
								if (memoryforfill[x][y + i] == char(4))
								{
									stop = true;
								}
							}

							if (stop == false)
							{
								if (lucky2.battleship[0][1] + 3 <= 9)
								{
									for (int i = 1; i < 4; i++)
									{
										lucky2.battleship[i][0] = lucky2.battleship[0][0];
										lucky2.battleship[i][1] = lucky2.battleship[0][1] + i;
										memoryforfill[lucky2.battleship[i][0]][lucky2.battleship[i][1]] = char(4);
									}
									sequence.a++;
									b = 0;
									break;
								}
								else
								{
									cout << "YOU CANT SELECT RIGHT,ONLY LEFT(Program automaticly selected Left)";
									Sleep(1000);
									selection = 'L';
									continue;
								}
							}
							else break;
						}

						if (selection == 'L' || selection == 'l')
						{
							for (int i = 1; i < 4; i++)
							{
								if (memoryforfill[x][y - i] == char(4))
								{
									stop = true;
								}
							}

							if (stop == false)
							{
								if (lucky2.battleship[0][1] - 3 >= 0)
								{
									for (int i = 1; i < 4; i++)
									{
										lucky2.battleship[i][0] = lucky2.battleship[0][0];
										lucky2.battleship[i][1] = lucky2.battleship[0][1] - i;
										memoryforfill[lucky2.battleship[i][0]][lucky2.battleship[i][1]] = char(4);
									}
									sequence.a++;
									b = 0;
									break;
								}
								else
								{
									cout << "YOU CANT SELECT LEFT,ONLY RIGHT(Program automaticly selected RIGHT)";
									Sleep(1000);
									selection = 'R';
									continue;
								}
							}
							else break;
						}
					}
				}
			}


			if (stop == true)
			{
				cout << "Battleships are crossing" << endl;
				stop = false;
				Sleep(1000);
				continue;
			}
		}

		if (sequence.a == 2) // Cruiser
		{
			if (b == 0)
			{
				b++;
				continue;
			}
			if (b == 1)
			{
				cout << "Select first cordinate for Cruiser(3 pieces)\n";
				for (;;)
				{
					cin >> x >> y;
					if (cin.fail())
					{
#undef max
						cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						cout << "Please select true cordinate." << endl;
						continue;
					}
					else break;
				}
				if (x > 9 || y > 9)
				{

					cout << "Select Cordinates less than 10!!!";

					Sleep(2000);
					continue;
				}
				if (memoryforfill[x][y] == char(4))
				{
					cout << "CROSSING!" << endl;
					Sleep(1000);
					continue;
				}
				b++;
			}

			if (b == 2)
			{
				lucky2.cruiser[0][0] = x;
				lucky2.cruiser[0][1] = y;
				memoryforfill[x][y] = char(4);
				b++;
				continue;
			}
			else if (b == 3)
			{
				cout << "Cruiser : " << endl;
				cout << "Vertical(V) or Horizontal(H)?";
				cin >> selection;
				if (selection == 'V' || selection == 'v')
				{
					cout << "High(H) or Down(D)?"; cin >> selection;
					for (;;)
					{
						if (selection == 'H' || selection == 'h')
						{
							for (int i = 1; i < 3; i++)
							{
								if (memoryforfill[x - i][y] == char(4))
								{
									stop = true;
								}
							}
							if (stop == false)
							{
								if (lucky2.cruiser[0][0] - 2 >= 0)
								{

									for (int i = 1; i < 3; i++)
									{
										lucky2.cruiser[i][1] = lucky2.cruiser[0][1];
										lucky2.cruiser[i][0] = lucky2.cruiser[0][0] - i;
										memoryforfill[lucky2.cruiser[i][0]][lucky2.cruiser[i][1]] = char(4);
									}
									sequence.a++;
									b = 0;
									break;
								}
								else
								{
									cout << "YOU CANT SELECT HIGH,ONLY DOWN(Program automaticly selected Down)";
									Sleep(1000);
									selection = char(254);
									Sleep(1000);
								}
							}
							else break;

						}
						if (selection == char(254) || selection == char(254))
						{
							for (int i = 1; i < 3; i++)
							{
								if (memoryforfill[x + i][y] == char(4))
								{
									stop = true;
								}
							}

							if (stop == false)
							{
								if (lucky2.cruiser[0][0] + 2 <= 9)
								{
									for (int i = 1; i < 3; i++)
									{
										lucky2.cruiser[i][1] = lucky2.cruiser[0][1];
										lucky2.cruiser[i][0] = lucky2.cruiser[0][0] + i;
										memoryforfill[lucky2.cruiser[i][0]][lucky2.cruiser[i][1]] = char(4);
									}
									sequence.a++;
									b = 0;
									break;
								}
								else
								{
									cout << "YOU CANT SELECT DOWN,ONLY HIGH(Program automaticly selected High)";
									Sleep(1000);
									selection = 'H';
									Sleep(1000);
								}
							}
							else break;
						}
					}
				}
				else if (selection == 'H' || selection == 'h')
				{
					cout << "Right(R) or Left?(L)"; cin >> selection;
					for (;;)
					{
						if (selection == 'R' || selection == 'r')
						{
							for (int i = 1; i < 3; i++)
							{
								if (memoryforfill[x][y + i] == char(4))
								{
									stop = true;
								}
							}

							if (stop == false)
							{
								if (lucky2.cruiser[0][1] + 2 <= 9)
								{
									for (int i = 1; i < 3; i++)
									{
										lucky2.cruiser[i][0] = lucky2.cruiser[0][0];
										lucky2.cruiser[i][1] = lucky2.cruiser[0][1] + i;
										memoryforfill[lucky2.cruiser[i][0]][lucky2.cruiser[i][1]] = char(4);
									}
									sequence.a++;
									b = 0;
									break;
								}
								else
								{
									cout << "YOU CANT SELECT RIGHT,ONLY LEFT(Program automaticly selected Left)";
									Sleep(1000);
									selection = 'L';
									continue;
								}
							}
							else break;
						}

						if (selection == 'L' || selection == 'l')
						{
							for (int i = 1; i < 3; i++)
							{
								if (memoryforfill[x][y - i] == char(4))
								{
									stop = true;
								}
							}

							if (stop == false)
							{
								if (lucky2.cruiser[0][1] - 2 >= 0)
								{
									for (int i = 1; i < 3; i++)
									{
										lucky2.cruiser[i][0] = lucky2.cruiser[0][0];
										lucky2.cruiser[i][1] = lucky2.cruiser[0][1] - i;
										memoryforfill[lucky2.cruiser[i][0]][lucky2.cruiser[i][1]] = char(4);
									}
									sequence.a++;
									b = 0;
									break;
								}
								else
								{
									cout << "YOU CANT SELECT LEFT,ONLY RIGHT(Program automaticly selected RIGHT)";
									Sleep(1000);
									selection = 'R';
									continue;
								}
							}
							else break;
						}
					}
				}
			}



			if (stop == true)
			{
				cout << "Battleships are crossing" << endl;
				stop = false;
				Sleep(1000);
				continue;
			}
		}
		if (sequence.a == 3) // Destroyer
		{
			if (b == 0)
			{
				b++;
				continue;
			}
			if (b == 1)
			{
				cout << "Select first cordinate for Destroyer(2 pieces)\n";
				for (;;)
				{
					cin >> x >> y;
					if (cin.fail())
					{
#undef max
						cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						cout << "Please select true cordinate." << endl;
						continue;
					}
					else break;
				}
				if (x > 9 || y > 9)
				{

					cout << "Select Cordinates less than 10!!!";

					Sleep(2000);
					continue;
				}
				if (memoryforfill[x][y] == char(4))
				{
					cout << "CROSSING!" << endl;
					Sleep(1000);
					continue;
				}
				b++;
			}

			if (b == 2)
			{
				lucky2.destroyer[0][0] = x;
				lucky2.destroyer[0][1] = y;
				memoryforfill[x][y] = char(4);
				b++;
				continue;
			}
			else if (b == 3)
			{
				cout << "Destroyer : " << endl;
				cout << "Vertical(V) or Horizontal(H)?";
				cin >> selection;
				if (selection == 'V' || selection == 'v')
				{
					cout << "High(H) or Down(D)?"; cin >> selection;
					for (;;)
					{
						if (selection == 'H' || selection == 'h')
						{

							if (memoryforfill[x - 1][y] == char(4))
							{
								stop = true;
							}

							if (stop == false)
							{
								if (lucky2.destroyer[0][0] - 1 >= 0)
								{
									lucky2.destroyer[1][1] = lucky2.destroyer[0][1];
									lucky2.destroyer[1][0] = lucky2.destroyer[0][0] - 1;
									memoryforfill[lucky2.destroyer[1][0]][lucky2.destroyer[1][1]] = char(4);
									sequence.a++;
									b = 0;
									break;
								}
								else
								{
									cout << "YOU CANT SELECT HIGH,ONLY DOWN(Program automaticly selected Down)";
									Sleep(1000);
									selection = char(254);
									Sleep(1000);
								}
							}
							else break;

						}
						if (selection == char(254) || selection == char(254))
						{

							if (memoryforfill[x + 1][y] == char(4))
							{
								stop = true;
							}


							if (stop == false)
							{
								if (lucky2.destroyer[0][0] + 1 <= 9)
								{

									lucky2.destroyer[1][1] = lucky2.destroyer[0][1];
									lucky2.destroyer[1][0] = lucky2.destroyer[0][0] + 1;
									memoryforfill[lucky2.destroyer[1][0]][lucky2.destroyer[1][1]] = char(4);
									sequence.a++;
									b = 0;
									break;
								}
								else
								{
									cout << "YOU CANT SELECT DOWN,ONLY HIGH(Program automaticly selected High)";
									Sleep(1000);
									selection = 'H';
									Sleep(1000);
								}
							}
							else break;
						}
					}
				}
				else if (selection == 'H' || selection == 'h')
				{
					cout << "Right(R) or Left?(L)"; cin >> selection;
					for (;;)
					{
						if (selection == 'R' || selection == 'r')
						{
							if (memoryforfill[x][y + 1] == char(4))
							{
								stop = true;
							}

							if (stop == false)
							{
								if (lucky2.destroyer[0][1] + 1 <= 9)
								{
									lucky2.destroyer[1][0] = lucky2.destroyer[0][0];
									lucky2.destroyer[1][1] = lucky2.destroyer[0][1] + 1;
									memoryforfill[lucky2.destroyer[1][0]][lucky2.destroyer[1][1]] = char(4);
									sequence.a++;
									b = 0;
									break;
								}
								else
								{
									cout << "YOU CANT SELECT RIGHT,ONLY LEFT(Program automaticly selected Left)";
									Sleep(1000);
									selection = 'L';
									continue;
								}
							}
							else break;
						}

						if (selection == 'L' || selection == 'l')
						{

							if (memoryforfill[x][y - 1] == char(4))
							{
								stop = true;
							}
							if (stop == false)
							{
								if (lucky2.destroyer[0][1] - 1 >= 0)
								{

									lucky2.destroyer[1][0] = lucky2.destroyer[0][0];
									lucky2.destroyer[1][1] = lucky2.destroyer[0][1] - 1;
									memoryforfill[lucky2.destroyer[1][0]][lucky2.destroyer[1][1]] = char(4);
									sequence.a++;
									b = 0;
									break;
								}
								else
								{
									cout << "YOU CANT SELECT LEFT,ONLY RIGHT(Program automaticly selected RIGHT)";
									Sleep(1000);
									selection = 'R';
									continue;
								}
							}
							else break;
						}
					}
				}
			}


			if (stop == true)
			{
				cout << "Battleships are crossing" << endl;
				stop = false;
				Sleep(1000);
				continue;
			}
		}
		//for (int i = 0; i < 5; i++)
		//{
		//	cout << lucky2.carrier[i][0] << " " << lucky2.carrier[i][1] << endl;
		//}
		//cout << endl;
		//for (int i = 0; i < 3; i++)
		//{
		//	cout << lucky2.cruiser[i][0] << " " << lucky2.cruiser[i][1] << endl;
		//}
		//cout << endl;
		//for (int i = 0; i < 4; i++)
		//{
		//	cout << lucky2.battleship[i][0] << " " << lucky2.battleship[i][1] << endl;
		//}
		//cout << endl;
		//for (int i = 0; i < 2; i++)
		//{
		//	cout << lucky2.destroyer[i][0] << " " << lucky2.destroyer[i][1] << endl;
		//}
		break;
	}
	for (;;)
	{
		system("cls");
		gotoxy(45, 15);
		system("color f2");

		cout << "SELECT :       <A>Advanced BOT\n";
		cout << "\t\t\t\t\t\t\t\t\t\t\t<B>Weak BOT\n";
		selection = _getch();

		if (selection == 13)
		{
			computer.level = 1;
			maindrawer();
			return;
		}
		else if (selection == 'B' || selection == 'b')
		{
			for (;;)
			{
				system("cls");
				gotoxy(45, 15);
				cout << "SELECT : \t\t\t\t\t<B>Weak BOT\n";
				cout << "\t\t\t\t\t\t\t    <A>Advanced BOT\n";
				selection = _getch();

				if (selection == 13)
				{
					computer.level = 0;
					maindrawer();
					return;
				}
				else if (selection == 'A' || selection == 'a')
				{
					break;
				}
				continue;

			}
		}

	}
}
//This is for clearing computer's memory after destroy
void end()
{
	computer.hit = false;
	computer.horizontalr = true;
	computer.horizontall = true;
	computer.verticalr = true;
	computer.verticall = true;
	computer.go = -1;
	sequence.cnt = 0;
}
//This is drawing a Battleship Games in enter
void loaderdraw(){
	char arr[100] = "Battleship Games";
	gotoxy(55, 15);
	system("color f0");
	for (int i = 0; i < strlen(arr); i++)
	{
		cout << arr[i];
		Sleep(100);
	}
	cout << endl;
}

//This is player 1 s logic
void player1logic(){

	//
	cout << endl;
	int check = 1; char letter;
	int x, y;
	if (sequence.compvscomp == false)
	{
		cout << "ENTER CORDINATES(x)(y)/33,33 to pause game/ : " << endl;
		cin >> x >> y;
		for (;;)
		{
			if (cin.fail())
			{
				cout << "Please input a number.(x)(y)" << endl;
				Sleep(500);
#undef max
				cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cin >> x >> y;
				continue;
			}
			else break;
		}
		if (x == 33 || y == 33) // Pausing
		{
			system("cls");
			cout << "PAUSED\n/Click 'R' to restart game/\n/Click 'X' to continue/" << endl;
			char selectionx = _getch();
			if (selectionx == 'r' || selectionx == 'R')
			{
				clearing();
				starter();
				return;
			}
			if (selectionx == 'x' || selectionx == 'X')
			{
				maindrawer();
				return;
			}

			return;
		}
		if (x > 9 || y > 9)
		{
			system("cls");
			maindrawer();
			return;
		}
		letter = char(177);
		//check - 1 E,check - 2 - X,check - 3 -Already hit,check - 4 - Destroyed
		if (memory1[x][y] == char(4) || memory1[x][y] == char(177)){
			maindrawer();
			return;
		}
	}
	else
	{
		letter = char(177);
		for (;;)
		{
			x = rand() % 10;
			y = rand() % 10;
			if (memory1[x][y] == char(4) || memory1[x][y] == char(177) || memory1[x][y] == char(254))
			{
				continue;
			}
			else break;
		}
		cout << "Computer decides the cordinates : " << endl;
		cout << x << " " << y << endl;
		Sleep(1000);
	}
	for (int i = 0; i < 5; i++)
	{
		if (x == lucky.carrier[i][0]){
			if (y == lucky.carrier[i][1]){
				if (lucky.carrierb == 0)
				{
					letter = char(4);
					check = 2;
					lucky.carrierx++;
					if (lucky.carrierx == 5) check = 4;
					break;
				}
				else
				{
					check = 3;
					letter = char(254);
				}
			}
		}
	}
	for (int i = 0; i < 4; i++)
	{


		if (x == lucky.battleship[i][0]){
			if (y == lucky.battleship[i][1]){
				if (lucky.battleshipb == 0)
				{
					letter = char(4);
					check = 2;
					lucky.battleshipx++;
					if (lucky.battleshipx == 4) check = 4;
					break;
				}
				else
				{
					check = 3;
					letter = char(254);
				}
			}
		}
	}
	for (int i = 0; i < 3; i++)
	{


		if (x == lucky.cruiser[i][0]){
			if (y == lucky.cruiser[i][1]){
				if (lucky.cruiserb == 0)
				{
					letter = char(4);
					check = 2;
					lucky.cruiserx++;
					if (lucky.cruiserx == 3) check = 4;
					break;
				}
				else
				{
					check = 3;
					letter = char(254);
				}
			}
		}
	}
	for (int i = 0; i < 2; i++)
	{


		if (x == lucky.destroyer[i][0]){
			if (y == lucky.destroyer[i][1]){
				if (lucky.destroyerb == 0)
				{
					letter = char(4);
					check = 2;
					lucky.destroyerx++;
					if (lucky.destroyerx == 2) check = 4;
					break;
				}
				else
				{
					check = 3;
					letter = char(254);
				}
			}
		}
	}

	memory1[x][y] = letter;
	if (check == 4)
	{
		system("cls");
		//system("color 2a");
		cout << "DESTROYED!\a\a" << endl;
		Sleep(600);
		system("color 0f");
	}
	if (check == 3)
	{
		system("cls");
		//system("color 4c");
		cout << "YOU ALREADY HIT IT!" << endl;
		Sleep(600);
		system("color 0f");
	}
	if (check == 2)
	{
		system("cls");
		//system("color 2a");
		cout << "YOU HIT IT!\a" << endl;
		Sleep(600);
		system("color 0f");
	}
	if (check == 1)
	{
		system("cls");
		//system("color 4c");
		cout << "MISSED!" << endl;
		Sleep(600);
		system("color 0f");
	}


	//
	for (;;)
	{
		if (lucky.carrierx == 5)
		{
			for (int i = 0; i < 5; i++)
			{
				int x = lucky.carrier[i][0];
				int y = lucky.carrier[i][1];
				memory1[x][y] = char(254);
				lucky.carrierb = true;
				lucky.carrierx = -52;
			}
			lucky.win++;
			break;
		}
		if (lucky.battleshipx == 4)
		{
			for (int i = 0; i < 4; i++)
			{
				int x = lucky.battleship[i][0];
				int y = lucky.battleship[i][1];
				memory1[x][y] = char(254);
				lucky.battleshipb = true;
				lucky.battleshipx = -52;
			}
			lucky.win++;
			break;
		}
		if (lucky.cruiserx == 3)
		{
			for (int i = 0; i < 3; i++)
			{
				int x = lucky.cruiser[i][0];
				int y = lucky.cruiser[i][1];
				memory1[x][y] = char(254);
				lucky.cruiserb = true;
				lucky.cruiserx = -52;
			}
			lucky.win++;
			break;
		}
		if (lucky.destroyerx == 2)
		{
			for (int i = 0; i < 2; i++)
			{
				int x = lucky.destroyer[i][0];
				int y = lucky.destroyer[i][1];
				memory1[x][y] = char(254);
				lucky.destroyerb = true;
				lucky.destroyerx = -52;
			}
			lucky.win++;
		}
		break;
	}
	if (lucky.win == 4)
	{
		winner(1);
	}
	sequence.sequence = true;
	maindrawer2();
}
//This is player 2 s logic
void player2logic()
{

	int x, y; char letter;
	cout << endl;
	cout << "Computer decides the cordinates : " << endl;

	if (computer.level == 0)
	{
		for (;;)
		{
			x = rand() % 10;
			y = rand() % 10;
			if (memory2[x][y] == char(4) || memory2[x][y] == char(177) || memory2[x][y] == char(254))
			{
				continue;
			}
			else break;
		}
	}
	else
	{
		for (;;)
		{
			x = rand() % 10;
			y = rand() % 10;
			if (memory2[x][y] == char(4) || memory2[x][y] == char(177) || memory2[x][y] == char(254))
			{
				continue;
			}
			else break;
		}

		if (computer.hit == true)
		{
			for (;;)
			{
				if (computer.y + 1 <= 9)
				{
					if (computer.horizontalr == true)
					{
						x = computer.x;
						y = computer.y + 1;
						computer.go = 1;

						break;
					}
				}
				else computer.horizontalr = false;
				if (computer.y - 1 >= 0)
				{
					if (computer.horizontall == true)
					{
						x = computer.x;
						y = computer.y - 1;
						computer.go = 2;

						break;
					}
				}
				else computer.horizontall = false;
				if (computer.x + 1 <= 9)
				{
					if (computer.verticalr == true)
					{
						y = computer.y;
						x = computer.x + 1;
						computer.go = 3;
						break;
					}
				}
				else computer.verticalr = false;
				if (computer.x - 1 >= 0)
				{
					if (computer.verticall == true)
					{
						y = computer.y;
						x = computer.x - 1;
						computer.go = 4;
						break;
					}
				}
				else {
					computer.verticall = false;
				}

				break;
			}
		}
	}


	if (computer.hit == false && computer.level == 1) // this is for selecting a correct cordinate after 3 miss.
	{
		if (computer.miss == 5)
		{
			bool plsBreakMe = false;
			for (;;)
			{
				int selectRandom = rand() % 4 + 1;
				if (selectRandom == 1 && lucky2.carrierb == 0) // for carrier
				{
					for (int i = 0; i < 5; i++)
					{
						x = lucky2.carrier[i][0];
						y = lucky2.carrier[i][1];
						if (memory2[x][y] == char(4) || memory2[x][y] == char(254) || memory2[x][y] == char(177))continue;
						else break;
					}
					plsBreakMe = true;
				}
				//
				if (selectRandom == 2 && lucky2.battleshipb == 0) // for carrier
				{
					for (int i = 0; i < 4; i++)
					{
						x = lucky2.battleship[i][0];
						y = lucky2.battleship[i][1];
						if (memory2[x][y] == char(4) || memory2[x][y] == char(254) || memory2[x][y] == char(177))continue;
						else break;
					}
					plsBreakMe = true;
				}
				//
				if (selectRandom == 3 && lucky2.cruiserb == 0) // for carrier
				{
					for (int i = 0; i < 3; i++)
					{
						x = lucky2.cruiser[i][0];
						y = lucky2.cruiser[i][1];
						if (memory2[x][y] == char(4) || memory2[x][y] == char(254) || memory2[x][y] == char(177))continue;
						else break;
					}
					plsBreakMe = true;
				}
				//
				if (selectRandom == 4 && lucky2.destroyerb == 0) // for carrier
				{
					for (int i = 0; i < 2; i++)
					{
						x = lucky2.destroyer[i][0];
						y = lucky2.destroyer[i][1];
						if (memory2[x][y] == char(4) || memory2[x][y] == char(254) || memory2[x][y] == char(177))continue;
						else break;
					}
					plsBreakMe = true;
				}
				if (plsBreakMe == true)break;
				else continue;
			}
		}
	}

	letter = char(177);
	cout << x << " " << y << endl;
	Sleep(1000);

	bool doNotGo = false;
	int check = 1;//check - 1 E,check - 2 - X,check - 3 -Already hit,check - 4 - Destroyed
	if (memory2[x][y] == char(4) || memory2[x][y] == char(177) || memory2[x][y] == char(254)){
		check = 3;
		doNotGo = true;
	}
	for (int i = 0; i < 5; i++)
	{
		if (doNotGo == true) break;
		if (lucky2.carrier[i][0] == x)
		{
			if (lucky2.carrier[i][1] == y)
			{
				if (lucky2.carrierb == 0)
				{
					letter = char(4);
					check = 2;
					lucky2.carrierx++;
					if (lucky2.carrierx == 5) check = 4;
				}
				else
				{
					check = 3;
					letter = char(254);
				}
			}

		}
	}
	for (int i = 0; i < 4; i++)
	{
		if (doNotGo == true) break;
		if (lucky2.battleship[i][0] == x)
		{
			if (lucky2.battleship[i][1] == y)
			{
				if (lucky2.battleshipb == 0)
				{
					letter = char(4);
					check = 2;
					lucky2.battleshipx++;
					if (lucky2.battleshipx == 4) check = 4;
				}
				else
				{
					check = 3;
					letter = char(254);
				}
			}
		}
	}
	for (int i = 0; i < 3; i++)
	{
		if (doNotGo == true) break;
		if (lucky2.cruiser[i][0] == x)
		{
			if (lucky2.cruiser[i][1] == y)
			{
				if (lucky2.cruiserb == 0)
				{
					letter = char(4);
					check = 2;
					lucky2.cruiserx++;
					if (lucky2.cruiserx == 3) check = 4;
				}
				else
				{
					check = 3;
					letter = char(254);
				}
			}
		}
	}
	for (int i = 0; i < 2; i++)
	{
		if (doNotGo == true) break;
		if (lucky2.destroyer[i][0] == x)
		{
			if (lucky2.destroyer[i][1] == y)
			{
				if (lucky2.destroyerb == 0)
				{
					letter = char(4);
					check = 2;
					lucky2.destroyerx++;
					if (lucky2.destroyerx == 2) check = 4;
				}
				else
				{
					check = 3;
					letter = char(254);
				}
			}
		}
	}
	//
	if (doNotGo == false)memory2[x][y] = letter;
	//for advanced
	if (computer.level == 1)
	{
		if (check == 2)
		{
			computer.x = x;
			computer.y = y;
			if (sequence.cnt == 0) { computer.x1 = x; computer.y1 = y; sequence.cnt = 60; }
			computer.hit = true;
		}
		else if (computer.hit == true)
		{
			// 1 - horizontalr,2 - horizontall,3 - verticalr,4 - verticall
			if (computer.go == 1)
			{
				computer.horizontalr = false;

				computer.x = computer.x1;
				computer.y = computer.y1;
			}
			if (computer.go == 2)
			{
				computer.horizontall = false;

				computer.x = computer.x1;
				computer.y = computer.y1;
			}
			if (computer.go == 3)
			{
				computer.verticalr = false;

				computer.x = computer.x1;
				computer.y = computer.y1;
			}
			if (computer.go == 4)
			{
				computer.verticall = false;

				computer.x = computer.x1;
				computer.y = computer.y1;
			}
		}
	}
	// Printing()
	if (check == 4)
	{
		end();
		system("cls");
		cout << "DESTROYED!" << endl;
		Sleep(1000);
	}
	if (check == 3)
	{
		system("cls");
		cout << "ALREADY HIT IT" << endl;
		Sleep(1000);
	}
	if (check == 2)
	{
		system("cls");
		cout << "HIT IT!" << endl;
		computer.miss = 0;
		Sleep(1000);
	}
	if (check == 1)
	{
		system("cls");
		cout << "MISSED!" << endl;
		if (computer.level == 1 && computer.hit == false)computer.miss++;
		Sleep(1000);
	}

	if (lucky2.carrierx == 5)
	{
		for (int i = 0; i < 5; i++)
		{
			int x = lucky2.carrier[i][0];
			int y = lucky2.carrier[i][1];
			memory2[x][y] = char(254);
			lucky2.carrierb = true;
			lucky2.carrierx = 999;
		}
		lucky2.win++;
	}
	if (lucky2.battleshipx == 4)
	{
		for (int i = 0; i < 4; i++)
		{
			int x = lucky2.battleship[i][0];
			int y = lucky2.battleship[i][1];
			memory2[x][y] = char(254);
			lucky2.battleshipb = true;
			lucky2.battleshipx = 999;
		}
		lucky2.win++;
	}
	if (lucky2.cruiserx == 3)
	{
		for (int i = 0; i < 3; i++)
		{
			int x = lucky2.cruiser[i][0];
			int y = lucky2.cruiser[i][1];
			memory2[x][y] = char(254);
			lucky2.cruiserb = true;
			lucky2.cruiserx = 999;
		}
		lucky2.win++;
	}
	if (lucky2.destroyerx == 2)
	{
		for (int i = 0; i < 2; i++)
		{
			int x = lucky2.destroyer[i][0];
			int y = lucky2.destroyer[i][1];
			memory2[x][y] = char(254);
			lucky2.destroyerb = true;
			lucky2.destroyerx = 999;
		}
		lucky2.win++;
	}

	if (lucky2.win == 4)
	{
		winner(2);
		return;
	}

	maindrawer();
}
//This is drawing the table for human
void maindrawer(){
	system("cls");
	system("color f0");
	if (sequence.compvscomp == false)cout << "COMPUTER'S BOARD : " << endl;
	else cout << "COMPUTER 2'S BOARD : " << endl;
	// First Table
	cout << "    ";
	for (int i = 0; i < 10; i++)
	{
		cout << i << " | ";

	}
	cout << endl;
	// --------- 
	for (int i = 0; i < 43; i++)
	{
		cout << char(196);
	}
	cout << endl;
	//
	for (int i = 0; i < 10; i++)
	{
		cout << i;
		for (int j = 0; j < 11; j++)
		{
			cout << " | ";
			cout << memory1[i][j];
		}
		cout << endl;
		for (int x = 0; x < 43; x++)
		{
			cout << char(196);
		}
		cout << endl;
	}
	if (sequence.compvscomp == false)
	{
		gotoxy(50, 0);
		cout << "YOUR BOARD : ";
		//
		gotoxy(50, 1);
		cout << "    ";
		for (int i = 0; i < 10; i++)
		{
			cout << i << " | ";
		}
		//
		gotoxy(50, 2);
		for (int i = 0; i < 43; i++)
		{
			cout << char(196);
		}
		//
		gotoxy(50, 3);
		int count = 4;
		for (int i = 0; i < 10; i++)
		{
			cout << i;
			for (int j = 0; j < 11; j++)
			{
				cout << " | ";
				cout << memory2[i][j];
			}
			gotoxy(50, count++);
			for (int x = 0; x < 43; x++)
			{
				cout << char(196);
			}
			gotoxy(50, count++);
		}
	}
	player1logic();
}
//This is computer's table
void maindrawer2(){
	system("cls");
	system("color f0");
	if (sequence.compvscomp == false)cout << "HUMAN'S BOARD : " << endl;
	else cout << "COMPUTER 1'S BOARD :  " << endl;
	// First Table
	cout << "    ";
	for (int i = 0; i < 10; i++)
	{
		cout << i << " | ";

	}
	cout << endl;
	// --------- 
	for (int i = 0; i < 43; i++)
	{
		cout << char(196);
	}
	cout << endl;
	//
	for (int i = 0; i < 10; i++)
	{
		cout << i;
		for (int j = 0; j < 11; j++)
		{
			cout << " | ";
			cout << memory2[i][j];
		}
		cout << endl;
		for (int x = 0; x < 43; x++)
		{
			cout << char(196);
		}
		cout << endl;
	}

	player2logic();

}
//This is Human vs Computer
void hvsc(){
	system("cls");

	gotoxy(45, 15);
	cout << "Do you want to place your battleships randomly(y/n/x)?";

	char selection; cin >> selection;

	if (selection == 'y' || selection == 'Y')
	{

		fillerbonuseshuman();
		fillerbonuses();
		for (;;)
		{
			system("cls");
			gotoxy(45, 15);
			system("color f2");

			cout << "SELECT :       <A>Advanced BOT\n";
			cout << "\t\t\t\t\t\t\t\t\t\t\t<B>Weak BOT\n";
			cout << "\n\n\n\t\t\t\t\t\t\t\t\t      <X>Back";
			selection = _getch();
			if (selection == 'x' || selection == 'X')return;

			if (selection == 13)
			{
				computer.level = 1;
				maindrawer();
				return;
			}
			else if (selection == 'B' || selection == 'b')
			{
				for (;;)
				{
					system("cls");
					system("color f1");
					gotoxy(45, 15);
					cout << "SELECT : \t\t\t\t\t<B>Weak BOT\n";
					cout << "\t\t\t\t\t\t\t    <A>Advanced BOT\n";
					cout << "\n\n\n\t\t\t\t\t\t\t\t\t      <X>Back";
					selection = _getch();
					if (selection == 'x' || selection == 'X')return;

					if (selection == 13)
					{
						computer.level = 0;
						maindrawer();
						return;
					}
					else if (selection == 'A' || selection == 'a')
					{
						break;
					}
					continue;

				}
			}

		}
	}
	else if (selection == 'n' || selection == 'N')
	{
		fillerbonuses();
		humanfill();
		return;
	}
	else if (selection == 'x' || selection == 'X')
	{
		return;
	}
	else
	{
		hvsc(); return;
	}
}
//This is Computer vs Computer
void cvsc(){
	system("cls");
	fillerbonuses();
	fillerbonuseshuman();
	sequence.compvscomp = true;
	maindrawer();
	return;
}
//This is Menu for start
void starter(){
	system("cls");
	system("color f2");
	gotoxy(40, 15);
	cout << "SELECT:   \t<A>Start\n";
	cout << "\t\t\t\t\t\t\t\t\t\t<B>Rules" << endl;

	char selection = _getch();

	////////////////////////////////////////////////////////////////////////////////////
	if (selection == 13)
	{
		for (;;)
		{
			system("cls");
			system("color f2");
			gotoxy(40, 15);

			cout << "SELECT:      <A>Human VS Computer\n";
			cout << "\t\t\t\t\t\t\t\t\t\t<B>Computer VS Computer" << endl;
			cout << "\n\n\t\t\t\t\t\t\t\t\t<X>Back" << endl;
			char selection2 = _getch();
			if (selection2 == 'x') { starter(); break; }


			if (selection2 == 13)
			{
				hvsc();
			}
			else if (selection2 == 'b')
			{
				for (;;)
				{
					system("cls");
					system("color f1");
					gotoxy(40, 15);
					cout << "SELECT:       \t\t\t\t<B>Computer VS Computer\n";
					cout << "\t\t\t\t\t\t     <A>Human VS Computer" << endl;
					cout << "\n\n\t\t\t\t\t\t\t\t\t<X>Back" << endl;
					selection2 = _getch();

					if (selection2 == 'x') { starter(); break; }

					if (selection2 == 13)
					{
						cvsc();  return;
					}
					else if (selection2 == 'a')
					{
						break;
					}
				}
			}
			else
			{
				continue;
			}
		}
	}
	////////////////////////////////////////////////////////////////////////////////////
	else if (selection == 'b')
	{
		for (;;)
		{
			system("cls");
			system("color f1");
			gotoxy(40, 15);

			cout << "SELECT:\t\t\t\t\t<B>Rules\n";

			cout << "\t\t\t\t\t\t\t<A>Start";

			selection = _getch();
			if (selection == 13)
			{

				cout << "\nRULES : " << endl;

				cout << "1.When you hit a part of battleship it will be showen up with " << char(4)  << "."<< endl;
				cout << "2.When you hit all parts of a battleship it will be showen up with " << char(254) << "." << endl;
				cout << "3.When you hit an empty area it will be showen up with " << char(177) << "." << endl;
				cout << "4.You cant attack a prohibited area." << endl;
				cout << "5.You cant hit the destroyed,hit area." << endl;
				cout << "6.You can place your battleships yourself too." << endl;
				cout << "7.You can make a Computer vs Computer game too." << endl;
				cout << "8.Try to not input letters to cordinates,otherwise it will get crashed!" << endl;
				cout << "9.Try to not input number to letter input,otherwise it will get crashed!" << endl;
				cout << "\n\nClick something to get back" << endl;
				_getch();

			}
			else if (selection == 'a')
			{
				starter();  return;
			}
			else
			{
				continue;
			}
		}
	}
	else
	{
		starter(); return;
	}
}
// Main
int main(){
	system("mode 145,35");
	srand(time(NULL));
	loaderdraw();
	starter();

}
