#include<iostream>

using namespace std;

string tab[8][8];
class Pionek{
public:
	int x_,y_,move_;
	Pionek(int x,int y,int move)
	{
		x_=x;
		y_=y;
		move_=move;
	}
	void move_pionek()
	{
		int x,y;
		bool movable=false;
		while(movable!=true)
		{
			cout<<"On postion X: ";
			cin>>x;
			cout<<"On position Y: ";
			cin>>y;
			if((x<0||x>8)||(y<0||y>8)) //zabezpieczenie przed wyjsciem z szachownicy 
			{
				cout<<"On postion X: ";
				cin>>x;
				cout<<"On position Y: ";
				cin>>y;
			}
			if((y-y_==1 && move_%2==0)||(y-y_==-1 && move_%2==1) ) //Pionek player 1 and 2 movement 
			{
				if(abs(x-x_)>0)
				{
					if(tab[y][x]!="##")
					{
						movable=true;
					}
					else{
						cout<<"No";
					}
				}
				else{
					movable=true;
				}
			}
			else if(((y-y_==2 && move_%2==0)||(y-y_==-2 && move_%2==1)) && (y_==1 || y_==6)) //first movement Pionek 
			{
				if(abs(x-x_)>0)
				{
					cout<<"No";
				}
				else{
					movable=true;
				}
			}
			else{
				cout<<"No";
			}
			
			
		}
		tab[y][x]=tab[y_][x_];
		tab[y_][x_]="##";
	}

};


class Tower{
	public:
		int x_;
		int y_;
		int counter_;
		Tower(int x, int y, int counter)
		{
			x_=x;
			y_=y;
			counter_=counter;
		}
		void move_tower()
		{
			int x,y;
			bool movable=false;
			while(movable!=true)
			{
				cout<<"On postion X: ";
				cin>>x;
				cout<<"On position Y: ";
				cin>>y;
				if((x<0||x>8)||(y<0||y>8)) //zabezpieczenie przed wyjsciem z szachownicy 
				{
					cout<<"On postion X: ";
					cin>>x;
					cout<<"On position Y: ";
					cin>>y;
				}
				if(x-x_==0 && y-y_!=0)
				{
					int start = min(y,y_);
					int end =  max(y_,y);

					for(int i=start ; i<=end;i++)
					{
							if((tab[i][x]=="P1" || tab[i][x]=="N1" || tab[i][x]=="Q1" || tab[i][x]=="B1" || tab[i][x]=="K1") &&  counter_%2==1)
						{
							movable=false;
							cout<<"No";
						}
						else if((tab[i][x]=="P2" || tab[i][x]=="N2" || tab[i][x]=="Q2" || tab[i][x]=="B2" || tab[i][x]=="K2") &&  counter_%2==0)
						{
							movable=false;
							cout<<"No";
						}
						else{
							movable=true;
						}
					}
				
				}
				else if(x-x_!=0 && y-y_==0)
				{
					int start = min(x,x_);
					int end =  max(x_,x);
					for(int i= start;i<=end;i++)
					{
						if((tab[y][i]=="P1" || tab[y][i]=="N1" || tab[y][i]=="Q1" || tab[y][i]=="B1" || tab[y][i]=="K1") &&  counter_%2==1)
						{
							movable=false;
							cout<<"No";
						}
						else if((tab[y][i]=="P2" || tab[y][i]=="N2" || tab[y][i]=="Q2" || tab[y][i]=="B2" || tab[y][i]=="K2") &&  counter_%2==0)
						{
							movable=false;
							cout<<"No";
						}
						else{
							movable=true;
						}
						i++;
					}
				}
				else{
					cout<<"No";
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
	int i=3;
    board_setup();
	view_board();
	int x,y;
	while(i<=5)
	{	
		if(i%2==1){
			cout<<"Player 1 move :";
			cout<<"From position X: ";
			cin>>x;
			cout<<"From Position Y: ";
			cin>>y;
			if(tab[y][x]=="P1")
			{
				Pionek P1(x,y,i);
				P1.move_pionek();
				view_board();
			}
			else if(tab[y][x]=="R1")
			{
				Tower T1(x,y,i);
				T1.move_tower();
				view_board();
			}

		}
		else{
			cout<<"Player 2 move: ";
			cout<<"From position X: ";
			cin>>x;
			cout<<"From Position Y: ";
			cin>>y;
			if(tab[y][x]=="P2") //Pionek 
			{
				Pionek P1(x,y,i);
				P1.move_pionek();
				view_board();
			}
			else if(tab[y][x]=="R2")
			{
				Tower T2(x,y,i);
				T2.move_tower();
				view_board();
			}
		}
		i++;
	}

    return 0;
}