#include <bits/stdc++.h>
using namespace std;
int static t[11][51];

int eggDrop(int n,int k){
    if(k==0||k==1){
        return k;
    }
    if(n==1){
        return k;
    }
    if(t[n][k]!=-1){
        return t[n][k];
    }
    int mn=INT_MAX;
    for(int i=1;i<=k;i++){
        int ans = 1+ max(eggDrop(n-1,i-1),eggDrop(n,k-i));
        mn=min(ans,mn);
    }
    t[n][k]=mn;
    return t[n][k];
}

int main() {
	//code
	int tt;cin>>tt;
	while(tt--){
	    int n,k;
	    cin>>n>>k;
	    memset(t,-1,sizeof(t));
	    int ans = eggDrop(n,k);
	    cout<<ans<<"\n";
	}
	return 0;
}
