# Dennis_CSCI2270_FinalProject
# Project Summary:

 I used a linked list to simulate the game "telephone". The telephone game is often played as a children’s party game. In this game, the first player thinks of a message and whispers it to the person sitting next to them, who then whispers it to the person sitting next to them and so on. The message is passed down the line until it eventually reaches the final player who then announces the message to the group. 

Errors tend to accumulate as the message is being passed from player to player, and is often significantly different than what it started as by the time it reaches the final player. Generally, the more players there are, the more the message will be distorted. It is often used as a metaphor for the unreliability of human recollection or the inaccuracies of rumors and gossip.

This code stores the list of players as a linked list. The list of words you can use to create a message is stored in a vector of the datatype "Word" which includes a string (the word) and a vector of strings (the list of rhyming words - words that a person in real life might mistake the original word for). You can add players to the linked list at the beginning, middle, or end. If you randomly generate player list, it adds each player to the end of the linked list. You can also delete players and clear the list. The word list is just what was listed as the most common english nouns, verbs, and adjectives and then words that rhyme with those words. You can add words to the word list in the program by choosing that option in the main menu. 

Once you start the game (option 5 on the menu), the message you type goes through the transmit message function. Originally, I was going to do this similarly to how we did the communication network assignment, but it worked better to store each word individually in a vector, change the words as many times as needed depending on the number of players (number of nodes in linked list), and then printing out each word again at the end. 


# How to run: 

The files needed to run this program are: "main.cpp", "Telephone.cpp", "Telephone.h", and "WordData.txt".
When you run the program, this menu will appear:

======Main Menu======
1. Show instructions
2. Add players
3. Remove players
4. Print player list
5. Start game
6. Show word list
7. Add word to word list
8. Clear all players to start new game
9. Quit

The first thing you need to do is create your player list. You can do this with the "Add players" option. You have the option of creating your own list of players and determining the order, or creating a randomly generated list of characters. You can also remove players or clear all the players. To check the current list, choose "Print player list". 

Once you've determined your player list, choose "Start game" and you will be prompted to create a message using words in the word list. You can also add your own words to the word list. 

These instructions are written into the code as well - just choose "Show instructions" in the main menu.

# Dependencies
Files: "main.cpp", "Telephone.cpp", "Telephone.h", and "WordData.txt"

# System Requirements
Works in virtual machine we've been using in CSCI 2270

# Group Members
Me

# Contributers
Got the words in my WordData.txt file from www.englishclub.com and www.rhymer.com

# Open Issues/Bugs



