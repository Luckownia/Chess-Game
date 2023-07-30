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

	bool check_route(int x,int y)
	{
		int i=move_;
		if(tab[y][x]!=("P"+to_string(i%2+1)) && tab[y][x]!=("N"+to_string(i%2+1)) && tab[y][x]!=("Q"+to_string(i%2+1))
		&& tab[y][x]!=("B"+to_string(i%2+1)) && tab[y][x]!=("K"+to_string(i%2+1))  && tab[y][x]!=("R"+to_string(i%2+1)))
		{
			return true;
		}
		else{
			cout<<"You can't beat your own figure! :"<<tab[y][x]<<endl;
			return false;
		}
	}
	bool ifMove(){
		if(move_%2==0 && tab[y_-1][x_]=="##") //player1 verticaly
		{
			return true;
		}
		//player 1 diagonially 
		else if(move_%2==0 && ((tab[y_-1][x_-1]!="##" && (x_>0 && y_>0 )) || (tab[x_+1][y_-1]!="##" &&(x_<7 && y_>0))))
		{
			if(check_route(x_-1,y_-1) || check_route(x_+1,y_-1))
			{
				return true;
			}
			else{
				return false;
			}
		}
		else if(move_%2==1 && tab[y_+1][x_]=="##"){ //player 2
			return true;
		}	
		else if(move_%2==1 &&((tab[y_+1][x_+1]!="##" && (x_<7 && y_<7 )) ||(tab[y_+1][x_-1]!="##" &&(x_>0 && y_<7))))
		{
			if(check_route(x_+1,y_+1) || check_route(x_-1,y_+1))
			{
				return true;
			}
			else{
				return false;
			}
		}
		else{
			return false;
		}
	}
	void move_pionek()
	{
		int x,y;
		bool movable=false;
		while(movable!=true)
		{
			x,y=-1; // set value to launch while 
			while((x<0||x>8)||(y<0||y>8)) //prevent from escape player chess board
			{
				cout<<"On postion X: ";
				cin>>x;
				cout<<"On position Y: ";
				cin>>y;
				/* Zrobic osoban funkcje wyłowić z tej klasy sprawdzajaca czy mozna sie ruszyc 
				if(((tab[y_-1][x_]!="##" || tab[y_-1][x_+1]=="##" || tab[y_-1][x_-1]=="##") && move_%2==0 )
				||((tab[y_+1][x_]!="##" || tab[y_+1][x_+1]=="##" || tab[y_+1][x_-1]=="##") && move_%2==1 ))
				{
					cout<<"You can't move anywhere this figure, choose another one or move other figure to be able to!"<<endl;
				}
				*/
				//checking if figure can move anywhere (if it's not blocked)
				
			}
			if((y-y_==1 && move_%2==1)||(y-y_==-1 && move_%2==0) ) //Pionek player 1 and 2 movement 
			{
				if(abs(x-x_)>0)
				{
					if(tab[y][x]!="##" )
					{
						if(((tab[y][x]=="P1" || tab[y][x]=="N1" || tab[y][x]=="Q1" 
						|| tab[y][x]=="B1" || tab[y][x]=="K1" ||  tab[y][x]=="R1") &&  move_%2==0)
						|| (tab[y][x]=="P2" || tab[y][x]=="N2" || tab[y][x]=="Q2" 
						|| tab[y][x]=="B2" || tab[y][x]=="K2" ||  tab[y][x]=="R2") &&  move_%2==1)
						{
							cout<<"You can't beat your own figure! :"<<tab[y][x]<<endl;
							movable=false;
						}
						else{
							movable=true;
						}
					}
					else{
						cout<<"Inappropriate move! Try again! "<<endl;
					}
				}
				else
				{
					if(tab[y][x]!="##")
					{
						movable=false;
						cout<<"You can't beat this figure! :"<<tab[y][x]<<endl;
					}
					else{
						movable=true;
					}
				}
			}
			else if(((y-y_==2 && move_%2==1)||(y-y_==-2 && move_%2==0)) && (y_==1 || y_==6)) //first movement Pionek 
			{
				if(abs(x-x_)>0)
				{
					cout<<"Inappropriate move! try again!"<<endl;
				}
				else{
					if(tab[y][x]!="##")
					{
						movable=false;
						cout<<"You can't beat this figure! :"<<tab[y][x]<<endl;
					}
					else{
						movable=true;
					}
				}
			}
			else{
				cout<<"Inappropriate move try again!"<<endl;
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
				while((x<0||x>8)||(y<0||y>8)) //prevent from escape player chess board 
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
						if((tab[i][x]=="P1" || tab[i][x]=="N1" || tab[i][x]=="Q1" 
						|| tab[i][x]=="B1" || tab[i][x]=="K1" || tab[y][x]=="R1") &&  counter_%2==0)
						{
							movable=false;
							cout<<"You can't beat your own figure: "<<tab[i][x]<<endl;
							break;
						}
						else if((tab[i][x]=="P2" || tab[i][x]=="N2" || tab[i][x]=="Q2" 
						|| tab[i][x]=="B2" || tab[i][x]=="K2" || tab[y][x]=="R2") &&  counter_%2==1)
						{
							movable=false;
							cout<<"You can't beat your own figure! : "<<tab[i][x]<<endl;
							break;
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
						if((tab[y][i]=="P1" || tab[y][i]=="N1" || tab[y][i]=="Q1"
						 || tab[y][i]=="B1" || tab[y][i]=="K1") &&  counter_%2==0)
						{
							movable=false;
							cout<<"You can't beat your own figure: "<<tab[y][i]<<endl;
							break;
						}
						else if((tab[y][i]=="P2" || tab[y][i]=="N2" || tab[y][i]=="Q2"
						 || tab[y][i]=="B2" || tab[y][i]=="K2") &&  counter_%2==1)
						{
							movable=false;
							cout<<"You can't beat your own figure: "<<tab[y][i]<<endl;
							break;
						}
						else{
							movable=true;
						}
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

class Goniec{
	public:
		int x_,y_,counter_;
		Goniec(int x,int y,int move)
		{
			x_=x;
			y_=y;
			counter_=move;
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
				while((x<0||x>8)||(y<0||y>8)) //prevent from escape player chess board
				{
					cout<<"On postion X: ";
					cin>>x;
					cout<<"On position Y: ";
					cin>>y;
				}
				if(abs(x_-x)==abs(y_-y))
				{
					int start = min(y,y_);
					int end =  max(y_,y);

					int rowDiff = abs(x - x_);
					int colDiff = abs(y_-y);
					int rowD = (x > x_) ? 1 : -1; // Upright movement 
					int colD = (y > y_) ? 1 : -1; // Horizontaly movement 
					for(int i=1; i<=rowDiff;i++)
					{
						if((tab[y_+i*colD][x_+i*rowD]=="P1" || tab[y_+i*colD][x_+i*rowD]=="N1" ||tab[y_+i*colD][x_+i*rowD]=="Q1" 
						|| tab[y_+i*colD][x_+i*rowD]=="B1" || tab[y_+i*colD][x_+i*rowD]=="K1" || tab[y_+i*colD][x_+i*rowD]=="R1") &&  counter_%2==0)
						{
							movable=false;
							cout<<"You can't beat your own figure: "<<tab[y_+i*colD][x_+i*rowD]<<endl;
							break;
						}
						else if((tab[y_+i*colD][x_+i*rowD]=="P2" || tab[y_+i*colD][x_+i*rowD]=="N2" || tab[y_+i*colD][x_+i*rowD]=="Q2" 
						|| tab[y_+i*colD][x_+i*rowD]=="B2" || tab[y_+i*colD][x_+i*rowD]=="K2" || tab[y_+i*colD][x_+i*rowD]=="R2") &&  counter_%2==1)
						{
							movable=false;
							cout<<"You can't beat your own figure: "<<tab[y_+i*colD][x_+i*rowD]<<endl;
							break;
						}
						else{
							movable=true;
						}
					}
				}
				else{
					cout<<"Inappropriate move try again! "<<endl;
				}
			}
			tab[y][x]=tab[y_][x_];
			tab[y_][x_]="##";
		}
};
class Queen{
	public:
		int x_,y_,counter_;
		Queen(int x,int y,int move)
		{
			x_=x;
			y_=y;
			counter_=move;
		}
		void move_queen()
		{
			int x,y;
			bool movable=false;
			while(movable!=true)
			{
				cout<<"On postion X: ";
				cin>>x;
				cout<<"On position Y: ";
				cin>>y;
				while((x<0||x>8)||(y<0||y>8)) //prevent from escape player chess board
				{
					cout<<"On postion X: ";
					cin>>x;
					cout<<"On position Y: ";
					cin>>y;
				}
				if(x-x_==0 && y-y_!=0) //movement Queen Tower
				{
					int start = min(y,y_);
					int end =  max(y_,y);

					for(int i=start; i<=end;i++)
					{
						if((tab[i][x]=="P1" || tab[i][x]=="N1" || tab[i][x]=="R1" 
						|| tab[i][x]=="B1" || tab[i][x]=="K1") &&  counter_%2==0)
						{
							movable=false;
							cout<<"You can't beat your own figure: "<<tab[i][x]<<endl;
							break;
						}
						else if((tab[i][x]=="P2" || tab[i][x]=="N2" || tab[i][x]=="B2" 
						|| tab[i][x]=="R2"|| tab[i][x]=="K2") &&  counter_%2==1)
						{
							movable=false;
							cout<<"You can't beat your own figure: "<<tab[i][x]<<endl;
							break;
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
						if((tab[y][i]=="P1" || tab[y][i]=="N1"  || tab[y][i]=="B1" 
						|| tab[y][i]=="K1" || tab[y][i]=="R1" ) &&  counter_%2==0)
						{
							movable=false;
							cout<<"You can't beat your own figure: "<<tab[y][i]<<endl;
							break;
						}
						else if((tab[y][i]=="P2" || tab[y][i]=="N2"  || tab[y][i]=="B2" 
						|| tab[y][i]=="K2" || tab[y][i]=="R2") &&  counter_%2==1)
						{
							movable=false;
							cout<<"You can't beat your own figure: "<<tab[y][i]<<endl;
							break;
						}
						else{
							movable=true;
						}
					}
				}
				else if(abs(x_-x)==abs(y_-y)) //movement bishop
				{
					int start = min(y,y_);
					int end =  max(y_,y);

					int rowDiff = abs(x - x_);
					int colDiff = abs(y_-y);
					int rowD = (x > x_) ? 1 : -1; // Kierunek ruchu w pionie
					int colD = (y > y_) ? 1 : -1; // Kierunek ruchu w poziomie
					for(int i=1; i<=rowDiff;i++)
					{
							if((tab[y_+i*colD][x_+i*rowD]=="P1" || tab[y_+i*colD][x_+i*rowD]=="N1" ||tab[y_+i*colD][x_+i*rowD]=="R1"
							 || tab[y_+i*colD][x_+i*rowD]=="B1" || tab[y_+i*colD][x_+i*rowD]=="K1") &&  counter_%2==0)
						{
							movable=false;
							cout<<"You can't beat your own figure: "<<tab[y_+i*colD][x_+i*rowD]<<endl;
							break;
						}
						else if((tab[y_+i*colD][x_+i*rowD]=="P2" || tab[y_+i*colD][x_+i*rowD]=="N2" || tab[y_+i*colD][x_+i*rowD]=="R2" 
						|| tab[y_+i*colD][x_+i*rowD]=="B2" || tab[y_+i*colD][x_+i*rowD]=="K2") &&  counter_%2==1)
						{
							movable=false;
							cout<<"You can't beat your own figure: "<<tab[y_+i*colD][x_+i*rowD]<<endl;
							break;
						}
						else{
							movable=true;
						}
					}
				}
				else{
					cout<<"Inappropriate move try again !"<<endl;
				}	

			}
			tab[y][x]=tab[y_][x_]; //movement 
			tab[y_][x_]="##";
		}
};
class King{
	public:
		int x_,y_,counter_;
		King(int x,int y,int move)
		{
			x_=x;
			y_=y;
			counter_=move;
		}
		void move_king()
		{
			int x,y;
			bool movable=false;
			while(movable!=true)
			{
				cout<<"On postion X: ";
				cin>>x;
				cout<<"On position Y: ";
				cin>>y;
				while((x<0||x>8)||(y<0||y>8)) //zabezpieczenie przed wyjsciem z szachownicy 
				{
					cout<<"On postion X: ";
					cin>>x;
					cout<<"On position Y: ";
					cin>>y;
				}
				if(x-x_==0 && abs(y-y_)==1)
				{

						if((tab[y][x]=="P1" || tab[y][x]=="N1" || tab[y][x]=="Q1" 
						|| tab[y][x]=="B1" || tab[y][x]=="R1") &&  counter_%2==0)
						{
							movable=false;
							cout<<"You can't beat your own figure: "<<tab[y][x]<<endl;
							
						}
						else if((tab[y][x]=="P2" || tab[y][x]=="N2" || tab[y][x]=="Q2" 
						|| tab[y][x]=="B2" || tab[y][x]=="R2") &&  counter_%2==1)
						{
							movable=false;
							cout<<"You can't beat your own figure: "<<tab[y][x]<<endl;
						}
						else{
							movable=true;
						}
				
				}
				else if(abs(x-x_)==1 && y-y_==0)
				{
					if((tab[y][x]=="P1" || tab[y][x]=="N1" || tab[y][x]=="Q1" 
					|| tab[y][x]=="B1" || tab[y][x]=="R1") &&  counter_%2==0)
						{
							movable=false;
							cout<<"You can't beat your own figure: "<<tab[y][x]<<endl;
						}
						else if((tab[y][x]=="P2" || tab[y][x]=="N2" || tab[y][x]=="Q2" 
						|| tab[y][x]=="B2" || tab[y][x]=="R2") &&  counter_%2==1)
						{
							movable=false;
							cout<<"You can't beat your own figure: "<<tab[y][x]<<endl;
						}
						else{
							movable=true;
						}
				}
				else if(abs(x-x_)==1 && abs(y-y_)==1)
				{
					if((tab[y][x]=="P1" || tab[y][x]=="N1" || tab[y][x]=="Q1" 
					|| tab[y][x]=="B1" || tab[y][x]=="R1") &&  counter_%2==0)
						{
							movable=false;
							cout<<"You can't beat your own figure: "<<tab[y][x]<<endl;
						}
						else if((tab[y][x]=="P2" || tab[y][x]=="N2" || tab[y][x]=="Q2" 
						|| tab[y][x]=="B2" || tab[y][x]=="R2") &&  counter_%2==1)
						{
							movable=false;
							cout<<"You can't beat your own figure: "<<tab[y][x]<<endl;
						}
						else{
							movable=true;
						}
				}
				else{
					cout<<"Inappropriate move try again!:"<<endl;
				}	
			}
			tab[y][x]=tab[y_][x_];
			tab[y_][x_]="##";
		}
};
class Horse{
public:
		int x_,y_,counter_;
		Horse(int x,int y,int move)
		{
			x_=x;
			y_=y;
			counter_=move;
		}
		void move_horse()
		{
			int x,y;
			bool movable=false;
			while(movable!=true)
			{
				cout<<"On postion X: ";
				cin>>x;
				cout<<"On position Y: ";
				cin>>y;
				while((x<0||x>8)||(y<0||y>8)) //prevent from escape player chess board
				{
					cout<<"On postion X: ";
					cin>>x;
					cout<<"On position Y: ";
					cin>>y;
				}
				if(((x==x_-1 || x==x_+1) && (x>=0 & x<8))&&((y==y_+2 || y==y_-2) && (y<8 && y>=0))
        		||((x==x_-2 || x==x_+2) && (x>=0 & x<8))&&((y==y_+1 || y==y_-1) && (y<8 && y>=0))) 
				{
					if((tab[y][x]=="P1" || tab[y][x]=="N1" || tab[y][x]=="Q1" 
					|| tab[y][x]=="B1" || tab[y][x]=="K1"  || tab[y][x]=="R1") &&  counter_%2==0)
						{
							movable=false;
							cout<<"You can't beat your own figure: "<<tab[y][x]<<endl;
						}
					else if((tab[y][x]=="P2" || tab[y][x]=="N2" || tab[y][x]=="Q2" 
					|| tab[y][x]=="B2" || tab[y][x]=="K2" || tab[y][x]=="R2") &&  counter_%2==1)
						{
							movable=false;
							cout<<"You can't beat your own figure: "<<tab[y][x]<<endl;
						}
					else{
							movable=true;
					}
				}
				else{
					cout<<"Inappropriate move try again !";
					movable=false;
				}	

			}
			tab[y][x]=tab[y_][x_]; //movement 
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
	//displaying chessboard
    for (int y=-1;y<8;y++){
		if(y==-1)
		{
			cout<<"Y/X| ";
			for(int z=1;z<=8;z++){
				cout << z << "  | ";
			}
			cout<<endl;
		}
		else{
			cout<<" "<<y+1<<" | ";
			for(int x=0;x<8;x++){
				cout << tab[y][x] << " | ";
			}
			cout << "\n";
		}
	}
}

int main()
{
	int i=2;
    board_setup();
	view_board();
	int x,y,counter;
	bool ifmove;
	while(i<=100)
	{	
		bool ifmove =false;
		counter=0; //while working until someone choose their own figures 
			do
			{
				x=-1,y=-1;
				if(tab[y][x]!=("P"+to_string(i%2+1)) && tab[y][x]!=("N"+to_string(i%2+1)) && tab[y][x]!=("Q"+to_string(i%2+1))
				&& tab[y][x]!=("B"+to_string(i%2+1)) && tab[y][x]!=("K"+to_string(i%2+1))  && tab[y][x]!=("R"+to_string(i%2+1)))
				{
					if(counter>0) //skip when it's first move player 
					{
						cout<<"Inappropriate move! Choose your figures! Unable move from: "<<tab[y][x]<<" for Player "<<i%2+1<<". Try again!"<<endl;
					}
					cout<<"Player "<<i%2+1<<" move :"<<endl;
					cout<<"From position X: ";
					cin>>x;
					cout<<"From Position Y: ";
					cin>>y;
					counter++;

					cout<<"Where do you want to move: "<<tab[y][x]<<endl;
					//creating class appropriate to chosen figure 	
					if(tab[y][x]=="P1" || tab[y][x]=="P2") 
					{
						Pionek P(x,y,i);
						if(P.ifMove()==true)
						{
							P.move_pionek();
							view_board();
							ifmove=true;
						}
						else
						{
							cout<<"There is no place where you can move this figures .Your figure is blocked"<<endl;
							ifmove=false;
						}
					}
					else if(tab[y][x]=="R1" || tab[y][x]=="R2")
					{
						Tower T(x,y,i);
						T.move_tower();
						view_board();
						ifmove=true;
					}
					else if(tab[y][x]=="B1" || tab[y][x]=="B2")
					{
						Goniec G(x,y,i);
						G.move_tower();
						view_board();
						ifmove=true;
					}
					else if(tab[y][x]=="Q1" || tab[y][x]=="Q2")
					{
						Queen Q(x,y,i);
						Q.move_queen();
						view_board();
						ifmove=true;
					}
					else if(tab[y][x]=="K1" || tab[y][x]=="K2")
					{
						King K(x,y,i);
						K.move_king();
						view_board();
						ifmove=true;
					}
					else if(tab[y][x]=="N1" || tab[y][x]=="N2")
					{
						Horse H(x,y,i);
						H.move_horse();
						view_board();
						ifmove=true;
					}
				}
			}while(ifmove!=true);
		i++;
	}

    return 0;
}