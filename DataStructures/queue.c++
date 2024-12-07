#include<iostream>
using namespace std;
const int maxSize= 10;
class queue{
private:
    int q[maxSize];
    int front , rear;
public:
    queue():front(-1),rear(-1){};
    int isfull(){return rear == maxSize-1 ; }
    int isempty(){return front== -1 ; }
    void add(int element){
        if(isfull()){
            cout << "queue is full" << endl;
        }
        if(isempty()){
            front = 0;
        }
            q[++rear] = element;
    }
    void remove(){
        if(isempty()){
            cout << "queue is empty" << endl;
        }
        if(front == rear){
            front = rear = -1;
        }
        front++;
    }
void display()
{
    if(isfull()){
        cout << "queue is full " << endl;
    }
    cout << "Queue elements: ";
    for (int i = front; i <= rear; i++) {
        cout << q[i] << " ";
      }
        cout << endl;
    
  }
};
int main(){
    queue q;
    q.add(1);
    q.add(2);
    q.add(3);
    q.add(4);
    q.add(5);
    q.add(6);
    q.add(7);
    q.add(8);
    q.add(9);
    q.add(10);
    q.display();
}