#include <iostream>
#include <cstring>
#include <string>
using namespace std;
void printStructmMiku(struct miku temp);
void printStructmMiku(struct miku *temp);
struct miku{
  char name[10];
  string like;
  int year;
};
int main(){
  miku Hmiku;

  strcpy(Hmiku.name,"yankai");
  //strcpy(Hmiku.like,"Miku");
  Hmiku.like="Miku";
  Hmiku.year=17;
  
  /*cout<<"name: "<<Hmiku.name<<endl
      <<"like: "<<Hmiku.like<<endl
      <<"year: "<<Hmiku.year<<endl;
  */
printStructmMiku(Hmiku);
printStructmMiku(&Hmiku);
return 0;
}
void printStructmMiku(struct miku temp){
    cout<<"name: "<<temp.name<<endl
      <<"like: "<<temp.like<<endl
      <<"year: "<<temp.year<<endl;
}
void printStructmMiku(struct miku *temp){
    cout<<"name: "<<temp->name<<endl
      <<"like: "<<temp->like<<endl
      <<"year: "<<temp->year<<endl;
}