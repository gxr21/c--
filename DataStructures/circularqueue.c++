#include<iostream>
using namespace std;
const int Maxsize = 10;
class circularq{
private:
    int cqueue[Maxsize];
    int front , rear;
public:
    circularq(): front(-1) , rear(-1){};
    int isfull(){return front == (rear+1)%Maxsize;}
    int isempty(){return front==-1;}
 void add(int value){
    if(isfull()){
        cout << "queue is full baby" << endl;
    }
    if(isempty()){
        front = rear = 0;
    }
    else
    {
    rear = (rear+1) % Maxsize;
    }
    cqueue[rear] = value;
 }
 void remove(){
    if(isempty()){
        cout << "queue is empty baby" << endl;
    }
    if(front == rear){
        front = rear = -1;
    }else
    {
        front = (front+1) % Maxsize;
    }
 }
 void display(){
    if(isfull()){
        cout << "queue is full " << endl;
    }
    cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << cqueue[i] << " ";
            if (i == rear) {
                break;
            }
            i = (i + 1) % Maxsize;  // Move through the circular queue
        }
        cout << endl;

 }
};
int main(){
    circularq cq;
    cq.add(1);
    cq.add(2);
    cq.add(3);
    cq.add(4);
    cq.add(5);
    cq.add(6);
    cq.add(7);
    cq.add(8);
    cq.add(9);
    cq.add(10);
    cq.remove();
    cq.add(11);
    cq.remove();
    cq.display();
    return 0;
}