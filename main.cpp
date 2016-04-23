// Joseph Ismailyan
// Circularly Doubly Linked List
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

ifstream in("input.txt");

struct node {

    char data[10];
    node *next;
    node *prev;

};
void insertBeginning(char*, node*&);
void insertEnd(char*, node*&);
void deleteNode(node*&);
void printList(node *&head);

int main(){
    node *head = NULL;
    char cont = 'n';
    char A[10];
    if(!in.eof()){
        cout << "The following data is being stored: " << endl;
        while(in){
            in.getline(A,10,'\n');
            cout << A << endl;
            insertEnd(A, head);
        }
        do{
            deleteNode(head);
            cout << "Delete another node? y/n" << endl;
            cin >> cont;
            cout << endl;
        }while(cont == 'y');
        printList(head);
    }
    cout << "Exiting.. " << endl;
    return 0;
}

void deleteNode(node *&head){
    int num = 0;
    node *temp;
    node *lastTemp;
    node *toDelete;
    temp = head;
    lastTemp = temp;

    cout << "Enter node # to be delete: ";
    cin >> num;

    for(int i = 1; i < num; i++)
        temp = temp->next;
    lastTemp = temp->prev;
    temp->next->prev = lastTemp;
    lastTemp->next = temp->next;
    toDelete = temp;
    if(temp == head){
        head = head->next;
    }
    delete toDelete;
}

void insertBeginning(char *item, node *&head){
    node *newNode;
    newNode = new node;
    strcpy(newNode->data, item);

    if (!head){ //nothing in the list, everything points to self
        newNode->prev = newNode;
        newNode->next = newNode ;
        head = newNode;
    }
    else { //something in the list. Connect old tail and old head
        newNode->prev = head->prev; //newNode->prev=head->prev connect newNode to tail
        newNode->next = head; //connect newNode to head
        head->prev = newNode; //connect old head to the one before it which is the new node
        newNode->prev->next = newNode; //connecting the tail to the new node
        head = newNode; //head becomes newNode
    }

}

void insertEnd(char *item, node *&head){
    node *newNode;
    node *temp;
    newNode = new node;
    strcpy(newNode->data, item);

    if(!head){
        newNode->prev = newNode;
        newNode->next = newNode ;
        head = newNode;
    }
    else{
        temp = head->prev;
        temp->next = newNode;
        head->prev = newNode;
        newNode->next = head;
        newNode->prev = temp;
    }
}

void printList(node *&head){
    node *temp;
    temp = head;
    cout << "This is what the list looks like: " << endl;
        while(temp->next != head){
            cout << temp->data << endl;
            temp = temp->next;
        }
    cout << endl;
}

