#include<bits/stdc++.h>
using namespace std;
const int N = 200010;
int parent[N];
int find(int a){ // iterative way to find parent
	while(parent[a]>0)
		a = parent[a];
	return a;
}

int find_recursion(int a){ // find parent using recursion
	if(parent[a]<0)return a;
	int k = find_recursion(parent[a]);
	parent[a] = k;
	return k;
}

// For using path compression technique we uses an array that will keep a parent
// of the set and in parent, we will keep a negative number that will tell the size of the set

int find_with_pathCompression(int a){ // returning parent with compression of path 
	vector<int> v;
	while(parent[a]>0){
		v.push_back(a);
		a = parent[a];
	}
	for(int i = 0;i<v.size();i++){
		parent[v[i]] = a;
	}
	return a;
}

void merge(int a,int b){ // to get the union of two different sets
	a = find(a);
	b = find(b);
	
	if(a==b)return ;
	if(parent[a]>parent[b]){ // this if condition is to merge set with smaller size into set with larger size
		parent[a]+=parent[b];
		parent[b] = a;
	}else{
		parent[b]+=parent[a];
		parent[a] = b;	
	}
}
int main(){
	fill(parent,parent+1001,-1);
}