//#include <iostream>
//#include <cstdio>
//using namespace std;
//bool mp[20010][20010];
//int m, n, q;
//bool check(int aim, int b) {
//	if (mp[b][aim])return 1;
//	for (int i = 1; i <= n; ++i) {
//		bool status = false;
//		if (mp[b][i])status = check(aim, i);
//		if (status)return 1;
//	}
//	return 0;
//}
//int main() {
//	
//	cin >> n >> m;
//	ios::sync_with_stdio(0);
//	while (m--) {
//		int a, b;
//		scanf("%d%d", &a, &b);
//		mp[a][b] = mp[b][a] = 1;
//	}
//	cin >> q;
//	while (q--) {
//		int c, d;
//		scanf("%d%d", &c, &d);
//		cout << (check(c,d) ? "Yes" : "No") << endl;
//	}
//	return 0;
//}
///以上代码为未学习并查集时所写，


#include <iostream>
using namespace std;
int m, n, q;
int st[20010];
int find(int x) {
	if (x == st[x])return x;//如果所在的集合是自己本身（要么只有自己一个元素，要么自己是集合的“代表”），则返回自己
	st[x] = find(st[x]);//否则的话则更新x位置所在的集合，例如x=5,st[x]=3时，查询位置3属于哪个集合...返回给st[x](以递归的方式)
	return st[x];//返回位置x所在的集合编号.
}
void merge(int a, int b) {
	int setA = find(a), setB = find(b);
	if (setA != setB)st[setA] = st[setB];
	//由于是单向操作的，所以不用担心是否会在查找过程中死循环，比如st[3]=5,st[5]=3
}
int main(){
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)st[i] = i;
	while (m--) {
		int a, b;
		scanf("%d%d", &a, &b);
		merge(a, b);
	}
	cin >> q;
	while (q--) {
		int c, d;
		scanf("%d%d", &c, &d);
		printf("%s\n", (find(c) == find(d) ? "Yes" : "No"));
		//卡cin,cout
	}
	return 0;
}