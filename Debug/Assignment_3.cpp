/*
 * Assigment_3.cpp
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

int main() {
	Node *arr[10];

	int i;
	for (i = 0; i < 10; i++) {
		arr[i] = new Node();
		arr[i]->data = 'A' + i;
	}

	Linkedlist LL;
	LL.print();

	LL.push_front(arr[0]);
	LL.print();

	LL.push_front(arr[1]);
	LL.print();

	LL.push_back(arr[2]);
	LL.print();

	LL.push_back(arr[3]);
	LL.print();


	LL.insert(arr[4], 0);
	LL.print();

	LL.insert(arr[5], 3);
	LL.print();

	LL.remove(0);
	LL.print();

	LL.remove(1);
	LL.print();

	LL.remove(3);
	LL.print();


}

