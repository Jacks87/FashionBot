// FinalProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Jackelin Britton
//Final Project C++ II
//Chatbot FashionBot

//<iostream> contains all the functions of program like cout, cin
//<string> to include variables
//<fstream> to include file stream (ofstream/ifstream)creates, reads and write files.
//<thread> to include threads (single thread execution)
//<exception> to include exception handling.

#include <iostream>
#include <string>
#include <fstream>
#include <thread>
#include <exception>

//we are going to include classes or functions from "std" namespace

using namespace std;

//creating classes
class articles {
    
    //giving name to an integer inside the class
    int article1;

    //When used as a function return type, the void keyword specifies that the function doesn't return a value.
    void readArtcl() {

        //printing a message in console, giving instruciton to user.
        cout << "How many pieces of clothing do you need? ";
        //to allow user to input data. This data will assign a value to our int article1.
        cin >> article1;
    }
    //specifying class members to be accessible from any function.
public:
    void showArtcl() {
        //it'll return the value given by user
        readArtcl();
        //will print the message and the value given by user.
        cout << "You are getting a total of " << article1<<" \n\n";
    }
};
//Creating threading
//declaring functions
void sayHi(string intro)
{
    cout << "Welcome to FashionBot!  " << intro;
}

//Inheritance
//Base/parent class
class Clothing
{
    //private attribute (what we don't want user to see)
private:
    int discount;

    //to give a value to it, we use an int, then we use access specifier public to be able to access it
public:
    int a;

    //Method/function defined inside the class
    void priceTag(int x) {
        cout << "Everything's under $" << x << endl;
    }

    //Method/function defined inside the class
    void priceTag(double x) {
        cout << "Clearance starts at $" << x << endl;
    }
    
    //Method/function defined inside the class
    //setter
    void set(int n) {
        discount = n;
    }
    //getter
    int get() {
        return discount;
    }
};

//Derived/Child Class
class tops : virtual public Clothing
{
    //public access specifier. Assigning value to int.
public:
    int b;
};

//Derived/Child Class
class bottoms : virtual public Clothing
{
    //public access specifier. Assigning value to int.
public:
    int c;
};

//Derived/Child Class
class inventory : public tops, public bottoms
{
    //public access specifier. Assigning value to int.
public:
    int d;
};

//main function
//where we call our functions to execute.
int main()
{
    //calling the thread + printing message
    thread t1(sayHi, "Not sure what outfit to wear? no problem, I'll help you find the right option.\n\n");
    //join thread: The function returns when the thread execution has completed.
    t1.join();

    //printing message tonsole.
    cout << "*************" << endl;
    cout << "INSTRUCTIONS:" << endl;
    cout << "*************" << endl;
    cout << "1. FashionBot will help you find your favorite clothing items within your budget" << endl;
    cout << "2. FashionBot will suggest options, choose any." << endl;
    cout << "3. Once you are done with your choices, you can save it or keep adding more." << endl;

    cout << "*************************************************************************************************************" << endl;

    //declaring a string
    string usrName;

    cout << "\n\n\What's your name?" << endl << endl;
    //asking user to enter his/her name
    cin >> usrName;
    //printing a message + user's name.
    cout << "Hi " << usrName << "!" << endl << endl;

    cout << "Here is our inventory: " << endl << endl;

    //calling the values in derived class inventory
    inventory obj;
    //creating objects & assigning values.
    obj.a = 90;
    obj.b = 44;
    obj.c = 87;
    obj.d = 74;

    //printing assigned values from objects.
    cout << "Tops: " << obj.a << endl;
    cout << "Bottoms: " << obj.b << endl;
    cout << "Footwear: " << obj.c << endl;
    cout << "Underwear: " << obj.d << endl << endl;

    //creating objects from base class
    Clothing obj1;
    //giving values to objects. Int & Double.
    obj1.priceTag(100);
    obj1.priceTag(9.99);

    //creating object from base class
    Clothing obj2;
    //calling the value made public from private class.
    obj2.set(10);
    //printing the value
    cout<<"All products (except clearance) have a " << obj2.get()<<"% discount."<<endl<<endl;

    //declaring int 
    int usrChoice;

    //giving user options
    cout << "Press 1 to continue or 2 to quit." << endl << endl;
    cout << "1: CONTINUE" << endl << endl;
    cout << "2: QUIT" << endl << endl;

    //where user inputs chosen option
    cin >> usrChoice;
    //creating a loop where it'll perform a specific action depending on user's choice.
    if (usrChoice == 2) {
        cout << "Sad to see you go, bye!" << endl;
        //this will exit the program.
        exit(0);

    }
    //if user chooses option 1 then...
    else if (usrChoice == 1) {
    }
    //this will do something else when the options were not chosen.
    else {};
    //this will take user back to where the statement START is.
    goto START;

START:

    //declaring a string
    string usrInput;

    //printing a message to console to give instructions to user.
    cout << "What do you feel like wearing today " << usrName <<"?"<< endl << endl;
    //input from user
    cin >> usrInput;
    //printing a message to console with information given by user.
    cout << "Nice choice " << usrName << "!" << endl<< endl;
    //printing previous message and asking for more information to user.
    cout << "What color of " << usrInput << " would you like to wear?"<<endl<<endl;

    cout << "Choose your fave:" << endl;

    //declaring a string
    string usrColor;
    //asking user to input data.
    cin >> usrColor;
    //printing the data.
    cout << "That's a beatiful color " << usrName << "!" << endl << endl;

    cout << "What size of " << usrInput << " are you looking for?" <<endl;
    cout << "S, M, L" << endl << endl;

    //declaring a char
    char usrSize;
    //asking user to input data.
    cin >> usrSize;
    //printing user's data.
    cout << "Awesome " << usrName << "!" << endl << endl;

    cout << "Now, what's your budget "<< "?" << endl << endl;

    //declaring integer.
    int usrBudget;
    //getting data from client.
    cin >> usrBudget;
    cout << "Great " << usrName << "!" << endl << endl;
    cout << "I found the " << usrColor<< " " << usrInput << " in size " << usrSize << " with price tag " << usrBudget << endl<<endl;

    //giving value to class article and printing it.
    articles s;
    s.showArtcl();

    //declaring int
    int usrAge;

    //give user an input option.
    try {
        cout << "You have to be 18+ to be able to shop. " << endl;
        cout << "What's your age? " << endl << endl;
        cin >> usrAge;

        //giving the conditions of if/else statements with throw exception.
        if (usrAge >= 18) {
            cout << "Perfect! You can continue." << endl << endl;
        }
        else {
            throw 0;
        }
    }
    //this catch with the ... will catch any exceptions. Default exceptions.
    catch (...) {
        cout << "You cannot continue shopping. You are not 18+." << endl << endl;
        exit(0);
    }

    cout << "Press 1 to save it and continue shopping" << endl;
    cout << "Or press 2 to exit." << endl << endl;

    cin >> usrChoice;
    //creating a loop where it'll perform a specific action depending on user's selection.
    if (usrChoice == 2) {
        cout << "it was fun! bye!" << endl;
        exit(0);
    }

    else if (usrChoice == 1) {
    }
    //this will do something else when the options were not chosen.
    else {};

    ofstream myCloset("outfitOfTheDay.txt");
    if (myCloset.is_open())
    {
        myCloset << "Outfit Of The Day has been saved! " << usrColor << " " << usrInput << " in size " << usrSize << " with price tag " << usrBudget << endl << endl;
        myCloset.close();
    }
    else cout << "wrong file";

    //this will take user back to where the statement START is located.
    goto START;

    //exit function.
    return 0;
}


