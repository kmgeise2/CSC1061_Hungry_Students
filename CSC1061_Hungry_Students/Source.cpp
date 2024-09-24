/*
File: Sandwiches
Author: Ram Longman
Revised: 9/22/23
Description: 1.	Write a function that takes in a queue of students
    and a stack of sandwiches and returns the number of students unable to eat lunch.
    Write a main/test function to initialize queues and stacks to test the function with.
    Implemented using the template library
*/

#include <iostream>
#include <stack>
#include <queue>
#include <cassert>

using namespace std;

int HungryStudents(stack<int> sandwiches, queue<int> students);
void Test();

int main()
{
    Test();
}

int HungryStudents(stack<int> sandwiches, queue<int> students)
{
    int count = 0;
    while (!sandwiches.empty() && !students.empty()) {
        // The student at the front of the queue
        //   likes the sandwich at the top of the stack
        // Remove student from queue and sandwich from stack
        if (sandwiches.top() == students.front()) {
            sandwiches.pop();
            students.pop();
            count = 0;
        }
        // The only students left in the queue 
        //    are the unfed ones
        else if (count == students.size()) {
            cout << "Hungry students " << count << endl;
            return count;
        }
        else {
            // Push the student to the back of the queue
            // Increment the counter
            students.push(students.front());
            students.pop();
            ++count;
        }
    }
    cout << "Student queue " << students.size() << endl;
    return students.size();
}

void Test()
{
    stack<int> sand;
    queue<int> stud;

    //case 1
    cout << "Case 1" << endl;
    sand.push(0); // circular sandwich
    sand.push(0);
    sand.push(1); // square sandwich
    sand.push(1);
    stud.push(0); // student likes circular sandwich
    stud.push(1); // student prefers square sandwich
    stud.push(1);
    stud.push(0);
    assert(HungryStudents(sand, stud) == 0);
    // Empty the stack and queue for the next test
    while (!sand.empty()) sand.pop();
    while (!stud.empty()) stud.pop();

    //case 2
    cout << "Case 2 (Not enough circular sandwiches)" << endl;
    sand.push(0);
    sand.push(1);
    sand.push(0);
    sand.push(1);
    stud.push(0);
    stud.push(0);
    stud.push(1);
    stud.push(0);
    assert(HungryStudents(sand, stud) == 2);
    while (!sand.empty()) sand.pop();
    while (!stud.empty()) stud.pop();

    //case 3
    cout << "Case 3 (Not enough circular sandwiches)" << endl;
    sand.push(0);
    sand.push(0);
    sand.push(1);
    stud.push(0);
    stud.push(0);
    stud.push(0);
    assert(HungryStudents(sand, stud) == 3);
    while (!sand.empty()) sand.pop();
    while (!stud.empty()) stud.pop();

    //case 4
    cout << "Case 4 (3 sandwiches and 4 students)" << endl;
    sand.push(1);
    sand.push(0);
    sand.push(1);
    stud.push(0);
    stud.push(1);
    stud.push(1);
    stud.push(0);
    assert(HungryStudents(sand, stud) == 1);
    while (!sand.empty()) sand.pop();
    while (!stud.empty()) stud.pop();

    //case 5
    cout << "Case 5 (3 sandwiches and 2 students)" << endl;
    sand.push(1);
    sand.push(1);
    sand.push(0);
    stud.push(0);
    stud.push(1);
    assert(HungryStudents(sand, stud) == 0);
    while (!sand.empty()) sand.pop();
    while (!stud.empty()) stud.pop();

    cout << "Success!\n";
}

