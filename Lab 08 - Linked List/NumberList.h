#include <iostream>
#ifndef NUMBERLIST_H 
#define NUMBERLIST_H


class NumberList {
private:
	struct ListNode {
		int value;
		ListNode *next;
	};
	ListNode *head;

public:
	NumberList();
	void appendNode(int);
	void insertNode(int);
	void deleteNode(int);
	void displayList() const;
};

#endif // !NUMBERLIST_H 

