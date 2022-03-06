/*  Jai Shree Ram 🚩🚩🚩 */
#include "bits/stdc++.h"

using namespace std;

class Game{

private:
    vector<vector<int>> board;
    int size , win_num;
    int curr_available;
    vector<pair<int,int>> available_pos;
    pair<int,int> generateNewPoint(){
        int sz = available_pos.size();
        int x = rand() % sz;
        return available_pos[x];
    }
    void fill2(){
        auto [x,y] = generateNewPoint();
        board[x][y] = 2;
    }
    void getAvailPos(){
        available_pos.clear();
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                if(board[i][j] == 0) available_pos.push_back({i,j});
            }
        }
    }
    void initializeBoard(){
        checkAndFill();
        checkAndFill();
        printBoard();
    }
    int move(int dir){
        bool f = 0;
        if(dir == 0){ // for upward direction
            for(int j=0;j<size;j++){
                for(int l=0,r=0;r<size;r++){
                    while(l<r && board[l][j] > 0 ) l++;
                    if(board[r][j] > 0 && l != r){
                        board[l][j] = board[r][j];
                        board[r][j] = 0;
                    }
                }
            }
            for(int j=0;j<size;j++){
                for(int i=0;i<size-1;i++){
                    if(board[i][j] == board[i+1][j]){
                        board[i][j] += board[i+1][j];
                        board[i+1][j] = 0;
                        f |= board[i][j] == win_num;
                        i++;
                    }
                }
            }
            for(int j=0;j<size;j++){
                for(int l=0,r=0;r<size;r++){
                    while(l<r && board[l][j] > 0 ) l++;
                    if(board[r][j] > 0 && l != r){
                        board[l][j] = board[r][j];
                        board[r][j] = 0;
                    }
                }
            }
        }
        else if(dir == 1){ // for rightward direction
            for(int i=0;i<size;i++){
                for(int l=size-1,r=size-1;l>=0;l--){
                    while(l<r && board[i][r] > 0 ) r--;
                    if(board[i][l] > 0 && l != r){
                        board[i][r] = board[i][l];
                        board[i][l] = 0;
                    }
                }
            }
            for(int i=0;i<size;i++){
                for(int j=size-1;j>0;j--){
                    if(board[i][j] == board[i][j-1]){
                        board[i][j] += board[i][j-1];
                        board[i][j-1] = 0;
                        f |= board[i][j] == win_num;
                        j--;
                    }
                }
            }
            for(int i=0;i<size;i++){
                for(int l=size-1,r=size-1;l>=0;l--){
                    while(l<r && board[i][r] > 0 ) r--;
                    if(board[i][l] > 0 && l != r){
                        board[i][r] = board[i][l];
                        board[i][l] = 0;
                    }
                }
            }
        }
        else if(dir == 2){ // for downward direction
            for(int j=0;j<size;j++){
                for(int l=size-1,r=size-1;l>=0;l--){
                    while(l<r && board[r][j] > 0 ) r--;
                    if(board[l][j] > 0 && l != r){
                        board[r][j] = board[l][j];
                        board[l][j] = 0;
                    }
                }
            }
            for(int j=0;j<size;j++){
                for(int i=size-1;i>0;i--){
                    if(board[i][j] == board[i-1][j]){
                        board[i][j] += board[i-1][j];
                        board[i-1][j] = 0;
                        f |= board[i][j] == win_num;
                        i--;
                    }
                }
            }
            for(int j=0;j<size;j++){
                for(int l=size-1,r=size-1;l>=0;l--){
                    while(l<r && board[r][j] > 0 ) r--;
                    if(board[l][j] > 0 && l != r){
                        board[r][j] = board[l][j];
                        board[l][j] = 0;
                    }
                }
            }
        }
        else{ // for leftward direction
            for(int i=0;i<size;i++){
                for(int l=0,r=0;r<size;r++){
                    while(l<r && board[i][l] > 0 ) l++;
                    if(board[i][r] > 0 && l != r){
                        board[i][l] = board[i][r];
                        board[i][r] = 0;
                    }
                }
            }
            for(int i=0;i<size;i++){
                for(int j=0;j<size-1;j++){
                    if(board[i][j] == board[i][j+1]){
                        board[i][j] += board[i][j+1];
                        board[i][j+1] = 0;
                        f |= board[i][j] == win_num;
                        j++;
                    }
                }
            }
            for(int i=0;i<size;i++){
                for(int l=0,r=0;r<size;r++){
                    while(l<r && board[i][l] > 0 ) l++;
                    if(board[i][r] > 0 && l != r){
                        board[i][l] = board[i][r];
                        board[i][r] = 0;
                    }
                }
            }
        }
        bool ch_and_f = checkAndFill();
        if(f){
            return 2;
        }
        else if(!ch_and_f) {
            return 1;
        }
        return 0;
    }
    bool checkAndFill(){
        getAvailPos();
        if(available_pos.size() > 0){
            fill2();
            return 1;
        }
        return 0;
    }

public:
    Game(int size , int win_num){
        this->size = size;
        curr_available = size;
        this->win_num = win_num;
        board = vector<vector<int>>(size , vector<int>(size,0));
    }
    
    void play(){
        initializeBoard();
        while(true){
            int dir; cin >> dir;
            int temp = move(dir);
            printBoard();
            if(temp == 2 ){
                cout <<"Win" << endl;
                return;
            }
            else if(temp == 1){
                break;
            }
        }
        cout << "Lose" << endl;
        return;
    }
    void printBoard(){
        cout <<"\t====================" << endl;
        for(int i=0;i<size;i++){
            cout << "\t";
            for(int j=0;j<size;j++){
                if(board[i][j]){
                    cout << board[i][j]<<" ";
                }
                else{
                    cout << "- ";
                }
            }
            cout << endl;
        }
    }
};



int main(int argc, char const *argv[]){

    if (argc != 3){
        printf("\nInvalid arguments...\n");
        return 0;
    }
    int size = stoi(argv[1]) , win_num = stoi(argv[2]);

    Game g(size , win_num);

    g.play();

    return 0;
}