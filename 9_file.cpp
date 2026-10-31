#include <iostream>
#include <fstream>
using namespace std;

int main(){

	ofstream out("data.txt");
	out<<"hi fewngiwegbnin"<<endl;
	out.close();

	ifstream in("data.txt");
	string line;
	while(getline(in,line)) cout<<line<<endl;
	in.close();
	
	ofstream app("data.txt", ios::app);
	app<<"adding shi"<<endl;
	app.close();


	ofstream out2("test.txt");
	out2<<"nihg"<<endl;
	out2.close();

	ifstream in2("test.txt");
	string line2;
	while(getline(in2,line2)) cout<<line2<<endl;
	in2.close();

	remove("test.txt");

}