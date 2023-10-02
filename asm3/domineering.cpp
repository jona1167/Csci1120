/*
Name: Ng Ka Wah
Student ID: 1155162668
E-mail: 1155162668@link.cuhk.edu.hk
*/


#include <iostream>
using namespace std;

int gridState(long long , int );
void printGrid(long long );
bool isPlaceable(long long , int , int );
void putToGrid(long long& , int , int );

int gridState(long long grid, int pos) {
	long long num = 1,check;//num is to find the position then check is to check the position value
	while (pos != 0) {//use a while loop to find the position
		num *= 10;
		pos--;
	}
	check = grid / (10000000000000000 / num) % 10;
	return (int)check;//since it is a int function so add (int)
}
void printGrid(long long grid) {
	long long check;//check is to check the position value
	int j=0;

	for (int i = 1; i <= 16; i++) {
		long long num = 1;
		j = i;//using j to store the i for below while loop to find the position
			while (j != 0) {			
				num *= 10;				
				j--;
			}			
		check = grid / (10000000000000000/num)%10;//check is to check the position value
		if (check == 1)//use if else if else to find 0 1 2
			printf("A");
		else if (check == 2)
			printf("B");
		else 
			printf(".");

		if (i == 4 || i == 8 || i == 12 || i == 16)//use if else to format
			printf("\n");
		else
			printf(" ");

	}
}
bool isPlaceable(long long grid, int pos, int p) {

	if (pos < 1 || pos>16)//check valid pos
		return false;
	else if(p!=1&&p!=2)//check valid player
		return false;
	else if (p==1) {
		if (pos + 4 > 16)//check valid player 1 position
			return false;
		else if (gridState(grid, pos) != 0 || gridState(grid, pos + 4) != 0)
			return false;
		else 
			return true;
	}
	else if (p == 2) {
		if (pos + 1 ==5|| pos + 1 == 9 || pos + 1 == 13 || pos + 1 == 17)//check valid player 2 position
			return false;
		else if (gridState(grid, pos) != 0 || gridState(grid, pos + 1) != 0)
			return false;
		else
			return true;
	}
	else 
		return true;

}
void putToGrid(long long& grid, int pos, int p) {
	long long num = 1;//num is to find the position then check is to check the position value
	long long num2 = 1;//num is to find the position then check is to check the position value
	int loop = 16 - pos;
	while (loop != 0) {//use a while loop to find the position
		num *= 10;
		loop--;
	}

	if (p == 1) {
		loop = 16 - (pos + 4);
		while (loop != 0) {//use a while loop to find the position
			num2 *= 10;
			loop--;
		}
	}
	else if (p == 2) {
		loop = 16 - (pos + 1);
		while (loop != 0) {//use a while loop to find the position
			num2 *= 10;
			loop--;
		}
	}
	grid += num * p + num2*p;
}


int main()
{
	long long grid = 0;
	int pos,count=0;
	bool win = false;
	while (win == false) {//loping until win
		
		printGrid(grid);
		

		count = 0;
		for (int i = 1; i <= 16; i++) {//check player 2 win
			if (isPlaceable(grid, i, 1) == true) {
				count++;
			}
		}
		if (count == 0) {
			cout << "Player 2 wins!";
			win = true;
			break;//break the loop
		}


		do{
		cout << "Player 1's move: ";//player 1 input
		cin >> pos;
		if (isPlaceable(grid, pos, 1) == false) {
			cout << "Invalid! Try again.\n";
		}
		} while (isPlaceable(grid, pos, 1) == false);



		putToGrid(grid, pos, 1);
		printGrid(grid);
		count = 0;
		for (int i = 1; i <= 16; i++) {
			if (isPlaceable(grid, i, 2) == true) {
				count++;
			}
		}//check player 1 win
		if (count == 0) {
			cout << "Player 1 wins!";
			win = true;
			break;//break the loop
		}

		do {
			cout << "Player 2's move: ";//player 2 input
			cin >> pos;
			if (isPlaceable(grid, pos, 2) == false) {
				cout << "Invalid! Try again.\n";
			}
		} while (isPlaceable(grid, pos, 2) == false);
		putToGrid(grid, pos, 2);
		

	}
	
	return 0;

}