#include <bits/stdc++.h>
using namespace std;

int max(vector<int>v,int n){
    int tmp[4][n+1];
    for(int i=0;i<=v.size();i++){
        for(int j=0;j<=n;j++){
            if(j==0){
                tmp[i][j]=0;
            }
            else if(i==0){
                if(j%v[i]==0){
                    tmp[i][j]=j/v[i];
                }
                else{
                    tmp[i][j]=0;
                }
            }
            else{
            if(v[i-1]>j){
                tmp[i][j]=tmp[i-1][j];
            }
            else{
                if(tmp[i-1][j]==0&&tmp[i][j-v[i-1]]==0&&j-v[i-1]!=0){
                    tmp[i][j]=0;
                }
                else{
                tmp[i][j]=max(1+tmp[i][j-v[i-1]],tmp[i-1][j]);
            }}}
        }
    }
    return tmp[3][n];
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int x,y,z,n;
	    vector<int>v;
	    cin>>n;
	    cin>>x>>y>>z;
	    v.push_back(x);
	    v.push_back(y);
	    v.push_back(z);
	    cout<<max(v,n)<<"\n";
	}
	return 0;
}
