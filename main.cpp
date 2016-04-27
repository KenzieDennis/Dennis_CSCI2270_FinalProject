#include <iostream>
#include "Telephone.h"

using namespace std;

int MainMenu(){
    cout<<"======Main Menu======"<<endl;
    cout<<"1. Show instructions"<<endl;
    cout<<"2. Add players"<<endl; //Submenu: Add individual Player or Randomly generate certain number of players
    cout<<"3. Remove players"<<endl; //Who would you like to remove
    cout<<"4. Print player list"<<endl;
    cout<<"5. Start game"<<endl; //"transmit message coast to coast"
    cout<<"6. Show word list"<<endl;
    cout<<"7. Add word to word list"<<endl;
    cout<<"8. Clear all players to start new game"<<endl;
    cout<<"9. Quit"<<endl;
    int choice;
    cin>>choice;
    return choice;
}

int main(int argc, char* argv[])
{
    Telephone Game;
    Game.fillWordData();

    int choice = MainMenu();
    while(choice != 9){
        if(choice == 1){
            cout<<" "<<endl;
            cout<<"WELCOME TO THE TELEPHONE GAME!"<<endl;
            cout<<" "<<endl<<" "<<endl;
            cout<<"WHAT IS THE TELEPHONE GAME?"<<endl;
            cout<<" "<<endl;
            cout<<"The telephone game is often played as a children’s party game. In this game, the first player thinks of a message and whispers it to the person sitting next to them, who then whispers it to the person sitting next to them and so on. The message is passed down the line until it eventually reaches the final player who then announces the message to the group."<<endl;
            cout<<" "<<endl;
            cout<<"Errors tend to accumulate as the message is being passed from player to player, and is often significantly different than what it started as by the time it reaches the final player. Generally, the more players there are, the more the message will be distorted. It is often used as a metaphor for the unreliability of human recollection or the inaccuracies of rumor and gossip."<<endl;
            cout<<" "<<endl<<" "<<endl;
            cout<<"SO HOW CAN I PLAY THIS GAME IN THIS PROGRAM?"<<endl;
            cout<<" "<<endl;
            cout<<"This program simulates a group of players playing the telephone game. Begin by: "<<endl;
            cout<<" "<<endl;
            cout<<"     (1) Deciding on player names/positions in line"<<endl;
            cout<<"         **You can either pick names and positions for players yourself, or you can choose to have a list of random player names generated for you."<<endl;
            cout<<" "<<endl;
            cout<<"         **If you mistakenly add a player, or would like to remove a player for any reason, you can choose Delete Player from the main menu."<<endl;
            cout<<" "<<endl;
            cout<<"         **If you'd like to remove all players and start from scratch, choose the Clear All Players option on the main menu."<<endl;
            cout<<" "<<endl;
            cout<<"         **Feel like you have all the correct players in all the correct positions? Choose Print Player List from the main menu to verify."<<endl;
            cout<<" "<<" "<<endl;
            cout<<"Then you're ready to play! The next step is: "<<endl;
            cout<<" "<<endl;
            cout<<"     (2) Crafting a message you'd like to send down the line"<<endl;
            cout<<"         **Make sure your message is comprised of words on the Word List. To view Word List at any time, just choose Show Word List from the main menu"<<endl;
            cout<<" "<<endl;
            cout<<"         **When you're ready to write your message and send it down the line, just choose Start Game from the main menu"<<endl;
            cout<<" "<<" "<<endl;
            choice = MainMenu();
        }
        if(choice == 2){
            cout<<"Would you like to:"<<endl;
            cout<<"1. Add an individual player by name"<<endl;
            cout<<"2. Randomly generate player names"<<endl;
            cin.ignore();
            int subChoice;
            cin>>subChoice;
            if(subChoice == 1){
                string newPlayer;
                string previousPlayer;
                cout<<"Enter new player's name"<<endl;
                cin.ignore();
                getline(cin, newPlayer);
                cout<<"Where would you like to add this player?"<<endl;
                cout<<"1. To the end of the list"<<endl;
                cout<<"2. To the beginning of the list"<<endl;
                cout<<"3. Between existing players"<<endl;
                int position;
                cin>>position;
                if(position == 1){
                    Game.addPlayer("last",newPlayer);
                }
                else if(position == 2){
                    Game.addPlayer("first",newPlayer);
                }
                else if(position == 3){
                    cout<<"Enter name of previous player:"<<endl;
                    cin.ignore();
                    getline(cin, previousPlayer);
                    Game.addPlayer(previousPlayer,newPlayer);
                }
            }
            else{
                cout<<"You can add between 1 and 100 players at a time - How many would you like?"<<endl;
                cin.ignore();
                int players;
                cin>>players;
                Game.randomPlayer(players);
            }
            choice = MainMenu();
        }
        else if(choice == 3){
            cout<<"Who would you like to remove?"<<endl;
            cin.ignore();
            string delPlayer;
            getline(cin, delPlayer);
            Game.deletePlayer(delPlayer);
            choice = MainMenu();
        }
        else if(choice == 4){
            Game.printPlayerList();
            choice = MainMenu();
        }
        else if(choice == 5){
            cin.ignore();
            string message;
            Game.showWordList();
            cout<<"What message would you like to start with?"<<endl;
            getline(cin, message);
            if(Game.checkIfValid(message)){
                Game.transmitMsg(message);
            }
            else{
                cout<<"Sorry, one or more of your words is not on the approved word list. Please try again"<<endl;
            }
            choice = MainMenu();
        }
        else if(choice == 6){
            Game.showWordList();
            choice = MainMenu();
        }
        else if(choice == 7){
            cin.ignore();
            string MainWord;
            string List;
            cout<<"Enter the word you'd like to add to the word list: "<<endl;
            getline(cin, MainWord);
            cout<<" "<<endl;
            cout<<"Enter at least one word that may be mistaken for the word you added"<<endl;
            cout<<"To enter multiple words, just type each word separated by a space"<<endl;
            cout<<"For example, if your word is cat, you might enter: bat fat sat mat"<<endl;
            getline(cin, List);
            Game.addWords(MainWord, List);
            choice = MainMenu();
        }
        else if(choice == 8){
            Game.deleteAll();
            choice = MainMenu();
        }
        else{
            cout<<"Sorry, that's not a valid choice. Please pick an option from the menu"<<endl;
            choice = MainMenu();
        }
    }
    if(choice == 9){
        cout<<"Goodbye!"<<endl;
    }

    return 0;
}
