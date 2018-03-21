package com.company;

import com.company.LinkedNode;

public class Ch_7_Questions {
    //P
    
    public static void main(String[] args){
        int [] feed = {1,2,3,4,5,6};
        LinkedNode<Integer> list1 = LinkedNode.createList(feed);
        //create a linked list, test.
        list1.printList();

    }

    public static LinkedNode<Integer> mergeSortedLists(LinkedNode<Integer> list1, LinkedNode<Integer> list2){
        LinkedNode<Integer> tempHead = new LinkedNode<>(0,null);
       LinkedNode<Integer> current = tempHead;
        if(list1.data <= list2.data){
            current.next = list1;
            list1 = list1.next;
        }
        else {
            current.next = list2;
            list2 = list2.next;
        }

        current = current.next;

        current.next = list1.next == null ? list2:current.next;

        return tempHead.next;

    }
}
