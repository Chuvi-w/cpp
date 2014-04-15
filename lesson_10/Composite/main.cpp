#include <iostream>
#include <list>

class Component {
public:
   virtual void show() = 0;
};

class Leaf : public Component {
   std::string s;
public:
   Leaf(std::string s) : s(s) {}
   void show(){
       std::cout << s.c_str() << std::endl;
   }
};

class Composite : public Component {
   std::list<Component*> list;
public:
   void show(){
       std::list<Component*>::iterator i;
       for(i = list.begin(); i != list.end(); i++)
           (*i)->show();
   }
   void add(Component* child){
       list.push_back(child);
   }
   void remove(Component* child){
       list.remove(child);
   }
};

int main()
{
    Composite comp;
    comp.add(new Leaf("test"));
    Composite a;
    a.add(new Leaf("aa"));
    a.add(new Leaf("bb"));
    a.show();
    comp.add(&a);

    comp.show();

    return 0;
}
