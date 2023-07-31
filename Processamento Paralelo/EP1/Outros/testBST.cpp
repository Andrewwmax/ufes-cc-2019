#include <iostream>

using namespace std;

struct node {
   string val;
   node* left;
   node* right;
};

node* createNewNode(string x) {
	node* nn = new node;
	nn->val = x;
	nn->left  = nullptr;
	nn->right = nullptr;

	return nn;
}

void bstInsert(node* &root, string x) {
	if(root == nullptr) {
		root = createNewNode(x);
		return;
	}

	if(x.compare(root->val) < 0) {
		if(root->left == nullptr) {
			root->left = createNewNode(x);
			return;
		} else bstInsert(root->left, x);
	}

	if(x.compare(root->val) > 0) {
		if(root->right == nullptr) {
			root->right = createNewNode(x);
			return;
		} else bstInsert(root->right, x);
	}
}

bool busca(node *root, string x){
    if(root == NULL) return false;
    else if(x.compare(root->val) < 0) return busca(root->left, x);
    else if(x.compare(root->val) == 0) return true;
    else if(x.compare(root->val) > 0) return busca(root->right, x);
    else return false;

}

int main(){
	node* root = nullptr;

	string x;
	while(cin >> x) {
		if(!x.compare("-1")) break;
		else bstInsert(root, x);
	}

	busca(root, "asdas") ? cout << "True" : cout << "False";
	return 0;
}
