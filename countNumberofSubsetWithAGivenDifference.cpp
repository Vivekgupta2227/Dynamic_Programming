#include<bits/stdc++.h>
using namespace std;
int tmp[1001][1001];

int minDiff(int arr[],int n,int s1){
    for(int i=0;i<=n;i++){
        tmp[i][0]=1;
    }
    for(int i=1;i<=s1;i++){
        tmp[0][i]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=s1;j++){
            if(arr[i-1]>j){
                tmp[i][j]=tmp[i-1][j];
            }
            else{
                tmp[i][j]=tmp[i-1][j-arr[i-1]]+tmp[i-1][j];
            }
        }
    }
    return tmp[n][s1];
}

int main(){
    int n,arr[100000],diff;
    cin>>n>>diff;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    int s1=(sum-diff)/2;
    cout<<minDiff(arr,n,s1);
    return 0;
}
