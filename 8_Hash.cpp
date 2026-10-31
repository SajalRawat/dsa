// Online C++ compiler (editor)
// Write and run C++ online using this editor.

#include <iostream>
#define SIZE 10
#include <string>
using namespace std;


struct person{
    string name;
    string phone;
};


person h[SIZE];
int status[SIZE]={0};



int hingkey(person pe){
    string p=pe.phone;
    return (p[p.length()-1]-'0' )% SIZE;
}

void ins(person p){
    
    int index=hingkey(p);
    int pos;
    for(int i=0; i<SIZE; i++){
        pos=(index+i)%SIZE;
        if(status[pos]==0){
            cout<<endl<<"inserted";
            cout<<endl<<p.name;
            cout<<"  "<<p.phone;
            h[pos]=p;
            status[pos]=1;
            return;
        }
        
    }
    cout<<endl<<"its full";

}

void sea(person p){
    int index=hingkey(p);
    int pos;
    for(int i=0; i<SIZE; i++){
        pos=(index+i)%SIZE;
        if(h[pos].phone==p.phone && status[pos]==1){
            cout<<endl<<"found";
            cout<<endl<<h[pos].name;
            cout<<"  "<<h[pos].phone;
     
            return; 
        }
       
    }
     cout<<endl<<"not found";
}


void del(person p){
    int index=hingkey(p);
    int pos;
    for(int i=0; i<SIZE; i++){
        pos=(index+i)%SIZE;
        if(h[pos].phone==p.phone && status[pos]==1){
            cout<<endl<<"deleting";
            cout<<endl<<h[pos].name;
            cout<<"  "<<h[pos].phone;
            status[pos]=0;
            return; 
        }
       
    }
     cout<<endl<<"doesnt exist";
}


int main() {
    person p;
    p.name="abc";
    p.phone="9876554321";
    ins(p);
cout<<endl;
cout<<endl;
    sea(p);
cout<<endl;
cout<<endl;
    del(p);
cout<<endl;
cout<<endl;
    sea(p);
cout<<endl;
cout<<endl;
    return 0;
}