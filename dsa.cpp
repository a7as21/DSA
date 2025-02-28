#include "utility.h"
#include "linkedlist.h"
#include "heap.h"
#include "graph.h"
#include "utility.h"

using namespace std;

void linkedListmain() {

	cout << "single linked list\n\n\n";
	singleLinkedList sl;

	sl.insertBeginning(4);
	
	sl.insertEnd(5);

	sl.insertPos(6,3); 
	
	sl.insertBeginning(20); 
	sl.insertEnd(2);
	sl.insertPos(200, 3); 

	cout << "after only insertion: ";
	sl.display(); 


	sl.deleteBeginning(); 
	sl.deleteEnd(); 
	sl.deletePos(2); 

	cout << "after deletion: ";
	sl.display();

	int value = 4;

	cout << "does the linked list have the value " << value << ": ";
	sl.searchLinkedList(value) ? cout <<"True\n" : cout << "False\n";

	cout << "\n\n\ndouble linked list\n\n\n";


	doubleLinkedList dl;

	dl.insertEnd(5);
	
	dl.insertBeginning(4);

	dl.insertPos(6, 3);

	dl.insertBeginning(20);
	dl.insertEnd(2);
	dl.insertPos(200, 4);

	cout << "after only insertion (forwards): ";
	dl.displayForward();

	cout << "\nafter only insertion (backwards): ";
	dl.displayBackward();

	dl.deleteBeginning();
	dl.deleteEnd();
	dl.deletePos(3);

	cout << "\n\nafter deletion (forwards): ";
	dl.displayForward();
	
	cout << "\nafter deletion (backwards): ";
	dl.displayBackward();


	cout << "does the linked list have the value " << value << ": ";
	dl.searchLinkedList(value) ? cout <<"True\n" : cout << "False\n";

}


//////////////////////////////////////////////////////////////////////////////////////////////////////


void heapMain()
{
    vector<int> arr = { 10, 5, 3, 2, 4 };

	int n = arr.size();

	deleteRoot(arr, n);

    displayTree(arr, 0, 0);

}

//////////////////////////////////////////////////////////////////////////////////////////////////////

void graphMain() {
    Graph g(5); // Create a graph with 5 vertices (0 to 4)

    // Add edges to the graph
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);

    // Perform DFS starting from node 0
    g.DFS(0);

    // Perform BFS starting from node 0
    g.BFS(0);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

int main() {
	
	int c;

	while(c != 10) {
		cout << "1: heaps\n";
		cout << "2: graphs\n";
		cout << "3: linked lists\n";
		cout << "Type 10 to exit\n";

		cin >> c;
		if(c == 1)
			heapMain();
		else if (c == 2)
			graphMain();
		else if (c == 3)
			linkedListmain();
		cout << "\n\n\n";
	}


}