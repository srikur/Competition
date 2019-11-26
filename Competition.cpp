/*
	Lab 10 CECS 130

	Description: This program is a 3D Tic Tac Toe Board

	Kanuparthy Srikur, Section 01, 11/1/19, First Semester 2019-2020 School Year
*/

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
				character = "X";
			}
			else {
				character = "O";
			}

			move->value = character;
		}

		~Board() {}

		bool checkEnd();
		void printBoard();
		void checkWinner();

		void computerMove();
	};

	class ThreeDBoard : public Board {
	public:
		Slot spaces[27];

		~ThreeDBoard() {}

	};

	ThreeDBoard board;
	int playerMove, computerMove, playerWins, computerWins;

	int main() {

		Slot* computerPoint, * playerPoint;

		//creating all of the space objects and assigning their character value
		srand(time(NULL));
		board.spaces[0].value = "1";
		board.spaces[1].value = "2";
		board.spaces[2].value = "3";
		board.spaces[3].value = "4";
		board.spaces[4].value = "5";
		board.spaces[5].value = "6";
		board.spaces[6].value = "7";
		board.spaces[7].value = "8";
		board.spaces[8].value = "9";
		board.spaces[9].value = "10";
		board.spaces[10].value = "11";
		board.spaces[11].value = "12";
		board.spaces[12].value = "13";
		board.spaces[13].value = "14";
		board.spaces[14].value = "15";
		board.spaces[15].value = "16";
		board.spaces[16].value = "17";
		board.spaces[17].value = "18";
		board.spaces[18].value = "19";
		board.spaces[19].value = "20";
		board.spaces[20].value = "21";
		board.spaces[21].value = "22";
		board.spaces[22].value = "23";
		board.spaces[23].value = "24";
		board.spaces[24].value = "25";
		board.spaces[25].value = "26";
		board.spaces[26].value = "27";
		playerWins = 0;
		computerWins = 0;

		bool goesFirst = rand() % 2;

		cout << "Let's play 3D Tic Taco Toe!";
		board.printBoard();

		if (goesFirst == 0) {
			cout << "Computer goes first!" << endl;
			do {
				computerMove = (rand() % 27) + 1;
			} while (!board.avaliable(board.spaces[computerMove - 1]));

			computerPoint = &board.spaces[computerMove - 1];
			cout << "\nThe computer chose space " << computerMove << "\n";
			board.fillSlot(computerPoint, 2);

			board.printBoard();

		}
		else {
			cout << "You go first!";
		}
		//loop to continue playing the game
		while (!board.checkEnd()) {

			//loop to continue asking the player to choose a move if they pick an invalid option

			do {
				cout << "\nWhich space do you choose? ";
				cin >> playerMove;
			} while (!board.avaliable(board.spaces[playerMove - 1]));

			//fill in the players move, reprint the board, and check for a winner
			playerPoint = &board.spaces[playerMove - 1];
			board.fillSlot(playerPoint, 1);

			board.printBoard();

			if (board.checkEnd() == true) {
				break;
			}
			//Loop to have the computer pick a random space until choosing one that is available
			do {
				computerMove = (rand() % 27) + 1;
			} while (!board.avaliable(board.spaces[computerMove - 1]));

			cout << "\nThe computer chose space " << computerMove << "\n";
			computerPoint = &board.spaces[computerMove - 1];
			board.fillSlot(computerPoint, 2);


			board.printBoard();

		}

		board.checkWinner();

		cout << "The computer won this many times: " << computerWins << endl;
		cout << "You won this many times: " << playerWins << endl;

		if (computerWins > playerWins) {
			cout << "You lose.";
		}
		else {
			cout << "You win!";
		}

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
	void Board::checkWinner() {

		//Checks horizontal for each vertical panes
		for (int j = 0; j < 19; j += 9) {
			for (int i = 0; i < 7; i += 3) {
				if (board.spaces[i + j].value == (board.spaces[i + 1 + j].value) && board.spaces[i + j].value == (board.spaces[i + 2 + j].value)) {
					if (board.spaces[i + j].value == ("X")) {
						playerWins++;
					}
					else {
						computerWins++;
					}
				}
			}
		}
		//Checks right diagonal for each vertical pane
		for (int i = 0; i < 19; i += 9) {
			if (board.spaces[i].value == (board.spaces[i + 4].value) && board.spaces[i].value == (board.spaces[i + 8].value)) {
				if (board.spaces[i].value == ("X")) {
					playerWins++;
				}
				else {
					computerWins++;
				}
			}
		}

		//checks right diagonal for each horizontal pane
		for (int i = 0; i < 7; i += 3) {
			if (board.spaces[i].value == (board.spaces[i + 10].value) && board.spaces[i].value == (board.spaces[i + 20].value)) {
				if (board.spaces[i].value == ("X")) {
					playerWins++;
				}
				else {
					computerWins++;
				}
			}
		}

		//checks left diagonal for each horizontal pane
		for (int i = 2; i < 9; i += 3) {
			if (board.spaces[i].value == (board.spaces[i + 8].value) && board.spaces[i].value == (board.spaces[i + 16].value)) {
				if (board.spaces[i].value == ("X")) {
					playerWins++;
				}
				else {
					computerWins++;

				}
			}
		}


		//Checks left diagonal for each vertical pane
		for (int i = 2; i < 21; i += 9) {
			if (board.spaces[i].value == (board.spaces[i + 2].value) && board.spaces[i].value == (board.spaces[i + 4].value)) {
				if (board.spaces[i].value == ("X")) {
					playerWins++;
				}
				else {
					computerWins++;
				}
			}
		}
		//Checks vertical for each vertical pane
		for (int j = 0; j < 19; j += 9) {
			for (int i = 0; i < 3; i++) {
				if (board.spaces[i + j].value == (board.spaces[i + 3 + j].value) && board.spaces[i + j].value == (board.spaces[i + 6 + j].value)) {
					if (board.spaces[i + j].value == ("X")) {
						playerWins++;
					}
					else {
						computerWins++;
					}
				}
			}
		}
		//checks vertical for each horizontal pane 
		for (int j = 0; j < 7; j += 3) {
			for (int i = 0; i < 3; i++) {
				if (board.spaces[i + j].value == (board.spaces[i + 9 + j].value) && board.spaces[i + j].value == (board.spaces[i + 18 + j].value)) {
					if (board.spaces[i + j].value == ("X")) {
						playerWins++;
					}
					else {
						computerWins++;
					}
				}
			}
		}

		//check four diagonals that go through the center
		if (board.spaces[0].value == (board.spaces[13].value) && board.spaces[0].value == (board.spaces[26].value)) {
			if (board.spaces[0].value == ("X")) {
				playerWins++;
			}
			else {
				computerWins++;
			}
		}

		if (board.spaces[3].value == (board.spaces[13].value) && board.spaces[3].value == (board.spaces[24].value)) {
			if (board.spaces[3].value == ("X")) {
				playerWins++;
			}
			else {
				computerWins++;
			}
		}

		if (board.spaces[20].value == (board.spaces[13].value) && board.spaces[20].value == (board.spaces[6].value)) {
			if (board.spaces[20].value == ("X")) {
				playerWins++;
			}
			else {
				computerWins++;
			}
		}

		if (board.spaces[18].value == (board.spaces[13].value) && board.spaces[18].value == (board.spaces[8].value)) {
			if (board.spaces[18].value == ("X")) {
				playerWins++;
			}
			else {
				computerWins++;
			}
		}
	}

	Slot* compPoint, * playPoint;
	int compMove, playMove;

	void Board::computerMove() {

		srand(time(NULL));

		do {
			compMove = (rand() % 27) + 1;
		} while (!board.avaliable(board.spaces[compMove - 1]));

		compPoint = &board.spaces[compMove - 1];
		cout << "\nThe computer chose space " << compMove << "\n";
		board.fillSlot(compPoint, 2);

		board.printBoard();
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

class Competition : Srikur::ThreeDBoard : Sidharth::