/*#include <iostream>
#include <time.h>
#include <string>
using namespace std;

int main(){
	// while(1){
	// 	string s;
	//  time_t current = time(0);
	// 	s = ctime(&current);
	// 	s[s.length()-1] = '\r';
	// 	cout << s;
    // }

	while(1){
		time_t current = time(0);
        string s = ctime(&current);
        s.resize( s.length() - 1 );
        cout << "\r" << s << flush;
	}
	return 0;
}
*/

#include <iostream>
#include <time.h>
#include <string>
using namespace std;

int main(){
	
	time_t initial = time(0);
	while(1){
		time_t current = time(0);
        // string s = ctime(&current);
        // s.resize( s.length() - 1 );
        cout << "\r" << difftime(current, initial) << flush;
	}
	return 0;
}

/*
#include <stdio.h>
#include <time.h>

int main (){
	time_t now, newyear;
	double seconds;

	get current time; same as: now = time(NULL)  
	time(&now);  

	newyear = time(0);

	seconds = difftime(now, newyear);

	printf ("%.25f seconds since new year in the current timezone.\n", seconds);

	return 0;
}*/