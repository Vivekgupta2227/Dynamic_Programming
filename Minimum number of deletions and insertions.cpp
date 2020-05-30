#include <bits/stdc++.h>
using namespace std;

int minDel(string s1,string s2,int n,int m){
    int tmp[n+1][m+1];
    int total=0;
    for(int i=0;i<=n;i++){
        tmp[i][0]=0;
    }
    for(int i=0;i<=m;i++){
        tmp[0][i]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                tmp[i][j]=1+tmp[i-1][j-1];
            }
            else{
                tmp[i][j]=max(tmp[i-1][j],tmp[i][j-1]);
            }
        }
    }
    return tmp[n][m];
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n,m;
	    string s1,s2;
	    cin>>n>>m;
	    cin>>s1;
	    cin>>s2;
	    int total=n+m-2*minDel(s1,s2,n,m);
	    cout<<total<<"\n";
	}
	return 0;
}
