template<class T> struct Seg_Tree {
	const T DEFAUL = 0;
	vector<T> st, arr;
	int len = 0;

	void init(int l) {
		len = l;
		st.resize(4*l + 10, DEFAUL);
		// arr.resize(l + 10);
		// FOR(i, 1, n) cin >> arr[i];
		build(1, 1, len);
	}
	T cb(T& a, T& b) { // combine to node
        return a + b;
    }
	void build(int v, int l, int r) {
		if (l == r) {
			st[v] = arr[l];
		} else {
			int mid = (l + r) / 2;
			build(2*v, l, mid);
			build(2*v + 1, mid + 1, r);
			// st[v] = cb(st[2*v], st[2*v + 1]);
		}
	}
	void print_st() {
		int w = 2*log2(4*len);
		cout << string(log2(len) + w, ' ').c_str();
		for (int i = 1; i < 2*len; i++) {
			if (__builtin_popcount(i) == 1 && i != 1) {
				cout << "\n" << string(log(len) - log2(i) + w, ' ').c_str();
				w -= 2;
			} 
			cout << string(w, ' ').c_str() << st[i];
		}
		cout << "\n";
	}
    // * Description: 1D point update and range query
    // * Verification: https://cses.fi/problemset/task/1649
	void upd(int pos, T val) {
		upd(pos, val, 1, 1, len);
	}
	void upd(int pos, T val, int v, int l, int r) {
		if (l > pos or pos > r) return;
		else if (l == r) {
			st[v] += val;
		} else {
			int mid = (l + r) / 2;
			upd(pos, val, 2*v, l, mid);
			upd(pos, val, 2*v + 1, mid + 1, r);
			st[v] = cb(st[2*v], st[2*v + 1]);
		}
	}
	T get(int lx, int rx) { // query in range[l, r]
		// O(log(len))
		return get(lx, rx, 1, 1, len);
	}
	T get(int lx, int rx, int v, int l, int r) {
		if (r < lx or rx < l) return DEFAUL;
		else if (lx <= l && r <= rx) {
			return st[v];
		} else {
			int mid = (l + r) / 2;
			T left = get(lx, rx, 2*v, l, mid);
			T right = get(lx, rx, 2*v + 1, mid + 1, r);
			return cb(left, right);
		}
	}
    
	// * Description: 1D range update and point query
	// * Verification: https://cses.fi/problemset/task/1651
	void upd(int lx, int rx, T val) {
		upd(lx, rx, val, 1, 1, len);
	}
	void upd(int lx, int rx, T val, int v, int l, int r) {
		if (r < lx or rx < l) return;
		else if (lx <= l && r <= rx) {
			st[v] += val;
		} else {
			int mid = (l + r) / 2;
			upd(lx, rx, val, 2*v, l, mid);
			upd(lx, rx, val, 2*v + 1, mid + 1, r);
			// st[v] = cb(st[2*v], st[2*v + 1]);
		}
	}
	T get(int pos) {
		return get(pos, 1, 1, len);
	}
	T get(int pos, int v, int l, int r) {
		if (l > pos or pos > r) return DEFAUL;
		else if (l == r) return st[v];
		else {
			int mid = (l + r) / 2;
			T left = get(pos, 2*v, l, mid);
			T right = get(pos, 2*v + 1, mid + 1, r);
			return st[v] + cb(left, right);
		}
	}
};
