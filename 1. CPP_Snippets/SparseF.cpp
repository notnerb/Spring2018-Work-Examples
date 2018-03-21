#include <iostream>
# include <stdio.h>
# include <stdlib.h>
//utlilizing scanf and printf since consensus seems to be that they are 
//faster than iostream
//NVM, just saw the post about speeding up io, thank you!;
struct snode{
      int val;
      int row;
      int col;
      struct snode *next;
};
void find (struct snode *);
void printlist (struct snode *);
//find the desired values;
void find(struct snode *f, int k){
	struct snode *sniffer;
	sniffer = f;
	
	while (sniffer!=NULL){
		if(sniffer-> val == k){
			std::cout<<sniffer->row<<" "<<sniffer->col<<" ";
		}
		sniffer=sniffer->next;
	}
}	
//For early debugging.
void printlist(struct snode *p){
      while (p->next!= NULL)
           {
      printf("%d %d %d\n",p->row,p->col,p->val);
               p = p-> next;
        }
}
//Reusing my previously created LinkedList.
class LinkedList
{
public:
    snode *pHead;
	snode *iterator;
	int length;
    //Constructor
    LinkedList(void);
    //Maybe Useful.
    LinkedList(int val);
    //travers and print the value of each node;
    void traversePrint();
    //add to list
    void link(int data, int c,int r);
    //Interleve a minor list into the main list;
    void interleve (int step2, LinkedList minor);
    //void resetIterator();
};
LinkedList::LinkedList()
{
    //Initializes the Head Node and iterator;
    pHead = new snode;
    iterator = pHead;
}  
//insert end of list;
void LinkedList::link(int data, int r, int c){
	iterator->val=data;
	iterator->col=c;
	iterator->row=r;
	iterator->next= new snode;
	iterator=iterator->next;
	iterator->next=NULL;
}
//A function to add the matrices. Lots of trial and error, 
//still not quite sure if it is optimal.
LinkedList addmat(struct snode *p, struct snode *q){
	LinkedList total;
	int val;
	//P[i,j]+Q[i,j]=C[i,j]
     while((p!=NULL) && (q != NULL)){
		if(p->row < q->row){
		   total.link(p->val,p->row,p->col);
		   p = p->next;
	    }
	    else
	    if(p->row > q->row){
		   total.link(q->val,q->row,q->col);
		   q = q->next;
        }
        else
	    if( p->col < q->col){
		   total.link(p->val,p->row,p->col);
           p = p->next;
        }
        else
        if(p->col > q->col){
		   total.link(q->val,q->row,q->col);
		   q = q->next;
        }
	    else{
		    val = p->val + q->val;
		    if(val!=0){
		    total.link(val,p->row,p->col);
			}
		    p = p->next;
		    q = q->next;
	    }
    }
    while(p!=NULL){
		if(p->next!=NULL){
		total.link(p->val,p->row,p->col);
		}
		p = p->next;
    }
	while(q!=NULL){
		if(q->next!=NULL){
		total.link(q->val,q->row,q->col);
		}
		q = q->next;
    }
   return(total);
}
int main(){
	std::ios::sync_with_stdio(false);
	int rows,eles,c,data,snum;
	int *sint;
	LinkedList m1;
	LinkedList m2;
	LinkedList addm;
	scanf("%d",&rows);
	//first list input and create;
	for(int i =0;i<rows;i++){
		scanf("%d",&eles);
		for(int j=0;j<eles;j++){
			scanf("%d %d",&c,&data);
			m1.link(data,i,c);
		}
	}
	//printlist(m1.pHead);
	scanf("%d",&rows);
	//second list input and create;
	for(int i =0;i<rows;i++){
		scanf("%d",&eles);
		for(int j=0;j<eles;j++){
			scanf("%d %d",&c,&data);
			m2.link(data,i,c);
		}
	}
	//printf("Made2\n");
	//printf("Made2\n");
	addm = addmat(m1.pHead,m2.pHead);
	scanf("%d",&snum);
	sint = new int[snum]();
	for(int i = 0;i<snum;i++){
		scanf("%d",&sint[i]);
	}
	printf("\n");
	for(int i = 0;i<snum;i++){
		find(addm.pHead,sint[i]);
		std::cout<<"\n";
	}
}
