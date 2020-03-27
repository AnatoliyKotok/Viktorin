#include<iostream>
#include "Viktorin.h"
using namespace std;

int main() {
	init();
	int a;
	do {
		cout << "1.Add viktorin" << endl;
		cout << "2.Pass the viktorin" << endl;
		cout << "3.Exit" << endl;
		cout << "Selekt action->";
		cin >> a;
		system("cls");
		switch (a)
		{
		case 1:
			addviktorin();
			system("cls");
			break;
		case 2:
			
			play();
			break;
		case 3:
			cout << "Bye" << endl;
			break;
		}
	} while (a != 3);
	
	
	return 0;
}