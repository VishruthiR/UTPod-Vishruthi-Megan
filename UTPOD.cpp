//
// Created by Vishruthi Ramaswamy and Megan Nguyen
//
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
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

int UtPod::addSong(Song const &s)
{
    if(s.getSize()<=memSize)
    {
        if(songs == NULL)   //set new node's next to null when list is empty
        {
            SongNode *newNode = new(SongNode);
            newNode->s = s;
            newNode->next = NULL;
            songs = newNode;
            return SUCCESS;
        }
        else    // add new song node to top of linked list, subtract song's size from remaining memory
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

int UtPod::removeSong(Song const &s)
{
    SongNode* temp = songs;
    SongNode* trail = songs;
    SongNode* deleteNode;
    while(temp)
    {
        //traverse linked list to find song node to delete
        if((temp->s).getTitle() == s.getTitle() && (temp->s).getArtist() == s.getArtist() && (temp->s).getSize() == s.getSize()){
            if(temp == songs)   //if the node to delete is the first one, set head ptr to second node
            {
                songs = temp->next;
            }
            trail->next = temp->next;      //remove node from linked list
            delete temp;
            return SUCCESS;
        }
        trail = temp;
        temp = temp->next;
    }
    return NOT_FOUND;
}

void UtPod::shuffle()
{
    unsigned int currentTime = (unsigned)time(0);

    int numOfSongs = numSongs(songs);

    //do not shuffle if 1 or less songs in list
    if(numOfSongs <= 1)
    {
        return;
    }

    else
    {
        //pointers to nodes that will be swapped
        SongNode *s1 = NULL;
        SongNode *s2 = NULL;

        srand(currentTime);

        int randNum = rand() % 20 + 5;

        currentTime = (unsigned)time(0);

        for (int i = 0; i < randNum; i++)
        {
            srand(currentTime);
            int num1 = rand() % numOfSongs;                   //index of first song to swap
            srand(currentTime+11);
            int num2 = rand() % numOfSongs;                   //index of second song to swap

            while (num1 == num2) {                            //if same song selected generate new song selection
                num2 = rand() % numOfSongs;
            }

            //-----------------------------------------FINDING ADDRESS OF SELECTED NODES FOR SWAP-----------------------
            SongNode *temp = songs;
            int j = 0;
            while (temp)
            {
                if (j == num1)
                {
                    s1 = temp;
                }
                else if (j == num2)
                {
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
    while(temp)
    {
        cout << temp->s.getTitle() << ", " << temp->s.getArtist() << ", " << temp->s.getSize() << " MB" << endl;
        temp = temp->next;
    }
}

void UtPod::sortSongList()
{
    SongNode *pt1 = songs;
    SongNode *pt2 = songs->next;

    while(pt1->next)
    {
        if(pt1->s > pt2->s)
        {
            Song temp = pt1->s;                            //swap nodes if first song is greater then second
            pt1->s = pt2->s;
            pt2->s = temp;
            pt1 = songs;                                   //start back at top to sort
            pt2 = songs->next;
        }
        else
        {
            pt1 = pt1->next;        //set pointers to next two nodes
            pt2 = pt1->next;
        }
    }
}

void UtPod::clearMemory()
{
    SongNode *temp = songs;
    while(temp)
    {
        SongNode *list = temp->next;    //save next node
        delete temp;                    //delete current node
        temp = list;                    //set current node to next node
    }
    songs = NULL;
}


int UtPod::numSongs(UtPod::SongNode *s)
{
    int count = 1;
    while(s->next)
    {
        count++;
        s = s->next;
    }
    return count;
}

UtPod::~UtPod()
{
   clearMemory();
}
