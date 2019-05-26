#include <bits/stdc++.h>
using namespace std;
char matrix[3][3];
int checker(char player,char computer){
	if(matrix[0][0]==matrix[0][1] && matrix[0][0]==matrix[0][2] && matrix[0][2]==matrix[0][1] && matrix[0][0]==player) return 2; 
	if(matrix[0][0]==matrix[0][1] && matrix[0][0]==matrix[0][2] && matrix[0][2]==matrix[0][1] && matrix[0][0]==computer) return 1; 

	if(matrix[1][0]==matrix[1][1] && matrix[1][0]==matrix[1][2] && matrix[1][2]==matrix[1][1] && matrix[1][0]==player) return 2; 
	if(matrix[1][0]==matrix[1][1] && matrix[1][0]==matrix[1][2] && matrix[1][2]==matrix[1][1] && matrix[1][0]==computer) return 1;

	if(matrix[2][0]==matrix[2][1] && matrix[2][0]==matrix[2][2] && matrix[2][2]==matrix[2][1] && matrix[2][0]==player) return 2; 
	if(matrix[2][0]==matrix[2][1] && matrix[2][0]==matrix[2][2] && matrix[2][2]==matrix[2][1] && matrix[2][0]==computer) return 1;

	if(matrix[0][0]==matrix[1][0] && matrix[1][0]==matrix[2][0] && matrix[0][0]==matrix[2][0] && matrix[0][0]==player) return 2; 
	if(matrix[0][0]==matrix[1][0] && matrix[1][0]==matrix[2][0] && matrix[0][0]==matrix[2][0] && matrix[0][0]==computer) return 1;

	if(matrix[0][1]==matrix[1][1] && matrix[1][1]==matrix[2][1] && matrix[0][1]==matrix[2][1] && matrix[0][1]==player) return 2; 
	if(matrix[0][1]==matrix[1][1] && matrix[1][1]==matrix[2][1] && matrix[0][1]==matrix[2][1] && matrix[0][1]==computer) return 1;

	if(matrix[0][2]==matrix[1][2] && matrix[1][2]==matrix[2][2] && matrix[0][2]==matrix[2][2] && matrix[0][2]==player) return 2; 
	if(matrix[0][2]==matrix[1][2] && matrix[1][2]==matrix[2][2] && matrix[0][2]==matrix[2][2] && matrix[0][2]==computer) return 1;

	if(matrix[0][0]==matrix[1][1] && matrix[1][1]==matrix[2][2] && matrix[0][0]==matrix[2][2] && matrix[0][0]==player) return 2; 
	if(matrix[0][0]==matrix[1][1] && matrix[1][1]==matrix[2][2] && matrix[0][0]==matrix[2][2] && matrix[0][0]==computer) return 1;

	if(matrix[0][2]==matrix[1][1] && matrix[1][1]==matrix[2][0] && matrix[0][2]==matrix[2][0] && matrix[0][2]==player) return 2; 
	if(matrix[0][2]==matrix[1][1] && matrix[1][1]==matrix[2][0] && matrix[0][2]==matrix[2][0] && matrix[0][2]==computer) return 1;

	return 0;
}
int main()
{
	srand (time(NULL));
	char s='y',player,computer;
	vector <int> unused;
	for(int i=0;i<9;i++){
		unused.push_back(i);
	}
	cout<<"Welcome! \nLet's play tic-tac-toe"<<endl;
	while(s=='y'){
		cout<<"Which character do you want? X or O"<<endl;
		cin>>player;
		if(player=='X') computer='O';
		else computer='X';

		int toss=rand() & 1;
		if(toss==0) cout<<"Computer goes first.";
		else  cout<<"Player goes first.";

		int didanyonewin=0,count=0,currentplayer=toss;

		cout<<"Matrix Numbering"<<endl;
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				matrix[i][j]='\0';
				cout<<3*i+j+1;
				if(j!=2) cout<<" |";
				else cout<<endl;
			}
			cout<<"--------"<<endl;
		}
		int x_cordinate,y_cordinate;
		while(count<=9 && !didanyonewin){
			if(currentplayer==0){
					cout<<"Computer's turn"<<endl;
				vector<int> remaining;
				for(int i=0;i<9;i++){
					if(unused[i]!=-1)
						remaining.push_back(i);
				}
				int computergridnumber=remaining[rand()%remaining.size()];
				unused[computergridnumber]=-1;
				x_cordinate=computergridnumber/3;
				y_cordinate=computergridnumber%3;
				if(matrix[x_cordinate][y_cordinate]=='\0'){matrix[x_cordinate][y_cordinate]=computer;count++;}

			}
			else{
				int usergridnumber,valid=1;
				while(valid){
					cout<<"Player's turn"<<endl;
					cout<<"Please enter a valid grid number.";
					cin>>usergridnumber;
					usergridnumber--;
					unused[usergridnumber]=-1;
					x_cordinate=usergridnumber/3;
					y_cordinate=usergridnumber%3;
					if(matrix[x_cordinate][y_cordinate]=='\0'){
						matrix[x_cordinate][y_cordinate]=player;
						valid=0;
						count++;
					}
				}
			}
			currentplayer=!currentplayer;
			didanyonewin=checker(player,computer);
			for(int i=0;i<3;i++){
				for(int j=0;j<3;j++){
					cout<<matrix[i][j];
					if(j!=2) cout<<" |";
					else cout<<endl;
				}
				cout<<"--------"<<endl;
			}
		}
		if(didanyonewin==0) cout<<"Guess it's a draw.GG"<<endl;
		else if(didanyonewin==1) cout<<"Computer won the game."<<endl;
		else cout<<"Congratulations . You won the game."<<endl;
		cout<<"Do you want to play another game? y or n"<<endl;
		cin>>s;
	}
}
