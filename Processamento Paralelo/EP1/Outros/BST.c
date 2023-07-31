#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

typedef struct TreeNode {
	string data;
	struct TreeNode* left;
	struct TreeNode* right;
} tNode;

tNode* makeEmpty(tNode* t) {
	if(t != NULL) {
		makeEmpty(t->left);
		makeEmpty(t->right);
		free(t);
	}
	return NULL;
}

tNode* insertNode(tNode* t, string x) {
	if(t == NULL){
		t = (tNode *) malloc(sizeof(tNode));
		t->data = x;
		t->left = t->right = NULL;
		// cout << "ENTRO" << endl;
	}
	else if(x.compare(t->data) < 0) t->left = insertNode(t->left, x);
	else if(x.compare(t->data) > 0)	t->right = insertNode(t->right, x);
	return t;
}

tNode* findMin(tNode* t) {
	if(t == NULL) return NULL;
	else if(t->left == NULL) return t;
	else return findMin(t->left);
}

tNode* findMax(tNode* t) {
	if(t == NULL) return NULL;
	else if(t->right == NULL) return t;
	else return findMax(t->right);
}

tNode* find(tNode* t, string x) {
	if(t == NULL) return NULL;
	else if(x.compare(t->data) < 0) return find(t->left, x);
	else if(x.compare(t->data) > 0) return find(t->right, x);
	else return t;
}

int findHeight(tNode* t) {
	int lefth, righth;
	if(t == NULL) return -1;

	lefth = findHeight(t->left);
	righth = findHeight(t->right);
	
	return (lefth > righth ? lefth : righth)+1;
}

tNode* deleteNode(tNode* t, string x) {
	tNode* temp;
	if(t == NULL) return NULL;
	else if(x.compare(t->data) < 0) t->left = deleteNode(t->left, x);
	else if(x.compare(t->data) > 0) t->right = deleteNode(t->right, x);
	else if(t->left && t->right) {
		temp = findMin(t->right);
		t->data = temp->data;
		t->right = deleteNode(t->right, t->data);
	} else {
		temp = t;
		if(t->left == NULL) t = t->right;
		else if(t->right == NULL) t = t->left;
		free(temp);
	}
	return t;
}

void inorder(tNode* t) {
	if(t == NULL) return;

	inorder(t->left);
	cout << t->data << endl;
	inorder(t->right);
}

tNode* findNode(tNode* t, string x) {
    if(t == NULL) return NULL;
    else if(x.compare(t->data) < 0) return findNode(t->left, x);
    else if(x.compare(t->data) > 0) return findNode(t->right, x);
    else return t;
}

bool search(tNode *root, string x) {
	tNode *t = findNode(root, x);
	// cout << t->data << endl;
	bool ret;
	t != NULL ? ret = true : ret = false;
    return ret;
}

// int main() {
// 	tNode *t;
// 	tNode *temp;
// 	t = NULL;
// 	t = insertNode(t, (char *) "0011132FEDD62EDDA753B63E7352EC1D84ADBD0A");
// 	t = insertNode(t, (char *) "001087FD136A0FC2CF5B93AFA716EF64BE48EA73");
// 	t = insertNode(t, (char *) "0010DB009BF034E6EFF668F04D4197AC0CCA7899");
// 	t = insertNode(t, (char *) "0000BA996ED92A2EEA1DDD7AD886EA64295C0F51");
// 	t = insertNode(t, (char *) "0000C1BDAB3A615C3B636084CC33171482948D5A");
// 	t = insertNode(t, (char *) "0000F4B5EB4502F10ADC426238F2DF8778399E06");
// 	t = insertNode(t, (char *) "0010555B8F3765B6CF761D8E1958C8C5AFC44D06");
// 	t = insertNode(t, (char *) "0000363AF51392C9C15E5B93924DBF720F30FF85");
// 	t = insertNode(t, (char *) "000039E7065D98862742CF12544B10C1C262519A");
// 	t = insertNode(t, (char *) "0010D5D4DDAE6B9555ED2542058A475CCBA12ADE");
// 	search(t, (char *) "0000C1BDAB3A615C3B636084CC33171482948D5A") ? printf("Achou\n") : printf("Não Achou\n");

// 	t = makeEmpty(t);
// 	return 0;
// }