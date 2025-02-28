#pragma once

#include <iostream>


struct Node {
	int data;
	Node* next;
	Node* prev = nullptr;

	Node(int d) {
		data = d;
		next = nullptr;
	}
};

class singleLinkedList {

	Node* head;

public:
	
	singleLinkedList() { head = nullptr; }

	//insertion functions
	void insertBeginning(int val);
	void insertEnd(int val);
	void insertPos(int val, int pos);

	//deletion functions
	void deleteBeginning();
	void deleteEnd();
	void deletePos(int pos);


	bool searchLinkedList(int target) {

		while(head!=nullptr) {

			if(head->data == target)
				return true;
		
			head = head->next;

		}

		return false;

	}


	void display() {

		if (head == nullptr) {
			std::cout << "empty list";
			return;
		}

		Node* temp = head;
		while (temp != nullptr) {
			std::cout << temp->data << "-->";
			temp = temp->next;
		}

		std::cout << "nullptr\n";

	}

};


void singleLinkedList::insertBeginning(int val) {

	Node* newNode = new Node(val);
	newNode->next = head;
	head = newNode;

}

void singleLinkedList::insertEnd(int val) {

	Node* newNode = new Node(val);

	if (!head) {
		head = newNode;
		return;
	}

	Node* temp = head;
	while (temp->next != nullptr) {
		temp = temp->next;
	}

	temp->next = newNode;

}

void singleLinkedList::insertPos(int val, int pos) {

	if (pos < 1) {
		std::cout << "position should be >= 1";
		return;
	}

	else if (pos == 1) {
		insertBeginning(val);
		return;
	}

	Node* newNode = new Node(val);
	
	int i = 1;

	Node* temp = head;
	while (temp != nullptr && i < pos - 1) {
		temp = temp->next;
		i++;
	}

	if (temp == nullptr) {
		std::cout << "position out of range" << std::endl;
		delete newNode;
		return;
	}

	newNode->next = temp->next;
	temp->next = newNode;

}



void singleLinkedList::deleteBeginning() {

	if (!head) {
		std::cout << "empty list\n";
		return;
	}

	Node* temp = head;
	head = head->next;
	delete temp;

}

void singleLinkedList::deleteEnd() {

	if (!head) {
		std::cout << "empty list\n";
		return;
	}

	Node* temp = head;

	while (temp->next->next != nullptr)
		temp = temp->next;

	delete temp->next;
	temp->next = nullptr;

}

void singleLinkedList::deletePos(int pos) {

	if (pos < 1) {
		std::cout << "position should be >=1\n";
		return;
	}

	if (pos == 1) {
		deleteBeginning();
		return;
	}

	Node* temp = head;
	int i = 1;

	while (temp->next != nullptr && i < pos - 1) {
		temp = temp->next;
		i++;
	}

	if (temp == nullptr || temp->next == nullptr) {
		std::cout << "out of range";
		return;
	}


	Node* toDelete = temp->next;
	temp->next = temp->next->next;
	
	delete toDelete;

}



class doubleLinkedList {

	Node* head;

public:

	doubleLinkedList() { head = nullptr; }

	void insertBeginning(int val);
	void insertEnd(int val);
	void insertPos(int val, int pos);


	void deleteBeginning();
	void deleteEnd();
	void deletePos(int pos);


	bool searchLinkedList(int target) {

		while(head!=nullptr) {

			if(head->data == target)
				return true;
		
			head = head->next;

		}

		return false;

	}

	void displayForward() {

		if (head == nullptr) {
			std::cout << "list is empty\n";
			return;
		}

		Node* temp = head;
		while (temp != nullptr) {
			std::cout << temp->data << "-->";
			temp = temp->next;
		}
		std::cout << "null\n";
	}

	void displayBackward() {

		if (head == nullptr) {
			std::cout << "list is empty\n";
			return;
		}
		
		Node* temp = head;
		while (temp->next != nullptr) {
			temp = temp->next;
		}

		std::cout << "null<--";

		while (temp->prev != nullptr) {
			std::cout << temp->data;
			temp = temp->prev;
			std::cout << "<--";
		}
		std::cout << temp->data;
		std::cout << "\n";

	}

};


void doubleLinkedList::insertBeginning(int val) {

	Node* newNode = new Node(val);
	
	newNode->next = head;
	head->prev = newNode;
	head = newNode;

}

void doubleLinkedList::insertEnd(int val) {

	Node* newNode = new Node(val);

	if (!head) {
		head = newNode;
		return;
	}

	Node* temp = head;
	while (temp->next != nullptr) {
		temp = temp->next;
	}

	temp->next = newNode;
	newNode->prev = temp;

}

void doubleLinkedList::insertPos(int val, int pos){

	if (pos < 1) {
		std::cout << "pos should be >=1";
		return;
	}

	if (pos == 1) {
		insertBeginning(val);
		return;
	}

	Node* newNode = new Node(val);

	Node* temp = head;


	int i = 1;
	while (temp != nullptr && i < pos - 1) {
		temp = temp->next;
		i++;
	}

	if (temp == nullptr) {
		std::cout << "out of position\n";
		return;
	}

	newNode->next = temp->next;
	newNode->prev = temp;

	if (temp->next != nullptr) {
		temp->next->prev = newNode;
	}

	temp->next = newNode;

}


void doubleLinkedList::deleteBeginning(){

	if (head == nullptr) {
		std::cout << "list is already empty\n";
		return;
	}

	Node* temp = head;
	head = head->next;

	if (head != nullptr) {
		head->prev = nullptr;
	}

	delete temp;

}

void doubleLinkedList::deleteEnd(){

	if (head == nullptr) {
		std::cout << "list is already empty";
		return;
	}

	Node* temp = head;

	if (temp->next == nullptr) {
		head = nullptr;
		delete temp;
		return;
	}

	while (temp->next != nullptr) {
		temp = temp->next;
	}

	temp->prev->next = nullptr;
	delete temp;

}

void doubleLinkedList::deletePos(int pos){

	if (head == nullptr) {
		std::cout << "list is already empty\n";
		return;
	}

	if (pos == 1) {
		deleteBeginning();
		return;
	}

	Node* temp = head;
	int i = 1;

	while (temp != nullptr && i < pos) {
		temp = temp->next;
		i++;
	}

	if (temp == nullptr) {
		std::cout << "out of range\n";
		return;
	}

	if (temp->next != nullptr)
		temp->next->prev = temp->prev;

	if (temp->prev != nullptr)
		temp->prev->next = temp->next;

	delete temp;

}