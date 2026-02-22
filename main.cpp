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
    int numRecGames;
    string * recentGames;
};

void getMemberData (ClubMember &);
void printMemberData (ClubMember, int);

int main() {
    // DECLARATIONS
    int clubSize;

    // Banner
    cout << "**** VIDEO GAME CLUB MEMBER LOG ****" << endl << endl;

    // Get number of members
    cout << "Enter the number of club members: ";
    cin >> clubSize;
    cout << endl;

    // Declare member list array
    ClubMember memberList[clubSize];

    getMemberData(memberList[0]);
    printMemberData(memberList[0], 1);

    return 0;
}

void getMemberData (ClubMember &mem) {
    cout << "Please enter the following info for member: " << endl;
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
    cin >> mem.numRecGames;
    cin.ignore();
}

void printMemberData (ClubMember m, int n) {
    cout << "Data for Member #" << n <<": " << endl;
    cout << "\tName: " << m.name << endl;
    cout << "\tPhone Number: " << m.number << endl;
    cout << "\tFavorite Game Overall: " << m.favGame << endl;
    cout << "\tFavorite Game Rating: " << m.favRating << "/10" << endl;
    cout << "\tNumber of Games Played Last Month: " << m.numRecGames << endl;
}