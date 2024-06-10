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
};

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

User::User(string NAME, string USERNAME, string PASSWORD) : name(NAME), username(USERNAME), password(PASSWORD) {}

void User::printUser() { cout << username << endl; } // to matn soal nis ama niyaze

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
    string Info_type(){return type;} // niaz bod baraye print all
    Question(string, string, User, DateTime);
    virtual void print() = 0;
    virtual void printAll() = 0;
};




Question *QuestionS[100]={NULL};

Question::Question(string type, string question, User user, DateTime createdAt)
{
    isPublished=false;
    this->type = type;
    this->question = question;
    this->createdAt = createdAt;
    this->user = user;
}

void Question::unpublish() { isPublished = false; }
void Question::publish() { isPublished = true; }










class Descriptive : public Question
{
private:
    string answer;

public:
    void print();
     void printALL();
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