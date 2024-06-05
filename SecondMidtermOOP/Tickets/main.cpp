#include <iostream>
#include <cstring>
#include <string>
using namespace std;

class Tickets {
protected:
	int id[12];
	string event;
	static double basePrice;
public:
	Tickets(const int *ids, const string &event, double base_price) {
		this->event = event;
		Tickets::basePrice = base_price;
		for (int i = 0; i < 12; i++) { // Change <= to <
			id[i] = ids[i];
		}
	}

	int *getId() {
		return id;
	}

	string getEvent() {
		return event;
	}

	static void changeDiscount(double newDis) {
		Tickets::basePrice = newDis;
	}

	friend ostream &operator<<(ostream &out , Tickets &o) {
		for (int i = 0; i < 12; i++) {
			out << o.id[i];
		}
		out << "-" << o.event << "-" << o.presmetajCena();

		return out;
	}

	bool falsifikat(int from, int to) const {
		for (int i = 8; i < 12; i++) { // Loop through the last 4 digits of the ID
			if (id[i] >= from && id[i] <= to) {
				return false; // If any of the last 4 digits are in the range, the ticket is not fake
			}
		}
		return true; // If none of the last 4 digits are in the range, the ticket is fake
	}

	virtual double presmetajCena() const = 0; // Making it a pure virtual function to ensure Tickets is abstract
};

class Online: public Tickets {
	bool isPremium;
public:
	Online(const int *ids, const string &event, double base_price, bool is_premium)
		: Tickets(ids, event, base_price),
		  isPremium(is_premium) {
	}

	double presmetajCena() const override {
		if (isPremium) return basePrice - (basePrice * (15) / 100);
		return basePrice;
	};
};

class Offline: public Tickets {
	bool hasReservation = false;
public:
	Offline(const int *ids, const string &event, double base_price, bool hasReservation)
		: Tickets(ids, event, base_price){
		this->hasReservation = hasReservation;
	}

	double presmetajCena() const override {
		if (hasReservation) return basePrice - (basePrice * (10) / 100);
		return basePrice;
	};

};

void vkupenPrihod(Tickets ** t, int n, int from, int to) {
	int income = 0;
	for (int i=0;i<n;i++) {
		if (t[i]->falsifikat(from , to)) {
			int res = t[i]->presmetajCena();
			income += res;
		}
	}
	cout << income << endl;
}

double Tickets::basePrice = 0.0;

// DO NOT CHANGE THE MAIN FUNCTION, EXCEPT THE MARKED PART FOR HANDLING WITH THE EXCEPTION
int main() {
	int testCase;
	cin >> testCase;
	int ID[12];
	char nastan[100];
	float price;
	bool premium;
	bool rezervacija;
	int od, doo;

	if (testCase == 1) {
		cout << "===== TESTING CONSTRUCTORS ======" << endl;
		for (int i = 0; i < 12; i++)
			cin >> ID[i];
		cin >> nastan;
		cin >> price;
		cin >> premium;
		Online o1(ID, nastan, price, premium);
		cout << o1 << endl;
		for (int i = 0; i < 12; i++)
			cin >> ID[i];
		cin >> nastan;
		cin >> price;
		cin >> rezervacija;
		Offline o2(ID, nastan, price, rezervacija);
		cout << o2 << endl;

	}
	else if (testCase == 2) {
		cout << "===== TESTING METHOD vkupenPrihod()  ======" << endl;
		int n;
		cin >> n;
		Tickets** t = new Tickets*[n];
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < 12; j++)
				cin >> ID[j];
			cin >> nastan;
			cin >> price;

			if (i % 2 == 0){
				cin >> premium;
				t[i] = new Online(ID, nastan, price, premium);
			}
			else {
				cin >> rezervacija;
				t[i] = new Offline(ID, nastan, price, rezervacija);
			}
		}
		cin >> od;
		cin >> doo;
		vkupenPrihod(t, n, od, doo);
		for (int i = 0; i < n; ++i) {
			delete t[i];
		}
		delete[] t;
	}
	else if (testCase == 3) {
		cout << "===== TESTING DISCOUNT STATIC ======" << endl;
		int n;
		cin >> n;
		//cout<<n<<endl;
		Tickets** t = new Tickets*[n];
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < 12; ++j)
				cin >> ID[j];
			cin >> nastan;
			//cout<<nastan<<endl;
			cin >> price;
			//cout<<price<<endl;
			if (i % 2 == 0){
				cin >> premium;
				t[i] = new Online(ID, nastan, price, premium);
			}
			else {
				cin >> rezervacija;
				//cout<<rezervacija<<endl;
				t[i] = new Offline(ID, nastan, price, rezervacija);
			}
		}
		int d;
		cin >> d;
		Tickets::changeDiscount(d);
		for (int i = 0; i < n; ++i)
			cout << *t[i] << endl;

	}
}
