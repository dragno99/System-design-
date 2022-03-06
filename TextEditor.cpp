/*  Jai Shree Ram 🚩🚩🚩 */

// Problem statement - https://leetcode.com/discuss/interview-question/860501/text-editor-implementation

#include "bits/stdc++.h"

using namespace std;

// insert data
// copy index
// paste
// delete (delete last character)
// undo

class Editor{

    class operation{
    public:
        string type;
        string second_arument;
    };

    vector<operation> operations;
    string clipboard;
    string curr_text;
    
    void show(string type){
        cout <<"After applying (" << type <<") text is: ";
        cout << curr_text << endl;
    }

public:
    Editor(){
        clipboard = "";
        curr_text = "";
    }
    void COPY(string index){
        int idx = stoi(index);
        if(idx < 0){
            idx = curr_text.size();
        }
        clipboard = curr_text.substr(idx);
        show("COPY");
    }
    void INSERT(string data){
        operations.push_back(operation({"insert" , data}));
        curr_text += data;
        show("INSERT");
    }
    void PASTE(){
        operations.push_back(operation({"paste" , clipboard}));
        curr_text += clipboard;
        show("PASTE");
    }
    void DELETE(){
        if(!curr_text.empty()){
            operations.push_back(operation({"delete" , string(1,curr_text.back())}));
            curr_text.pop_back();
        }
        show("DELETE");
    }
    void UNDO(){
        if(!operations.empty()){
            operation op = operations.back(); operations.pop_back();
            if(op.type == "paste" || op.type == "insert"){
                int size = op.second_arument.size();
                for(int i=0;i<size;i++){
                    curr_text.pop_back();
                }
            }
            else{
                curr_text += op.second_arument;
            }
        }
        show("UNDO");
    }

};


int main(){ 


    Editor e;

    e.INSERT("Da");
    e.COPY("0");
    e.UNDO();
    e.PASTE();
    e.PASTE();
    e.COPY("2");
    e.PASTE();
    e.PASTE();
    e.DELETE();
    e.INSERT("aaam");
    e.COPY("-2"); // invalid index
    e.PASTE();

    while(true){

        string type; cin >> type; // type of operation

        if(type == "end"){
            break;
        }
        else if(type == "delete"){
            e.DELETE();
        }
        else if(type == "undo"){
            e.UNDO();
        }
        else if(type == "paste"){
            e.PASTE();
        }
        else if(type == "insert" || type == "copy"){

            string second_arument; cin >> second_arument;
            
            if(type == "copy"){
                e.COPY(second_arument);
            }
            else{
                e.INSERT(second_arument);
            }
        }
        else{
            cout <<"Invalid command" << endl;
        }
    }

    return 0;
}
