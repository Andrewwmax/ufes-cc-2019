#include <iostream>

using namespace std;

class BST {
    struct node {
        string data;
        node* left;
        node* right;
    };

    node* root;
    int sizet = 0;

    node* makeEmpty(node* t) {
        if(t == NULL) return NULL;
        {
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
        }
        return NULL;
    }

    node* insert(string x, node* t){
        if(t == NULL) {
            t = new node;
            t->data = x;
            t->left = t->right = NULL;
            sizet++;
            // cout << x << endl;
        }
        else if(x.compare(t->data) < 0) t->left = insert(x, t->left);
        else if(x.compare(t->data) > 0) t->right = insert(x, t->right);
        return t;
    }

    node* findMin(node* t) {
        if(t == NULL) return NULL;
        else if(t->left == NULL) return t;
        else return findMin(t->left);
    }

    node* findMax(node* t) {
        if(t == NULL) return NULL;
        else if(t->right == NULL) return t;
        else return findMax(t->right);
    }

    node* remove(string x, node* t) {
        node* temp;
        if(t == NULL) return NULL;
        else if(x.compare(t->data) < 0) t->left = remove(x, t->left);
        else if(x.compare(t->data) > 0) t->right = remove(x, t->right);
        else if(t->left && t->right) {
            temp = findMin(t->right);
            t->data = temp->data;
            t->right = remove(t->data, t->right);
        
        } else {
            temp = t;
            if(t->left == NULL) t = t->right;
            else if(t->right == NULL) t = t->left;
            delete temp;
        }
        // sizet--;
        return t;
    }

    void inorder(node* t) {
        if(t == NULL) return;
        inorder(t->left);
        cout << t->data << " ";
        inorder(t->right);
    }

    node* find(node* t, string x) {
        if(t == NULL) return NULL;
        else if(x.compare(t->data) < 0) return find(t->left, x);
        else if(x.compare(t->data) > 0) return find(t->right, x);
        else return t;
    }

public:
    BST() { root = NULL; }

    ~BST() { root = makeEmpty(root); }

    void insert(string x) { root = insert(x, root); }

    void remove(string x) { root = remove(x, root); }

    void display() { inorder(root); cout << endl; }

    void search(string x) { root = find(root, x); }
    
    bool searchTrue(string x) { 
        root = find(root, x);
        bool ret;
        root != NULL ? ret = true : ret = false;
        return ret;
    }

    int size() { return sizet; }

};


/*int main() {
    BST t;
    t.insert("0000C1BDAB3A615C3B636084CC33171482948D5A");
    t.insert("0000BA996ED92A2EEA1DDD7AD886EA64295C0F51");
    t.insert("0000F4B5EB4502F10ADC426238F2DF8778399E06");
    t.insert("0000363AF51392C9C15E5B93924DBF720F30FF85");
    t.insert("000039E7065D98862742CF12544B10C1C262519A");
    t.display();
    // t.remove("0000F4B5EB4502F10ADC426238F2DF8778399E06");
    // t.display();
    // t.remove("0000C1BDAB3A615C3B636084CC33171482948D5A");
    // t.display();
    // t.remove("0000363AF51392C9C15E5B93924DBF720F30FF85");
    // t.display();
    // t.searchTrue("0000F4B5EB4502F10ADC426238F2DF8778399E06");
    cout << t.size();
}
*/
