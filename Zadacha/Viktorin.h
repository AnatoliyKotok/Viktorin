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
	qvestions qvestion[5];
	
	

};

void insertViktorin();
void init();
void addviktorin();
int play();