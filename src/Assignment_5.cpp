#include <iostream>
using namespace std;

class Node {
	public:
		int dest;
		Node *next;
		Node(int d) {
			dest = d;
			next = nullptr;
		}
};

class GraphLL {
	private:
		int V;
		Node **adjList;		// Array of node pointers

	public:
		GraphLL(int v) {	// How many vertices(nodes) in that graph
			V = v;
			adjList = new Node*[V];		// create a new node pointer for every vertex
			for (int i = 0; i < V; i++) {
				adjList[i] = nullptr;
			}
		}

		~GraphLL() {
			for (int i = 0; i < V; i++) {
				Node *current = adjList[i];
				while (current != nullptr) {
					Node *next = current->next;
					delete current;
					current = next;
				}
			}
			delete[] adjList;
			adjList = nullptr;
		}

		void addEdge(int src, int dest) {
			Node *newNode = new Node(dest);
			newNode->next = adjList[src];
			adjList[src] = newNode;
		}

		void printGraph() {
			for (int i = 0; i < V; i++) {
				Node *temp = adjList[i];
				while (temp != nullptr) {
					cout << "(" << i << "," << temp->dest << ") ";
					temp = temp->next;
				}
				cout << endl;
			}
		}

};

class GraphArr {
	private:
		int V;
		int **arr;
	public:
		GraphArr(int v) {
			V = v;
			arr = new int*[V];
			for (int i = 0; i < V; i++) {
				arr[i] = new int[V]();		//() to zero the elements of the array
			}
		}
		~GraphArr() {
			for (int i = 0; i < V; i++) {
				delete[] arr[i];
			}

			delete[] arr;
			arr = nullptr;
		}

		void addEdge(int src, int dest) {
			arr[src][dest] = 1;
		}

		void printGraph() {
			int i, j;
			for (i = 0; i < V; i++) {
				for (j = 0; j < V; j++) {
					if (arr[i][j] == 1) {
						cout << "(" << i << "," << j << ") ";
					}
				}

				cout << endl;
			}
		}
};

int main() {
	int V = 5;
	GraphLL g_ll(V);

	g_ll.addEdge(0, 1);
	g_ll.addEdge(0, 4);
	g_ll.addEdge(1, 2);
	g_ll.addEdge(1, 3);
	g_ll.addEdge(1, 4);
	g_ll.addEdge(2, 3);
	g_ll.addEdge(3, 4);

	g_ll.printGraph();

	cout << endl;

	GraphArr g_arr(V);

	g_arr.addEdge(2, 1);
	g_arr.addEdge(3, 2);
	g_arr.addEdge(1, 2);
	g_arr.addEdge(0, 3);
	g_arr.addEdge(4, 3);
	g_arr.addEdge(4, 1);
	g_arr.addEdge(1, 3);

	g_arr.printGraph();

	return 0;
}
