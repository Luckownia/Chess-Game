#include<iostream>
#include<vector>

using namespace std;

string tab[8][8];
vector <string> beatenFigures1;
vector <string> beatenFigures2;

class Pawn{
public:
	int x_,y_,move_;
	Pawn(int x,int y,int move)
	{
		x_=x;
		y_=y;
		move_=move;
	}

	bool ifBeatOwnFigure(int x,int y)
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
	bool ifMove(){ //checking if figure isn't blocked
		if(move_%2==0 && tab[y_-1][x_]=="##") //player1 verticaly
		{
			return true;
		}
		//player 1 diagonially 
		else if(move_%2==0 && ((tab[y_-1][x_-1]!="##" && (x_>0 && y_>0 )) || (tab[x_+1][y_-1]!="##" &&(x_<7 && y_>0))))
		{
			if(ifBeatOwnFigure(x_-1,y_-1) || ifBeatOwnFigure(x_+1,y_-1))
			{
				return true;
			}
			else{
				return false;
			}
		}
		else if(move_%2==1 && tab[y_+1][x_]=="##"){ //player 2 verticaly
			return true;
		}	
		else if(move_%2==1 &&((tab[y_+1][x_+1]!="##" && (x_<7 && y_<7 )) ||(tab[y_+1][x_-1]!="##" &&(x_>0 && y_<7))))
		{
			if(ifBeatOwnFigure(x_+1,y_+1) || ifBeatOwnFigure(x_-1,y_+1))
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
	void move_pawn()
	{
		int x,y;
		bool movable=false;
		while(movable!=true)
		{
			do  //prevent from escape player chess board
			{
				cout<<"On postion X: ";
				cin>>x;
				cout<<"On position Y: ";
				cin>>y;	
			} while((x<0||x>8)||(y<0||y>8));

			if((y-y_==1 && move_%2==1)||(y-y_==-1 && move_%2==0) ) //Pawn player 1 and 2 movement 
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
							(move_%2==0) ? beatenFigures1.push_back(tab[y][x]) : beatenFigures2.push_back(tab[y][x]); //add beaten figures
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
			else if(((y-y_==2 && move_%2==1)||(y-y_==-2 && move_%2==0)) && (y_==1 || y_==6)) //first movement Pawn 
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
		//Promotion checking
		if((y==0 && move_%2==0) || (y==7 && move_%2==1))
		{
			int number;
			cout<<"Which one figure do you wanna bring back?: "<<endl;
			cin>>number;
			(move_%2==0)?  beatenFigures1.erase(beatenFigures1.begin()+number+1):
			beatenFigures1.erase(beatenFigures1.begin()+number+1);
			(move_%2==0)?  tab[y][x]=beatenFigures1[number+1]:tab[y][x]=beatenFigures2[number+1];
		}
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
		bool ifMove()
		{
			if((y_<7 && ifBeatOwnFigure(x_,y_+1) ) || ( y_>0 && ifBeatOwnFigure(x_,y_-1))|| 
			(x_<7 && ifBeatOwnFigure(x_+1,y_))|| (x_>0 && ifBeatOwnFigure(x_-1,y_)))
			{
				return true;
			}
			else{
				return false;
			}
		}
		bool ifBeatOwnFigure(int x_g,int y_g)  
		{
			int x,y;
			bool ifcan = false;
			x=x_g;
			y=y_g;
			if(x-x_==0 && y-y_!=0) 
				{
					int start = min(y,y_);
					int end =  max(y_,y);

					for(int i=start; i<=end;i++)
					{
						if((tab[i][x]=="P1" || tab[i][x]=="N1" || (tab[i][x]=="R1" && i!=y_)
						|| tab[i][x]=="B1" || tab[i][x]=="K1") &&  counter_%2==0)
						{
							ifcan=false;
							cout<<"You can't beat your own figure: "<<tab[i][x]<<endl;
							break;
						}
						else if((tab[i][x]=="P2" || tab[i][x]=="N2" || tab[i][x]=="B2" 
						|| (tab[i][x]=="R2" && i!=y_)|| tab[i][x]=="K2") &&  counter_%2==1)
						{
							ifcan=false;
							cout<<"You can't beat your own figure: "<<tab[i][x]<<endl;
							break;
						}
						else{
							if(tab[y][x]!="##")
							{
								(counter_%2==0)? beatenFigures1.push_back(tab[y][x]):beatenFigures2.push_back(tab[y][x]);
								ifcan=true;
								break;
							}
							else{
								ifcan = true;
							}
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
						|| tab[y][i]=="K1" || (tab[y][i]=="R1" && i!=x_)  ) &&  counter_%2==0)
						{
							ifcan=false;
							cout<<"You can't beat your own figure: "<<tab[y][i]<<endl;
							break;
						}
						else if((tab[y][i]=="P2" || tab[y][i]=="N2"  || tab[y][i]=="B2" 
						|| tab[y][i]=="K2" || (tab[y][i]=="R2" && i!=x_)) &&  counter_%2==1)
						{
							ifcan=false;
							cout<<"You can't beat your own figure: "<<tab[y][i]<<endl;
							break;
						}
						else{
							if(tab[y][x]!="##")
							{
								(counter_%2==0)? beatenFigures1.push_back(tab[y][x]):beatenFigures2.push_back(tab[y][x]);
								ifcan=true;
								break;
							}
							else{
								if(tab[y][x]!="##")
								{
									(counter_%2==0)? beatenFigures1.push_back(tab[y][x]):beatenFigures2.push_back(tab[y][x]);
									ifcan=true;
									break;
								}
								else{
									ifcan = true;
								}
							}
						}
					}
				}
				else{
					cout<<"Inappropriate move try again!"<<endl;
				}
				return ifcan;	
		}
		void move_tower()
		{
			int x,y;
			bool movable=false;
			while(movable!=true)
			{
				do //prevent from escape player chess board 
				{
					cout<<"On postion X: ";
					cin>>x;
					cout<<"On position Y: ";
					cin>>y;
				} while((x<0||x>8)||(y<0||y>8));
				
				movable=ifBeatOwnFigure(x,y);
			}	
			tab[y][x]=tab[y_][x_];
			tab[y_][x_]="##";
		}
};

class Bishop :public Tower{
	public:
		using Tower::Tower;
		bool ifMove()
		{
			if(((x_<7 && y_<7)&&ifBeatOwnFigure(x_+1,y_+1))||((x_<7 && y_>0)&&ifBeatOwnFigure(x_+1,y_-1)) 
			|| ((x_>0 && y_<7)&&ifBeatOwnFigure(x_-1,y_+1)) || ((x_>0 && y_>0)&&ifBeatOwnFigure(x_-1,y_-1)))
			{
				return true;
			}
			else{
				return false;
			}
		}
		bool ifBeatOwnFigure(int x_g,int y_g) 
		{
			bool ifcan =false;
			int x,y;
			x=x_g;
			y=y_g;
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
							ifcan=false;
							cout<<"You can't beat your own figure: "<<tab[y_+i*colD][x_+i*rowD]<<endl;
							break;
						}
						else if((tab[y_+i*colD][x_+i*rowD]=="P2" || tab[y_+i*colD][x_+i*rowD]=="N2" || tab[y_+i*colD][x_+i*rowD]=="Q2" 
						|| tab[y_+i*colD][x_+i*rowD]=="B2" || tab[y_+i*colD][x_+i*rowD]=="K2" || tab[y_+i*colD][x_+i*rowD]=="R2") &&  counter_%2==1)
						{
							ifcan=false;
							cout<<"You can't beat your own figure: "<<tab[y_+i*colD][x_+i*rowD]<<endl;
							break;
						}
						else{
							if(tab[y][x]!="##")
							{
								(counter_%2==0)? beatenFigures1.push_back(tab[y][x]):beatenFigures2.push_back(tab[y][x]);
								ifcan=true;
								break;
							}
							else{
								ifcan = true;
							}
						}
					}
				}
				else{
					cout<<"Inappropriate move try again! "<<endl;
				}
				return ifcan;
		}
		void move_bishop()
		{
			int x,y;
			bool movable=false;
			while(movable!=true)
			{
				do //prevent from escape player chess board
				{
					cout<<"On postion X: ";
					cin>>x;
					cout<<"On position Y: ";
					cin>>y;
				} while((x<0||x>8)||(y<0||y>8));
				
				movable = ifBeatOwnFigure(x,y);
			}
			tab[y][x]=tab[y_][x_];
			tab[y_][x_]="##";
		}
};
class Queen:public Bishop{
	public:
		using Bishop::Bishop;
		bool ifMove()
		{
			if(Tower::ifMove()) 
			{
				return true;
			}
			else if(Bishop::ifMove())
			{
				return true;
			}
			else{
				return false;
			}
		}
		void move_queen()
		{
			int x,y;
			bool movable=false;
			while(movable!=true)
			{
				do //prevent from escape player chess board
				{
					cout<<"On postion X: ";
					cin>>x;
					cout<<"On position Y: ";
					cin>>y;
				} while((x<0||x>8)||(y<0||y>8));
				if(x-x_==0 && y-y_!=0 || (x-x_!=0 && y-y_==0) ){
					movable = Tower::ifBeatOwnFigure(x,y); // For tower's movement 
				}
				else if(abs(x_-x)==abs(y_-y)) // For bishop's movement 
				{
					movable = Bishop::ifBeatOwnFigure(x,y);
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
		bool ifBeatOwnFigure(int x_g,int y_g)
		{
			int y,x;
			y=y_g;
			x=x_g;
			
			if((tab[y][x]=="P1" || tab[y][x]=="N1" || tab[y][x]=="Q1" 
			|| tab[y][x]=="B1" || tab[y][x]=="R1") &&  counter_%2==0)
				{
					cout<<"You can't beat your own figure: "<<tab[y][x]<<endl;
					return false;	
				}
				else if((tab[y][x]=="P2" || tab[y][x]=="N2" || tab[y][x]=="Q2" 
				|| tab[y][x]=="B2" || tab[y][x]=="R2") &&  counter_%2==1)
				{
					cout<<"You can't beat your own figure: "<<tab[y][x]<<endl;
					return false;
				}
				else{
					if(tab[y][x]!="##")
					{
						(counter_%2==0)? beatenFigures1.push_back(tab[y][x]):beatenFigures2.push_back(tab[y][x]);
					}
					return true;
				}
		}
		bool ifMove()
		{
			bool ifcan =false;
			if (
				(y_ > 0 && ifBeatOwnFigure(x_, y_-1) ) ||
				(y_ < 7 && ifBeatOwnFigure(x_, y_+1)) ||
				(x_ > 0 && ifBeatOwnFigure(x_-1, y_)) ||
				(x_ < 7 && ifBeatOwnFigure(x_+1, y_) ) ||
				((x_ < 7 && y_ < 7) && ifBeatOwnFigure(x_+1, y_+1)) ||
				((x_ > 0 && y_ < 7)&&ifBeatOwnFigure(x_-1, y_+1)) ||
				((x_ < 7 && y_ > 0)&&ifBeatOwnFigure(x_+1, y_-1)) ||
				((x_ > 0 && y_ > 0)&&ifBeatOwnFigure(x_-1, y_-1) )
   			 )
			{
				ifcan=true;
			}
			return ifcan;
		}
		void move_king()
		{
			int x,y;
			bool movable=false;
			while(movable!=true)
			{
				do  //prevent from escape player chess board 
				{
					cout<<"On postion X: ";
					cin>>x;
					cout<<"On position Y: ";
					cin>>y;
				} while((x<0||x>8)||(y<0||y>8));

				if(x-x_==0 && abs(y-y_)==1)
				{
					movable=ifBeatOwnFigure(x,y);
				}
				else if(abs(x-x_)==1 && y-y_==0)
				{
					movable=ifBeatOwnFigure(x,y);
				}
				else if(abs(x-x_)==1 && abs(y-y_)==1)
				{
					movable=ifBeatOwnFigure(x,y);
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
		bool ifBeatOwnFigure(int x_g,int y_g)
		{
			int x,y;
			bool ifcan = false;
			x=x_g;
			y=y_g;
			if((tab[y][x]=="P1" || tab[y][x]=="N1" || tab[y][x]=="Q1" 
			|| tab[y][x]=="B1" || tab[y][x]=="K1"  || tab[y][x]=="R1") &&  counter_%2==0)
				{
					ifcan=false;
					cout<<"You can't beat your own figure: "<<tab[y][x]<<endl;
				}
			else if((tab[y][x]=="P2" || tab[y][x]=="N2" || tab[y][x]=="Q2" 
			|| tab[y][x]=="B2" || tab[y][x]=="K2" || tab[y][x]=="R2") &&  counter_%2==1)
				{
					ifcan=false;
					cout<<"You can't beat your own figure: "<<tab[y][x]<<endl;
				}
			else{
				if(tab[y][x]!="##")
				{
					(counter_%2==0)? beatenFigures1.push_back(tab[y][x]):beatenFigures2.push_back(tab[y][x]);
					ifcan=true;
				}
				else{
					ifcan = true;
				}
			}

			return ifcan;
		}
		bool ifMove()
		{
			if((x_>0 & y_>1)&&(ifBeatOwnFigure(x_-1,y_-2))|| ((x_>0 & y_<6) && ifBeatOwnFigure(x_-1,y_+2)) || 
			((x_<7 & y_>1)&&ifBeatOwnFigure(x_+1,y_-2)) || ((x_<7 & y_<6)&&ifBeatOwnFigure(x_+1,y_+2)) || 
			((x_>1 & y_<7)&&ifBeatOwnFigure(x_-2,y_+1)) || ((x_>1 & y_>0)&&ifBeatOwnFigure(x_-2,y_-1)) ||
			((x_>1 & y_<7)&&ifBeatOwnFigure(x_+2,y_+1)) || ((x_>1 & y_>0)&&ifBeatOwnFigure(x_+2,y_-1)))
			{
				return true;
			}
			else{
				return false;
			}
		}
		void move_horse()
		{
			int x,y;
			bool movable=false;
			while(movable!=true)
			{
				do  //prevent from escape player chess board
				{
					cout<<"On postion X: ";
					cin>>x;
					cout<<"On position Y: ";
					cin>>y;
				} while((x<0||x>8)||(y<0||y>8));
		
				if(((x==x_-1 || x==x_+1) && (x>=0 & x<8))&&((y==y_+2 || y==y_-2) && (y<8 && y>=0))
        		||((x==x_-2 || x==x_+2) && (x>=0 & x<8))&&((y==y_+1 || y==y_-1) && (y<8 && y>=0))) 
				{
					movable=ifBeatOwnFigure(x,y);
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

void view_board(int counter)
{
	//displaying chessboard
    for (int y=-1;y<8;y++){
		if(y==-1)
		{
			cout<<"Y/X| ";
			for(int z=1;z<=8;z++){
				cout << z << "  | ";
			}
			if(counter%2==1)
			{
				cout<<"   "<<"Figures beaten by Player 1: ";
				for(int i=0;i<beatenFigures1.size();i++)
				{
					cout<<beatenFigures1[i];
				}
			}
			else{
				cout<<"   "<<"Figures beaten by Player 2: ";
				for(int i=0;i<beatenFigures2.size();i++)
				{
					cout<<beatenFigures2[i];
				}
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
	view_board(i);
	int x,y,counter;
	bool ifmove;
	while(i<=100)
	{	
		bool ifmove =false;
		counter=0; //while working until someone choose their own figures 
			while(ifmove!=true)
			{
				do
				{
					if(counter>0) //skip when it's first player's move  
					{
						cout<<"Inappropriate move! Choose your figures! Unable move from: "<<tab[y][x]<<" for Player "<<i%2+1<<". Try again!"<<endl;
					}
					cout<<"Player "<<i%2+1<<" move :"<<endl;
					cout<<"From position X: ";
					cin>>x;
					cout<<"From Position Y: ";
					cin>>y;
					counter++;
				} while(tab[y][x]!=("P"+to_string(i%2+1)) && tab[y][x]!=("N"+to_string(i%2+1)) && tab[y][x]!=("Q"+to_string(i%2+1))
				&& tab[y][x]!=("B"+to_string(i%2+1)) && tab[y][x]!=("K"+to_string(i%2+1))  && tab[y][x]!=("R"+to_string(i%2+1)));

					cout<<"Where do you want to move: "<<tab[y][x]<<endl;
					//creating class appropriate to chosen figure 	
					if(tab[y][x]=="P1" || tab[y][x]=="P2") 
					{
						Pawn P(x,y,i);
						if(P.ifMove()==true) //checking if figure isn't blocked (if there is free space)
						{
							P.move_pawn();
							view_board(i);
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
						if(T.ifMove()==true)//checking if figure isn't blocked (if there is free space)
						{
							T.move_tower();
							view_board(i);
							ifmove=true;
						}
						else{
							cout<<"There is no place where you can move this figures .Your figure is blocked"<<endl;
							ifmove=false;
						}
					}
					else if(tab[y][x]=="B1" || tab[y][x]=="B2")
					{
						Bishop G(x,y,i);
						if(G.ifMove()==true)//checking if figure isn't blocked (if there is free space)
						{	
							G.move_bishop();
							view_board(i);
							ifmove=true;
						}
						else{
							cout<<"There is no place where you can move this figures .Your figure is blocked"<<endl;
							ifmove=false;
						}

					}
					else if(tab[y][x]=="Q1" || tab[y][x]=="Q2")
					{
						Queen Q(x,y,i);
						if(Q.ifMove()==true)//checking if figure isn't blocked (if there is free space)
						{
							Q.move_queen();
							view_board(i);
							ifmove=true;
						}
						else{
							cout<<"There is no place where you can move this figures .Your figure is blocked"<<endl;
							ifmove=false;
						}

					}
					else if(tab[y][x]=="K1" || tab[y][x]=="K2")
					{
						King K(x,y,i);
						if(K.ifMove()==true)//checking if figure isn't blocked (if there is free space)
						{
							K.move_king();
							view_board(i);
							ifmove=true;
						}
						else{
							cout<<"There is no place where you can move this figures .Your figure is blocked"<<endl;
							ifmove=false;
						}
					}
					else if(tab[y][x]=="N1" || tab[y][x]=="N2")
					{
						Horse H(x,y,i);
						if(H.ifMove()==true)//checking if figure isn't blocked (if there is free space)
						{
							H.move_horse();
							view_board(i);
							ifmove=true;
						}
						else{
							cout<<"There is no place where you can move this figures .Your figure is blocked"<<endl;
							ifmove=false;
						}
					}
			}
		i++;
	}

    return 0;
}