//Dynamic Programming implementation of SubsetSum problem.

/* Given a set of non-negative integers, and a value sum, 
determine if there is a subset of the given set with sum
equal to given sum. */


#include<stdio.h>
#include<stdlib.h>

int isSubsetSum(int set[],int n,int sum)
{
	int subset[n+1][sum+1];
	int i,j;

	//sum=1, then true
	for(i=0;i<=n;i++)
		subset[i][0]=1;

	//set empty for nonzero sum
	for(i=1;i<=sum;i++)
		subset[0][i]=0;

	//fill in bottom up manner
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=sum;j++) 
		{
			if(j<set[i-1])
				subset[i][j]=subset[i-1][j] || subset[i-1][j-set[i-1]];
			

		}
	}
return subset[n][sum];
}

int main()
{
	int set[]={3,34,4,12,5,2};
	int sum=9;
	int n=sizeof(set)/sizeof(set[0]);
	printf("%d",isSubsetSum(set,n,sum));
	if(isSubsetSum(set,n,sum)==1)
		printf("Found subset");
	else
		printf("No subset\n");
	return 0;
}
