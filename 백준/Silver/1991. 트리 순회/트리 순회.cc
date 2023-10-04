#include <iostream>
#include <map>

using namespace std;

struct Node {
	char left;
	char right;
};

map<char, Node> m;

void preOrder(char node) {
	if (node == '.')
		return;

	cout << node;
	preOrder(m[node].left);
	preOrder(m[node].right);
}

void inOrder(char node) {
	if (node == '.')
		return;

	inOrder(m[node].left);
	cout << node;
	inOrder(m[node].right);
}

void postOrder(char node) {
	if (node == '.')
		return;

	postOrder(m[node].left);
	postOrder(m[node].right);
	cout << node;
}

int main() {
	int n;
	char index, left, right;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> index >> left >> right;
		m[index].left = left;
		m[index].right = right;
	}

	preOrder('A');
	cout << '\n';
	inOrder('A');
	cout << '\n';
	postOrder('A');

	return 0;
}