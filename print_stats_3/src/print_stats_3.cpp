#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void PrintStats(vector<Person> persons) {
	cout << "Median age = " << ComputeMedianAge(persons.begin(), persons.end()) << endl;
	cout << "Median age for females = " << ComputeMedianAge(persons.begin(), partition(persons.begin(), persons.end(), [] (const Person& person) {return person.gender == Gender::FEMALE;} )) << endl;
	cout << "Median age for males = " << ComputeMedianAge(persons.begin(), partition(persons.begin(), persons.end(), [] (const Person& person) {return person.gender == Gender::MALE;} )) << endl;
	cout << "Median age for employed females = " << ComputeMedianAge(persons.begin(), partition(persons.begin(), persons.end(), [] (const Person& person) {return person.gender == Gender::FEMALE && person.is_employed;} )) << endl;
	cout << "Median age for unemployed females = " << ComputeMedianAge(persons.begin(), partition(persons.begin(), persons.end(), [] (const Person& person) {return person.gender == Gender::FEMALE && !person.is_employed;} )) << endl;
	cout << "Median age for employed males = " << ComputeMedianAge(persons.begin(), partition(persons.begin(), persons.end(), [] (const Person& person) {return person.gender == Gender::MALE && person.is_employed;} )) << endl;
	cout << "Median age for unemployed males = " << ComputeMedianAge(persons.begin(), partition(persons.begin(), persons.end(), [] (const Person& person) {return person.gender == Gender::MALE && !person.is_employed;} )) << endl;
}


int main() {
  vector<Person> persons = {
      {31, Gender::MALE, false},
      {40, Gender::FEMALE, true},
      {24, Gender::MALE, true},
      {20, Gender::FEMALE, true},
      {80, Gender::FEMALE, false},
      {78, Gender::MALE, false},
      {10, Gender::FEMALE, false},
      {55, Gender::MALE, true},
  };
  PrintStats(persons);
  return 0;
}
