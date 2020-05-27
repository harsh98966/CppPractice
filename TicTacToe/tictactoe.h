#ifndef _TICTACTOE_HEADER_
#define _TICTACTOE_HEADER_

#define CLEARSCR system("clear"); //if you are using windows change "clear" to "cls" or "clr"
class board{
	char choices[9];	//stores choices of player and to print it accordingly
	char p1_choice;		//stores choice of player1 'x' or 'o';
	char p2_choice; 	//stores choice of player2 'x' or 'o';
	bool turn; 			//if false then player2 turns if true then player1 will play.
	string p1_name,p2_name;
	string cur_name; //stores name of the currently playing player
public:
	board(){
		for(int i = 0; i < 9; i++) choices[i] = ' ';
		p1_choice = ' ';
		p2_choice = ' ';
		turn = false;
		p1_name = "--";
		p2_name = "--";
		cur_name = "--";
	}
	void print(); 
	void reset();
	void start();  
	void clear(); //clear console screen
	void error_msg(string msg);
	bool already_played(int n);
	int won();
};


//+++++++++++++++
//class functions

void board::reset(){
	clear();
	for(int i = 0; i < 9; i++) choices[i] = ' ';
	p1_choice = ' ';
	p2_choice = ' ';
	turn = false;
	p1_name = "--";
	p2_name = "--";
	cur_name = "--";
}


void board::print(){
	for(int i = 0; i < 5; i++){
		cout << "\t\t";
		for(int j = 0; j < 5;j++){
			if(i == 0){
				if(j == 0) cout << choices[6];
				else if(j == 2) cout<< choices[7];
				else if(j == 4) cout << choices[8];
				else cout << "|";
			}
			else if(i == 2){
				if(j == 0) cout << choices[3];
				else if(j == 2) cout<< choices[4];
				else if(j == 4) cout << choices[5];
				else cout << "|";
			}
			else if(i == 4){
				if(j == 0) cout << choices[0];
				else if(j == 2) cout<< choices[1];
				else if(j == 4) cout << choices[2];
				else cout << "|";
			}
			else {
				cout << '-';
			}

		}
		cout << '\n';
	}
}

void board::clear(){
	#ifdef CLEARSCR
	CLEARSCR
	#endif
}

void board::start(){
	unsigned short int n; //
	cout << "Player1 Enter Your name : ";
	getline(cin, p1_name);
	cout << "Player2 Enter Your name : ";
	getline(cin, p2_name);
	while(1){
		cout << p1_name << " 'x' or 'o' ? : ";
		cin >> p1_choice;
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		if(p1_choice == 'x' || p1_choice == 'X') {
			p1_choice = 'x';
			p2_choice = 'o';
			break;
		}
		else if(p1_choice == 'o' || p1_choice == 'O'){
			 p1_choice = 'o';
			 p2_choice = 'x';
			 break;
		}	
		else cout << "Not a valid Choice. " << '\n';
		
	}
	clear();
	print();
	cout << p2_name << " will play first \n";
	cur_name = p2_name;
	for(int turns = 0; turns < 9;){
		if(won() == 1){
			clear();
			print();
			cout << "***********************************************************\t" << endl;
			cout << "\t\t\t" << p1_name << " Won \t\t" << endl;
			cout << "***********************************************************\t" << endl;
			break;
		}
		else if(won() == 2){

			clear();
			print();	
			cout << "***********************************************************\t" << endl;
			cout << "\t\t\t" << p2_name << " Won \t\t" << endl;
			cout << "***********************************************************\t" << endl;
			break;
		}
		else if(turns == 9 && won() == -1){
			clear();
			print();	
			cout << "***********************************************************\t" << endl;
			cout << "\t\t\t" << "Draw                        \t\t" << endl;
			cout << "***********************************************************\t" << endl;
			break;	
		}
		else {}
		cout <<"Enter a number b/w 1 to 9\n";
		cout << cur_name  << " enter your choice : ";
		cin >> n;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		if(!cin) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');	
			error_msg("Not A valid choice");
		}
		else if(n < 1 || n > 9) error_msg("Not A valid choice Enter a number b/w 1 to 9");
		else if(already_played(n) == true) error_msg("Already Played. Please Enter a valid choice.");
		else{
			clear();
			++turns;
			if(turn == false){
				choices[n - 1] = p2_choice;
				turn = true;
				cur_name = p1_name;
			}
			else{
				choices[n - 1] = p1_choice;
				turn = false;
				cur_name = p2_name;
			}
			print();
		}	
	}
}


bool board::already_played(int n){
	if(choices[n-1] == 'x' ||choices[n-1] == 'o') return true;
	else return false;
	return false;
}


void board::error_msg(string msg){
	clear();
	print();
	cout << msg << endl;
}


int board::won(){
	if(choices[0] == p1_choice && choices[1] == p1_choice && choices[2] == p1_choice ) return 1;
	else if (choices[3] == p1_choice && choices[4] == p1_choice && choices[5] == p1_choice ) return 1;
	else if (choices[6] == p1_choice && choices[7] == p1_choice && choices[8] == p1_choice ) return 1;
	else if (choices[0] == p1_choice && choices[3] == p1_choice && choices[6] == p1_choice ) return 1;
	else if (choices[1] == p1_choice && choices[4] == p1_choice && choices[7] == p1_choice ) return 1;
	else if (choices[2] == p1_choice && choices[5] == p1_choice && choices[8] == p1_choice ) return 1;
	else if (choices[0] == p1_choice && choices[4] == p1_choice && choices[8] == p1_choice ) return 1;
	else if (choices[2] == p1_choice && choices[4] == p1_choice && choices[6] == p1_choice ) return 1;
	else if (choices[0] == p2_choice && choices[1] == p2_choice && choices[2] == p2_choice ) return 2;
	else if (choices[3] == p2_choice && choices[4] == p2_choice && choices[5] == p2_choice ) return 2;
	else if (choices[6] == p2_choice && choices[7] == p2_choice && choices[8] == p2_choice ) return 2;
	else if (choices[0] == p2_choice && choices[3] == p2_choice && choices[6] == p2_choice ) return 2;
	else if (choices[1] == p2_choice && choices[4] == p2_choice && choices[7] == p2_choice ) return 2;
	else if (choices[2] == p2_choice && choices[5] == p2_choice && choices[8] == p2_choice ) return 2;
	else if (choices[0] == p2_choice && choices[4] == p2_choice && choices[8] == p2_choice ) return 2;
	else if (choices[2] == p2_choice && choices[4] == p2_choice && choices[6] == p2_choice ) return 2;
	else return -1;
	return -1;
}

#endif

