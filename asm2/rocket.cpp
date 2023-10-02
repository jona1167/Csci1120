/*
Name: Ng Ka Wah
Student ID: 1155162668
E-mail: 1155162668@link.cuhk.edu.hk
*/
#include <iostream>
#include <cmath>
using namespace std;



void head(int,int);
void body(int,int,int);
void tail(int,int,int);

void head(int he,int wi) {
    for (int i = 0; i < (2*he-1+wi*2+4)/2; i++)
    {
        cout << " ";
    }
    cout << "|"<<endl;
    for (int i = 0; i < he ; i++)
    {
        for (int j = 0; j < (2 * he - 1 + wi * 2 + 4) ; j++)
        {
            if (j <= wi)//print the space of the wing and the +
                cout << " ";
            else if (j < ((2 * he - 1) - (i * 2 + 1)) / 2 + wi + 1)//print the space before /
                cout << " ";
            else if (j < ((2 * he - 1) - (i * 2 + 1)) / 2 + wi+1+1)//printing the /
                cout << "/";
            else if (j < ((2 * he - 1) - (i * 2 + 1)) / 2 + wi+1 +1+ (i * 2 + 1))//print the star inside
                cout << "*";
            else
            {
                cout << "\\" ;//print the \ 
                break;
            }
        }
        cout << endl;
    }
    for (int i = 0; i < wi; i++)
        cout << " ";
    cout << "+";
    for (int i = 0; i < 2*he-1+2; i++)//print the +---+
    {
        cout << "-";
    }
    cout << "+" << endl;
}

void body(int he,int bo, int wi) {

    for (int i = 0; i < bo; i++)
    {
        for (int j = 0; j < (2 * he - 1 + wi * 2 + 4); j++)
        {

            if (j < wi && i < ceil(bo / 2))//print the space of the part that no wing 
                cout << " ";
            else if (j < wi && i >= ceil(bo / 2))//print the wings
                cout << "/";
            else if (j < wi + 1)//print the |
                cout << "|";
            else if (j < wi + 1 + 2 * he + 1)//print the dot
                cout << ".";
            else if (j < wi + 1 + 2 * he + 1 + 1)//print |
                cout << "|";
            else if (j < wi + 1 + 2 * he + 1 + 1 + 1 + wi&& i >= ceil(bo / 2)) //print the "\"
                cout << "\\";
            else
            {
                //berak the loop
                break;
            }
        }
        cout << endl;
    }
    for (int i = 0; i < wi; i++)
        cout << " ";
    cout << "+";
    for (int i = 0; i < 2*he-1+2; i++)//print the +---+
    {
        cout << "-";
    }
    cout << "+" << endl;
}

void tail(int he,int wi,int ta) {
    double cr =floor((2.0*ta-1)/2);
    double cv = ((2 * he - 1) + wi * 2 + 4);
    double ca = floor(cv/2.0) ;
    ca -= cr;
   
    
    for (int i = ta+1-ceil((double)ta/2.0); i <= ta; i++)
    {
        for (int j = 0; j < (2 * he -1 + wi * 2 + 4); j++)
        {
            if (j <   ta - i + ca)//print the space of the part that no wing 
                cout << " ";
            else if (j <   ta- i+ 1+2*(i-1)+ ca)//print the wings
                cout << "*";       
            else {
                break;
            }
        }
        cout << endl;
     
    }

    for (int i = ta; i >0; i--)
    {
        for (int j = 0; j < (2 * he - 1 + wi * 2 + 4); j++)
        {
            if (j < -i+ta+ ca)//print the space of the part that no wing 
                cout << " ";
            else if (j <  - i + ta+2*i-1+ ca)//print the wings
                cout << "*";
            else {
                break;
            }
        }
        cout << endl;
    }







}

int main()
{
    int h, b, w, t;
    do{
        cout << "Enter h, b, w, t: ";
        cin >> h >> b >> w >> t;
    } while(((2 * t - 1 )> (2 * h + 3)) || h<1 || b<2 || w<1 || t<2);
    head(h,w);
    body(h,b, w);
    tail(h,w,t);
    return 0;
}