#include<iostream>
#include<limits>
#include<string>
using namespace std;
#include "tictactoe.h"


void thankyou(){
	cout << "\n\n\n\n\n\n\n";
	cout << "****************************************\n";
	cout << "*         Thank You For Playing        *\n";
	cout << "****************************************\n";
	cout << "\n\n\n\n\n\n\n";
}

int main(){
	board b1;
	string ans = "no";
	while(1){
		b1.reset();
		b1.start();
		cout << "Play Again?(yes or no) : ";
		getline(cin, ans);
		if(ans != "Yes" && ans != "y" && ans != "YES" && ans != "Y"){
			thankyou();
			break;
		}
	}
	return 0;
}