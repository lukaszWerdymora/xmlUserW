#include "UserManager.h"
void UserManager :: registerUser()
{
    User user;

    user=getDataNewUser();
    users.push_back(user);
    fileManager.saveUserToFile (user);
}
User UserManager :: getDataNewUser ()
{
    User user;

    cout<<"Podaj dane uzytkownika do rejestracji: \n";
    user.setId (8);
    user.setLogin("Lukasz");
    user.setName ("Maciej");
    user.setSurname ("Brzoza123");
    user.setPassword ("tajne");

    return user;
}
void UserManager :: addUserToVector()
{
    User user;
    user=getDataNewUser();
    users.push_back(user);
}
void UserManager :: wyswietl ()
{
    //cout<<users.size();
    for (int i=0; i<users.size(); i++)
    {

        cout<<users[i].getId()<<endl;
        cout<<users[i].getName()<<endl;
        cout<<users[i].getSurname()<<endl;
        cout<<users[i].getPassword()<<endl;
    }

}

int UserManager :: loggingUser()
{
    //User user;


    string login="", password="";
    int step=0;
    cout<<endl<< "Podaj login: ";
    cin>>login;
    vector <User>::iterator itr =users.begin();
    while (itr!=users.end())
    {

        if (itr -> User :: getLogin() == login)
        {
            for (int numberAttempts =3; numberAttempts>0; numberAttempts--){
                cout << "Podaj haslo. Pozostalo prob: " << numberAttempts << ": ";
                cin >> password;
                if (itr ->User :: getPassword() == password){
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    idLoggedUser= itr -> User :: getId();
                    return idLoggedUser;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return 0;

        }
        itr++;

    }

    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
return 0;
}

int UserManager :: returnLastIdNewUser(){
    int id=0;
    if (users.empty()==true){
        id=1;
    }else {
        id=users.back().getId()+1;
    }
    cout<<id;
    return id;
}
