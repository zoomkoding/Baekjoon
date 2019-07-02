#include <string>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <math.h>

using namespace std;

struct Node {
    int src;
    int dst;
    int w;
    Node* next, * prev;
    Node() {
        next = prev = NULL;
        this->src = 0;
        this->dst = 0;
        this->w = 0;
    }
    Node(int src, int dst, int w, Node* ptr)//ptr 뒤에 추가
    {
        this->src = src;
        this->dst = dst;
        this->w = w;
        prev = ptr;
        next = ptr->next;
        next->prev = prev->next = this;
    }
};

struct LinkedList {
    Node *head;
    Node *tail;
    int count;
    LinkedList() { //생성자
        count = 0;
        head = new Node(); //더미를 선언해서 가지고 있게한다.
        tail = new Node(); //더미를 선언해서 가지고 있게한다.
        head->next = tail; //서로연결한다.
        tail->prev = head;
    }
    void endInsert(int src, int dst, int w) { //tail 앞에 추가한다.
        new Node(src, dst, w, tail->prev);
        count ++;
    }
    void printAll() {
        Node* tmp = head->next;
        while (tmp->next != NULL) {
            printf("%d", tmp->dst);
            tmp = tmp->next;
        }
        printf("\n");
    }
};
LinkedList ** list;
int max_d = 0;

void dfs(int src, int d, int parent){
    Node* tmp = list[src]->head->next;
    bool exist = false;
    while (tmp->next != NULL) {
        if(tmp->dst == parent) {
            tmp = tmp->next;
            continue;
        }
        else{
            exist = true;
            dfs(tmp->dst, d + tmp->w, src);
            tmp = tmp->next;
        }
    }
    if(!exist && max_d < d)max_d = d;
    
}

int main(){
    int n;
    scanf("%d", &n);
    list = new LinkedList*[n+1];
    for(int i = 0; i < n + 1; i++)list[i] = new LinkedList();
    for(int i = 0; i < n; i++){
        int n1, n2, w;
        scanf("%d", &n1);
        while(1){
            scanf("%d", &n2);
            if(n2 == -1) break;
            scanf("%d", &w);
            list[n1]->endInsert(n1, n2, w);
        }
    }
    for(int i = 1; i <= n; i++){
        if(list[i]->count == 1)dfs(i,0,0);
        
    }
    printf("%d", max_d);
    
}
