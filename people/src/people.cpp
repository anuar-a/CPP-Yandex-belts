#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Human {
public:
	Human (const string& name, const string& type):Name(name), type_(type){}

	virtual void Walk(const string& destination) const {
		cout << type_ << ": " << Name << " walks to: " << destination << endl;
	}

	string TypeInfo() const {
		return type_ + ": " + Name;
	}

	const string Name;
	const string type_;
};

class Student:public Human {
public:

    Student(const string& name, const string& favouriteSong):Human(name, "Student"), FavouriteSong(favouriteSong) {
    }

    void Learn() const {
        cout << TypeInfo() << " learns" << endl;
    }

    void Walk(const string& destination) const override{
		cout << TypeInfo() << " walks to: " << destination << endl;
    	SingSong();
    }

    void SingSong() const {
        cout << TypeInfo() << " sings a song: " << FavouriteSong << endl;
    }

private:
    const string FavouriteSong;
};

class Teacher:public Human {
public:

    Teacher(const string& name, const string& subject):Human(name, "Teacher"), Subject(subject) {
    }

    void Teach() const {
        cout << TypeInfo() << " teaches: " << Subject << endl;
    }

private:
    const string Subject;
};

class Policeman:public Human {
public:
    Policeman(const string& name):Human(name, "Policeman") {
    }

    void Check(Human& person) const{
        cout << TypeInfo() << " checks " << person.type_ << ". " << person.type_ << "'s name is: " << person.Name << endl;
    }

};

void VisitPlaces(const Human& person, const vector<string>& places) {
    for (auto p : places) {
        person.Walk(p);
    }
}

int main() {
    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    Policeman p("Bob");

    VisitPlaces(t, {"Moscow", "London"});
    p.Check(s);
    VisitPlaces(s, {"Moscow", "London"});
    return 0;
}
