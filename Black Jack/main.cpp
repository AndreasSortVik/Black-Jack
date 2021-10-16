#include "declear.h"

int main() {
	std::srand(std::time(nullptr));
	login();

	while (true) {
		resetVariables();
		playerDrawCard();

		while (true) {
			checkWin();

			std::cout << std::endl << "Do you want to play again? (y/n)" << std::endl;
			char answer;
			std::cin >> answer;
			clearcin();
			answer = tolower(answer);

			if (answer == 'y') {
				system("cls");
				resetVariables();
				break;
			}
			else if (answer == 'n') {
				exit(0);
			}
			else {
				std::cout << "Please enter a valid input. Try again." << std::endl;
				system("cls");
				continue;
			}
		}
	}
}

void login() {
	tryAgain = 3;

	while (true) {
		std::cout << "Enter username: "; //Username is 'Wohall'
		std::cin >> username;
		std::cout << "Enter password: "; //Password is 'Pass'
		std::cin >> password;

		if (username == "Wohall") {
			checkUsername = true;
		}

		if (password == "Pass") {
			checkPassword = true;
		}

		if (checkUsername == true && checkPassword == true) {
			std::cout << "Username and password is correct. Logging in";
			Sleep(500);
			std::cout << ".";
			Sleep(500);
			std::cout << ".";
			Sleep(500);
			std::cout << "." << std::endl;
			system("cls");
			break;
		}

		if (tryAgain > 0) {
			if (tryAgain == 1) {
				std::cout << "Username or password is incorrect. You used up to many tries." << std::endl
					<< "Closing program." << std::endl;
				exit(0);
			}
			if (username != "Wohall" || password != "PassInCode") {
				system("cls");
				tryAgain--;
				std::cout << "Username or password is incorrect, please try again. ("
					<< tryAgain << " tries left)" << std::endl;
			}
		}
	}

	return;
}

void playerDrawCard() {
	while (true) {

		//
		while (true) {
			std::cout << "Your capital is $" << playerMoney << "." << std::endl
				<< "How much would you like to bet? (minimum starting bet is $5): ";
			std::cin >> playerBet;
			clearcin();

			if (playerBet >= 5 && playerBet <= playerMoney) {
				system("cls");
				std::cout << "Your starting bet is $" << playerBet << "." << std::endl;
				playerMoney = playerMoney - playerBet;
				std::cout << "You currently have $" << playerMoney << std::endl;
				break;
			}
			else if (playerBet < 5) {
				system("cls");
				std::cout << "Your minimum starting bet is $5. Please try again." << std::endl;
				continue;
			}
			else if (playerBet > playerMoney) {
				system("cls");
				std::cout << "You cannot bet more money than your capital. Please try again." << std::endl;
				continue;
			}
		}

		std::cout << "Type 'hit' to draw a card." << std::endl;
		std::cin >> playerAnswer;
		clearcin();

		if (playerAnswer == "hit") {
			system("cls");
			firstCard = rand() % 13 + 1;

			//Adds the possibility to get a knight, a queen and a knight
			if (firstCard <= 10) {
				std::cout << "You drew a card, you drew " << firstCard << "." << std::endl;
			}
			else if (firstCard == 11) {
				firstCard = 10;
				std::cout << "You drew a card, you drew a knight." << std::endl;
			}
			else if (firstCard == 12) {
				firstCard = 10;
				std::cout << "You drew a card, you drew a queen." << std::endl;
			}
			else if (firstCard == 13) {
				firstCard = 10;
				std::cout << "You drew a card, you drew a king." << std::endl;
			}

			//Gives the option to change the first card to 11, if it draws 1
			if (firstCard == 1) {
				while (true) {
					std::cout << "Do you want to change the card to 11? (y/n): ";
					std::cin >> playerAnswer;
					clearcin();

					if (playerAnswer == "y") {
						system("cls");
						std::cout << "The card has been changed to 11" << std::endl;
						firstCard = 11;
						break;
					}
					else if (playerAnswer == "n") {
						system("cls");
						std::cout << "The card stays as 1" << std::endl;
						break;
					}
					else {
						std::cout << "Invalid input. Please try again" << std::endl;
						system("cls");
						continue;
					}
				}
			}

			std::cout << "You currently have " << firstCard << " points." << std::endl;
			break;
		}
		else {
			system("cls");
			std::cout << "You need to type exactly 'hit'. Please try again." << std::endl;
		}
	}

	while (true) {
		std::cout << "Type 'hit' to draw a card, or type 'stand' to stand." << std::endl;
		std::cin >> playerAnswer;
		clearcin();

		if (playerAnswer == "hit") {
			system("cls");
			card = rand() % 13 + 1;

			//Adds the possibility to get a knight, a queen and a knight
			if (card <= 10) {
				std::cout << "You drew a card, you drew " << card << "." << std::endl;
			}
			else if (card == 11) {
				card = 10;
				std::cout << "You drew a card, you drew a knight." << std::endl;
			}
			else if (card == 12) {
				card = 10;
				std::cout << "You drew a card, you drew a queen." << std::endl;
			}
			else if (card == 13) {
				card = 10;
				std::cout << "You drew a card, you drew a king." << std::endl;
			}
			
			//Gives the option to change the card to 11, if it draws 1
			if (card == 1) {
				while (true) {
					std::cout << "Do you want to change the card to 11? (y/n): ";
					std::cin >> playerAnswer;
					clearcin();

					if (playerAnswer == "y") {
						system("cls");
						std::cout << "The card has been changed to 11" << std::endl;
						card = 11;
						break;
					}
					else if (playerAnswer == "n") {
						system("cls");
						std::cout << "The card stays as 1" << std::endl;
						break;
					}
					else {
						std::cout << "Invalid input. Please try again" << std::endl;
						system("cls");
						continue;
					}
				}
			}

			newPoint = card;
			points = newPoint += firstCard;
			firstCard = newPoint;
			std::cout << "You currently have " << points << " points." << std::endl;

			if (points > 21) {
				houseMoney = houseMoney + houseBet + playerBet;
				std::cout << "You went above 21. House wins." << std::endl;
				std::wcout << "You currently have $" << playerMoney << std::endl;
				return;
			}
		}
		else if (playerAnswer == "stand") {
			system("cls");
			if (points == 0) {
				std::cout << "You stand. You currently have " << firstCard << " points." << std::endl;
				points = firstCard;
			}
			else {
				std::cout << "You stand. You currently have " << points << " points." << std::endl;
			}
			break;
		}
		else {
			system("cls");
			std::cout << "You need to type exactly 'hit' or 'stand'. Please try again." << std::endl;
			std::cout << "You currently have " << points << " points." << std::endl;
			std::cout << "House currently has $" << houseMoney << "." << std::endl;
		}
	}
	houseDrawCard();

	return;
}

void houseDrawCard() {
	int houseFirstCard = 0;
	int houseCard = 0;
	int houseNewPoint = 0;
	int housePoints = 0;
	int houseBet = 0;

	houseBet = playerBet;
	houseMoney = houseMoney - houseBet;
	std::cout << "House bet $" << houseBet << "." << std::endl;
	std::cout << "House currently has $" << houseMoney << "." << std::endl;

	houseFirstCard = rand() % 13 + 1;

	if (houseFirstCard == 1) {
		houseFirstCard = 11;
	}
	//Adds the possibility to get a knight, a queen and a knight
	else if (houseFirstCard == 11) {
		houseFirstCard = 10;
	}
	else if (houseFirstCard == 12) {
		houseFirstCard = 10;
	}
	else if (houseFirstCard == 13) {
		houseFirstCard = 10;
	}

	while (true) {
		houseCard = rand() % 10 + 1;

		//House chooses the best number (either 1 or 11) according to logic
		if (houseCard == 1) {
			if (housePoints <= 10) {
				houseCard = 11;
			}
			else if (housePoints > 10) {
				houseCard = 1;
			}
		}

		//Adds the possibility to get a knight, a queen and a knight
		else if (houseCard == 11) {
			houseCard = 10;
		}
		else if (houseCard == 12) {
			houseCard = 10;
		}
		else if (houseCard == 13) {
			houseCard = 10;
		}

		houseNewPoint = houseCard;
		housePoints = houseNewPoint += houseFirstCard;
		houseFirstCard = houseNewPoint;

		/*Ensures that house keeps picking cards as long as their cards are under players card amount,
		under 21 and equal or over 17*/
		if (housePoints < 17) {
			continue;
		}
		else if (housePoints >= points) {
			break;
		}
		else if (housePoints >= 21) {
			break;
		}
	}

	if (housePoints > points && housePoints <= 21) {
		houseMoney = houseMoney + houseBet + playerBet;
		std::cout << "House drew it's cards and got " << housePoints << " points. House wins." << std::endl;
		std::cout << "You currently have $" << playerMoney << "." << std::endl;
		std::cout << "House currently has $" << houseMoney << "." << std::endl;
	}
	else if (housePoints == points) {
		houseMoney = houseMoney + houseBet + playerBet;
		std::cout << "House drew it's cards and got " << housePoints << " points. House wins." << std::endl;
		std::cout << "You currently have $" << playerMoney << "." << std::endl;
		std::cout << "House currently has $" << houseMoney << "." << std::endl;
	}
	else if (housePoints > 21) {
		playerMoney = playerMoney + playerBet + houseBet;
		std::cout << "House drew it's cards and got " << housePoints << " points. You win." << std::endl;
		std::cout << "You currently have $" << playerMoney << "." << std::endl;
		std::cout << "House currently has $" << houseMoney << "." << std::endl;
	}

	return;
}

void checkWin() {
	if (playerMoney < 5) {
		std::cout << "You can't bet anymore, you lost the match." << std::endl;
		exit(0);
	}
	if (houseMoney < 5) {
		std::cout << "House can't bet anymore, you won the match!" << std::endl;
		exit(0);
	}

	return;
}

//Resets the variables so the game can start over
void resetVariables() {
	int firstCard = 0;
	int card = 0;
	int newPoint = 0;
	int points = 0;
	int playerBet = 0;
	int houseFirstCard = 0;
	int houseCard = 0;
	int houseNewPoint = 0;
	int housePoints = 0;
	int houseBet = 0;

	return;
}

void clearcin() {
	std::cin.clear();
	std::cin.ignore(32767, '\n');
}