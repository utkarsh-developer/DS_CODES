#include<bits/stdc++.h>
#define ll long long int
using namespace std;

class segtree
{
private:
	int sz;
	std::vector<long long> sums;
public:
	segtree(int n){
		sz = 1;
		while(sz < n)sz *= 2;
		sums.assign(2*sz, 0LL);
	}

	void build(vector<int>&a, int x, int lx, int rx){
		if(rx-lx == 1){
			if(lx < (int)a.size()){
				sums[x] =a[lx];	
			}
			return;
		}

		int mid = (lx+rx)/2;

		build(a, 2*x+1, lx, mid);
		build(a, 2*x+2, mid, rx);
		sums[x] = sums[2*x+1] + sums[2*x+2];
	}

	void build(vector<int>&a){
		build(a, 0, 0, sz);
	}

	void set(int i, int v, int x, int lx, int rx){
		if(rx-lx == 1){
			sums[x] = v;
			return;
		}

		int mid = (lx+rx)/2;

		if(i < mid){
			set(i, v, 2*x+1, lx, mid);
		}
		else{
			set(i, v, 2*x+2, mid, rx);
		}
		sums[x] = sums[2*x+1] + sums[2*x+2];
	}

	void set(int idx, int v){
		set(idx, v, 0, 0, sz);
	}

	long long sum(int l, int r, int x, int lx, int rx){
		/// Do not intersect
		if(lx >= r || l >= rx)return 0;

		if(lx >= l && rx <= r){
			return sums[x];
		}

		int mid = (lx+rx)/2;
	
		long long s1 = sum(l, r, 2*x+1, lx, mid);
		long long s2 = sum(l, r, 2*x+2, mid, rx);
		return s1+s2;
	}

	long long sum(int l, int r){
		return sum(l, r, 0, 0, sz);
	}

};


int main(){


	  #ifndef ONLINE_JUDGE
    freopen("C:/Codeforces/input.txt", "r", stdin);
    freopen("C:/Codeforces/output.txt", "w", stdout);
    #endif

	int n, q;

	cin >> n >> q;
	segtree st(n);

	vector<int>v(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}

	st.build(v);

	while(q--){
		int op;
		cin >> op;
		if(op == 1){
			int i, v;
			cin >> i >> v;
			st.set(i, v);
		}	
		else{
			int l, r;
			cin >> l >> r;
			cout << st.sum(l, r) << "\n";
		}
	}

}