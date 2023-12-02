#include <bits/stdc++.h>

using namespace std;

int Removalgame(int l, int h, bool chance, vector<long long int> A){

    int ans = 0;
    if(chance){
        ans = max(Removalgame(l,h-1,false,A)+A[h],Removalgame(l+1,h,false,A)+A[l]);
    }
    else{
        ans = max(Removalgame(l,h-1,true,A)+A[h],Removalgame(l+1,h,true,A)+A[l]);
        
    }
    return ans;
}

int main(){

    int n; cin >> n;

    vector<long long int> A(n);
    for(int i = 0; i < n; i++) {
        cin >> A[i];
    }

    cout << Removalgame(0,n-1,true,A) << endl;
}