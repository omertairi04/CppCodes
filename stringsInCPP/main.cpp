#include <iostream>
#include <string>
using namespace std;

int main() {
    string greet;
    // get string input
    getline(cin, greet);

    // or this way for multiple
    //    while(getline(cin, greet) && !greet.empty()) {
    //        cout << greet << endl;
    //    }

//    int greetLength = greet.length();
//    cout << greetLength << endl;

    string happyGreet;
    getline(cin, happyGreet);

    /*
     * COMPARE strings
     * value < 0 = this is shorter than str or 1st char that doesn't match is samller than str
     * value > 0 = this is longer than str or 1st char that doesn't match is longer than str
     *
     * YOU CAN ALSO USE - ==;!=;>;<;>=;<=
    */
    int cmp = greet.compare(happyGreet);
    if (cmp == 0) cout << "Same length " << cmp << endl;
    else if (cmp < 0) cout << "Greet is smaller than happyGreet " << cmp << endl;
    else cout << "Greet is longer than happyGreet " << cmp << endl;

    /*
     * CONCATINATION
     */

    string bothGreetings = greet + happyGreet;
    cout << bothGreetings << endl;

    /*
     * APPENDING str OR char
     */

    string endLine = "/";
    endLine = "\n";
    bothGreetings += endLine;

    cout << "EDITED " <<bothGreetings;
    cout << "This appears in new line\n";

    /*
     * SEARCHING/FIND-ING
     * find("text to find") - searches the str for the first occurrence of the arg.
     * rfind - finds last occurrence of the content in str
     * find_first_of - find char in string
     * find_last_of - find last occurrence of char
     * find_first_not_of - search str for the first chars that don't
        match any of the chars specified in its arguments
     * find_last_not_of - searches for last char that does not match any of
        chars specified in its arguments
     */
    string text = "Research is what I'm doing when I don't know what I'm doing.";
    int firstDo = text.find("do");
    cout << "First occurrence of 'do': " << firstDo << endl;
    int secondDo = text.find("do", firstDo + 1);
    cout << "Second occurrence of 'do': " << secondDo << endl;
    int thirdDo = text.find("do", secondDo + 1);
    cout << "Third occurrence of 'do': " << thirdDo << endl;
    int lastDo = text.rfind("do");
    cout << "Last occurrence of 'do': " << lastDo << endl;
    int kPos = text.find("k");
    cout << "Position of 'k': " << kPos << endl;
    int zPos = text.find("z");
    cout << "Position of 'z': " << zPos << endl;
    int firstIPos = text.find_first_of("I");
    cout << "First occurrence of 'I': " << firstIPos << endl;
    int lastIPos = text.find_last_of("I");
    cout << "Last occurrence of 'I': " << lastIPos << endl;

    /*
     * SUBSTRINGS
     * string substr(size_t pos = 0, size_t len = npos) const;
     * returns a string containing a copy of the object that starts from the
     * char postion pos until the len char(or the end)
     *
     * pos < 0 - runtime error
     * pos == string - empty string
     * len < 0 - undefined behaviour
    */
    string myString;
    myString = "No amount of experimentation can ever prove me right; a single experiment can prove me wrong.";
    int len = myString.length();
    cout << "Original sentence: " << myString << endl;

    int semiCol = myString.find("; ");
    string firstPart = myString.substr(0, semiCol);
    firstPart += ".";
    cout << "First part: " << firstPart << endl;
    string secondPart = myString.substr(semiCol + 2);
    cout << "Second part: " << secondPart << endl;

    /*
     * REPLACING/INSERTING
     * - Inserts strs to the right before char indicated by pos
     * insert (size_t pos, const string& str)
     * - Replace the portion of str that begins at
       char pos and stans len chars with str
     * replace (size_t pos, size_t len, const string& str)
     */

    secondPart.replace(0, 1, "A");
    cout << "Second part REPLACE: " << secondPart << endl;
    secondPart.insert(secondPart.length(), " - Albert Einstein");
    cout << "Second part INSERT: " << secondPart << endl;

    /*
     * LOOPING/PARSING
     */
    string loop = "loop";
    for (int i=0;i<loop.length();i++)
        cout << i << ": " << loop[i] << endl;
    string content = "content";
    for (char ch : content)
        cout << ch << endl;
    return 0;
}
