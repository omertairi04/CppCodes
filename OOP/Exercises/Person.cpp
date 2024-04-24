#include <cstring>
#include <iostream>
using namespace std;

class Person {
  char *name;
  int birth;

  void copy(const Person &p) {
    name = new char[strlen(p.name) + 1];
    strcpy(this->name, name);
    birth = p.birth;
  }

public:
  Person() {}

  Person(Person &p) { copy(p); }

  Person(char *name, int birth) {
    strcpy(this->name, name);
    this->birth = birth;
  }

  ~Person() { delete[] name; }
};

class Song {
protected:
  char *songName;
  Person *performers;
  int numOfPerformers;
  int *ratings;
  int ratingCount; // 1 - 10

  void copy(Song &s) {
    songName = new char[strlen(s.songName) + 1];
    strcpy(this->songName, songName);
    numOfPerformers = s.numOfPerformers;
    performers = new Person[numOfPerformers];
    ratingCount = s.ratingCount;
    ratings = new int[ratingCount];
  }

public:
  Song() {}

  Song(Song &s) { copy(s); }

  Song(char *name, Person *performers, int perNum, int *rating, int numRating) {
    strcpy(this->songName, name);
    performers = performers;
    this->numOfPerformers = perNum;
    this->ratings = rating;
    ratingCount = numRating;
  }

  float getTotalRating() {}

  ~Song() {
    delete[] songName;
    delete[] performers;
    delete[] ratings;
  }
};

class Movie {
protected:
  char *movieName;
  int popularity; // 1 - 10

public:
  Movie() {}

  Movie(char *mn, int pop) {
    strcpy(this->movieName, mn);
    popularity = pop;
  }

  ~Movie() { delete[] movieName; }
};

class MovieSong : Song, Movie {
  int songPopularity;

public:
  MovieSong(char *title, Person *performers, int num, int *ratings, int numR,
            char *movieTitle, int mpop, int songpop) {
    strcpy(this->songName, title);
    this->performers = performers;
    this->numOfPerformers = num;
    this->ratings = ratings;
    ratingCount = numR;
    strcpy(this->movieName, movieTitle);
    popularity = mpop;
    songPopularity = songpop;
  }

  ~MovieSong() {
    delete[] songName;
    delete[] performers;
    delete[] ratings;
    delete[] movieName;
  }
};

int main() {

  Person performers[10];
  int year, numberOfPerformers, ratings[20], rating, numberOfRatings, type,
      popularity, songPopularity;
  char name[40], title[30], perfomer[30];

  cin >> type;

  if (type == 1) // test class MovieSong
  {
    cout << "-----TEST MovieSong-----" << endl;
    cin >> title >> numberOfPerformers;
    for (int i = 0; i < numberOfPerformers; i++) {
      cin >> name >> year;
      performers[i] = Person(name, year);
    }
    cin >> numberOfRatings;
    for (int i = 0; i < numberOfRatings; i++) {
      cin >> rating;
      ratings[i] = rating;
    }
    cin >> title >> popularity >> songPopularity;

    MovieSong ok(title, performers, numberOfPerformers, ratings,
                 numberOfRatings, title, popularity, songPopularity);
    cout << "Object of class MovieSong is created";

  } else if (type == 2) // function print in song
  {
    cout << "-----TEST print-----" << endl;
    cin >> title >> numberOfPerformers;
    for (int i = 0; i < numberOfPerformers; i++) {
      cin >> name >> year;
      performers[i] = Person(name, year);
    }
    cin >> numberOfRatings;
    for (int i = 0; i < numberOfRatings; i++) {
      cin >> rating;
      ratings[i] = rating;
    }

    Song k(title, performers, numberOfPerformers, ratings, numberOfRatings);
    k.print();

  } else if (type == 3) // function getTotalRating
  {
    cout << "-----TEST getTotalRating-----" << endl;
    cin >> title >> numberOfPerformers;
    for (int i = 0; i < numberOfPerformers; i++) {
      cin >> name >> year;
      performers[i] = Person(name, year);
    }
    cin >> numberOfRatings;
    for (int i = 0; i < numberOfRatings; i++) {
      cin >> rating;
      ratings[i] = rating;
    }

    Song k(title, performers, numberOfPerformers, ratings, numberOfRatings);
    cout << "Total rating: " << k.getTotalRating() << endl;

  } else if (type == 4) // funkcija getTotalRating vo MovieSong
  {
    cout << "-----TEST getTotalRating-----" << endl;
    cin >> title >> numberOfPerformers;
    for (int i = 0; i < numberOfPerformers; i++) {
      cin >> name >> year;
      performers[i] = Person(name, year);
    }
    cin >> numberOfRatings;
    for (int i = 0; i < numberOfRatings; i++) {
      cin >> rating;
      ratings[i] = rating;
    }
    cin >> title >> popularity >> songPopularity;

    MovieSong fp(title, performers, numberOfPerformers, ratings,
                 numberOfRatings, title, popularity, songPopularity);
    cout << "Total rating: " << fp.getTotalRating() << endl;

  } else if (type == 5) // funkcija print vo MovieSong
  {
    cout << "-----TEST print -----" << endl;
    cin >> title >> numberOfPerformers;
    for (int i = 0; i < numberOfPerformers; i++) {
      cin >> name >> year;
      performers[i] = Person(name, year);
    }
    cin >> numberOfRatings;
    for (int i = 0; i < numberOfRatings; i++) {
      cin >> rating;
      ratings[i] = rating;
    }
    cin >> title >> popularity >> songPopularity;

    MovieSong fp(title, performers, numberOfPerformers, ratings,
                 numberOfRatings, title, popularity, songPopularity);
    fp.print();

  } else if (type == 6) // all classes
  {
    cout << "-----TEST Song and MovieSong-----" << endl;
    cin >> title >> numberOfPerformers;
    for (int i = 0; i < numberOfPerformers; i++) {
      cin >> name >> year;
      performers[i] = Person(name, year);
    }
    cin >> numberOfRatings;
    for (int i = 0; i < numberOfRatings; i++) {
      cin >> rating;
      ratings[i] = rating;
    }
    cin >> title >> popularity >> songPopularity;

    Song *p = new MovieSong(title, performers, numberOfPerformers, ratings,
                            numberOfRatings, title, popularity, songPopularity);
    p->print();
    cout << "Total rating: " << p->getTotalRating() << endl;
    delete p;

  } else if (type == 7) // function average rating
  {
    cout << "-----TEST average rating-----" << endl;
    int k, opt;
    cin >> k;
    Song **pesni = new Song *[k];
    for (int j = 0; j < k; j++) {
      cin >> opt; // 1 Song 2 MovieSong
      cin >> title >> numberOfPerformers;
      for (int i = 0; i < numberOfPerformers; i++) {
        cin >> name >> year;
        performers[i] = Person(name, year);
      }
      cin >> numberOfRatings;
      for (int i = 0; i < numberOfRatings; i++) {
        cin >> rating;
        ratings[i] = rating;
      }
      if (opt == 1) {
        pesni[j] = new Song(title, performers, numberOfPerformers, ratings,
                            numberOfRatings);
      } else {
        cin >> title >> popularity >> songPopularity;
        pesni[j] =
            new MovieSong(title, performers, numberOfPerformers, ratings,
                          numberOfRatings, title, popularity, songPopularity);
      }
    }

    cout << "Average rating of the songs is " << averageRating(pesni, k);
    for (int j = 0; j < k; j++)
      delete pesni[j];
    delete[] pesni;

  } else if (type == 8) // function print songs
  {
    cout << "-----TEST print songs-----" << endl;
    int k, opt;
    cin >> k;
    Song **pesni = new Song *[k];
    for (int j = 0; j < k; j++) {
      cin >> opt; // 1 Song 2 MovieSong
      cin >> title >> numberOfPerformers;
      for (int i = 0; i < numberOfPerformers; i++) {
        cin >> name >> year;
        performers[i] = Person(name, year);
      }
      cin >> numberOfRatings;
      for (int i = 0; i < numberOfRatings; i++) {
        cin >> rating;
        ratings[i] = rating;
      }
      if (opt == 1) {
        pesni[j] = new Song(title, performers, numberOfPerformers, ratings,
                            numberOfRatings);
      } else {
        cin >> title >> popularity >> songPopularity;
        pesni[j] =
            new MovieSong(title, performers, numberOfPerformers, ratings,
                          numberOfRatings, title, popularity, songPopularity);
      }
    }
    cin >> perfomer;
    cout << "Songs of " << perfomer << " are:" << endl;
    printSongs(perfomer, pesni, k);
    for (int j = 0; j < k; j++)
      delete pesni[j];
    delete[] pesni;
  }

  return 0;
}
