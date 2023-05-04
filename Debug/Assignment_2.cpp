#include <iostream>

using namespace std;

#define MAX_SIZE	50

class Queue {
	private:
		int size;
		int capacity;

		int *front;
		int *back;

		int array[MAX_SIZE];

	public:
		Queue(int inputSize) {
			size = inputSize;
			capacity = 0;

			front = &array[0];
			back = &array[0] - 1;
		}

		bool isEmpty() {
			return (capacity == 0);
		}

		bool isFull() {
			return (capacity >= size);
		}

		void push(char inputData){
			back++;
			capacity++;

			if(back > &array[size - 1]){
				back -= size;
			}
			*back = inputData;
		}

		void pop(){
			*front = 0;
			capacity--;

			front++;
			if(front > &array[size - 1]){
				front -= size;
			}
		}

		int getFront(){
			return *front;
		}


};

int main() {
	cout << "N = ";

		unsigned int N;
//		cin >> N;
		N = MAX_SIZE;
		cout << N << endl;

		Queue q_even(MAX_SIZE);
		Queue q_odd(MAX_SIZE);

		int input;

		unsigned int i;
		for (i = 0; i < N; i++) {
			cout << "Number (" << i << ") : ";
			//cin >> input;
			input = i;
			cout << input << endl;

			if (input % 2 == 0) {
				q_even.push(input);
			} else {
				q_odd.push(input);
			}
		}

		cout << endl;

		int currentElement;

		cout << "E_Queue: ";
		while (q_even.isEmpty() == false) {
			currentElement = q_even.getFront();
			q_even.pop();

			cout << currentElement << "\t";
		}

		cout << endl;

		cout << "O_Queue: ";
		while (q_odd.isEmpty() == false) {
			currentElement = q_odd.getFront();
			q_odd.pop();

			cout << currentElement << "\t";
		}

	return 0;
}
