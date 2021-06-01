#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef void Func(int);
typedef Func* NextCallback;

// For simplicity, it will only have the `next` method
class Subscriber {
  function<Func> nextCb;
  
  public:
    Subscriber(function<Func> cb): nextCb(cb) {}

    void next (int value) {
      nextCb(value);
  }
};

class Subject {
  private:
    vector<Subscriber> subscribers;
  public:
    void subscribe(const Subscriber& s) {
      subscribers.push_back(s);
    }

    virtual void next (int v) {
      for_each(subscribers.begin(), subscribers.end(), [&v](Subscriber& s) {
        s.next(v);
      });
    }
};