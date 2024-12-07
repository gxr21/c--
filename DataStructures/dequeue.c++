#include<iostream>
using namespace std;
class dequeue{
private:
 struct node{
    int data;
    node* next;
    node(int value): data(value) , next(nullptr){};
 }; 
    node* front;
    node* rear;
public:
 bool isempty(){return front==nullptr;}
 dequeue():front(nullptr), rear(nullptr){};
  void addfront(int value){
    node* newnode = new node(value);
    if(front==nullptr){
        cout << "queue is full " << endl;
        front = rear = newnode;
    }
    else{
        newnode->next = front;
        front = newnode;
    }
  }
 void deleteFront() {
        if (isempty()) {
            cout << "Dequeue is empty, nothing to delete." << endl;
            return;
        }
        node* temp = front;
        front = front->next;

        // If front becomes nullptr, rear should also be nullptr
        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp;
        cout << "Deleted element from the front." << endl;
    }
    void display() {
        if (isempty()) {
            cout << "Dequeue is empty." << endl;
            return;
        }

        node* temp = front;
        cout << "Dequeue elements: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main(){
    dequeue dq;
    dq.addfront(1);
    dq.addfront(2);
    dq.addfront(3);
    dq.addfront(4);
    dq.addfront(5);
    dq.addfront(6);
    dq.addfront(7);
    dq.addfront(8);
    dq.addfront(9);
    dq.addfront(10);
    dq.display();
    return 0;
}