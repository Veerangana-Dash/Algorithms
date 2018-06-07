//Dynamic Programming implementation of Edit Distance problem.

/*Given two strings str1 and str2 and below operations that can 
performed on str1. Find minimum number of edits 
(operations) required to convert ‘str1’ into ‘str2’
Insert
Remove
Replace
*/

#include<stdio.h>
#include<string.h>

int min1(int a,int b)
{
	return (a<b?a:b);
}

int min(int x, int y,int z)
{
	return min1(min1(x,y),z);
}


int ED(char *str1,char *str2,int m,int  n)
{
	int T[m+1][n+1];
	int i,j;
	for(i=0;i<=m;i++)
	{
		for(j=0;j<=n;j++)
		{
			if(i==0)
				T[i][j]=j;
			else if(j==0)
				T[i][j]=i;
			else if(str1[i-1]==str2[j-1])
				T[i][j]=T[i-1][j-1];
			else
				T[i][j]=1+min(T[i][j-1],T[i-1][j],T[i-1][j-1]);
		}
	}
	return T[i][j];
}

int main()
{
	char str1[]="hello";
	char str2[]="heya";

	printf("Minimum no of operations required is %d",ED(str1,str2,strlen(str1),strlen(str2)));
		return 0;
}