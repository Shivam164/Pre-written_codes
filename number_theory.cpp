#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename num_t>
using ordered_set = tree<num_t, null_type, less_equal<num_t>, rb_tree_tag, tree_order_statistics_node_update>;
priority_queue<pair<int,int>, vector<pair<int,int> > , greater<pair<int,int> > > p;


void fastio(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
/****************************************/

/* NUMBER THEORY */
// => Sieve over range
const int N = 20;
vector<int> f(N);
void factors(){
    for(int i = 2;i<N;i++){
        if(f[i] == 0){
            for(int j = i*i;j<N;j+=i){
                f[j] = i;
            }
        }
    }
}

// => Frequency of every prime factor
vector<pair<int,int>> primeFactorCount(int k){
    vector<pair<int,int> > v;
    for(int i = 2;i*i<=k;i++){
        if(k%i == 0){
            int count = 0;
            while(k%i == 0){
                k/=i;
                count++;
            }
            v.push_back({i,count});
        }
    }

    if(k!=1)v.push_back({k,1});

    return v;
}

// => Euler totient function [to know no. of number which are coprime with n in the range 1 to n - 1]
// Time complexity O(nlog(logn))
vector<int> fillPhi(){
    vector<int> phi(200010);
    for(int i = 0;i<200010;i++){
        phi[i] = i;
    }

    for(int i = 2;i<200010;i++){
        if(phi[i] == i){
            for(int j = i*i;j<200010;j+=i){
                phi[j] -= phi[j]/i; 
            }
        }
        
    }
    return phi;
}

int32_t main() {
    fastio();

    factors();
    for(int i = 1;i<N;i++){
        cout<<f[i]<<" ";
    }



}