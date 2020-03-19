#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll choice,row,column;
char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char turn='X';
bool draw=false;

void display_board()
{
    system("cls");
    cout<<endl<<"\t\t\t\t\t\tTIC TAC TOE GAME:"<<endl;
    cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"\tPLAYER1 [X]"<<endl<<"\tPLAYER2 [0]"<<endl;
    cout<<"\t\t\t\t\t\t     |     |     \n";
    cout<<"\t\t\t\t\t\t  "<<board[0][0]<<"  |  "<<board[0][1]<<"  |  "<<board[0][2]<<"  \n";
    cout<<"\t\t\t\t\t\t_____|_____|_____\n";
    cout<<"\t\t\t\t\t\t     |     |     \n";
    cout<<"\t\t\t\t\t\t  "<<board[1][0]<<"  |  "<<board[1][1]<<"  |  "<<board[1][2]<<"  \n";
    cout<<"\t\t\t\t\t\t_____|_____|_____\n";
    cout<<"\t\t\t\t\t\t     |     |     \n";
    cout<<"\t\t\t\t\t\t  "<<board[2][0]<<"  |  "<<board[2][1]<<"  |  "<<board[2][2]<<"  \n";
    cout<<"\t\t\t\t\t\t     |     |     \n";
}

void player_turn()
{
    if(turn=='X')
    {
        cout<<"\n\tPlayer1 [X] turn: ";
    }
    if(turn=='0')
    {
        cout<<"\n\tPlayer2 [0] turn: ";
    }
    cin>>choice;

    switch(choice)
    {
        case 1: row =0; column =0;break;
        case 2: row =0; column =1;break;
        case 3: row =0; column =2;break;
        case 4: row =1; column =0;break;
        case 5: row =1; column =1;break;
        case 6: row =1; column =2;break;
        case 7: row =2; column =0;break;
        case 8: row =2; column =1;break;
        case 9: row =2; column =2;break;

        default:
            cout<<"Invalid Choice"<<endl;
            break;
    }
    if(turn=='X'&&board[row][column]!='X'&&board[row][column]!='0')
    {
        board[row][column]='X';
        turn='0';
    }
    else if(turn=='0'&&board[row][column]!='X'&&board[row][column]!='0')
    {
        board[row][column]='0';
        turn='X';
    }
    else
    {
        cout<<"Box Already Filled!\nPlease Try Again!\n\n";
        player_turn();
    }
    display_board();
}

bool gameover()
{
    //check win
    for(ll i=0;i<3;i++)
    {
        if((board[i][0]==board[i][1]&&board[i][0]==board[i][2])||(board[0][i]==board[1][i]&&board[2][i]==board[1][i]))
        {
            return false;
        }
    }
    if((board[0][0]==board[1][1]&&board[1][1]==board[2][2])||(board[0][2]==board[1][1]&&board[1][1]==board[2][0]))
    {
        return false;
    }

    //check game continue
    for(ll i=0;i<3;i++)
    {
        for(ll j=0;j<3;j++)
        {
            if(board[i][j]!='X'&&board[i][j]!='0')
            {
                return true;
            }
        }
    }
    //check draw
    draw=true;
    return false;

}

int main()
{

    while(gameover())
    {
        display_board();
        player_turn();
        gameover();
    }
    if(turn=='0'&&draw==false)
    {
        cout<<"Player1 [X] Wins! Congratulations\n";
    }
    else if(turn=='X'&&draw==false)
    {
        cout<<"Player2 [0] Wins! Congratulations\n";
    }
    else
    {
        cout<<"GAME DRAW:)"<<endl;
    }

    cout<<endl<<endl;
    cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
}
