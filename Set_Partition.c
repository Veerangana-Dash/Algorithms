//Dynamic Programming implementation of Set Partition problem.

/*Given a set of integers, the task is to divide it into two 
sets S1 and S2 such that the absolute difference
between their sums is minimum.*/

#include<stdio.h>
#include<limits.h>
#include<stdlib.h>


int minPart(int ar[],int n)
{
	int i,j,sum=0;
	for(i=0;i<n;i++)
		sum +=ar[i];
	int T[n+1][sum+1];

	for(i=0;i<=n;i++)
		T[i][0]=1;

	for(i=1;i<=sum;i++)
		T[0][i]=0;

	//Fill partition table in bottom up manner
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=sum;j++)
		{
			//i'th element is excluded
			T[i][j]=T[i-1][j];

			//i'th element is included
			if(ar[i-1]<=j)
				T[i][j] |= T[i-1][j-ar[i-1]];
		}
	}

	int diff=INT_MAX;
	for(j=sum/2;j>=0;j--)
	{
		if(T[n][j]==1)
		{
			diff=sum-2*j;
			break;
		}
	}
	return diff;
}

int main()
{
	int ar[]={3,1,4,2,2,1};
	int n=sizeof(ar)/sizeof(ar[0]);
	printf("The minimum difference between 2 sets is %d",minPart(ar,n));
	return 0;

}