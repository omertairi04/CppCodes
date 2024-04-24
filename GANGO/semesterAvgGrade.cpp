#include <iostream>

/* Make a calculator that when entering grades per semester, it will print the
ordinal number of the semester with the best average.
// On number N is entered at the beginning, which indicates how many semesters
the student has enrolled.
// For each of the semesters, first enter the M number which indicates how many
entered grades the student has and then the M grades are entered.
//After entering the grades, enter how many subjects were planned for that
semester.
//Ex.
// 3
// 5 9 10 8 9 7 5
// 4 8 8 7 9 5
// 5 10 8 10 9 9 6
//From this example, we can conclude that N 3, that is, the student has enrolled
for 3 semesters, for the previous semester M is 5 -
// the student has 5 grades entered for that semester and the number 5 is
entered as the last number,
// which indicates how many subjects are planned for the semester.
//To print the serial number of the semester where the student achieved the
overall average,
// the average for that semester and the percentage of passed subjects/predicted
subjects.
//The average is calculated:
//Average = (sumGrades / countGrades) * (numberOfSubjects/sumSubjects) +
(1-numberofSubjects/intendedSubjects) * 5 */

int main() {
  int n;
  std::cin >> n;

  for (int i = 0; i < n; i++) {
    int m;
    int semesterGrades[m];
    std::cin >> m;
    for (int i = 0; i < m; i++) {
      std::cin >> semesterGrades[i];
    }

    std::cout << "----------------";
    for (int i = 0; i < m; i++) {
      std::cout << semesterGrades[i] << " ";
    }
  }
}