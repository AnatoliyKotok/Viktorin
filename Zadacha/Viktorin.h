#pragma once
#include<iostream>
#include<string>

using namespace std;
struct qvestions {
	string action;
	string ansver;
};

struct viktorin {
	string name;
	qvestions*qvestion;
	int countqvestion;
	

};

void init();
void addviktorin();