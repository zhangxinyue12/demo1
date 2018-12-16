
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "math.h"
#include "string.h"
struct student            /*ѧ����Ϣ*/
{
        char num[20];     /*ѧ��*/
        char name[20];    /*����*/
        char sex;         /* �Ա�'1'->��, '0'->Ů*/
        short age;        /*����*/
        short score[3];   /*���ſγ̵ĳɼ�*/
        short sum;        /*�ܳɼ�*/
        short deptid;     /*����ϵ��ϵ��*/
        struct student *next;
};
struct department           /*ϵ��Ϣ�������ܹ���3��ϵ*/
{
        short id;           /*ϵ��*/
        char name[20];      /*ϵ��*/
        char dean[20];      /*ϵ����*/
        char location[30];  /*ϵ�İ칫�ص�*/
};
struct department dp[3]={{1,"�������ϵ","�ο���","�칫¥104"},{2,"ʳ��ϵ","��Ӣ","�칫¥105"},{3,"����ϵ","����","�칫¥106"}};
int currentNumOfstu=0;
/*¼��ѧ������Ϣ*/
struct student *create()
{
        struct student *p, *q, *head=NULL;
        int k, currentNumOfstu=1,i;
        short sum;
        char tmp[20],str[3];
        printf("����ѧ���ĸ�����");
        gets(tmp);
        k=atoi(tmp);
        while(k)
        {
                p=(struct student*)malloc(sizeof(struct student));
                printf("\n=======�������%d��������Ϣ=======\n", currentNumOfstu);
                printf("ѧ��:");
                gets(p->num);
                printf("����:");
                gets(p->name);
                printf("�Ա�,��(1),Ů(0):");
                p->sex=getchar();
                getchar();
                printf("����:");
                gets(str);
                p->age=atoi(str);
                sum=0;
                for(i=0;i<3;i++)
                {
                        printf("�γ�%d�ĳɼ�(����):",i+1);
                        gets(str);
                        p->score[i]=atoi(str);
                        sum=sum+p->score[i];
                }
                p->sum=sum;
                printf("ϵ��(1��2��3):");
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
        printf("\n¼�����,");
        return head;
}
/*��ʾ����ѧ����Ϣ*/
void display(struct student *p)
{
        if(p==NULL)
                printf("û��ѧ������Ϣ\n");
        else
        {
                printf("\n=========================ѧ������Ϣ��������=========================");
                printf("\nѧ��\t����\t�Ա�\t����\t�γ�1\t�γ�2\t�γ�3\t�ܳɼ�\tϵ��\n");
                while(p!=NULL)
                {
                        printf("%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\n", p->num, p->name,p->sex=='1'?"��":"Ů",p->age,p->score[0],p->score[1],p->score[2],p->sum,p->deptid);
                        p=p->next;
                }
        }
        printf("\n��ʾ���,");
}
/*��ѧ�Ų�ѯѧ����Ϣ*/
struct student *displayOnnum(struct student *head)
{
        struct student *p, *q;
        char x[30];
        if(head==NULL)
        {
                printf("Not find node: %s\n", x);
                return head;
        }
        printf("��Ҫ��ѯ��ѧ����ѧ��:");
        gets(x);
        q=p=head;
        while(strcmp(p->num,x)&&p->next)
        {
                q=p;
                p=p->next;
        }
        if(strcmp(p->num,x)==0)
        {
                printf("\n=========================ѧ������Ϣ��������=========================");
                printf("\nѧ��\t����\t�Ա�\t����\t�γ�1\t�γ�2\t�γ�3\t�ܳɼ�\tϵ��\n");
                printf("%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\n", p->num, p->name,p->sex=='1'?"��":"Ů",p->age,p->score[0],p->score[1],p->score[2],p->sum,p->deptid);
        }
        else
        {
                printf("Not find node: %s\n", x);
                return head;
        }
        printf("\n��ʾ���,");
        return head;
}
/*��������ѯѧ����Ϣ��֧��ģ����ѯ��*/
struct student *displayOnName(struct student *head)
{
        struct student *p, *q;
        char x[30];
        if(head==NULL)
        {
                printf("Not find node: %s\n", x);
                return head;
        }
        printf("��Ҫ��ѯ��ѧ��������:");
        gets(x);
        q=p=head;
        while(strstr(p->name,x)==0&&p->next)
        {
                q=p;
                p=p->next;
        }
        if(strstr(p->name,x))
        {
                printf("\n=========================ѧ������Ϣ��������=========================");
                printf("\nѧ��\t����\t�Ա�\t����\t�γ�1\t�γ�2\t�γ�3\t�ܳɼ�\tϵ��\n");
                printf("%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\n", p->num, p->name,p->sex=='1'?"��":"Ů",p->age,p->score[0],p->score[1],p->score[2],p->sum,p->deptid);
        }
        else
        {
                printf("Not find node: %s\n", x);
                return head;
        }
        printf("\n��ʾ���,");
        return head;
}
/*�������ѯѧ����Ϣ*/
struct student *displayOnAge(struct student *head)
{
        struct student *p, *q;
        char x[30];
        if(head==NULL)
        {
                printf("Not find node: %s\n", x);
                return head;
        }
        printf("��Ҫ��ѯ��ѧ��������:");
        gets(x);
        q=p=head;
        while(p->age!=atoi(x) && p->next)
        {
                q=p;
                p=p->next;
        }
        if(p->age==atoi(x))
        {
                printf("\n=========================ѧ������Ϣ��������=========================");
                printf("\nѧ��\t����\t�Ա�\t����\t�γ�1\t�γ�2\t�γ�3\t�ܳɼ�\tϵ��\n");
                printf("%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\n", p->num, p->name,p->sex=='1'?"��":"Ů",p->age,p->score[0],p->score[1],p->score[2],p->sum,p->deptid);
        }
        else
        {
                printf("Not find node: %s\n", x);
                return head;
        }
        printf("\n��ʾ���,");
        return head;
}
/*��ѯָ��ѧ��������ϵ����Ϣ(����ϵ��,ϵ����,ϵ�İ칫�ص�)*/
struct student *displaydeptid(struct student *head)
{
        struct student *p, *q;
        short f=1,i;
        char str[20];
        printf("��Ҫ��ѯ��ѧ����ѧ��:");
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
                        printf("\n================��������ϵ����Ϣ================");
                        printf("\nϵ��\tϵ��\tϵ����\tϵ�İ칫�ص�\n");
                        printf("%d\t%s\t%s\t%s\n",dp[i].id,dp[i].name,dp[i].dean,dp[i].location);
                }
        }
        if(f)
        {
                printf("Not find node: %s\n", str);
                return head;
        }
        printf("\n��ʾ���,");
        return head;
}
/*�޸�ѧ������Ϣ*/
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
        printf("������Ҫ�޸ĵ�ѧ����ѧ��:");
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
                printf("\n�ҵ���Ҫ�޸���Ϣ��ѧ��!\n");
                printf("\nѧ��\t����\t�Ա�\t����\t�γ�1\t�γ�2\t�γ�3\t�ܳɼ�\tϵ��\n");
                printf("%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\n", p->num, p->name,p->sex=='1'?"��":"Ů",p->age,p->score[0],p->score[1],p->score[2],p->sum,p->deptid);
                printf("ѧ��:");
                gets(x);
                if(strcmp(x,"")!=0)
                        strcpy(p->num,x);
                printf("����:");
                gets(x);
                if(strcmp(x,"")!=0)
                        strcpy(p->name,x);
                printf("�Ա�,��(1),Ů(0):");
                gets(m);
                if(strcmp(m,""))
                        p->sex=atoi(m);
                printf("����:");
                gets(m);
                p->age=atoi(m);
                for(i=0;i<3;i++)
                {
                        printf("�γ�%d�ĳɼ�:",i+1);
                        gets(x);
                        if(p->score[i]!=atoi(x))
                                p->score[i]=atoi(x);
                        sum+=p->score[i];
                }
                printf("ϵ��(1��2��3):");
                gets(m);
                if(strcmp(m,""))
                        p->sex=atoi(m);
        }
        else
        {
                printf("Not find node: %s\n", x);
                return head;
        }
        printf("\n�޸����,");
        return head;
}
/*ɾ��ѧ������Ϣ*/
struct student *deletestu(struct student *head)
{
        struct student *p, *q;
        char x[30];
        if(head==NULL)
        {
                printf("Not find node: %s\n", x);
                return head;
        }
        printf("��Ҫɾ����ѧ����ѧ��:");
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
                        printf("\nɾ�����,");
                        return head;
                }
                else
                {
                        q->next=p->next;
                        free(p);
                        printf("\nɾ�����,");
                        return head;
                }
        }
        else
        {
                printf("Not find node: %s\n", x);
                return head;
        }
        printf("\nɾ�����,");
        return head;
}
/*׷��Ա������Ϣ*/
struct student *appendstu(struct student *head)
{
        struct student *p;
        char str[3];
        FILE *fp;
        char fileName[50]="C:\\students.dat";
        short sum=0,i;
        p=(struct student*)malloc(sizeof(struct student));
        printf("ѧ��:");
        gets(p->num);
        printf("����:");
        gets(p->name);
        printf("�Ա�,��(1),Ů(0):");
        p->sex=getchar();
        getchar();
        printf("����:");
        gets(str);
        p->age=atoi(str);
        for(i=0;i<3;i++)
        {
                printf("�γ�%d�ĳɼ�(����):",i+1);
                gets(str);
                p->score[i]=atoi(str);
                sum=sum+p->score[i];
        }
        p->sum=sum;
        printf("ϵ��(1��2��3):");
        gets(str);
        p->deptid=atoi(str);
        p->next=NULL;
        printf("\n=============ѧ������Ϣ�������===============\n");
        printf("�������ļ�������%s: ", fileName);
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
        printf("\n׷�����,");
        return head;
}
/*���ڴ�����д���ļ�*/
void saveNode(struct student *p)
{
        char fileName[50]="C:\\students.dat";
        FILE *fp;
        printf("�������ļ���,��%s: ", fileName);
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
        printf("\n��Ϣ�ɹ�����,");
        return;
}
/*���������ݵ��ڴ�*/
struct student *loadNode()
{
        struct student *p, *q, *head=NULL;/*�����¼ָ�����*/
        FILE *fp;
        char fileName[50]="C:\\students.dat";   /*�����ļ�����Ĭ��ΪC:\\students.dat*/
        printf("�������ļ�������%s: ", fileName);
        gets(fileName);
        if(strcmp(fileName, "")==0)       /*���û�������ļ�����Ĭ��ΪC:\\students.dat,����,�����ļ����洢*/
                strcpy(fileName, "C:\\students.dat");
        if((fp=fopen(fileName, "rb"))==NULL)
        {
                printf("File open error!\n");
                exit(1);
        }
        printf("\n���������ļ������Ժ�...\n");
        p=(struct student *)malloc(sizeof(struct student));   /*����ռ�*/
        if(!p)
        {
                printf("out of memory!\n");    /*��û�����뵽�����ڴ����*/
                return head;       /*���ؿ�ͷָ��*/
        }
        head=p;         /*���뵽�ռ䣬������Ϊͷָ��*/
        while(!feof(fp))  /*ѭ��������ֱ���ļ�β����*/
        {
                if(1!=fread(p,sizeof(struct student),1,fp))
                        break;  /*���û�������ݣ�����ѭ��*/
                p->next=(struct student *)malloc(sizeof(struct student));  /*Ϊ��һ���������ռ�*/
                if(!p->next)
                {
                        printf("out of memory!\n");  /*��û�����뵽�����ڴ����*/
                        return head;
                }
                q=p;   /*���浱ǰ����ָ�룬��Ϊ��һ����ǰ��*/
                p=p->next;   /*ָ����ƣ��¶�������������ǰ��β*/
        }
        q->next=NULL;   /*���һ�����ĺ��ָ��Ϊ��*/
        fclose(fp);       /*�ر��ļ�*/
        printf("\n��Ϣ�ѳɹ��Ӵ��������ڴ�,");
        return head;   /*����ͷָ��*/
}
/*���س�����*/
void enterToContinue()
{
        printf("�� Enter ����...\n");
        getchar();
}
/*�˵�*/
int selectMenu()
{
        int c=0;
        char s[3];
        system("cls");
        printf("              ѧ����Ϣ����ϵͳ\n");
        printf("===========================================\n");
        printf(" 1. ¼��ѧ����Ϣ\n");
        printf(" 2. ��ʾ����ѧ����Ϣ\n");
        printf(" 3. ��ѧ�Ų�ѯѧ����Ϣ\n");
        printf(" 4. ��������ѯѧ����Ϣ(֧��ģ����ѯ)\n");
        printf(" 5. �������ѯѧ����Ϣ\n");
        printf(" 6. ��ѯָ��ѧ��������ϵ����Ϣ(����ϵ��,ϵ����,ϵ�İ칫�ص�)\n");
        printf(" 7. �޸�ѧ����Ϣ\n");
        printf(" 8. ɾ��ѧ����Ϣ\n");
        printf(" 9. ׷��ѧ����Ϣ\n");
        printf("10. ����ѧ����Ϣ���ļ�\n");
        printf("11. ���ļ�����ѧ����Ϣ\n");
        printf(" 0. �˳�ϵͳ\n");
        do
        {
                printf("\n��ѡ����(0-11): ");    /*�ڲ˵���������ʾ��ʾ��Ϣ*/
                gets(s);           /*����ѡ����*/
                c=atoi(s); /*��������ַ���ת��Ϊ������*/
        }while(c<0||c>12);    /*ѡ�����0~12֮������*/
        return c;
}


/***************ns*/
/*����������ʾ����ѧ����Ϣ*/
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

        printf("\n=========================ѧ���ɼ��Ӹߵ��͵���Ϣ��������=========================");
        printf("\nѧ��\t����\t�Ա�\t����\t�γ�1\t�γ�2\t�γ�3\t�ܳɼ�\tϵ��\n");

        printf("%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\n", stu[m].num, stu[m].name,stu[m].sex=='1'?"��":"Ů",stu[m].age,stu[m].score[0],stu[m].score[1],stu[m].score[2],stu[m].sum,stu[m].deptid);


}


}
/*������*/
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




