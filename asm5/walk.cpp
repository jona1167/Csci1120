//Ng Ka Wah
//1155162668
//1155162668@link.cuhk.edu.hk
#include <iostream>
#include "KnightsPath.h"
using namespace std;

int main() {

	char col=0;
	int row=0;
	bool check=false;
	while (check==false) {
		cout << "Enter starting position (col row): ";
		cin  >> col >> row;
		if ((col > 64 && col < 91)&& col<65+ KnightsPath::N&& row>-1&& row < KnightsPath::N)
			check = true;
		else 
			cout << "Invalid. Try again!"<<endl;
	}
	
	KnightsPath path(row, col-65 );
	
	do {
		path.print();
		cout << "Steps: " << path.getSteps()<<endl;
		check = false;
		while (check == false) {
			cout << "Move the knight (col row): ";
			cin >> col >> row;

			

			if ((col > 64 && col < 91) && col<65 + KnightsPath::N && row>-1 && row < KnightsPath::N&&path.isValid(row, col - 65)==true) {
				path.move(row, col - 65);
				check = true;
			}
			else
				cout << "Invalid move. Try again!" << endl;
				
		}




	} while (path.hasMoreMoves());
	path.print();
	cout << "Steps: " << path.getSteps() << endl;
	cout << "Finished! No more moves!"  << endl;
	if(path.getSteps()+1> (KnightsPath::N* KnightsPath::N)/2)
		cout << "Well done!";
	else 
		cout << "Still drunk? Walk wiser!";
	return 0;
}