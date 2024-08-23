/*
Create a class person with name and date of birth as data members. Ask the user to
enter a date of birth and print all persons name with a matched date of birth.
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Person {
public:
    string name;
    int day, month, year;

    Person(string n, int d, int m, int y) : name(n), day(d), month(m), year(y) {}
};

int main() {
    int n;
    cout << "Enter the number of persons: ";
    cin >> n;

    vector<Person> persons;

    for (int i = 0; i < n; i++) {
        string name;
        int day, month, year;
        cout << "Enter name of person " << i + 1 << ": ";
        cin >> name;
        cout << "Enter date of birth (day month year): ";
        cin >> day >> month >> year;
        persons.push_back(Person(name, day, month, year)); 
    }

    int d, m, y;
    cout << "Enter a date of birth to match (day month year): ";
    cin >> d >> m >> y;

    bool found = false;
    cout << "Persons with matched date of birth: ";
    for (int i = 0; i < n; i++) {
        if (persons[i].day == d && persons[i].month == m && persons[i].year == y) {
            cout << persons[i].name << " ";
            found = true;
        }
    }

    if (!found) {
        cout << "No matching date of birth..." << endl;
    } else {
        cout << endl;
    }

    return 0;
}
