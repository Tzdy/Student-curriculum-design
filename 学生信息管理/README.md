# C99编译没问题！
## 函数总览
#
### 初始化
* struct Student* init()
### 链表节点的操作
* int newList(struct Student *head ,int id, char name[], int age, char gender[],  char tel[])
* int delId(struct Student *head, int id)
* int delName(struct Student *head, char name[])
* int searchId(struct Student *head, int id)
* int searchName(struct Student *head, char name[])
* int count(struct Student *head)
* int displayit(struct Student *node)
* int displayList(struct Student *head)
* int destory(struct Student *head)
* int nodeSwap(struct Student *a, struct Student *b)
### 文件读写I/O
* int readFile(struct Student *head)
* int writeFile(struct Student *head)
### 输入验证
* int ageJudge(int age)
* int idJudge(int id)
### 场景
* void sence(struct Student *head)
* void addMessageSence(struct Student *head)
* int msgMenu(struct Student *head ,int id, char name[], int age, char gender[],  char tel[])
* void searchSence(struct Student *head)
* void delSence(struct Student *head)
### 排序
* int sortId(struct Student *head

## 功能分析
#
### 1.初始化
获取一个链表的头节点。
### 2.链表节点的操作
通过传入形参的数据对链表进行增删查，**此处不提供用户交互的功能**。
### 3.文件读写I/O
将链表上的数据以二进制的形式存入/读取文件
### 4.输入验证
验证用户输入的信息，提高程序健壮性。
### 5.场景（菜单）
通过输入验证，与链表节点的操作，文件写入，来完成用户交互的函数。
### 6.排序
通过插入排序的方式对所有节点进行学号从小到大的排序。**注:只有当数据大于等于2时排序才能成功**。
