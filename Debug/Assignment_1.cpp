/*
 * main.cpp
 *
 *  Created on: Apr 4, 2023
 *      Author: Master
 */

#include <iostream>

using namespace std;

#define MAX_SIZE	20

class Stack {
	private:
		int size;
		int capacity;
		char *top;
		char array[MAX_SIZE];

	public:
		Stack(int inputSize) {
			size = inputSize;
			capacity = 0;
			top = &array[0] - 1;

			int i;
			for (i = 0; i < size; i++) {
				array[i] = 0;
			}
		}

		bool isFull() {
			return (capacity >= size);
		}
		bool isEmpty() {
			return (capacity == 0);
		}

		void push(char inputData) {
			top++;
			capacity++;
			*top = inputData;
		}

		void pop() {
			*top = 0;
			capacity--;
			top--;
		}

		char getTop() {
			return *top;
		}

		void print() {
			int i;
			for (i = 0; i < capacity; i++) {
				cout << array[i];
			}
		}

};

bool hasHigherPrecedence(char a, char b) {
	return ((a == '*' || a == '/') && (b == '+' || b == '-'));
}

int main() {
	char infix[] = "1+2/5*3+(5-7+7-3*5/4)";

	Stack operatorStack(MAX_SIZE);
	Stack outputStack(MAX_SIZE);

	int i = 0;
	while (infix[i] != '\0') {

		if (infix[i] >= '0' && infix[i] <= '9') {
			outputStack.push(infix[i]);
		}
		else {

			switch (infix[i]) {
				case '(': {
					operatorStack.push(infix[i]);
					break;
				}
				case ')': {
					while (operatorStack.getTop() != '(') {
						outputStack.push(operatorStack.getTop());
						operatorStack.pop();
					}
					operatorStack.pop();		// to remove the '('
					break;
				}
				default: {
					while (true) {
						if (operatorStack.isEmpty() == true || operatorStack.getTop() == '('
								|| hasHigherPrecedence(infix[i], operatorStack.getTop()) == true) {
							operatorStack.push(infix[i]);
							break;
						}
						else{
							outputStack.push(operatorStack.getTop());
							operatorStack.pop();
						}
					}
				}
			}

		}

		i++;
	}

	while (operatorStack.isEmpty() == false) {
		outputStack.push(operatorStack.getTop());
		operatorStack.pop();
	}

	outputStack.print();

	return 0;
}
