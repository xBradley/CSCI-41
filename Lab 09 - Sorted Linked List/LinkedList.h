/*
/*
Bradley Gallardo
CS41
Linked list header file
*/

// A class template for holding a linked list.
// The node type is also a class template.
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

//*********************************************
// The ListNode class creates a type used to  *
// store a node of the linked list.           *
//*********************************************

template <class T>
class ListNode
{
public:
   T value;           // Node value
   ListNode<T> *next; // Pointer to the next node

   // Constructor
   ListNode (T nodeValue)
      { value = nodeValue;
        next = nullptr;}
};

//*********************************************
// LinkedList class                           *
//*********************************************

template <class T>
class LinkedList
{
private:
   ListNode<T> *head;   // List head pointer

public:
   // Constructor
   LinkedList()
      { head = nullptr; }
      
   // Destructor
   ~LinkedList();
      
   // Linked list operations
   void appendNode(T);
   void insertNode(T);
   void deleteNode(T);
   void displayList() const;
   void sortList();				//Linear sorting algorithm
};

/*
This sort functions finds the min value node of a list, appends min node to a temp list, and repeats until 
 temp list is a sorted version, and then make head of orginal list point to sorted the list
*/
template <class T>
void LinkedList<T>::sortList() {
	ListNode<T> *nodePtr = nullptr;
	ListNode<T> *prevNode;
	ListNode<T> *minNode = nullptr;
	LinkedList<T> *tempList;

		tempList = new LinkedList<T>;

		while (head != nullptr) {

			minNode = head;

			if (minNode->next)
				nodePtr = minNode->next;
			else
				nodePtr = minNode;

			prevNode = nullptr;

			//Find min value node
			while (nodePtr) {
				if (nodePtr->value < minNode->value || nodePtr->value == minNode->value) 
					minNode = nodePtr;

				nodePtr = nodePtr->next;
			}

			//If the first node is min node, move the pointers to skip it
			if (head == minNode)
				head = minNode->next;
			else {

				nodePtr = head;

				//Find previous node of min node
				while (nodePtr && nodePtr != minNode) {
					prevNode = nodePtr;
					nodePtr = nodePtr->next;
				}

				//Move pointers to skip min node
				prevNode->next = minNode->next;
			}


			//If temp list is empty, make haed point to min node
			if (!tempList->head) {
				tempList->head = minNode;
				minNode->next = nullptr;
			}
			else {
					// Initialize nodePtr to head of list.
					nodePtr = tempList->head;

					// Find the last node in the list.
					while (nodePtr->next)
						nodePtr = nodePtr->next;

					// Insert newNode as the last node.
					nodePtr->next = minNode;
					minNode->next = nullptr;

				}

			} // !while (head != nullptr)

		nodePtr = nullptr;
		minNode = nullptr;

		//Makes head point to sorted list
		head = tempList->head;

		//Set temp list to null
		tempList->head = nullptr;
	
} // !Function end




//**************************************************
// appendNode appends a node containing the value  *
// pased into newValue, to the end of the list.    *
//**************************************************

template <class T>
void LinkedList<T>::appendNode(T newValue)
{
   ListNode<T> *newNode;  // To point to a new node
   ListNode<T> *nodePtr = nullptr;  // To move through the list

   // Allocate a new node and store newValue there.
   newNode = new ListNode<T>(newValue);

   // If there are no nodes in the list
   // make newNode the first node.
   if (!head)
      head = newNode;
   else  // Otherwise, insert newNode at end.
   {
      // Initialize nodePtr to head of list.
      nodePtr = head;

      // Find the last node in the list.
      while (nodePtr->next)
         nodePtr = nodePtr->next;

      // Insert newNode as the last node.
      nodePtr->next = newNode;
   }
   nodePtr = nullptr;
}

//**************************************************
// displayList shows the value stored in each node *
// of the linked list pointed to by head.          *
//**************************************************

template <class T>
void LinkedList<T>::displayList() const
{
   ListNode<T> *nodePtr;  // To move through the list

   // Position nodePtr at the head of the list.
   nodePtr = head;

   // While nodePtr points to a node, traverse
   // the list.
   while (nodePtr)
   {
	   
      // Display the value in this node.
		 cout << nodePtr->value << ", ";

      // Move to the next node.
      nodePtr = nodePtr->next;
   }
}

//**************************************************
// The insertNode function inserts a node with     *
// newValue copied to its value member.            *
//**************************************************

template <class T>
void LinkedList<T>::insertNode(T newValue)
{
   ListNode<T> *newNode;             // A new node
   ListNode<T> *nodePtr;             // To traverse the list
   ListNode<T> *previousNode = NULL; // The previous node

   // Allocate a new node and store newValue there.
   newNode = new ListNode<T>(newValue);
   
   // If there are no nodes in the list
   // make newNode the first node
   if (!head)
   {
      head = newNode;
      newNode->next = NULL;
   }
   else  // Otherwise, insert newNode
   {
      // Position nodePtr at the head of list.
      nodePtr = head;

      // Initialize previousNode to NULL.
      previousNode = NULL;

      // Skip all nodes whose value is less than newValue.
      while (nodePtr != NULL && nodePtr->value < newValue)
      {  
         previousNode = nodePtr;
         nodePtr = nodePtr->next;
      }

      // If the new node is to be the 1st in the list,
      // insert it before all other nodes.
      if (previousNode == NULL)
      {
         head = newNode;
         newNode->next = nodePtr;
      }
      else  // Otherwise insert after the previous node.
      {
         previousNode->next = newNode;
         newNode->next = nodePtr;
      }
   }
}

//*****************************************************
// The deleteNode function searches for a node        *
// with searchValue as its value. The node, if found, *
// is deleted from the list and from memory.          *
//*****************************************************

template <class T>
void LinkedList<T>::deleteNode(T searchValue)
{
   ListNode<T> *nodePtr;       // To traverse the list
   ListNode<T> *previousNode;  // To point to the previous node

   // If the list is empty, do nothing.
   if (!head)
      return;
   
   // Determine if the first node is the one.
   if (head->value == searchValue)
   {
      nodePtr = head->next;
      delete head;
      head = nodePtr;
   }
   else
   {
      // Initialize nodePtr to head of list
      nodePtr = head;

      // Skip all nodes whose value member is 
      // not equal to num.
      while (nodePtr != NULL && nodePtr->value != searchValue)
      {  
         previousNode = nodePtr;
         nodePtr = nodePtr->next;
      }

      // If nodePtr is not at the end of the list, 
      // link the previous node to the node after
      // nodePtr, then delete nodePtr.
      if (nodePtr)
      {
         previousNode->next = nodePtr->next;
         delete nodePtr;
      }
   }
}

//**************************************************
// Destructor                                      *
// This function deletes every node in the list.   *
//**************************************************

template <class T>
LinkedList<T>::~LinkedList()
{
   ListNode<T> *nodePtr;   // To traverse the list
   ListNode<T> *nextNode;  // To point to the next node

   // Position nodePtr at the head of the list.
   nodePtr = head;

   // While nodePtr is not at the end of the list...
   while (nodePtr != nullptr)
   {
      // Save a pointer to the next node.
      nextNode = nodePtr->next;

      // Delete the current node.
      delete nodePtr;

      // Position nodePtr at the next node.
      nodePtr = nextNode;
   }

   head = nullptr;
}
#endif