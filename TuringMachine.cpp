#include"TuringMachine.h"
#include<iostream>
using namespace std;

Rule::Rule(char found_, char required_, char turn_, int nextrule_) {
	found = found_;
	required = required_;
	turn = turn_;
	nextrule = nextrule_;
}

void Rule::print() {

	cout << found << "\t" << required << "\t" << turn << "\t" << nextrule << endl;

}

void TuringMachine::add_element(char element) {
	if (head == NULL) {
		Cell* cell = new Cell;
		cell->info = element;
		cell->next = NULL;
		cell->prev = NULL;
		head = cell;
		return;
	}
	Cell* ñurrent= head; 
	while (ñurrent->next) {
		ñurrent = ñurrent->next;
	}
	Cell* cell = new Cell;
	cell->info = element;
	cell->next = NULL;
	cell->prev = ñurrent;
	ñurrent->next = cell;
	ñurrent = cell;
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
	
	Cell* cell = head;
	while (cell) {
		cout << cell->info;
		cell = cell->next;
	}
	cout << endl;
}

void TuringMachine::create_rules(char found_, char required_, char turn_, int nextrule_) {

	Rule r(found_, required_, turn_, nextrule_);
	rules.push_back(r);

}

void TuringMachine::show_rules(int size) {
	for (int i = 0; i < size; i++) {
		rules[i].print();
	}
	cout << endl;
}


void TuringMachine::run_machine(int size) {
	Cell* iterator=head;
	bool long_cycle = false;
	int i=0;
	while (i != -1 && i < size) {
		if (rules[i].found == iterator->info) {
			long_cycle = false;
			if (find_element(rules[i].required, rules[i].turn, iterator))
				continue;
			else return;
			i = rules[i].nextrule - 1;
		}
		else {
			move(i, size, iterator, long_cycle);
		}
	}
}


bool TuringMachine::find_element(char required, char turn, Cell* &iterator) {
	iterator->info = required;
	if (turn == 'r' && iterator->next != NULL) {
		iterator = iterator->next;
		return true;
	}
	if (turn == 'l' && iterator->prev != NULL) {
		iterator = iterator->prev;
		return true;
	}
	if (iterator->next == NULL || iterator->prev == NULL) {
		return false;
	}
}

void TuringMachine::move(int &i, int size, Cell* &iterator, bool &long_cycle) {
	if (i == size - 1) {
		if (!long_cycle) {
			i = 0;
			long_cycle = true;
		}
		else {
			if (iterator->next != NULL) {
				iterator = iterator->next;
			}
			else return;
		}
	}
	else {
		i++;
	}
}

