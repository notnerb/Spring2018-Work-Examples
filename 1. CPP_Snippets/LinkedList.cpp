#include <stdlib.h>
#include <iostream>
#include <cstddef>

//Building block of the List;
struct Node {
int stuff;
struct Node *next;
};
//Linked List structure;
class LinkedList
{
public:
    Node *pHead;
	Node *iterator;
	int length;
    //Constructor
    LinkedList(void);
    //Maybe Useful.
    LinkedList(int val);
    //travers and print the value of each node;
    void traversePrint();
    //add to list
    void link(int data);
    //Interleve a minor list into the main list;
    void interleve (int step2, LinkedList minor);
    //void resetIterator();
};
LinkedList::LinkedList()
{
    //Initializes the Head Node and iterator;
    pHead = new Node;
    iterator = pHead;
}  
void LinkedList::link(int data){
	iterator->stuff=data;
	iterator->next= new Node;
	iterator=iterator->next;
	iterator->next=0;
}
void LinkedList::traversePrint()
{	//reset to head;
    iterator = pHead;
    //Empty list check
    if (pHead == 0) {
        std::cout << "Empty List" << "\n";
        return;
    }
    //traverse and print the list while there are still elements.
    while (iterator->next!= 0) { 
		std::cout<<iterator->stuff<<" ";
        //shift iterator;
        iterator = iterator->next;
    }
    std::cout << "\n";
}
void LinkedList::interleve (int step2, LinkedList minor){
	//reset iterator to head of Main list;
	iterator=pHead;
	//initialize second header of Main list;
	Node *iterator2;
	//Second iterator for the list to be inserted.
	Node *minorIterator2;
	//Set second main iterator to one node ahead of the first iterator.
	iterator2 = iterator->next;
	//Set the iterator of the minor (to be inserted) list to its' head.
	minor.iterator = minor.pHead;
	//Set second minor iterator;
	minorIterator2 = minor.iterator->next;
	//traverse main list.
	for(int i=1;i<length+1;i++){
		//move both iterators along the list.
		//move both iterators of minor as well.
		if(i%(step2)==0){
			//perform interleve at step intervals.
			iterator->next = minor.iterator;
			minor.iterator->next = iterator2;
			minor.iterator=minorIterator2;
			//break if there are no more elements to interleve.
			if(minor.iterator->next==NULL){
				break;
			}
			minorIterator2=minorIterator2->next;
		}
		iterator = iterator2;
		iterator2 = iterator2->next;
	}
}
LinkedList popuList(int n, LinkedList list){
	for(int i = 0; i<n;i++){
		int temp;
		//create linked list from inputs
		std::cin>>temp;
		list.link(temp);
	}
	//set list length;
	list.length=n;
	return list;
}
int main(){
	int n1;
	int nlists;
	int step;
	int nelements;
	std::cin>>n1;
	//first linked list
	LinkedList list1;
	//stick this loop in it's own method so the interleve doesn't look 
	//like spaghetti.
	list1 = popuList(n1,list1);
	std::cin>>nlists;
	for (int j = 0; j < nlists;j++){
		LinkedList addList;
		//Take in information regarding additional lists;
		std::cin>>step;
		std::cin>>nelements;
		//create list to be interleved.
		addList=popuList(nelements, addList);
		list1.interleve(step, addList);
		list1.length+=nelements;
	}
	list1.traversePrint();
}
