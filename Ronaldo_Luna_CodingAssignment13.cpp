#include <iostream>
#include <vector>
using namespace std;

struct node{
  int data;
  node* next;
  int index;
};


class SLinkedList{
  private:
    node* head;
    node* tail;
  public:

  SLinkedList(){
    head = nullptr;
    tail = nullptr;
    cout << "intialized" << endl;
  };

  void listAppend(int elm){
    node* newNode = new node;
    newNode->data = elm;
    newNode->next = nullptr;
    if(head == nullptr){
      head = newNode;
      tail = newNode;
    }else{
      tail->next = newNode;
      tail = newNode;
    }
  }
  void listPrepend(int elm){
    node* newNode = new node;
    newNode->data = elm;
    newNode->next = head;
    if(head == nullptr){
      head = newNode;
      tail = newNode;
    }else{
      head = newNode;
    }
  }
void ListDisplay() {
  node *tmp;
  tmp = head;
  while (tmp != nullptr) {
      cout << tmp->data << " ";
      tmp = tmp->next;
  }
  cout << endl;
}


node* search(int value) {
  node* temp = head;
  int count = 0; //countains the 'index' or position of the node
  while (temp != nullptr) {
    if (temp->data == value) {
      temp->index = count;
      return temp; 
    }
    temp = temp->next;
    count++;
  }
  return nullptr;
}
void insertAfter(node* curNode, int elem) {
    node* newNode = new node;
    newNode->data = elem;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    }

    else if (curNode == tail) {
        tail->next = newNode;
        tail = newNode;
    }

    else {
        newNode->next = curNode->next;
        curNode->next = newNode;
    }
}
void removeAfter(node* curNode) {
    if (head == nullptr) {
        cout << "List is empty. Nothing to remove." << endl;
        return;
    }

    if (curNode == nullptr && head != nullptr) {
        node* sucNode = head->next;
        delete head; 
        head = sucNode;
        if (head == nullptr) { 
            tail = nullptr;
        }
        return;
    }
    if (curNode->next != nullptr) {
        node* sucNode = curNode->next;
        curNode->next = sucNode->next;

        if (sucNode == tail) {
            tail = curNode;
        }
        delete sucNode; 
    }
}

};

int main() {
  SLinkedList numList1;
  SLinkedList numList2;
  
  numList1.listAppend(30);
  numList1.listAppend(40);
  numList1.listPrepend(20);
  numList1.listPrepend(10);
  numList1.ListDisplay();
  numList1.insertAfter(numList1.search(20), 25);
  numList1.ListDisplay();
  numList1.removeAfter(numList1.search(10));
  numList1.ListDisplay();
  
  //allows user to search within the list
  int searchedValue;
  while(true){
    cout << "What value do you want to search for?(-1 to quit) "<< endl;
    cin >> searchedValue;
    if(searchedValue == -1){
      break;
    }
    node* nodeSearched = numList1.search(searchedValue);
    if( nodeSearched != nullptr){
      cout << "Found node with value " << nodeSearched->data << " at the position: " << nodeSearched->index << endl;
    }else{
      cout << "Could not find node with value " << searchedValue << " please try again." << endl;
    }
  }
  numList1.ListDisplay();

  node* nodeSearched = numList2.search(10);
  if( nodeSearched != nullptr){
    cout << "Found node with value " << nodeSearched->data << endl;
  }else{
    cout << "Could not find node with that value " << endl;
  }
  
  numList2.ListDisplay();
  return 0;
}

