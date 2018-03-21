#include <bits/stdc++.h>
#include <iostream>
#include <string>

long long int mergeS(long long int a[],  int temp[], int left, int right);
long long int merge(long long int a[], int temp[], int left, int midp, int right);
	long long int mergeS(long long int a[], long long int asize)
	{
		int *temp = (int *)malloc(sizeof(int)*asize);
		return mergeS(a, temp, 0, asize - 1);
	}
	//MOdified mergesort
	long long int mergeS(long long int a[], int temp[], int left, int right)
	{
		long long int midp, inversions = 0;
		if (right > left){	
			midp = (right + left)/2;
			inversions = mergeS(a, temp, left, midp);
			inversions += mergeS(a, temp, midp+1, right);
			inversions+= merge(a, temp, left, midp+1, right);
		}
	return inversions;
	}
//
long long int merge(long long int a[],int temp[], int left,int midp, int right)
{
	long long int i,j,k;
	long long int inversions=0;
	i = left;
	j = midp; 
	k = left; 
	while ((i <= midp-1) && (j <=right))
	{
		if (a[i] <= a[j])
		{
		temp[k++]= a[i++];
		}
		else
		{
		temp[k++]=a[j++];
		inversions=inversions+(midp -i);
		}
	}
	while (i <= midp-1){
		temp[k++] = a[i++];
	}
	while (j <= right){
		temp[k++] =a[j++];
	}
	for (i=left; i <=right; i++){
		a[i]=temp[i];
	}
return inversions;
}
int main()
{
	long long int testcases;
	std::cin>>testcases;
	long long int* answers = new long long int[testcases];
	for(int i = 0; i<testcases; i++){
		long long int length;
		std::cin>>length;
		//std::cout<<"\n"<<length;
		long long int* array = new long long int[length];
		for(int i = 0; i<length; i++){
			long long int input1;
			std::cin>>input1;
			array[i] = input1;
		}
		answers[i] = mergeS(array, length);
	}
	std::cout<<"\n";
	for(int i = 0; i<testcases; i++){
		std::cout<<answers[i]<<"\n";
	}
}
