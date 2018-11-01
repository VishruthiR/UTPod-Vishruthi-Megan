//
// Created by Vishruthi Ramaswamy and Megan Nguyen
//

#include "Song.h"
#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>

Song::Song()
{
    title = "";
    artist = "";
    size = 512;
}

Song::Song(string _artist, string _title, int _size)
{
    artist = _artist;
    title = _title;
    size = _size;
}

string Song::getTitle() const
{
    return title;
}

string Song::getArtist() const
{
    return artist;
}

int Song::getSize() const
{
    return size;
}

bool Song:: operator > (Song const &rhs)
{
    if(this->artist > rhs.artist){
        return true;
    }
    else if(this->artist == rhs.artist){
        if(this->title > rhs.title){
            return true;
        }
        else if(this->title == rhs.title){
            if(this->size > rhs.size){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}

bool Song:: operator < (Song const &rhs)
{
    if(this->artist < rhs.artist){
        return true;
    }
    else if(this->artist == rhs.artist){
        if(this->title < rhs.title){
            return true;
        }
        else if(this->title == rhs.title){
            if(this->size < rhs.size){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}

