#include <iostream>
using namespace std;

class Node
{
public:
  int data;
  Node *next;
};

class LinkedList
{
public:
  Node *head;

  LinkedList()
  {
    head = NULL;
  }

  bool isEmpty()
  {
    return (head == NULL);
  }

  void insertFirst(int newValue)
  {
    if (isEmpty())
    {
      Node *newNode = new Node();
      newNode->data = newValue;
      newNode->next = NULL;
      head = newNode;
    }
    else
    {
      Node *newNode = new Node();
      newNode->data = newValue;
      newNode->next = head;
      head = newNode;
    }
  }

  void insertBefore(int item, int newValue)
  {

    if (isFound(item))
    {
      Node *newNode = new Node();
      newNode->data = newValue;

      Node *temp = head;

      while (temp != NULL && temp->next->data != item)
      {
        temp = temp->next;
      }

      newNode->next = temp->next;
      temp->next = newNode;
    }
    else{
      cout << "Item Not Found to insert before it" << endl;
    }
  }

  // insert last
  void append(int newValue){
    if(isEmpty()){
      insertFirst(newValue);
    }else{
      Node *temp = head;

      while(temp ->next != NULL){
        temp = temp ->next;
      }
      Node *newNode = new Node();
      newNode->data = newValue;

      temp ->next = newNode;
      newNode ->next = NULL;
    }
  }

  void Delete(int item){
    if(isEmpty()){
      cout << "Empty linked list .. No items to delete" << endl;
    }
    else{
      // Delete first
      if(head ->data == item){
        Node *delPointer = head;
        head = head-> next;
        delete delPointer;
      }
      // Delete specific item
      else{
        Node *delPointer = head;
        Node *prevPointer = NULL;

        while(delPointer->data != item){
          prevPointer = delPointer;
          delPointer = delPointer ->next;
        }

        prevPointer ->next = delPointer ->next;
        delete delPointer;
      }
    }
  }

  void display()
  {
    Node *temp = head;

    while (temp != NULL)
    {
      cout << temp->data << " ";
      temp = temp->next;
    }
  }

  int count()
  {
    Node *temp = head;
    int counter = 0;

    while (temp != NULL)
    {
      counter++;
      temp = temp->next;
    }
    return counter;
  }

  bool isFound(int key)
  {
    Node *temp = head;
    bool found = false;

    while (temp != NULL)
    {
      if (temp->data == key)
      {
        found = true;
      }
      temp = temp->next;
    }
    return found;
  }
};

const int Size = 5;
int stackArray[Size];
int top = -1;

bool isEmpty(){
  if(top == -1){
    return true;
  }
  else{return false;}
}

bool isFull(){
  if(top == Size -1){
    return true;
  }
  else{return false;}
}

int peek(){
  return stackArray[top];
}

void push(int item){
  if(isFull()){
    cout << "The Stack is full .. can not push item";
  }
  else {
    top++; // top = top +1
    stackArray[top] = item;
  }
}

int pop(){
  if(isEmpty()){
    cout << "The Stack is empty .. can not pop";
    return 0;
  }
  else{
    return stackArray[top--]; 
  }
}

void display(){
  if(isEmpty()){
    cout << "The Stack is empty";
  }
  else{
    for(int i=top; i>= 0 ; i--){
      cout << stackArray[i] << endl;
    }
  }
}

/*

  // // again
  // cout << "Pleace insert the item you want to insert" << endl;
  // cin >> item;

  // list.insertFirst(item);
  // list.display();
  // cout << "\n";

  // // again
  // cout << "Pleace insert the item you want to insert" << endl;
  // cin >> item;

  // list.insertFirst(item);
  // list.display();
  // cout << "\n";

  // // Count elements in linked list
  // cout << list.count() << " elements in linked list" << endl;


   push(9);
  push(6);
  push(2);
  display();
  cout << "Top value is " << peek() << endl;

  cout << "pop " << pop() << endl;
  display();
*/
int main()
{
  LinkedList list;

  // Check if linked list is empty or not
  if (list.isEmpty())
  {
    cout << "Empty linked list" << endl;
  }
  else
  {
    cout << "Not Empty linked list" << endl;
    cout << list.count() << "elements in linked list";
  }

  // Insert the element you want to add
  int item;
  cout << "Pleace insert the item you want to insert" << endl;
  cin >> item;
  list.insertFirst(item);
  list.display();
  cout << "\n";

   // again
  cout << "Pleace insert the item you want to insert" << endl;
  cin >> item;
  list.insertFirst(item);
  list.display();
  cout << "\n";

  // again
  cout << "Pleace insert the item you want to insert" << endl;
  cin >> item;
  list.insertFirst(item);
  list.display();
  cout << "\n";

  // Count elements in linked list
  cout << list.count() << " elements in linked list" << endl;

  // Search
  cout << "Pleace enter the item you want to search about it" << endl;
  cin >> item;
  if (list.isFound(item))
  {
    cout << "Found";
    cout << "\n";
  }
  else
  {
    cout << "Not Found";
    cout << "\n";
  }

  // Insert before
  int newValue;
  cout << "Pleace enter the new value you want to insert" << endl;
  cin >> newValue;
  cout << "Pleace enter the position" << endl;
  cin >> item;
  list.insertBefore(item,newValue);
  cout << "\n";

  list.display();
  cout << "\n";

  // Insert LAST (append)
  cout << "Pleace enter the new value you want to insert" << endl;
  cin >> newValue;
  list.append(newValue);
  cout << "\n";

  list.display();
  cout << "\n";


  
  // Delete
  cout << "Pleace enter the item you want to delete it" << endl;
  cin >> item;
  list.Delete(item);
  cout << "\n";

  list.display();
  cout << "\n";

  return 0;
}
