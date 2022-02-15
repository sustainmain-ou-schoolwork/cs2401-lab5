#include <iostream>
#include <string>

struct Node {
    std::string data;
    Node *next;
};

class Lilist {
    public:
        Lilist() {head = NULL;}
        void add(std::string item);
        void show();
        Node* search(std::string target);
        void move_front_to_back();
    
    private:
        Node *head;
};

void Lilist::add(std::string item) {
    Node * tmp;
    if(head == NULL) {
        head = new Node;
        head -> data = item;
        head -> next= NULL;
    }
    else {
        for(tmp = head; tmp -> next != NULL; tmp = tmp -> next)
            ;  // this loop simply advances the pointer to last node in
               // the list
        tmp -> next = new Node;
        tmp = tmp -> next;
        tmp -> data = item;
        tmp -> next = NULL;
    }
}

void Lilist::show() {
    for(Node *tmp = head; tmp != NULL; tmp = tmp -> next)
        std::cout << tmp -> data << "  ";
}

Node* Lilist::search(std::string target) {
    Node* cursor = head;

    while (cursor != NULL && cursor -> data != target) {
        cursor = cursor -> next;
    }

    return cursor;
}

void Lilist::move_front_to_back() {
    if (head == NULL || head -> next == NULL) {
        return;
    }
    else {
        // make 1st Node point to NULL
        Node* prev2nd = head -> next;
        head -> next = NULL;

        // make head point to 2nd Node
        Node* prev1st = head;
        head = prev2nd;        

        // make last Node point to 1st 
        Node* tmp;
        for(tmp = head; tmp -> next != NULL; tmp = tmp -> next)
            ;  // this loop simply advances the pointer to last node in
               // the list
        tmp -> next = prev1st;
    }
}