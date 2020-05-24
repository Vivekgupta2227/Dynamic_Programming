#include<bits/stdc++.h>
using namespace std;
int tmp[1001][1001];
int countsubset(int arr[],int n,int sum){
    if(sum==0)
      return tmp[n][sum]=1;
    if(n==0)
      return tmp[n][sum]=0;
    if(tmp[n][sum]!=-1)
      return tmp[n][sum];
    else{
        if(arr[n-1]>sum)
          return tmp[n][sum]=countsubset(arr,n-1,sum);
        else{
          return tmp[n][sum]=countsubset(arr,n-1,sum)+countsubset(arr,n-1,sum-arr[n-1]);
        }
   }
}
void print(int row, int col){
    for(int i = 0; i<row; i++){
        for(int j = 0; j<col; j++){
            cout<<tmp[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    memset(tmp, -1, sizeof(tmp));
    int n,sum,arr[100000];
    cin>>n>>sum;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<countsubset(arr,n,sum)<<endl;
    print(n+1,sum+1);
    return 0;
}
