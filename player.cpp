#include "Player.h"
extern char g_boardChar[4];
/*********State Control********/
int State::successorSize(int mover) {
		int resultn = 0;
		int srow, scol;
		if (mover == MAX) {
				srow = maxPos[0];	
				scol = maxPos[1];
		}
		else {
				srow = minPos[0];		
				scol = minPos[1];
		}
		vector<int> move;		
		move.push_back(srow);
		move.push_back(scol);		
		//north
		while (move[0] > 0 && board[move[0] - 1][move[1]] == 0) {
				move[0]--;
				resultn++;
		}
		move[0] = srow;
		//south				
		while (move[0] < 7 && board[move[0] + 1][move[1]] == 0) {
				move[0]++;
				resultn++;
		}
		move[0] = srow;
		//west
		while (move[1] > 0 && board[move[0]][move[1] - 1] == 0) {
				move[1]--;
				resultn++;
		}
		move[1] = scol;
		//east 
		while (move[1] < 7 && board[move[0]][move[1] + 1] == 0) {
				move[1]++;
				resultn++;
		}
		move[1] = scol;
		//northwest
		while (move[0] > 0 && move[1] > 0 && board[move[0] - 1][move[1] - 1] == 0) {
				move[0]--;  move[1]--;
				resultn++;
		}
		move[0] = srow; move[1] = scol; 
		//northeast
		while (move[0] > 0 && move[1] < 7 && board[move[0] - 1][move[1] + 1] == 0) {
				move[0]--;  move[1]++;
				resultn++;
		}
		move[0] = srow; move[1] = scol; 
		//southwest
		while (move[0] < 7 && move[1] > 0 && board[move[0] + 1][move[1] - 1] == 0) {
				move[0]++;  move[1]--;
				resultn++;
		}
		move[0] = srow; move[1] = scol; 
		//southeast
		while (move[0] < 7 && move[1] < 7 && board[move[0] + 1][move[1] + 1] == 0) {
				move[0]++;  move[1]++;
				resultn++;
		}
		move[0] = srow; move[1] = scol; 
		return resultn;
}
vector<vector<int> > State::successor(int mover) {
		// make a vector of successing moves based on which player is moving
		vector <vector<int> > result;
		int srow, scol;
		if (mover == MAX) {
				srow = maxPos[0];	
				scol = maxPos[1];
		}
		else {
				srow = minPos[0];		
				scol = minPos[1];
		}
		vector<int> move;		
		move.push_back(srow);
		move.push_back(scol);		
		//north
		while (move[0] > 0 && board[move[0] - 1][move[1]] == 0) {
				move[0]--;
				result.push_back(vector<int>(move));
		}
		move[0] = srow;
		//south				
		while (move[0] < 7 && board[move[0] + 1][move[1]] == 0) {
				move[0]++;
				result.push_back(vector<int>(move));
		}
		move[0] = srow;
		//west
		while (move[1] > 0 && board[move[0]][move[1] - 1] == 0) {
				move[1]--;
				result.push_back(vector<int>(move));
		}
		move[1] = scol;
		//east 
		while (move[1] < 7 && board[move[0]][move[1] + 1] == 0) {
				move[1]++;
				result.push_back(vector<int>(move));
		}
		move[1] = scol;
		//northwest
		while (move[0] > 0 && move[1] > 0 && board[move[0] - 1][move[1] - 1] == 0) {
				move[0]--;  move[1]--;
				result.push_back(vector<int>(move));
		}
		move[0] = srow; move[1] = scol; 
		//northeast
		while (move[0] > 0 && move[1] < 7 && board[move[0] - 1][move[1] + 1] == 0) {
				move[0]--;  move[1]++;
				result.push_back(vector<int>(move));
		}
		move[0] = srow; move[1] = scol; 
		//southwest
		while (move[0] < 7 && move[1] > 0 && board[move[0] + 1][move[1] - 1] == 0) {
				move[0]++;  move[1]--;
				result.push_back(vector<int>(move));
		}
		move[0] = srow; move[1] = scol; 
		//southeast
		while (move[0] < 7 && move[1] < 7 && board[move[0] + 1][move[1] + 1] == 0) {
				move[0]++;  move[1]++;
				result.push_back(vector<int>(move));
		}
		move[0] = srow; move[1] = scol; 
		return result;
}
void State::print() {
		for (int i = 0; i < 8; i++) {
				for (int j = 0; j < 8; j++){
						cout <<  g_boardChar[(int)board[i][j]];	
				}
				cout << endl;
		}
		cout << endl;
}
State::State(int mover){
		for (int i = 0; i < 8; i++) 
				for (int j = 0; j < 8; j++){
						board[i][j] = 0;	
				}
		if (mover == MAX) {
				board[0][0] = MAX;		
				board[7][7] = MIN;		
				maxPos = vector<int>(2, 0);
				minPos = vector<int>(2, 7);
		}
		else {
				board[0][0] = MIN;		
				board[7][7] = MAX;		
				maxPos = vector<int>(2, 7);
				minPos = vector<int>(2, 0);
		}
}
State& State::operator =(const State& init){
		//a copy constructor
		for (int i = 0; i < 8; i++) 
				for (int j = 0; j < 8; j++)
						board[i][j] = init.board[i][j];			
		maxPos = vector<int>(init.maxPos);
		minPos = vector<int>(init.minPos);
		return *this;
}

State::State(const State& init,  int mover, vector<int> move){
		//initialize a state based on a move of the mover
		for (int i = 0; i < 8; i++) 
				for (int j = 0; j < 8; j++)
						board[i][j] = init.board[i][j];			
		maxPos = vector<int>(init.maxPos);
		minPos = vector<int>(init.minPos);
		if (mover == MAX) {
				board[maxPos[0]][maxPos[1]] = FILLED;
				maxPos = vector<int>(move);
				board[maxPos[0]][maxPos[1]] = MAX;
		}
		else {
				board[minPos[0]][minPos[1]] = FILLED;
				minPos = vector<int>(move);
				board[minPos[0]][minPos[1]] = MIN;
		}
}
bool State::isLegal(int mover, vector<int> move){		//check whether a move of a mover is legal or not		
		vector<vector<int> > moveList = successor(mover);
		vector<vector<int> >::iterator iter;
		for (iter = moveList.begin(); iter!=moveList.end(); iter++) {
				if (move[0] == iter->at(0) && move[1] == iter->at(1))
						return true;
		}
		return  false;
}
void State::update(int mover, vector<int> move) { //update all the members based on a move of the mover
		if (mover == MAX) {
				board[maxPos[0]][maxPos[1]] = FILLED;
				maxPos = vector<int>(move);
				board[maxPos[0]][maxPos[1]] = MAX;
		}
		else {
				board[minPos[0]][minPos[1]] = FILLED;
				minPos = vector<int>(move);
				board[minPos[0]][minPos[1]] = MIN;
		}
}
void State::moveBack(int mover, vector<int> move) { //go back to a state before a move of the mover
				if (mover == MAX) {
				board[maxPos[0]][maxPos[1]] = EMPTY;
				maxPos = vector<int>(move);
				board[maxPos[0]][maxPos[1]] = MAX;
		}
		else {
				board[minPos[0]][minPos[1]] = EMPTY;
				minPos = vector<int>(move);
				board[minPos[0]][minPos[1]] = MIN;
		}
}


/*********Search Agent********/
//conduct the minimax alpha-beta search based on a State
//return the best move, noticing that depthLimit needs to be bound
vector<int>	AgentAB::searchAB(State s) {		
		ansMove = vector<int>(2, -1); // initialize as a lose move
		searchState_ = s;
		maxValue(depthLimit, INT_MIN, INT_MAX);		// here will change the value of ansMove
		return ansMove;
}
bool AgentAB::setDepthLimit(int i) {
		depthLimit = i;
		return true;
}
int AgentAB::maxValue(int depth, int alpha, int beta) {
		//returns a value and an action in vector<int> ansMove
		//within the depth limit
		if (depth == 0)
				return eval(searchState_);
		int v = INT_MIN;
		vector<vector<int> >moveList = searchState_.successor(MAX);	
		if (depth == depthLimit && moveList.size() != 0) { // if there is a legal movement, at least use it
				ansMove[0] = moveList[0][0];
				ansMove[1] = moveList[0][1];
		}
		vector<vector<int> >::iterator iter;
		vector<int> tmpPos;
		for (iter = moveList.begin(); iter != moveList.end(); iter++) {
				tmpPos = searchState_.maxPos;
				searchState_.update(MAX, *iter);
				int tmp = minValue( depth - 1, alpha, beta);
				searchState_.moveBack(MAX,  tmpPos);
				if (v < tmp) {
						v = tmp;
						if (depth == depthLimit) 
								ansMove = (*iter);														
				}
				if (v >= beta)
						return v;
				alpha = max(v, alpha);
		}
		return v;
}
int AgentAB::minValue(int depth, int alpha, int beta) {
		//returns a value and an action in vector<int> ansMove
		//within the depth limit
		if (depth == 0)
				return eval(searchState_);
		int v = INT_MAX;
		vector<vector<int> >moveList = searchState_.successor(MIN);
		vector<vector<int> >::iterator iter;
		vector<int> tmpPos;
		for (iter = moveList.begin(); iter != moveList.end(); iter++) {
				tmpPos = searchState_.minPos;
				searchState_.update(MIN, *iter);
				int tmp = maxValue(depth - 1, alpha, beta);
				searchState_.moveBack(MIN, tmpPos);
				if (v > tmp) {
						v = tmp;
						if (depth == depthLimit) 
								ansMove = (*iter);														
				}				
				if (v <= alpha)
						return v;
				beta = min(v, beta);
		}
		return v;
}
bool AgentAB::setStep(int ss) {
	step_ = ss;
	return true;
}
int AgentAB::eval(State& s) {		
		return  ev_.evalFunc(s, step_); 
}

/*********Eval********/
int Eval::evalFunc(State& s, int step) {
	//control:	s.successorSize(MAX)-s.successorSize(MIN) 
	//payoff:	payoff(s,MAX) - payoff(s,MIN)
	s_ = s; //init the state;
	int score = 0;
	if (step < 8) { 	//opening, ctrl is important
		score = s.successorSize(MAX)-s.successorSize(MIN);
	} 
	else if (step < 15) {
		int control = (s.successorSize(MAX)-s.successorSize(MIN)) * 5;
		int payff = payoff(s,MAX) - payoff(s,MIN);
		score = control + payff;
	}
	else {				//ending, payoff is important
		score = payoff(s,MAX) - payoff(s,MIN);
	}
	return score;
}
int Eval::payoff(State& s, int mover) {
	// calculate the compartive payoff for mover
	int score = 0;
	int delta = 5;	
	//s_ = s;
	init(mover);
	int toSpreadn;
	vector<int> cur;		 //to spread pos
	while (delta > 0 && wl_.size() > 0) {
		cur = wl_[0];
		wl_.erase(wl_.begin());
		toSpreadn = spread(cur); // will update tl_ and wl_
		score += toSpreadn * delta;
		delta--;		
	}
	return score;
}
int Eval::spread(vector<int> pos){	
		int srow, scol;
		srow = pos[0];	
		scol = pos[1];		
		vector<int> move = pos;	
		int toSpreadn = 0;					
		//north
		while (move[0] > 0 && s_.board[move[0] - 1][move[1]] == 0) {
				move[0]--;
				if (bitMap_[move[0]][move[1]] == 0) {
					wl_.push_back(vector<int>(move));
					bitMap_[move[0]][move[1]] == 1;
					toSpreadn++;
				}
		}
		move[0] = srow;
		//south				
		while (move[0] < 7 && s_.board[move[0] + 1][move[1]] == 0) {
				move[0]++;
				if (bitMap_[move[0]][move[1]] == 0) {
					wl_.push_back(vector<int>(move));
					bitMap_[move[0]][move[1]] == 1;
					toSpreadn++;
				}
		}
		move[0] = srow;
		//west
		while (move[1] > 0 && s_.board[move[0]][move[1] - 1] == 0) {
				move[1]--;
				if (bitMap_[move[0]][move[1]] == 0) {
					wl_.push_back(vector<int>(move));
					bitMap_[move[0]][move[1]] == 1;
					toSpreadn++;
				}
		}
		move[1] = scol;
		//east 
		while (move[1] < 7 && s_.board[move[0]][move[1] + 1] == 0) {
				move[1]++;
				if (bitMap_[move[0]][move[1]] == 0) {
					wl_.push_back(vector<int>(move));
					bitMap_[move[0]][move[1]] == 1;
					toSpreadn++;
				}
		}
		move[1] = scol;
		//northwest
		while (move[0] > 0 && move[1] > 0 && s_.board[move[0] - 1][move[1] - 1] == 0) {
				move[0]--;  move[1]--;
				if (bitMap_[move[0]][move[1]] == 0) {
					wl_.push_back(vector<int>(move));
					bitMap_[move[0]][move[1]] == 1;
					toSpreadn++;
				}
		}
		move[0] = srow; move[1] = scol; 
		//northeast
		while (move[0] > 0 && move[1] < 7 && s_.board[move[0] - 1][move[1] + 1] == 0) {
				move[0]--;  move[1]++;
				if (bitMap_[move[0]][move[1]] == 0) {
					wl_.push_back(vector<int>(move));
					bitMap_[move[0]][move[1]] == 1;
					toSpreadn++;
				}
		}
		move[0] = srow; move[1] = scol; 
		//southwest
		while (move[0] < 7 && move[1] > 0 && s_.board[move[0] + 1][move[1] - 1] == 0) {
				move[0]++;  move[1]--;
				if (bitMap_[move[0]][move[1]] == 0) {
					wl_.push_back(vector<int>(move));
					bitMap_[move[0]][move[1]] == 1;
					toSpreadn++;
				}
		}
		move[0] = srow; move[1] = scol; 
		//southeast
		while (move[0] < 7 && move[1] < 7 && s_.board[move[0] + 1][move[1] + 1] == 0) {
				move[0]++;  move[1]++;
				if (bitMap_[move[0]][move[1]] == 0) {
					wl_.push_back(vector<int>(move));
					bitMap_[move[0]][move[1]] == 1;
					toSpreadn++;
				}
		}
		move[0] = srow; move[1] = scol; 		
		return toSpreadn;
}
bool Eval::init(int mover){
	wl_.clear(); //work list	
	for (int i = 0; i < 8; i++) 
				for (int j = 0; j < 8; j++){
						bitMap_[i][j] = 0;	
				}
	if (mover == MAX)
		wl_.push_back(s_.maxPos);
	else
		wl_.push_back(s_.minPos);
	bitMap_[wl_[0][0]][wl_[0][1]] = 1;

	return true;
}

/*********Player********/
Player::Player(int mover) : depthLimit_(0)
{	//initialize the player to be MAX or MIN
		curState = State(mover);
		role = mover;
		if (role == MAX) {				
				me = vector<int>(2, 0);				
				you = vector<int>(2, 7);
				g_boardChar[MAX] = 'x';
				g_boardChar[MIN] = 'o';
		}
		else {
				me = vector<int>(2, 7);				
				you = vector<int>(2, 0);
				g_boardChar[MAX] = 'o';
				g_boardChar[MIN] = 'x';
		}
		lastMe_ =  me;
		lastYou_ = you;

}
void Player::timePlay(int timeLimit) {   //play the game in a time-based manner
		// I think my program is able to run within 30s, thus this function is leaved blank
}
void Player::play(){   //play the game		
		// Player would increase step every time one makes a movement,
		// And modify it depthlimit every 5 steps
		gameOver = 0; // nobody wins the game
		step = 0;
		depthLimit_ = 7;
		sab.setDepthLimit(depthLimit_);
		if (role == MIN) {
				takeIn();
				curState.print();				
		}				
		move();		putOut();
		curState.print();		
		takeIn();	
		curState.print();		
		while (gameOver == 0) {
				move();		putOut();
				curState.print();				
				if (gameOver == 0) {
						takeIn();			
						curState.print();						
				}
		}
		checkGame();		
}
void Player::checkGame() {
		if (gameOver == MAX) 
				cout << "I win!" << endl;
		else 
				cout << "Opponent win!" << endl;
}
void Player::rollBack() {
		curState.moveBack(MAX, lastMe_);
		decreaseStep();
		curState.moveBack(MIN, lastYou_);
		decreaseStep();
		me = lastMe_;
		you = lastYou_;
}
void Player::move() {//make a move based on the move made by the opponent
		lastMe_ = me;
		sab.setStep(step);
        cout << "Computing. Be patient, it takes time to become intelligent" << endl;
		me = sab.searchAB(curState);		
		if (!checkLose(me))
				curState.update(MAX, me);
		else 
				gameOver = MIN;
		increaseStep();
}
void Player::takeIn(){ // take in the opponent's move, and deal with roll back
		int i, j;
		cin >> i >> j;
		if (i == -1 && j == -1) {
				rollBack();				
				cout << "Insert you move again" << endl;
				takeIn();
		}
		else {
				lastYou_ = you;				
				you[0] = i; you[1] = j;
				you[0]--; you[1]--;				
				char c;
				while (!checkLegal(you) ) {
						cout << "Are u sure that u input something illegal y/n?" << endl;						
						cin >> c;
						if (c == 'y') {
								gameOver = MAX;	
								return;
						}
						cin >> i >> j;
						you[0] = i; you[1] = j;
						you[0]--; you[1]--;
				}
				curState.update(MIN, you);				
				increaseStep();
		}
}
void Player::putOut(){			// output our move
		cout << '(' << me[0]+1 << "," << me[1]+1 << ')' << endl;
}
bool Player::checkLegal(vector<int> m) {	// check the validity of the opponent's move
		return curState.isLegal(MIN, m);
}
bool Player::checkLose(vector<int> m) {
		return ((m[0] == -1) && (m[1] == -1));
}
void Player::increaseStep(void)
{
		step++;
		cout << "step " << step << endl;
		if (step <= 16) {
				depthLimit_ = 7;
				sab.setDepthLimit(depthLimit_);
				cout << "DepthLimit = " << sab.depthLimit << endl;
		} 
		else {
				depthLimit_ = 8;
				sab.setDepthLimit(depthLimit_);
				cout << "DepthLimit = " << sab.depthLimit << endl;
		} 
}
void Player::decreaseStep(void)
{
		step--;
		if (step <= 16) {
				depthLimit_ = 7;
				sab.setDepthLimit(depthLimit_);
				cout << "DepthLimit = " << sab.depthLimit << endl;
		} 
		else {
				depthLimit_ = 8;
				sab.setDepthLimit(depthLimit_);
				cout << "DepthLimit = " << sab.depthLimit << endl;
		} 		
}
