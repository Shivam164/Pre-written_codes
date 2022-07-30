#include<bits/stdc++.h>
using namespace std;


// class SGTree{

// 	vector<int> seg, lazy;
// public:
// 	SGTree(int n){
// 		seg.resize(4*n + 1);
// 		lazy.resize(4*n + 1);
// 	}

// 	// BUILDING SEGMENT TREE
// 	void build(int ind, int low, int high, int ar[]){
// 		if(low == high){
// 			seg[ind] = ar[low];
// 			return;
// 		}

// 		int mid = (low + high)/2;

// 		build(2*ind + 1, low, mid, ar);
// 		build(2*ind + 2, mid + 1, high, ar);

// 		seg[ind] = min(seg[2*ind + 1], seg[2*ind + 2]);
// 	}

// 	// QUERYING FROM SEGMENT TREE
// 	int query(int ind, int low, int high, int query_low, int query_high){
// 		// NO INTERSECTION
// 		if(low > query_high || query_low > high){
// 			return INT_MAX;
// 		}

// 		// COMPLETE OVERLAP
// 		if(low >= query_low && high <= query_high){
// 			return seg[ind];
// 		}

// 		int mid = (low + high)/2;

// 		int left = query(2*ind + 1, low, mid, query_low, query_high);
// 		int right = query(2*ind + 2, mid + 1, high, query_low, query_high);

// 		return min(left, right);
// 	}

// 	void update(int ind, int low, int high, int arr_ind, int val){
// 		if(low == high){
// 			seg[ind] = val;
// 			return;
// 		}

// 		int mid = (low + high)/2;

// 		if(arr_ind <= mid){
// 			update(2*ind + 1, low, mid, arr_ind, val);
// 		}else{
// 			update(2*ind + 2, mid + 1, high, arr_ind, val);
// 		}

// 		seg[ind] = min(seg[2*ind + 1], seg[2*ind + 2]);
// 	}
// };

class SGTree{

	vector<int> seg, lazy;
public:
	SGTree(int n){
		seg.resize(4*n + 1);
		lazy.resize(4*n + 1);
	}

	// BUILDING SEGMENT TREE
	void build(int ind, int low, int high, int ar[]){
		if(low == high){
			seg[ind] = ar[low];
			return;
		}

		int mid = (low + high)/2;

		build(2*ind + 1, low, mid, ar);
		build(2*ind + 2, mid + 1, high, ar);

		seg[ind] = seg[2*ind + 1] + seg[2*ind + 2];
	}

	// QUERYING FROM SEGMENT TREE
	int query(int ind, int low, int high, int query_low, int query_high){

		if(lazy[ind] != 0){
			seg[ind] += (high - low + 1)*lazy[ind];
			if(low != high){
				lazy[2*ind + 1] += lazy[ind];
				lazy[2*ind + 2] += lazy[ind];
			}
			lazy[ind] = 0;
		}

		// NO INTERSECTION
		if(low > query_high || query_low > high){
			return 0;
		}

		// COMPLETE OVERLAP
		if(low >= query_low && high <= query_high){
			return seg[ind];
		}

		int mid = (low + high)/2;

		int left = query(2*ind + 1, low, mid, query_low, query_high);
		int right = query(2*ind + 2, mid + 1, high, query_low, query_high);

		return left + right;
	}

	void update(int ind, int low, int high, int low_update, int high_update, int val){

		if(lazy[ind] != 0){
			seg[ind] += (high - low + 1)*lazy[ind];
			if(low != high){
				lazy[2*ind + 1] += lazy[ind];
				lazy[2*ind + 2] += lazy[ind];
			}
			lazy[ind] = 0;
		}

		// NO OVERLAP
		if(low > high_update || low_update > high){
			return;
		}

		// COMPLETE OVERLAP
		if(low >= low_update && high <= high_update){
			seg[ind] += (high - low + 1)*val;
			if(low != high){
				lazy[2*ind + 1] += val;
				lazy[2*ind + 2] += val;
			}
			return;
		}

		// PARTIAL OVERLAP
		int mid = (low + high)/2;

		update(2*ind + 1, low, mid, low_update, high_update, val);
		update(2*ind + 2, mid + 1, high, low_update, high_update, val);

		seg[ind] = seg[2*ind + 1] + seg[2*ind + 2];

	}
};


int main(){

	int n;
	cin>>n;
	int ar[n];

	for(int i = 0;i<n;i++)cin>>ar[i];

	SGTree s(n);

	s.build(0, 0, n - 1, ar);

	int q;
	cin>>q;

	while(q--){
		int type;
		cin>>type;
		if(type == 1){
			int l, r;
			cin>>l>>r;
			cout<<s.query(0, 0, n - 1, l, r)<<endl;
		}else{
			int l, r, val;
			cin>>l>>r>>val;
			s.update(0, 0, n - 1, l, r, val);
		}
	}

}