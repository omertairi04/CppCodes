#include <cstring>
#include <iostream>
using namespace std;

class Text {
  char sender[20];
  char reciever[20];
  char content[100];
  int bill;

public:
  Text(char *_sender, char *_reciever, char *_content) {
    strcpy(sender, _sender);
    strcpy(reciever, _reciever);
    strcpy(content, _content);
  }

  void setSender(char *from) { strcpy(sender, from); }
  char *getSender() { return sender; };

  void setReciever(char *to) { strcpy(reciever, to); }
  char *getReciever() { return reciever; };

  void setContent(char *body) { strcpy(content, body); }
  char *getContent() { return content; }

  void viewMessage() {
    cout << "From: " << sender << "\n";
    cout << "To: " << reciever << "\n";
    cout << "-------------------------------------------\n";
    cout << content << "\n";
  }
};

int main() {
  char name[20], to[20], body[100];
  cin.getline(name, 20);
  cin.getline(to, 20);
  cin.getline(body, 100);

  Text msg(name, to, body);
  // msg.viewMessage();

  msg.getSender();
  
}
