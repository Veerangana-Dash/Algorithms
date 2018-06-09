//Dynamic Programming implementation of Distance Cover problem.

/*Given a distance ‘dist, count total number of ways
 to cover the distance with 1, 2 and 3 steps.*/

#include<stdio.h>

int countWays(int dist)
{
	int count[dist+1],i;
	count[0]=1;
	count[1]=1;
	count[2]=2;

	for(i=3;i<=dist;i++)
		count[i]=count[i-1]+count[i-2]+count[i-3];
	return count[dist];
}

int main()
{
	int dist=4;
	printf("Number of ways to cover a distance 4 is %d",countWays(dist));
	return 0;
}