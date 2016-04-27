#ifndef TELEPHONE_H
#define TELEPHONE_H
#include <iostream>
#include <vector>

using namespace std;

struct Player{
    std::string name;
    std::string message;
    Player *next;
    Player *previous;

    Player(){}; //default constructor

    Player(std::string initName, Player *initNext, Player *initPrevious, std::string initMessage)
    {
        name = initName;
        next = initNext;
        previous = initPrevious;
        message = initMessage;

    }
};


struct Word{
    std::string name;
    vector<string> rhymes;
};

struct Data{
    std::string name;
    std::string original;
};


class Telephone
{
    public:
        Telephone();
        ~Telephone();
        void addPlayer(std::string previousPlayer, std::string newPlayer);
        void deletePlayer(std::string delPlayer);
        void randomPlayer(int);
        void printPlayerList();
        void transmitMsg(string);
        void deleteAll();
        void fillWordData();
        void showWordList();
        bool checkIfValid(string message);
        void addWords(std::string MainWord, std::string List);
    protected:
    private:
        Player *head;
        vector<Word> MainWordList;

};

#endif // TELEPHONE_H
