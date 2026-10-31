#include <iostream>
#include <algorithm>
#include <cctype>

using namespace std;

struct Node{
	char data;
	Node* next;
};


class stack{
	
Node* top=nullptr;

public:
void push(char input){
	Node* n = new Node{input,top};

	top = n; 
}

char pop(){
    	
	if(top==nullptr){
		cout<<"empty";
		return '\0';
	}

	Node* p=top;
	char wapis=top->data ;
		
	top = top->next;

	delete p;
	return wapis;
            			    	
}

char peek(){

	if(top==nullptr){
		cout<<"empty";
		return '\0';
	}

	return top->data;	

}

bool empty(){
	return (top==nullptr);
}

int prec(char c){
	if(c=='+' || c=='-') return 1;
	if(c=='*' || c=='/') return 2;
	if(c=='^') return 3;

	return 0;
}




string postfix(string s, bool pre=false){

	string out;
	for(char c: s){
		
		
		if(c==' ') continue;

		if(c=='('){
			push(c);
		}

		if(c==')'){
			while(!empty() && peek()!='(') out+=pop();
			if(!empty()) pop();
		}

		if(isalnum(c)) out+=c;

		if(c=='+' || c=='-' || c=='*' || c=='/' || c=='^'){
			
			while(!empty() && peek()!='('){
				if(prec(peek())>=prec(c)) out+=pop();
			}

			push(c);
		}

	}	
		while (!empty())
        	out += pop();

   		return out;

}


string prefix(string s){

	string out=s;

	for(char& ele:out){
		if(ele=='(') ele=')';
		else if(ele==')') ele='(';
	}

	reverse(out.begin(),out.end());
	out=postfix(out,true);

	reverse(out.begin(),out.end());
	return out;

}



};


int main(){
	stack st;
	string s="A+4+45*7/6";
	cout<<"in"<<s<<endl;
		
	cout<<"pre"<<st.prefix(s)<<endl;
	cout<<"post"<<st.postfix(s);
}






