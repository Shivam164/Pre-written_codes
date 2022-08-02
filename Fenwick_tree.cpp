#include<bits/stdc++.h>
using namespace std;


class FenwickTree {
public:
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> a) : FenwickTree(a.size()) {
        for (int i = 0; i < a.size(); i++)
            update(i, a[i]);
    }

    // bit[r] = sum[ r & (r + 1) . . . . . . r ]
    int sum(int r) {
        int currSum = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            currSum += bit[r];
        return currSum;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void update(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};


int main(){

	

}