#include <iostream>
using namespace std;
/*
 * http://www.geeksforgeeks.org/dynamic-programming-subset-sum-problem/
 */
bool subsetsum(int nums[], int n, int sum){
	//The value of subset[i][j] will be true if there is a subset of set[0..j-1] 
	//with sum equal to i., otherwise false. Finally, we return subset[sum][n]
	bool **subset = new bool*[sum+1];//[n] ;//= {false};
	for(int i = 0; i < sum+1; i++){
		subset[i] = new bool[n];
		for(int j = 0 ; j < n ;j++)
			subset[i][j] = false;
	}
	for(int i = 0; i < n;i++)
		subset[0][i] = true;
	if(nums[0] <= sum)
		subset[nums[0]][0] = true;

	for(int i = 0; i < sum + 1; i ++){
		for(int j = 1 ;  j < n; j++){
			subset[i][j] = subset[i][j- 1];
			if(i >= nums[j]){
				subset[i][j] = subset[i][j]||subset[i - nums[j]][j-1];
			}
		}
	}
	 for (int i = 0; i <= sum; i++)
     {
       for (int j = 0; j < n; j++)
          printf ("%4d", subset[i][j]);
       printf("\n");
     }
	return subset[sum][n-1];
}
int subsummain(){
	int set[] = {3, 34, 4, 12, 5, 2};
  int sum = 9;
  int n = sizeof(set)/sizeof(set[0]);
  if (subsetsum(set, n, sum) == true)
     printf("Found a subset with given sum");
  else
     printf("No subset with given sum");
  return 0;
}