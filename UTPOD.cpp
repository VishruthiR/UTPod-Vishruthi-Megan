//
// Created by Vishruthi Ramaswamy on 10/31/18.
//
#include <iostream>
#include <string>
#include <cstdlib>
#include "UTPOD.h"

UtPod::UtPod()
{
    memSize = MAX_MEMORY;
    totalmem = MAX_MEMORY;

};


UtPod::UtPod(int size)
{
    if(size <= 0 || size > MAX_MEMORY)
    {
        memSize = MAX_MEMORY;
        totalmem = MAX_MEMORY;
    }
    else
    {
        memSize = size;
        totalmem = size;
    }

};

int UtPod::addSong(Song const &s) {
    if(s.getSize()<=memSize)
    {
        if(songs == NULL)
        {
            SongNode *newNode = new(SongNode);
            newNode->s = s;
            newNode->next = NULL;
            songs = newNode;
            return SUCCESS;
        }
        else
        {
            SongNode *newNode = new(SongNode);
            newNode->s = s;
            newNode->next = songs;
            songs = newNode;
            memSize -= s.getSize();
            return SUCCESS;
        }
    }
    else
    {
        return NO_MEMORY;
    }
}

int UtPod::removeSong(Song const &s) {
    SongNode* temp = songs;
    SongNode* trail = songs;
    while(temp){
        if((temp->s).getTitle() == s.getTitle() && (temp->s).getArtist() == s.getArtist() && (temp->s).getSize() == s.getSize()){
            if(temp == songs)
            {
                songs = temp->next;
            }
            trail->next = temp->next;
            return SUCCESS;
        }
        trail = temp;
        temp = temp->next;
    }

    return NOT_FOUND;

}
void UtPod::shuffle(){

    unsigned int currentTime = (unsigned)time(0);

    int numOfSongs = numSongs(songs);

    if(numOfSongs <= 1){
        return;
    }
    else {
        SongNode *s1 = NULL;
        SongNode *s2 = NULL;

        srand(currentTime);
        int randNum = rand() % 20 + 5;

        currentTime = (unsigned)time(0);

        for (int i = 0; i < randNum; i++) {
            srand(currentTime);
            int num1 = rand() % numOfSongs;                   //first song to swap
            srand(currentTime+11);
            int num2 = rand() % numOfSongs;                   //second song to swap

            while (num1 == num2) {                            //if same song selected generate new song selection
                num2 = rand() % numOfSongs;
            }

            //-----------------------------------------FINDING ADDRESS OF SELECTED NODES FOR SWAP-----------------------
            SongNode *temp = songs;
            int j = 0;
            while (temp) {
                if (j == num1) {
                    s1 = temp;
                }
                else if (j == num2) {
                    s2 = temp;
                }
                j++;
                temp = temp->next;
            }
            //----------------------------------------------------------------------------------------------------------

            Song holdval = s1->s;                                      //swap nodes
            s1->s = s2->s;
            s2->s = holdval;
        }
    }

}

void UtPod::showSongList(){
    SongNode* temp = songs;
    while(temp){
        cout << temp->s.getTitle() << ", " << temp->s.getArtist() << ", " << temp->s.getSize() << " MB" << endl;
        temp = temp->next;
    }
}
void UtPod::sortSongList(){


    SongNode *pt1 = songs;
    SongNode *pt2 = songs->next;

    while(pt1->next){
        if(pt1->s > pt2->s){
            Song temp = pt1->s;                                      //swap nodes
            pt1->s = pt2->s;
            pt2->s = temp;
            pt1 = songs;
            pt2 = songs->next;
        }
        else{
            pt1 = pt1->next;
            pt2 = pt1->next;
        }

    }

}


int UtPod::numSongs(UtPod::SongNode *s) {
    int count = 1;
    while(s->next){
        count++;
        s = s->next;
    }
    return count;
}

UtPod::~UtPod() {
    SongNode *temp = songs;
    while(temp) {
        SongNode *list = temp->next;
        delete temp;
        temp = list;
    }
    songs = NULL;
}
