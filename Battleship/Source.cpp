#include <iostream>
#include <ctime>
#include <conio.h>
#include <Windows.h>

using namespace std;
#define I 6
void MakeEmptyBaord(char board[][I], const int, const int, bool );
int RandomRow();
int RandomColumn();
int WriteLetters(int);
void MakeBoard(int, char board[][I]);
void PrintBoard();
void printPlayerBoard();
void shoot();

void MakeEmptyBaord(char board[][I], const int M, const int N, bool flag) {
	if (flag == 0) {
		cout << " AI Board " << "\n";
	}
	else {
		cout << " Player Board " << "\n";
	}
	
	for (int i = 0; i < M; i++)
	{
		std::cout << i + 1 << "|";
		for (int j = 0; j < N; j++)
		{
			std::cout << board[i][j] << "|";
		}
		std::cout << "\n";
	}
	std::cout << " ";
	for (int k = 0; k < M; k++) {
		cout <<" "<< char(WriteLetters(k));
	}
	std::cout << "\n\n\n\n";
}

int RandomRow() {

	return rand()%6 +0;

}

int RandomColumn() {
	return rand() % 6 + 0;
}

void MakeBoard(int NumberOfShips, char board[][I]) {
	int Row = 0;
	int Col = 0;
	for (int i=0; i < NumberOfShips; i++){
		Row = RandomRow();
		Col = RandomColumn();
		if (board[Row][Col] == 'S' && i!=0) {
			i--;
		}
		else {
			board[Row][Col] = 'S';
		}
	}
	
}

void PrintBoard() {

}
void printPlayerBoard() {

}
void shoot() {
	// we are going to work on this part 
}
int WriteLetters(int K) {

	return K + 65;

	
}
	

int main() {
	srand(time(nullptr));
	const int M = 6;
	const int N = 6;
	char AIboard[M][N] = {};
	char PlayerBoard[M][N] = {};
	MakeBoard(6, AIboard);
	MakeEmptyBaord(AIboard, M,N, 0);
	MakeEmptyBaord(PlayerBoard, M, N,1);
	_getch();
	return 0;
}
