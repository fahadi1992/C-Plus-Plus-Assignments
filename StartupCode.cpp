#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

class Player {
    private:
        char name[20];
        int score; 

    public:
        Player(){
            strcpy(name, "\0");
            score = 0;
            //cout<<"Constructor Called";
        }
        ~Player(){
            //cout<<"Destructor Called";
        }
        void setName(){            
            cin>>this->name; 
        }
        char* getName(){
            return this->name;
        }
        void setScore(int score){
            this->score = score;
        }                   
        int getScore(){
            return this->score;
        }     
};    

void displayInformation () {
cout<<"This is a mini Game, allowing three players to contest.";
cout<<"Each Player will have to open three boxes from given one hundred boxes in 3 turns.";
cout<<"There is a secret number in each box. In each turn number, the secret number inside the selected box will add-up to the total score of player.  At the end, it will display the summary of score of each player.\n\n";
}

void fillBoard(int array[10][10]){
    srand(time(0));
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            array[i][j] = rand()%100+1;
        }    
    }
}   
void displayBoard(int array[10][10]){
    int *ptr = *array;
    
    system("cls");
    
    displayInformation();
    
    for(int i = 1; i <= 100; i++){
        if(*ptr != 0){
            //cout<<i<<"("<<*ptr<<")\t";
            cout<<i<<"\t";
        }
        else {
            cout<<"X\t";
        }        
        ptr++;
            
        if(i%10 == 0) 
            cout<<endl;
    }
    cout<<endl;
    ptr = NULL;
}    
int openBox(int grid[10][10]){
    int *ptr = *grid, choice = 0, secretNumber = 0;
    cout<<"Enter the number of box to open it: ";
    cin>>choice;
	    
    ptr = ptr+choice-1;  
    secretNumber = *ptr;
    *ptr = 0;
    return secretNumber;
}    

void sortPlayers(Player players[], int size){
		
	// put your code here to sort the players in descending order on the bases of score
	// Example Input
	// Uzma 233
	// Ali 280
	// bc123456899  250

	// Desired Output
	// Ali 280
	// bc123456899  250
	// Uzma 233
		
}

main(){
    int size = 3, board[10][10] = {0};
    Player players[size];
    
    
    displayInformation();
    
    for(int x = 0; x < size; x++) {
    	fillBoard(board);
    	cout<<"Enter name of player "<<x+1<<" of "<<size<<": ";
		players[x].setName();    	
    	
    	for(int i = 1; i <= 3; i++){
    		displayBoard(board);
			cout<<"Turn "<<i<<" of 3"<<endl;
    		
    		if(i < 3) {
    			players[x].setScore(players[x].getScore()+openBox(board));
			}
			else{
				char choice = '\0';
            	int offer = 25+rand()%51;
            	cout<<"Special offer take: "<<offer<<endl<<endl;
            
            	cout<<"You can take special offer or open last box."<<endl;
            	cout<<"To take special offer press y or Y and any other character to open your last box: ";
            	cin>>choice;
            
            	if(choice == 'y' || choice == 'Y'){
                	players[x].setScore(players[x].getScore()+offer);
            	}    
            	else{
                	players[x].setScore(players[x].getScore()+openBox(board));
            	}	    
            }                
            cout<<endl<<endl;        	
		}	     	
    	cout<<"Your Score: "<<players[x].getScore()<<endl<<endl;
	}  
	
	sortPlayers(players, size); 
	
	cout<<"----------  Result Summary --------------   "<<endl;
	for(int k = 0; k < size; k++) {
		cout<<players[k].getName()<<"\t Score: "<<players[k].getScore()<<endl;
	}
	cout<<endl;
    system("pause");    
}    
