#include"TuringMachine.h"
#include<iostream>
using namespace std;

void TuringMachine::add_element(char n) {
	if (head == NULL) {
		Cell* buf = new Cell;
		buf->info = n;
		buf->next = NULL;
		buf->prev = NULL;
		head = buf;
		return;
	}
	Cell* it = head;
	while (it->next) {
		it = it->next;
	}
	Cell* buf = new Cell;
	buf->info = n;
	buf->next = NULL;
	buf->prev = it;
	it->next = buf;
	it = buf;
}

void TuringMachine::clear_tape() {
	if (head == NULL) return;
	while (head) {
		Cell* next = head->next;
		delete head;
		head = next;
	}
}

void TuringMachine::show_tape() {
	
	Cell* buf = head;
	while (buf) {
		cout << buf->info;
		buf = buf->next;
	}
	cout << endl;
}

void TuringMachine::create_rules(int n) {
	Rule r;
	cout << "found\trequired\tturn\tnextrule" << endl;
	for (int i = 0; i < n-1; i++) {
		
		cin >> r.found >> r.required >> r.turn >> r.nextrule ;
		rules.push_back(r);
	}
	Rule p;
	cin >> p.found >> p.required >> p.turn;
	p.nextrule = - 1;
	rules.push_back(p);
}

void TuringMachine::show_rules(int n) {
	cout << "rules:" << endl;
	for (int i = 0; i < n; i++) {
		cout << rules[i].found << "\t" << rules[i].required << "\t" << rules[i].turn <<"\t"<<rules[i].nextrule;
	}
	cout << endl;
}


void TuringMachine::run_machine(int n) {
	Cell* iterator=head;
	bool longcycle = false;
	int i=0;
	while (i != -1 && i < n) {
		if (rules[i].found == iterator->info) {
			longcycle = false;
			iterator->info = rules[i].required;
			if (rules[i].turn == 'r' && iterator->next != NULL) {
				iterator = iterator->next;
				//TuringMachine::turn(iterator, 'r');
				continue;
			}
			if (rules[i].turn == 'l' && iterator->prev != NULL) {
				iterator = iterator->prev;
				//TuringMachine::turn(iterator, 'l');
				continue;
			}
			if (iterator->next == NULL || iterator->prev == NULL) {
				return;
			}
			i = rules[i].nextrule - 1;
		}
		else {
			if (i == n - 1) {
				if (!longcycle) {
					i = 0;
					longcycle = true;
				}
				else {
					if (iterator->next != NULL) {
						iterator = iterator->next;
						//TuringMachine::turn(iterator, 'r');
					}
					else return;
				}
			}
			else {
				i++;
			}
		}
	}
}



