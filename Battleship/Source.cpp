#include <iostream>
#include <ctime>
#include <conio.h>
#include <Windows.h>


// we need to duplicate board 
// we check the empty board with the hidden board 

using namespace std;
#define I 7
void MakeEmptyBaord(char board[][I], const int, const int, bool );
int RandomRow();
int RandomColumn();
int WriteLetters(int);
void MakeBoard(int, char board[][I]);
void PrintBoard();
void printPlayerBoard();
void shoot();
class Points {
public:
	Points() {
		ROW = 0;
		COL = 0;
	}
	int ROW ;
	int COL;
}P_AI[6],P_PL[6];

void MakeEmptyBaord(char board[][I], const int M, const int N, bool flag) {
	if (flag == 0) {
		cout << " AI Board " << "\n";
	}
	else {
		cout << " Player Board " << "\n";
	}
	
	for (int i = 1; i < M; i++)
	{
		std::cout << i  << "|";
		for (int j = 1; j < N; j++)
		{
			std::cout << board[i][j] << "|";
		}
		std::cout << "\n";
	}
	std::cout << " ";
	for (int k = 1; k < M; k++) {
		cout <<" "<< char(WriteLetters(k));
	}
	std::cout << "\n\n\n\n";
}

int RandomRow() {

	return rand()% 6 + 1;

}

int RandomColumn() {
	return rand() % 6 + 1;
}

void MakeAIBoard(int NumberOfShips, char board[][I]) {
	int Row = 0;
	int Col = 0;
	for (int i=1; i < NumberOfShips; i++){
		Row = RandomRow();
		Col = RandomColumn();
		if (board[Row][Col] == 'S' && i!=0) {
			i--;
		}
		else {
			P_AI[i].ROW = Row;
			P_AI[i].COL = Col;
			board[Row][Col] = 'S';
		}

	}
	for (int i = 1; i < NumberOfShips; i++) {
		std::cout << P_AI[i].ROW << " ----  " << P_AI[i].COL << std::endl;
	}

	
}

void PrintBoard() {

}
void printPlayerBoard() {

}
void shoot(char AI_arr[][7]) {
	string shoot_in = " ";
	int num = 0;
	char ch = ' ';
	int ch2num = 0;
	std::cout << "where do you want to shoot ?  ";
	std::cin >> shoot_in;
	ch = shoot_in[0];
	num = shoot_in[1];
	
	switch (ch) {
	case  'A':case  'a':
		ch2num = 1;
		break;
	case  'B': case  'b':
		ch2num = 2;
		break;
	case  'C': case  'c':
		ch2num = 3;
		break;
	case  'D':case  'd':
		ch2num = 4;
		break;
	case  'E':case  'e':
		ch2num = 5;
		break;
	case  'F':case  'f':
		ch2num = 6;
		break;
	default :
		break;

	}



	//this part Doesnt work :D 

	std::cout << "Ok";
	num = int(num) - 48;
	bool flag1 = false;
	bool flag2 = false;
	std::cout << ch << " " << num << "\n";

	for (int j = 1; j < 7; j++) {
		if (P_AI[j].ROW == num) {
			flag1 = true;
			
		}else{
			flag1 = false;
		}
	}
	for (int i = 1; i < 7; i++) {
		 if(P_AI[i].COL == ch2num) {
			 flag2 = true;
			 
		}
		else {
			 flag2 = false;
			
		}
		 if (flag1 == true && flag2 == true) {
			 AI_arr[num][ch2num] = 'H';
		 }
		 else if (flag1 == false && flag2 == false) {
			 AI_arr[num][ch2num] = 'X';
		 } 
		
	}
	
	 std::cout << "Flag1 " << flag1 << "\n";
		 std::cout << "Flag2 " << flag2 << "\n";
	std::cout << "Ok X";



	// we are going to work on this part 
}
int WriteLetters(int K) {

	return K + 64;

	
}
	

int main() {
	srand(time(nullptr));
	const int M = 7;
	const int N = 7;
	char AIboard[M][N] = {};
	char AIboardCPY[M][N] = {};
	char PlayerBoard[M][N] = {};
	//MakeBoard(6, AIboard);
	MakeEmptyBaord(AIboard, M, N, 0);
	MakeEmptyBaord(PlayerBoard, M, N,1);
	MakeAIBoard(7, AIboard);
	while (true) {
		shoot(AIboard);
		MakeEmptyBaord(AIboard, M, N, 0);
	}
	_getch();
	return 0;
}
