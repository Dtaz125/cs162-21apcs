#include<iostream>
#include<stdlib.h>

using namespace std;

int main()
{
	int choose, bre = 0;
	string user, pass;
	while (bre != 1)
	{
		cout << "PLEASE LOG IN!" << endl;
		cout << "Username: " << endl;
		cin >> user;
		cout << "Password: " << endl;
		cin >> pass;
		//check user
		system("cls");
		while (bre != 1)
		{
			cout << " Choose " << endl;
			cout << " 1 " << endl;
			cout << " 2 " << endl;
			cout << " 3 " << endl;
			cout << " 4 " << endl;
			cout << " 5 " << endl;
			cout << " 6 " << endl;
			cout << " 7 " << endl;
			cout << " 8 " << endl;
			cout << " 9 " << endl;
			cout << "Input your choose: ";
			cin >> choose;
			switch (choose) {
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				break;
			case 7:
				break;
			case 8:
				break;
			case 9:
				break;
			default:
				/*
				If x is not equal to one of the values above
				the code in this block will be executed
				*/
				break;
			}
		}
	}
	cout << flush;
}