#include <string>
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

struct Node { 
    int data = 0;
    Node* next, * prev; 
    Node() {
        next = prev = NULL;
        data = 0;
    }
    Node(int i, Node* ptr)//ptr 뒤에 추가
    {
        data = i;
        prev = ptr;
        next = ptr->next;
        next->prev = prev->next = this; 
    }
    void selvDelete() {
        prev->next = next;
        next->prev = prev;
        delete this;
    }
};

struct DLinkedList {
    Node *head;
    Node *tail;
    Node *iter;
    int count;
    DLinkedList() { //생성자
        count = 0;
        iter = new Node();
        head = new Node(); //더미를 선언해서 가지고 있게한다.
        tail = new Node(); //더미를 선언해서 가지고 있게한다.
        head->next = tail; //서로연결한다.
        tail->prev = head;
        iter = head;
    }
    void endInsert(int i) { //tail 앞에 추가한다.
        new Node(i, tail->prev);   
    }
    void moveRight(){
      if (iter -> next == tail -> prev) iter = head;
      else iter = iter->next;
    }

    void endDelete() { 
        Node* temp = iter->next;
        cout << temp->data;
        moveRight();
        temp->selvDelete();
    }
};

int main(){
  int n, k, count = 0;
  cin >> n >> k;
  DLinkedList *list = new DLinkedList();

  for(int i = 1; i <= n; i++)list->endInsert(i);
  
  cout << "<";
  while(count < n){
    if(count!= 0)cout << ", ";
    for(int i = 0; i < k-1; i++)list->moveRight();
    list->endDelete();
    count ++;
  }
  cout << ">";
}