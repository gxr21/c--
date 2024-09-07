#include<iostream>
#include<ctime>
using namespace std;
const int maxsize = 10;
class multiqueue{
private:
    int front1 , rear1 , front2 , rear2;
    int mq[maxsize];
public:
    multiqueue(): front1(-1) , rear1(-1) , front2(maxsize) , rear2(maxsize){};
    bool full1(){return rear1 == front1 -1 ;}
    bool full2(){return rear2 == rear2 +1 ;}
    bool empty1(){return front1 == rear1 ;}
    bool empty2(){return front2 == rear2 ;}
    void add1(int element){
        if(full1()){
            cout << "queue 1 is full " << endl;
        }
        if(rear1 == -1){
            front1  = 0;
        }
        mq[++rear1] = element;
    }
    void add2(int element){
        if(full2()){
            cout << "queue 2 is full " << endl;
        }
        if(rear2 == maxsize ){
            front2  = maxsize - 1;
        }
        mq[--rear2] = element;
    }
    void remove1(){
        if(empty1()){
            cout << "queue 1 is empty " << endl;
        }
        cout << "Removed from Queue 1: " << mq[front1++] << endl;
        if(front1 > rear1){
            front1 = rear1 = -1;
        }
    }
    void remove2(){
        if(empty2()){
            cout << " queue 2 is empty " << endl;
        }
        cout << "Removed from Queue 2: " << mq[front2--] << endl;
        if(front2 < rear2){
            front2 = rear2 = maxsize;
        }
    }
   void display1(){
    if (empty1()) {
            cout << "Queue 1 is empty\n";
            return;
        }
        cout << "Queue 1 elements: ";
        for (int i = front1; i <= rear1; i++) {
            cout << mq[i] << " ";
        }
        cout << endl;
   }
   void display2(){
    if (empty2()) {
            cout << "Queue 2 is empty\n";
            return;
        }
        cout << "Queue 2 elements: ";
        for (int i = front2; i >= rear2; i--) {
            cout << mq[i] << " ";
        }
        cout << endl;
    }
};
int main(){
 multiqueue mq;
 mq.add1(1);
 mq.add1(2);
 mq.add1(3);
 mq.add1(4);
 mq.add1(5);
 mq.display1(); // multiqueue complate...
    return 0;
}