#include <cstring>
#include <iostream>
#include <ostream>
using namespace std;

// your code here
class Character {
  char *var;

  void copy(const Character &other) {
    this->var = new char[strlen(other.var) + 1];
    strcpy(this->var, other.var);
  }

public:
  Character() {}

  Character(const char *text) {
    this->var = new char[strlen(text) + 1];
    strcpy(this->var, text);
  }

  // For only one character that is not a pointer
  Character(char c) {
    this->var = new char[2];
    this->var[0] = c;
    this->var[1] = '\0';
  }

  Character(Character *c) { copy(c); }

  char *getVar() const { return var; }

  friend ostream &operator<<(ostream &out, Character &c) {
    for (int i = 0; i < strlen(c.var); i++) {
      out << c.var[i];
    }
    return out;
  }

  Character &operator=(const Character &other) {
    if (this != &other) {
      // Delete the existing memory for var
      delete[] var;

      // Allocate new memory for var and copy the content
      var = new char[strlen(other.var) + 1];
      strcpy(var, other.var);
    }
    return *this;
  }

  // Convert character to uppercase
  void toUpperCase() { *var = toupper(*var); }

  ~Character() { delete[] var; }
};

class CharSequence {
  Character *vars;
  int length;
  int totalCapacity;

  void copy(const CharSequence &other) {
    length = other.length;
    totalCapacity = other.totalCapacity;
    vars = new Character[this->totalCapacity];
    for (int i = 0; i < this->length; i++) {
      this->vars[i] = other.vars[i];
    }
  }

public:
  CharSequence() {}

  CharSequence(char *text) {
    totalCapacity = strlen(text);
    length = 0;
    vars = new Character[this->totalCapacity];
  }

  CharSequence(const CharSequence &S) { copy(S); };

  CharSequence &operator=(const CharSequence &s) {
    if (this == &s) {
      return *this;
    }

    delete[] vars;
    copy(s);
    return *this;
  }

  void increaseCapacity() {
    Character *tmp = new Character[this->totalCapacity + 10];
    for (int i = 0; i < length; i++) {
      tmp[i] = vars[i];
    }

    delete[] vars;
    vars = tmp;
    this->totalCapacity += 10;
  }

  void add(Character chara) {
    if (this->length == this->totalCapacity) {
      increaseCapacity();
    }

    vars[length] = chara;
    length++;
  }

  const Character &getCharacterAt(int index) const { return vars[index]; }

  friend std::ostream &operator<<(std::ostream &out, const CharSequence &c) {
    for (int i = 0; i < c.length; i++) {
      out << c.vars[i].getVar() << " ";
    }
    return out;
  }

  char &operator[](int i) { return vars[i].getVar()[0]; }

  void operator+=(const Character &ch) {
    Character *temp = new Character[length + 1];
    for (int i = 0; i < length; ++i) {
      temp[i] = vars[i];
    }
    temp[length++] = ch;
    delete[] vars;
    vars = temp;
  }

  friend bool operator==(const CharSequence &a, const CharSequence &b) {
    bool flag = true;
    if (a.length != b.length)
      return false;

    for (int i = 0; i < a.length; i++) {
      if (strcmp(a.vars[i].getVar(), b.vars[i].getVar()) != 0) {
        return false;
      }
    }

    return true;
  }

  CharSequence toUpperCase() const {
    CharSequence result;
    for (int i = 0; i < length; i++) {
      Character ch(vars[i].getVar());
      ch.toUpperCase();
      result += ch;
    }

    return result;
  }

  ~CharSequence() { delete[] vars; }
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
