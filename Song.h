//
// Created by Vishruthi Ramaswamy and Megan Nguyen
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
        Song(string artist, string title, int size);
        string getTitle() const;
        string getArtist() const;
        int getSize()const;

    bool operator > (Song const &rhs);
    bool operator < (Song const &rhs);

};
