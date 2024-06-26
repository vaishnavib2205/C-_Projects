#include<iostream>
#include<string>

using namespace std;

void delay(int milliseconds)
{
    for(int i = 0; i< milliseconds * 1000000; i++)
    {
        //delay loop
    }
}

int main()
{
    string playerName;
    char choice;
    int health = 100; //player's initial health
    srand(static_cast<unsigned int>(time(nullptr)));

    cout<<"Welcome to the text adventure game!\n";
    cout<<"------------------------------------\n";
    cout<<"Enter your name: ";
    getline(cin, playerName); //getline is reading from an input stream in your C++ program


    cout<<"\nHello, "<<playerName<<"!YOU WAKE UP IN A MYSTICAL LAND.\n\n";
    delay(5000);
    cout<<"You have 100 health points. Your goal is tp find the treasure and survive!\n\n";
      delay(4000);

    cout<<"You find yourself on crossroad. Which path will you take?\n";
    cout<<"a) Follow the path through the forest. \n";
    cout<<"b) Explore the dark cave. \n";
    cout<<"c) Climb the mountain.\n";
    cout<<"Enter your choice(a, b or c): ";
    cin>>choice;


switch(choice){

    case 'a':
    cout<<"\nYou decide to follow the path through the forest.\n";
    delay(2000);
    cout<<"As you walk, you hear rustling in the bushes...\n";
   
    if(rand() %2 == 0)
    {
        cout<<"Oh no! Its a bear! You lose all your healthy points.\n";
        health -= 100;
        delay(2000);
    }
    else{
        cout<<"Phew! It was just the wind.\n";
    }
    break;

    case 'b':
    cout<<"\nYou decide to explore the dark cave.\n";
    delay(2000);
    cout<<"You enter cautiously, and your eyes slowly adjust to the darkness...\n";
    if(rand()%2 == 0)
    {
    cout<<"Oops! You stumble upon a trap and lose 80 health points.\n";
    health -= 80;
    }else{
        cout<<"You find chest full of gold! Gain 50 healthy points.\n";
    health += 50;
    }
    break;


    case 'c':
    cout<<"\nYou decide to climb the moutain.\n";
    delay(2000);
    cout<<"The climb is tough, but the view from the top is breathtaking!\n";
    delay(2000);
    cout<<"You feel invigorated and gain 10 healthy points.\n";
    health += 10;
    break;

    default:
    cout<<"\nInvalid choice. The adventure ends here.\n";
    return 0;

}

cout<<"\nCurrent health: "<< health <<" points.\n";

if(health <= 80)
{
    cout<<"Oh no! Your health has dropped.";
    cout<<"-------------GAME OVER-----------------\n";
}else
{
    cout<<"Congratulations, "<<playerName<<"!YOU SURVIVED the first leg of the journey.\n";
    cout<<"Now, for continue to experience adventure again, play the game again!\n";
}

return 0;

}