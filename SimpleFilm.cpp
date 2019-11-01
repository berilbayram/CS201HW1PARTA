//
// Created by berilbayram on 1.11.2019.
//

#include "SimpleFilm.h"
using namespace std;

Film::Film(const string fTitle , const string fDirector,
          const unsigned int fYear,
          const unsigned int fDuration ){
    title = fTitle;
    director = fDirector;
    duration = fDuration;
    year = fYear;
};

Film::~Film() {
}

Film::Film(const Film &fToCopy){
    title = fToCopy.title;
    director = fToCopy.director;
    year = fToCopy.year;
    duration = fToCopy.duration;
}

void Film::operator=(const Film &right) {
    title = right.title;
    duration = right.duration;
    director = right.director;
    year = right.year;
}

ostream& operator<<(ostream& out, const Film& f){
    out << f.title << ", " << f.year << ", " << f.director << ", " << f.duration << " min" << endl;
    return out;
}

string Film::getDirector() const {
    return director;
}

string Film::getTitle() const {
    return title;
}

unsigned int Film::getDuration() const {
    return duration;
}

unsigned int Film::getYear() const {
    return year;
}
