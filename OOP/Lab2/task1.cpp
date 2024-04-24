#include <iostream>
#include <cstring>
using namespace std;

// TODO: Implement 'Achievement' and 'UserProfile' classes
class Achievment {
    char name[20];
    char description[200];
    static int totalAchievments;
public:
    Achievment() {}

    Achievment(char *name , char *description , int total){
        strcpy(this->name , name);
        strcpy(this->description , description);
        totalAchievments = total;
    }

    Achievment(Achievment &ach) {
        strcpy(this->name , ach.name);
        strcpy(this->description , ach.description);
        totalAchievments = ach.totalAchievments;
    }

    void print() {
        cout << "Name: " << name << endl;
        cout << "Description: " << description << endl;
    }

    void incrementTotalUserAchievements() {
        totalAchievments++;
    }
};

class UserProfile {
    char name[20];
    Achievment achievment[50];
    int achievmentsObtained = 0;

public:
    UserProfile() {}

    UserProfile(UserProfile &n) {
        strcpy(this->name , n.name);
        achievmentsObtained = n.achievmentsObtained;
    }

    UserProfile(char *name , Achievment ach , int obtained) {
        strcpy(this->name , name);


    }
};
// TODO: Implement showAchievementsProgress function



// Don't modify
int main() {
    char testcase[100];
    cin.getline(testcase, 100);

    int n;
    cin >> n;
    cin.ignore();

    char ignore[100];
    cin.getline(ignore, 100);
    UserProfile users[100];
    for (int i = 0; i < n; ++i) {
        char name[100];
        cin >> name;
        users[i] = UserProfile(name);
    }

    int m;
    cin >> m;
    cin.ignore();

    cin.getline(ignore, 100);
    Achievement achievements[100];
    for (int i = 0; i < m; ++i) {
        char name[100], description[100];
        cin.getline(name, 100);
        cin.getline(description, 100);
        achievements[i] = Achievement(name, description);
    }

    int k;
    cin >> k;
    cin.ignore();

    cin.getline(ignore, 100);
    for (int i = 0; i < k; ++i) {
        int numUser, numAchievement;
        cin >> numUser >> numAchievement;
        numUser -= 1;
        numAchievement -= 1;
        users[numUser].addAchievement(achievements[numAchievement]);
    }

    if (testcase[8] == 'A') {  // Testing Achievement methods.
        for (int i = 0; i < m; ++i) {
            achievements[i].print();
        }
        Achievement::incrementTotalUserAchievements();
    } else if (testcase[8] == 'U') {  // Testing UserProfile methods.
        for (int i = 0; i < n; ++i) {
            users[i].print();
        }
    } else {  // Testing showAchievementsProgress function.
        showAchievementsProgress(users, n, achievements, m);
    }

    return 0;
}