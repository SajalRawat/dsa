#include <iostream>
#define SIZE 10

using namespace std;



int front=-1;
int rear=-1;
int queue[SIZE];

//empty
//full

void enqueue(int x){
    

    if((rear+1)%SIZE==front){
        cout<<"it is full"<<endl;
        return;   
    }

    if(front==-1){
        front=0;
    }

    rear=(rear+1)%SIZE;
    queue[rear]=x;
    cout<<"added "<<x<<endl;

}


void dequeue(){
    if(front==-1){
        cout<<"empty"<<endl;
	return;
    }

    if(front==rear){
	cout<<"removed "<<queue[front]<<endl;
	front=rear=-1;
	return;
    }

    cout<<"removed "<<queue[front]<<endl;
    front=(front+1)%SIZE;
    
}



void disp(){
    cout<<"displaying:    ";
    if(front==-1){
        cout<<"empty"<<endl;
	return;
    }



    int pos=front;
    for(int i=0;i<SIZE;i++){
	pos=(front+i)%SIZE;
        cout<<queue[pos];
	if(pos==rear){
	    break;
	}       

    }
    cout<<endl;
  

}


int main(){
    
    

enqueue(5);
disp();
enqueue(6);
disp();
enqueue(7);
disp();
enqueue(8);
disp();
dequeue();
disp();
dequeue();
disp();
dequeue();
disp();
dequeue();
disp();
dequeue();
disp();
dequeue();
disp();
    
}