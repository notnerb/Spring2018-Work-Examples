package com.company;

public class LinkedNode<T> {
   public T data;
   public LinkedNode<T> next;

   public LinkedNode(T i, LinkedNode<T> o) {
      data = i;
      next = o;
   }

   public static void insertNewNode(LinkedNode<Integer> newNode, LinkedNode<Integer> previousNode){

      newNode.next = previousNode.next;
      previousNode.next = newNode;

   }

   public static void deleteNode(LinkedNode<Integer> precedingNode){

      precedingNode.next = precedingNode.next.next;

   }

   public static LinkedNode<Integer> searchList(LinkedNode<Integer> head, int key){

      while(head.next != null){
         head = head.next;
         if(head.data == key){
            return head;
         }
         else{
            return null;

         }
      }

      return null;
   }
   //create a linked list from an integer array.
   public static LinkedNode<Integer> createList(int[] nodes){
      LinkedNode<Integer> tempHead = new LinkedNode<>(0, null);
      LinkedNode<Integer> iterator = tempHead;

      for(int i = 0;i < nodes.length;++i){
         iterator.next = new LinkedNode<>(nodes[i], null);
         iterator = iterator.next;
      }
      return tempHead.next;
   }

   public void printList(){
      LinkedNode<T> dummyHead = this;
      while(dummyHead.next != null){
         System.out.print(dummyHead.data);
         dummyHead = dummyHead.next;
      }
      //for data of last node.
      if(dummyHead.next == null){
         System.out.print(dummyHead.data);
      }
      System.out.print("\n");
   }

}


