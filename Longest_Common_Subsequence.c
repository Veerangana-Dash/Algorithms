//Dynamic Programming implementation of Longest Common Subsequence problem in C

#include<stdio.h>
#include<string.h>

int max(int a,int b);

int LCS(char *x, char *y, int m, int n)
{
	int L[m+1][n+1];
	int i,j;

	//build table in bottom up manner
	for(i=0;i<=m;i++)
	{
		for(j=0;j<=n;j++)
		{
			if(i==0 || j==0)
				L[i][j]=0;
			else if(x[i-1]==y[j-1])
				L[i][j]=L[i-1][j-1]+1;
			else
				L[i][j]=max(L[i-1][j],L[i][j-1]);
		}
	}
	return L[m][n];
}

int max(int a,int b)
{
	return (a>b)?a:b;
}

int main()
{
	char x[]="ABCDHKT";
	char y[]="ADHEKY";

	int m=strlen(x);
	int n=strlen(y);

	printf("Length of LCS is %d", LCS(x,y,m,n));
	return 0;
}