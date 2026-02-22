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

    // Destructor
    ~ClubMember() {
        if (recentGames)
            delete [] recentGames;
        recentGames = nullptr;
    }
};

// FUNCTION PROTOTYPES
void getMemberData (ClubMember *, int);     // Obtain member info
void printMemberData (ClubMember *, int);   // Print member info

int main() {
    // DECLARATIONS
    int clubSize;

    // Banner
    cout << "**** VIDEO GAME CLUB MEMBER LOG ****" << endl << endl;

    // Get number of total members
    cout << "Enter the number of club members: ";
    cin >> clubSize;
    cout << endl;

    // Declaration of memberList array
    ClubMember *memberList = new ClubMember[clubSize];

    // Collect member information
    for (int i = 0; i < clubSize; i++) {
        getMemberData(&memberList[i], i + 1);
    }

    // Print member list and info
    cout << "**** NOW SHOWING MEMBER LIST DATA ****" << endl << endl;
    for (int i = 0; i < clubSize; i++) {
        printMemberData(&memberList[i], i + 1);  
    }

    return 0;
}

//FUNCTION DEFINITIONS
void getMemberData (ClubMember *m, int n) {
    cout << "Please enter the following info for Member #" << n << ":" << endl;

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

    // Declare dynamic array for recent games
    m->recentGames = new string[m->numRecGames];
    cin.ignore();

    // Obtain recent game info
    for (int i = 0; i < m->numRecGames; i++) {
        cout << "\t\tGame #" << i + 1 << ": ";
        getline(cin, m->recentGames[i]);
    }

    cout << endl;
}

void printMemberData (ClubMember *m, int n) {
    cout << "Data for Member #" << n <<": " << endl;
    cout << "\tName: " << m->name << endl;
    cout << "\tPhone Number: " << m->number << endl;
    cout << "\tFavorite Game Overall: " << m->favGame << endl;
    cout << "\tFavorite Game Rating: " << m->favRating << "/10" << endl;
    cout << "\tNumber of Games Played Last Month: " << m->numRecGames << endl;

    for (int i = 0; i < m->numRecGames; i++) {
        cout << "\t\tGame #" << i + 1 << ": ";
        cout << m->recentGames[i] << endl;
    }

    cout << endl;
}