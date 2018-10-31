#ifndef UTPOD_H
#define UTPOD_H
#include "Song.h"
#include <cstdlib>
#include <iostream>

//UtPod class declaration

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

    SongNode *songs = NULL;  //the head pointer

    int memSize;
    int totalmem;

public:
    UtPod()
    {
        memSize = MAX_MEMORY;
        totalmem = MAX_MEMORY;

    };


    UtPod(int size)
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

    int addSong(Song const &s){
        if(s.getSize()<=memSize)
        {
            if(songs == NULL)
            {
                SongNode *newNode = new(SongNode);
                newNode->s = s;
                newNode->next = NULL;
                songs = newNode;
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

    int removeSong(Song const &s){
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
    void shuffle(){

        unsigned int currentTime = (unsigned)time(0);

        int numOfSongs = numSongs(songs);
        SongNode* s1;
        SongNode* s2;

        srand(currentTime);
        int randNum = rand()%20 + 5;


        for(int i = 0; i < randNum; i ++)
        {
            int num1 = rand()%numOfSongs;                   //first song to swap
            int num2 = rand()%numOfSongs;                   //second song to swap

            while(num1 == num2){                            //if same song selected generate new song selection
                num2 = rand()%numOfSongs;
            }

            //-----------------------------------------FINDING ADDRESS OF SELECTED NODES FOR SWAP-----------------------
            SongNode* temp = songs;
            int j = 0;
            while(temp){
                if(j == num1){
                    s1 = temp;
                }
                else if(j == num2){
                    s2 = temp;
                }
                j++;
            }
            //----------------------------------------------------------------------------------------------------------

            temp = s1;                                      //swap nodes
            s1 = s2;
            s2 = temp;
        }

    }

    void showSongList(){
        SongNode* temp = songs;
        while(temp){
            cout << temp->s.getTitle() << ", " << temp->s.getArtist() << ", " << temp->s.getSize() << " MB" << endl;
            temp = temp->next;
        }
    }
    void sortSongList(){}

    int getRemainingMemory(){
        return memSize;
    }
    int getTotalMemory(){
        return totalmem;
    }
    int numSongs(SongNode *s){
        int count = 1;
        while(s->next){
            count++;
        }
    }
//    //Default constructor
//    //set the memory size to MAX_MEMORY
//    UtPod();
//
//
//
//    //Constructor with size parameter
//    //The user of the class will pass in a size.
//    //If the size is greater than MAX_MEMORY or less than or equal to 0,
//    //set the size to MAX_MEMORY.
//    UtPod(int size);
//
//    /* FUNCTION - int addSong
//     * attempts to add a new song to the UtPod
//         o returns a 0 if successful
//         o returns -1 if not enough memory to add the song
//
//     precondition: s is a valid Song
//
//     input parms -
//
//     output parms -
//    */
//
//    int addSong(Song const &s);
//
//
//    /* FUNCTION - int removeSong
//     * attempts to remove a song from the UtPod
//     * removes the first instance of a song that is in the the UtPod multiple times
//         o returns 0 if successful
//         o returns -1 if nothing is removed
//
//
//       input parms -
//
//       output parms -
//    */
//
//    int removeSong(Song const &s);
//
//
//    /* FUNCTION - void shuffle
//     *  shuffles the songs into random order
//        o will do nothing if there are less than two songs in the current list
//
//       input parms -
//
//       output parms -
//    */
//
//    void shuffle();
//
//    /* FUNCTION - void swap
//        *  Swap song nodes
//
//          input parms - nodes to be swapped
//
//          output parms -
//       */
//    void swap(SongNode &s1, SongNode &s2);
//
//    /* FUNCTION - void showSongList
//     * prints the current list of songs in order from first to last to standard output
//     * format - Title, Artist, size in MB (one song per line)
//
//       input parms -
//
//       output parms -
//    */
//
//
//
//
//    void showSongList();
//
//
//    /* FUNCTION - void sortSongList
//     *  sorts the songs in ascending order
//        o will do nothing if there are less than two songs in the current list
//
//       input parms -
//
//       output parms -
//    */
//
//    void sortSongList();
//
//
//    /* FUNCTION - void clearMemory
//     * clears all the songs from memory
//
//       input parms -
//
//       output parms -
//    */
//    void clearMemory();
//
//
//    /* FUNCTION - int getTotalMemory
//     *  returns the total amount of memory in the UtPod
//        o will do nothing if there are less than two songs in the current list
//
//       input parms -
//
//       output parms -
//    */
//
//    int getTotalMemory() {}
//
//
//
//    /* FUNCTION - int getRemainingMemory
//     *  returns the amount of memory available for adding new songs
//
//       input parms -
//
//       output parms -
//    */
//
//    int getRemainingMemory();
//
//
//    ~UtPod();
//
//



};


#endif