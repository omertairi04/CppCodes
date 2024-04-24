#include <iostream>
#include <string.h>
using namespace std;

class Parcel {
protected:
  int idNum;
  static int processingPrice;

  void copy(Parcel &p) {
    idNum = p.idNum;
    processingPrice = p.processingPrice;
  }

public:
  Parcel() {}

  Parcel(int id) {
    idNum = id;
    processingPrice = 150;
  }

  Parcel(Parcel &p) { copy(p); }

  static void setProcessingPrice(int price) { processingPrice = price; }

  ~Parcel() {}
};

class Envelope : Parcel {
  int height, width;

  void copy(Envelope &e) {
    this->idNum = e.idNum;
    this->processingPrice = e.processingPrice;
    height = e.height;
    width = e.width;
  }

public:
  Envelope() {}

  Envelope(Envelope &e) { copy(e); }

  Envelope(int id, int h, int w) {
    idNum = id;
    processingPrice = 150;
    height = h;
    width = w;
  }

  int price() { return processingPrice * height * width * 0.3; }

  ~Envelope() {}
};

class PostOffice {
  Envelope *envelopes;
  int capacity;
  int sentEnvelopes;

  void copy(PostOffice &p) {
    capacity = p.capacity;
    envelopes = new Envelope[capacity];
    sentEnvelopes = p.sentEnvelopes;
  }

  void resizeArray() {
    capacity *= 2;
    Envelope *newEnvelope = new Envelope[capacity];

    for (int i = 0; i < sentEnvelopes; i++) {
      newEnvelope[i] = envelopes[i];
    }

    delete[] envelopes;
    envelopes = newEnvelope;
  }

public:
  PostOffice() {}

  PostOffice(PostOffice &p) { copy(p); }

  PostOffice(Envelope *en) {
    capacity = 20;
    envelopes = new Envelope[capacity];
    sentEnvelopes++;
  }

  int sendEnvelope(int id, char *receiver, int length, int width) {
    if (sentEnvelopes >= capacity) {
      resizeArray();
    }
    Envelope *newE = new Envelope(id, length, width);
    envelopes[sentEnvelopes++] = newE;
  }
};

int main() {

  int type;
  int n;
  int price;
  int id;
  int height, width;
  char receiver[50];

  PostOffice p;

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> type;
    if (type == 1) { // send envelope
      cin >> id >> receiver >> width >> height;
      cout << "The price of sending envelope with id " << id
           << " is:" << p.sendEnvelope(id, receiver, width, height) << endl;
    } else if (type == 2) { // print envelops to
      cin >> receiver;
      p.printEnvelopsTo(receiver);
    } else if (type == 3) { // set processing price
      cin >> price;
      Parcel::setProcessingPrice(price);
    } else if (type == 4) { // Parcel
      cin >> id;
      Parcel p1(id);
      cout << "Parcel with id [" << p1.getId() << "] is created" << endl;
    } else { // Envelope
      cin >> id >> receiver >> width >> height;
      Envelope p2(id, receiver, width, height);
      cout << "Price of sending envelope with ID: " << p2.getId()
           << " To: " << p2.getReceiver() << " is: " << p2.price() << endl;
    }
  }
  return 0;
}
