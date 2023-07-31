// C++ program to demonstrate functionality of unordered_map 
#include <iostream> 
#include <unordered_map> 
using namespace std; 
  
int main() 
{ 
    // Declaring umap to be of <string, int> type 
    // key will be of string type and mapped value will 
    // be of double type 
    hash<string> str_hash;

    unordered_map<string, long long int> umap; 
    string s("0003C5BC3A5E12CFDF602F545D5F073F4E46406B");
    // inserting values by using [] operator 
    umap[s] = str_hash(s);
    umap["Practice"] = 20; 
    umap["Contribute"] = 30; 
  
    // Traversing an unordered map 
    for (auto x : umap) 
      cout << x.first << " : " << x.second << endl; 
  
} 