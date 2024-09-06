#include<iostream>
using namespace std;
const int maxsize = 10;
class multstack {
private:
    int ms[maxsize];
    int top1 , top2;
public:
    multstack(): top1(-1) , top2(maxsize){};
    int full1(){return top1+1==top2;}
    int full2(){return top2-1==top1;}
    int empty1(){return top1==-1;}
    int empty2(){return top2==maxsize;} 
    void push1(int element){
        if(full1()){
            cout << "stack 1 is overflow" << endl;
        }
        else{
            top1++;
            ms[top1] = element;
        }
    }
    void push2(int element){
        if(full2()){
            cout << "stack 2 is overflow" << endl;
        }
        else{
            --top2;
            ms[top2] = element;
        }
    }
    void pop1(){
        if(empty1()){
            cout << "stack 1 is empty " << endl; 
        }
        else{
          ms[top1--];
        }
    }
    void pop2(){
        if(empty2()){
            cout << "stack 2 is empty " << endl;
        }
        else{
            ms[top2++];
        }
    }
void display1(){
    if(empty1()){
        cout << "stack 1 is empty" << endl;
    }
    for(int i = top1; i >= 0 ; i--){
        cout << ms[i] << " ";
    }
}
    void dispplay2(){
        if(empty2()){
            cout << "stack 2 is empty " << endl;
         }
        for(int i = top2; i < maxsize; i++){
            cout << ms[i] << " " ;
         }
     }
};
int main(){
    multstack m;
    m.push1(1);
    m.push1(2);
    m.push1(3);
    m.push1(4);
    m.push1(5);
    m.pop1();
    m.pop1();
    m.display1();
    cout << endl;
    m.push2(6);
    m.push2(7);
    m.push2(8);
    m.push2(9);
    m.push2(10);
    m.dispplay2();
    return 0;
} 