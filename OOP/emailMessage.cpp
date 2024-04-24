#include <cstring>
#include <iostream>

using namespace std;

class EmailMessage {
private:
  char sender[50];
  char reciever[50];
  char subject[50];
  char body[500];

public:
  EmailMessage(char *_sender, char *_reciever, char *_subject, char *_body) {
    strcpy(sender, _sender);
    strcpy(reciever, _reciever);
    strcpy(subject, _subject);
    strcpy(body, _body);
  }

  // print info
  void show() {
    cout << "Sender:   \t" << sender << endl;
    cout << "Reciever: \t" << reciever << endl;
    cout << "---------------------------\n";
    cout << "Subject:  \t" << subject << endl;
    cout << "---------------------------\n";
    cout << body << endl;
  }
};

bool valid(char *email) {
  char *ptr =
      strchr(email, '@'); // otairi010@gmail.com -> @gmail.com if !returns null
  if (ptr != nullptr) {
    return strchr(ptr, '.') !=
           nullptr; // gmail.com -> returns true ; gmail -> returns false
  } else {
    return false;
  }
}

int main() {
  // default
  /*EmailMessage m;
  m.show();* */

  char sender[50], reciever[50], subject[50], body[50];
  cin.getline(sender, 50);
  cin.getline(reciever, 50);
  cin.getline(subject, 50);
  cin.getline(body, 500);

  if (valid(sender) && valid(reciever)) {
    EmailMessage message(sender, reciever, subject, body);
    message.show();
  }
}
