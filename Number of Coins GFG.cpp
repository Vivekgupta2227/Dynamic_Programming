#include <bits/stdc++.h>
using namespace std;

int minCoin(int arr[],int n,int sum){
    int tmp[n+1][sum+1];
    for(int i=0;i<=n;i++){
        tmp[i][0]=0;
    }
    for(int i=1;i<=sum;i++){
        tmp[0][i]=INT_MAX-1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(j%arr[0]==0){
                tmp[i][j]=j/arr[0];
            }
            if(arr[i-1]>j){
                tmp[i][j]=tmp[i-1][j];
            }
            else{
                tmp[i][j]=min(tmp[i][j-arr[i-1]]+1,tmp[i-1][j]);
            }
        }
    }
    return tmp[n][sum];
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,sum;
	    cin>>sum>>n;
	    int arr[n];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    int x=minCoin(arr,n,sum);
	    if(x==INT_MAX-1){
	        cout<<"-1"<<"\n";
	    }
	    else{
	        cout<<x<<"\n";   
	    }
	}
	return 0;
}
