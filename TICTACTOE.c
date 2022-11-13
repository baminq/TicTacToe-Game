#include <stdio.h>
#include <stdlib.h>

// declare functions
int check_win_person();
void board();
char square[10] = {'0','1','2','3','4','5','6','7','8','9'};

// draw the board 3x3
void board(){
	system("cls");
	printf("\n TIC TAC TOE (1vs1) \n"); // specify the icon of 2 players
	printf("\n Player1 (X) - Player2 (O) \n");
	printf("     |     |     \n");
	printf("  %c  |  %c  |  %c  \n",square[1],square[2],square[3]);
	printf("_____|_____|_____\n");
	printf("     |     |     \n");
	printf("  %c  |  %c  |  %c  \n",square[4],square[5],square[6]);
	printf("_____|_____|_____\n");
	printf("     |     |     \n");
	printf("  %c  |  %c  |  %c  \n",square[7],square[8],square[9]);
	printf("     |     |     \n");	
}

// check win condition
int check_win_person(){
	if(square[1] == square[2] && square[2] == square[3])
		return 1;
	else if (square[4] == square[5] && square[5] == square[6])
		return 1;
	else if(square[7] == square[8] && square[8] == square[9])
		return 1;
	else if(square[1] == square[4] && square[4] == square[7])
		return 1;
	else if(square[2] == square[5] && square[5] == square[8])
		return 1;
	else if(square[3] == square[6] && square[6] == square[9])
		return 1;
	else if(square[1] == square[5] && square[5] == square[9])
		return 1;
	else if(square[3] == square[5] && square[5] == square[7])
		return 1;
	else if(square[1] != '1' && square[2] != '2' && square[3] != '3' && square[4] !='4' && square[5] != '5' && square[6] != '6' && square[7] != '7' && square[8] != '8' && square[9] != '9')
		return 0;
	else 
		return -1;	
}

int main(void){
	int player = 1, i ,location_choice;
	char mark;
	do {
		board();
		player = (player % 2) ? 1 : 2;
		printf("Player %d turn, please enter the number of your choice : ", player);
		scanf("%d",&location_choice);
		mark = (player == 1) ? 'X' : 'O';
		if(location_choice == 1 && square[1] == '1')
			square[1] = mark;
		else if(location_choice == 2 && square[2] == '2')
			square[2] = mark;
			else if(location_choice == 3 && square[3] == '3')
			square[3] = mark;
			else if(location_choice == 4 && square[4] == '4')
			square[4] = mark;
			else if(location_choice == 5 && square[5] == '5')
			square[5] = mark;
			else if(location_choice == 6 && square[6] == '6')
			square[6] = mark;
			else if(location_choice == 7 && square[7] == '7')
			square[7] = mark;
			else if(location_choice == 8 && square[8] == '8')
			square[8] = mark;
			else if(location_choice == 9 && square[9] == '9')
			square[9] = mark;
			
			else {
				printf("Invalid option !!!");
				player--;

			}
			i = check_win_person();
			player++;	
		
	}while(i == -1);
	
	board();
	if(i==1){
		printf("Congratulations to Player %d for Winning!!!\n",--player);

	}
	else {
		printf("Game draw!");
	}
		
		return 0;
}

