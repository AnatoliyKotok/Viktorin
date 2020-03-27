#include "Viktorin.h"
#include<fstream>

viktorin* viktorins;
int countviktorins=0;
const int countquestions = 5;
const string filename = "viktorin.txt";
void insertViktorin(viktorin getQuiz)
{
	viktorin* temp = new viktorin[countviktorins+1];
	for (int i = 0; i < countviktorins; i++)
	{
		temp[i] = viktorins[i];
	}

	temp[countviktorins] = getQuiz;
	countviktorins++;
	viktorins = new viktorin[countviktorins];
	for (int i = 0; i < countviktorins; i++)
	{
		viktorins[i] = temp[i];
	}
	
	delete[]temp;

}
void init()
{
	
	ifstream fin;
	fin.open(filename);

	bool isopen = fin.is_open();
	int count = 0;
	if (isopen == true) {
		  while(!fin.eof()){
			  
			viktorin getQuiz;
			fin >> getQuiz.name;
			for (int i = 0; i < countquestions; i++)
			{
				fin >> getQuiz.qvestion[i].action;
				fin >> getQuiz.qvestion[i].ansver;
			}
			
			insertViktorin(getQuiz);

		}
	}
	else {
		cout << "Error: file not open!" << endl;
	 }
}

void addviktorin()
{
	ofstream fout;
	fout.open(filename,fstream::app);
	bool isopen = fout.is_open();

	if (isopen == true) {
		viktorin* temp = new viktorin[countviktorins + 1];
		for (int i = 0; i < countviktorins; i++)
		{
			temp[i] = viktorins[i];
		}
		
		cout << "Enter name for viktorin->";
		cin >> temp[countviktorins].name;

		

		for (int i = 0; i < countquestions; i++)
		{
			cout << "Enter" << i + 1 << "/5 qeestion->";
			cin >> temp[countviktorins].qvestion[i].action;
			cout << "Enter corekt answer for this question ->";
			cin >> temp[countviktorins].qvestion[i].ansver;
		}

		fout << temp[countviktorins].name << endl;
	    for (int i = 0; i < countquestions; i++)
		{
			fout << temp[countviktorins].qvestion[i].action << endl;
			fout << temp[countviktorins].qvestion[i].ansver << endl;
		}

		countviktorins++;
		viktorins = new viktorin[countviktorins];
		for (int i = 0; i < countviktorins; i++)
		{
			viktorins[i] = temp[i];
		}
		delete []temp;
		
		fout.close();
	}
	else {
		cout << "Error:file not open" << endl;
	}
}

void showviktorin()
{
}

int play()
{
	string ansver;
	int count = 0;
	int a;
	if (countviktorins != 0) {
		for (int i = 0; i < countviktorins; i++)
		{
			cout << i + 1 << "." << viktorins[i].name << endl;
		}
		cout << "Selekt viktorin->";
		cin >> a;
		system("cls");
		cout << viktorins[a-1].name << endl;
		for (int i = 0; i < 5; i++)
		{
			cout << viktorins[a-1].qvestion[i].action << endl;
			cout << "Enter corekt ansverfor question"<<i+1<<"/5->";
			cin >> ansver;
			if (ansver == viktorins[a-1].qvestion[i].ansver) {
				count++;
			}
			
		}
		cout << "Corekt answers - " << count << "/5" << endl;
	}
	else {
		cout << "File is empty" << endl;
	}
	
	
		
	
	return 0;
}


