#include<iostream>
#include<string.h>
using namespace std;

class InvalidTimeException {
public:
    InvalidTimeException() {}

    void print() {
        cout << "Invalid Time" << endl;
    }
};

class Race {
protected:
    string city;
    int year;
    int month;
    float bestTime; // in seconds
    float length; // in km
public:
    Race() = default;
    Race(const string &city, int year, int month, float best_time, float length)
        : city(city),
          year(year),
          month(month),
          bestTime(best_time),
          length(length) {
    }

    virtual float complexity() {
        return bestTime / length;
    }

    friend ostream& operator<<(ostream &out, Race & r) {
        out << r.city << " " << r.month << "." << r.year << " " << r.complexity() << endl;
        return out;
    }

};

class MotoGPRace:public Race {
    float *bestTimes; // of prep
    int numOfBT;
    int laps;
    static float coefficient;
public:
    MotoGPRace() = default;

    MotoGPRace(const string &city, int year, int month, float best_time, float length, float *best_times, int num_of_bt,
        int laps)
        : Race(city, year, month, best_time, length),
          laps(laps) {
        this->numOfBT = num_of_bt;
        this->bestTimes = new float[numOfBT];
        for (int i=0;i<numOfBT;i++) {
            bestTimes[i] = best_times[i];
        }
    }

    float complexity() override {
        float allBT = 0.0;
        float avgBT = 0.0;
        for (int i=0;i<numOfBT;i++) {
            allBT += bestTimes[i];
        }

        avgBT = allBT / numOfBT;
        float newComp = avgBT * coefficient;
        if (laps > 22) {
            newComp += newComp * 0.20;
        }

        return newComp;
    };

    static void setK(const float newK) {
        coefficient = newK;
    }

    MotoGPRace &operator+=(float &newBT) {
        float *tmp = new float[numOfBT + 1];
        for (int i=0;i<numOfBT;i++) {
            tmp[i] = bestTimes[i];
        }
        numOfBT += 1;
        if (newBT < 9.5) {
            throw InvalidTimeException();
        }
        tmp[numOfBT] = newBT;
        delete [] bestTimes;
        bestTimes = tmp;
        return *this;
    }

    MotoGPRace &operator++(int i) {
        MotoGPRace ret(*this);
        laps++;
        return ret;
    }

    void setNumberLaps(int newLaps) {
        this->laps = newLaps;
    }

    int getNumberLaps() {
        return this->laps;
    }

    ~MotoGPRace() {
        delete [] bestTimes;
    }
};

float MotoGPRace::coefficient = 0.4;

int main(){
    int testCase;
    cin >> testCase;
    string city;
    int year;
    int month;
    float bestTime;
    float length;
    float bestTimes[50];
    int n;
    int m;
    int choice;
    int numberLaps;

    if (testCase == 1){
        cout << "===== Testing - classes ======" << endl;
        cin >> city;
        cin >> year;
        cin >> month;
        cin >> bestTime;
        cin>>length;
        Race t(city, year, month, bestTime, length);
        cout<<t;
        cin >> city;
        cin >> year;
        cin >> month;
        cin >> bestTime;
        cin>>length;
        cin>>numberLaps;
        cin>>n;
        for (int j = 0; j < n; j++)
            cin >> bestTimes[j];
        MotoGPRace mgt(city, year, month, bestTime, length,bestTimes, n, numberLaps);
        cout << mgt;
        MotoGPRace mgt2;
    }
    if (testCase == 2){
        cout << "===== Testing - operatorot += ======" << endl;
        Race **rArray;
        cin >> m;
        rArray = new Race *[m];
        for (int i = 0; i<m; i++){
            cin >> choice;
            cin >> city;
            cin >> year;
            cin >> month;
            cin >> bestTime;
            cin >>length;
            if (choice == 1){
                rArray[i] = new Race(city, year, month, bestTime, length);
            }
            else{
                cin>>numberLaps;
                cin>>n;
                for (int j = 0; j < n; j++)
                    cin >> bestTimes[j];
                rArray[i] = new MotoGPRace(city, year, month, bestTime, length,bestTimes, n, numberLaps);
            }
        }
        // print the races
        cout << "\nList of all races:\n";
        for (int i = 0; i < m; i++)
            cout << *rArray[i];

        // add a new best time
        float best;
        cin >> best;
        int flag = 1;
        for (int i = 0; i < m; i++){
            MotoGPRace* nn = dynamic_cast<MotoGPRace*>(rArray[i]);
            if (nn != 0){
                flag = 0;
                (*nn) += best;
                break;
            }
        }

        // print the races
        cout << "\nLista na site Trki:\n";
        for (int i = 0; i < m; i++)
            cout << *rArray[i];
    }
    // if (testCase == 3){
    //     cout << "===== Testing - exceptions ======" << endl;
    //     cin >> city;
    //     cin >> year;
    //     cin >> month;
    //     cin >> bestTime;
    //     cin>>length;
    //     cin>>numberLaps;
    //     MotoGPRace mgt(city, year, month, bestTime, length);
    //     mgt.setNumberLaps(numberLaps);
    //     float time1,time2;
    //     cin>>time1>>time2;
    //
    //     mgt+=time1;
    //     mgt+=time2;
    //
    //     cout<<mgt;
    // }
    if (testCase == 4){
        cout <<"===== Testing - operator++ ======"<<endl;
        cin >> city;
        cin >> year;
        cin >> month;
        cin >> bestTime;
        cin>>length;
        cin>>numberLaps;
        cin>>n;
        for (int j = 0; j < n; j++)
            cin >> bestTimes[j];

        MotoGPRace mgt(city, year, month, bestTime, length,bestTimes,n,numberLaps);
        float v,koef2;
        cout<<(mgt++).getNumberLaps()<<endl;
        cout<<mgt;
        mgt++;
        cout<<mgt;
    }
    if (testCase == 5){
        cout << "===== Testing - coefficient ======" << endl;
        Race **rArray;
        cin >> m;
        rArray = new Race *[m];
        for (int i = 0; i<m; i++){
            cin >> choice;
            cin >> city;
            cin >> year;
            cin >> month;
            cin >> bestTime;
            cin >>length;
            if (choice == 1){
                rArray[i] = new Race(city, year, month, bestTime, length);
            }
            else{
                cin>>numberLaps;
                cin>>n;
                for (int j = 0; j < n; j++)
                    cin >> bestTimes[j];
                rArray[i] = new MotoGPRace(city, year, month, bestTime, length,bestTimes, n, numberLaps);
            }
        }
        // print the races
        cout << "\nList of all races:\n";
        for (int i = 0; i < m; i++)
            cout << *rArray[i];

        MotoGPRace::setK(0.7);
        // print the races
        cout << "\nList of all races:\n";
        for (int i = 0; i < m; i++)
            cout << *rArray[i];
    }

    if (testCase == 6){
        cout << "===== Testing - full functionality ======" << endl;
        Race **rArray;
        cin >> m;
        rArray = new Race *[m];
        for (int i = 0; i<m; i++){
            cin >> choice;
            cin >> city;
            cin >> year;
            cin >> month;
            cin >> bestTime;
            cin >>length;
            if (choice == 1){
                rArray[i] = new Race(city, year, month, bestTime, length);
            }
            else{
                cin>>numberLaps;
                cin>>n;
                for (int j = 0; j < n; j++)
                    cin >> bestTimes[j];
                rArray[i] = new MotoGPRace(city, year, month, bestTime, length,bestTimes, n, numberLaps);
            }
        }
        // print the races
        cout << "\nList of all races:\n";
        for (int i = 0; i < m; i++)
            cout << *rArray[i];
        float newCoef;
        cin>>newCoef;
        MotoGPRace::setK(newCoef);
        cout << "\nList of all races:\n";
        for (int i = 0; i < m; i++)
            cout << *rArray[i];
        // print the races
        float newBest;
        cin>>newBest;
        int flag = 1;
        for (int i = 0; i < m; i++){
            MotoGPRace * pok= dynamic_cast<MotoGPRace *>(rArray[i]);
            if(pok!=0)
            {
                (*pok)++;
                (*pok)+=newBest;
                if(flag==1)
                {
                    flag = 0;
                    float varss = 1.4;
                    *pok+=varss;

                }
            }
        }
        cout << "\nList of the races:\n";
        for (int i = 0; i < m; i++)
            cout << *rArray[i];
    }

    return 0;
}
