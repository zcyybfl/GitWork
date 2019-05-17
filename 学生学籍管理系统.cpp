#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#define FILE_Student "ѧ��.txt"
#define FILE_Teacher "��ʦ.txt"
#define N 100
void menu();
void Add_Information1();
void Add_Information2();
void Add_Grade();
void Class();
void Delete();
void Delete_Grade();
void Delete_Course_T();
void Modify();
void Modify_Grade();
void Modify_Course_T();
void Modify_Class_T();
void Modify_Class_S(); 
void Search();
void Search1();
void Grade_Statistics();
void Grade_Sort();
void Total_Grade_Sort();
void Total_Grade_In();
void Average_Grade();
void Single_Grade_In();
void Graduate_Imformation();
int m=-1;
struct score{
	char name[20];
	int grade;
	int Class;
};
struct course{
	char ID[20];//�γ̺� 
	char Name[20];//�γ��� 
	int grade;//�ɼ�
	char Mark[20];
};
struct student{
	char num[20];//ѧ��
	char name[20];//����
	char sex[10];//�Ա�
	char birthday[30];//��������
	char ID[30];//���֤
	char time[20];//��ѧʱ��
	char courtyard[20];//����Ժϵ
	char politics[20];//������ò
	char site[20];//��ͥסַ
	char place[20];//����
	char post[20];//��������
	char nation[20];//����
	int Class;//�༶
	int Required_credits;//����ѧ��
	int Revised_credits;//����ѧ��
	char Diploma_Number[20];//��ҵ֤����
	struct course cou[5];
}stu[N];
struct teacher{
	char ID[20];//�̹���
	char name[20];//����
	char sex[20];//�Ա�
	char title[20];//ְ��
	char courtyard[20];//����Ժϵ
	char phone[20];//�绰����
	char C_ID[20];//�γ̺�
	int Class;//�༶ 
}tea[N];
void Course_Choice()//�γ�ѡ�����
{
	puts("\t\t����������������������");
    puts("\t\t��       �γ���         �γ̺�          ��");
    puts("\t\t��       ��  ��         J10001          ��");
    puts("\t\t��       ΢����         J10002          ��");
    puts("\t\t��       Ӣ  ��         J10003          ��");
    puts("\t\t��       C ����         J10004          ��");
    puts("\t\t��        JAVA          J10005          ��");
    puts("\t\t����������������������");
} 
int load(int m1) //���ļ�,��ȡ��������� 
{
	FILE *fp,*fp1,*fp2;
    int i;
    if(m1==1)
    {
		if((fp=fopen(FILE_Student,"rb"))==NULL) //������ļ���rb��ʾ��һ���������ļ���ֻ���������
		{
			printf("\n�ļ�������!������:\n");
	        return 0;
		}
	    for(i=0;!feof(fp);i++)  //�����ļ���β
	       fread(&stu[i],sizeof(struct student),1,fp);
	    fclose(fp);
	    return i;
   }
    else if(m1==2)
    {
	    if((fp1=fopen(FILE_Teacher,"rb"))==NULL) /*������ļ���rb��ʾ��һ���������ļ���ֻ���������*/
		{
			printf("\n�ļ�������!������:\n");
	        return 0;
		}
	    for(i=0;!feof(fp1);i++)  /*�����ļ���β*/
	       fread(&tea[i],sizeof(struct teacher),1,fp1);
	    fclose(fp1);
	    return i;
    } 
}
void save(int n,int m1) //������Ϣ
{
	FILE *fp,*fp1,*fp2;
	int i,a;
	a=load(m1);
    if(m1==1)
	{
		if((fp=fopen(FILE_Student,"ab"))==NULL) //ֻ�򿪻���һ���������ļ���ֻ����д����
		{
			printf("\nCan not open file!\n");
		}
	    for(i=a;i<n+a;i++)
	      //if(stu[i].name[0]!='\0')
	         if(fwrite(&stu[i],sizeof(struct student),1,fp)!=1) //��һ��������Ϊһ������һ����д������ļ�
	            printf("�ļ�д�����!\n");
	    fclose(fp);
    }
    else if(m1==2)
    {
		if((fp1=fopen(FILE_Teacher,"ab"))==NULL) /*ֻ�򿪻���һ���������ļ���ֻ����д����*/
		{
			printf("\nCan not open file!\n");
		}
	    for(i=a;i<n+a;i++)
	      //if(stu[i].name[0]!='\0')
	         if(fwrite(&tea[i],sizeof(struct teacher),1,fp1)!=1) /*��һ��������Ϊһ������һ����д������ļ�*/
	            printf("�ļ�д�����!\n");
	    fclose(fp1);
    }
}
void Add() //������Ϣ������� 
{
	system("cls");
	int n,w;
	if(m==3)
	{
		do
		{
			puts("\t\t����������������������");
		    puts("\t\t��                                      ��");
		    puts("\t\t��           1.������Ϣ¼��             ��");
		    puts("\t\t��                                      ��");
		    puts("\t\t��           2.��ʦ�γ̹���             ��");
		    puts("\t\t��                                      ��");
		    puts("\t\t��           3.������Ϣɾ��             ��");
		    puts("\t\t��                                      ��");
		    puts("\t\t��           4.������Ϣ�޸�             ��");
		    puts("\t\t��                                      ��");
		    puts("\t\t��           5.��        ��             ��");
		    puts("\t\t����������������������");
			printf("��ѡ���������(1-5) : [ ]\b\b");
			scanf("%d",&n);
			getchar();
			if(n<1||n>5)
		    {
			    system("cls");
			    printf("ѡ�����!  ������ѡ��!\n");
			    w=1;
		    }
		   else
			   w=0;
	    }while(w==1);
	    system("cls");
	    switch(n)
	    {
	    	case 1:Add_Information1();break;
	    	case 2:Add_Information2();break;
	    	case 3:Delete();break;
	    	case 4:Modify();break;
	    	default:system("cls");menu();break;
		 } 
    }
    else
    {
    	printf("��û��Ȩ�ޣ�\n");
		system("pause");
		system("cls");
		menu();
    }
}
void Grade()//�ɼ����� 
{
	system("cls");
	if(m==3)
	{
		int n,w;
		do
		{
			puts("\t\t����������������������");
		    puts("\t\t��                                      ��");
		    puts("\t\t��             1.�ɼ�¼��               ��");
		    puts("\t\t��                                      ��");
		    puts("\t\t��             2.�ɼ�ɾ��               ��");
		    puts("\t\t��                                      ��");
		    puts("\t\t��             3.�ɼ��޸�               ��");
		    puts("\t\t��                                      ��");
		    puts("\t\t��             4.��    ��               ��");
		    puts("\t\t����������������������");
			printf("��ѡ���������(1-4) : [ ]\b\b");
			scanf("%d",&n);
			getchar();
			if(n<1||n>4)
		    {
			    system("cls");
			    printf("ѡ�����!  ������ѡ��!\n");
			    w=1;
		    }
		   else
			   w=0;
	    }while(w==1);
	    system("cls");
	    switch(n)
	    {
	    	case 1:Add_Grade();break;
	    	case 2:Delete_Grade();break;
	    	case 3:Modify_Grade();break;
	    	default:system("cls");menu();break;
		}
	}
	else
	{
		printf("��û��Ȩ�ޣ�\n");
		system("pause");
		system("cls");
		menu();
	}
 } 
void Add_Grade()//�ɼ�¼�� 
{
	FILE *fp;
	int i,j,n,f,num;
	char Mark[20],Flag[5];
	n=load(1);
	struct student S[n];
	do
	{
		printf("��������Ҫ¼��ɼ���ѧ���ĸ�����");
		scanf("%d",&num);
		getchar();
		int flag[num],mark[num];
		printf("������������Ҫ¼��ɼ���ѧ����ѧ�ţ�\n");
		for(i=0;i<num;i++)
		{
			printf("��%d��ѧ����ѧ�ţ�",i+1);
			gets(S[i].num);
			flag[i]=-1;
			mark[i]=-1;
		}
		for(j=0;j<num;j++)
		{
			for(i=0;i<n-1;i++)
			{   
				if(strcmp(S[j].num,stu[i].num)==0)
				{
					flag[j]=i;
			    }
			    else
			        mark[j]=j;
			 }
		}
		for(j=0;j<num;j++)
		{
			if(flag[j]!=-1)
			{
				printf("����ѧ��Ϊ%s��ѧ��! \n",stu[flag[j]].num);
				printf("�Ƿ�¼����ɼ� y/n :");
				gets(Mark);
				if(strcmp(Mark,"y")==0||strcmp(Mark,"Y")==0)
				{
					for(i=0;i<5;i++)
					{
						if(stu[flag[j]].cou[i].grade!=-1)
						{
							printf("%s�ɼ��Ѵ��ڣ��Ƿ��޸� y/n: ",stu[flag[j]].cou[i].Name);
							gets(Mark);
							if(strcmp(Mark,"n")==0||strcmp(Mark,"N")==0)
							    continue;
						}
					    printf("%s�ɼ���",stu[flag[j]].cou[i].Name);
					    scanf("%d",&stu[flag[j]].cou[i].grade);
						getchar();
				    }
					if((fp=fopen(FILE_Student,"wb"))==NULL) //ֻ�򿪻���һ���������ļ���ֻ����д����
					{
						printf("\nCan not open file!\n");
					}
				    for(i=0;i<n-1;i++)
				      //if(stu[i].name[0]!='\0')
				         if(fwrite(&stu[i],sizeof(struct student),1,fp)!=1) //��һ��������Ϊһ������һ����д������ļ�
				            printf("�ļ�д�����!\n");
				    fclose(fp);
					printf("�ɹ�¼��ѧ��Ϊ%s��ѧ���ĳɼ���\n",stu[flag[j]].num);
				}
			}
			else
			{
				printf("��ѧ��Ϊ%s��ѧ��! \n",S[mark[j]].num);
				system("pause"); 
			}
	   }
		printf("�Ƿ����¼������ѧ���ĳɼ� y/n");
		gets(Flag);  
    }while(strcmp(Flag,"y")==0||strcmp(Flag,"Y")==0);
    system("cls");
    Grade();
}
void Credit_Judgment()//ѧ���ж� 
{
	FILE *fp;
	int i,j,n;
	n=load(1);
	for(i=0;i<n-1;i++)
	{
		stu[i].Revised_credits=0;
		for(j=0;j<5;j++)
		{
			if(stu[i].cou[j].grade>=60)
			{
				stu[i].Revised_credits+=3;
			}
		}
	}
	fp=fopen(FILE_Student,"wb");
	for(i=0;i<n-1;i++)
	   fwrite(&stu[i],sizeof(struct student),1,fp);
	fclose(fp);
}
void Add_Student()//���ѧ����Ϣ 
{
	int i,j,n,a,k,p,f;
	char Mark[5];
	do
	{
		system("cls");
		n=load(1);
		f=1;
		printf("��������Ҫ��ӵ�ѧ����Ϣ�ĸ�����");
		scanf("%d",&a);
		getchar();
		for(i=n;i<n+a;i++)
		{
			printf("��%d��ѧ��\n",f);
	    	printf("ѧ�ţ�");
			gets(stu[i].num);
			for(k=0;k<n-1;k++)
			{
				if(strcmp(stu[k].num,stu[i].num)==0)
				{
					printf("ѧ���ظ�������������...\n");
					p=1;
					i--;
					break;
				}
				else
				   p=0;
			}
			if(p==1) continue;
			printf("������"); 
			gets(stu[i].name);
			printf("�Ա�");
			gets(stu[i].sex);
			printf("�������ڣ�");
			gets(stu[i].birthday);
			printf("���֤�ţ�");
			gets(stu[i].ID);
			printf("��ѧʱ�䣺");
			gets(stu[i].time);
			printf("����Ժϵ��");
			gets(tea[i].courtyard);
			printf("������ò��");
			gets(stu[i].politics);
			printf("��ͥסַ��");
			gets(stu[i].site);
			printf("���᣺");
			gets(stu[i].place);
			printf("������ţ�");
			gets(stu[i].post);
			printf("���壺");
			gets(stu[i].nation);
			stu[i].Class=-1; 
		    stu[i].Required_credits=15;
		    stu[i].Revised_credits=0;
			strcpy(stu[i].Diploma_Number,"��");
			for(j=0;j<5;j++)
			{
				stu[i].cou[j].grade=-1;
				strcpy(stu[i].cou[j].Mark,"��");
			}
			strcpy(stu[i].cou[0].Name,"����");
			strcpy(stu[i].cou[0].ID,"J10001");
			strcpy(stu[i].cou[1].Name,"΢����");
			strcpy(stu[i].cou[1].ID,"J10002");
			strcpy(stu[i].cou[2].Name,"Ӣ��");
			strcpy(stu[i].cou[2].ID,"J10003");
			strcpy(stu[i].cou[3].Name,"C����");
			strcpy(stu[i].cou[3].ID,"J10004");
			strcpy(stu[i].cou[4].Name,"JAVA");
			strcpy(stu[i].cou[4].ID,"J10005");
			f++;
			system("cls");
		}
		save(a,1);
		printf("��ӳɹ���\n");
		printf("�Ƿ�����������ѧ�� y/n \n");
		gets(Mark) ;
    }while(strcmp(Mark,"y")==0||strcmp(Mark,"Y")==0);
	system("cls");
    Add_Information1();
 } 
void Add_Teacher()//��ӽ�ʦ��Ϣ 
{
	int i,n,a,k,p,f;
	char Mark[5];
	do
	{
		system("cls"); 
		n=load(2);
		f=1;
		printf("��������Ҫ��Ҫ��ӵĽ�ʦ��Ϣ�ĸ�����");
		scanf("%d",&a);
		getchar();
		for(i=n;i<n+a;i++)
		{
			printf("��%d����ʦ\n",f);
			printf("�̹��ţ�");
			gets(tea[i].ID);
			for(k=0;k<n;k++)
			{
				if(strcmp(tea[k].ID,tea[i].ID)==0)
				{
					printf("�̹����ظ�������������...");
					p=1;
					i--;
					break;
				}
				else
				   p=0;
			}
			if(p==1) continue;
			printf("������"); 
			gets(tea[i].name);
			printf("�Ա�");
			gets(tea[i].sex);
			printf("ְ�ƣ�"); 
			gets(tea[i].title);
			printf("����Ժϵ��");
			gets(tea[i].courtyard);
			printf("�绰���룺");
			gets(tea[i].phone);
			strcpy(tea[i].C_ID,"��");
			f++;
			system("cls");
		}
		save(a,2);
		printf("��ӳɹ���\n");
		printf("�Ƿ�����������ʦ y/n \n");
		gets(Mark) ;
    }while(strcmp(Mark,"y")==0||strcmp(Mark,"Y")==0);
	system("cls");
    Add_Information1();
}
void Add_Class()//ѧ���༶���� 
{
	FILE *fp;
	int i,j,n,f,k,num;
	char Mark[20],Flag[5];
	struct student S[n];
	do
	{
		n=load(1);
		printf("������༶��(��1-5��ѡ��)��");
		scanf("%d",&f);
		getchar();
    	printf("��ǰ����%d��ѧ����Ϣ\n",n-1);
		printf("������Ҫ���䵽�˰༶��ѧ���ĸ�����");
		scanf("%d",&num);
		getchar();
		int flag[num],mark[num];
		printf("������������Ҫ����ൽ�˼���ѧ����ѧ�ţ�\n");
		for(i=0;i<num;i++)
		{
			printf("��%d��ѧ����ѧ�ţ�",i+1);
			gets(S[i].num);
			flag[i]=-1;
			mark[i]=-1;
		}
		for(j=0;j<num;j++)
		{
			for(i=0;i<n-1;i++)
			{   
				if(strcmp(S[j].num,stu[i].num)==0)
				{
					flag[j]=i;
			    }
			 }
			 if(flag[j]==-1)
			 {
			 	mark[j]=j;
			 }
		} 
		for(j=0;j<num;j++)
		{
			if(flag[j]!=-1)
			{
				if(stu[flag[j]].Class!=-1)
				{
					printf("ѧ��Ϊ%s��ѧ���Ѵ��ڰ༶���Ƿ��޸ĵ��˰༶ y/n��",stu[flag[j]].num);
					gets(Flag);
					if(strcmp(Flag,"n")==0||strcmp(Flag,"N")==0)
					    continue;
				}
				stu[flag[j]].Class=f;
				k=1;
			}
	   }
	   if(k==1)
	   {
	   	    printf("����ɹ���"); 
	   	    fp=fopen(FILE_Student,"wb");
			for(i=0;i<n-1;i++)
			{
				fwrite(&stu[i],sizeof(struct student),1,fp);
			}
			fclose(fp);
	   } 
	   for(j=0;j<num;j++)
	   {
	   	    if(mark[j]!=-1)
			{
				printf("��ѧ��Ϊ%s��ѧ��! \n",S[mark[j]].num);
			}
	   }
		printf("�Ƿ�������� y/n");
		gets(Flag);
    }while(strcmp(Flag,"y")==0||strcmp(Flag,"Y")==0);
    system("cls"); 
    Class(); 
}
void Add_Class_T()//��ʦ�༶���� 
{
	FILE *fp,*fp1; 
	int a,i,j,n,k,f,num;
	char Mark[20],Flag[5];
	do
	{
		num=0;
		n=load(2);
		a=load(1);
		int mark[a];
		do
		{
			f=-1;
			printf("������Ҫ�����ʦ�İ༶�ţ�");
			scanf("%d",&k);
			getchar();
			printf("��������Ҫ���䵽�˰༶�Ľ�ʦ�Ľ̹��ţ�"); 
			gets(Mark);
			for(i=0;i<n-1;i++)
			{
				if(strcmp(tea[i].ID,Mark)==0)
					f=i;
			}
			if(f==-1)
			{
				printf("���޸ý�ʦ��\n");
				printf("�Ƿ��������� ��y/n����");
				gets(Flag);
				continue;
			}
			else
			{
				if(strcmp(tea[f].C_ID,"��")==0)
					f=-1;
				if(f==-1)
				{
					printf("�ý�ʦ��δ�οΣ�");
					printf("�Ƿ��������� ��y/n����");
					gets(Flag);
				}
				else
					break;
			}
		}while(strcmp(Flag,"y")==0||strcmp(Flag,"Y")==0);
		for(i=0;i<a-1;i++)
		{
			if(stu[i].Class=k)
			{
				mark[num]=i;
				num++;
			}
		}
		if(num==0)
		{
			printf("�ð�����ѧ����");
		}
		else
		{
			if(f!=-1)
			{
				for(i=0;i<5;i++)
				{
					if(strcmp(tea[f].C_ID,stu[mark[0]].cou[i].ID)==0)
						j=i;
				}
				if(strcmp(stu[mark[0]].cou[j].Mark,"��")!=0)
				{
					printf("�ð��%s�γ�������ʦ�ڿΣ�",stu[mark[0]].cou[j].Name);
				}
				else
				{
					tea[f].Class=k;
					for(i=0;i<num-1;i++)
					{
						strcpy(stu[mark[i]].cou[j].Mark,tea[f].ID);
					}
					fp=fopen(FILE_Student,"wb");
					for(i=0;i<a-1;i++)
					{
						fwrite(&stu[i],sizeof(struct student),1,fp);
					}
					fclose(fp);
					fp1=fopen(FILE_Teacher,"wb");
					for(i=0;i<n-1;i++)
					{
						fwrite(&tea[i],sizeof(struct teacher),1,fp1);
					}
					fclose(fp1);
					printf("����ɹ���");
				 }
		    }
		}
		printf("�Ƿ�������� y/n \n");
		gets(Flag);
    }while(strcmp(Mark,"y")==0||strcmp(Mark,"Y")==0);
    system("cls"); 
    Class(); 
}
void Class()//�༶������� 
{
	system("cls");
	int a,w;
	if(m==3)
	{
		do
		{
			puts("\t\t����������������������");
			puts("\t\t��                                      ��");
			puts("\t\t��           1.ѧ���༶����             ��");
			puts("\t\t��                                      ��");
			puts("\t\t��           2.��ʦ�༶����             ��");
			puts("\t\t��                                      ��");
			puts("\t\t��           3.ѧ���༶�޸�             ��");
			puts("\t\t��                                      ��");
			puts("\t\t��           4.��ʦ�༶�޸�             ��");
			puts("\t\t��                                      ��");
			puts("\t\t��           5.��        ��             ��");
			puts("\t\t����������������������");
			printf("��ѡ���������(1-5) : [ ]\b\b");
			scanf("%d",&a);
			getchar();
			if(a<1||a>5)
			{
			    system("cls");
			    printf("ѡ�����!  ������ѡ��!\n");
			    w=1;
			}
			else
			   w=0;
		}while(w==1);
		switch(a)
		{
			case 1:Add_Class();break;
			case 2:Add_Class_T();break;
			case 3:Modify_Class_S();break;
			case 4:Modify_Class_T();break;
			default:system("cls");menu();break;
		}
    }
    else
    {
    	printf("��û��Ȩ�ޣ�\n");
		system("pause");
		system("cls");
		menu();
    }
 } 
void Add_Course_T()//��ʦ�γ̷���
{
	FILE *fp;
	int i,j,n,f;
	char Mark[20],Flag[5];
	if(m==3)
	{
		do
		{
			n=load(2);
			if(n==1)
			{
				printf("���޽�ʦ��Ϣ��\n");
				system("pause");
				break;
			}
	    	printf("������Ҫ����γ̵Ľ�ʦ�Ľ̹��ţ�\n");
			gets(Mark);
			system("cls");
			for(i=0;i<n-1;i++)
			{
				if(strcmp(Mark,tea[i].ID)==0)
			    {
			    	Course_Choice();
			        printf("������Ͽγ̷��䣺\n");
			    	gets(Mark);
			    	strcpy(tea[i].C_ID,Mark);
		    		f=1;
		    		if((fp=fopen(FILE_Teacher,"wb"))==NULL) //ֻ�򿪻���һ���������ļ���ֻ����д����
					{
						printf("\nCan not open file!\n");
					}
				    for(i=0;i<n-1;i++)
				      //if(stu[i].name[0]!='\0')
				         if(fwrite(&tea[i],sizeof(struct teacher),1,fp)!=1) //��һ��������Ϊһ������һ����д������ļ�
				            printf("�ļ�д�����!\n");
				    fclose(fp);
				    printf("¼��ɹ���\n");
					system("pause");
				}
			}
			printf("�Ƿ����¼�� y/n");
			gets(Flag);
	    }while(strcmp(Flag,"y")==0||strcmp(Flag,"Y")==0);
    }
    else
    {
    	printf("��û��Ȩ�ޣ�\n");
    	system("pause");
	}
	system("cls");
    Add_Information2(); 
}
void Add_Information1()//��ӻ�����Ϣ 
{
	system("cls");
	int w,m1;
	do
	{
		puts("\t\t����������������������");
	    puts("\t\t��                                      ��");
	    puts("\t\t��        1.ѧ��������Ϣ¼��            ��");
	    puts("\t\t��                                      ��");
	    puts("\t\t��        2.��ʦ������Ϣ¼��            ��");
	    puts("\t\t��                                      ��");
	    puts("\t\t��        3.��            ��            ��");
	    puts("\t\t����������������������");
		printf("��ѡ����Ҫ��ӵ���Ϣ����(1-3) : [ ]\b\b");
		scanf("%d",&m1);
		getchar();
		if(m1<1||m1>3)
	    {
		    system("cls");
		    printf("ѡ�����!  ������ѡ��!\n");
		    w=1;
	    }
	   else
		   w=0;
    }while(w==1);
    switch(m1)
    {
    	case 1:Add_Student();break;
    	case 2:Add_Teacher();break;
    	default:system("cls");Add();break;
	}
}
void Add_Information2() //��ʦ�γ̹������ 
{
	system("cls");
	int w,m1;
	do
	{ 
		puts("\t\t����������������������");
	    puts("\t\t��                                      ��");
	    puts("\t\t��            1.��ʦ�γ̷���            ��");
	    puts("\t\t��                                      ��");
	    puts("\t\t��            2.��ʦ�γ��޸�            ��");
	    puts("\t\t��                                      ��");
	    puts("\t\t��            3.��ʦ�γ�ɾ��            ��");
	    puts("\t\t��                                      ��");
	    puts("\t\t��            4.��        ��            ��");
	    puts("\t\t����������������������");
	    printf("��ѡ���������(1-4) : [ ]\b\b");
	    scanf("%d",&m1);
	    getchar();
	    if(m1<1||m1>4)
	   {
		   system("cls");
		   printf("ѡ�����!  ������ѡ��!\n");
		   w=1;
	   }
	   else
		   w=0;
    }while(w==1);
    switch(m1)
    {
    	case 1:Add_Course_T();break;
    	case 2:Modify_Course_T();break;
    	case 3:Delete_Course_T();break;
    	default:system("cls");Add();break;
	}
}
void Search_Information_S()//ѧ��������Ϣ��ѯ 
{
	int i,j,n,f;
	char Mark[20],Flag[5];
	n=load(1);
	do
	{
		do
		{
			f=-1;
			printf("��������Ҫ��ѯ��Ϣ��ѧ����ѧ�ţ�");
			gets(Mark);
			for(i=0;i<n-1;i++)
			{
				if(strcmp(Mark,stu[i].num)==0)
				{
					f=i;
				}
			}
			if(f==-1)
			{
			    printf("�޸�ѧ����\n");
			    printf("�Ƿ��������� y/n :");
			    gets(Flag);
			}
			else
			    break;
		}while(strcmp(Flag,"y")==0||strcmp(Flag,"Y")==0);
		if(f==-1)
		{
			system("cls");
			Search(); 
		}
		else
		{
			printf("ѧ�ţ�");
			puts(stu[f].num);
			printf("������");
			puts(stu[f].name);
			printf("�Ա�");
			puts(stu[f].sex);
			printf("�������£�");
			puts(stu[f].birthday);
			printf("���֤�ţ�");
			puts(stu[f].ID);
			printf("��ѧʱ�䣺");
			puts(stu[f].time);
			printf("������ò��");
			puts(stu[f].politics);
			printf("��ͥסַ��");
			puts(stu[f].site);
			printf("���᣺");
			puts(stu[f].place);
			printf("������ţ�");
			puts(stu[f].post);
			printf("���壺");
			puts(stu[f].nation);
		}
		printf("�Ƿ������ѯ����ѧ����Ϣ y/n��");
		gets(Flag);
    }while(strcmp(Flag,"y")==0||strcmp(Flag,"Y")==0);
    system("cls");
    Search();
} 
void Search_Information_T()//��ʦ������Ϣ��ѯ
{
	int i,j,n,f=-1;
	char Mark[20],Flag[5];
	n=load(2);
	do
	{
		do
		{
			printf("��������Ҫ��ѯ��Ϣ�Ľ�ʦ�Ľ̹��ţ�");
			gets(Mark);
			for(i=0;i<n-1;i++)
			{
				if(strcmp(Mark,tea[i].ID)==0)
				{
					f=i;
				}
			}
			if(f==-1)
			{
			    printf("�޸ý�ʦ��\n");
			    printf("�Ƿ��������� y/n :");
			    gets(Flag);
			}
			else
			    break;
		}while(strcmp(Flag,"y")==0||strcmp(Flag,"Y")==0);
		if(f==-1)
		{
			system("cls");
			Search(); 
		}
		else
		{
			printf("�̹��ţ�");
			puts(tea[f].ID);
			printf("������"); 
			puts(tea[f].name);
			printf("�Ա�");
			puts(tea[f].sex);
			printf("ְ�ƣ�"); 
			puts(tea[f].title);
			printf("����Ժϵ��");
			puts(tea[f].courtyard);
			printf("�绰���룺");
			puts(tea[f].phone);
		}
		printf("�Ƿ������ѯ������ʦ��Ϣ y/n��");
		gets(Flag);
    }while(strcmp(Flag,"y")==0||strcmp(Flag,"Y")==0);
    system("cls");
    Search();
} 
void Search_Grade()//�ɼ���ѯ 
{
	int i,j,n,f;
	char Mark[20],Flag[5];
	n=load(1); 
	do
	{
		do
		{
			f=-1; 
			printf("��������Ҫ���ҳɼ���ѧ�ţ�");
			gets(Mark);
			for(i=0;i<n-1;i++)
			{
				if(strcmp(Mark,stu[i].num)==0)
				{
					f=i;
				}
			}
			if(f==-1)
			{
			    printf("�޸�ѧ����\n");
			    printf("�Ƿ��������� y/n :");
			    gets(Flag);
			}
			else
			    break;
		}while(strcmp(Flag,"y")==0||strcmp(Flag,"Y")==0);
		if(f==-1)
		{
			system("pause");
		}
		else
		{
			if(stu[f].cou[0].grade==-1)
			{
				printf("��ѧ���ɼ���δ¼�룡\n");
				f=0; 
			}
			else
				for(j=0;j<5;j++)
				{
					printf("%s�ɼ���",stu[f].cou[j].Name);
				    printf("%d\n",stu[f].cou[j].grade);
				}
		}
		printf("�Ƿ����²�ѯ����ѧ���ĳɼ� y/n :");
		gets(Flag);
	}while(strcmp(Flag,"y")==0||strcmp(Flag,"Y")==0);
	system("cls");
	Search();
}
void Search_Course_T()//��ʦ�γ̲�ѯ 
{
	int i,j,n,f;
	char Mark[20],Flag[5];
	n=load(2);
	do
	{
		do
		{
			f=-1; 
			printf("��������Ҫ��ѯ�ο���Ϣ�Ľ�ʦ�Ľ̹��ţ�");
			gets(Mark);
			for(i=0;i<n-1;i++)
			{
				if(strcmp(Mark,tea[i].ID)==0)
				{
					f=i;
				}
			}
			if(f==-1)
			{
			    printf("�޸ý�ʦ��\n");
			    printf("�Ƿ��������� y/n :");
			    gets(Flag);
			}
			else
			    break;
		}while(strcmp(Flag,"y")==0||strcmp(Flag,"Y")==0);
		if(f==-1)
		{
			system("cls");
			Search(); 
		}
		else
		{
			if(strcmp(tea[f].C_ID,"��")==0)
				printf("�ý�ʦ��δ����γ̣�\n");
			else
				printf("�ý�ʦ���ڿογ̺�%s�Ŀγ� \n",tea[f].C_ID); 
		}
		printf("�Ƿ������ѯ������ʦ��Ϣ y/n��");
		gets(Flag);
    }while(strcmp(Flag,"y")==0||strcmp(Flag,"Y")==0);
    system("cls");
    Search();
}
void Search_Name_S()//���������� 
{
	int i,j,f,n;
	char Mark[20],Flag[5];
	n=load(1);
	int mark[n];
	do
	{
		do
		{
			f=0;
			printf("�����������ѧ��������");
			gets(Mark);
			for(i=0;i<n-1;i++)
			{
				if(strcmp(Mark,stu[i].name)==0)
				{
					mark[f]=i;
					f++;
				}
			}
			if(f==0)
			{
				printf("�޸�ѧ����\n");
			    printf("�Ƿ��������� y/n :");
			    gets(Flag);   
			}
			else
			    break;
		}while(strcmp(Flag,"y")==0||strcmp(Flag,"Y")==0);
		if(f==0)
		{
			system("cls");
			Search1(); 
		}
		else
		{
			printf("����Ϊ%s��ѧ������%d�����ֱ�Ϊ\n",Mark,f);
			for(i=0;i<f;i++)
			{
				printf("��%d��ѧ����\n",i+1);
				printf("����:%s\n",stu[mark[i]].name);
	            printf("�Ա�%s\n",stu[mark[i]].sex);
	            printf("�������ڣ�%s\n",stu[mark[i]].birthday);
	            printf("��ѧʱ�䣺%s\n",stu[mark[i]].time);
	            printf("����Ժϵ��%s\n",tea[mark[i]].courtyard);
	            printf("������ò��%s\n",stu[f].politics);
            }
		}
		printf("�Ƿ������ѯ��ѧ����Ϣ y/n��");
		gets(Flag);
	}while(strcmp(Flag,"y")==0||strcmp(Flag,"Y")==0);
    system("cls");
    Search1();
}
void Search_ID_num()//���֤�Ų�ѯ 
{
	int i,j,f,n;
	char Mark[20],Flag[5];
	n=load(1);
	do
	{
		do
		{
			f=-1;
			printf("�����������ѧ�����֤�ţ�");
			gets(Mark);
			for(i=0;i<n-1;i++)
			{
				if(strcmp(Mark,stu[i].ID)==0)
				f=i;
			}
			if(f==-1)
			{
				printf("�޸�ѧ����\n");
			    printf("�Ƿ��������� y/n :");
			    gets(Flag);   
			}
			else
			    break;
		}while(strcmp(Flag,"y")==0||strcmp(Flag,"Y")==0);
		if(f==-1)
		{
			system("cls");
			Search1(); 
		}
	    else
	    {
	    	printf("������%s\n",stu[f].name);
            printf("��ͥסַ��%s\n",stu[f].site);
            printf("�������룺%s\n",stu[f].post);
            printf("���壺%s\n",stu[f].nation);
            printf("���᣺%s\n",stu[f].place);
		}
		printf("�Ƿ������ѯ��ѧ�������Ϣ y/n��");
		gets(Flag);	
	}while(strcmp(Flag,"y")==0||strcmp(Flag,"Y")==0);
    system("cls");
    Search1();
}
void Search_Graduation_num()//��ҵ֤�Ų�ѯ 
{
	int i,j,f,n;
	char Mark[20],Flag[5];
	n=load(1);
	do
	{
		f=-1;
		do
		{
			printf("������Ҫ��ѯ�ı�ҵ֤�ţ�");
			gets(Mark);
			for(i=0;i<n-1;i++)
			{
				if(strcmp(Mark, stu[i].Diploma_Number)==0)
				f=i;
			} 
			if(f==-1)
			{
				printf("�޸ñ�ҵ֤��Ϣ��\n");
			    printf("�Ƿ��������� y/n :");
			    gets(Flag);   
			}
			else
			 break; 
		}while(strcmp(Flag,"y")==0||strcmp(Flag,"Y")==0);
		if(f==-1)
		{
			system("cls");
			Search1(); 
		}
		else
		{
		  printf("������\n",stu[f].name);
		  printf("ѧ�ţ�\n",stu[f].num);
		  printf("��ѧʱ�䣺\n",stu[f].time);
		  printf("����Ժϵ��\n",stu[f].courtyard);
		  printf("��ҵ֤�ţ�\n",stu[f].Diploma_Number);
		} 
		printf("�Ƿ������ѯy/n :");
        gets(Flag); 
    }while(strcmp(Flag,"y")==0||strcmp(Flag,"Y")==0);
    system("cls");
    Search1();
}
void Search_Course_num()//�γ̺Ų�ѯ 
{
	int i,j,f,n,k;
	char Mark[20],Flag[5];
	n=load(2);
	load(1); 
	int mark[n];
	do
	{
		system("cls");
		f=0;
		do
		{
			printf("������Ҫ��ѯ�����Ϣ�Ŀγ̺ţ�");
			gets(Mark);
			for(j=0;j<5;j++)
			{
				if(strcmp(Mark,stu[0].cou[j].ID)==0)
					k=j;
			}
			for(i=0;i<n-1;i++)
			{
				if(strcmp(Mark,tea[i].C_ID)==0)
				{
					mark[f]=i;
					f++;
				}
			} 
			if(f==0)
			{
				printf("�޸ÿγ̵��ον�ʦ��\n");
			    printf("�Ƿ��������� y/n :");
			    gets(Flag);   
			}
			else
			 break; 
		}while(strcmp(Flag,"y")==0||strcmp(Flag,"Y")==0);
		if(f==0)
		{
			system("cls");
			Search1(); 
		}
	    else
	    {
	    	system("cls");
	    	printf("�ÿγ̵��ον�ʦ�ĸ���Ϊ%d�����ֱ�Ϊ\n",f);
	    	for(i=0;i<f;i++)
	    	{
	    		printf("��%d����ʦ��\n",i+1);
		    	printf("�ÿγ̵Ŀγ���Ϊ��%s\n",stu[0].cou[k].Name);
				printf("�ÿγ̵��ον�ʦ������%s\n",tea[mark[i]].name);
				printf("�ÿγ̵��ον�ʦ�绰��%s\n",tea[mark[i]].phone);
				printf("�ÿγ̵��ον�ʦ�̹��ţ�%s\n",tea[mark[i]].ID);
		    }
		} 
		printf("�Ƿ������ѯy/n :");
		gets(Flag); 
	}while(strcmp(Flag,"y")==0||strcmp(Flag,"Y")==0);
    system("cls");
    Search1();
}
void Search()//��ѯͳ�ƽ��� 
{
	system("cls");
	int a,w;
	do
	{
		puts("\t\t����������������������");
		puts("\t\t��                                      ��");
		puts("\t\t��         1.ѧ��������Ϣ��ѯ           ��");
		puts("\t\t��         2.ѧ�����Գɼ���ѯ           ��");
		puts("\t\t��         3.��ʦ������Ϣ��ѯ           ��");
		puts("\t\t��         4.��ʦ�ο���Ϣ��ѯ           ��");
		puts("\t\t��         5.������ѯ��ʽ               ��");
		puts("\t\t��         6.�ɼ�����                   ��");
		puts("\t\t��         7.��            ��           ��");
		puts("\t\t����������������������");
		printf("��ѡ���������(1-7) : [ ]\b\b");
		scanf("%d",&a);
		getchar();
		if(a<1||a>7)
		{
		    system("cls");
		    printf("ѡ�����!  ������ѡ��!\n");
		    w=1;
		}
		else
		   w=0;
	}while(w==1);
	switch(a)
	{
		case 1:Search_Information_S();break;
		case 2:Search_Grade();break;
		case 3:Search_Information_T();break;
		case 4:Search_Course_T();break;
		case 5:Search1();break;
		case 6:Grade_Sort();break;
		default:system("cls");menu();break; 
	}
}
void Search1()//������ѯ���� 
{
	system("cls");
	int a,w;
	do
	{
		puts("\t\t����������������������");
		puts("\t\t��                                      ��");
		puts("\t\t��            1.ѧ      ��              ��");
		puts("\t\t��            2.��      ��              ��");
		puts("\t\t��            3.���֤��                ��");
		puts("\t\t��            4.��ҵ֤���              ��");
		puts("\t\t��            5.�̹���                  ��");
		puts("\t\t��            6.�γ̺�                  ��");
		puts("\t\t��            7.��      ��              ��");
		puts("\t\t����������������������");
		printf("��ѡ����Ҫ���ҵķ�ʽ(1-7) : [ ]\b\b");
		scanf("%d",&a);
		getchar();
		if(a<1||a>7)
		{
		    system("cls");
		    printf("ѡ�����!  ������ѡ��!\n");
		    w=1;
		}
		else
		   w=0;
	}while(w==1);
	switch(a)
	{
		case 1:Search_Information_S();break;
		case 2:Search_Name_S();break;
		case 3:Search_ID_num();break;
		case 4:Search_Graduation_num();break;
		case 5:Search_Information_T();break;
		case 6:Search_Course_num();break;
		default:system("cls");Search();break;
	}
}
void Grade_Sort()//�ɼ�������� 
{
	system("cls");
	int a,w;
	do
	{
		puts("\t\t����������������������");
		puts("\t\t��                                      ��");
		puts("\t\t��           1.�ܳɼ�����               ��");
		puts("\t\t��                                      ��");
		puts("\t\t��           2.����ƽ���ɼ�����         ��");
		puts("\t\t��                                      ��");
		puts("\t\t��           3.�����ܳɼ�����           ��");
		puts("\t\t��                                      ��");
		puts("\t\t��           4.���ڵ��Ƴɼ�����         ��");
		puts("\t\t��                                      ��");
		puts("\t\t��           5.��          ��           ��");
		puts("\t\t����������������������");
		printf("��ѡ���������(1-5) : [ ]\b\b");
		scanf("%d",&a);
		getchar();
		if(a<1||a>5)
		{
		    system("cls");
		    printf("ѡ�����!  ������ѡ��!\n");
		    w=1;
		}
		else
		   w=0;
	}while(w==1);
	switch(a)
	{
		case 1:Total_Grade_Sort();break;
		case 2:Average_Grade();break;
		case 3:Total_Grade_In();break;
		case 4:Single_Grade_In();break;
		default:system("cls");Search();break;
	}
}
void Total_Grade_Sort()//�ܳɼ�����
{
	system("cls");
	int a,i,j,n,f,k=0,num=0;
	n=load(1);
	struct score s[n],mark;
	for(i=0;i<n-1;i++)
	{
		strcpy(s[i].name,stu[i].name);
		s[i].Class=stu[i].Class;
		s[i].grade=stu[i].cou[0].grade+stu[i].cou[1].grade+stu[i].cou[2].grade+stu[i].cou[3].grade+stu[i].cou[4].grade;
	}
	for(i=0;i<n-2;i++)
		for(j=n-2;j>i;j--)
		{
			if(s[j].grade>s[j-1].grade)
			{
				mark.grade=s[j].grade;
				strcpy(mark.name,s[j].name);
				mark.Class=s[j].Class;
				s[j].grade=s[j-1].grade;
				strcpy(s[j].name,s[j-1].name);
				s[j].Class=s[j-1].Class;
				s[j-1].grade=mark.grade;
				strcpy(s[j-1].name,mark.name);
				s[j-1].Class=mark.Class;
			}
		}
	printf("��ѡ������ʽ��1���Ӵ�С 2����С���󣩣�");
	scanf("%d",&a);
	getchar();
	j=1;
	if(a==1)
		for(i=0;i<n-1;i++)
		{
			if(s[i].grade>=0)
			{
				printf("��%d����",j);
				printf("����%s ",s[i].name);
				printf("�༶%d ",s[i].Class);
				printf("�ܳɼ�Ϊ��%d\n",s[i].grade);
				j++;
		    }
		}
	else
	{
		j=n-1;
	    for(i=n-2;i>=0;i--)
		{
			if(s[i].grade>=0)
			{
				printf("��%d����",j);
				printf("����%s ",s[i].name);
				printf("�༶%d ",s[i].Class);
				printf("�ܳɼ�Ϊ��%d\n",s[i].grade);
				j--;
			}
		}
	}
 } 
void Total_Grade_In()//�����ܳɼ����� 
{
	system("cls");
	int a,i,j,n,f,k=0,num=0;
	n=load(1);
	struct score s[n],mark;
	printf("������Ҫ��ѯ�ܳɼ�����İ�ţ�");
	scanf("%d",&f);
	getchar();
	for(i=0;i<n-1;i++)
	{
		if(stu[i].Class==f)
		{
			strcpy(s[num].name,stu[i].name);
			s[num].grade=stu[i].cou[0].grade+stu[i].cou[1].grade+stu[i].cou[2].grade+stu[i].cou[3].grade+stu[i].cou[4].grade;
			num++;
			k=1;
		}
	}
	if(k!=1)
	{
		printf("�ð༶����ѧ����");
	}
	else
	{
		for(i=0;i<num-1;i++)
			for(j=num-1;j>i;j--)
			{
				if(s[j].grade>s[j-1].grade)
				{
					mark.grade=s[j].grade;
					strcpy(mark.name,s[j].name);
					s[j].grade=s[j-1].grade;
					strcpy(s[j].name,s[j-1].name);
					s[j-1].grade=mark.grade;
					strcpy(s[j-1].name,mark.name);
				}
			}
		printf("��ѡ������ʽ��1���Ӵ�С 2����С���󣩣�");
		scanf("%d",&a);
		getchar();
		j=1;
		if(a==1)
			for(i=0;i<num;i++)
			{
				if(s[i].grade>=0)
				{
					printf("��%d����",j);
					printf("%s ",s[i].name);
					printf("�ܳɼ�Ϊ��%d\n",s[i].grade);
					j++;
				}
			}
		else
		{
			j=num;
		    for(i=num-1;i>=0;i--)
			{
				if(s[i].grade>=0)
				{
					printf("��%d����",num);
					printf("%s ",s[i].name);
					printf("�ܳɼ�Ϊ��%d\n",s[i].grade);
					j--;
				}
			}
		}
	}
}
void Average_Grade()//ƽ���ɼ�����
{
	system("cls");
	int a,i,j,n,f[5],k,num,grade;
	struct score s[5],mark;
	n=load(1);
	for(i=0;i<5;i++)
		f[i]=i+1;
	for(j=0;j<5;j++)
	{
		num=0;
		k=0;
		grade=0;
		for(i=0;i<n-1;i++)
		{
			if(stu[i].Class==f[j])
			{
				s[j].Class=f[j];
				grade+=(stu[i].cou[0].grade+stu[i].cou[1].grade+stu[i].cou[2].grade+stu[i].cou[3].grade+stu[i].cou[4].grade);
				num++;
				k=1;
			}
		}
		if(k!=1)
		{
			s[j].grade=-1;
		}
		else
			s[j].grade=grade/num;
	}
		for(i=0;i<5-1;i++)
			for(j=5-1;j>i;j--)
			{
				if(s[j].grade>s[j-1].grade)
				{
					mark.grade=s[j].grade;
					mark.Class=s[j].Class;
					s[j].grade=s[j-1].grade;
					s[j].Class=s[j-1].Class;
					s[j-1].grade=mark.grade;
					s[j-1].Class=mark.Class;
				}
			}
		printf("��ѡ������ʽ��1���Ӵ�С 2����С���󣩣�");
		scanf("%d",&a);
		getchar();
		j=1;
		if(a==1)
			for(i=0;i<5;i++)
			{
				if(s[i].grade!=-1)
				{
					printf("��%d����",j);
					printf("�༶%d ",s[i].Class);
					printf("ƽ���ɼ�Ϊ��%d\n",s[i].grade);
					j++; 
				}
			}
		else
		    for(i=5-1;i>=0;i--)
			{
				if(s[i].grade!=-1)
				{ 
					printf("��%d����",j);
					printf("�༶%d ",s[i].Class);
					printf("ƽ���ɼ�Ϊ��%d\n",s[i].grade);
					j++;
			    }
			}
 } 
void Single_Grade_In()//���ڵ��Ƴɼ�����
{
	system("cls");
	int a,i,j,n,f,p,k=0,num=0;
	char Mark[20]; 
	n=load(1);
	struct score s[n],mark;
	printf("������Ҫ��ѯ�ɼ�����İ�ţ�");
	scanf("%d",&f);
	getchar();
	Course_Choice();
	printf("������Ͽγ���ѡ����Ҫ��ѯ�ɼ�����Ŀγ̺ţ�");
	gets(Mark);
	for(j=0;j<5;j++)
		if(strcpy(stu[0].cou[j].ID,Mark)==0)
			p=j;
	for(i=0;i<n-1;i++)
	{
		if(stu[i].Class==f)
		{
			strcpy(s[num].name,stu[i].name);
			s[num].grade=stu[i].cou[p].grade;
			num++;
			k=1;
		}
	}
	if(k!=1)
	{
		printf("�ð༶����ѧ����");
	}
	else
	{
		for(i=0;i<num-1;i++)
			for(j=num-1;j>i;j--)
			{
				if(s[j].grade>s[j-1].grade)
				{
					mark.grade=s[j].grade;
					strcpy(mark.name,s[j].name);
					s[j].grade=s[j-1].grade;
					strcpy(s[j].name,s[j-1].name);
					s[j-1].grade=mark.grade;
					strcpy(s[j-1].name,mark.name);
				}
			}
		printf("��ѡ������ʽ��1���Ӵ�С 2����С���󣩣�");
		scanf("%d",&a);
		getchar();
		j=1;
		if(a==1)
			for(i=0;i<num;i++)
			{
				if(s[i].grade>=0)
				{
					printf("��%d����",j);
					printf("%s ",s[i].name);
					printf("�ɼ�Ϊ��%d\n",s[i].grade);
					j++;
				}
			}
		else
		{
			j=num;
		    for(i=num-1;i>=0;i--)
			{
				if(s[i].grade>=0)
				{
					printf("��%d����",i+1);
					printf("%s ",s[i].name);
					printf("�ɼ�Ϊ��%d\n",s[i].grade);
					j--;
				}
			}
		}
	}
 } 
void Modify_Student()//�޸�ѧ����Ϣ 
{
	FILE *fp;
	int i,n,f;
	char Mark[20],Flag[5];
	do
	{
		do
		{
			f=-1;
			n=load(1);
			printf("��������Ҫ�޸ĵ�ѧ����ѧ�ţ�\n");
			gets(Mark);
			for(i=0;i<n-1;i++)
			{
				if(strcmp(Mark,stu[i].num)==0)
				{
					f=i;
					strcpy(Flag,"n");
				} 
		    }
		    if(f==-1) 
		    {
		    	printf("�޸�ѧ����\n");
		    	printf("�Ƿ��������� y/n \n");
			    gets(Flag);
			}	
	    }while(strcmp(Flag,"y")==0||strcmp(Flag,"Y")==0);
	    if(f==-1)
	    {
	    	system("cls");
		    Modify();
		}
		else
		{
			printf("����ѧ��Ϊ%s��ѧ�����Ƿ��޸� y/n\n",stu[f].num);
			gets(Flag);
			if(strcmp(Flag,"y")==0||strcmp(Flag,"Y")==0)
			{
				printf("�޸�����Ϊ��"); 
				gets(stu[f].name);
				printf("�޸��Ա�Ϊ��");
				gets(stu[f].sex);
				printf("�޸ĳ�������Ϊ��");
				gets(stu[f].birthday);
				printf("�޸����֤��Ϊ��");
				gets(stu[f].ID);
				printf("�޸���ѧʱ��Ϊ��");
				gets(stu[f].time);
				printf("�޸�����ԺϵΪ��");
				gets(tea[f].courtyard);
				printf("�޸�������òΪ��");
				gets(stu[f].politics);
				printf("�޸ļ�ͥסַΪ��");
				gets(stu[f].site);
				printf("�޸ļ���Ϊ��");
				gets(stu[f].place);
				printf("�޸��������Ϊ��");
				gets(stu[f].post);
				printf("�޸�����Ϊ��");
				gets(stu[f].nation);
				fp=fopen(FILE_Student,"wb");
		    	for(i=0;i<n-1;i++)
		    	   fwrite(&stu[i],sizeof(struct student),1,fp);
		    	fclose(fp);
		    	printf("�޸ĳɹ���\n");
		    	system("pause");
			}
		}
		printf("�Ƿ�����޸�����ѧ����Ϣ y/n \n");
		gets(Flag);
	}while(strcmp(Flag,"y")==0||strcmp(Flag,"Y")==0);
	system("cls");
	Modify();
}
void Modify_Teacher()//�޸Ľ�ʦ��Ϣ 
{
	FILE *fp;
	int i,n,f;
	char Mark[20],Flag[5];
	do
	{
		do
		{
			f=-1;
			n=load(2);
			printf("��������Ҫ�޸ĵĽ�ʦ�Ľ̹��ţ�\n");
			gets(Mark);
			for(i=0;i<n-1;i++)
			{
				if(strcmp(Mark,tea[i].ID)==0)
				{
					f=i;
					strcpy(Flag,"n");
				}
		    }
		    if(f==-1) 
		    {
		    	printf("�޸ý�ʦ��\n");
		    	printf("�Ƿ��������� y/n \n");
			    gets(Flag);
			}	
	    }while(strcmp(Flag,"y")==0||strcmp(Flag,"Y")==0);
	    if(f==-1)
	    {
	    	system("cls");
		    Modify();
		}
		else
		{
			printf("���ڽ̹���Ϊ%s�Ľ�ʦ���Ƿ��޸� y/n\n",stu[f].num);
			gets(Flag);
			if(strcmp(Flag,"y")==0||strcmp(Flag,"Y")==0)
			{
				printf("�޸�����Ϊ��"); 
				gets(tea[f].name);
				printf("�޸��Ա�Ϊ��");
				gets(tea[f].sex);
				printf("�޸�ְ��Ϊ��"); 
				gets(tea[f].title);
				printf("�޸�����ԺϵΪ��");
				gets(tea[f].courtyard);
				printf("�޸ĵ绰����Ϊ��");
				gets(tea[f].phone);
				fp=fopen(FILE_Teacher,"wb");
		    	for(i=0;i<n-1;i++)
		    	   fwrite(&tea[i],sizeof(struct teacher),1,fp);
		    	fclose(fp);
		    	printf("�޸ĳɹ���\n");
		    	system("pause");
			}
		}
		printf("�Ƿ�����޸�������ʦ��Ϣ y/n \n");
		gets(Flag);
	}while(strcmp(Flag,"y")==0||strcmp(Flag,"Y")==0);
	system("cls");
	Modify();
}
void Modify_Grade()//�޸ĳɼ� 
{
	FILE *fp;
	int i,j,n,f=0,num;
	char Mark[5];
	n=load(1);
	struct student S[n];
	do
	{
		n=load(1);
		printf("��ǰ����%d��ѧ����Ϣ\n",n-1);
		printf("��������Ҫ�޸ĵ�ѧ���ɼ��ĸ�����");
		scanf("%d",&num);
		getchar();
		int flag[num],mark[num];
		printf("������������Ҫ�޸ĳɼ���ѧ����ѧ�ţ�\n");
		for(i=0;i<num;i++)
		{
			printf("��%d��ѧ����ѧ�ţ�",i+1);
			gets(S[i].num);
			flag[i]=-1;
			mark[i]=-1;
		}
		for(j=0;j<num;j++)
		{
			for(i=0;i<n-1;i++)
			{   
				if(strcmp(S[j].num,stu[i].num)==0)
				{
					flag[j]=i;
			    }
			    else
			        mark[j]=i;
			 }
		}
		for(j=0;j<num;j++)
		{
			if(flag[j]!=-1)
			{
				printf("����ѧ��Ϊ%s��ѧ��! \n",stu[flag[j]].num);
				printf("�Ƿ��޸� y/n :");
				gets(Mark);
				if(strcmp(Mark,"y")==0||strcmp(Mark,"Y")==0)
				{
					for(i=0;i<5;i++)
					{
					    printf("�޸�%s�ĳɼ�Ϊ��",stu[flag[j]].cou[i].Name);
					    scanf("%d",&stu[flag[j]].cou[i].grade);
						getchar();
				    }
					fp=fopen(FILE_Student,"wb");
					for(i=0;i<n-1;i++)
					{
						fwrite(&stu[i],sizeof(struct student),1,fp);
					}
					fclose(fp);
					printf("�ɹ��޸�ѧ��Ϊ%s��ѧ���ĳɼ���\n",S[flag[j]].num);
				}
			}
			else
			{
				printf("��ѧ��Ϊ%s��ѧ��! \n",S[mark[j]].num);
				system("pause"); 
			}
	   }		
		printf("�Ƿ�����޸�����ѧ���ĳɼ� y/n: \n");
		gets(Mark) ;
    }while(strcmp(Mark,"y")==0||strcmp(Mark,"Y")==0);
	system("cls");
    Grade();
}
void Modify_Course_T()//�޸Ľ�ʦ�γ�
{
	system("cls");
	FILE *fp;
	int i,n,f;
	char Mark[20],Flag[5];
	do
	{
		do
		{
			f=-1;
			n=load(2);
			printf("��������Ҫ�޸Ŀγ̵Ľ�ʦ�Ľ̹��ţ�");
			gets(Mark);
			for(i=0;i<n-1;i++)
			{
				if(strcmp(Mark,tea[i].ID)==0)
				{
					f=i;
					strcpy(Flag,"n");
				} 
		    }
		    if(f==-1) 
		    {
		    	printf("�޸ý�ʦ��\n");
		    	printf("�Ƿ��������� y/n \n");
			    gets(Flag);
			}	
	    }while(strcmp(Flag,"y")==0||strcmp(Flag,"Y")==0);
	    if(f==-1)
	    {
	    	system("cls");
		    Add_Information2();
		}
		else
		{
			printf("���ڽ̹���Ϊ%s�Ľ�ʦ���Ƿ��޸� y/n\n",stu[f].num);
			gets(Flag);
			if(strcmp(Flag,"y")==0||strcmp(Flag,"Y")==0)
			{
				Course_Choice();
				printf("������Ͽγ�ѡ���޸�\n");
				printf("�޽�ʦ���ογ�Ϊ��");
				gets(tea[f].C_ID);
				fp=fopen(FILE_Teacher,"wb");
		    	for(i=0;i<n-1;i++)
		    	   fwrite(&tea[i],sizeof(struct teacher),1,fp);
		    	fclose(fp);
		    	printf("�޸ĳɹ���\n");
		    	system("pause");
			}
		}
		printf("�Ƿ�����޸�������ʦ�Ŀγ� y/n \n");
		gets(Flag);
    }while(strcmp(Flag,"y")==0||strcmp(Flag,"Y")==0);
    system("cls");
	Add_Information2();
}
void Modify_Class_S()//ѧ���༶�޸�
{
	FILE *fp;
	int i,n,f,k;
	char Mark[20],Flag[5];
	do
	{
		do
		{
			f=-1;
			n=load(1);
			printf("��������Ҫ�޸ĵ�ѧ����ѧ�ţ�\n");
			gets(Mark);
			for(i=0;i<n-1;i++)
			{
				if(strcmp(Mark,stu[i].num)==0)
				{
					f=i;
					strcpy(Flag,"n");
				} 
		    }
		    if(f==-1) 
		    {
		    	printf("�޸�ѧ����\n");
		    	printf("�Ƿ��������� y/n \n");
			    gets(Flag);
			}	
	    }while(strcmp(Flag,"y")==0||strcmp(Flag,"Y")==0);
	    if(f==-1)
	    {
	    	system("cls");
		    Class();
		}
		else
		{
			printf("����ѧ��Ϊ%s��ѧ�����Ƿ��޸� y/n\n",stu[f].num);
			gets(Flag);
			if(strcmp(Flag,"y")==0||strcmp(Flag,"Y")==0)
			{
				printf("������༶�ţ�1-5����");
				scanf("%d",&k);
				getchar();
				stu[f].Class=k;
				fp=fopen(FILE_Student,"wb");
		    	for(i=0;i<n-1;i++)
		    	   fwrite(&stu[i],sizeof(struct student),1,fp);
		    	fclose(fp);
		    	printf("�޸ĳɹ���\n");
		    	system("pause");
			}
		}
		printf("�Ƿ�����޸�����ѧ���İ༶ y/n \n");
		gets(Flag);
	}while(strcmp(Flag,"y")==0||strcmp(Flag,"Y")==0);
	system("cls");
    Class();
} 
void Modify_Class_T()//��ʦ�༶�޸�
{
	FILE *fp,*fp1;
	int a,i,j,n,f,k,num;
	char Mark[20],Flag[5];
	do
	{
		a=load(1);
		n=load(2);
		num=0; 
		int mark[a];
		do
		{
			f=-1;
			printf("��������Ҫ�޸ĵĽ�ʦ�Ľ̹��ţ�\n");
			gets(Mark);
			for(i=0;i<n-1;i++)
			{
				if(strcmp(Mark,tea[i].ID)==0)
				{
					f=i;
					strcpy(Flag,"n");
				} 
		    }
		    if(f==-1) 
		    {
		    	printf("�޸ý�ʦ��\n");
		    	printf("�Ƿ��������� y/n \n");
			    gets(Flag);
			}	
	    }while(strcmp(Flag,"y")==0||strcmp(Flag,"Y")==0);
	    if(f==-1)
	    {
	    	system("cls");
		    Class();
		}
		else
		{
			printf("����ѧ��Ϊ%s�Ľ�ʦ���Ƿ��޸� y/n\n",stu[f].num);
			gets(Flag);
			if(strcmp(Flag,"y")==0||strcmp(Flag,"Y")==0)
			{
				printf("������༶�ţ�1-5����");
				scanf("%d",&k);
				getchar();
				for(i=0;i<a-1;i++)
				{
					if(stu[i].Class==k)
					{
						mark[num]=i;
						num++;
					}
				}
				if(num==0)
				{
					printf("�ð�����ѧ����\n");
				}
				else
				{
					for(i=0;i<5;i++)
					{
						if(strcmp(tea[f].C_ID,stu[mark[0]].cou[i].ID)==0)
							j=i;
					}
					if(strcmp(stu[mark[0]].cou[j].Mark,"��")!=0)
					{
						printf("�ð��%s�γ�������ʦ�ڿΣ�\n",stu[mark[0]].cou[j].Name);
					}
					else
					{
						tea[f].Class=k;
						for(i=0;i<num-1;i++)
						{
							strcpy(stu[mark[i]].cou[j].Mark,tea[f].ID);
						}
						fp=fopen(FILE_Student,"wb");
						for(i=0;i<a-1;i++)
						{
							fwrite(&stu[i],sizeof(struct student),1,fp);
						}
						fclose(fp);
						fp1=fopen(FILE_Teacher,"wb");
						for(i=0;i<n-1;i++)
						{
							fwrite(&tea[i],sizeof(struct teacher),1,fp1);
						}
						fclose(fp1);
			    	    printf("�޸ĳɹ���\n");
			    	    system("pause");
			    	}
		        }
			}
		}
		printf("�Ƿ�����޸�����ѧ���İ༶ y/n \n");
		gets(Flag);
	}while(strcmp(Flag,"y")==0||strcmp(Flag,"Y")==0);
	system("cls");
	Class();
 } 
void Modify()//�޸Ľ��� 
{
	system("cls");
	int w,m1;
	do
	{
		puts("\t\t����������������������");
	    puts("\t\t��                                      ��");
	    puts("\t\t��           1.�޸�ѧ����Ϣ             ��");
	    puts("\t\t��                                      ��");
	    puts("\t\t��           2.�޸Ľ�ʦ��Ϣ             ��");
	    puts("\t\t��                                      ��");
	    puts("\t\t��           3.��        ��             ��");
	    puts("\t\t����������������������");
		printf("��ѡ����Ҫ�޸ĵ���Ϣ����(1-3) : [ ]\b\b");
		scanf("%d",&m1);
		getchar();
		if(m1<1||m1>3)
	    {
		    system("cls");
		    printf("ѡ�����!  ������ѡ��!\n");
		    w=1;
	    }
	   else
		   w=0;
    }while(w==1);
    switch(m1)
    {
    	case 1:Modify_Student();break;
    	case 2:Modify_Teacher();break;
    	default:system("cls");Add();break;
	}
}
void Delete_Student()//ɾ��ѧ����Ϣ 
{
	FILE *fp;
	int i,j,n,num;
	char Mark[5];
	n=load(1);
	struct student S[n];
	do
	{
		n=load(1);
		printf("��ǰ����%d��ѧ����Ϣ\n",n-1);
		printf("��������Ҫɾ����ѧ���ĸ�����");
		scanf("%d",&num);
		getchar();
		int flag[num],mark[num];
		printf("������������Ҫɾ����ѧ����ѧ�ţ�\n");
		for(i=0;i<num;i++)
		{
			printf("��%d��ѧ����ѧ�ţ�",i+1);
			gets(S[i].num);
			flag[i]=-1;
			mark[i]=-1;
		}
		for(j=0;j<num;j++)
		{
			for(i=0;i<n-1;i++)
			{   
				if(strcmp(S[j].num,stu[i].num)==0)
				{
					flag[j]=j;
			    }
			    else
			        mark[j]=j;
			 }
		}
		for(j=0;j<num;j++)
		{
			if(flag[j]!=-1)
			{
				printf("����ѧ��Ϊ%s��ѧ��! \n",S[flag[j]].num);
				printf("�Ƿ�ɾ�� y/n :");
				gets(Mark);
				if(strcmp(Mark,"y")==0||strcmp(Mark,"Y")==0)
				{
					fp=fopen(FILE_Student,"wb");
					for(i=0;i<n-1;i++)
					{
						if(strcmp(S[flag[j]].num,stu[i].num)!=0)
						{
							fwrite(&stu[i],sizeof(struct student),1,fp);
						}
					}
					fclose(fp);
					printf("�ɹ�ɾ��ѧ��Ϊ%s��ѧ����\n",S[flag[j]].num);
				}
			}
			else
			{
				printf("��ѧ��Ϊ%s��ѧ��! \n",S[mark[j]].num);
				system("pause"); 
			}
	   }		
		printf("�Ƿ����ɾ������ѧ����Ϣ y/n \n");
		gets(Mark) ;
    }while(strcmp(Mark,"y")==0||strcmp(Mark,"Y")==0);
	system("cls");
    Delete();
}
void Delete_Teacher()//ɾ����ʦ��Ϣ 
{
	FILE *fp;
	int i,j,n,num;
	char Mark[5];
	n=load(2);
	struct teacher T[n];
	do
	{
		n=load(2);
		printf("��ǰ����%d����ʦ��Ϣ\n",n-1);
		printf("��������Ҫɾ���Ľ�ʦ�ĸ�����");
		scanf("%d",&num);
		getchar();
		int flag[num],mark[num];
		printf("������������Ҫɾ���Ľ�ʦ�Ľ̹��ţ�\n");
		for(i=0;i<num;i++)
		{
			printf("��%d����ʦ�Ľ̹��ţ�",i+1);
			gets(T[i].ID);
			flag[i]=-1;
			mark[i]=-1;
		}
		for(j=0;j<num;j++)
		{
			for(i=0;i<n-1;i++)
			{   
				if(strcmp(T[j].ID,tea[i].ID)==0)
				{
					flag[j]=j;
			    }
			    else
			        mark[j]=j;
			 }
		}
		for(j=0;j<num;j++)
		{
			if(flag[j]!=-1)
			{
				printf("���ڽ̹���Ϊ%s�Ľ�ʦ! \n",T[flag[j]].ID);
				printf("�Ƿ�ɾ�� y/n :");
				gets(Mark);
				if(strcmp(Mark,"y")==0||strcmp(Mark,"Y")==0)
				{
					fp=fopen(FILE_Teacher,"wb");
					for(i=0;i<n-1;i++)
					{
						if(strcmp(T[flag[j]].ID,tea[i].ID)!=0)
						{
							fwrite(&tea[i],sizeof(struct teacher),1,fp);
						}
					}
					fclose(fp);
					printf("�ɹ�ɾ���̹���Ϊ%s�Ľ�ʦ��\n",T[flag[j]].ID);
				}
			}
			else
			{
				printf("�޽̹���Ϊ%s�Ľ�ʦ! \n",T[mark[j]].ID);
				system("pause"); 
			}
	   }		
		printf("�Ƿ����ɾ��������ʦ��Ϣ y/n \n");
		gets(Mark) ;
    }while(strcmp(Mark,"y")==0||strcmp(Mark,"Y")==0);
	system("cls");
    Delete();
}
void Delete_Grade()//ɾ���ɼ� 
{
	FILE *fp;
	int i,j,n,num;
	char Mark[5];
	n=load(1);
	struct student S[n];
	do
	{
		n=load(1);
		printf("��ǰ����%d��ѧ����Ϣ\n",n-1);
		printf("��������Ҫɾ��ѧ���ɼ��ĸ�����");
		scanf("%d",&num);
		getchar();
		int flag[num],mark[num];
		printf("������������Ҫɾ���ɼ���ѧ����ѧ�ţ�\n");
		for(i=0;i<num;i++)
		{
			printf("��%d��ѧ����ѧ�ţ�",i+1);
			gets(S[i].num);
			flag[i]=-1;
			mark[i]=-1;
		}
		for(j=0;j<num;j++)
		{
			for(i=0;i<n-1;i++)
			{   
				if(strcmp(S[j].num,stu[i].num)==0)
				{
					flag[j]=i;
			    }
			    else
			        mark[j]=i;
			 }
		}
		for(j=0;j<num;j++)
		{
			if(flag[j]!=-1)
			{
				printf("����ѧ��Ϊ%s��ѧ��! \n",stu[flag[j]].num);
				printf("�Ƿ�ɾ�� y/n :");
				gets(Mark);
				if(strcmp(Mark,"y")==0||strcmp(Mark,"Y")==0)
				{
					for(i=0;i<5;i++)
					{
						stu[flag[j]].cou[i].grade=-1;
					}
					fp=fopen(FILE_Student,"wb");
					for(i=0;i<n-1;i++)
					{
						fwrite(&stu[i],sizeof(struct student),1,fp);
					}
					fclose(fp);
					printf("�ɹ�ɾ��ѧ��Ϊ%s��ѧ����\n",stu[flag[j]].num);
				}
			}
			else
			{
				printf("��ѧ��Ϊ%s��ѧ��! \n",stu[mark[j]].num);
				system("pause"); 
			}
	   }		
		printf("�Ƿ����ɾ������ѧ�� y/n \n");
		gets(Mark) ;
    }while(strcmp(Mark,"y")==0||strcmp(Mark,"Y")==0);
	system("cls");
    Grade();
}
void Delete_Course_T()//ɾ����ʦ�γ�
{
	FILE *fp;
	int i,j,n,num;
	char Mark[5];
	n=load(2);
	struct teacher T[n];
	do
	{
		n=load(2);
		printf("��ǰ����%d����ʦ��Ϣ\n",n-1);
		printf("��������Ҫɾ���Ľ�ʦ�ĸ�����");
		scanf("%d",&num);
		getchar();
		int flag[num],mark[num];
		printf("������������Ҫɾ���Ľ�ʦ�Ľ̹��ţ�\n");
		for(i=0;i<num;i++)
		{
			printf("��%d����ʦ�Ľ̹��ţ�",i+1);
			gets(T[i].ID);
		}
		for(j=0;j<num;j++)
		{
			for(i=0;i<n-1;i++)
			{   
				if(strcmp(T[j].ID,tea[i].ID)==0)
				{
					flag[j]=i;
			    }
			    else
			        mark[j]=j;
			 }
		}
		for(j=0;j<num;j++)
		{
			if(flag[j]!=0)
			{
				printf("���ڽ̹���Ϊ%s�Ľ�ʦ! \n",tea[flag[j]].ID);
				printf("�Ƿ�ɾ�� y/n :");
				gets(Mark);
				if(strcmp(Mark,"y")==0||strcmp(Mark,"Y")==0)
				{
					strcpy(tea[flag[j]].C_ID,"��");
					fp=fopen(FILE_Teacher,"wb");
					for(i=0;i<n-1;i++)
					{
						fwrite(&tea[i],sizeof(struct teacher),1,fp);
					}
					fclose(fp);
					printf("�ɹ�ɾ���̹���Ϊ%s�Ľ�ʦ�Ŀγ̣�\n",tea[flag[j]].ID);
				}
			}
			else
			{
				printf("�޽̹���Ϊ%s�Ľ�ʦ! \n",T[mark[j]].ID);
				system("pause"); 
			}
	   }		
		printf("�Ƿ����ɾ��������ʦ�Ŀγ� y/n \n");
		gets(Mark) ;
    }while(strcmp(Mark,"y")==0||strcmp(Mark,"Y")==0);
	system("cls");
    Add_Information2();
 } 
void Delete()//ɾ������ 
{
	system("cls");
	int w,m1;
	do
	{
		puts("\t\t����������������������");
	    puts("\t\t��                                      ��");
	    puts("\t\t��           1.ɾ��ѧ����Ϣ             ��");
	    puts("\t\t��                                      ��");
	    puts("\t\t��           2.ɾ����ʦ��Ϣ             ��");
	    puts("\t\t��                                      ��");
	    puts("\t\t��           3.��        ��             ��");
	    puts("\t\t����������������������");
		printf("��ѡ����Ҫɾ������Ϣ����(1-3) : [ ]\b\b");
		scanf("%d",&m1);
		getchar();
		if(m1<1||m1>3)
	    {
		    system("cls");
		    printf("ѡ�����!  ������ѡ��!\n");
		    w=1;
	    }
	   else
		   w=0;
    }while(w==1);
    switch(m1)
    {
    	case 1:Delete_Student();break;
    	case 2:Delete_Teacher();break;
    	default:system("cls");Add();break;
	}
}
void Graduate_Judgement()//��ҵ�ж�
{
	FILE *fp;
	int i,j,n,f;
	char Mark[20],Flag[5];
	n=load(1);
	if(m==3)
	{
		Credit_Judgment();
		do
		{
			f=-1; 
			printf("������ѧ����ѧ�ţ�");
			gets(Mark);
			for(i=0;i<n-1;i++)
			{
				if(strcmp(Mark,stu[i].num)==0)
				{
					f=i;
				}
			}
			if(f==-1)
			{
				printf("�޸�ѧ����");
			}
			else
			{
				if(strcmp(stu[f].Diploma_Number,"��")==0)
				{
					if(stu[f].Revised_credits>=stu[f].Required_credits)
					{
						printf("���������ҵ������");
						printf("���������ҵ֤��ţ�");
						gets(stu[f].Diploma_Number);
						fp=fopen(FILE_Student,"wb");
						for(i=0;i<n-1;i++)
						{
							fwrite(&stu[i],sizeof(struct student),1,fp);
						}
						fclose(fp);
						printf("¼��ɹ���");
					}
					else
					    printf("�����������ҵ������");
				}
				else
					printf("������¼���ҵ֤��ţ�");
			}
			printf("�Ƿ���� y/n \n");
			gets(Flag) ;
	    }while(strcmp(Flag,"y")==0||strcmp(Flag,"Y")==0);
	}
	else
    {
    	printf("��û��Ȩ�ޣ�\n");
		system("pause");
		system("cls");
		Graduate_Imformation();
    }
	system("cls");
	Graduate_Imformation();
 } 
void Search_Gradute()//��ҵ��Ϣ��ѯ
{
	int i,j,n,f;
	char Mark[20],Flag[5];
	n=load(1);
	do
	{
		do
		{
			f=-1;
			printf("��������Ҫ��ѯ��ѧ�ţ�");
			gets(Mark);
			for(i=0;i<n-1;i++)
			{
				if(strcmp(Mark,stu[i].num)==0)
				{
					f=i;
				}
			}
			if(f==-1)
			{
			    printf("�޸�ѧ����\n");
			    printf("�Ƿ��������� y/n :");
			    gets(Flag);
			}
			else
			    break;
		}while(strcmp(Flag,"y")==0||strcmp(Flag,"Y")==0);
		if(f==-1)
		{
			system("cls");
			Graduate_Imformation();
		}
		else
		{
			if(strcmp(stu[f].Diploma_Number,"��")==0)
			{
				printf("��ѧ��δ¼���ҵ֤��ţ�\n");
			}
			else
			{
				printf("��ҵ֤���Ϊ��");
				puts(stu[f].Diploma_Number);
			}
		}
		printf("�Ƿ������ѯ����ѧ�� y/n :");
		gets(Flag);
    }while(strcmp(Flag,"y")==0||strcmp(Flag,"Y")==0);
	system("cls");
	Graduate_Imformation();
 } 
void Graduate_Imformation()//��ҵ����Ϣ�������
{
	system("cls");
	int a,w;
	do
	{
		puts("\t\t����������������������");
		puts("\t\t��                                      ��");
		puts("\t\t��            1.��ҵ�������            ��");
		puts("\t\t��                                      ��");
		puts("\t\t��            2.��ҵ��Ϣ��ѯ            ��");
		puts("\t\t��                                      ��");
		puts("\t\t��            3.��        ��           ��");
		puts("\t\t����������������������");
		printf("��ѡ����Ҫ���ҵķ�ʽ(1-3) : [ ]\b\b");
		scanf("%d",&a);
		getchar();
		if(a<1||a>3)
		{
		    system("cls");
		    printf("ѡ�����!  ������ѡ��!\n");
		    w=1;
		}
		else
		   w=0;
	}while(w==1);
	switch(a)
	{
		case 1:Graduate_Judgement();break;
		case 2:Search_Gradute();break;
		default:system("cls");menu();break;
	 } 
 } 
void Login()//��¼ע�� 
{
	int a,i;
	char Mark[20];
	printf("���������Ա��֤�룺");
	for(i=0;i<20;i++)
	{
		Mark[i]=getch();
		if(Mark[i]=='\r')
			break;
		printf("*");
	}
	Mark[i]='\0';
	if(strcmp(Mark,"060809")==0)
	{
		system("cls");
		printf("��֤�ɹ�\n");
		m=3;
	}
	else
	{
		system("cls");
		printf("��֤�����\n");
	}
	system("pause");
	system("cls");
	menu();
 } 
void exit()//�˳� 
{
	printf("��ӭ�´�ʹ��!");
	exit(0);
}
void face()//����ҳ��
{
	printf("\n\t    �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� ��\n\n");
	puts("\t    ������������������������������������������������������");
	puts("\t    ����                                              ����");
	puts("\t    ����                                              ����");
	puts("\t    ����                                              ����");
	puts("\t    ����                                              ����");
	puts("\t    ����           ��ӭ����ѧ��ѧ������ϵͳ!          ����");
	puts("\t    ����                                              ����");
	puts("\t    ����                                              ����");
	puts("\t    ����                                              ����");
	puts("\t    ����                                              ����");
    puts("\t    ����                                              ����");
	puts("\t    ������������������������������������������������������");
	printf("\n\tPress [ Enter ] key to continue����\n");
	getchar();
	system("cls");
}
void menu()//���˵� 
{
	system("cls");
	int n,n1,w1,w2;
	if(m==-1)
	{
	    do
		{
		   printf("\n\t\t\t��ӭʹ��ѧ��ѧ������ϵͳ!\n");
	       printf("\n");
		   puts("\t\t����������  �˵�  ���������");
		   puts("\t\t��               1.��  ��               ��");
		   puts("\t\t��                                      ��");
		   puts("\t\t��               2.����Ա               ��");
		   puts("\t\t��                                      ��");
		   puts("\t\t��               3.��  ��               ��");
		   puts("\t\t����������������������");
		   printf("��ѡ��ʹ������(1-3) : [ ]\b\b");
		   scanf("%d",&n);
		   if(n<1||n>3)
		   {
			   system("cls");
			   printf("ѡ�����!  ������ѡ��!\n");
			   w1=1;
		   }
		   else
			   w1=0;
		}while(w1==1);
		system("cls");
		switch(n)
		{
			case 1:m=1;break;
			case 2:Login();break;
			default:exit();break;
		 } 
    }
	if(m!=-1)
	{
		do
		{
		   puts("\t\t����������  �˵�  ���������");
		   puts("\t\t��           1.������Ϣ����             ��");
		   puts("\t\t��           2.ѧ���ɼ�����             ��");
		   puts("\t\t��           3.�༶��Ϣ����             ��");
		   puts("\t\t��           4.��Ϣ��ѯͳ��             ��");
		   puts("\t\t��          5.��ҵ����Ϣ����            ��");
		   puts("\t\t��           6.��        ��             ��");
		   puts("\t\t��           7.��        ��             ��");
		   puts("\t\t����������������������");
		   printf("��ѡ���������(1-7) : [ ]\b\b");
		   scanf("%d",&n1);
		   if(n1<1||n1>7)
		   {
			   system("cls");
			   printf("ѡ�����!  ������ѡ��!\n");
			   w2=1;
		   }
		   else
			   w2=0;
		}while(w2==1);
		system("cls");
		switch(n1)
		{
			case 1:Add();break;
			case 2:Grade();break;
			case 3:Class();break;
			case 4:Search();break;
			case 5:Graduate_Imformation();break;
			case 6:m=-1;menu();break; 
			default:exit();break;
		}
	}
}
main()
{
	face();
	menu();	
 } 
