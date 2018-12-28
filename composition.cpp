//Composition over inheritance applied to instantiate video-game characters
//Inspiration: https://medium.com/humans-create-software/composition-over-inheritance-cb6f88070205

#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

class AbstractIndividual {
protected:
	string name;
public:
	AbstractIndividual(string name)	{
		this->name = name;
	}
	virtual void poke() = 0;
};

void bark() {
	cout << " Whoof";
}

void beep() {
	cout << " Beep";
}

void poop() {
	cout << " Poop";
}

class AnimalDog : public AbstractIndividual
{
public:
	AnimalDog(string name) : AbstractIndividual(name)	{
		cout << "I am an Animal Dog and my name is " << this->name << endl;
	}
	void poke() {
		cout << this->name << " is poked and it replied:";

		bark();

		poop();

		cout << endl;
	}
};

class RobotDog : public AbstractIndividual
{
public:
	RobotDog(string name) : AbstractIndividual(name) {
		cout << "I am a Robot Dog and my name is " << this->name << endl;
	}
	void poke() {
		cout << this->name << " is poked and it replied:";

		bark();

		beep();

		cout << endl;
	}
};

int main()
{
	AnimalDog dog1("Rex");
	RobotDog dog2("One");
	cout << endl;

	dog1.poke();
	dog2.poke();
}
