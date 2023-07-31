#include <iostream>
using namespace std;

string alphanumerical = " abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890.";

int steps = 0;

int crack (string code, string current, int it) {
	
	for (int x = 0; x < alphanumerical.length(); x++) {
		steps++;
		if (alphanumerical[x] == code[it] && current.length() + 1 == code.length()) {
			current += alphanumerical[x];
			cout << current << endl;
			return 0;	
		} else if (alphanumerical[x] == code[it]) {
			current += alphanumerical[x];
			cout << current << endl;
			crack(code, current, it+1);
		}
	}
}

int main() {
    string passcode("d27e086d60a993d203717509c46a6752daccc967");
    // cout << "Please enter a password: ";
    // getline(cin, passcode);
    crack(passcode, "", 0);
    cout << "It took me " << steps << " steps to do a simple brute force search" << endl;
    /*cout << endl << endl << endl << "Okay so I cheated a bit. This is not a 100% brute force because everytime I iterate through a string of characters, I can add it to the current string to see whether or not it matches so far with the passcode. In real life a hacker probably won't have the option of doing that (you need to know the passcode before hand). A true brute force would take an O(n^62) complexity to solve.... ;)";*/
}