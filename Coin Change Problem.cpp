#include <bits/stdc++.h>
using namespace std;

int coin(int arr[],int n,int sum){
    int tmp[n+1][sum+1];
    for(int i=0;i<=n;i++){
        tmp[i][0]=1;
    }
    for(int i=1;i<=sum;i++){
        tmp[0][i]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(arr[i-1]>j){
                tmp[i][j]=tmp[i-1][j];
            }
            else{
                tmp[i][j]=tmp[i-1][j]+tmp[i][j-arr[i-1]];
            }
        }
    }
    return tmp[n][sum];
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n,sum;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    cin>>sum;
	    cout<<coin(arr,n,sum)<<"\n";
	}
	return 0;
}
