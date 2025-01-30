/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/ 

#include "split.h"
using namespace std;

/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens)
{
  // if get to end of in, return -- base case
  if(in == nullptr){ 
    return;
  }

  // storing next node in input
  Node* inNext = in->next;

  // if even
  if(in->value %2 == 0){
    Node* temp = evens;
    addNode(in, evens, temp);
  }

  // if odd
  if(in->value %2 == 1){
    Node* temp = odds;
    addNode(in, odds, temp);
  }
  // detating in node
  in = nullptr;
  in = inNext;
  split(in, odds, evens);

}

/* If you needed a helper function, write it here */
void addNode(Node*& inNode, Node*& inList, Node*& temp){
  
  // if input list is empty, put input node directly on input list
  if(inList == nullptr){
    inList = inNode;
    inNode->next = nullptr;
    return;
  }

  // if at end of input list, adding on next node
  if(temp->next == nullptr){
    temp->next = inNode;
    inNode->next = nullptr;
    return;
  }

  // if not at end of input list, 
  //traverse list until can put on
  else{
    addNode(inNode, inList, temp->next);
  }
  
}
