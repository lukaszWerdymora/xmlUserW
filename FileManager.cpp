#include "FileManager.h"


void FileManager :: loadFile(CMarkup &xml) {
    bool ifFileExist=xml.Load (NAME_FILE);
    //cout<<"czy utworzono plik "<<ifFileExist<<endl;
    if (!ifFileExist) {

        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }
}
void FileManager :: saveUserToFile (User user) {
    loadFile (xml);

    xml.FindElem();
    xml.IntoElem();

    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("UserID", user.getId());
    xml.AddElem("Login", user.getLogin());
    xml.AddElem("Name", user.getName());
    xml.AddElem("Surname", user.getSurname());
    xml.AddElem("Password", user.getPassword());
    string document=xml.GetDoc();
    //cout<<document;

    //xml.Save(NAME_FILE);

}
int FileManager :: returnLastID (CMarkup &xml){

    string lastID="15";
    int lastId;
    xml.Load(NAME_FILE);
    xml.ResetPos();
    xml.FindElem();


    xml.IntoElem();
    xml.FindElem("User");
    xml.IntoElem();
    while (xml.FindElem("UserID")){
        lastID=xml.GetData();
    }
    //int lastId= HelpMethods :: conversionStringToInt (lastID);
    lastId= HelpMethods :: conversionStringToInt (lastID);

    cout<<lastId;
    return 0;
}

