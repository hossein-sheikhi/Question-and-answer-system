#include <iostream>

using namespace std;

struct DateTime
{
    int year, month, day, hour, minute, second;
};

class Permission
{
private:
    string title;

public:
    Permission(string _title) : title(_title) {}
    static Permission *create(string _title);
    string titleback()
    {
        return title;
    }
};
/// tabeh print braye pree

Permission *perar[100] = {new Permission("add-descriptive-question"), new Permission("add-four-choice-question"), new Permission("edit-descriptive-question"), new Permission("edit-four-choice-question"), new Permission("add-user"), NULL};


Permission *Permission::create(string _title)
{
    Permission *temp = new Permission(_title);
    int i = 0;
    for (; perar[i] != NULL; i++)
    {
        ;
    }
    perar[i] = temp;
    return temp;
}

class User
{
private:
    string name, username, password;
    Permission *permissions[100] = {NULL};

public:
    User(string _name, string _username, string _password) : name(_name), username(_username), password(_password) {}
    static User *create(string, string, string);
    void addPermission(Permission *);
    void print();
    void printUser(); // to soal nabod vali lazem bod
    bool checkAuth(string, string);
};

void User::printUser() { cout << username << endl; }

bool User::checkAuth(string _user, string _pass)
{
    if (username == _user && password == _pass)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void User::addPermission(Permission *permission)
{
    int i = 0;
    for (; permissions[i] != NULL; i++)
    {
        if (permissions[i] == permission)
            return;
    }
    permissions[i] = permission;
}
User *userarray[100] = {new User("admin", "admin", "123456")};

/// agar dastresi add user dasht
// baresi shavad
User *User ::create(string _name, string _username, string _password)
{
    User *newuser = new User(_name, _username, _password);
    int i = 0;
    for (; userarray[i]; i++)
    {
        ;
    }
    userarray[i] = newuser;
    return newuser;
}
void User::print()
{
    cout << "username is:" << username << endl
         << "password is:" << password;
    cout << "permissions are:";
    for (int i = 0; permissions[i] != NULL; i++)
    {
        cout << permissions[i]->titleback() << endl;
    }
}

class Auth
{
private:
    static User *auth;

public:
    static User *login(string username, string password);
    static void logout() { auth = NULL; }
    static User *Whoami() { return auth; }
};
User *Auth::login(string username, string password)
{
    for (int i = 0; userarray[i] != NULL; i++)
    {
        if (userarray[i]->checkAuth(username, password))
        {
            auth = userarray[i];
            return userarray[i];
        }
    }
    return NULL;
}

class Tag
{
private:
    string title;

public:
    Tag(string str) : title(str) {}
    void print();
    string showTag();       // baraye print all niyaze
    static void printAll(); // static behtare
    static Tag *create(string);
};

void Tag::print() { cout << title << endl; }
string Tag::showTag() { return title; }

Tag *MyTags[100] = {nullptr};

Tag *Tag::create(string TAG)
{
    int x = 0;
    Tag *TEMP = new Tag(TAG);
    while (MyTags[x] != nullptr)
    {
        x++;
    }
    MyTags[x] = TEMP;
    return TEMP;
}

void Tag::printAll()
{
    cout << "your tags are :" << endl;
    for (size_t i = 0; i < 100; i++)
    {
        if (MyTags[i] != nullptr)
        {
            cout << "(" << i << "). ";
            MyTags[i]->print();
        }
    }
}

class Question
{
protected:
    string question;
    DateTime createdAt;
    bool isPublished;
    string type;
    User user;
    Tag *tags[100] = {nullptr};

public:
    void publish();
    void unpublish();
    void addTag(Tag *); ////  BAYAD EZAFEH SHAVAD
    // MITAVANAD NABASHAD
    string Info_type() { return type; }   // niaz bod baraye print all
    string q_print() { return question; } // niaz bod baraye print all
    ////////////////////////
    Question(string, string, User, DateTime);
    virtual void print() = 0;
    virtual void printAll() = 0;
};

void Question::addTag(Tag *_tag)
{
    int i = 0;
    for (; tags[i] != nullptr; i++)
    {
        if (MyTags[i]->showTag() == _tag->showTag())
            break;
    }
    MyTags[i]->showTag() = _tag->showTag();
};

Question::Question(string _type, string _question, User _user, DateTime _createdAt) : type(_type), question(_question), user(_user), createdAt(_createdAt)
{
    isPublished = false;
}

Question *QuestionS[100] = {NULL};

void Question::unpublish() { isPublished = false; }
void Question::publish() { isPublished = true; }

class Descriptive : public Question
{
private:
    string answer;

public:
    void print();
    void printAll(); // static nis
    void addAnswer(string);
    Descriptive(User, DateTime, string);
    static Descriptive *create(string, DateTime, User);
    /// TABEH EDIT
};

Descriptive::Descriptive(User usr, DateTime crAt, string Ques) : Question("Descriptive", Ques, usr, crAt) {}

Descriptive *create(string, DateTime, User);

void Descriptive::print()

{
    cout << "Question type: " << type << endl
         << "Question: " << question << endl
         << "answer: " << answer << endl
         << " published by: ";
    user.printUser();
    cout << "Date of Release: " << createdAt.year << "/" << createdAt.month << "/" << createdAt.day << endl
         << "Release time: " << createdAt.hour << ":" << createdAt.minute << ":" << createdAt.second << endl;

    if (isPublished != false)
    {
        cout << "This question is in publishing mode." << endl;
    }
    else
    {
        cout << "This question isn't in publishing mode." << endl;
    }

    // TAG SOAL HA BAYAD PRINT SHAVAD
}

void Descriptive::printAll()
{

    for (int i; QuestionS[i] != NULL; i++)
    {
        if (QuestionS[i]->Info_type() == "Descriptive")
        {
            cout << "❇️" << i << " : " << QuestionS[i]->q_print() << "❓" << endl;
        }
    }
}

void Descriptive::addAnswer(string answer)
{
    this->answer = answer;
}

class FourChoice : public Question
{
private:
    string A;
    string B;
    string C;
    string D;
    char answer; // ARAYE BESHE

public:
    ///// TABEH STATIC CREATE
    /// TABEH EDIT
    void print();
    void printAll();
    FourChoice(char, string, string, string, string, User, DateTime, string);
};
FourChoice::FourChoice(char answer, string A, string B, string C, string D, User usr, DateTime crAt, string Ques) : Question("FourChoice", Ques, usr, crAt)
{
    this->A = A;
    this->B = B;
    this->C = C;
    this->D = D;
    this->answer = answer;
}

void FourChoice::printAll()
{

    for (int i; QuestionS[i] != NULL; i++)
    {
        if (QuestionS[i]->Info_type() == "FourChoice")
        {
            cout << "💠" << i << " : " << QuestionS[i]->q_print() << "❓" << endl;
        }
    }
}

void FourChoice::print()
{
    cout << "Question type: " << type << endl
         << "Question: " << question << endl
         << "A- " << A << endl
         << "B- " << B << endl
         << "C-" << C << endl
         << "D-" << D << endl
         << "The correct option for this question is " << answer << endl
         << " published by: ";
    user.printUser();
    cout << "Date of Release: " << createdAt.year << "/" << createdAt.month << "/" << createdAt.day << endl
         << "Release time: " << createdAt.hour << ":" << createdAt.minute << ":" << createdAt.second << endl;

    if (isPublished != false)
    {
        cout << "This question is in publishing mode." << endl;
    }
    else
    {
        cout << "This question isn't in publishing mode." << endl;
    }
    // TAG SOAL HA BAYAD PRINT SHAVAD
}

void NoLogin()
{
    cout << "⚪️(L) Login  " << endl
         << "⚪️(V) View Question" << endl;
}

void Login(string u_ser)
{
    cout << "--------------------" << endl;
    cout << "Hello " << u_ser << " 🤚" << endl;
    cout << "--------------------" << endl;
    cout << "⚪️(Q) Question Menu " << endl;
    cout << "⚪️(T) Tag Menu" << endl;
    cout << "⚪️(U) User Menu" << endl;
}

void Qu_Menu()
{
    cout << "⭕️(L) list of Descriptive Questions with ID" << endl;
    cout << "⭕️(C) create Descriptive Question" << endl;
    cout << "⭕️(E) edit Descriptive Question" << endl;
    cout << "⭕️(P) print Descriptive Question" << endl;
    cout << "🔴(l) list of FourChoice Questions with ID" << endl;
    cout << "🔴(c) create FourChoice Question" << endl;
    cout << "🔴(e) edit FourChoiceQuestion" << endl;
    cout << "🔴(p) print FourChoice Question" << endl;
}
void User_Menu()
{
    cout << "⚪️(L) List of Users with ID" << endl;
    cout << "⚪️(C) Create new User" << endl;
    cout << "⚪️(A) Add Permission to a User" << endl;
}

void p_FourChoice()
{
    User admin("null", "null", "null");
    DateTime TestDate = {2024, 6, 14, 18, 25, 00};

    FourChoice testQ('0', "null", "null", "null", "null", admin, TestDate, "null");
}
    void p_Descriptive()
    {
    }

    void p_Quetions()
    {
        p_Descriptive();
        p_FourChoice();
    }

    int main()
    {






        char x;
        NoLogin();
        cin >> x;
        switch (x)
        {
        case 'l':
        case 'L':
            /* code */
            break;
        case 'V':
        case 'v':

        default:
            system("clear");
            cout << "❌ Not Found " << x << endl;
            break;
        }

        return 0;
    }
