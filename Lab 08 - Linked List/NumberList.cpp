#include <iostream>
#include "NumberList.h"
using namespace std;

NumberList::NumberList() {
	head = nullptr;
}

void NumberList::appendNode(int num) {
	
	ListNode *newNode;	//To point to a new node
	ListNode *nodePtr;	//To traverse nodes
	
	//Allocate new node and store data
	newNode = new ListNode;	
	newNode->value = num;
	newNode->next = nullptr; 

	if (!head)	//If no nodes set as first node
		head = newNode; 
	else {
		nodePtr = head;	//Set to start of list

		while (nodePtr->next)	//Traverse through the list
			nodePtr = nodePtr->next;	

		nodePtr->next = newNode; //Add node to end
	}

}

void NumberList::insertNode(int num) {
	ListNode *newNode;	//To point to a new node
	ListNode *nodePtr;	//To traverse nodes
	ListNode *prevNode;	//To insert after previous node

	//Allocate new node and store data
	newNode = new ListNode;
	newNode->value = num;
	newNode->next = nullptr;

	if (!head)	//If no nodes set as first node
		head = newNode;
	else {
		nodePtr = head; //Set to start of list
		prevNode = nullptr; //Set previous node to null

		while (nodePtr != nullptr && nodePtr->value < num) { //Traverse through list until end or a list value is greater than num
			prevNode = nodePtr; 
			nodePtr = nodePtr->next; 
		}

		if (prevNode == nullptr) { //If inserting on first node 
			head = newNode;
			newNode->next = nodePtr;
		}
		else {
			prevNode->next = newNode; 
			newNode->next = nodePtr;
		}
	}
}

void NumberList::deleteNode(int num) {
	ListNode *nodePtr;
	ListNode *prevNode = nullptr;

	if (!head) //Edge case: num not found or empty list
		return;
	
	if (head->value == num) { //If first node is going deleted
		nodePtr = head->next; 
		delete head;
		head = nodePtr;
	}
	else {
		nodePtr = head; //Set to start of list

		while (nodePtr != nullptr && nodePtr->value != num) { //Traverse through list until end or a node value is equal to num
			prevNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		if (nodePtr) { //If true
			prevNode->next = nodePtr->next; 
			delete nodePtr;
		}
	}
}

void NumberList::displayList() const {
	ListNode *nodePtr;

	nodePtr = head; //Set to start of list

	while (nodePtr) { //Display each node
		cout << nodePtr->value << " ";

		nodePtr = nodePtr->next;
	}
}


