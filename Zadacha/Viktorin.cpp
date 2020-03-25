#include "Viktorin.h"
#include<fstream>

viktorin* viktorins;
int countviktorins;


void init()
{
	
}

void addviktorin()
{
	ofstream fout;
	fout.open("viktorin.txt");
	bool isopen = fout.is_open();

	if (isopen == true) {
		viktorin* temp = new viktorin[countviktorins + 1];
		for (int i = 0; i < countviktorins; i++)
		{
			temp[i] = viktorins[i];
		}
		const int countqvestions = 5;
		cout << "Enter name for viktorin->";
		cin >> temp[countviktorins].name;

		temp[countviktorins].countqvestion = countqvestions;

		temp[countviktorins].qvestion = new qvestions[countqvestions];

		for (int i = 0; i < countqvestions; i++)
		{
			cout << "Enter qvestion" << endl;
			cin >> temp[countviktorins].qvestion[i].action;
			cout << "Enter ansver " << endl;
			cin >> temp[countviktorins].qvestion[i].ansver;
		}

		fout << temp[countviktorins].name << endl;
	    for (int i = 0; i < countqvestions; i++)
		{
			fout << temp[countviktorins].qvestion[i].action << endl;
			fout << temp[countviktorins].qvestion[i].ansver << endl;
		}

		countviktorins++;
		delete viktorins;
		viktorins = temp;
		fout.close();
	}
	else {
		cout << "Error:file not open" << endl;
	}
}
