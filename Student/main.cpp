#include<iostream>
#include<string>
using namespace std;

class Student{
    string name;  //  姓名
    int id;  // 学号
    double grade;  // 成绩
        public:
            Student();
            Student(string a, int b, double c):name(a),id(b),grade(c){}
            void setGrade(double a){
                grade = a;
            }
            bool name(string a){
                if(a == name)
                    return true;
                else
                    return false;    
            }
            bool id(int a){
                if(a == id)
                    return true;
                else
                    return false;
            }
            bool grade(double a){
                if(a == grade)
                    return true;
                else
                    return false;
            }
            void display();
            bool operator==(Student stu);
};
void Student::display(){
    cout << "姓名：" << name 
         << "学号：" << id 
         << "成绩：" << grade << endl;
}
bool Student::operator==(Student stu){
    if(id == stu.id)
        return true;
    else
        return false;
}


class StudentBox{
    Student student[50];
    int number = 0;
        public:
            bool pushStudent(Student stu);
            bool delStudent(Student stu);
            void display();  //展示所有学生成绩
            bool searchPersonName(string name);  //按姓名展示
            bool searchPersonId(int id);  //按学号展示
            bool searchPersonGrade(double grade);  //按成绩展示            
            bool searchGradeRange(double a, double b);  //按成绩范围展示
            void showRangeGrade();  //展示平均分
            void showStudentData();  //展示数据
            void sence();
};
bool StudentBox::pushStudent(Student stu){
    if(number == 50)
        return false;
    else{
        student[number] = stu;
        number ++;
        return true;
    }
}
bool StudentBox::delStudent(Student stu){
    if(number == 0){
        return false;
    }
    else{
        for(int i = 0; i < number ; i ++){
            if(student[i] == stu){
                for(int j = i ; j < number ; j ++){
                    student[j] = student[j + 1];
                }
                number --;
                return true;
            }
        }
        return false;
    }
    
}
void StudentBox::display(){
    for(int i = 0 ; i < number ; i ++){
        student[i].display();
    }
}
bool StudentBox::searchPersonName(string name){
    for(int i = 0 ; i < number ; i ++){
        if(student[i].name(name)){
            student[i].display();
            return true;
        }
    }
    return false;
}



int main(){

    return 0;
}