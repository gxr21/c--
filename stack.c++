#include<iostream>
using namespace std;
const int Maxsize = 10;
class stack{
    private:
    int top;
    int Stack[Maxsize];
    public:
    stack():top(-1){};
    int full(){return top==Maxsize-1;}
    int empty(){return top==-1;}
    void push(int element){
        if(full()){
            cout << "stack is full" << endl;
        }
        else{
            Stack[++top] = element;
        }
    }
 void pop(){
    if(empty()){
        cout << "stack is overflow" << endl;
        
    }
    else{
        Stack[top--];
    }
 }
 void display();
};
void stack::display(){
    if(empty()){
        cout << "stack is underflow" << endl;
    }
    else{
    for(int i = top ; i >= 0 ; i--){
        cout << Stack[i] << " ";
    }
  }
}
int main(){
    stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.push(7);
    s.push(8);
    s.push(9);
    s.push(10);
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();    
    s.display();
    return 0 ;
}