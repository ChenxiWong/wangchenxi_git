/*
 * 
 */ 
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct TreeNode {
	TreeNode* left;
	TreeNode* right;
	int val;
	TreeNode(int x) : val(x), left(NULL), right(NULL) { }
};

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x) , next(NULL) { }
};

void printTree(TreeNode* p) {
	if(p == NULL) return ;
	vector<TreeNode*> vec;
	vec.push_back( p );
	int last = 1;
	int cur = 0;
	while(cur < vec.size()){
		last = vec.size();
		while( cur < last ) {
			cout << vec[cur]->val << " ";
			if(vec[cur]->left) vec.push_back( vec[cur]->left );
			if(vec[cur]->right) vec.push_back( vec[cur]->right );
			cur ++;
		} 
		cout << endl;
	}
	cout << endl;
}

void printList( ListNode* p ) {
	ListNode* i = p;
	while(i) {
		cout << i->val << " ";
		i = i->next;
	}
	cout << endl;	
}



int main() {

	return 0;
}
