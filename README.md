# Card-game

A Non Gui card game made with c++  

### Rules

-There are five players in the game , including the human player . 
The numbers in the cards are irrelevant . 
The game is played by rounds ,  so in  each rounds the Human player plays first 
He / She must select a card to swap  
The card would be given to the next player . 

For example : 
Player 0 gave player 1 S5 ; // means you swapped whatever incoming card you had for s5 and now you passing s5 to the next player . 

To preview what card you will be receiving ;

An activity format will be displayed to you , for example : 

        Player 0 gave Player 1 S4

        Player 1 gave Player 2 H8

        Player 2 gave Player 3 S9

        Player 3 gave Player 4 Q2

        Player 4 gave Player 0 DQ
        
        
Human player is getting a card from Dq (means D with queens) ,  at every time the human player always receive He/Her card from Player 4 .

At the end of every round , the game checks who has all the same type of card ( Spades , Hearts , Queen , D ) ,  and those or whoever have such arrangement is the winner .

### Architecture overview

Developed using objected oriented programming in c++ 

In which you have the player class and auto player (the computer players ) are derived from the player class . 

The main difference between two classes is chooseCard method . The Choosecard method is made polymorphic and implemented in different ways . 

In player it is implemented by using asking for a input from the console , where the player picks a card (a - g ) . 

Meanwhile when the Auto player is made ,  the computer makes decision on which card to swap there is no input . This is implemented  using frequency sort that is the card with least frequency is chosen to be swapped with the new card .
