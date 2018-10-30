//
// Created by Vishruthi Ramaswamy on 10/25/18.
//

#include "Song.h"
#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>

Song::Song(string title, string _artist, int _size){
    this->title = title;
    artist = _artist;
    size = _size;
}

string Song::getTitle() const{
    return title;
}

string Song::getArtist() const{
    return artist;
}

int Song::getSize() const{

    return size;

}