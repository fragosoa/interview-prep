#include<bits/stdc++.h>
using namespace std;

enum class CharacterType{
    ENEMY,
    PLAYER
};

class Character{
protected:
    int stamina;
    int x;
    int y;
    CharacterType charType;
    
    
public:
    Character(){
        stamina = 10;
        x = 0;
        y = 0;
    }
    int  getX(){
        return x;
    }
    int getY(){
        return y;
    }
    int getStamina(){
        return stamina;
    }
    void currentPosition(){
        cout << "player is at position " << getX() << " " << getY() <<  endl;
    }
    
    virtual void receiveAttack() = 0;
    
    void moveTo(int x_,int y_){
        x= x_;
        y=y_;
    }
    
    
    
};



class Player: public Character {

public:
    Player(int stamina_,int x_,int y_){
        stamina = stamina_;
        x = x_;
        y = y_;
        charType = CharacterType::PLAYER;
    }
    void init(){
        cout << "initializing player" << endl;
    }
    void receiveAttack() override{
        cout << "you received damage" << endl;
        stamina -= 1;
    }
   
    
};

class Enemy: public Character {

public:
    Enemy(int stamina_,int x_,int y_){
        stamina = stamina;
        x = x_;
        y = y_;
        charType = CharacterType::ENEMY;
    }
    void init(){
        cout << "initializing enemy" << endl;
    }
    void receiveAttack() override{
        stamina -= 2;
    }
   
    
};

class WorldMap{
private:
    static constexpr int ROWS = 10;
    static constexpr int COLS = 10;
    
    int worldMap[ROWS][COLS];
    
public:
     WorldMap(){
         for(int i=0;i<ROWS;i++){
            for(int j=0;j<COLS;j++){
                worldMap[i][j] = 0;
            }
        }
     }
     
     void printWorldMap(){
         for(int i=0;i<ROWS;i++){
            for(int j=0;j<COLS;j++){
                cout << worldMap[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
     }
     
     bool isValidPosition(int x,int y){
         return (x>=0  && x<ROWS && y>=0 && y<COLS);
     }
};

class Game{
private:
    Player player{100,0,0};
    bool isRunning = false;
    WorldMap world;
   
    
    
    // Method definition
    void showUserOptions(){
        cout << "1.- move" << endl;
        cout << "2.- receive damage" << endl;
        cout << "3.- get stamina" << endl;
        cout << "4.- print current position" << endl;
        cout << "5.- print current map" << endl;
        
        cout << "-1.- end" << endl;
    }
    void movePlayer(){
        int x,y;
        cout << "what x y?" << endl;
        cin>>x>>y;
        if(world.isValidPosition(x,y)){
            cout << "moved from" << player.getX() << " " << player.getY() << " to " << x << " , " << y << endl;
            player.moveTo(x,y);
        }
        else{
            cout << "cannot move outside of map limits" << endl;
        }
    }
    void processUserInput(int option){
        switch(option){
            case 1:
                movePlayer();
                break;
            case 2:
                player.receiveAttack();
                break;
                
            case 3:
                cout << "player stamina is : " << player.getStamina() << endl;
                break;
            case 4:
                // player position
                player.currentPosition();
                break;
            case 5:
                world.printWorldMap();
                break;
            case -1:
                endGame();
                break;
        }
    }
    void endGame(){
        isRunning = false;
    }
    void startRunning(){
        isRunning = true;
    }
    void getSystemInput(){
        cout << "what to do?" << endl;
        
        showUserOptions();
        
        int option;
        cin>>option;
        
        processUserInput(option);
    }
public:
    Game(){
        player.init();
        
    }
    void start(){
        startRunning();
        
        while(isRunning){
            getSystemInput();
        }
        
    }
    
    
    
   
};



int main(){
    Game game;
    game.start();
    return 0;
}










