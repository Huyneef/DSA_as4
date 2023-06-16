#include <bits/stdc++.h>
using namespace std;


struct node 
{
   long int info;
    node *next;
};
struct List {
   node *head;  
   node *tail;
};
node *getNode(long int x) {
    node *p = new node ;
        p->info = x;
        p->next = NULL;
    return p;
}
void addHead(List &L, long int x) {
    node *newele = getNode(x);
    if(L.head == nullptr) {
        L.head = L.tail = newele;
    }
    else {
        newele->next = L.head;
        L.head = newele;
        
    }
}
void addTail(List& L,long int x)
{
    node *newele = getNode(x);
    if(L.head == nullptr) {
        L.head = L.tail = newele;
    }
    else {
        L.tail->next = newele;
        L.tail = newele;
    }
}
node* sEle(List L,long int a) {
    for(;L.head != nullptr;) {
        if(L.head->info == a) {break;}
        L.head = L.head->next;
    }
    return L.head;
}
void addAfter(List &L,long int pos, long int x) {
    
    node *p = sEle(L,pos);
    if(p == nullptr) {
        addHead(L,x);
    }
    else if(p == L.tail) {
        addTail(L,x);
    }
    else {
        node *tmp = getNode(x);
        tmp->next = p->next;
        p->next = tmp;
    }
    
}


void deleteEle(List &L, long int x){
    if(L.head == nullptr) return;
    node* trc = nullptr;
    node *sau = L.head;
    for(;sau!= nullptr;) {
        if(sau->info == x) break;
        trc = sau;
        sau = sau->next;
    }
    if(sau == L.tail) {
        L.tail = trc;
        delete sau;
    }
    else if(trc == nullptr) {
        L.head = L.head->next;
    }
    else if(trc != nullptr) {
        trc->next = sau->next;
        sau->next = nullptr;
        delete sau;
    }
}
void delFir(List &L) {
    if(L.head == nullptr) return;
    node*p = L.head;
    L.head = p->next;
    p->next = nullptr;
    delete p;
}

int main () {
    List L;
    L.head = nullptr;
    L.tail = nullptr;
    while(1) {
        int a; cin >> a;
        if(a == 6) break;
        else if(a == 5) 
        {
               delFir(L);
        }
        
        else if(a == 3) {
            long int x; cin >> x;
            deleteEle(L,x);
        }
        else if(a == 0) {
            long int b;
            cin >> b;
            addHead(L,b);
        }
        else if(a == 1) {
            long int b; cin >> b;
            addTail(L,b);
        }
        else if(a == 2) {
            long int pos; cin >> pos;
            long int b; cin >> b;
            addAfter(L,pos,b);
        }
       
    }
    
    if(L.head == nullptr) cout <<"blank";
    else {
    for(;L.head != nullptr;) {
        cout << L.head->info << " ";
        L.head = L.head->next;
    }
    }
    
}