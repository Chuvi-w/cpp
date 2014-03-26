#include <iostream>
#include <stdio.h>
#include <map>
#include <locale.h>

// Перевод
// Как ввести строку целиком?
// Как читать

using namespace std;

int main()
{
  setlocale(LC_ALL, "Russian.UTF-8");

  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);

  int N; // Количество слов в словаре
  cin >> N;

  map<string, string> dict; // Словарь
  // Ключ - слово по-английски,
  // значение - слово по-русски
  //  Словарь = Ассоциативный массив

  for(int i = 0; i < N ; ++i){
    string inEnglish, inRussian;
    cin >> inEnglish >> inRussian;

    dict[inEnglish] = inRussian;
  }

  freopen("str.txt","r",stdin);

  const int strLen = 1024;
  char phrase[strLen];
  cin.getline(phrase, strLen);
  cout << phrase << endl;


  string s(phrase);
  cout << "s = \"" << s << "\"" << endl;

  for(map<string, string>::iterator i = dict.begin();
      i != dict.end();
      i++ ){
    string inEnglish = i->first; // Ключ
    string inRussian = i->second; // Значение
    // Ищем слово из словаря в строке
    size_t pos;
    do{
      pos = s.find(inEnglish);
      //cout << inEnglish << " pos " << pos << endl;
      if(pos != string::npos){ // Если подстрока найдена
        s.replace(pos, inEnglish.size(), inRussian);
      }
    } while(pos != string::npos);
  }

  cout << s << endl;
  return 0;
}
