/*
 * Assignment_4.cpp
 *
 *  Created on: Apr 4, 2023
 *      Author: Master
 */

#include <iostream>
#include <assert.h>

using namespace std;

struct Node {
		Node *next;
		char data;
};

class Linkedlist {
	private:
		Node *head;
		int capacity;
	public:
		Linkedlist() {
			head = 0;
			capacity = 0;
		}
		~Linkedlist() {
			Node *currentNode = head;
			Node *tempNode;
			while (currentNode != 0) {
				tempNode = currentNode;
				currentNode = currentNode->next;
				delete tempNode;
			}
		}

		void push_back(Node *inputNode) {

			if (capacity == 0) {
				head = inputNode;
			}
			else {
				Node *currentNode = head;					//currentNode ---> 0

				while (currentNode->next != 0) {
					currentNode = currentNode->next;
				}

				currentNode->next = inputNode;
			}

			inputNode->next = 0;
			capacity++;
		}

		void push_front(Node *inputNode) {
			Node *currentNode = head;

			head = inputNode;
			head->next = currentNode;

			capacity++;
		}

		void remove(int index) {
			assert(index < capacity);

			Node *currentNode = head;
			if (index == 0) {
				head = currentNode->next;
			}
			else {
				Node *preIndexNode;
				Node *postIndexNode;			//preIndex ---> currentNode --> postIndex

				int i;
				for (i = 0; i < index; i++) {
					preIndexNode = currentNode;
					currentNode = currentNode->next;
					postIndexNode = currentNode->next;
				}

				preIndexNode->next = postIndexNode;
			}

			delete currentNode;
			capacity--;

		}

		void insert(Node *inputNode, int index) {
			assert(index <= capacity);

			Node *currentNode = head;

			if (index == 0) {
				push_front(inputNode);
			}
			else {
				Node *preIndexNode;			//preIndexNode ---> currentNode
				int i;
				for (i = 0; i < index; i++) {
					preIndexNode = currentNode;
					currentNode = currentNode->next;
				}

				preIndexNode->next = inputNode;
				inputNode->next = currentNode;

				capacity++;
			}

		}

		Node* getNode(int index) {
			assert(index < capacity);

			Node *currentNode = head;

			int i;
			for (i = 0; i < index; i++) {
				currentNode = currentNode->next;
			}

			return currentNode;
		}

		void print() {
			Node *currentNode = head;
			cout << "CAPACITY = " << capacity << "\t";
			cout << "HEAD ---> ";
			while (currentNode != 0) {
				cout << currentNode->data << " ---> ";
				currentNode = currentNode->next;
			}

			cout << "0" << endl;
		}

		bool isEmpty() {
			return (capacity == 0);
		}

};

class QueueLL {
	private:
		Linkedlist LL;

	public:
		void push(char inputData) {
			Node *tempNode = new Node;
			tempNode->data = inputData;
			LL.push_back(tempNode);
		}

		void pop() {
			LL.remove(0);
		}

		char getFront() {
			return (LL.getNode(0)->data);
		}

		bool isEmpty() {
			return LL.isEmpty();
		}
};

class StackLL {
	private:
		Linkedlist LL;

	public:
		void push(char inputData) {
			Node *tempNode = new Node;
			tempNode->data = inputData;
			LL.push_front(tempNode);	  //THE ONLY CHANGE FROM QueueLL CLASS pushing front instead of back
		}

		void pop() {
			LL.remove(0);
		}

		char getTop() {
			return (LL.getNode(0)->data);
		}

		bool isEmpty() {
			return LL.isEmpty();
		}
};

int main() {
	cout << "N = ";

	unsigned int N;
//		cin >> N;
	N = 10;
	cout << N << endl;

	QueueLL q_even;
	QueueLL q_odd;

	StackLL s_even;
	StackLL s_odd;

	int input;

	unsigned int i;
	for (i = 0; i < N; i++) {
		cout << "Number (" << i << ") : ";
		//cin >> input;
		input = i;
		cout << input << endl;

		if (input % 2 == 0) {
			q_even.push(input);
			s_even.push(input);
		}
		else {
			q_odd.push(input);
			s_odd.push(input);
		}
	}

	cout << endl;

	int currentElement;

	cout << "q_even: ";
	while (q_even.isEmpty() == false) {
		currentElement = q_even.getFront();
		q_even.pop();

		cout << currentElement << "\t";
	}

	cout << endl;

	cout << "q_odd : ";
	while (q_odd.isEmpty() == false) {
		currentElement = q_odd.getFront();
		q_odd.pop();

		cout << currentElement << "\t";
	}

	cout << endl;

	cout << "s_even: ";
	while (s_even.isEmpty() == false) {
		currentElement = s_even.getTop();
		s_even.pop();

		cout << currentElement << "\t";
	}

	cout << endl;

	cout << "s_odd : ";
	while (s_odd.isEmpty() == false) {
		currentElement = s_odd.getTop();
		s_odd.pop();

		cout << currentElement << "\t";
	}

	return 0;
}
