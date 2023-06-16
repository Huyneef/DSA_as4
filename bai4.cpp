
#include <iostream>
using namespace std;

//Cach 1: Khi da cai dat List roi, dinh nghia Stack dua tren List
struct node 
{
   int info;
    node *next;
};
struct List {
   node *head;  
   node *tail;
};
node *getNode(int x) {
    node *p = new node ;
        p->info = x;
        p->next = NULL;
    return p;
}
struct Stack
{
	List L;
};
void Init(Stack& s) {
    s.L.head = s.L.tail = NULL;
}
void Push(List& L,const int x) {
    node *newele = getNode(x);
    if(L.head == nullptr) {
        L.head = L.tail = newele;
    }
    else {
        newele->next = L.head;
        L.head = newele;
        
    }
}

void printStack(Stack& s) {
    if(s.L.head != nullptr) {
        for(;s.L.head != nullptr;) {
        cout << s.L.head->info ;
        s.L.head = s.L.head->next;
    }
    }
    else {
        cout << "0";
    }
}
void DecimaltoBinary1(int x,Stack& s) {
    
        while(x) {
        int r = x%2;
        Push(s.L,r);
        x/=2;
        } 
}



int main()
{
    Stack S;Init(S);
    int n,x;
    cin>>n;
    DecimaltoBinary1(n,S);
    printStack(S);
    return 0;
}

