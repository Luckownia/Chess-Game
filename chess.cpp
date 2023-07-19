#include<iostream>

using namespace std;

string tab[8][8];
class Pionek{
public:
	int x_,y_;
	Pionek(int x,int y)
	{
		x_=x;
		y_=y;
	}
	void move_pionek()
	{
		int x,y;
		bool movable=false;
		while(movable!=true)
		{
			cout<<"Na jaka pozycje X: ";
			cin>>x;
			cout<<"Na jaka pozycje Y: ";
			cin>>y;
			if(abs(y-y_)==1 || abs(x-x_)) //mozliwe cofanie do naprawy 
			{
				if(abs(x-x_)>0)
				{
					if(tab[y][x]!="##")
					{
						cout<<"Yes";
						movable=true;
					}
					else{
						cout<<"No";
					}
				}
				else{
					cout<<"Yes";
					movable=true;
				}
			}
			else{
				if(abs(y-y_)==2 && (y==1 || y==7))
				{
					if(abs(x-x_)>0)
					{
						if(tab[y][x]!="##")
						{
							cout<<"Yes";
							movable=true;
						}
						else{
							cout<<"No";
						}
					}
					else{
						cout<<"Yes";
						movable=true;
					}
				}
			}
			
		}
		tab[y][x]=tab[y_][x_];
		tab[y_][x_]="##";
	}

};

void board_setup()
{
    int x,y; //create chessboard tab
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
}

void view_board()
{
	for(char word ='A';word<='H';word++)
	{
		if(word=='A')
		{
			cout<<"Y/X| ";
		} 
		cout<<" "<<word<<" | ";
	}
	//displaying chessboard 
	cout<<endl;

    for (int y=0;y<8;y++){
		cout<<" "<<y+1<<" | ";
			for(int x=0;x<8;x++){
				cout << tab[y][x] << " | ";
			}
			cout << "\n";
		}
}

int main()
{
    board_setup();
	view_board();
	Pionek P1(1,1);
	P1.move_pionek();
	view_board();
    return 0;
}