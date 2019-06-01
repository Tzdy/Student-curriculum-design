#include <stdio.h>
#include <string.h>
struct Student
{
    int Id;        // 学号
    double Grade;  // 成绩
    char Name[18]; //  姓名
} Stu = {0, 0, ""};

struct Student setMsg(){
    struct Student stu;
    printf("请输入姓名\n");
    scanf("%s",stu.Name);
    printf("请输入学号\n");
    scanf("%d",&stu.Id);
    printf("请输入成绩\n");
    scanf("%lf",&stu.Grade);
    return stu;    
}

struct StudentBox
{
    struct Student box[50];
    int number;
};

struct Student returnStu(struct StudentBox box, char name[]){
    int i = 0;   
    for(i = 0; i < box.number ; i++){
        if(strcmp(box.box[i].Name,name))
            return box.box[i];
    }
    struct Student stu;
    return stu;
}


int pushStudent(struct StudentBox *box, struct Student stu)
{
    if (box->number == 50)
        return 0;
    else
    {
        box->box[box->number] = stu;
        box->number++;
        return 1;
    }
}

int delStudent(struct StudentBox *box, struct Student stu)
{
    if (box->number == 0)
    {
        return 0;
    }
    else
    {
        int i, j;
        for (i = 0; i < box->number; i++)
        {
            if (box->box[i].Id == stu.Id)
            {
                for (j = i; j < box->number; j++)
                {
                    box->box[j] = box->box[j + 1];
                }
                box->number--;
                return 1;
            }
        }
        return 0;
    }
}

int display(struct StudentBox box)
{
    if (box.number == 0)
        return 0;
    int i;
    for (i = 0; i < box.number; i++)
    {
        printf("姓名：%s 学号：%d 成绩：%lf\n", box.box[i].Name, box.box[i].Id, box.box[i].Grade);
    }
    return 1;
}

int searchPersonName(struct StudentBox box, char name[])
{
    int i = 0;
    for (i = 0; i < box.number; i++)
    {
        if (!strcmp(box.box[i].Name, name))
        {
            printf("姓名：%s 学号：%d 成绩：%lf\n", box.box[i].Name, box.box[i].Id, box.box[i].Grade);
            return 1;
        }
    }
    return 0;
}

int searchPersonId(struct StudentBox box, int id)
{
    int i = 0;
    for (i = 0; i < box.number; i++)
    {
        if (box.box[i].Id == id)
        {
            printf("姓名：%s 学号：%d 成绩：%lf\n", box.box[i].Name, box.box[i].Id, box.box[i].Grade);
            return 1;
        }
    }
    return 0;
}

int searchPersonGrade(struct StudentBox box, double grade)
{
    int i = 0;
    for (i = 0; i < box.number; i++)
    {
        if (box.box[i].Grade == grade)
        {
            printf("姓名：%s 学号：%d 成绩：%lf\n", box.box[i].Name, box.box[i].Id, box.box[i].Grade);
            return 1;
        }
    }
    return 0;
}

int searchGradeRange(struct StudentBox box, double a, double b)
{
    int i = 0;
    int judge = 0;
    for (i = 0; i < box.number; i++)
    {
        if (box.box[i].Grade >= a && box.box[i].Grade <= b)
        {
            printf("姓名：%s 学号：%d 成绩：%lf\n", box.box[i].Name, box.box[i].Id, box.box[i].Grade);
            judge = 1;
        }
    }
    return judge;
}

double showRangeGrade(struct StudentBox box)
{
    double grade = 0;
    int i = 0;
    for (i = 0; i < box.number; i++)
    {
        grade += box.box[i].Grade;
    }
    return grade / box.number;
}

double showPassPerson(struct StudentBox box)
{
    int i = 0;
    int pass = 0;
    for (i = 0; i < box.number; i++)
    {
        if (box.box[i].Grade >= 60)
            pass++;
    }
    double person = box.number;
    return pass / person;
}

void showStudentData(struct StudentBox box)
{
    printf("人数：%d 平均分：%lf\n通过率：%lf", box.number, showRangeGrade(box), showPassPerson(box));
}

void sence()
{
    struct StudentBox box;
    while (1)
    {

        if (box.number == 0)
        {
            printf("1:添加学生信息\n");
            printf("2:退出\n");
            int operate;
            scanf("%d", &operate);
            if (operate == 1)
            {
                if(pushStudent(&box, setMsg()))
                    printf("添加成功！\n");
                else
                    printf("添加失败！\n");
            }
            else
                break;
        }
        else
        {
            int id;
            double a,b,grade;
            char name[18];
            printf("1:添加学生信息\n");
            printf("2:退出\n");
            printf("3:根据学号搜索\n");
            printf("4:根据姓名搜索\n");
            printf("5:根据成绩搜索\n");
            printf("6:根据分数段搜索\n");
            printf("7:学生综合信息\n");
            printf("8:展示所有学生\n");
            printf("9:退出\n");
            int operate;
            scanf("%d", &operate);
            switch (operate)
            {
            case 1:
                if(pushStudent(&box, setMsg()))
                    printf("添加成功！\n");
                else
                    printf("添加失败！\n");
                break;
            case 2:
                printf("请输入学生姓名\n");
                scanf("%s",name);
                if(delStudent(&box, returnStu(box, name)))
                    printf("删除成功！\n");
                else
                    printf("删除失败！\n");
                break;
            case 3:
                printf("请输入学号\n");
                scanf("%d",&id);
                searchPersonId(box, id);
                break;
            case 4:
                printf("请输入学生姓名\n");
                scanf("%s",name);
                searchPersonName(box, name);
                break;    
            case 5:
                printf("请输入学生成绩\n");
                scanf("%lf",&grade);
                searchPersonGrade(box, grade);
                break;
            case 6:
                printf("请输入最低分\n");
                scanf("%lf",&a);
                printf("请输入最高分\n");
                scanf("%lf",&b);
                searchGradeRange(box, a, b);
                break;
            case 7:
                showStudentData(box);
                break;
            case 8:
                display(box);
                break;         
            default:
                break;
            }
            if(operate == 9)
            break;
        }
    
    }
    system("cls");
}

int main()
{
    sence();
    return 0;
}
