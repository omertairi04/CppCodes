#include<iostream>
#include<string.h>
using namespace std;

class Cinema {
    char name[20];
    int hall;
    float discount;
    float price;

public:
    Cinema() {}

    Cinema(char *n , float ds, float pr) {
      strcpy(name ,n);
      hall = 0;
      discount = ds;
      price = pr;
    }

    Cinema(const Cinema&c) {
      strcpy(name ,c.name);
      hall = c.hall;
      discount = c.discount;
      price = c.price;
    }

    void changeStudentDiscount(float discount) {

    }

};

int main(){

  int tip,n;
  char name[100], movieName[40];
  int no;
  bool premiere;
  float ticketPrice;
  float hours;
  bool isStudent;

  cin>>tip;
  if (tip==1){//Cinema
    cin>>name>>no>>ticketPrice;
    Cinema k1(name,no,ticketPrice);
    cout<<"Cinema created with name: "<<k1.getname()<<endl;
  }
  else if (tip==2){//price - Cinema
    cin>>name>>no>>ticketPrice>>isStudent;
    Cinema k1(name,no,ticketPrice);
    cout<<"Initial price for the cinema with name "<<k1.getname()<< " is: " <<k1.price(isStudent)<<endl;
  }
  else if (tip==3){//3D Cinema
    cin>>name>>no>>ticketPrice>>movieName>>hours>>premiere;
    ThreeDCinema s(name,no,ticketPrice,movieName,hours,premiere);
    cout<<"Cinema created with name "<<s.getname()<<" and discount "<<s.getStudentDiscount()<<endl;
  }
  else if (tip==4){//price - 3DCinema
    cin>>name>>no>>ticketPrice>>movieName>>hours>>premiere>>isStudent;
    ThreeDCinema s(name,no,ticketPrice,movieName,hours,premiere);
    cout<<"The price for the cinema "<<s.getname()<<" is: "<<s.price(isStudent)<<endl;
  }
  else if (tip==5) {//cheapest Cinema
    Cinema ** halls = new Cinema *[5];
    int n;
    halls[0] = new Cinema("Cineplexx1",1,350);
    halls[1] = new ThreeDCinema("Milenium3D",44,285,"Shrek",2.5,false);
    halls[2] = new ThreeDCinema("Vardar",12,333,"StarWars",4,true);
    halls[2] = new ThreeDCinema("Home",44,299,"Godfather",5,false);
    halls[3] = new Cinema("Cineplexx2",2,333);
    halls[4] = new ThreeDCinema("Cinedays",1,310,"ManInBlack",5,true);
    cheapestCinema(halls,5,true);
  }
  else if (tip==6){//search
    Cinema ** halls = new Cinema *[5];
    halls[0] = new Cinema("Cineplexx1",1,350);
    halls[1] = new ThreeDCinema("Milenium3D",44,285,"Shrek",2.5,false);
    halls[2] = new ThreeDCinema("Vardar",12,333,"StarWars",4,true);
    halls[3] = new Cinema("Cineplexx2",2,333);
    halls[4] = new ThreeDCinema("Cinedays",1,310,"ManInBlack",5,true);

    if(searchCinema(halls,5, "Milenium3D",true,true))
      cout<<"Found"<<endl;
    else cout<<"Not found"<<endl;

    if(searchCinema(halls,5, "CinePlexx1",false,false))
      cout<<"Found"<<endl;
    else cout<<"Not found"<<endl;

  }
  else if (tip==7){//change price
    Cinema ** halls = new Cinema *[5];
    halls[0] = new Cinema("Cineplexx1",1,350);
    halls[1] = new ThreeDCinema("Milenium3D",44,285,"Shrek",2.5,false);
    halls[2] = new ThreeDCinema("Vardar",12,333,"StarWars",4,true);
    halls[2] = new ThreeDCinema("Domasno",44,299,"Godfather",5,false);
    halls[3] = new Cinema("Cineplexx2",2,333);
    halls[4] = new ThreeDCinema("Cinedays",1,310,"ManInBlack",5,true);
    halls[2] -> setStudentDiscount(0.9);
    cheapestCinema(halls,4,true);
  }

  return 0;
}
