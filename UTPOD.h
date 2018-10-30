#include "Song.h"
//UtPod class declaration
#ifndef  _UTPOD_H
#define  _UTPOD_H

using namespace std;

class UtPod
{
private:
    static const int MAX_MEMORY = 512;
    static const int SUCCESS = 0;
    static const int NO_MEMORY = -1;
    static const int NOT_FOUND = -2;

    struct SongNode
    {
        Song s;
        SongNode *next;
    };

    SongNode *songs;  //the head pointer

    int memSize;

public:
    UtPod(){}
    UtPod(int size){}

    int addSong(Song const &s){
        return 0;
    }
    int removeSong(Song const &s){
        return 0;
    }
    void shuffle(){}
    void showSongList(){}
    void sortSongList(){}

    int getTotalMemory() {
        return memSize;
    };

    int getRemainingMemory(){
        return 0;
    }

    ~UtPod(){}

};


#endif