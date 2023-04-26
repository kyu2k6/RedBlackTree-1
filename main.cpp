#include <iostream>
#include <cstring>
#include <fstream>
#include "node.h"

using namespace std;

//RED IS 1 !!!!! BLACK IS 0

//same function from binary search tree
struct Trunk { //Used for printing
    Trunk *previous;
    char* str;

    Trunk(Trunk* previous, char* str) {
        this->previous = previous;
        this->str = str;
    }
};

void showTrunks(Trunk* p) { //Uesd for printing
    if (p == NULL) 
        return;

    showTrunks(p->previous);

    cout << p->str;
}

void print(Node* head, Trunk *previous, bool prev);

int main() {
	
	bool play = true;
	char input1[10];

	cout << "File or Console input? ";
	cin.get(input1, 10);
	cin.get();
	


	return 0;
}


//same print function as the BST
void print(Node* head, Trunk *previous, bool prev) {

	if (head == NULL) {
		return;
	}

	char* prevStr = (char*)("    ");
	Trunk *trunk = new Trunk(previous, prevStr);
	print(head -> getPrev(), trunk, true);

	if (!previous) {
		trunk -> str = (char*)("---");
	}
	else if (prev) {
		trunk -> str = (char*)(".---");
		prevStr = (char*)("   |");
	}
	else {
		trunk -> str = (char*)("'---");
		previous -> str = prevStr;
	}
	showTrunks(trunk);
	cout << " " << head->getData() << endl;

	if (previous) {
		previous -> str = prevStr;
	}
	trunk->str = (char*)("   |");
	print(head -> getNext(), trunk, false);
}

