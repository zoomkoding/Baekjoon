#include <string>
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

struct Node { 
    char data = ' ';
    Node* next, * prev; 
    Node() {
        next = prev = NULL;
        data = ' ';
    }
    Node(char c, Node* ptr)//ptr 뒤에 추가
    {
        data = c;
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
    int count;
    DLinkedList() { //생성자
        count = 0;
        head = new Node(); //더미를 선언해서 가지고 있게한다.
        tail = new Node(); //더미를 선언해서 가지고 있게한다.
        head->next = tail; //서로연결한다.
        tail->prev = head;
    }
    void endInsert(char c) { //tail 앞에 추가한다.
        new Node(c, tail->prev);
    }
    void moveRight(){
      if (tail -> data == ' ') return;
      tail = tail -> next;
    }
    void moveLeft(){
        if (tail->prev == head) return;
        tail = tail -> prev;
    }
    void endDelete() { //tail 앞에 제거한다.
        if (tail->prev == head) return;
        tail->prev->selvDelete();
    }
    void printAll() {
        Node* tmp = head;
        while (tmp->next != NULL) {
            cout<< tmp->next->data;
            tmp = tmp->next;
        }
    }
};

int main(){
  DLinkedList *list = new DLinkedList();
  string s;
  Node* cursor = NULL;
  int n;
  char cmd, input;
  cin >> s >> n;
  
  for(int i = 0; i < s.size(); i++)list->endInsert(s[i]);
  
  
  for(int i = 0; i < n; i++){
    cin >> cmd;
    if(cmd == 'P'){
      cin >> input;
      list->endInsert(input);
    }
    else if(cmd == 'D'){
      list->moveRight();
    }
    else if(cmd == 'B'){
      list->endDelete();
    }
    else if(cmd == 'L'){
      list->moveLeft();
    }
  }
  list->printAll();
}