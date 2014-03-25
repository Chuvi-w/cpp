#include <iostream>
#include <map>

using namespace std;

int main()
{
  string s = "Hello world!";

  map<char, int> charCount;

  cout << "charCount['A'] = " <<
    charCount['H'] << endl;

  for(string::iterator c = s.begin();
      c != s.end();
      c++){
    char letter = *c;
    map<char, int>::iterator i = charCount.find(letter);
    if(i == charCount.end()){
      cout << "end()" << endl;
      charCount[letter] = 1;
    } else {
      charCount[letter]++;
    }
  }

  charCount['Z'] = 100;

  for(map<char, int>::iterator i = charCount.begin();
      i != charCount.end();
      i++ ) {
    pair<char, int> p = *i;
    cout << "'" << p.first << "' -> " << p.second << endl;
  }

  return 0;
}
