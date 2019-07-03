//start:2019-07-02
//fin:2019-07-03 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
struct Student {
	int id;   
	//学号8位 
	char name[16];
	//姓名
	int age;
	//年龄1~130 
	char gender[8];
	//性别 
	char tel[12];
	//手机号 
	struct Student *next;
	struct Student *before;
};

enum Gender{
	male = 1,famale 
};

struct Student* init() {
	struct Student *head;
	head = (struct Student*)malloc(sizeof(struct Student));
	head->next = NULL;
	head->before = NULL;
	return head;
}

int displayit(struct Student *node) {
	printf("学号\t 姓名\t  年龄 性别 电话\t\t \n");
	printf("%-8d %-8s %-4d %-4s %-11s\n",node->id,node->name,node->age,node->gender,node->tel);
}
int searchId(struct Student *head, int id) {// 0空   1没找到
	struct Student *node;
	node = head->next;
	if(head->next == NULL)
		return 0;
	else {
		int i = 0;
		while(1) {
			if(node == NULL)
				return 1;
			if(node->id == id) {
				displayit(node);
				return 2;
			}
			node = node->next;
		}
	}
}

int searchName(struct Student *head, char name[]) {  // 0空   1没找到
	struct Student *node;
	node = head->next;
	if(head->next == NULL)
		return 0;
	else {
		int i = 0;
		while(1) {        //先执行后判断判断node  
			if(node == NULL)
				return 1;
			if(strcmp(node->name,name) == 0) {
				displayit(node);
				return 2;
			}
			node = node->next;
		}
	}
}

int newList(struct Student *head ,int id, char name[], int age, char gender[],  char tel[]) {
	struct Student *node,*end;
	node = head;
	while(1) {
		if(node->next == NULL)
			break;
		node = node->next;
	}
	end = (struct Student*)malloc(sizeof(struct Student));
	end->id = id;
	strcpy(end->name,name);
	end->age = age;
	strcpy(end->tel,tel);
	strcpy(end->gender,gender);

	node->next = end;
	end->before = node;
	end->next = NULL;
	return 1;
}

int displayList(struct Student *head) {
	if(head->next == NULL) {
		return 0;
	} else {
		struct Student *node;
		node = head->next;
		printf("学号\t 姓名\t  年龄 性别 电话\t\t \n");
		while(1) {
			printf("%-8d %-8s %-4d %-4s %-11s\n",node->id,node->name,node->age,node->gender,node->tel);
			node = node->next;
			if(node == NULL)
				break;
		}
	}
	return 1;
}

int destory(struct Student *head) {
	struct Student *node,*end;
	if(head->next == NULL)
		return 0;
	node = head;
	while(1) {
		end = node->next;
		free(node);
		node = end;
		if(node == NULL)
			break;
	}
}

int delId(struct Student *head, int id) {
	struct Student *node,*end;
	node = head;
	end = head->next;
	if(end == NULL) {
		return 0;
	} else {
		while(1231412412412412) {
			if(end->id == id) {
				node->next = end->next;
				free(end);
				end = node;
				return 2;
			}
			node = end;
			end = end->next;
			if(end == NULL)
				break;
		}
		return 1;
	}
}

int delName(struct Student *head, char name[]) {
	struct Student *node,*end;
	node = head;
	end = head->next;
	if(end == NULL) {
		return 0;
	} else {
		while(1231412412412412) {
			if(strcmp(end->name, name) == 0) {
				node->next = end->next;
				free(end);
				end = node;
				return 2;
			}
			node = end;
			end = end->next;
			if(end == NULL)
				break;
		}
		return 1;
	}
}

int count(struct Student *head) {
	int count = 0;
	while(1) {
		if(head->next == NULL)
			break;
		count ++;
		head = head->next;
	}
	return count;
}

int readFile(struct Student *head) {
	struct Student *node;
	FILE *file;
	file = fopen("www.out","rb+");
	if(!file)
		return 0;
	while(1) {
		node = (struct Student*)malloc(sizeof(struct Student));
		fread(node,sizeof(struct Student),1,file);
		if(feof(file)) break;
		newList(head,node->id, node->name, node->age, node->gender, node->tel);
		free(node);
	}
	fclose(file);
	return 1;
}

int writeFile(struct Student *head) {
	struct Student *node;
	int i = 0 ;
	node = head->next;
	FILE *file;
	file = fopen("www.out","wb");
	for(i = 0 ; i < count(head); i ++) {
		fwrite(node,sizeof(struct Student),1,file);
		node = node->next;
	}
	fclose(file);
}

int idJudge(int id) {   //1 验证成功   0 验证失败
	int sit = 0;
	if(id <= 0) {
		printf("输入有误！\n");
		return 0;
	}
	while(id > 0) {
		id /= 10;
		sit ++;
	}
	if(sit != 8) {
		printf("请检查学号位数\n");
		return 0;
	}
	return 1;
}

int ageJudge(int age) {
	if(age > 0 && age < 130)
		return 1;
	printf("年龄输入有误！\n");
	return 0;
}

int msgMenu(struct Student *head ,int id, char name[], int age, char gender[],  char tel[]) { //0 继续   1 退出
	char chance;
	printf("(1):提交,(2)重写,(3)退出:");
	chance = getch();
	printf("\n");
	system("cls");
	switch(chance) {
		case '1':
			if(idJudge(id)) {
				if(ageJudge(age)) {
					newList(head, id, name, age, gender, tel);
					return 1;
				}
			}
			return 0;
			break;
		case '2':
			return 0;
			break;
		case '3':
			return 1;
			break;
	}

}

void addMessageSence(struct Student *head) {
	while(1314) {
		enum Gender genderJudge;
		int id;
		char name[16];
		int age;
		char gender[8];
		char tel[12];
		printf("请输入学号\n");
		scanf("%d",&id);
		fflush(stdin);
		printf("请输入姓名\n");
		scanf("%s",name);
		printf("请输入年龄\n");
		scanf("%d",&age);
		fflush(stdin);
		printf("请选择性别(1:男，2:女)\n");
		scanf("%d",&genderJudge);
		switch(genderJudge){
			case male:
				strcpy(gender, "男");
				break;
			case famale:
				strcpy(gender, "女");
				break;	
		}
		printf("请输入电话\n");
		scanf("%s",tel);
		if(msgMenu(head, id, name, age, gender, tel)) {
			writeFile(head);
			break;
		}
	}
}

void searchSence(struct Student *head) {
	printf("1:按学号查询\n");
	printf("2:按姓名查询\n");
	printf("3:返回\n");
	int question;
	char judge;
	int id;
	char name[16];
	judge = getch();
	fflush(stdin);
	system("cls");
	switch(judge) {
		case '1':
			displayList(head);
			printf("请输入学号\n");
			scanf("%d",&id);
			question = searchId(head, id);
			if(question == 0)
				printf("空\n");
			else if(question == 1)
				printf("不存在！\n");
			break;
		case '2':
			displayList(head);
			printf("请输入姓名\n");
			scanf("%s",name);
			question = searchName(head,name);
			if(question == 0)
				printf("空\n");
			else if(question == 1)
				printf("不存在！\n");
			break;
		case '3' :{
			break;
		}	
	}
}

void delSence(struct Student *head) {
	int question;
	char judge;
	int id;
	char name[16];
	printf("1:按学号删除\n");
	printf("2:按姓名删除\n");
	printf("3:后退\n");
	judge = getch();
	fflush(stdin);
	system("cls");
	switch(judge) {
		case '1':
			displayList(head);
			printf("请输入学号\n");
			scanf("%d",&id);
			system("cls");
			question = delId(head, id);
			if(question == 0)
				printf("空\n");
			else if(question == 1)
				printf("不存在！\n");
			else {
				printf("删除成功！\n");
			}
			break;
		case '2':
			displayList(head);
			printf("请输入姓名\n");
			scanf("%s",name);
			system("cls");
			question = delName(head,name);
			if(question == 0)
				printf("空\n");
			else if(question == 1)
				printf("不存在！\n");
			else {
				printf("删除成功！\n");
			}
			break;
		case '3':
			break;	
	}
}

int nodeSwap(struct Student *a, struct Student *b) { 
	//交换节点 
	struct Student *copy1,*copy2,*copy3,*copy4;
	copy1 = a->next;
	copy2 = a->before;
	copy3 = b->next;
	copy4 = b->before;
	if(copy1 != b) {
		a->next = copy3;
		a->before = copy4;
		b->next = copy1;
		b->before = copy2;
		if(a->next) {
			a->next->before = a ;
		}
		a->before->next = a;
		b->next->before = b;
		b->before->next = b;
	} else {
		a->next = copy3;
		a->before = b;
		b->next = a;
		b->before = copy2;
		copy2->next = b;
		if(copy3)
			copy3->before = a;
	}
}

int sortId(struct Student *head) {
	//排序 
	struct Student *node,
			*second;

	if(head->next == NULL || count(head) == 1)
		return 0;
	node = head->next;//   init
	second = node;
	while(666) {
		while(233) {

			if(node->id > second->id) {
				nodeSwap(node, second);
				struct Student *copy;
				copy = node;
				node = second;
				second = copy;
			}
			if(second->next == NULL)
				break;
			second = second->next;
		}

		node = node->next;
		second = node;
		if(node->next == NULL)
			break;
	}
	return 1;
}

void sence(struct Student *head) {
	while(1) {
		printf("------------------------------------------------\n");
		printf("1:添加学生信息\n");
		printf("2:查询学生信息\n");
		printf("3:删除学生信息\n");
		printf("4:总览\n");
		printf("5:根据学号排序\n");
		printf("6:退出\n");
		printf("------------------------------------------------\n");
		char judge;
		judge = getch();
		fflush(stdin);
		system("cls");
		switch(judge) {   //6445
			case '1':
				addMessageSence(head);
				break;
			case '2':
				searchSence(head);
				break;
			case '3':
				delSence(head);
				break;
			case '4':
				if(!displayList(head))
					printf("请添加信息！\n");
				break;
			case '5':
				if(sortId(head)){
					printf("排序成功\n");
					writeFile(head);
				}	
				else
					printf("排序失败\n");
				break;
			case '6':
				break;
			default :
				printf("excause me？\n");
		}
		if(judge == '6') {
			break;
		}
	}
}

int main(int argc, char *argv[]) {
	struct Student *head = init();
	//如果把head传进去，在函数中分配内存必须把head返回来，如果是c++的引用可能不需要，没试过。
	readFile(head);
	sence(head);
	writeFile(head);
	//写入文件 
	destory(head);
	//释放
}
