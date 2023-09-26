#include<iostream>
#include"TuringMachine.h"
#include<vector>
using namespace std;

int main() {
	TuringMachine t;
	t.add_element('1');
	t.add_element('#');
	t.add_element('$');
	t.add_element('1');
	t.add_element('0');
	t.add_element('#');
	t.show_tape();
	int n = 4;
	t.create_rules(n);
	t.show_rules(n);
	t.run_machine(n);
	t.show_tape();
	t.clear_tape();
}