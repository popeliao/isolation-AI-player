#ifndef PLAYER
#define PLAYER
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1;
const int MIN = 2;
const int FILLED = 3;
const int EMPTY = 0;
static char g_boardChar[4] = {'-', '-', '-', '*'};

class State{
public:
		unsigned char board[8][8];		
		vector<int> minPos, maxPos;

		vector<vector<int> > successor(int) ; // make a vector of successing moves based on which player is moving
		int successorSize(int mover);
		void print();
		State& operator =(const State& init);
		State(const State&,  int, vector<int>); //initialize a state based on a move of the mover
		void update(int, vector<int>); //update all the members based on a move of the mover
		void moveBack(int, vector<int>);
		State(int);	 //initialize a state based on the mover
		State() {}
		bool isLegal(int, vector<int>); //check whether a move of a mover is legal or not
};

class Eval { // class for evaluation function
	//For pay off
public:	
	vector<vector<int> >wl_; //work list	
	char bitMap_[8][8];
	State s_;

	int evalFunc(State&, int);
	int payoff(State&, int);
	int spread(vector<int> pos);
	bool init(int mover);
};

class AgentAB{
public:
		int depthLimit;
		vector<int> ansMove;
		int step_;
		Eval ev_;

		State searchState_; // current search state
		bool setDepthLimit(int);
		int maxValue(int, int, int); //returns an action of the type int[2], within the depth limit
		int minValue(int, int, int); //returns an action of the type int[2], within the depth limit
		int eval(State&);		
		vector<int>	searchAB(State);
		bool setStep(int);
		
};



class Player{
public:
		State curState;		//var holds the current state 
		AgentAB sab;
		int role;		//MAX or MIN
		vector<int> me, you; // current move made by me and you
		vector<int> lastMe_, lastYou_; // last move made by me and you
		int gameOver;		 // a flag indicate	who win the game
		int step;
		
		void rollBack(); //rollBack two steps
		Player(int);	//initialize the player to be MAX or MIN
		void play();   //play the game
		void timePlay(int);   //play the game in a time-based manner
		void move(); //make a move based on the current state
		void takeIn(); // take in the opponent's move, and deal with roll back
		void putOut();			// output our move
		bool checkLegal(vector<int>);  // check the validity of the opponent's move
		bool checkLose(vector<int>);
		void checkGame();

		void increaseStep(void);
		void decreaseStep(void);
		int depthLimit_;
};
#endif
