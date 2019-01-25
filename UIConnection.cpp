//
// Created by Parham Bagherzadeh on 1/22/2019 AD.
//

//
// Created by Parham Bagherzadeh on 1/22/2019 AD.
//
#include "engine.h"
using namespace std;


UIConnection* UIConnection::instance=nullptr;
void UIConnection::showPlayersStates(vector<Pair> states) {
    string str;
    for(int i=0;i<states.size();i++){ // parham roo in warining mide (kolan har jaE ke az function size e vector estefade kardi)
		switch (states[i].getY())
		{
		case 0:
			str = "pending";
			break;
		case 1:
			str = "loser";
			break;
		case 2:
			str = "winner";
			break;

		default:
			break;
		}
        cout<<"player "<<states[i].getX()<< "-> "<< str <<endl;
    }
}
void UIConnection::start() {
    cout<<"game started"<<endl;
}
void UIConnection::end() {
    cout<<"game ended"<<endl;
}
void UIConnection::endClock() {
    cout<<"pause the clock"<<endl;
}
void UIConnection::startClock() {
    cout<<"resume the clock"<<endl;
}
void UIConnection::setClock(int seconds) {
    int clock =seconds;
}
void UIConnection::movePlayer(Event event) {
    cout<<"player "<<(event.getPlayer())->getName()<<"moved to"<<event.getLocation().getX()<<" "<<event.getLocation().getY()<<endl;
}
GameStruct * UIConnection::giveStartData() {
    cout<<"number of players : ?";
    int n;
    cin>>n;
    cout<<"enter x of board"<<endl;
    int x;
    cin>>x;
    cout<<"enter y of board"<<endl;
    int y;
    cin>>y;
    GameStruct * gs=new GameStruct();
    gs->BoardSize=new Pair(x,y);
    for (int i=0;i<n;i++){
        cout<<"enter name of player"<<i<<endl;
        string name;
        cin>>name;
        cout <<"if Auto Player enter (1)"<<endl;
        int isAuto;
        cin>>isAuto;

        gs->playersNames.push_back(name);
        if(isAuto==1){
            gs->isAuto.push_back(true);
        }else{
            gs->isAuto.push_back(false);
        }
    }
    return gs;
}
UIConnection* UIConnection::getInstance() {
    return instance;
}
Pair * UIConnection::giveMove(int index) {
    cout<<"player "<<index+1<<"enter x"<<endl;
    int x;
    cin>>x;
    cout<<"player "<<index+1<<"enter y"<<endl;
    int y;
    cin>>y;
    Pair * loc=new Pair(x,y);
    return loc;
}
void UIConnection::showDice(vector<Dice> dices) {
    cout<<"dices -> ";
    for (int i=0;i<dices.size();i++){
        cout<<dices[i].getValue()<<"   ";  
    }
    cout<<endl;
}
void UIConnection::wrongMove() {
    cout<<"your move was wrong try again"<<endl;
}