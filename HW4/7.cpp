//Answers 14.7 Programming Project Question

#include <iostream>
#include <iostream>
using namespace std;

class Document{
private:
  string text;

public:
  Document(){
    text = " ";
  }

  Document(string newText){
    text = newText;
  }

  string getText() const{
    return text;
  }

  void setText(string newText){
    text = newText;
  }
  Document& operator =(const Document& RHS);
};

Document& Document::operator =(const Document& RHS){
    text = RHS.text;
    return *this;
  }

class Email : public Document{
public:
  Email(){
    sender = "None";
    title = "None";
    recipient = "None";
  }
  Email(string s, string t, string r, string body);

  string getSender(){
    return sender;
  }
  string getTitle(){
    return title;
  }
  string getRecipient(){
    return recipient;
  }

  void setSender(string newSender){
    sender = newSender;
  }
  void setTitle(string newTitle){
    newTitle = newTitle;
  }
  void setRecipient(string newRecipient){
    recipient = newRecipient;
  }

  Email& operator =(const Email& RHS);
private:
  string sender;
  string title;
  string recipient;
};

Email& Email::operator =(const Email& RHS){
  Document::operator =(RHS);
  sender = RHS.sender;
  title = RHS.title;
  recipient = RHS.recipient;
  return *this;
}

Email::Email(string s, string t, string r, string body) : Document(body) //call to the Document constructor: Document(string newText)
{
  sender = s;
  title = t;
  recipient = r;
}

class File : public Document{
private:
  string pathName;
public:
  File(){
    pathName = "None";
  }

  File(string path, string body) : Document(body){
    pathName = path;
  }

  string getPath(){
    return pathName;
  }

  void setPathName(string newPathName){
    pathName = newPathName;
  }

  File& operator =(const File& RHS){
    Document::operator =(RHS);
    pathName = RHS.pathName;
    return *this;
  }
};

bool ContainsKeyword(const Document& docObject, string keyword){
  if(docObject.getText().find(keyword) != string::npos){
    return true;
  }
  return false;
}

int main(){
  Email email1("George@gmail.com", "parneetk@gmail.com", "Hello", "Body of the email");
  Email email2("George@gmail.com", "parneetk@gmail.com", "Program Project", "Let's Learn how to use Inheritance");
  File file1("//path//to//File", "Parneet Kaur's Information");
  File file2("//path//to//AnotherFile", "To-do List");
  if(ContainsKeyword(email1, "C++")){
    cout << "Email 1 contains Body" << endl;
  }
  else if(ContainsKeyword(email2, "C++")){
    cout << "Email 2 contains Inheritance" << endl;
  }
  else if(ContainsKeyword(file1, "C++")){
    cout << "File 1 contains C++" << endl;
  }
  else if(ContainsKeyword(file2, "C++")){
    cout << "File 2 contains C++" << endl;
  }
  else{
    cout << "None of these contain C++" << endl; 
  }
  return 0;
}
