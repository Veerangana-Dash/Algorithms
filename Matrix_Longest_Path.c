//Dynamic Programming implementation of Matrix Longest Path problem.

/*Given a n*n matrix where all numbers are distinct, find the maximum 
length path (starting from any cell) such that all cells 
along the path are in increasing order with a difference of 1.*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int LongestPath(int i,int j, int mat[][],int T[][],int n)
{
	//base case
	if(i<0 || i>=n || j<0 ||j>=n)
		return 0;

	//if already solved
	if(T[i][j]!=-1)
		return T[i][j];

	//adjacent moves
	if(j<n-1 && ((mat[i][j]+1)==mat[i][j+1]))
		return T[i][j]=1+LongestPath(i,j+1,mat,T,n);
	if(j>0 && ((mat[i][j]+1)==mat[i][j-1]))
		return T[i][j]=1+LongestPath(i,j+1,mat,T,n);
	if(i>0 && ((mat[i][j]+1)==mat[i-1][j]))
		return T[i][j]=1+LongestPath(i,j+1,mat,T,n);
	if(i<n-1 && ((mat[i][j]+1)==mat[i+1][j]))
		return T[i][j]=1+LongestPath(i,j+1,mat,T,n);

	//if no adjacent cell is 1 greater
	return T[i][j]=1;
}

int LongestOverall(int *mat,int n)
{
	int result=1;

	int T[n][n],i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			T[i][j]=-1;
		}
	}

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(T[i][j]==-1)
				LongestPath(i,j,mat,T,n);
			result=max(result,T[i][j]);
		}
	}
	return result;
}

int main()
{
	int mat[][]={{1,2,9},{5,3,8},{4,6,7}};
	int n=3;
	printf("Longest path lenght is %d",LongestOverall(mat,n));
	return 0;
}