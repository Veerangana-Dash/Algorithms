//Dynamic Programming implementation of Longest Increasing Subsequence problem.

/*The Longest Increasing Subsequence (LIS) problem is to find the length of the longest 
subsequence of a given sequence such that all elements of the 
subsequence are sorted in increasing order.*/

#include<stdio.h>
#include<stdlib.h>

int LIS(int ar[],int n)
{
	int *lis,i,j,max=0;
	lis=(int*)malloc (sizeof(int)*n);
	for(i=0;i<n;i++)
		lis[i]=1;

	//Compute in bottom up manner
	for(i=1;i<n;i++)
		for(j=0;j<i;j++)
			if(ar[i]>ar[j] && lis[i]<lis[j]+1)
				lis[i]=lis[j]+1;

	for(i=0;i<n;i++)
		if(max<lis[i])
			max=lis[i];

	free(lis);
	return max;
}

int main()
{
	int ar[]={1,5,8,3,9,6};
	int n=sizeof(ar)/sizeof(ar[0]);
	printf("Length of LIS is %d",LIS(ar,n));
	return 0;
}
