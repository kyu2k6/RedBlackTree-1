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
void file();
void add(Node*& head, Node*& current, Node*& previous, int data);
void sort();

int main() {

	bool play2 = true;
	char input2[10];
	Node* head = NULL;

	while (play2 == true) {

		cout << "Console, Read, Print, or Quit: ";
		cin.get(input2, 10);
		cin.get();

		if (strcmp(input2, "Console") == 0) {
			int data;
			cout << "What Value: ";
			cin >> data;
			cin.get();
			Node* current = head;
			Node* previous = NULL;
			add(head, current, previous, data);
		}
		else if (strcmp(input2, "Read") == 0) {
			file();
		}
		else if(strcmp(input2, "Print") == 0) {
			print(head, NULL, false);
		}
		else if (strcmp(input2, "Quit") == 0) {
			play2 = false;
		}
		else {
			cout << "Invalid Input";
		}

	}

	return 0;
}

void sort() {

}

void add(Node*& head, Node*& current, Node*& previous, int data) {
		//firts person is always black
		if (head == NULL) {
			head = new Node();
			current = head;
			head -> setData(data);
			head -> setColor(0);
		}
		else {
			//if incoming is less than current node
			if (data < (current -> getData())) {
				previous = current;
				current = current -> getPrev();
				//if there is nothing below insert the node
				if (current == NULL) {
					current = new Node();
					current -> setData(data);
					previous -> setPrev(current);
					current -> setParent(previous);
					//ADD THE FUNCTION WHERE U RUN THE TEST CASES AND REORGANIZE THE TREE //sort();
					return;
				}
				else {
					add(head, current, previous, data);
				}
			}
			//if incoming is greater than the current node
			else {
				previous = current;
				current = current -> getNext();
				if (current == NULL) {
					current = new Node();
					current -> setData(data);
					previous -> setNext(current);
					current -> setParent(previous);
					//ADD THE FUNCTION WHERE U RUN THE TEST CASES AND REORGANIZE THE TREE //sort();
					return;
				}
				else {
					add(head, current, previous, data);
				}
			}	
		}

}

void file() {

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
	if (head -> getColor() == 0) { //b
		cout << head -> getData() << "B" << endl;
	}
	else { //r
		cout << head -> getData() << "R" << endl;
	}
	if (previous) {
		previous -> str = prevStr;
	}
	trunk->str = (char*)("   |");
	print(head -> getNext(), trunk, false);
}

