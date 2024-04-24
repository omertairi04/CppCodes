//
// Created by intelory on 3/29/24.
//
#include <iostream>
#include <cstring>
using namespace std;

// YOUR CODE HERE
class AlcoholicDrink {
protected:
    char name[100];
    char country[100];
    float alcoholPercent;
    float basePrice;
    static int discount;
public:
    AlcoholicDrink() {}

    AlcoholicDrink(const float percentage , const char *name , const char *country, float price) {
        strcpy(this->name , name);
        strcpy(this->country , country);
        alcoholPercent = percentage;
        basePrice = price;
    }

    float getBasePrice() {
        return basePrice;
    }

    virtual float computePrice() const = 0;

    friend ostream & operator<<(ostream& out, const AlcoholicDrink& a) {
        out << a.name << " " << a.country << " " << a.basePrice << "\n";
        return out;
    }

    bool operator< (const AlcoholicDrink& other) const {
        return basePrice < other.basePrice;
    }

    static float changeDiscount(int d) {
        discount = d;
    }

    static void total(AlcoholicDrink ** ad , int n) {
        double sum(0);
        for (int i=0;i<n;i++) {
            sum += ad[i]->computePrice();
        }
        cout << "Total price: " << sum << endl;
        cout << "Total price with discount: " << sum * (100 - discount) / 100 << endl;
    }

    virtual ~AlcoholicDrink() {} // Declare the destructor as virtual if AlcoholicDrink is a base class

};


class Beer: public AlcoholicDrink{
    bool ingredient;

public:
    Beer() {}

    Beer(float percentage, char *name, char *country,const float price, bool ingredient) {
        strcpy(this->name , name);
        strcpy(this->country , country);
        alcoholPercent = percentage;
        basePrice = price;
        this->ingredient = ingredient;
    }

    float computePrice() const{
        float add(0);
        if (strcmp(country, "Germany") == 0){
            add += basePrice/20;
        }
        if (!ingredient){
            add += basePrice/10;
        }
        return add+basePrice;
    }

    ~Beer() {}
};

class Wine:public AlcoholicDrink {
    char grapeType[20];
    int yearOfManufacturing;

public:
    Wine() {}

    Wine(double percentage, char *name, char *country, double price, int year, char *grape){        strcpy(this->name , name);
        this->alcoholPercent = percentage;
        strcpy(this->name , name);
        strcpy(this->country , country);
        this->basePrice = price;
        yearOfManufacturing = year;
        strcpy(grapeType , grape);
    }

    float computePrice() const {
        float add(0);
        if (country == "Italy") {
            add = (1 + 5 / 100);
        }
        if (yearOfManufacturing < 2005) {
            add = (1 + 15 / 100);
        }
        return add+basePrice;
    }

    ~Wine() {}
};

void lowestPrice(AlcoholicDrink ** a, int n) {
    int dx=0;
    for (int i=0;i<n;i++) {
        if (a[i]->computePrice() < a[dx]->computePrice()) {
            dx = i;
        }
    }
    cout << *a[dx] << "\n";
}

int AlcoholicDrink::discount = 5;

// DO NOT CHANGE THE MAIN FUNCTION
int main() {
    int testCase;
    cin >> testCase;
    float p;
    char name[100];
    char country[100];
    float price;
    bool mainI;
    int year;
    char grape [20];
    if(testCase == 1) {
        cout << "===== TESTING CONSTRUCTORS ======" << endl;
        cin >> p;
        cin >> name;
        cin >> country;
        cin >> price;
        cin >> mainI;
        Beer b(p, name, country, price, mainI);
        cout << b << endl;
        cin >> p;
        cin >> name;
        cin >> country;
        cin >> price;
        cin >> year;
        cin >> grape;
        Wine w(p, name, country, price, year, grape);
        cout << w << endl;

    } else if(testCase == 2) {
        cout << "===== TESTING LOWEST PRICE ======" << endl;
        int n;
        cin >> n;
        AlcoholicDrink** ad = new AlcoholicDrink*[n];
        for(int i = 0; i < n; ++i) {
            cin >> p;
            cin >> name;
            cin >> country;
            cin >> price;

            if(i % 2 == 1){
                cin >> mainI;
                ad[i] = new Beer(p, name, country, price, mainI);
            }
            else {
                cin >> year;
                cin >> grape;
                ad[i] = new Wine(p, name, country, price, year, grape);
            }
        }

        lowestPrice(ad, n);
        for(int i = 0; i < n; ++i) {
            delete ad[i];
        }
        delete [] ad;
    } else if(testCase == 3) {
        cout << "===== TESTING DISCOUNT STATIC ======" << endl;
        int n;
        cin >> n;
        AlcoholicDrink** ad = new AlcoholicDrink*[n];
        for(int i = 0; i < n; ++i) {
            cin >> p;
            cin >> name;
            cin >> country;
            cin >> price;
            if(i % 2 == 1){
                cin >> mainI;
                ad[i] = new Beer(p, name, country, price, mainI);
            }
            else {
                cin >> year;
                cin >> grape;
                ad[i] = new Wine(p, name, country, price, year, grape);
            }
        }
        AlcoholicDrink::total(ad, n);
        int d;
        cin >> d;
        AlcoholicDrink::changeDiscount(d);
        AlcoholicDrink::total(ad, n);
        for(int i = 0; i < n; ++i) {
            delete ad[i];
        }
        delete [] ad;
    }

}

