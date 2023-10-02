/*
Name: Ng Ka Wah
Student ID: 1155162668
E-mail: 1155162668@link.cuhk.edu.hk
*/



#include <iostream>
using namespace std;

const int N = 6; // board size
const int P = 8; // number of pieces per player
const int L = 3; // number of pieces required to form a line

bool is_valid_move(char board[][N], char player, int y, int x);
int pieces_on_board(char board[][N], char player);
bool pieces_in_line(char board[][N], char player);
void move(char board[][N], char player, int y, int x);
void print(char board[][N]);



bool is_valid_move(char board[][N], char player, int y, int x) {//check the board is empty

	if (board[y][x] == '.')
		return true;
	else
		return false;

}

int pieces_on_board(char board[][N], char player) {//return number win if same num to player
	int count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == player)
				count++;
		}
	}
	return count;
}

bool pieces_in_line(char board[][N], char player) {//4 cases to win
	int h = 0,v = 0, rb = 0, lb = 0;
	for (int i = 0; i < N; i++) {
		
		for (int j = 0; j < N; j++) {
			h = 0, v = 0, rb = 0,lb = 0;
			for (int k = 0; k < L; k++) {
				if ((board[i][j + k] == player && j < N - 2)) {//case 1 horizonal
					h++;
					
					if (h == L)
					{
						
						return true;
						
					}

				}
				
				if ((board[i+k][j] == player && i < N - 2)) {//case 2 vertical
					v++;
					
					if (v == L)
					{
						
						return true;
					}
				}
				
				 if ((board[i + k][j+k] == player && j < N - 2 && i < N - 2)) {//case 3 right bottom
					rb++;
					
					if (rb == L)
					{
						
						return true;
					}
				}
				 
				if ((board[i + k][j - k] == player &&( i < N - 2 && j > 1))) {//case 4 left bottom
					lb++;
					if (lb == L)
					{
						
						return true;
					}
				}

				
			}


			
		}
	}
	
	 
		return false;
}

void move(char board[][N], char player, int y, int x) {//4 case 4 side
	board[y][x] = player;
	if (y - 1 >= 0 &&x-1>=0 ) {//left top
		if (board[y - 1][x - 1] != '.') {
			if (y - 2 < 0 || x - 2 < 0) {
				board[y - 1][x - 1] = '.';
			}
			
			else if (board[y - 2][x - 2] == '.') {
				if (y - 2 >= 0) {
					board[y - 2][x - 2] = board[y - 1][x - 1];
					board[y - 1][x - 1] = '.';
				}
			}
			
		}		
	}
	
	if (y - 1 >= 0 && x >= 0) {//middle top
		if (board[y - 1][x ] != '.') {
			if (board[y - 2][x] == '.') {
				if (y - 2 >= 0) {
					board[y - 2][x] = board[y - 1][x];
					board[y - 1][x ] = '.';
				}
			}
			else if (y - 2 < 0) {
				board[y - 1][x] = '.';
			}
		}
	}
	
	if (y - 1 >= 0 && x <N-1) {//right top
		if (board[y - 1][x+1] != '.') {
			if (y - 2 < 0 || x +2 >N -1) {
				board[y - 1][x + 1] = '.';
			}
			else if(x+2< N - 1){
			 if (board[y - 2][x+2] == '.') {
				if (y - 2 >= 0) {
					board[y - 2][x+2] = board[y - 1][x+1];
					board[y - 1][x+1] = '.';
				}
			}
			 }
		}
	}
	
	if (y >= 0 && x - 1 >= 0) {//left middle
		if (board[y][x - 1] != '.') {
			if (y < 0 || x - 2 < 0) {
				board[y][x - 1] = '.';
			}

			else if (board[y][x - 2] == '.') {

				board[y][x - 2] = board[y][x - 1];
				board[y][x - 1] = '.';

			}

		}
	}
	
	if (y >= 0 && x < N - 1) {//right middle
		if (board[y][x +1] != '.') {
			if (y  < 0 || x + 2 > N - 1) {
				board[y][x + 1] = '.';
			}
			else if (x + 2 < N - 1) {
				if (board[y][x + 2] == '.') {
					
						board[y][x + 2] = board[y ][x + 1];
						board[y][x + 1] = '.';
					
				}
			}

		}
	}
	
	if (y  <N-1 && x-1 >= 0) {//left bottom
		if (board[y + 1][x - 1] != '.') {
			
			if (y + 2 >N-1 || x - 2 < 0) {
				board[y + 1][x - 1] = '.';
			}

			else if (board[y + 2][x - 2] == '.') {
				
					board[y + 2][x - 2] = board[y + 1][x - 1];
					board[y + 1][x - 1] = '.';
				
			}

		}
	}
	
	if (y < N - 1) {//middle bottom
		if (board[y + 1][x] != '.') {

			if (y + 2 > N - 1 ) {
				board[y + 1][x] = '.';
			}

			else if (board[y + 2][x] == '.') {

				board[y + 2][x] = board[y + 1][x];
				board[y + 1][x] = '.';

			}

		}
	}

	if (y < N - 1 && x < N - 1) {//right bottom
		if (board[y + 1][x+1] != '.') {

			if (y + 2 > N - 1 || x + 2 > N - 1) {
				board[y + 1][x+1] = '.';
			}

			else if (board[y + 2][x+2] == '.') {

				board[y + 2][x+2] = board[y + 1][x+1];
				board[y + 1][x+1] = '.';

			}

		}
	}
	
}


void print(char board[][N]) {
	for (int i = 0; i <= N; i++) {
		
		for (int j = 0; j <= N; j++) {
			if (i == 0&&j==0) {
				cout << "  ";
			}
			else if(i==0)
				cout << " " << (char)(64+j);
			else if(j==0)
				cout <<" "<< i;
			else 
				cout << " "<<board[i-1][j-1];
			
		}				
		cout << "\n";
	}


}


int main()
{
	char board[N][N] = {};
	
	char x;//input
	int y;
	char px='X', po='O';
	
	for (int i = 0; i < N; i++) {	//set the array to.
		for (int j = 0; j < N; j++) {
			board[i][j] = '.';
		}

	}
	
	
	

	int count = 1,check=-1,vaild=-1;//count is count round
	while (check != 0) {
		cout << "Round "<<count<<":\n";//player x
		print(board);		
		while (vaild != 0) {//check vaild
			cout << "Player X's turn: ";
			cin >> x >> y;
			if (x >= 97&&x<=122)
				x -= 32;
			if ((y > 0 && y < 27) && (x >= 65 && x < 65 + N)) {
				if (is_valid_move(board, px, y-1, x - 64-1) == true) {
					vaild = 0;
				
				}
			}
				

			if (vaild != 0)
				cout << "Invalid move!\n";
		}
		vaild = -1;//reset
		count++;//add round
		move(board, px, y - 1, x - 64 - 1);

		

		
		if (pieces_in_line(board, px) == true && pieces_in_line(board, po) == true) {
			
			
			cout << "Game over:\n";
			print(board);
			cout << "Draw game!";
			check = 0;
			
			break;
		}
		

		else if (pieces_in_line(board, px) == true || pieces_on_board(board, px) == P) {
			
			cout << "Game over:\n";
			print(board);
			cout << "Player X wins!";
			check = 0;
			
			break;
		}
		
		else if (pieces_in_line(board, po) == true || pieces_on_board(board, po) == P) {
			
			cout << "Game over:\n";
			print(board);
			cout << "Player O wins!";
			check = 0;
			
			break;
		}
		
		cout << "Round " << count << ":\n";//player O
		print(board);
		while (vaild != 0) {//check vaild
			cout << "Player O's turn: ";
			cin >> x >> y;
			if (x >= 97 && x <= 122)
				x -= 32;
			if ((y > 0 && y < 27) && (x >= 65 && x < 65 + N)) {
				if (is_valid_move(board, po, y - 1, x - 64 - 1) == true) {
					vaild = 0;

				}
			}
				
			if (vaild != 0)
				cout << "Invalid move!\n";
		}
		vaild = -1;//reset
		count++;//add round

		move(board, po, y - 1, x - 64 - 1);
		
		if (pieces_in_line(board, px) == true && pieces_in_line(board, po) == true) {
			
			
			cout << "Game over:\n";
			print(board);
			cout << "Draw game!";
			check = 0;
			
			break;
		}
		else if (pieces_in_line(board, px) == true || pieces_on_board(board, px) == P) {
			
			cout << "Game over:\n";
			print(board);
			cout << "Player X wins!";
			check = 0;
			
			break;
		}
		else if (pieces_in_line(board, po) == true || pieces_on_board(board, po) == P) {
			
			cout << "Game over:\n";
			print(board);
			cout << "Player O wins!";
			check = 0;
			
			break;
		}
		
		
		
	}
	
	return 0;

}