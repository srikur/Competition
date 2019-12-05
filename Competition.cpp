/*
	Lab 10 CECS 130

	Description: This program is a 3D Tic Tac Toe Board

	Kanuparthy Srikur, Section 01, 11/1/19, First Semester 2019-2020 School Year
	Sidharth Sundar, Section 02, 12/5/19, First Semester 2019-2020 School Year
*/

#define srikur 0
#define sidharth 1

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

namespace Srikur {

	class Slot {
	public:
		string value;
	};

	class Board {
	public:
		Slot spaces[9];

		bool avaliable(Slot space) {
			if ((space.value) != "X" && (space.value) != "O") {
				return true;
			}
			return false;
		}

		void fillSlot(Slot* move, int player) {
			string character;
			if (player == 1) {
				character = "O";
			}
			else if (player == 2)
				character = "X";
			move->value = character;
		}

		~Board() {}

		bool checkEnd();
		void printBoard();
		int checkWinner();

		int computerMove();
		void printCompetitionBoard();
	};

	class ThreeDBoard : public Board {
	public:
		Slot spaces[27];

		~ThreeDBoard() {}

	};

	ThreeDBoard board;
	int playerMove, computerMove, playerWins, computerWins;
	ThreeDBoard competitionBoard;

	void setupBoard() {

		competitionBoard.spaces[0].value = "1";
		competitionBoard.spaces[1].value = "2";
		competitionBoard.spaces[2].value = "3";
		competitionBoard.spaces[3].value = "4";
		competitionBoard.spaces[4].value = "5";
		competitionBoard.spaces[5].value = "6";
		competitionBoard.spaces[6].value = "7";
		competitionBoard.spaces[7].value = "8";
		competitionBoard.spaces[8].value = "9";
		competitionBoard.spaces[9].value = "10";
		competitionBoard.spaces[10].value = "11";
		competitionBoard.spaces[11].value = "12";
		competitionBoard.spaces[12].value = "13";
		competitionBoard.spaces[13].value = "14";
		competitionBoard.spaces[14].value = "15";
		competitionBoard.spaces[15].value = "16";
		competitionBoard.spaces[16].value = "17";
		competitionBoard.spaces[17].value = "18";
		competitionBoard.spaces[18].value = "19";
		competitionBoard.spaces[19].value = "20";
		competitionBoard.spaces[20].value = "21";
		competitionBoard.spaces[21].value = "22";
		competitionBoard.spaces[22].value = "23";
		competitionBoard.spaces[23].value = "24";
		competitionBoard.spaces[24].value = "25";
		competitionBoard.spaces[25].value = "26";
		competitionBoard.spaces[26].value = "27";
	}

	Slot* compPoint, * playPoint;
	int compMove, playMove;

	int Board::computerMove() {

		srand(time(NULL));

		do {
			compMove = (rand() % 27) + 1;
		} while (!competitionBoard.avaliable(competitionBoard.spaces[compMove - 1]));

		compPoint = &competitionBoard.spaces[compMove - 1];
		cout << "\nThe computer chose space " << compMove << "\n";
		competitionBoard.fillSlot(compPoint, 2);

		return compMove;
	}

	void Board::printCompetitionBoard() {
		//first pane
		cout << "\n " << competitionBoard.spaces[0].value << " | " << competitionBoard.spaces[1].value << " | " << competitionBoard.spaces[2].value;
		cout << "\n-----------";
		cout << "\n " << competitionBoard.spaces[3].value << " | " << competitionBoard.spaces[4].value << " | " << competitionBoard.spaces[5].value;
		cout << "\n-----------";
		cout << "\n " << competitionBoard.spaces[6].value << " | " << competitionBoard.spaces[7].value << " | " << competitionBoard.spaces[8].value << "\n";

		//second pane
		cout << "\n           " << competitionBoard.spaces[9].value << " | " << competitionBoard.spaces[10].value << " | " << competitionBoard.spaces[11].value;
		cout << "\n           ------------";
		cout << "\n           " << competitionBoard.spaces[12].value << " | " << competitionBoard.spaces[13].value << " | " << competitionBoard.spaces[14].value;
		cout << "\n           ------------";
		cout << "\n           " << competitionBoard.spaces[15].value << " | " << competitionBoard.spaces[16].value << " | " << competitionBoard.spaces[17].value << "\n";

		//third pane
		cout << "\n                        " << competitionBoard.spaces[18].value << " | " << competitionBoard.spaces[19].value << " | " << competitionBoard.spaces[20].value;
		cout << "\n                        ------------";
		cout << "\n                        " << competitionBoard.spaces[21].value << " | " << competitionBoard.spaces[22].value << " | " << competitionBoard.spaces[23].value;
		cout << "\n                        ------------";
		cout << "\n                        " << competitionBoard.spaces[24].value << " | " << competitionBoard.spaces[25].value << " | " << competitionBoard.spaces[26].value << "\n";

	}

	//function to print out the board
	void Board::printBoard() {
		//first pane
		cout << "\n " << board.spaces[0].value << " | " << board.spaces[1].value << " | " << board.spaces[2].value;
		cout << "\n-----------";
		cout << "\n " << board.spaces[3].value << " | " << board.spaces[4].value << " | " << board.spaces[5].value;
		cout << "\n-----------";
		cout << "\n " << board.spaces[6].value << " | " << board.spaces[7].value << " | " << board.spaces[8].value << "\n";

		//second pane
		cout << "\n           " << board.spaces[9].value << " | " << board.spaces[10].value << " | " << board.spaces[11].value;
		cout << "\n           ------------";
		cout << "\n           " << board.spaces[12].value << " | " << board.spaces[13].value << " | " << board.spaces[14].value;
		cout << "\n           ------------";
		cout << "\n           " << board.spaces[15].value << " | " << board.spaces[16].value << " | " << board.spaces[17].value << "\n";

		//third pane
		cout << "\n                        " << board.spaces[18].value << " | " << board.spaces[19].value << " | " << board.spaces[20].value;
		cout << "\n                        ------------";
		cout << "\n                        " << board.spaces[21].value << " | " << board.spaces[22].value << " | " << board.spaces[23].value;
		cout << "\n                        ------------";
		cout << "\n                        " << board.spaces[24].value << " | " << board.spaces[25].value << " | " << board.spaces[26].value << "\n";

	}


	//algorithms to check for winner
	int Board::checkWinner() {

		//Checks horizontal for each vertical panes
		for (int j = 0; j < 19; j += 9) {
			for (int i = 0; i < 7; i += 3) {
				if (board.spaces[i + j].value == (board.spaces[i + 1 + j].value) && board.spaces[i + j].value == (board.spaces[i + 2 + j].value)) {
					if (board.spaces[i + j].value == ("O")) {
						return srikur;
					}
					else {
						return sidharth;
					}
				}
			}
		}
		//Checks right diagonal for each vertical pane
		for (int i = 0; i < 19; i += 9) {
			if (board.spaces[i].value == (board.spaces[i + 4].value) && board.spaces[i].value == (board.spaces[i + 8].value)) {
				if (board.spaces[i].value == ("O")) {
					return srikur;
				}
				else {
					return sidharth;
				}
			}
		}

		//checks right diagonal for each horizontal pane
		for (int i = 0; i < 7; i += 3) {
			if (board.spaces[i].value == (board.spaces[i + 10].value) && board.spaces[i].value == (board.spaces[i + 20].value)) {
				if (board.spaces[i].value == ("O")) {
					return srikur;
				}
				else {
					return sidharth;
				}
			}
		}

		//checks left diagonal for each horizontal pane
		for (int i = 2; i < 9; i += 3) {
			if (board.spaces[i].value == (board.spaces[i + 8].value) && board.spaces[i].value == (board.spaces[i + 16].value)) {
				if (board.spaces[i].value == ("O")) {
					return srikur;
				}
				else {
					return sidharth;
				}
			}
		}


		//Checks left diagonal for each vertical pane
		for (int i = 2; i < 21; i += 9) {
			if (board.spaces[i].value == (board.spaces[i + 2].value) && board.spaces[i].value == (board.spaces[i + 4].value)) {
				if (board.spaces[i].value == ("O")) {
					return srikur;
				}
				else {
					return sidharth;
				}
			}
		}
		//Checks vertical for each vertical pane
		for (int j = 0; j < 19; j += 9) {
			for (int i = 0; i < 3; i++) {
				if (board.spaces[i + j].value == (board.spaces[i + 3 + j].value) && board.spaces[i + j].value == (board.spaces[i + 6 + j].value)) {
					if (board.spaces[i + j].value == ("O")) {
						return srikur;
					}
					else {
						return sidharth;
					}
				}
			}
		}
		//checks vertical for each horizontal pane 
		for (int j = 0; j < 7; j += 3) {
			for (int i = 0; i < 3; i++) {
				if (board.spaces[i + j].value == (board.spaces[i + 9 + j].value) && board.spaces[i + j].value == (board.spaces[i + 18 + j].value)) {
					if (board.spaces[i + j].value == ("O")) {
						return srikur;
					}
					else {
						return sidharth;
					}
				}
			}
		}

		//check four diagonals that go through the center
		if (board.spaces[0].value == (board.spaces[13].value) && board.spaces[0].value == (board.spaces[26].value)) {
			if (board.spaces[0].value == ("O")) {
				return srikur;
			}
			else {
				return sidharth;
			}
		}

		if (board.spaces[3].value == (board.spaces[13].value) && board.spaces[3].value == (board.spaces[24].value)) {
			if (board.spaces[3].value == ("O")) {
				return srikur;
			}
			else {
				return sidharth;
			}
		}

		if (board.spaces[20].value == (board.spaces[13].value) && board.spaces[20].value == (board.spaces[6].value)) {
			if (board.spaces[20].value == ("O")) {
				return srikur;
			}
			else {
				return sidharth;
			}
		}

		if (board.spaces[18].value == (board.spaces[13].value) && board.spaces[18].value == (board.spaces[8].value)) {
			if (board.spaces[18].value == ("O")) {
				return srikur;
			}
			else {
				return sidharth;
			}
		}
	}

	bool Board::checkEnd() {

		if (board.spaces[0].value != "1" && board.spaces[1].value != ("2") && board.spaces[2].value != ("3")
			&& board.spaces[3].value != ("4") && board.spaces[4].value != ("5")
			&& board.spaces[5].value != ("6") && board.spaces[7].value != ("8")
			&& board.spaces[8].value != ("9") && board.spaces[9].value != "10" && board.spaces[10].value != ("11") && board.spaces[11].value != ("12")
			&& board.spaces[12].value != ("13") && board.spaces[13].value != ("14")
			&& board.spaces[14].value != ("15") && board.spaces[15].value != ("16")
			&& board.spaces[16].value != ("17") && board.spaces[17].value != "18" && board.spaces[18].value != ("19") && board.spaces[19].value != ("20")
			&& board.spaces[20].value != ("21") && board.spaces[21].value != ("22")
			&& board.spaces[22].value != ("23") && board.spaces[23].value != ("24")
			&& board.spaces[24].value != ("25") && board.spaces[6].value != "7" && board.spaces[25].value != "26" && board.spaces[26].value != "27") {
			return true;
		}
		return false;
	}
}

namespace Sidharth
{

	class TicTacToeBoard {
	private:
		char board[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
		int count = 0;
		int move;


	public:

		void setBoard() {
			for (int i = 0; i <= 2; i++) {
				for (int j = 0; j <= 2; j++) {
					board[i][j] = ' ';
				}
			}
			count = 0;
		}

		void printBoard() {
			cout << "   0   1   2" << endl;
			cout << "   -   -   -" << endl;
			cout << "0: " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
			cout << "  -----------" << endl;
			cout << "1: " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
			cout << "  -----------" << endl;
			cout << "2: " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
		};

		string firstMove() {
			move = rand() % 2;
			if (move == 0) {
				return "The computer gets to move first. You have \"X\"s"; //First move ALWAYS uses O, second move ALWAYS uses X
			}
			else {
				return "You get to move first. You have \"O\"s ";
			}
		}

		bool playerMove(int x, int y) {
			if (x > 2 || x < 0 || y > 2 || y < 0) {
				cout << "Invalid input" << endl;
				return true;
			}

			if (board[x][y] != ' ') {
				cout << "Space is occupied" << endl;
				return true;
			}
			else {
				if (move == 0) {
					board[x][y] = 'X';
				}
				else {
					board[x][y] = 'O';
				}
				count++;
				return false;
			}

		}

		int computerMove() {
			int x;
			int y;
			do {
				x = rand() % 3;
				y = rand() % 3;
			} while (board[x][y] != ' ');

			if (move == 0) {
				board[x][y] = 'O';
			}
			else {
				board[x][y] = 'X';
			}
			count++;
			return 3 * x + y;

		}

		int getCount() {
			return count;
		}

		int getMove() {
			return move;
		}

		void setMove(int m) {
			move = m;
		}

		bool gameComplete() {
			if (count < 5) {
				return false;
			}
			char comp;
			int turn = count % 2;
			if (turn == 1) {
				comp = 'O';
			}
			else {
				comp = 'X';
			}

			if ((board[0][0] == comp && board[0][1] == comp && board[0][2] == comp) || (board[1][0] == comp && board[1][1] == comp && board[1][2] == comp) || (board[2][0] == comp && board[2][1] == comp && board[2][2] == comp) || (board[0][0] == comp && board[1][0] == comp && board[2][0] == comp) || (board[0][1] == comp && board[1][1] == comp && board[2][1] == comp) || (board[0][2] == comp && board[1][2] == comp && board[2][2] == comp) || (board[0][0] == comp && board[1][1] == comp && board[2][2] == comp) || (board[0][2] == comp && board[1][1] == comp && board[2][0] == comp)) {
				if ((move == 1 && turn == 0) || move == 0 && turn == 1) {
					cout << "Computer Wins!" << endl;
				}
				else {
					cout << "Player Wins!" << endl;
				}
				return true;
			}
			if (count == 9) {
				cout << "It's a tie." << endl;
				return true;
			}
			return false;

		}


	};

	/*----------------------------------------------------------------------------------------------------------------------------------------------------
	-------------------------------------------------------------------------------------------------------------------------------------------------------
	-----------------------------------------------------------------------------------------------------------------------------------------------------*/


	class TicTacToeBoard3D : public TicTacToeBoard
	{
	private:
		int actualBoard[3][3][3] = { {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}},{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}},{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}} };

		TicTacToeBoard b1;
		TicTacToeBoard b2;
		TicTacToeBoard b3;
		int moveCount = 0;
		int playerCount = 0;
		int computerCount = 0;



	public:
		int getMoveCount() {
			return moveCount;
		}

		void printBoard()
		{
			cout << "    Board 1 " << endl;
			cout << "   _________\n" << endl;
			b1.printBoard();
			cout << "\n    Board 2 " << endl;
			cout << "   _________\n" << endl;
			b2.printBoard();
			cout << "\n    Board 3 " << endl;
			cout << "   _________\n" << endl;
			b3.printBoard();
			cout << endl;
		}

		void setBoard() {
			b1.setBoard();
			b2.setBoard();
			b3.setBoard();
			moveCount = 0;
			for (int i = 0; i <= 2; i++) {
				for (int j = 0; j <= 2; j++) {
					for (int k = 0; k <= 2; k++) {
						actualBoard[i][j][k] = 0;
					}
				}
			}
		}

		bool playerMove(int boardNum, int x, int y)
		{
			if (boardNum == 1)
			{
				if (b1.playerMove(x, y))
				{
					return true;
				}
				actualBoard[boardNum - 1][x][y] = 1;
				moveCount += 1;

				return false;
			}
			else if (boardNum == 2)
			{
				if (b2.playerMove(x, y))
				{
					return true;
				}
				actualBoard[boardNum - 1][x][y] = 1;
				moveCount += 1;
				return false;
			}

			else if (boardNum == 3)
			{
				if (b3.playerMove(x, y))
				{
					return true;
				}
				actualBoard[boardNum - 1][x][y] = 1;
				moveCount += 1;
				return false;
			}

			cout << "Invalid Board Choice" << endl;
			return true;

		}

		void moveInitialize() {
			b1.setMove((getMove()));
			b2.setMove((getMove()));
			b3.setMove((getMove()));
		}

		int getTMove() {

			return getMove();
		}

		int computerMove()
		{
			int coordinates, x, y, bnum;
			while (true)
			{

				bnum = rand() % 3;
				if (bnum == 0)
				{
					if (b1.getCount() == 9)
					{
						continue;
					}

					else
					{
						coordinates = b1.computerMove();
						moveCount += 1;


						break;
					}
				}
				if (bnum == 1)
				{
					if (b2.getCount() == 9)
					{
						continue;
					}

					else
					{
						coordinates = b2.computerMove();
						moveCount += 1;
						break;
					}
				}
				if (bnum == 2)
				{
					if (b3.getCount() == 9)
					{
						continue;
					}

					else
					{
						coordinates = b3.computerMove();
						moveCount += 1;
						break;
					}
				}
			}
			y = coordinates % 3;
			x = (int)(coordinates - y) / 3;
			actualBoard[bnum][x][y] = -1;
			return bnum * 9 + coordinates + 1;
		}

		void printActual()
		{
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					for (int k = 0; k < 3; k++)
					{
						cout << actualBoard[i][j][k];
					}
					cout << endl;
				}
			}
		}

		int gameComplete()
		{
			//base class gameComplete() method returned a boolean, and we need a count, so I'm just completely overhauling the method.

			if (abs(actualBoard[0][0][0] + actualBoard[0][0][1] + actualBoard[0][0][2]) == 3)
			{

				if (actualBoard[0][0][0] == 1)
				{
					playerCount++;
				}
				else
				{
					computerCount++;
				}
			}
			if (abs(actualBoard[0][1][0] + actualBoard[0][1][1] + actualBoard[0][1][2]) == 3)
			{

				if (actualBoard[0][1][0] == 1)
				{
					playerCount++;
				}
				else
				{
					computerCount++;
				}
			}
			if (abs(actualBoard[0][2][0] + actualBoard[0][2][1] + actualBoard[0][2][2]) == 3)
			{

				if (actualBoard[0][2][0] == 1)
				{
					playerCount++;
				}
				else
				{
					computerCount++;
				}
			}
			if (abs(actualBoard[0][0][0] + actualBoard[0][1][0] + actualBoard[0][2][0]) == 3)
			{

				if (actualBoard[0][0][0] == 1)
				{
					playerCount++;
				}
				else
				{
					computerCount++;
				}
			}
			if (abs(actualBoard[0][0][1] + actualBoard[0][1][1] + actualBoard[0][2][1]) == 3)
			{

				if (actualBoard[0][0][1] == 1)
				{
					playerCount++;
				}
				else
				{
					computerCount++;
				}
			}
			if (abs(actualBoard[0][0][2] + actualBoard[0][1][2] + actualBoard[0][2][2]) == 3)
			{

				if (actualBoard[0][0][2] == 1)
				{
					playerCount++;
				}
				else
				{
					computerCount++;
				}
			}
			if (abs(actualBoard[0][0][0] + actualBoard[0][1][1] + actualBoard[0][2][2]) == 3)
			{

				if (actualBoard[0][0][0] == 1)
				{
					playerCount++;
				}
				else
				{
					computerCount++;
				}
			}
			if (abs(actualBoard[0][0][2] + actualBoard[0][1][1] + actualBoard[0][2][0]) == 3)
			{

				if (actualBoard[0][0][2] == 1)
				{
					playerCount++;
				}
				else
				{
					computerCount++;
				}
			}

			//board 2 only:

			if (abs(actualBoard[1][0][0] + actualBoard[1][0][1] + actualBoard[1][0][2]) == 3)
			{

				if (actualBoard[1][0][0] == 1)
				{
					playerCount++;
				}
				else
				{
					computerCount++;
				}
			}
			if (abs(actualBoard[1][1][0] + actualBoard[1][1][1] + actualBoard[1][1][2]) == 3)
			{

				if (actualBoard[1][1][0] == 1)
				{
					playerCount++;
				}
				else
				{
					computerCount++;
				}
			}
			if (abs(actualBoard[1][2][0] + actualBoard[1][2][1] + actualBoard[1][2][2]) == 3)
			{

				if (actualBoard[1][2][0] == 1)
				{
					playerCount++;
				}
				else
				{
					computerCount++;
				}
			}
			if (abs(actualBoard[1][0][0] + actualBoard[1][1][0] + actualBoard[1][2][0]) == 3)
			{

				if (actualBoard[1][0][0] == 1)
				{
					playerCount++;
				}
				else
				{
					computerCount++;
				}
			}
			if (abs(actualBoard[1][0][1] + actualBoard[1][1][1] + actualBoard[1][2][1]) == 3)
			{

				if (actualBoard[1][0][1] == 1)
				{
					playerCount++;
				}
				else
				{
					computerCount++;
				}
			}
			if (abs(actualBoard[1][0][2] + actualBoard[1][1][2] + actualBoard[1][2][2]) == 3)
			{

				if (actualBoard[1][0][2] == 1)
				{
					playerCount++;
				}
				else
				{
					computerCount++;
				}
			}
			if (abs(actualBoard[1][0][0] + actualBoard[1][1][1] + actualBoard[1][2][2]) == 3)
			{

				if (actualBoard[1][0][0] == 1)
				{
					playerCount++;
				}
				else
				{
					computerCount++;
				}
			}
			if (abs(actualBoard[1][0][2] + actualBoard[1][1][1] + actualBoard[1][2][0]) == 3)
			{

				if (actualBoard[1][0][2] == 1)
				{
					playerCount++;
				}
				else
				{
					computerCount++;
				}
			}

			//board 3 only:

			if (abs(actualBoard[2][0][0] + actualBoard[2][0][1] + actualBoard[2][0][2]) == 3)
			{

				if (actualBoard[2][0][0] == 1)
				{
					playerCount++;
				}
				else
				{
					computerCount++;
				}
			}
			if (abs(actualBoard[2][1][0] + actualBoard[2][1][1] + actualBoard[2][1][2]) == 3)
			{

				if (actualBoard[2][1][0] == 1)
				{
					playerCount++;
				}
				else
				{
					computerCount++;
				}
			}
			if (abs(actualBoard[2][2][0] + actualBoard[2][2][1] + actualBoard[2][2][2]) == 3)
			{

				if (actualBoard[2][2][0] == 1)
				{
					playerCount++;
				}
				else
				{
					computerCount++;
				}
			}
			if (abs(actualBoard[2][0][0] + actualBoard[2][1][0] + actualBoard[2][2][0]) == 3)
			{

				if (actualBoard[2][0][0] == 1)
				{
					playerCount++;
				}
				else
				{
					computerCount++;
				}
			}
			if (abs(actualBoard[2][0][1] + actualBoard[2][1][1] + actualBoard[2][2][1]) == 3)
			{

				if (actualBoard[2][0][1] == 1)
				{
					playerCount++;
				}
				else
				{
					computerCount++;
				}
			}
			if (abs(actualBoard[2][0][2] + actualBoard[2][1][2] + actualBoard[2][2][2]) == 3)
			{

				if (actualBoard[2][0][2] == 1)
				{
					playerCount++;
				}
				else
				{
					computerCount++;
				}
			}
			if (abs(actualBoard[2][0][0] + actualBoard[2][1][1] + actualBoard[2][2][2]) == 3)
			{

				if (actualBoard[2][0][0] == 1)
				{
					playerCount++;
				}
				else
				{
					computerCount++;
				}
			}
			if (abs(actualBoard[2][0][2] + actualBoard[2][1][1] + actualBoard[2][2][0]) == 3)
			{

				if (actualBoard[2][0][2] == 1)
				{
					playerCount++;
				}
				else
				{
					computerCount++;
				}
			}

			//Between boards:

			//Vertical 3 in a row:
			if (abs(actualBoard[0][0][0] + actualBoard[1][0][0] + actualBoard[2][0][0]) == 3)
			{

				if (actualBoard[0][0][0] == 1)
				{
					playerCount++;
				}
				else
				{
					computerCount++;
				}
			}
			if (abs(actualBoard[0][0][1] + actualBoard[1][0][1] + actualBoard[2][0][1]) == 3)
			{

				if (actualBoard[0][0][1] == 1)
				{
					playerCount++;
				}
				else
				{
					computerCount++;
				}
			}
			if (abs(actualBoard[0][0][2] + actualBoard[1][0][2] + actualBoard[2][0][2]) == 3)
			{

				if (actualBoard[0][0][2] == 1)
				{
					playerCount++;
				}
				else
				{
					computerCount++;
				}
			}
			if (abs(actualBoard[0][1][0] + actualBoard[1][1][0] + actualBoard[2][1][0]) == 3)
			{

				if (actualBoard[0][1][0] == 1)
				{
					playerCount++;
				}
				else
				{
					computerCount++;
				}
			}
			if (abs(actualBoard[0][1][1] + actualBoard[1][1][1] + actualBoard[2][1][1]) == 3)
			{

				if (actualBoard[0][1][1] == 1)
				{
					playerCount++;
				}
				else
				{
					computerCount++;
				}
			}
			if (abs(actualBoard[0][1][2] + actualBoard[1][1][2] + actualBoard[2][1][2]) == 3)
			{

				if (actualBoard[0][1][2] == 1)
				{
					playerCount++;
				}
				else
				{
					computerCount++;
				}
			}
			if (abs(actualBoard[0][2][0] + actualBoard[1][2][0] + actualBoard[2][2][0]) == 3)
			{

				if (actualBoard[0][2][0] == 1)
				{
					playerCount++;
				}
				else
				{
					computerCount++;
				}
			}
			if (abs(actualBoard[0][2][1] + actualBoard[1][2][1] + actualBoard[2][2][1]) == 3)
			{

				if (actualBoard[0][2][1] == 1)
				{
					playerCount++;
				}
				else
				{
					computerCount++;
				}
			}
			if (abs(actualBoard[0][2][2] + actualBoard[1][2][2] + actualBoard[2][2][2]) == 3)
			{

				if (actualBoard[0][2][2] == 1)
				{
					playerCount++;
				}
				else
				{
					computerCount++;
				}
			}


			//Diagonals:

			if (abs(actualBoard[0][0][0] + actualBoard[1][1][0] + actualBoard[2][2][0]) == 3)
			{

				if (actualBoard[0][0][0] == 1)
				{
					playerCount++;
				}
				else
				{
					computerCount++;
				}
			}
			if (abs(actualBoard[0][0][1] + actualBoard[1][1][1] + actualBoard[2][2][1]) == 3)
			{

				if (actualBoard[0][0][1] == 1)
				{
					playerCount++;
				}
				else
				{
					computerCount++;
				}
			}
			if (abs(actualBoard[0][0][2] + actualBoard[1][1][2] + actualBoard[2][2][2]) == 3)
			{

				if (actualBoard[0][0][2] == 1)
				{
					playerCount++;
				}
				else
				{
					computerCount++;
				}
			}
			if (abs(actualBoard[0][2][0] + actualBoard[1][1][0] + actualBoard[2][0][0]) == 3)
			{

				if (actualBoard[0][2][0] == 1)
				{
					playerCount++;
				}
				else
				{
					computerCount++;
				}
			}
			if (abs(actualBoard[0][2][1] + actualBoard[1][1][1] + actualBoard[2][0][1]) == 3)
			{

				if (actualBoard[0][2][1] == 1)
				{
					playerCount++;
				}
				else
				{
					computerCount++;
				}
			}
			if (abs(actualBoard[0][2][2] + actualBoard[1][1][2] + actualBoard[2][0][2]) == 3)
			{

				if (actualBoard[0][2][2] == 1)
				{
					playerCount++;
				}
				else
				{
					computerCount++;
				}
			}
			if (abs(actualBoard[0][0][0] + actualBoard[1][0][1] + actualBoard[2][0][2]) == 3)
			{

				if (actualBoard[0][0][0] == 1)
				{
					playerCount++;
				}
				else
				{
					computerCount++;
				}
			}
			if (abs(actualBoard[0][1][0] + actualBoard[1][1][1] + actualBoard[2][1][2]) == 3)
			{

				if (actualBoard[0][1][0] == 1)
				{
					playerCount++;
				}
				else
				{
					computerCount++;
				}
			}
			if (abs(actualBoard[0][2][0] + actualBoard[1][2][1] + actualBoard[2][2][2]) == 3)
			{

				if (actualBoard[0][2][0] == 1)
				{
					playerCount++;
				}
				else
				{
					computerCount++;
				}
			}
			if (abs(actualBoard[0][0][2] + actualBoard[1][0][1] + actualBoard[2][0][0]) == 3)
			{

				if (actualBoard[0][0][2] == 1)
				{
					playerCount++;
				}
				else
				{
					computerCount++;
				}
			}
			if (abs(actualBoard[0][1][2] + actualBoard[1][1][1] + actualBoard[2][1][0]) == 3)
			{

				if (actualBoard[0][1][2] == 1)
				{
					playerCount++;
				}
				else
				{
					computerCount++;
				}
			}
			if (abs(actualBoard[0][2][2] + actualBoard[1][2][1] + actualBoard[2][2][0]) == 3)
			{

				if (actualBoard[0][2][2] == 1)
				{
					playerCount++;
				}
				else
				{
					computerCount++;
				}
			}

			//4 diagonals from corner to corner:

			if (abs(actualBoard[0][0][0] + actualBoard[1][1][1] + actualBoard[2][2][2]) == 3)
			{

				if (actualBoard[0][0][0] == 1)
				{
					playerCount++;
				}
				else
				{
					computerCount++;
				}
			}
			if (abs(actualBoard[0][0][2] + actualBoard[1][1][1] + actualBoard[2][2][0]) == 3)
			{

				if (actualBoard[0][0][2] == 1)
				{
					playerCount++;
				}
				else
				{
					computerCount++;
				}
			}
			if (abs(actualBoard[0][2][0] + actualBoard[1][1][1] + actualBoard[2][0][2]) == 3)
			{

				if (actualBoard[0][2][0] == 1)
				{
					playerCount++;
				}
				else
				{
					computerCount++;
				}
			}
			if (abs(actualBoard[0][2][2] + actualBoard[1][1][1] + actualBoard[2][0][0]) == 3)
			{

				if (actualBoard[0][2][2] == 1)
				{
					playerCount++;
				}
				else
				{
					computerCount++;
				}
			}


			if (playerCount > computerCount) {
				return srikur;
			}
			else if (computerCount > playerCount) {
				return sidharth;
			}
			else {
				return -1;
			}
		}

	};

}

int srikurReturn, sidReturn;
int sidharthGames = 0, srikurGames = 0;

class Competition : Srikur::ThreeDBoard, Sidharth::TicTacToeBoard3D {
public:

	const int NUM_GAMES = 10;
	bool turn = srikur;
	int games;

	void playGame() {
		setMove(0);
		printf("This program will play 10 games of 3D Tic-Tac-Toe between Srikur Kanuparthy and Sidharth Sundar\n");
		srand(time(NULL));
		int first = rand() % 2;
		if (first) {
			//Sidharth moves first since the value is zero
			printf("Sidharth moves first\n\n");
			turn = sidharth;
		}
		else {
			printf("Srikur moves first\n\n");
		}

		while (games <= 10) {
			while (true) {
				if (turn == srikur) {
					Srikur::ThreeDBoard::printCompetitionBoard();
					srikurReturn = Srikur::ThreeDBoard::computerMove();
					convertSrikurToSidharth(srikurReturn);
				}
				if (turn == sidharth) {
					Sidharth::TicTacToeBoard3D::printBoard();
					sidReturn = Sidharth::TicTacToeBoard3D::computerMove();
					convertSidharthToSrikur(sidReturn);
				}

				// Check end using both the boards
				int winner = 3;
				if (Sidharth::TicTacToeBoard3D::getMoveCount() == 27) {
					winner = Sidharth::TicTacToeBoard3D::gameComplete();
				}
				if (winner == srikur) {
					srikurGames++;
					break;
				}
				else if (winner == sidharth) {
					sidharthGames++;
					break;
				}

				turn = !turn;
			}
			games++;
			turn = rand() % 2;
			Sidharth::TicTacToeBoard3D::setBoard();
			Srikur::setupBoard();
		}
	}

	void convertSrikurToSidharth(int value) {
		value--;
		int y = value % 3;
		value -= y;
		value /= 3;
		int x = value % 3;
		value -= x;
		int boardNumber = value / 3;
		playerMove(boardNumber + 1, x, y);
	}

	inline void convertSidharthToSrikur(int value) {
		Srikur::competitionBoard.fillSlot(&Srikur::competitionBoard.spaces[value - 1], 2);
	}

};

int main() {
	Competition competition = Competition();
	competition.playGame();

	if (sidharthGames > srikurGames) {
		printf("Sidharth's CPU wins overall by a score of %d to %d\n\n", sidharthGames, srikurGames);
	}
	else if (srikurGames > sidharthGames) {
		printf("Srikur's CPU wins overall by a score of %d to %d\n\n", srikurGames, sidharthGames);
	}
	else if (srikurGames == sidharthGames) {
		printf("It was a tie!\n\n");
	}
}