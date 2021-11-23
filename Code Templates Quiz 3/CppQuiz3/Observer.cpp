/**
 * Observer Design Pattern
 *
 * Intent: Lets you define a subscription mechanism to notify multiple objects
 * about any events that happen to the object they're observing.
 *
 * Note that there's a lot of different terms with similar meaning associated
 * with this pattern. Just remember that the Subject is also called the
 * Publisher and the Observer is often called the Subscriber and vice versa.
 * Also the verbs "observe", "listen" or "track" usually mean the same thing.
 */

#include <iostream>
#include <list>
#include <string>
using namespace std;

class IObserver {
 public:
  virtual void Update(const string &message_from_subject) = 0;
};

class ISubject {
 public:
  virtual void Register(IObserver *observer) = 0;
  virtual void Remove(IObserver *observer) = 0;
  virtual void Notify() = 0;
};

/**
 * The Subject owns some important state and notifies observers when the state
 * changes.
 */
class Subject : public ISubject {
 private:
  list<IObserver *> list_observer_;
  string message_;
 public:
  
  // add new observer
  void Register(IObserver *observer) override {
    list_observer_.push_back(observer);
  }

  // remove an observer
  void Remove(IObserver *observer) override {
    list_observer_.remove(observer);
  }

  // notify all observers of the new message
  void Notify() override {
    list<IObserver *>::iterator iterator = list_observer_.begin();
    HowManyObserver();
    while (iterator != list_observer_.end()) {
      (*iterator)->Update(message_);
      ++iterator;
    }
  }

  // add new message to subject
  void CreateMessage(string message = "Empty") {
    this->message_ = message;
    Notify();
  }

  // get count of observers
  void HowManyObserver() {
    cout << "There are " << list_observer_.size() << " observers in the list.\n";
  }
};

class Observer : public IObserver {
 private:
  string message_from_subject_;
  Subject &subject_;
  static int static_number_;
  int number_;

 public:
  Observer(Subject &subject) : subject_(subject) {
    this->subject_.Register(this);
    cout << "Hi, I'm the Observer \"" << ++Observer::static_number_ << "\".\n";
    this->number_ = Observer::static_number_;
  }

  void Update(const string &message_from_subject) override {
    message_from_subject_ = message_from_subject;
    PrintInfo();
  }
  void RemoveMeFromTheList() {
    subject_.Remove(this);
    cout << "Observer \"" << number_ << "\" removed from the list.\n";
  }
  void PrintInfo() {
    cout << "Observer \"" << this->number_ << "\": a new message is available --> " << this->message_from_subject_ << "\n";
  }
};

int Observer::static_number_ = 0;

void ClientCode() {
  Subject *subject = new Subject;
  Observer *observer1 = new Observer(*subject);
  Observer *observer2 = new Observer(*subject);
  Observer *observer3 = new Observer(*subject);
  
  // original message
  subject->CreateMessage("Hello World! :D");
  cout << "\n\n";

  observer3->RemoveMeFromTheList();
  subject->CreateMessage("The weather is hot today! :p");
  cout << "\n\n";

  Observer *observer4;
  observer4 = new Observer(*subject);
  observer2->RemoveMeFromTheList();
  Observer *observer5;
  observer5 = new Observer(*subject);
  subject->CreateMessage("My new car is great! ;)");
  cout << "\n\n";

  observer5->RemoveMeFromTheList();
  observer4->RemoveMeFromTheList();
  observer1->RemoveMeFromTheList();

  delete observer5;
  delete observer4;
  delete observer3;
  delete observer2;
  delete observer1;
  delete subject;
}

int main() {
  ClientCode();
  return 0;
}