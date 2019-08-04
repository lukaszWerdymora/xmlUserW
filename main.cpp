#include <iostream>
#include "Markup.h"
#include "User.h"
#include "UserManager.h"
#include "FileManager.h"
//http://www.firstobject.com/dn_markupmethods.htm
using namespace std;

CMarkup addUser(int id, string login, string password, string name, string surname);
void addUserVoid (CMarkup xml, string fileName);
void findUser (CMarkup xml, string searchingData);
bool logged (CMarkup xml, string login);
int main() {
    CMarkup xml;
    User user;
    UserManager userManager("xmlUser.xml");
    FileManager fileManager("xmlUser.xml");

/*
    string nameFileUser="xmlUsers.xml";
    bool ifFileExist = xml.Load(nameFileUser);

    if (!ifFileExist){

        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
        cout<<"wykonala sie warunek";
    }
*/
    //addUserVoid (xml, nameFileUser);
    //addUserVoid (xml, nameFileUser);
    //findUser (xml, "Login");
    //logged (xml, "Login");


    userManager.registerUser();
    fileManager.returnLastID(xml);



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
