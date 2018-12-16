
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "math.h"
#include "string.h"
struct student            /*学生信息*/
{
        char num[20];     /*学号*/
        char name[20];    /*姓名*/
        char sex;         /* 性别，'1'->男, '0'->女*/
        short age;        /*年龄*/
        short score[3];   /*三门课程的成绩*/
        short sum;        /*总成绩*/
        short deptid;     /*所在系的系号*/
        struct student *next;
};
struct department           /*系信息，假设总共有3个系*/
{
        short id;           /*系号*/
        char name[20];      /*系名*/
        char dean[20];      /*系主任*/
        char location[30];  /*系的办公地点*/
};
struct department dp[3]={{1,"艺术设计系","宋俊杰","办公楼104"},{2,"食工系","王英","办公楼105"},{3,"法政系","王凡","办公楼106"}};
int currentNumOfstu=0;
/*录入学生的信息*/
struct student *create()
{
        struct student *p, *q, *head=NULL;
        int k, currentNumOfstu=1,i;
        short sum;
        char tmp[20],str[3];
        printf("输入学生的个数：");
        gets(tmp);
        k=atoi(tmp);
        while(k)
        {
                p=(struct student*)malloc(sizeof(struct student));
                printf("\n=======请输入第%d个结点的信息=======\n", currentNumOfstu);
                printf("学号:");
                gets(p->num);
                printf("姓名:");
                gets(p->name);
                printf("性别,男(1),女(0):");
                p->sex=getchar();
                getchar();
                printf("年龄:");
                gets(str);
                p->age=atoi(str);
                sum=0;
                for(i=0;i<3;i++)
                {
                        printf("课程%d的成绩(整数):",i+1);
                        gets(str);
                        p->score[i]=atoi(str);
                        sum=sum+p->score[i];
                }
                p->sum=sum;
                printf("系号(1或2或3):");
                gets(str);
                p->deptid=atoi(str);
                if(currentNumOfstu==1)
                        head=p;
                else
                        q->next=p;
                q=p;
                p->next=NULL;
                k--;
                currentNumOfstu++;
        }
        printf("\n录入完毕,");
        return head;
}
/*显示所有学生信息*/
void display(struct student *p)
{
        if(p==NULL)
                printf("没有学生的信息\n");
        else
        {
                printf("\n=========================学生的信息内容如下=========================");
                printf("\n学号\t姓名\t性别\t年龄\t课程1\t课程2\t课程3\t总成绩\t系号\n");
                while(p!=NULL)
                {
                        printf("%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\n", p->num, p->name,p->sex=='1'?"男":"女",p->age,p->score[0],p->score[1],p->score[2],p->sum,p->deptid);
                        p=p->next;
                }
        }
        printf("\n显示完毕,");
}
/*按学号查询学生信息*/
struct student *displayOnnum(struct student *head)
{
        struct student *p, *q;
        char x[30];
        if(head==NULL)
        {
                printf("Not find node: %s\n", x);
                return head;
        }
        printf("你要查询的学生的学号:");
        gets(x);
        q=p=head;
        while(strcmp(p->num,x)&&p->next)
        {
                q=p;
                p=p->next;
        }
        if(strcmp(p->num,x)==0)
        {
                printf("\n=========================学生的信息内容如下=========================");
                printf("\n学号\t姓名\t性别\t年龄\t课程1\t课程2\t课程3\t总成绩\t系号\n");
                printf("%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\n", p->num, p->name,p->sex=='1'?"男":"女",p->age,p->score[0],p->score[1],p->score[2],p->sum,p->deptid);
        }
        else
        {
                printf("Not find node: %s\n", x);
                return head;
        }
        printf("\n显示完毕,");
        return head;
}
/*按姓名查询学生信息（支持模糊查询）*/
struct student *displayOnName(struct student *head)
{
        struct student *p, *q;
        char x[30];
        if(head==NULL)
        {
                printf("Not find node: %s\n", x);
                return head;
        }
        printf("你要查询的学生的姓名:");
        gets(x);
        q=p=head;
        while(strstr(p->name,x)==0&&p->next)
        {
                q=p;
                p=p->next;
        }
        if(strstr(p->name,x))
        {
                printf("\n=========================学生的信息内容如下=========================");
                printf("\n学号\t姓名\t性别\t年龄\t课程1\t课程2\t课程3\t总成绩\t系号\n");
                printf("%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\n", p->num, p->name,p->sex=='1'?"男":"女",p->age,p->score[0],p->score[1],p->score[2],p->sum,p->deptid);
        }
        else
        {
                printf("Not find node: %s\n", x);
                return head;
        }
        printf("\n显示完毕,");
        return head;
}
/*按年龄查询学生信息*/
struct student *displayOnAge(struct student *head)
{
        struct student *p, *q;
        char x[30];
        if(head==NULL)
        {
                printf("Not find node: %s\n", x);
                return head;
        }
        printf("你要查询的学生的年龄:");
        gets(x);
        q=p=head;
        while(p->age!=atoi(x) && p->next)
        {
                q=p;
                p=p->next;
        }
        if(p->age==atoi(x))
        {
                printf("\n=========================学生的信息内容如下=========================");
                printf("\n学号\t姓名\t性别\t年龄\t课程1\t课程2\t课程3\t总成绩\t系号\n");
                printf("%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\n", p->num, p->name,p->sex=='1'?"男":"女",p->age,p->score[0],p->score[1],p->score[2],p->sum,p->deptid);
        }
        else
        {
                printf("Not find node: %s\n", x);
                return head;
        }
        printf("\n显示完毕,");
        return head;
}
/*查询指定学生的所在系的信息(包括系名,系主任,系的办公地点)*/
struct student *displaydeptid(struct student *head)
{
        struct student *p, *q;
        short f=1,i;
        char str[20];
        printf("你要查询的学生的学号:");
        gets(str);
        if(head==NULL)
        {
                printf("Not find node: %s\n", str);
                return head;
        }
        q=p=head;
        while(strcmp(p->num,str)&&p->next)
        {
                q=p;
                p=p->next;
        }
        for(i=0;i<3;i++)
        {
                if(i==p->deptid)
                {
                        f=0;
                        printf("\n================该生所在系的信息================");
                        printf("\n系号\t系名\t系主任\t系的办公地点\n");
                        printf("%d\t%s\t%s\t%s\n",dp[i].id,dp[i].name,dp[i].dean,dp[i].location);
                }
        }
        if(f)
        {
                printf("Not find node: %s\n", str);
                return head;
        }
        printf("\n显示完毕,");
        return head;
}
/*修改学生的信息*/
struct student *updatestu(struct student *head)
{
        struct student *p, *q;
        char x[30],m[2];
        short sum,i;
        if(head==NULL)
        {
                printf("Not find node: %s\n", x);
                return head;
        }
        printf("输入你要修改的学生的学号:");
        gets(x);
        q=p=head;
        while(strcmp(p->num,x)&&p->next)
        {
                q=p;
                p=p->next;
        }
        if(strcmp(p->num,x)==0)
        {
                sum=0;
                printf("\n找到了要修改信息的学生!\n");
                printf("\n学号\t姓名\t性别\t年龄\t课程1\t课程2\t课程3\t总成绩\t系号\n");
                printf("%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\n", p->num, p->name,p->sex=='1'?"男":"女",p->age,p->score[0],p->score[1],p->score[2],p->sum,p->deptid);
                printf("学号:");
                gets(x);
                if(strcmp(x,"")!=0)
                        strcpy(p->num,x);
                printf("姓名:");
                gets(x);
                if(strcmp(x,"")!=0)
                        strcpy(p->name,x);
                printf("性别,男(1),女(0):");
                gets(m);
                if(strcmp(m,""))
                        p->sex=atoi(m);
                printf("年龄:");
                gets(m);
                p->age=atoi(m);
                for(i=0;i<3;i++)
                {
                        printf("课程%d的成绩:",i+1);
                        gets(x);
                        if(p->score[i]!=atoi(x))
                                p->score[i]=atoi(x);
                        sum+=p->score[i];
                }
                printf("系号(1或2或3):");
                gets(m);
                if(strcmp(m,""))
                        p->sex=atoi(m);
        }
        else
        {
                printf("Not find node: %s\n", x);
                return head;
        }
        printf("\n修改完毕,");
        return head;
}
/*删除学生的信息*/
struct student *deletestu(struct student *head)
{
        struct student *p, *q;
        char x[30];
        if(head==NULL)
        {
                printf("Not find node: %s\n", x);
                return head;
        }
        printf("你要删除的学生的学号:");
        gets(x);
        q=p=head;
        while(strcmp(p->num,x)&&p->next)
        {
                q=p;
                p=p->next;
        }
        if(strcmp(p->num,x)==0)
        {
                if(p==head)
                {
                        head=p->next;
                        free(p);
                        printf("\n删除完毕,");
                        return head;
                }
                else
                {
                        q->next=p->next;
                        free(p);
                        printf("\n删除完毕,");
                        return head;
                }
        }
        else
        {
                printf("Not find node: %s\n", x);
                return head;
        }
        printf("\n删除完毕,");
        return head;
}
/*追加员工的信息*/
struct student *appendstu(struct student *head)
{
        struct student *p;
        char str[3];
        FILE *fp;
        char fileName[50]="C:\\students.dat";
        short sum=0,i;
        p=(struct student*)malloc(sizeof(struct student));
        printf("学号:");
        gets(p->num);
        printf("姓名:");
        gets(p->name);
        printf("性别,男(1),女(0):");
        p->sex=getchar();
        getchar();
        printf("年龄:");
        gets(str);
        p->age=atoi(str);
        for(i=0;i<3;i++)
        {
                printf("课程%d的成绩(整数):",i+1);
                gets(str);
                p->score[i]=atoi(str);
                sum=sum+p->score[i];
        }
        p->sum=sum;
        printf("系号(1或2或3):");
        gets(str);
        p->deptid=atoi(str);
        p->next=NULL;
        printf("\n=============学生的信息输入完成===============\n");
        printf("请输入文件名，如%s: ", fileName);
        gets(fileName);
        if(strcmp(fileName, "")==0)
                strcpy(fileName, "C:\\students.dat");
        if((fp=fopen(fileName, "ab"))==NULL)
        {
                printf("File open error!");
                exit(1);
        }
        fwrite(p,sizeof(struct student),1,fp);
        fclose(fp);
        printf("\n追加完毕,");
        return head;
}
/*将内存数据写入文件*/
void saveNode(struct student *p)
{
        char fileName[50]="C:\\students.dat";
        FILE *fp;
        printf("请输入文件名,如%s: ", fileName);
        gets(fileName);
        if(strcmp(fileName, "")==0)
                strcpy(fileName, "C:\\students.dat");
        if((fp=fopen(fileName, "wb"))==NULL)
        {
                printf("File open error!\n");
                exit(1);
        }
        while(p!=NULL)
        {
                fwrite(p,sizeof(struct student),1,fp);
                p=p->next;
        }
        fclose(fp);
        printf("\n信息成功保存,");
        return;
}
/*读磁盘数据到内存*/
struct student *loadNode()
{
        struct student *p, *q, *head=NULL;/*定义记录指针变量*/
        FILE *fp;
        char fileName[50]="C:\\students.dat";   /*保存文件名，默认为C:\\students.dat*/
        printf("请输入文件名，如%s: ", fileName);
        gets(fileName);
        if(strcmp(fileName, "")==0)       /*如果没有输入文件名，默认为C:\\students.dat,否则,以新文件名存储*/
                strcpy(fileName, "C:\\students.dat");
        if((fp=fopen(fileName, "rb"))==NULL)
        {
                printf("File open error!\n");
                exit(1);
        }
        printf("\n正在载入文件，请稍后...\n");
        p=(struct student *)malloc(sizeof(struct student));   /*申请空间*/
        if(!p)
        {
                printf("out of memory!\n");    /*如没有申请到，则内存溢出*/
                return head;       /*返回空头指针*/
        }
        head=p;         /*申请到空间，将其作为头指针*/
        while(!feof(fp))  /*循环读数据直到文件尾结束*/
        {
                if(1!=fread(p,sizeof(struct student),1,fp))
                        break;  /*如果没读到数据，跳出循环*/
                p->next=(struct student *)malloc(sizeof(struct student));  /*为下一个结点申请空间*/
                if(!p->next)
                {
                        printf("out of memory!\n");  /*如没有申请到，则内存溢出*/
                        return head;
                }
                q=p;   /*保存当前结点的指针，作为下一结点的前驱*/
                p=p->next;   /*指针后移，新读入数据链到当前表尾*/
        }
        q->next=NULL;   /*最后一个结点的后继指针为空*/
        fclose(fp);       /*关闭文件*/
        printf("\n信息已成功从磁盘载入内存,");
        return head;   /*返回头指针*/
}
/*按回车继续*/
void enterToContinue()
{
        printf("按 Enter 继续...\n");
        getchar();
}
/*菜单*/
int selectMenu()
{
        int c=0;
        char s[3];
        system("cls");
        printf("              学生信息管理系统\n");
        printf("===========================================\n");
        printf(" 1. 录入学生信息\n");
        printf(" 2. 显示所有学生信息\n");
        printf(" 3. 按学号查询学生信息\n");
        printf(" 4. 按姓名查询学生信息(支持模糊查询)\n");
        printf(" 5. 按年龄查询学生信息\n");
        printf(" 6. 查询指定学生的所在系的信息(包括系名,系主任,系的办公地点)\n");
        printf(" 7. 修改学生信息\n");
        printf(" 8. 删除学生信息\n");
        printf(" 9. 追加学生信息\n");
        printf("10. 保存学生信息到文件\n");
        printf("11. 从文件载入学生信息\n");
        printf(" 0. 退出系统\n");
        do
        {
                printf("\n请选择功能(0-11): ");    /*在菜单窗口外显示提示信息*/
                gets(s);           /*输入选择项*/
                c=atoi(s); /*将输入的字符串转化为整形数*/
        }while(c<0||c>12);    /*选择项不在0~12之间重输*/
        return c;
}


/***************ns*/
/*按降序序显示所有学生信息*/
void AscDisplay(struct student *p)
{
                if(p==NULL)
                        return;
        struct student stu[100],s;
        int i,max,maxindex=0,m,n;
        for(i=0,p;p;i++,p=p->next)
        {
        stu[i]=*p;
        //printf("%d,",stu[i].sum);
        }
printf("\n");
for(m=0;m<i;m++)
{
for(n=m+1;n<i;n++)
if(stu[m].sum<stu[n].sum)
{s=stu[m];stu[m]=stu[n];stu[n]=s;}

}

for(m=0;m<i;m++)
{

        printf("\n=========================学生成绩从高到低的信息内容如下=========================");
        printf("\n学号\t姓名\t性别\t年龄\t课程1\t课程2\t课程3\t总成绩\t系号\n");

        printf("%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\n", stu[m].num, stu[m].name,stu[m].sex=='1'?"男":"女",stu[m].age,stu[m].score[0],stu[m].score[1],stu[m].score[2],stu[m].sum,stu[m].deptid);


}


}
/*主函数*/
void main()
{
        struct student *h=NULL;
        int choice=0;
        while(1)
        {
                choice=selectMenu();
                switch (choice)
                {
                        case 1: h=create();enterToContinue();break;
                        case 2: display(h);enterToContinue();break;
                        case 3: h=displayOnnum(h);enterToContinue();break;
                        case 4: h=displayOnName(h);enterToContinue();break;
                        case 5: h=displayOnAge(h);enterToContinue();break;
                        case 6: h=displaydeptid(h);enterToContinue();break;
                        case 7: h=updatestu(h);enterToContinue();break;
                        case 8: h=deletestu(h);enterToContinue();break;
                        case 9: h=appendstu(h);enterToContinue();break;
                        case 10:saveNode(h);enterToContinue();break;
                        case 11:h=loadNode();enterToContinue();break;
                        case 0: exit(0);
                }
        }
}




