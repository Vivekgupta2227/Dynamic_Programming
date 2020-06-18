#include <bits/stdc++.h>
using namespace std;
int static tt[1001][1001];
int solve(int arr[100],int i,int j){
    if(i>=j){
        return 0;
    }
    if(tt[i][j]!=-1){
        return tt[i][j];
    }
    int mn=INT_MAX;
    for(int k=i;k<=j-1;k++){
        int tmp = solve(arr,i,k)+solve(arr,k+1,j)+(arr[i-1]*arr[k]*arr[j]);
        if(tmp<mn){
            mn=tmp;
        }
    }
    return tt[i][j] = mn;
}   

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int arr[100],n;
	    cin>>n;
	    memset(tt,-1,sizeof(tt));
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    cout<<solve(arr,1,n-1)<<"\n";
	}
	return 0;
}
