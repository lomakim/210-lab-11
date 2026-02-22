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

void getMemberData (ClubMember *);
void printMemberData (ClubMember *);

int main() {
    // DECLARATIONS
    int clubSize;
    ClubMember newMem;
    ClubMember * memPtr = &newMem;

    // Banner
    cout << "**** VIDEO GAME CLUB MEMBER LOG ****" << endl << endl;

    // Get number of members
    cout << "Enter the number of club members: ";
    cin >> clubSize;
    cout << endl;

    getMemberData(memPtr);
    printMemberData(memPtr);

    return 0;
}

void getMemberData (ClubMember *m) {
    cout << "Please enter the following info for member: " << endl;
    cout << "\tName (F & L): ";
    cin.ignore();
    getline(cin, m->name);
    cout << "\tPhone Number: ";
    getline(cin, m->number);
    cout << "\tFavorite Game Overall: ";
    getline(cin, m->favGame);
    cout << "\tRating for Favorite Game (_/10): ";
    cin >> m->favRating;
    cout << "\tNumber of games played in the past month: ";
    cin >> m->numRecGames;
    m->recentGames = nullptr;
    cin.ignore();
    for (int i = 0; i < m->numRecGames; i++) {
        cout << "\tGame #" << i + 1 << ": ";
        cin >> m->recentGames[i];
        cin.ignore();
    }
}

void printMemberData (ClubMember *m) {
    //cout << "Data for Member #" << <<": " << endl;
    cout << "\tName: " << m->name << endl;
    cout << "\tPhone Number: " << m->number << endl;
    cout << "\tFavorite Game Overall: " << m->favGame << endl;
    cout << "\tFavorite Game Rating: " << m->favRating << "/10" << endl;
    cout << "\tNumber of Games Played Last Month: " << m->numRecGames << endl;
}