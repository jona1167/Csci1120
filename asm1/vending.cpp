
#include <iostream>
using namespace std;

/*
Name: Ng Ka Wah
Student ID: 1155162668
E-mail: 1155162668@link.cuhk.edu.hk
*/


int main()
{
    
    int dollar[6],com[6];//com is for saving the combination
    int insert, item, charge, answer;
    cout << "Enter six decreasing denominations: ";
    for (int i = 0; i < 6; ++i) {
        cin >> dollar[i];
    }
    cout << "\nInsert money ($): ";
    cin >> insert;
    cout << "\nItem price ($): ";
    cin >> item;
    charge = insert - item;
    cout << "\nChange is $"<< charge <<endl;
    answer = charge;   
    for (int i = 0; i < 6; i++) {
        com[i] = answer / dollar[i];       
        answer = answer-(answer / dollar[i]* dollar[i]);
    }
    
    if (answer >= 1) {//finding the error case(Cannot find combination)
        cout << "Cannot find combination!";
    }
    else {
        for (int i = 0; i < 6; i++) {
            cout << "$" << dollar[i] << " x " << com[i] << endl;
        }
    }
    return 0;
}

