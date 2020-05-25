#include<bits/stdc++.h>
using namespace std;
bool tmp[1001][1001];

int minDiff(int arr[],int n,int sum){
    vector<int>v;
    for(int i=0;i<=n;i++){
        tmp[i][0]=true;
    }
    for(int i=1;i<=sum;i++){
        tmp[0][i]=false;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(arr[i-1]>j){
                tmp[i][j]=tmp[i-1][j];
            }
            else{
                tmp[i][j]=tmp[i-1][j-arr[i-1]]||tmp[i-1][j];
            }
        }
    }
    for(int i=0;i<=sum/2;i++){
        if(tmp[n][i]==true){
                v.push_back(i);
            }
    }
    int diff=INT_MAX;
    for(int i=0;i<v.size();i++){
        diff=min(diff,sum-2*v[i]);
    }
    return diff;
}

int main(){
    int n,arr[100000];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    cout<<minDiff(arr,n,sum);
    return 0;
}
