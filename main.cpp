//Quinton Dean
//Lab 6- Multimap

/* This lab uses the map libary in C++ and uses Multimap
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <map>
using namespace std;

struct structure
{
    string ID;
    string last;
    string first;
};
int main()
{
    typedef multimap<string, string> Map1;
    typedef Map1::iterator it;
    std::pair<it, it> range1;
    Map1 course;
    it it1, it2;
    structure class1;
    int i=0;
    string junk, courseID, section;
    fstream students;
    students.open("students.txt");
    if(!students.is_open())
    {
        cout << "'Students.txt' cannot open";
        return 10;
    }

    getline(students, junk);
    students >> class1.ID >> class1.last >> class1.first >> courseID >> section;
    while(!students.eof())                                              // Populating the multimap
    {

        course.insert(make_pair(courseID, class1.ID));
        course.insert(make_pair(courseID, class1.last));
        course.insert(make_pair(courseID, class1.first));
        students >> class1.ID >> class1.last >> class1.first >> courseID >> section;

    }
    for(it1=course.begin(); it1!=course.end(); it1++)
    {                                                                   // "Walking" through multimap
        range1=course.equal_range((*it1).first);                        // Set range for courseID
        cout << "ROSTER FOR " << (*it1).first << '\n';                  // Output Section
        cout << '\n' << "ID" << setw(15) << "Last" << setw(10) << "First" << '\n';
        for(it2=range1.first; it2!=range1.second; ++it2)
        {                                                               // Walking through data of multimap


            if(i==1)                                                    // For Outputting purposes
            {
                cout << " ";
                cout << setw(15);
            }
            if(i==2)
            {
                cout << " ";
                cout << setw(10);
            }
            if(i==3)
            {
                i=0;
                cout << '\n';
            }
            cout << (*it2).second;
            i++;

        }
        cout << '\n';
        it1=--it2;
        cout << "Number of Students " << course.count((*it1).first)/3 << '\n' << '\n';
                                                                         // Output number of students. Divide count of courseID by number of data to give Students.
    }

}
