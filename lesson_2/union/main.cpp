#include <iostream>

using namespace std;

typedef char MyType;

union InMemoryPresentation {
  MyType i;
  unsigned char b[sizeof(MyType)];
};


int main()
{
  InMemoryPresentation u;
  u.i = 'A';
  for(int i=0; i < sizeof(MyType); ++i){
    for(int b = 7; b >= 0; --b){
      unsigned char byte = u.b[i];
      // Число:    01101110  00001101
      // Ном.бита: 76543210         1
      cout << ((byte >> b) & 1);
    }
    cout << endl;
  }

  return 0;
}
