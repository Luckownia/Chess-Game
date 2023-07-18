#include<iostream>

using namespace std;

void view_board()
{
    int x,y; //create chessboard tab
	string tab[8][8];
	for (y=0;y<8;y++){
		for(x=0;x<8;x++){
			tab[y][x] = "##";
			}
		}
//chessboard setup
	y = 0;
	tab [y][0] = "R2";
	tab [y][1] = "N2";
	tab [y][2] = "B2";
	tab [y][3] = "Q2";
	tab [y][4] = "K2";
	tab [y][5] = "B2";
	tab [y][6] = "N2";
	tab [y][7] = "R2";
	y = 1;	
	for (x=0; x<8; x++){
		tab[y][x]="P2";
	}
	for (y=2; y<6; y++){
		for (x=0; x<8; x++){
		tab[y][x] = "##";
		}
	}
	
	y = 6;
	for (x=0; x<8; x++){
        	tab[y][x]="P1";
        }

	y=7;
		tab [y][0] = "R1";
        tab [y][1] = "N1";
        tab [y][2] = "B1";
        tab [y][3] = "Q1";
        tab [y][4] = "K1";
        tab [y][5] = "B1";
        tab [y][6] = "N1";
        tab [y][7] = "R1";
	
	for(int k=1;k<9;k++)
	{
		if(k==1)
		{
			cout<<"  | ";
		} 
		cout<<" "<<k<<" | ";
	}
	//displaying chessboard 
	cout<<endl;
	char word;
    for (y=0, word='A';y<8;y++,word++){
		cout<<word<<" | ";
			for(x=0;x<8;x++){
				cout << tab[y][x] << " | ";
			}
			cout << "\n";
		}
}

int main()
{
    view_board();
    return 0;
}