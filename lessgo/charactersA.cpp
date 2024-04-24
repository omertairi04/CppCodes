#include <iostream>
#include <cstring>

using namespace std;

class Character {
    char var;

public:
    Character() {}

    Character(char v) {
      var = v;
    }

    void setVar(char v) {
      this->var = v;
    }

    char getVar() const {
      return var;
    }

    Character(Character& c) {
      var = c.var;
    }

    friend ostream &operator<<(ostream &out , Character &c) {
      out << c.var;
      return out;
    }
};

class CharSequence {
    Character *chars;
    int length;
public:
    CharSequence() {
      chars = nullptr;
      length = 0;
    };

    CharSequence(const char *f) {
      length = strlen(f);
      chars = new Character[length];
      for (int i=0;i<length;i++) {
        chars[i].setVar(f[i]);
      }
    }

    CharSequence(const CharSequence *c) {
      length = c->length;
      chars = new Character[length];
      for (int i=0;i<length;i++) {
        chars[i].setVar(c->chars[i].getVar());
      }
    }

    Character& operator[](int i){
      return chars[i];
    }

    CharSequence& operator +=(const Character &c) {
      Character *temp = chars;
      chars = new Character[length + 1];
      for (int i=0;i<length;i++) {
        chars[i].setVar(temp[i].getVar());
      }
      chars[length].setVar(c.getVar());
      delete [] temp;
      length++;
      return *this;
    }

    int operator[](char c) const {
      int count = 0;
      for (int i = 0; i < length; ++i) {
        if (chars[i].getVar() == c) {
          count++;
        }
      }
      return count;
    }
    bool operator==(const CharSequence &cs) {
      if (this->length == cs.length) {
        return true;
      }
      for (int i=0;i<this->length;i++) {
        if (chars[i].getVar() != cs.chars[i].getVar()) {
          return false;
        }
      }
      return true;
    }

    CharSequence &toUpperCase() {
      for (int i=0;i<length;i++) {
        chars[i].setVar(toupper(chars[i].getVar()));
      }
      return *this;
    }

    friend ostream &operator<<(ostream &out , CharSequence &c) {
      out << c;
      return out;
    }

    ~CharSequence() {
      delete [] chars;
    }
};

int main() {
  int n;
  cin >> n;

  if (n == 1) {
    cout << "Testing Character class" << endl;
    cout << "Character constructor" << endl;
    char c;
    cin >> c;
    Character cc(c);
    cout << "OK" << endl;
    cout << "Character operator <<" << endl;
    cout << cc << endl;
  } else if (n == 2) {
    cout << "Testing CharSequence constructors" << endl;
    char word[100];
    cin >> word;
    CharSequence cs1(word);
    cout << cs1 << endl;
  } else if (n == 3) {
    cout << "Testing CharSequence copy constructor and operator[int]" << endl;
    CharSequence cs("Some sequence");
    CharSequence copy(cs);
    cs[0] = 'X';
    cout << "Original: " << cs << endl;
    cout << "Copy: " << copy << endl;
  } else if (n == 4) {
    cout << "Testing CharSequence =operator and operator[int]" << endl;
    CharSequence cs("Some sequence");
    CharSequence copy;
    copy = cs;
    cs[0] = 'X';
    cout << "Original: " << cs << endl;
    cout << "Copy: " << copy << endl;
  } else if (n == 5) {
    cout << "Testing CharSequence operator+=" << endl;
    CharSequence cs;
    char word[100];
    cin >> word;
    int len = strlen(word);
    for (int i = 0; i < len; ++i) {
      cs += Character(word[i]);
    }
    cout << cs << endl;
  } else if (n == 6) {
    cout << "Testing CharSequence operator[char]" << endl;
    CharSequence cs("If you don't read the newspaper, you're uninformed. If "
                    "you read the newspaper, you're mis-informed.");
    cout << cs['e'] << endl;
  } else if (n == 7) {
    cout << "Testing CharSequence toUpperCase" << endl;
    CharSequence cs(
        "If you tell the truth, you don't have to remember anything");
    cout << cs.toUpperCase() << endl;
  } else if (n == 8) {
    cout << "Testing CharSequence operator ==" << endl;
    CharSequence cs1("abc");
    CharSequence cs2("abc");
    CharSequence cs3("abcd");
    CharSequence cs4("xyz");
    cout << (cs1 == cs2) << endl;
    cout << (cs1 == cs3) << endl;
    cout << (cs2 == cs4) << endl;
  }

  return 0;
}
