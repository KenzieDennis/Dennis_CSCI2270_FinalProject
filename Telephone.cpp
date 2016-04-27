#include "Telephone.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>

using namespace std;

Telephone::Telephone()
{
    head = NULL;
}

Telephone::~Telephone()
{
    //dtor
}

void Telephone::addPlayer(string previousPlayer, string newPlayer)
{
    if(head == NULL){
        Player *n = new Player;
        n->name = newPlayer;
        n->next = NULL;
        n->previous = NULL;
        head = n;
        cout<<newPlayer<<" was added to the game!"<<endl;
    }
    else{ //head != NULL
        if(previousPlayer == "first"){
            Player *n = new Player;
            n->name = newPlayer;
            n->next = head;
            n->previous = NULL;
            head->previous = n;
            head = n;
            cout<<newPlayer<<" was added to the game!"<<endl;
        }
        else if(previousPlayer == "last"){
            Player *temp = head;

            while(temp->next != NULL){
                temp = temp->next;
            }

            Player *n = new Player;
            n->name = newPlayer;
            n->next = NULL;
            n->previous = temp;
            temp->next = n;
            cout<<newPlayer<<" was added to the game!"<<endl;

        }
        else{ //head != null and user gave name of a previous player
            //search until you find previous player, add new player in between
            Player *n = new Player;
            n->name = newPlayer;
            Player *temp = head;
            bool found = false;

            while(!found && temp->next != NULL){
                if(temp->name == previousPlayer){
                    found = true;
                }
                else{
                    temp = temp->next;
                }
            }

            if(temp->next == NULL){ //temp is last
                if(!found){
                    cout<<"Previous player not found, adding new player to end of list"<<endl;
                }
                temp->next = n;
                n->next = NULL;
                n->previous = temp;
                cout<<newPlayer<<" was added to the game!"<<endl;
            }

            else{
                n->next = temp->next;
                temp->next->previous = n;

                temp->next = n;
                n->previous = temp;
                cout<<newPlayer<<" was added to the game!"<<endl;
            }
        }
    }
}

void Telephone::printPlayerList()
{
    if(head == NULL){
        cout<<"No players yet"<<endl;
    }
    else{ //there's at least one player
        Player *temp = head;
        int counter = 0;
        cout<<"===Players==="<<endl;
        while(temp != NULL){
            counter++;
            cout<<"Player "<<counter<<": "<<temp->name<<endl;
            temp = temp->next;
        }
    }
}

void Telephone::randomPlayer(int number)
{
    srand(time(NULL));
    string names[] = {"Sophia", "Emma", "Olivia","Isabella","Mia","Ava","Lily","Zoe","Emily","Chloe","Layla","Madison",
"Madelyn","Abigail","Aubrey","Charlotte","Amelia","Ella","Kaylee","Avery","Aaliyah","Evelyn","Hannah","Addison",
"Riley","Harper","Aria","Alaina","Mackenzie","Willow","Celeste","Adalyn","Grace","Brooklyn","Ellie","Anna","Kaitlyn",
"Isabelle","Sophie","Scarlett","Natalie","Leah","Sarah","Nora","Mila","Elizabeth","Lillian","Kylie","Audrey","Lucy",
"Jackson","Aiden","Liam","Lucas","Noah","Mason","Jayden","Ethan","Jacob","Jack","Caden","Logan","Benjamin","Michael","Caleb",
"Ryan","Alexander","Elijah","James","William","Oliver","Connor","Matthew","Daniel","Luke","Brayden","Jayce","Henry","Carter",
"Dylan","Gabriel","Joshua","Nicholas","Isaac","Owen","Nathan","Grayson","Eli","Landon","Andrew","Max","Samuel","Gavin","Wyatt",
"Christian","Hunter","Cameron","Evan","Charlie","David"};

    if(number > 100){
        cout<<"Sorry, that's too many players. Try again with a number less than 101"<<endl;
    }
    if(number < 101){
    for(int i = 0; i < number; i++){
        int random;
        random = rand() % 100 + 0;
        addPlayer("last",names[random]);
        }
    }

}

void Telephone::deletePlayer(string delPlayer)
{
    bool found = false;
    if(head == NULL){
        cout<<"No players yet"<<endl;
    }
    else{ //head != NULL
        Player *temp = head;

        while(temp != NULL){

            if(temp->name == delPlayer){
                found = true;
                if(temp -> previous == NULL){ //head
                    if(head->next == NULL){
                        head = NULL;
                        delete temp;
                        cout<<delPlayer<<" left the game!"<<endl;
                    }
                    else{
                        head = head->next;
                        head->previous = NULL;
                        delete temp;
                        cout<<delPlayer<<" left the game!"<<endl;
                    }
                }
                else if(temp -> next == NULL){ //end
                    Player *node = temp;
                    temp = temp->previous;
                    temp->next = NULL;
                    delete node;
                    cout<<delPlayer<<" left the game!"<<endl;
                }
                else{
                    Player *node = temp;
                    node->next->previous = node->previous;
                    node->previous->next = node->next;
                    delete node;
                    cout<<delPlayer<<" left the game!"<<endl;
                }
            }
            temp = temp->next;
        }
    }
    if(found == false){
        cout<<"Player not found"<<endl;
    }
}

void Telephone::deleteAll()
{
    while(head != NULL){
        deletePlayer(head->name);
    }
}

void Telephone::transmitMsg(string message)
{
    vector<Data> comm; //vector to put individual words of message in

    if(head != NULL){
        Player *temp = head;

        ////counting how many words in message////
        string counterline = message;
        string counterparts;
        istringstream counteriss(counterline);
        int numberOfParts = 0;
        while(counteriss >> counterparts){
            numberOfParts++;
        }

        ////splitting message into words and putting in vector////
        string line = message;
        string part;

        istringstream iss(line);

        while(iss){ //while there is an iss
            while(iss >> part){ //for each part of iss
                Data newData;
                newData.name = part;
                newData.original = part;
                comm.push_back(newData);
            }
        }

        ////Making changes for each player////
        int CountingPlayers = 0;
        temp = head;

        while(temp != NULL){ //loop through player linked list

            string ToChange;
            ToChange = comm[CountingPlayers].original;
            for(int i = 0; i < MainWordList.size(); i++){ //check Main Word list for current word
                if(ToChange == MainWordList[i].name){ //if found
                    int Change = rand() % MainWordList[i].rhymes.size() + 0;
                    string different = MainWordList[i].rhymes[Change]; //change current name to one of its rhymes
                    string old = comm[CountingPlayers].name;
                    comm[CountingPlayers].name = different;
                    cout<<temp->name<<" heard "<<comm[CountingPlayers].name<<" instead of "<<old<<"!"<<endl;
                }
            }
            CountingPlayers++;
            if(CountingPlayers >= numberOfParts){ //if more players than number of words, start over again
                CountingPlayers = 0;
            }
            temp = temp->next;

        }

        //print final vector after changes are made
        cout<<"The final message is: ";

        for(int i = 0; i < comm.size(); i++){
            cout<<comm[i].name<<" ";
        }
        cout<<endl;
    }

    else{ //head == null
        cout<<"No players yet."<<endl;
    }
}

void Telephone::fillWordData()
{
    string line;
    string tmp;
    ifstream in_stream;
    in_stream.open("WordData.txt");
    while(!in_stream.eof()){
        getline(in_stream, line);
        Word temp;
        int counter = 0;
        istringstream iss(line);
        while(iss){
            while(iss >> tmp){
                if(counter == 0){
                    temp.name = tmp;
                    counter++;
                }
                else{
                    temp.rhymes.push_back(tmp);
                }
            }
        }
            MainWordList.push_back(temp);
    }
}

void Telephone::showWordList()
{
    cout<<" "<<endl;
    cout<<"Here's a list of the words you can use to build your starting sentence: "<<endl;
    cout<<" "<<endl;
    for(int i = 0; i < MainWordList.size(); i++){
        cout<<MainWordList[i].name<<", ";
    }
    cout<<endl;
}

bool Telephone::checkIfValid(string message)
{
    string line = message;
    string part;

    istringstream iss(line);
    bool found = false;

    while(iss){
        while(iss>>part){
            found = false;
            for(int i = 0; i < MainWordList.size(); i++){
                if(MainWordList[i].name == part){
                    found = true;
                }
            }
            if(found == false){
                return false;
                break;
            }
        }
    }
    return true;
}

void Telephone::addWords(std::string MainWord, std::string List)
{
    Word newWord;
    newWord.name = MainWord;

    vector<string> newRhymes;
    string RhymeWord;

    istringstream iss(List);
    while(iss){
        while(iss >> RhymeWord){
            newRhymes.push_back(RhymeWord);
        }
    }

    newWord.rhymes = newRhymes;
    MainWordList.push_back(newWord);
    cout<<"You added "<<MainWord<<" to the word list!"<<endl;
}
