//
// Created by Vishruthi Ramaswamy on 10/25/18.
//
#include <cstdlib>
#include <string>


using namespace std;


class Song{

    private:
        string title;
        string artist;
        int size;

        static const int MAX_SIZE =  512;

    public:
        Song();
        Song(string title, string artist, int size);
        string getTitle() const;
        string getArtist() const;
        int getSize()const;

    bool operator > (Song const &rhs);
};
