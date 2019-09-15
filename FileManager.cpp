#include "FileManager.h"


void FileManager :: loadFile(CMarkup &xml)
{
    bool ifFileExist=xml.Load (NAME_FILE);
    //cout<<"czy utworzono plik "<<ifFileExist<<endl;
    if (!ifFileExist)
    {

        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }

}
void FileManager :: saveUserToFile (User user)
{
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

    xml.Save(NAME_FILE);

}
int FileManager :: returnLastID ()// zwrot Id oststniego uzytkownika ma sie odbywac po vector
{

    string lastID="0";

    xml.Load(NAME_FILE);
    xml.ResetPos();
    xml.FindElem("Users");
    xml.IntoElem();
    xml.FindElem("User");
    xml.IntoElem();
    while (xml.FindElem("UserID"))
    {
        lastID=xml.GetData();
        xml.OutOfElem();
        xml.FindElem("User");
        xml.IntoElem();

    }
    int lastId= HelpMethods :: conversionStringToInt (lastID);

    return 0;
}
vector <User> FileManager :: loadAllUsersFromFileToVector ()
{

    vector <User> users;
    //loadUserFromFile( xml);
    xml.Load(NAME_FILE);
    xml.ResetPos();

    xml.FindElem("Users");
    xml.IntoElem();
    //xml.FindElem("User");
    //xml.IntoElem();
    while (xml.FindElem("User"))
    {
        xml.IntoElem();
        users.push_back(loadUserFromFile( xml));
        xml.OutOfElem();
        //xml.FindElem("User");
        //xml.IntoElem();

    }

    return users;
}
User FileManager :: loadUserFromFile (CMarkup &xml)  // przyda sie przy wyszukiwaniu po podanych parametrach
{

    User user;


    if (xml.FindElem("UserID"))
    {
        string id="";
        id=xml.GetData();
        user.setId(HelpMethods :: conversionStringToInt (id));
    };

    if (xml.FindElem("Login"))
    {
        user.setLogin(xml.GetData());
    };
    if (xml.FindElem("Name"))
    {
        user.setName(xml.GetData());
    };
    if (xml.FindElem("Surname"))
    {
        user.setSurname(xml.GetData());
    };
    if (xml.FindElem("Password"))
    {
        user.setPassword(xml.GetData());
    };

    return user;
}

