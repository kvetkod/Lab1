#pragma once
#include<iostream>
#include<vector>
using namespace std;
struct Cell {
	char info;
	Cell* next = NULL;
	Cell* prev = NULL;
};

struct Rule {
	char found;
	char required;
	char turn;
	int nextrule;
};

class TuringMachine {
public:
	vector<Rule>rules;
	Cell* head = NULL;
	void add_element(char n);
	void show_tape();
	void clear_tape();
	void create_rules(int n);
	void show_rules(int n);
	void run_machine(int n);

};

