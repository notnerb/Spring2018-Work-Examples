#include <stdlib.h>
#include <iostream>
int main(){
	//input of array size and numbers to be sorted
	int a;
	std::cin >> a;
	int num[a];
	for(int i = 0; i<a;i++){
		int c;
		std::cin>>c;
		num[i]=c;
	}
	//insertion sort Algorithm
	for(int t = 1;t<a;t++){
		int c = num[t];
		for(int j=t-1;j>=0 && c<num[j];j--){
			num[j+1] = num[j];
			num[j] = c;
		}
	}
	std::cout << "\n";
	for(int i = 0; i<a;i++){
		std::cout << num[i]<< "\n";
	}
}
