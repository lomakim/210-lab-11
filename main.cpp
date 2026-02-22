// COMSC-210 | Lab 11 | Loma Kim
#include <iostream>
#include <string>
#include <array>
using namespace std;

/* Struct Declaration for video game club member data. 
Includes: name, phone number, favorite game overall, rating for their
favorite game, and an array of games they have played in the last month. */
struct ClubMember {
    string name, number, favGame;
    double favRating;
    int numRecentGames;
    string * recentGames;
};

void getMemberData (ClubMember &);

int main() {
    // DECLARATIONS
    int size;
    // Banner
    cout << "**** VIDEO GAME CLUB MEMBER LOG ****" << endl << endl;

    // Get number of members
    cout << "Enter the number of club members: ";
    cin >> size;
    cout << endl;

    // Declare member list array
    ClubMember memberList[size];

    getMemberData (memberList[0]);

    return 0;
}

void getMemberData (ClubMember &mem){
    cout << "Please enter the following for member: " << endl;
    cout << "\tName (F & L): ";
    cin.ignore();
    getline(cin, mem.name);
    cout << "\tPhone Number: ";
    getline(cin, mem.number);
    cout << "\tFavorite Game Overall: ";
    getline(cin, mem.favGame);
    cout << "\tRating for Favorite Game (_/10): ";
    cin >> mem.favRating;
    cout << "\tNumber of games played in the past month: ";
    cin >> mem.numRecentGames;
    cin.ignore();
}