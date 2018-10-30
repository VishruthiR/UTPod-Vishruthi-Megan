//
// Created by Vishruthi Ramaswamy on 10/25/18.
//

using namespace std;

#include "UTPOD.h"
#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>

UtPod::UtPod()
{
    memSize = MAX_MEMORY;

};


UtPod::UtPod(int size)
{
    if(size <= 0 || size > MAX_MEMORY)
        memSize = MAX_MEMORY;
    else
        memSize = size;

};

int addSong(Song const &s){
    if(s.getSize()<=memSize)
    {
        if(songs == NULL)
            songs = s;

        SongNode newNode;
        newNode.s = s;
        newNode.next = songs;
        songs = newNode;
        memSize -= s.getSize();

        numSongs++;
        return SUCCESS;
    }
    else
        return NO_MEMORY;
}

int removeSong(Song const &s){
    SongNode* temp = songs;
    SongNode* trail = NULL;
    while(temp){
        if((temp.s).getTitle() == s.getTitle() && (temp.s).getArtist() == s.getArtist() && (temp.s).getSize() == s.getSize()){
            if(temp == songs)
            {
                songs = temp.next;
            }
            trail.next = temp.next;
            return SUCCESS;
        }
        trail = temp;
        temp = temp.next;
    }

    return NOT_FOUND;

}
void shuffle(){

    unsigned int currentTime = (unsigned)time(0);

    srand(currentTime);
    int randNum = rand()%15 + 1
    for(int i = 0; i < randNum; i ++)
    {
        //SongNode *s1 =
    }

}

void showSongList(){}
void sortSongList(){}

int getRemainingMemory(){
    return memSize;
}