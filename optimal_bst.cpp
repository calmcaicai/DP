#include <iostream>
using namespace std;
/*
 * http://www.geeksforgeeks.org/dynamic-programming-set-24-optimal-binary-search-tree/
 */
 //recursive implementation
int *freq;
int *sum_tillnow;
int recurOptCost(int i , int j){
	if(i >= j)
		return 0;
	if(i == j - 1){
		//cout<<i<<","<<j<<":::"<<freq[i]<<endl;
		return freq[i];
	}
	
	int opt_cost = sum_tillnow[j] - sum_tillnow[i];
	//cout<<i<<" "<<j <<opt_cost<<endl;
	int min = INT_MAX;
	for(int r = i; r < j;  r++){
		int subopt = recurOptCost(i,r) + recurOptCost(r + 1, j);
		if(subopt < min)
			min = subopt;
	}
	cout<<i<<","<<j<<":::"<<opt_cost<<"+"<<min<<endl;
	return opt_cost + min;

}
void dpOptCost(int n){
	//cost[i][j] from i to j
	int **cost = new int*[n];
	for(int i =0;i<n;i++){
		cost[i] = new int[n];
		cost[i][i] = freq[i];
	}
	
	for(int step = 1; step < n;step++){
		for(int i = 0; i < n - step;i++){//
			int j =  i + step;
			if(j > n){
				cout<<"---"<<j<<endl;
				return;
			}
			int min = INT_MAX;
			for(int r = i; r <=j;r++){
				int temp = ((r > i)? cost[i][r-1]:0) +
							((r < j)? cost[r+1][j]:0) +
							sum_tillnow[j + 1] - sum_tillnow[i];
				cout<<i<<","<<j<<":::"<<sum_tillnow[j + 1] - sum_tillnow[i]<<endl;
				if(temp < min){
					min = temp;
				}
			}
			cost[i][j] = min;
		}
	}
	cout<<cost[0][n-1]<<endl;
}
int opttmain(){
	int temp[3] = {34, 8, 50};
	int n = 3;
	freq = temp;

	sum_tillnow = new int[n + 1];
	sum_tillnow[0] = 0;
	for(int i = 1 ; i <n + 1; i++)
		sum_tillnow[i] = sum_tillnow[i - 1] + freq[i - 1];
	for(int i = 0 ; i <n + 1; i++)
		cout<<sum_tillnow[i]<<endl;
	dpOptCost(3);
	
	//cout<<recurOptCost(0,n)<<endl;
	return 0;
}