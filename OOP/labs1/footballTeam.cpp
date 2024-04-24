/*
Write a program in which the number N (the number of football teams) and the
information about the N football teams are entered from standard input.

A structure for FootballTeam should store the following information:

- Team name (character string)

- Array of players (represented via the FootballPlayer structure, where a team
will always have 11 players)

The following information should be stored in the FootballPlayer structure:

- Player name (character string)

- Jersey number (int)

- Number of goals scored (int)

Limit: 0 < N < 100

Your task is to make a function void bestTeam(FootballTeam * teams, int n) that
will print the team with the most given goals (in case there are more teams with
the same number of goals, the first entered should be printed). Entering the
data should be done in the main, while the order of the input data will be as
follows:

N

team_name_1

player_name_1 number_1 goals_1

...

player_name_11 number_11 goals_11

team_name_2

player_name_1 number_1 goals_1

...

player_name_11 number_11 goals_11

...

team_name_n

player_name_1 number_1 goals_1

...

player_name_11 number_11 goals_11

For example:
Input 	Result

2
Arsenal
Baro 14 1
Lubomir 16 4
Lubomir 1 3
Paul 35 8
Jakov 22 8
Jovan 7 3
Kristijan 18 4
Nikola 14 8
Mile 24 9
Vlatko 27 8
Ivan 43 0
PSG
Paul 49 11
Sasho 33 7
Ivo 35 4
Maksim 28 7
Bojan 25 2
Goran 32 8
Andrej 13 3
Mile 30 6
Jakov 31 1
Jovan 35 6
Ivan 37 4
*/

#include <cstring>
#include <iostream>

using namespace std;

struct FootballPlayer {
  char name[50];
  int jNumber, goals;
};
struct FootballTeam {
  char name[50];
  FootballPlayer footballPlayer[12];
  int scoredGoals = 0;
  void read() {
    cin.getline(name, 50);
    for (int i = 0; i < 11; i++) {
      cin >> footballPlayer[i].name >> footballPlayer[i].jNumber >>
          footballPlayer[i].goals;
      scoredGoals += footballPlayer[i].goals;
    }
  }
};

void bestTeam(FootballTeam *teams, int n) {
  int idxMaxGoal = 0, maxGoals = 0;
  for (int i = 0; i < n; i++) {
    if (teams[i].scoredGoals > maxGoals) {
      maxGoals = teams[i].scoredGoals;
      idxMaxGoal = i;
    }
  }
  cout << "The best team is: " << teams[idxMaxGoal].name << endl;
}

int main() {
  int n;
  cin >> n;
  FootballTeam footballTeam[100];
  for (int i = 0; i < n; i++) {
    footballTeam[i].read();
  }
  bestTeam(footballTeam, n);

  return 0;
}