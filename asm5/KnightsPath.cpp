//Ng Ka Wah
//1155162668
//1155162668@link.cuhk.edu.hk
#include <iostream>
#include "KnightsPath.h"
using namespace std;

KnightsPath::KnightsPath(int r, int c) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			board[i][j] = -1;
		}
	}
	currentR = r;
	currentC = c;
	board[r][c] = 0;
	steps = 0;
	previousR = -1;
	previousC = -1;

	



}
void KnightsPath::print() const{//0=k 
	
	for (int i = 0; i < N+1; i++) {//N+1 for cout the ABCD...
		if (i == 0)
			cout << " ";
		else if (i > 0)
			cout << i - 1;

		for (int j = 0; j < N ; j++) {
			 if (i == 0)
				cout << "  " << char(j + 65);
			 else {
				 cout << "  ";
				 if (board[i - 1][j] == -1)
					 cout << '.';
				 else if (board[i - 1][j] == 0)
					 cout << 'k';
				 else if(board[i - 1][j] == steps)
					 cout << 'K';
				 else 
					 cout << board[i - 1][j];
			 }
				
		}
		cout << endl;
		
	}
}
int KnightsPath::getSteps() const{
	return steps;
}
bool KnightsPath::isValid(int r, int c) const{
	int k;//for checing the eight direction
	int rnext, cnext,count=0;
	if (!(r >= 0 && r < N && c >= 0 && c < N && board[r][c] == -1))//out of range or travel before
		return false;
	if (previousC == -1 && previousR == -1)//for first round
		return true;
	int rMove[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
	int cMove[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
	//backward
	long int temp,m1=0,m2=0, min1=999, min2=999;//min1 and min2 need to set a number larger than sqrt20 is ok as the larger distance is sqrt20
	for (k = 0; k < 8; k++) {
		rnext = currentR + rMove[k];
		cnext = currentC + cMove[k];
		temp = (previousR - rnext) * (previousR - rnext) + (previousC - cnext) * (previousC - cnext);
		
		if ((temp<min2)&&temp!=0) {//miin1 is the smallest
			if (temp < min1) {
				min2 = min1;
				m2 = m1;
				min1 = temp;
				m1 = k;
				
			}
			else {
				min2 = temp;
				m2 = k;
			}
		}
	
	}
	
	
	

	for (k = 0; k < 8; k++) {//check if it is valid to put in the eight direction
		rnext = currentR + rMove[k];
		cnext = currentC + cMove[k];

		

		if (k != m1 && k!=m2) {//except the two shortest distance
			if (r == rnext && c == cnext)
				count++;
		}
	
	}
	
	if (count > 0)
		return true;
	else
		return false;
}
bool KnightsPath::hasMoreMoves() const{//check has more moves or not
	int rnext, cnext,count=0;
	int rMove[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
	int cMove[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
	for (int k = 0; k < 8; k++) {
		rnext = currentR + rMove[k];
		cnext = currentC + cMove[k];
		

		if (isValid(rnext, cnext)) {
			if (board[rnext][cnext] == -1)
				count++;
		}

	}

	if (count > 0)
		return true;
	else
		return false;
	
}
bool KnightsPath::move(int r, int c){//move
	if (isValid(r, c)) {
		steps++;
		board[r][c] = steps;
		previousR = currentR;
		previousC = currentC;
		currentR = r;
		currentC = c;
		
	}

	else
		return false;
}