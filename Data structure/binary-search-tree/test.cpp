#include<iostream>
#include"bst.h"
using namespace std;
int main(){
	freopen("C://Code//Data structure//binary-search-tree//input.in", "r", stdin);
	//freopen("C://Code//Data structure//binary-search-tree//output.out", "w", stdout);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		BST<int> bst;
		int num;
		while (n--)
		{
			cin >> num;
			bst.Insert(num);
		}
		bst.in_order_walk(bst.get_root());
		cout << endl;
		int op;
		cin >> op;
		while (op--) {
			cin >> num;
			bst.Delete(num);
			bst.in_order_walk(bst.get_root());
			cout<<endl;
		}
	}

    return 0;
}

/*
1
6
4 3 2 6 5 10
5
6

1
4
5 3 2 10
5
5


5
6
1 4 3 2 5 6
5
4

2
9
1 -2 6 3 8 2 3 7 9
5
6

*/