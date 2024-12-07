#include<iostream>
using namespace std;
const int Maxsize = 10;
class linkedlist{
 private:
  struct Node {
    int data; 
    Node* next; 

    Node(int value) : data(value), next(nullptr) {}
};
public:
 Node* head;
 linkedlist(): head(nullptr){};
 void add(int value){
    Node* newnode = new Node(value);
     if(head==nullptr){
        head = newnode;
     }
     else{
        Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newnode;
     }
 }
        void remove() {
        if (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        } else {
            cout << "The list is empty, cannot remove item." << endl;
        }
    }
    void displayItems() const {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
 };
int main(){
    linkedlist l1;
    l1.add(1);
    l1.add(2);
    l1.add(3);
    l1.add(4);
    l1.add(5);
    l1.add(6);
    l1.add(7);
    l1.add(8);
    l1.add(9);
    l1.add(10);
    l1.displayItems();
    return 0;
}