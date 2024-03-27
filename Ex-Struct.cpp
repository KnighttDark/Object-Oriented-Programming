#include <iostream>
#include <string>
using namespace std;

struct Student
{
    string name;
    float *marks;
    float average;
    int quantity;
};

void input(Student &student)
{
    cout << "Enter name:" << endl;
    getline(cin, student.name);

    cout << "Enter quantity:" << endl;
    cin >> student.quantity;

    student.marks = new float[student.quantity];

    for (int i = 0; i < student.quantity; i++)
    {
        cout << "Enter marks " << i + 1 << ": ";
        cin >> student.marks[i];
    }
}

float calculator(Student &student)
{
    float sum = 0;
    for (int i = 0; i < student.quantity; i++)
    {
        sum += student.marks[i];
    }

    student.average = sum / student.quantity;
    return student.average;
}

void display(Student &student)
{
    cout << " Your name:" << student.name << endl;
    cout << " Your quantity:" << student.quantity << endl;
    cout << "Your average:" << calculator(student);
}

int main()
{

    Student s1;
    input(s1);
    calculator(s1);
    display(s1);
    return 0;
}