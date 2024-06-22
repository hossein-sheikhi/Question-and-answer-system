#include <iostream>

/*
barkhi  az bakhsh ha be dorosti dar windows kar nemikonad ama linux okaye.
clear("syetem")
emojis
*/
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

Permission *perar[100] = {nullptr};

Permission *Permission::create(string _title)
{
    Permission *temp = new Permission(_title);
    int i = 0;
    for (; perar[i] != nullptr; i++)
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
    Permission *permissions[100] = {nullptr};

public:
    User(string _name, string _username, string _password) : name(_name), username(_username), password(_password) {}
    static User *create(string, string, string, User *);
    void addPermission(Permission *);
    void print();
    void printUser(); // to soal nabod vali lazem bod
    bool checkAuth(string, string);
    bool cPermission(Permission *);
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

bool User::cPermission(Permission *entry)
{
    for (int i = 0; permissions[i] != nullptr; i++)
    {
        if (permissions[i] == entry)
            return true;
    }
    return false;
}

void User::addPermission(Permission *permission)
{
    int i = 0;
    for (; permissions[i] != nullptr; i++)
    {
        if (permissions[i] == permission)
            return;
    }
    permissions[i] = permission;
}

User *userarray[100] = {nullptr};

User *User ::create(string _name, string _username, string _password, User *whoami)
{
    User *newuser = new User(_name, _username, _password);
    if (whoami->cPermission(perar[4]))
    {
        int i = 0;
        for (; userarray[i]; i++)
        {
            ;
        }
        userarray[i] = newuser;
        return newuser;
    }
    return NULL;
}
void User::print()
{
    cout << "username is:" << username << endl
         << "password is:" << password;
    cout << "permissions are:";
    for (int i = 0; permissions[i] != nullptr; i++)
    {
        cout << permissions[i]->titleback() << endl;
    }
}

class Auth
{
private:
    inline static User *auth = nullptr;

public:
    static User *login(string username, string password);
    static void logout()
    {
        cout << "You are logged out" << endl;
        auth = nullptr;
    }
    static User *Whoami() { return auth; }
};
User *Auth::login(string username, string password)
{
    for (int i = 0; userarray[i] != nullptr; i++)
    {
        if (userarray[i]->checkAuth(username, password))
        {
            auth = userarray[i];
            return userarray[i];
        }
    }
    return nullptr;
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
    int i = 0;
    Tag *TEMP = new Tag(TAG);
    for (; MyTags[i] != nullptr; i++)
    {
    }
    MyTags[i] = TEMP;
    return TEMP;
}

void Tag::printAll()
{
    system("clear");
    for (int i = 0; MyTags[i] != nullptr; i++)
    {
        cout << "🤡 " << i << " -> ";
        MyTags[i]->print();
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
    void addTag(Tag *);
    // MITAVANAD NABASHAD
    bool ISpublish() { return isPublished; };
    string Info_type() { return type; }   // niaz bod baraye print all
    string q_print() { return question; } // niaz bod baraye print all
    ////////////////////////
    Question(string, DateTime, string, User);
    virtual void addAnswer(string) = 0;
    virtual void print() = 0;
    virtual void printAll() = 0;
    virtual Question *edit(string, DateTime, User) = 0;
    virtual Question *edit(string, DateTime, User, string, string, string, string, char) = 0;
};

Question::Question(string _question, DateTime _createdAt, string _type, User _user) : question(_question), createdAt(_createdAt), type(_type), user(_user)
{
    isPublished = false;
}

void Question::addTag(Tag *_tag)
{
    int h = 0;
    while (true)
    {
        if (tags[h] == nullptr)
        {
            tags[h] = _tag;
            break;
        }

        else if (tags[h] == _tag)
        {
            break;
        }
        else
        {
            h++;
        }
    }
}

Question *QuestionS[100] = {nullptr};

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
    Question *edit(string question, DateTime createdAt, User user) override;
    Question *edit(string question, DateTime createdAt, User user, string A, string B, string C, string D, char answer) override;
};

Descriptive *Descriptive::create(string question, DateTime createdAt, User user)
{
    if (user.cPermission(perar[0]))
    {

        Descriptive *temp = new Descriptive(user, createdAt, question);
        int i = 0;
        for (; QuestionS[i] != nullptr; i++)
        {
        }
        QuestionS[i] = temp;
        return temp;
    }
    return nullptr;
}

Question *Descriptive::edit(string question, DateTime createdAt, User user, string A, string B, string C, string D, char answer) { return NULL; }

Question *Descriptive::edit(string str, DateTime dt, User usr)
{
    if (usr.cPermission(perar[2]))
    {

        this->question = str;
        this->createdAt = dt;
        this->user = usr;

        return this;
    }
    return nullptr;
}

Descriptive::Descriptive(User usr, DateTime crAt, string Ques) : Question(Ques, crAt, "Descriptive", usr) {}

void Descriptive::print()

{
    cout << "------------------------------------------" << endl;
    cout << "Question type: " << type << endl
         << "Question: " << question << endl
         << "answer: " << answer << endl
         << "published by: ";
    user.printUser();
    cout << "Date of Release: " << createdAt.year << "/" << createdAt.month << "/" << createdAt.day << endl
         << "Release time: " << createdAt.hour << ":" << createdAt.minute << ":" << createdAt.second << endl;

    if (isPublished != false)
    {
        cout << "This question is in publishing mode." << endl;
    }
    else
    {
        cout << "This question isn't in publishing mode." << endl
             << endl;
    }

    cout << "Tags for this question :" << endl;
    if (tags[0] == nullptr)
    {
        cout << "not tags for this question" << endl;
    }
    else
    {

        for (int i = 0; tags[i] != nullptr; i++)
        {
            tags[i]->print();
        }
    }
    cout << "------------------------------------------" << endl;
}

void Descriptive::printAll()
{

    for (int j = 0; QuestionS[j] != nullptr; j++)
    {
        if (QuestionS[j]->Info_type() == "Descriptive")

            if (QuestionS[j]->ISpublish() != false)
            {
                cout << "❇️  " << j << " : " << QuestionS[j]->q_print() << "❓" << endl;
            }
    }
}

void Descriptive::addAnswer(string ans)
{
    answer = ans;
}

class FourChoice : public Question
{
private:
    string A;
    string B;
    string C;
    string D;
    char answer;

public:
    void print();
    void printAll();
    static FourChoice *create(string, DateTime, User, string, string, string, string, char);
    void addAnswer(string){};
    Question *edit(string, DateTime, User);
    Question *edit(string question, DateTime createdAt, User user, string A, string B, string C, string D, char answer) override;
    FourChoice(char, string, string, string, string, User, DateTime, string);
};

FourChoice *FourChoice::create(string question, DateTime createdAt, User user, string A, string B, string C, string D, char answer)
{
    if (user.cPermission(perar[1]))
    {

        FourChoice *temp = new FourChoice(answer, A, B, C, D, user, createdAt, question);
        int i = 0;
        for (; QuestionS[i] != nullptr; i++)
        {
        }
        QuestionS[i] = temp;
        return temp;
    }
    return NULL;
}

Question *FourChoice::edit(string, DateTime, User) { return NULL; }
Question *FourChoice::edit(string question, DateTime createdAt, User user, string A, string B, string C, string D, char answer)
{

    if (user.cPermission(perar[3]))
    {

        this->question = question;
        this->createdAt = createdAt;
        this->user = user;
        this->A = A;
        this->B = B;
        this->C = C;
        this->D = D;
        this->answer = answer;
        return this;
    }
    return NULL;
}

FourChoice::FourChoice(char ans, string a, string b, string c, string d, User usr, DateTime crAt, string Ques) : Question(Ques, crAt, "FourChoice", usr)
{
    A = a;
    B = b;
    C = c;
    D = d;
    answer = ans;
}

void FourChoice::printAll()
{

    for (int i = 0; QuestionS[i] != nullptr; i++)
    {
        if (QuestionS[i]->Info_type() == "FourChoice")
        {
            if (QuestionS[i]->ISpublish() != false)
            {
                cout << "💠 " << i << " : " << QuestionS[i]->q_print() << "❓" << endl;
            }
        }
    }
}

void FourChoice::print()
{
    cout << "------------------------------------------" << endl;
    cout << "Question type: " << type << endl
         << "Question: " << question << endl
         << "A-" << A << endl
         << "B-" << B << endl
         << "C-" << C << endl
         << "D-" << D << endl
         << "The correct option for this question is " << answer << endl
         << "published by: ";
    user.printUser();
    cout << "Date of Release: " << createdAt.year << "/" << createdAt.month << "/" << createdAt.day << endl
         << "Release time: " << createdAt.hour << ":" << createdAt.minute << ":" << createdAt.second << endl;

    if (isPublished != false)
    {
        cout << "This question is in publishing mode." << endl;
    }
    else
    {
        cout << "This question isn't in publishing mode." << endl
             << endl;
        ;
    }

    cout << "Tags for this question :" << endl;
    if (tags[0] == nullptr)
    {
        cout << "not tags for this question" << endl;
    }
    else
    {

        for (int i = 0; tags[i] != nullptr; i++)
        {
            tags[i]->print();
        }
    }
    cout << "------------------------------------------" << endl;
}

void p_users()
{
    system("clear");
    for (int i = 0; userarray[i] != nullptr; i++)
    {
        cout << "👥 " << i << " -> ";
        userarray[i]->printUser();
    }
}

// void p_tags()
// {
//     for (int i = 0; MyTags[i] != nullptr; i++)
//     {
//         cout << "🤡 " << i << " -> ";
//         MyTags[i]->print();
//     }
// }

void p_FourChoice()
{

    User admin("nullptr", "nullptr", "nullptr");
    DateTime TestDate = {2024, 6, 14, 18, 25, 00};
    FourChoice testQ('0', "nullptr", "nullptr", "nullptr", "nullptr", admin, TestDate, "nullptr");
    testQ.printAll();
}

/// soal daram
void p_Descriptive()
{
    User admin("nullptr", "nullptr", "nullptr");
    DateTime TestDate = {2024, 6, 14, 18, 25, 00};
    Descriptive testQ(admin, TestDate, "00000");
    testQ.printAll();
}

// ------------------------------------------------------------------------------------FRONT--------------------------------------------------------------------------------------
void NoLogin();
void CinQTU();
void Login();
void TAG_MENU();
void Qu_Menu();
void User_Menu();
void _loginMenu();
void Exit();
void p_Qustions();
void PublishQ(int);

int main()
{
    Permission::create("add-descriptive-question");
    Permission::create("add-four-choice-question");
    Permission::create("edit-descriptive-question");
    Permission::create("edit-four-choice-question");
    Permission::create("add-user");
    User *x = new User("admin", "admin", "123456");
    userarray[0] = x;
    userarray[0]->addPermission(perar[0]);
    userarray[0]->addPermission(perar[1]);
    userarray[0]->addPermission(perar[2]);
    userarray[0]->addPermission(perar[3]);
    userarray[0]->addPermission(perar[4]);
    Descriptive::create("are you ready", {9, 9, 9, 9, 9, 9}, *userarray[0]);
    Descriptive::create("HOW ARE YOU", {9, 9, 9, 9, 9, 9}, *userarray[0]);
    FourChoice::create("Is dr a good person", {9, 9, 9, 9, 9, 9}, *userarray[0], "yes", "yes", "yes", "yes", 'a');
    QuestionS[0]->publish();
    QuestionS[1]->publish();
    QuestionS[2]->publish();
    Tag::create("programmer");
    Tag::create("Computer Engineering");
    QuestionS[0]->addTag(MyTags[0]); // TEST
    NoLogin();
    return false;
}

void NoLogin()
{

    system("clear");
    cout << "⚪️(L) Login  " << endl
         << "⚪️(V) View Question" << endl;
    char x;
    cin >> x;
    switch (x)
    {
    case 'l':
    case 'L':
        Login();
        break;
    case 'V':
    case 'v':
        p_Qustions();
        break;
    default:
        system("clear");
        cout << "❌ Not Found " << x << endl;
        break;
    }
}

void CinQTU()
{
    char x;
    cin >> x;
    switch (x)
    {
    case 'Q':
    case 'q':
        Qu_Menu();

        break;
    case 'T':
    case 't':
        TAG_MENU();

        break;
    case 'U':
    case 'u':
        User_Menu();

        break;
    case 'L':
    case 'l':
        Auth::logout();
        NoLogin();
        break;

    default:
        cout << " Not found " << x << "❌" << endl;
        break;
    }
}

void Login()
{

    string Name, UserName, PASSword;
    cin.ignore();
    cout << "write yuor username :";
    getline(cin, UserName);
    cout << "write yuor password :";
    getline(cin, PASSword);
    if (Auth::login(UserName, PASSword))
    {
        system("clear");
        cout << "--------------------" << endl;
        cout << "Hello " << UserName << " 🤚" << endl;
        cout << "--------------------" << endl;
        cout << "⚪️(Q) Question Menu " << endl;
        cout << "⚪️(T) Tag Menu" << endl;
        cout << "⚪️(U) User Menu" << endl;
        cout << "⚪️(L) Log out" << endl;
        CinQTU();
    }
    else
    {
        system("clear");
        cout << " User Not found ❌" << endl;
    }
}

void TAG_MENU()
{
    system("clear");
    cout << "⚪️(L) List of Tags with ID  " << endl
         << "⚪️(C) Create new Tag " << endl;
    cout << "📍(0) exit " << endl;

    string title;
    char h;
    cin >> h;
    switch (h)
    {
    case '0':
        system("clear");
        _loginMenu();
        break;
    case 'C':
    case 'c':
        cin.ignore();
        cout << "Write your tag :" << endl;
        getline(cin, title);
        Tag::create(title);
        system("clear");
        TAG_MENU();
        break;
    case 'L':
    case 'l':
        Tag::printAll();
        Exit();
        break;
    default:
        system("clear");
        cout << "not found " << h << "❌" << endl;
        _loginMenu();
        break;
    }
}

void Qu_Menu()
{
    system("clear");
    cout << "⭕️(L) list of Descriptive Questions with ID" << endl;
    cout << "⭕️(C) create Descriptive Question" << endl;
    cout << "⭕️(E) edit Descriptive Question" << endl;
    cout << "⭕️(P) print Descriptive Question" << endl;
    cout << "🔴(l) list of FourChoice Questions with ID" << endl;
    cout << "🔴(c) create FourChoice Question" << endl;
    cout << "🔴(e) edit FourChoiceQuestion" << endl;
    cout << "🔴(p) print FourChoice Question" << endl;
    cout << "📍(0) exit " << endl;

    char x, correct;
    int i, j, h;
    cin >> x;
    string _question, G1, G2, G3, G4;
    DateTime s1;
    string Answer;
    switch (x)
    {
    case 'L':
        system("clear");
        p_Descriptive();
        Exit();
        break;
    case 'C':
        cout << "write your question : ( Without ?)" << endl;
        cin.ignore();
        getline(cin, _question);
        cout << "write your answer :" << endl;
        cin >> Answer;
        cout << "write your date :" << " year-month-day \n exp 2024 01 02" << endl;
        cin >> s1.year >> s1.month >> s1.day;
        cout << "write your date :" << " hour-minute-Second \n exp 15 27 09" << endl;
        cin >> s1.hour >> s1.minute >> s1.second;
        Descriptive::create(_question, s1, *Auth::Whoami());
        i = 0;
        for (; QuestionS[i] != nullptr; i++)
        {
        }
        PublishQ(--i);
        QuestionS[i]->addAnswer(Answer);

        cout << "How many tags do you want to add?" << endl;
        cin >> j;
        for (int z = 0; z < j; z++)
        {
            cout << "write index tag :" << endl;
            cin >> h;
            QuestionS[i - 1]->addTag(MyTags[h]);
        }

        system("clear");

        Qu_Menu();
        break;
    case 'E':
        system("clear");
        p_Descriptive();
        cout << "which question?" << endl;
        cin >> i;
        cout << "write your question : ( Without ?)" << endl;
        cin.ignore();
        getline(cin, _question);
        cout << "write your date :" << " year-month-day \n exp 2024 01 02" << endl;
        cin >> s1.year >> s1.month >> s1.day;
        cout << "write your date :" << " hour-minute-Second \n exp 15 27 09" << endl;
        cin >> s1.hour >> s1.minute >> s1.second;
        QuestionS[i]->edit(_question, s1, *Auth::Whoami());
        system("clear");
        Qu_Menu();
        break;
    case 'P':
        system("clear");
        p_Descriptive();
        cout << "Enter the question number : " << endl;
        cin >> i;
        system("clear");
        QuestionS[i]->print();
        Exit();
        break;
    case 'l':
        system("clear");
        p_FourChoice();
        Exit();
        break;
    case 'c':

        cout << "write your question : (Without ?)" << endl;
        cin.ignore();
        getline(cin, _question);
        cout << "Write the text of option A :" << endl;
        cin.ignore();
        getline(cin, G1);
        cout << "Write the text of option B :" << endl;
        cin.ignore();
        getline(cin, G2);
        cout << "Write the text of option C :" << endl;
        cin.ignore();
        getline(cin, G3);
        cout << "Write the text of option D :" << endl;
        cin.ignore();
        getline(cin, G4);
        cout << "Which option is correct? (A,B,C,D)" << endl;
        cin >> correct;
        cout << "write your date :" << " year-month-day \n exp 2024 01 02" << endl;
        cin >> s1.year >> s1.month >> s1.day;
        cout << "write your date :" << " hour-minute-Second \n exp 15 27 09" << endl;
        cin >> s1.hour >> s1.minute >> s1.second;
        FourChoice::create(_question, s1, *Auth::Whoami(), G1, G2, G3, G4, correct);
        i = 0;
        for (; QuestionS[i] != nullptr; i++)
        {
        }
        PublishQ(i - 1);
        system("clear");
        Tag::printAll();
        cout << "How many tags do you want to add?" << endl;
        cin >> j;
        for (int z = 0; z < j; z++)
        {
            cout << "write index tag :" << endl;
            cin >> h;
            QuestionS[i - 1]->addTag(MyTags[h]);
        }
        system("clear");
        Qu_Menu();
        break;
    case 'e':
        system("clear");
        p_FourChoice();
        cout << "which question?" << endl;
        cin >> i;
        cout << "write your question : (Without ?)" << endl;
        cin.ignore();
        getline(cin, _question);
        cout << "Write the text of option A :" << endl;
        cin.ignore();
        getline(cin, G1);
        cout << "Write the text of option B :" << endl;
        cin.ignore();
        getline(cin, G2);
        cout << "Write the text of option C :" << endl;
        cin.ignore();
        getline(cin, G3);
        cout << "Write the text of option D :" << endl;
        cin.ignore();
        getline(cin, G4);
        cout << "Which option is correct? (A,B,C,D)" << endl;
        cin >> correct;
        cout << "write your date :" << " year-month-day \n exp 2024 01 02" << endl;
        cin >> s1.year >> s1.month >> s1.day;
        cout << "write your date :" << " hour-minute-Second \n exp 15 27 09" << endl;
        cin >> s1.hour >> s1.minute >> s1.second;
        QuestionS[i]->edit(_question, s1, *Auth::Whoami(), G1, G2, G3, G4, correct);
        PublishQ(i - 1);
        system("clear");
        Tag::printAll();
        cout << "How many tags do you want to add?" << endl;
        cin >> j;
        for (int z = 0; z < j; z++)
        {
            cout << "write index tag :" << endl;
            cin >> h;
            QuestionS[i - 1]->addTag(MyTags[h]);
        }
        system("clear");
        Qu_Menu();
        break;
    case 'p':
        system("clear");
        p_FourChoice();
        cout << "Enter the question number : " << endl;
        cin >> j;
        system("clear");
        QuestionS[j]->print();
        Exit();
        break;
    case '0':
        system("clear");
        _loginMenu();
        break;
    default:
        system("clear");
        cout << "not found " << x << "❌" << endl;
        _loginMenu();
        break;
    }
}
void User_Menu()
{
    system("clear");
    cout << "⚪️(L) List of Users with ID" << endl;
    cout << "⚪️(C) Create new User" << endl;
    cout << "⚪️(A) Add Permission to a User" << endl;
    cout << "📍(0) exit " << endl;
    string name, username, password;
    char x;
    int o, u;
    cin >> x;
    switch (x)
    {
    case 'L':
    case 'l':
        p_users();
        Exit();
        break;
    case 'C':
    case 'c':
        cin.ignore();
        cout << "enter name" << endl;
        getline(cin, name);
        cout << "enter username" << endl;
        getline(cin, username);
        cout << "enter password" << endl;
        getline(cin, password);
        User::create(name, username, password, Auth::Whoami());
        system("clear");
        User_Menu();
        break;
    case 'A':
    case 'a':
        system("clear");
        for (int i = 0; userarray[i] != nullptr; i++)
        {
            cout << i << ":";
            userarray[i]->printUser();
        }
        cout << "enter inedx user : " << endl;
        cin >> o;
        system("clear");
        for (int i = 0; perar[i] != nullptr; i++)
        {
            cout << i << ":" << perar[i]->titleback() << endl;
        }
        cout << "enter inedx permisson : " << endl;
        cin >> u;
        userarray[o]->addPermission(perar[o]);
        system("clear");
        User_Menu();
        break;
    case '0':
        system("clear");
        _loginMenu();
        break;
    default:
        system("clear");
        cout << "not found " << x << "❌" << endl;
        _loginMenu();
        break;
    }
}

void _loginMenu()
{
    cout << "-------------------------" << endl;
    cout << "⚪️(Q) Question Menu " << endl;
    cout << "⚪️(T) Tag Menu" << endl;
    cout << "⚪️(U) User Menu" << endl;
    cout << "⚪️(L) Log out" << endl;
    cout << "-------------------------" << endl;
    CinQTU();
}

void Exit()
{

    char x;
    cout << endl
         << "📍(0) Exit " << endl;
    cin >> x;
    if (x == '0')
    {
        system("clear");
        _loginMenu();
    }
    else
    {
        system("clear");
        cout << "not found " << x << " ❌" << endl;
        _loginMenu();
    }
}

void p_Qustions()
{
    system("clear");
    p_Descriptive();
    p_FourChoice();
}

void PublishQ(int f)
{

    char ch;
    cout << "Will it be published? (Y,N)" << endl;
    cin >> ch;
    switch (ch)
    {
    case 'y':
    case 'Y':
        QuestionS[f]->publish();
        break;
    case 'N':
    case 'n':
        QuestionS[f]->unpublish();
        break;

    default:
        Qu_Menu();
        break;
    }
}
