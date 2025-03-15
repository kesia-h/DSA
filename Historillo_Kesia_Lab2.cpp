#include <iostream>

using namespace std;

typedef struct Node{
    string songName;
    Node *link;
}Node;

//Node *sample = new Node;;
//sample->songName = "Heaven Knows by Orange and Lemon";

//cout << sample->songName <<endl;

Node *createNode(string data){
    Node *newNode = new Node;
    newNode->songName = data;
    newNodelink = NULL;

    return newNode;
}

void traverse(Node *head){
    Node *temp = new Node;
    temp = head;

    cout << "My Playlist" << endl;
    while(temp != NULL){
        cout << temp->songName<< "->"<<endl;
        if(temp->link == NULL){
            cout << "NULL"<<endl;
        }

        temp = temp->link;
    }
}

Node *insertAtTheEnd(string data, Node *head){
    if(head == NULL){
        Node *newNode = createNode(data);
        head = newNode;
        cout << "A new node has been inserted at the end \n" << endl;
        return head;
    }
    Node *temp = new Node;
    temp = head;

    while(temp->link != NULL){
        temp = temp->link;
    }

    Node *newNode = createNode(data);
    temp->link = newNode;

    cout << "A new node has been inserted at the end \n" << endl;
    return head;
}

Node *insertAtTheBeginning(string data, Node *head){
    Node *newNode = createNode(data);
    newNode->link = head;

    head = newNode;

    cout << "A new node has been inserted at the beginning \n" <<endl;
    return head;
}

string insertAfter(string after, string data, Node *head){
    Node *temp = new Node; 
    temp = head;

    while(temp->songName.compare(after) != 0){
        if(temp == NULL){
            return "No such song exist, please try again later.";
        }

        temp = temp->link;
    }
    Node *newNode = createNode(data);
    newNode->link = temp->link;
    temp->link = newNode;

    return "An new mode has been added after " + after + "\n";
}

int main(){
    Node *head = createNode("Sanctuary by JOJI");

    head = insertAtTheEnd("Sunday Morning by Maroon 5", head);
    traverse(head);

    return 0;
}
