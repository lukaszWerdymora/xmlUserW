#include <iostream>
#include "Markup.h"
#include "User.h"
#include "UserManager.h"
#include "FileManager.h"
#include "helpMethods.h"
//http://www.firstobject.com/dn_markupmethods.htm
using namespace std;

CMarkup addUser(int id, string login, string password, string name, string surname);
void addUserVoid (CMarkup xml, string fileName);
void findUser (CMarkup xml, string searchingData);
bool logged (CMarkup xml, string login);
int main() {
    CMarkup xml;
    User user;
    FileManager fileManager("xmlUser.xml");
    UserManager userManager("xmlUser.xml");


    //addUserVoid (xml, nameFileUser);
    //addUserVoid (xml, nameFileUser);
    //findUser (xml, "Login");
    //logged (xml, "Login");


    //userManager.registerUser();
    //fileManager.saveUserToFile(user); // to niech bedzie niewidoczne do testow



    //fileManager.loadFromFileToVectorAllUsers ();

    //userManager.loggingUser();
    //fileManager.returnLastID();
    userManager.changingPassword();
    userManager.wyswietl();


    return 0;
}
CMarkup addUser(int id,string login, string password, string name, string surname) {
    CMarkup xml;

    xml.FindElem();
    xml.IntoElem();

    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("UserID", id);
    xml.AddElem("Login", login);
    xml.AddElem("Password", password);
    xml.AddElem("Name", name);
    xml.AddElem("Surname", surname);
    return xml;
}
void addUserVoid (CMarkup xml,string fileName){

    xml.FindElem();
    xml.IntoElem();

    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("UserID", 1);
    xml.AddElem("Login", "Luki");
    xml.AddElem("Password", "123");
    xml.AddElem("Name", "Lukasz");
    xml.AddElem("Surname", "Jaworski");
    xml.Save(fileName);
}

void findUser (CMarkup xml, string searchingData){
    xml.FindChildElem();
    //xml.FindElem();
    xml.IntoElem();
    //xml.FindChildElem();
    xml.IntoElem();

    bool findBool=xml.FindElem(searchingData);
    string napis=xml.GetData();
    //cout<<napis;
}
bool logged (CMarkup xml, string login){
    findUser(xml, login);
    string password;
    cout<<endl<<"Podaj haslo: ";
    cin>>password;

    xml.FindElem();
    xml.IntoElem();
    xml.FindElem();
    xml.IntoElem();
    bool findPassword=xml.FindElem("Password");

    string userPassword=xml.GetData();
    if (userPassword==password){

        cout<<"Jestes zalogowany";
        return 1;
    }else{
        cout<<"Zle haslo";
        return 0;
    }


}
