//Observer Design Pattern applied for Twitter-like app

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Publisher {
	vector < class AObserver * > subscribers; 
public:
	string name;
	Publisher(string name) {
		this->name = name;
		cout << "I am a Publisher and my name is " << name << '\n';
	}
	void attach(AObserver *sub) {
		subscribers.push_back(sub);
	}
	void says(string speech);
};

class AObserver {
public:
	string name;
	AObserver(string name) {
		this->name = name;
		cout << "I am a Subscriber and my name is " << name << '\n';
	}
	void follow(Publisher *pub) {
		pub->attach(this);
		cout << name << " is following " << pub->name << '\n';
	}
	virtual void hears(string speech) = 0;
};

void Publisher::says(string speech) {
	cout << name << " says: " << speech << '\n';
	for (int i = 0; i < subscribers.size(); i++)
		subscribers[i]->hears(speech);
}

class Subscriber : public AObserver {
public:
	Subscriber(string name) : AObserver(name) {}
	void hears(string speech) {
		cout << name << " hears: " << speech << '\n';
	}
};

int main() {
	Publisher speaker("Lecturer");
	Subscriber sub1("He"), sub2("She");
	cout << '\n';

	sub1.follow(&speaker);
	cout << '\n';

	speaker.says("Hi");
	cout << '\n';

	sub2.follow(&speaker);
	cout << '\n';

	speaker.says("Hey");
}
