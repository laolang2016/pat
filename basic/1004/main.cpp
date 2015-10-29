#include<iostream>
#include<string>
#include<vector>

using namespace std;

typedef struct{
    string name;
    string stu_id;
    int grade;
}stu;

int person_num = 0;
int i;
int main()
{
    stu max, min;
    max.grade = -1;
    min.grade = 0x7fffffff;
    
    cin >> person_num;
    for( i = 0; i < person_num; ++i )
    {
        stu temp;
        cin >> temp.name;
        cin >> temp.stu_id;
        cin >> temp.grade;
        if( max.grade < temp.grade )
        {
            max.grade = temp.grade;
            max.name = temp.name;
            max.stu_id = temp.stu_id;    
        }
        if( min.grade > temp.grade )
        {
            min.grade = temp.grade;
            min.name = temp.name;
            min.stu_id = temp.stu_id;
        }
    }
    cout << max.name << " " << max.stu_id << endl;
    cout << min.name << " " << min.stu_id << endl;
    
    return 0;
}
