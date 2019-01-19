#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <time.h>




struct Card
{
	// a card is defined  in the datatype of struct 
	std::string displayvalue;
	std::string actualvalue;
	int frequency;
};

class Player {

	private:

		
		void replenish (int letterasciiv)
		{
			// this is the method that changes the card in player hands

			// it changes the letter form a-g to position values in vector , then does the swap 

			this-> discardIndex = abs(97-letterasciiv);


			//Its takes the value of the discardlist on which it wants to swap in and stores it in a temp variable

			// then takes the card he wants to replace in another variable 

			// then swap them

			
			Card Toswapcad = discardlist[this->takeFrom];


			Card Togocard = this->hand[discardIndex]; // set the card to pick the one user does not want from the card


			Player::discardlist[selfIndex] = Togocard;


			this->hand[discardIndex] = Toswapcad;


			std::cout << std::endl;

			std::cout << "	"<< "Player " << this->selfIndex << " gave Player 1 " << Togocard.actualvalue << std::endl;


		}
		

	protected:

			static Card discardlist[5];
			// the default is that of the player 
		 	int selfIndex = 0;     //index within player vector, starting with 0 for the human
 			int takeFrom = 4;  //player supplying new Card

 			
 			int discardIndex;   //position within hand of card being discarded
 			std::vector<Card> hand;

 			Card defaultcard = {"z","4"};


 			//Card discard = hand[discardIndex];    //card being discarded

 


	public: 

			static void displaycl();

			//player() = default;
			Player()
			{
				for(int k = 0;k<7;k++)
				{
					Card defaultcardx = {"z","4",0};
					this->hand.push_back(defaultcardx);
					this->showcards();
				}								
			}
			Player(std::vector<Card> topickcard,int begin) 
			{
				//constructor take the vector full of randomized cards and have an offset to start from so that it does not take a card
				// the same card as the next player , the cards will be randomized then distributed lineraly . For example player one will
				// take card from 0-6, player 2 will take from 7 - 13 and so on 

				for(int k = 0;k<7;k++)
				{
					this->hand.push_back(topickcard[k+begin]);
					//std::cout<< "yeah";
				}

			}

			static void  chnagedisplaycard(Card exa,int k)
			{
				// THIS changes the discard list cards incase the card is being passed around too much , it is also used to 
				//set default of cards
				Player::discardlist[0]=exa;
				Player::discardlist[1]=exa;
				Player::discardlist[2]=exa;
				Player::discardlist[3]=exa;
				Player::discardlist[4]=exa;

			}

			void changecardvalue(Card h,int indexo)
			{
				// this is a function that is used to debug 

				this->hand[indexo] = h;

			}

			bool everythingequal()
			{
				std::string  ku = this->hand[0].displayvalue;
				bool result = true;

				for(int k = 0;k<7;k++)
				{
					if(this->hand[k].displayvalue!=ku)
					{
						result = false;
						break;
					}
				}

				return result;
			}


			void showcards()
			{

				
				for(int i = 0;i<7;i++)
				{
					std::cout << "	"<<this->hand[i].actualvalue << " ";
				}

				std::cout << std::endl;

				for(int i = 0;i<7;i++)
				{
					char a = i+97;
					std::cout << "	" << a << " " ;
				}

					std::cout << std::endl;
				
			}

			std::vector<Card> getcopyofcurrentcards()
			{
				return hand;
			}


				virtual void chooseDiscard(int decimaasciivalue)
			{
			// this is the method that changes 
			//void replenish( );

			// user can only input from a - g

			// this takes the char value from the user 

					this->replenish(decimaasciivalue);
			}


};

class Autoplayer : public Player {


	private:
			static void  processchangeofcard()
			{
				// THIS is the decision maker that makes the decision of wether to change the call 
				std::cout << "life" << std::endl;
			}


			void getthemaximumval()
			{

			}




	public:
			// this sets the index for the auto player
			// it also sets the take from the auto player  
			// it sets the take from to previous index precidng it . 
			// FOR example index 3 to 2

			Autoplayer()
			{
				// The auto player should never ever be called by the default constructor
			}

			Autoplayer(std::vector<Card> topickcardu,int beginy,int indexi) : Player(topickcardu,beginy)
			{

				this->selfIndex = indexi;
				this->takeFrom = this->selfIndex-1;
				//constructor take the vector full of randomized cards and have an offset to start from so that it does not take a card
				// the same card as the next player , the cards will be randomized then distributed lineraly . For example player one will
				// take card from 0-6, player 2 will take from 7 - 13 and so on 					

			}
			int mapc(Card tempc)
			{

				// this is a function that transform cards to integers so the lowest can be counted by using  frquency 
				// think of it as a number id for the card ; 



				if(tempc.displayvalue== "S")
				{
					return 0;
				}
				else if(tempc.displayvalue=="H")
				{
					return 1;
				}
				else if(tempc.displayvalue=="D")
				{
					return 2;
				}
				else
				{
					return 3;
				}
			}

			std::string unpac(int k)
			{

				// this is a function that integers to cards 
				// think of it as a number id for the card ; 
				if(k==0)
				{
					return "S";
				}
				else if(k==1)
				{
					return "H";
				}
				else if(k==2)
				{
					return "D";
				}
				else
				{
					return "Q";
				}
			}

			std::string getlowest(std::string namec)
			{
				// this functions does a systematic sort , it gives a group of CARDs or a card That have the lowest frequency
				// this function returns vectors with the lowest frequency

				//int lowestf = mapc(this->hand[0]);

				

				int sf =0;

				int hf = 0;

				int df = 0;

				int qf = 0;
			

				for(int i = 0;i<7;i++)
				{
					if(mapc(this->hand[i])==0)
					{
						sf++;
					}
					else if(mapc(this->hand[i])==1)
					{
						hf++;
					}
					else if(mapc(this->hand[i])==2)
					{
						df++;
					}
					else
					{
						qf++;
					}
				}


				std::vector<int> moblower = {sf,hf,df,qf};

				int min = 6;

				for(int k = 0;k<4;k++)
				{
					std::string g = unpac(k);
					if((moblower[k] < min) && (moblower[k]!=0) && (g != namec))
					{
						min = moblower[k];
					}
				}
				std::string result = "S";

				if(sf==min)
				{
					return result;
				}
				if(hf==min)
				{
					result = "H";
					return result;
				}
				if(df==min)
				{
					result = "D";
					return result;
				}
				if(qf==min)
				{
					result = "Q";
					return result;
				}

			}
			int choosefrom(std::string facevofcard)
			{
				int index = 0;

				for(int i = 0;i<7;i++)
				{
					if(this->hand[i].displayvalue == facevofcard)
					{
						index = i;
						break;
					}
				}

				return index;
			}

			void chooseDiscard(int k)
			{
				// this choses the cards that is going to be discarded

				// it takes another form of the choosediscard in base class 

				// it takes the card available for autocard 
				// The method getlowest uses a simple method to choose the card that is about to be discarded 


				Card takein = Player::discardlist[this->takeFrom];
				std::string getlowestfv = getlowest(takein.displayvalue);

				this->discardIndex = choosefrom(getlowestfv);

				



				Card togo = this->hand[discardIndex];



				this->hand[this->discardIndex] = takein;

				Player::discardlist[selfIndex] = togo;

				int next = selfIndex+1;
				if(next==5)
				{
					next =0;
				}

				std::cout << std::endl;

				std::cout << "	"<< "Player " << this->selfIndex << " gave Player " << next << " " << togo.actualvalue << std::endl;

				//this->showcards();


			}


};

// the static discardlist will be initially  populated with the non card member

Card idefaultcard = {"z","0",0};
Card specialcard = {"Q","3",0};
Card aspc = {"U","8",0};
Card tte = {"R","2",0};
Card Player::discardlist[5] = {idefaultcard,aspc,tte,idefaultcard,specialcard};

void Player::displaycl()
{
	// this is used for debugging to display the card on the discardlist
	for(int k = 0;k<5;k++)
	{
		std::cout << Player::discardlist[k].displayvalue;
	}
}

std::vector<Card> generatecards()
{
	// this generates random positioned cards
	// it uses the struct structure to define cards 
	// it gives cards from SPADES, HEARTS,D, AND Q . where it generates 13 for each category making ti 52
	// each card type(spades , hearts etc having staus to them (king ,queek , jack and numbers) , where numbers are from 1-9 and ace)

	std::vector<Card> gencard;

	for(int j = 0;j<52;j++)
	{
		// 0 - 12 is for spade 

		int k = j/13;
		int r = j%13;
		std::string facevalue;
		std::string statusvalue;

		// this set the face value 
		if(k==0)
		{
			facevalue = "S";
		}
		else if(k == 1)
		{
			facevalue = "H";
		}
		else if(k == 2)
		{
			facevalue = "D";
		}
		else
		{
			facevalue = "Q";
		}

		if(r == 0)
		{
			statusvalue = "A";

		}
		else if(r>=1 && r<=9)
		{
			statusvalue = std::to_string(r);
		}
		else if(r==10)
		{
			statusvalue	= "J";
		}
		else if(r==11)
		{
			statusvalue = "Q";
		}
		else if(r==12)
		{
			statusvalue = "K";
		}

		Card temp = {facevalue,facevalue+statusvalue,0};

		gencard.push_back(temp);

	}


	return gencard;
}


void printplayershands(std::vector<Player *> playersx)
{
	// This function takes in a a vector of pointers to Player objects so that the value can be printed
	// 

	std::cout << std::endl;

	for(int g=0;g<playersx.size();g++)
	{
		Player temp1 = * playersx[g];
		std::vector<Card> tempcards = temp1.getcopyofcurrentcards();
		std::cout << g << ":	";
		for(int k = 0;k<7;k++)
		{
			std::cout << tempcards[k].actualvalue << "	";
		}

		std::cout << std::endl;
		std::cout << std::endl;
	}
}


int main()
{
	// firs step generate cards 
	srand(time(NULL));
	std::vector<Card> dealtcards = generatecards();

	std::random_shuffle(dealtcards.begin(),dealtcards.end());

	std::cout << dealtcards.size() <<std::endl;

	Player user(dealtcards,0);

	Autoplayer comp1(dealtcards,7,1);

	Autoplayer comp2(dealtcards,14,2);

	Autoplayer comp3(dealtcards,21,3);

	Autoplayer comp4(dealtcards,28,4);

	// this defaultcard available on the list;

	int changeindex = 35;



	Player::chnagedisplaycard(dealtcards[changeindex],0);

	std::vector<Player *> players;
	players.push_back(&user);
	players.push_back(&comp1);
	players.push_back(&comp2);
	players.push_back(&comp3);
	players.push_back(&comp4);


	//user.chooseDiscard(5);

	//std::cout << "changed" << std::endl;

	//comp3.chooseDiscard();
	//comp2.chooseDiscard();

	//printplayershands(players);



	int winner = 0;


	while(true)
	{



				char  userinput;

			while(true)
			{
				std::cout << "your hand : " << std::endl;

				std::cout << std::endl;

				user.showcards();

				std::cin >> userinput;

				int decimaasciivalue = int(userinput);

				if(!((decimaasciivalue>103) || (decimaasciivalue<97) ))
				{
					user.chooseDiscard(decimaasciivalue);
					break;
				}
				else if(decimaasciivalue==63)
				{
					// print the values of the cards
					printplayershands(players);

				}
				else
				{
					std::cout << "invalid choice" << std::endl;
				}


			}

		comp1.chooseDiscard(1);
		comp2.chooseDiscard(2);
		comp3.chooseDiscard(3);
		comp4.chooseDiscard(4);


		if(user.everythingequal())
		{
			std::cout<<std::endl;
			std::cout <<"	"<<"Player 0 is winner " << std::endl;
			winner++;
		}
		if(comp1.everythingequal())
		{
			std::cout<<std::endl;
			std::cout <<"	"<<"Player 1 is winner " << std::endl;
			winner++;
		}
		if(comp2.everythingequal())
		{
			std::cout<<std::endl;
			std::cout <<"	"<<"Player 2 is winner " << std::endl;
			winner++;
		}
		if(comp3.everythingequal())
		{
			std::cout<<std::endl;
			std::cout <<"	"<<"Player 3 is winner " << std::endl;
			winner++;
		}
		if(comp4.everythingequal())
		{
			std::cout<<std::endl;
			std::cout <<"	"<<"Player 4 is winner " << std::endl;
			winner++;
		}

		if(winner>0)
		{
			printplayershands(players);
			break;
		}






	}


	return 0;

}

