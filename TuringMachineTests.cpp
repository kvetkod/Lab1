#include "pch.h"
#include <sstream>
#include<vector>
#include "CppUnitTest.h"
#include "../lab1.1/TuringMachine.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestNamespace
{
	TEST_CLASS(TuringMachineTests)
	{
	public:
		TEST_METHOD(ShowRulesTest1)
		{
			TuringMachine machine;
			Rule r;
			r.turn = 'r';
			machine.rules.push_back(r);
			stringstream buf;
			streambuf* oldbuf = cout.rdbuf(buf.rdbuf());

			machine.show_rules(1);
			cout.rdbuf(oldbuf);

			string output = buf.str();
			char a = output[0];
			Assert::AreEqual(a, 'r');
		}
		TEST_METHOD(ShowTapeTest1)
		{
			TuringMachine machine;
			machine.add_element('1');
			stringstream buf;
			streambuf* oldbuf = cout.rdbuf(buf.rdbuf());
			machine.show_tape();

			string a = buf.str();
			char output = a[0];
			Assert::AreEqual(output, '1');
		}
		TEST_METHOD(AddElementTest1)
		{
			TuringMachine machine;
			machine.add_element('1');
			Assert::IsNotNull(machine.head);
		}
		TEST_METHOD(AddElementTest2)
		{
			TuringMachine machine;
			machine.add_element('1');
			Assert::AreEqual(machine.head->info, '1');
		}
		TEST_METHOD(AddElementTest3)
		{
			TuringMachine machine;
			machine.add_element('1');
			machine.add_element('1');
			machine.add_element('1');
			Cell* iterator = machine.head;
			while (iterator->next != NULL) {
				iterator = iterator->next;
			}
			Assert::IsNotNull(iterator);
		}
		TEST_METHOD(AddElementTest4)
		{
			TuringMachine machine;
			machine.add_element('1');
			machine.add_element('2');
			machine.add_element('3');
			Assert::AreEqual(machine.head->next->next->info, '3');
		}

		TEST_METHOD(ClearTapeTest1)
		{
			TuringMachine machine;
			machine.add_element('1');
			machine.clear_tape();
			Assert::IsNull(machine.head);
		}
		TEST_METHOD(ClearTapeTest2)
		{
			TuringMachine machine;
			machine.add_element('1');
			machine.add_element('2');
			machine.clear_tape();
			Assert::IsNull(machine.head);
		}
		TEST_METHOD(ClearTapeTest3)
		{
			TuringMachine m1, m2;
			m1.add_element('1');
			m2.add_element('1');
			m1.clear_tape();
			Assert::IsNotNull(m2.head);
		}
		TEST_METHOD(ClearTapeTest4)
		{
			TuringMachine m1, m2;
			m1.add_element('1');
			m2.add_element('1');
			m1.clear_tape();
			Assert::AreEqual(m2.head->info, '1');
		}

		TEST_METHOD(CreateRulesTest1)
		{
			TuringMachine machine;
			int size = 1;
			stringstream input;
			input << "1 1 L 1" << endl;
			vector<Rule> Input = { { '1','1','L',1 } };
			istringstream redirect(input.str());
			streambuf* oldCinBuf = cin.rdbuf(redirect.rdbuf());
			machine.create_rules(size);
			cin.rdbuf(oldCinBuf);
			Assert::AreEqual(machine.rules[0].found, '1');
		}

		TEST_METHOD(RunMachineTest1)
		{
			TuringMachine machine;
			machine.add_element('1');
			Rule r;
			r.found = '1'; r.required = '0'; r.nextrule = 1; r.turn = 'r';
			machine.rules.push_back(r);
			machine.run_machine(1);
			Assert::AreEqual(machine.head->info, '0');
		}
		TEST_METHOD(RunMachineTest2)
		{
			TuringMachine machine;
			machine.add_element('1');
			Rule r;
			r.found = '1'; r.required = '0'; r.nextrule = 1; r.turn = 'r';
			machine.rules.push_back(r);
			machine.run_machine(1);
			Assert::IsNotNull(machine.head);
		}
		TEST_METHOD(RunMachineTest3)
		{
			TuringMachine m1, m2;
			m1.add_element('1');
			m2.add_element('1');
			Rule r;
			r.found = '1'; r.required = '0'; r.nextrule = 1; r.turn = 'r';
			m1.rules.push_back(r);
			m1.run_machine(1);
			Assert::AreNotEqual(m1.head->info, m2.head->info);
		}
	};
}
