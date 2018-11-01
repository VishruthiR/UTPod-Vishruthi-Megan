//
// Created by Vishruthi Ramaswamy and Megan Nguyen
//

#include <cstdlib>
#include <iostream>
#include "UTPOD.h"

using namespace std;

/*void SuccessofAdd(int result, UtPod t);
void SuccessofDelete(int result, UtPod t);*/

int main(int argc, char *argv[]) {
    UtPod t;
    int result = 0;

    cout << "Total Memory: " << t.getTotalMemory() << endl << "Remaining Memory: " << t.getRemainingMemory() << endl;

    Song s1("Artist 2", "Song 1", 300);
    result = t.addSong(s1);
    if (result == 0)
        cout << "Successfully added Song 1" << endl;
    else
        cout << "Failed to add Song 1" << endl;

    Song s2("Artist1", "Song 2", 35);
    result = t.addSong(s2);
    if (result == 0)
        cout << "Successfully added Song 2" << endl;
    else
        cout << "Failed to add Song 2" << endl;


    Song s3("Artist1", "Song 2", 35);
    result = t.addSong(s3);
    if (result == 0)
        cout << "Successfully added Song 2" << endl;
    else
        cout << "Failed to add Song 2" << endl;

    Song s4("Artist4", "Song 4", 500);
    result = t.addSong(s4);
    if (result == 0)
        cout << "Successfully added Song 4" << endl;
    else
        cout << "Failed to add Song 4" << endl;

    cout << "Total Memory: " << t.getTotalMemory() << endl << "Remaining Memory: " << t.getRemainingMemory() << endl;

    t.showSongList();

//
//    Song s5("Artist6", "Song 3", 241);
//    result = t.addSong(s5);
//
//    Song s6("Artist8", "Song 12", 241);
//    result = t.addSong(s6);
//
//    Song s7("Artist8", "Song 12", 7);
//    result = t.addSong(s7);
//
//    Song s8("Artist12", "Song 2", 38);
//    result = t.addSong(s8);

    cout << endl << "SHUFFLE" << endl;
    t.shuffle();
    t.showSongList();

    cout << endl << "SORT" << endl;
    t.sortSongList();
    t.showSongList();

    cout << endl << "SHUFFLE" << endl;
    t.shuffle();
    t.showSongList();

    cout << endl << "SORT" << endl;
    t.sortSongList();
    t.showSongList();

    result = t.removeSong(s2);
    if (result == 0)
        cout << "Successfully deleted Song 2" << endl;
    else
        cout << "Failed to add Song 2" << endl;
    cout << "Total Memory: " << t.getTotalMemory() << endl << "Remaining Memory: " << t.getRemainingMemory() << endl;


    cout << endl << "SHUFFLE" << endl;
    t.shuffle();
    t.showSongList();

    t.clearMemory();

    cout << "SHOW SHUFFLED EMPTY LIST" << endl;
    t.shuffle();
    t.showSongList();

    cout << "SHOW SORTED EMPTY LIST" << endl;
    t.sortSongList();
    t.showSongList();

    t.addSong(s2);
    if (result == 0)
        cout << "Successfully added Song 4" << endl;
    else
        cout << "Failed to add Song 4" << endl;
    t.showSongList();
    cout << "Total Memory: " << t.getTotalMemory() << endl << "Remaining Memory: " << t.getRemainingMemory() << endl;

}