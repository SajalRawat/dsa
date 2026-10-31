#include <iostream>
using namespace std;



    
void linear(int arr[], int n, int x){
    for(int i=0;i<n;i++){
        if(arr[i]==x){
	    cout<<"found: "<<x<<" at "<<"index: "<<i<<endl;
	    return;
	}
    }
    cout<<"not found"<<endl;

}



void binary(int arr[], int n, int x){
    int lhs=0;
    int rhs=n-1;
    int mid=(lhs+rhs)/2;
    while(lhs<=rhs){
	mid=(lhs+rhs)/2;
	if(arr[mid]==x){
	    cout<<"found"<<x<<"at"<<mid<<endl;
	    return;
	}
	else if(arr[mid]<x) lhs=mid+1;
	else if(arr[mid]>x) rhs=mid-1;
    }
    cout<<"not foundd"<<endl;    

} 


void bubble(int arr[], int n){
    int temp;
    for(int i=0;i<(n-1);i++){
    	for(int j=0;j<n-i-1;j++){
    	    if(arr[j]>arr[j+1]){
	    	swap(arr[j],arr[j+1]);
	    }
        }

    }
    for(int k=0;k<n;k++) cout<<arr[k]<<" ";
    cout<<endl;

}


void select(int arr[], int n){
    int min;
    int index;
    for(int i=0;i<n-1;i++){
	min=arr[i];
        index=i;
    	for(int j=i+1;j<n;j++){
    	    if(arr[j]<min){
		min=arr[j];
		index=j;
	    }
        }
		
	
	swap(arr[index],arr[i]);
    }
    for(int k=0;k<n;k++) cout<<arr[k]<<" ";
    cout<<endl;

}



int main(){
    
    int n;
    cout<<"enter length of array"; 
    cin>>n;

    int arr[n];
    cout<<"keep entering the elements";
    for(int i=0;i<n;i++) cin>>arr[i];
   int choice;

do {
    cout << "\n========== ARRAY OPERATIONS ==========\n";
    cout << "1. Linear Search\n";
    cout << "2. Binary Search\n";
    cout << "3. Bubble Sort\n";
    cout << "4. Selection Sort\n";
    cout << "5. Display Array\n";
    cout << "6. Exit\n";
    cout << "======================================\n";

    cout << "Enter your choice: ";
    cin >> choice;

    switch(choice) {
        case 1: {
            int x;
            cout << "Enter element to search: ";
            cin >> x;
            linear(arr, n, x);
            break;
        }

        case 2: {
            int x;
            cout << "Enter element to search: ";
            cin >> x;
            binary(arr, n, x);
            break;
        }

        case 3:
            bubble(arr, n);
            break;

        case 4:
            select(arr, n);
            break;

        case 5:
            for(int i = 0; i < n; i++)
                cout << arr[i] << " ";
            cout << endl;
            break;

        case 6:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
    }

} while(choice != 6);

    
}















