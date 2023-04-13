#include <iostream>
#include <string>
#include "stack.h"
#include <Tchar.h>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "Input RPN Equation" << endl;
	Stack < double > s;
	double op1, op2;
	char c;
	while ((c = cin.peek()) != '\n') {// working until end of line
		if (isdigit(c)) { // if first is digit, it's number.
			cin >> op1;
			s.push(op1);
		}
		else {
			cin >> c; // read operator
			op2 = s.pop();
			op1 = s.pop();
			switch (c) {
				case '+': s.push(op1 + op2); break;
				case '-': s.push(op1 - op2); break;
				case '*': s.push(op1 * op2); break;
					case '/': if (op2 == 0) cerr << "Division by zero!\n";
							else s.push(op1 / op2); break;
			}
		}
		while ((c = cin.peek()) == ' ') {
			cin.ignore(1, ' ');// remove space before next token
		}
	}
	cout << " Result: " << s.pop();
	return 0;
}
