#include <iostream>

using namespace std;

struct DateTime
{
    int year, month, day, hour, minute, second;
};

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

void printAll()
{
cout << "your tags are :"<<endl;
    for (size_t i = 0; i < 100; i++)
    {
        if (MyTags[i] != nullptr)
        {
            cout << "("<<i<<"). ";
           MyTags[i]->print();
        }
    }
}

class User
{
private:
    string name;
    string username;
    string password;
    // Permission *permissions[100] = {NULL};

public:
    void print();
    void printUser(); // to soal nabod vali lazem bod
    bool checkAuth(string, string);
    User(string, string, string);
};

User::User(string NAME, string USERNAME, string PASSWORD) : name(NAME), username(USERNAME), password(PASSWORD) {}

bool User::checkAuth(string usr, string pass)
{
    if (username == usr && password == pass)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void User::printUser() { cout << username << endl; }
void User::print()
{
    cout << "name: " << name << endl
         << "username: " << username << endl
         << "password: " << password << endl;
}

class Question
{
protected:
    string question;
    DateTime createdAt;
    bool isPublished;
    string type;
    User user;
    Tag *tags[100] = {NULL};

public:
    void publish();
    void unpublish();
    string Info_type() { return type; }   // niaz bod baraye print all
    string q_print() { return question; } // niaz bod baraye print all
    Question(string, string, User, DateTime);
    virtual void print() = 0;
    virtual void printAll() = 0;
};

Question::Question(string TYPE, string QUESTION, User USER, DateTime CREATED_AT) : type(TYPE), question(QUESTION), user(USER), createdAt(CREATED_AT)
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
    void printAll();
    void addAnswer(string);
    Descriptive(User, DateTime, string);
};

Descriptive::Descriptive(User usr, DateTime crAt, string Ques) : Question("Descriptive", Ques, usr, crAt) {}

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
}

void Descriptive::printAll()
{
    int i;
    while (QuestionS[i] != NULL)
    {
        if (QuestionS[i]->Info_type() == "Descriptive")
        {
            cout << "Q_number " << i << " : " << QuestionS[i]->q_print() << endl;
        }

        i++;
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
    char answer;

public:
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
    int i;
    while (QuestionS[i] != NULL)
    {
        if (QuestionS[i]->Info_type() == "FourChoice")
        {
            cout << "Q_number " << i << " : " << QuestionS[i]->q_print() << endl;
        }

        i++;
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
}

int main()
{
    return 0;
}