#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
  // ��������� ���� ��� ������
  freopen("in.txt", "r", stdin);
  // ��������� ���� ��� ������
  freopen("out.txt", "w", stdout);

  map<string, string> dict;

  int numberOfWords;
  cin >> numberOfWords;
  for(int i = 0; i < numberOfWords; i++){
    string inEnglish, inRussian;
    cin >> inEnglish >> inRussian;
    dict[inEnglish] = inRussian;
  }

  // TODO: ��������� ���� :)

  return 0;
}
