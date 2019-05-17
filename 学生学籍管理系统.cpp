#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#define FILE_Student "学生.txt"
#define FILE_Teacher "教师.txt"
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
	char ID[20];//课程号 
	char Name[20];//课程名 
	int grade;//成绩
	char Mark[20];
};
struct student{
	char num[20];//学号
	char name[20];//姓名
	char sex[10];//性别
	char birthday[30];//出生日期
	char ID[30];//身份证
	char time[20];//入学时间
	char courtyard[20];//所属院系
	char politics[20];//政治面貌
	char site[20];//家庭住址
	char place[20];//籍贯
	char post[20];//邮政编码
	char nation[20];//民族
	int Class;//班级
	int Required_credits;//需修学分
	int Revised_credits;//已修学分
	char Diploma_Number[20];//毕业证书编号
	struct course cou[5];
}stu[N];
struct teacher{
	char ID[20];//教工号
	char name[20];//姓名
	char sex[20];//性别
	char title[20];//职称
	char courtyard[20];//所属院系
	char phone[20];//电话号码
	char C_ID[20];//课程号
	int Class;//班级 
}tea[N];
void Course_Choice()//课程选择界面
{
	puts("\t\t★★★★★★★★★★★★★★★★★★★★★");
    puts("\t\t★       课程名         课程号          ★");
    puts("\t\t★       语  文         J10001          ★");
    puts("\t\t★       微积分         J10002          ★");
    puts("\t\t★       英  语         J10003          ★");
    puts("\t\t★       C 语言         J10004          ★");
    puts("\t\t★        JAVA          J10005          ★");
    puts("\t\t★★★★★★★★★★★★★★★★★★★★★");
} 
int load(int m1) //打开文件,读取里面的数据 
{
	FILE *fp,*fp1,*fp2;
    int i;
    if(m1==1)
    {
		if((fp=fopen(FILE_Student,"rb"))==NULL) //读入空文件，rb表示打开一个二进制文件，只允许读数据
		{
			printf("\n文件不存在!请输入:\n");
	        return 0;
		}
	    for(i=0;!feof(fp);i++)  //处理到文件结尾
	       fread(&stu[i],sizeof(struct student),1,fp);
	    fclose(fp);
	    return i;
   }
    else if(m1==2)
    {
	    if((fp1=fopen(FILE_Teacher,"rb"))==NULL) /*读入空文件，rb表示打开一个二进制文件，只允许读数据*/
		{
			printf("\n文件不存在!请输入:\n");
	        return 0;
		}
	    for(i=0;!feof(fp1);i++)  /*处理到文件结尾*/
	       fread(&tea[i],sizeof(struct teacher),1,fp1);
	    fclose(fp1);
	    return i;
    } 
}
void save(int n,int m1) //保存信息
{
	FILE *fp,*fp1,*fp2;
	int i,a;
	a=load(m1);
    if(m1==1)
	{
		if((fp=fopen(FILE_Student,"ab"))==NULL) //只打开或建立一个二进制文件，只允许写数据
		{
			printf("\nCan not open file!\n");
		}
	    for(i=a;i<n+a;i++)
	      //if(stu[i].name[0]!='\0')
	         if(fwrite(&stu[i],sizeof(struct student),1,fp)!=1) //将一批数据作为一个整体一次性写入磁盘文件
	            printf("文件写入错误!\n");
	    fclose(fp);
    }
    else if(m1==2)
    {
		if((fp1=fopen(FILE_Teacher,"ab"))==NULL) /*只打开或建立一个二进制文件，只允许写数据*/
		{
			printf("\nCan not open file!\n");
		}
	    for(i=a;i<n+a;i++)
	      //if(stu[i].name[0]!='\0')
	         if(fwrite(&tea[i],sizeof(struct teacher),1,fp1)!=1) /*将一批数据作为一个整体一次性写入磁盘文件*/
	            printf("文件写入错误!\n");
	    fclose(fp1);
    }
}
void Add() //基本信息界面界面 
{
	system("cls");
	int n,w;
	if(m==3)
	{
		do
		{
			puts("\t\t★★★★★★★★★★★★★★★★★★★★★");
		    puts("\t\t★                                      ★");
		    puts("\t\t★           1.基本信息录入             ★");
		    puts("\t\t★                                      ★");
		    puts("\t\t★           2.教师课程管理             ★");
		    puts("\t\t★                                      ★");
		    puts("\t\t★           3.基本信息删除             ★");
		    puts("\t\t★                                      ★");
		    puts("\t\t★           4.基本信息修改             ★");
		    puts("\t\t★                                      ★");
		    puts("\t\t★           5.返        回             ★");
		    puts("\t\t★★★★★★★★★★★★★★★★★★★★★");
			printf("请选择服务类型(1-5) : [ ]\b\b");
			scanf("%d",&n);
			getchar();
			if(n<1||n>5)
		    {
			    system("cls");
			    printf("选择错误!  请重新选择!\n");
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
    	printf("你没有权限！\n");
		system("pause");
		system("cls");
		menu();
    }
}
void Grade()//成绩界面 
{
	system("cls");
	if(m==3)
	{
		int n,w;
		do
		{
			puts("\t\t★★★★★★★★★★★★★★★★★★★★★");
		    puts("\t\t★                                      ★");
		    puts("\t\t★             1.成绩录入               ★");
		    puts("\t\t★                                      ★");
		    puts("\t\t★             2.成绩删除               ★");
		    puts("\t\t★                                      ★");
		    puts("\t\t★             3.成绩修改               ★");
		    puts("\t\t★                                      ★");
		    puts("\t\t★             4.返    回               ★");
		    puts("\t\t★★★★★★★★★★★★★★★★★★★★★");
			printf("请选择服务类型(1-4) : [ ]\b\b");
			scanf("%d",&n);
			getchar();
			if(n<1||n>4)
		    {
			    system("cls");
			    printf("选择错误!  请重新选择!\n");
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
		printf("你没有权限！\n");
		system("pause");
		system("cls");
		menu();
	}
 } 
void Add_Grade()//成绩录入 
{
	FILE *fp;
	int i,j,n,f,num;
	char Mark[20],Flag[5];
	n=load(1);
	struct student S[n];
	do
	{
		printf("请输入你要录入成绩的学生的个数：");
		scanf("%d",&num);
		getchar();
		int flag[num],mark[num];
		printf("请依次输入你要录入成绩的学生的学号：\n");
		for(i=0;i<num;i++)
		{
			printf("第%d个学生的学号：",i+1);
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
				printf("存在学号为%s的学生! \n",stu[flag[j]].num);
				printf("是否录入其成绩 y/n :");
				gets(Mark);
				if(strcmp(Mark,"y")==0||strcmp(Mark,"Y")==0)
				{
					for(i=0;i<5;i++)
					{
						if(stu[flag[j]].cou[i].grade!=-1)
						{
							printf("%s成绩已存在，是否修改 y/n: ",stu[flag[j]].cou[i].Name);
							gets(Mark);
							if(strcmp(Mark,"n")==0||strcmp(Mark,"N")==0)
							    continue;
						}
					    printf("%s成绩：",stu[flag[j]].cou[i].Name);
					    scanf("%d",&stu[flag[j]].cou[i].grade);
						getchar();
				    }
					if((fp=fopen(FILE_Student,"wb"))==NULL) //只打开或建立一个二进制文件，只允许写数据
					{
						printf("\nCan not open file!\n");
					}
				    for(i=0;i<n-1;i++)
				      //if(stu[i].name[0]!='\0')
				         if(fwrite(&stu[i],sizeof(struct student),1,fp)!=1) //将一批数据作为一个整体一次性写入磁盘文件
				            printf("文件写入错误!\n");
				    fclose(fp);
					printf("成功录入学号为%s的学生的成绩！\n",stu[flag[j]].num);
				}
			}
			else
			{
				printf("无学号为%s的学生! \n",S[mark[j]].num);
				system("pause"); 
			}
	   }
		printf("是否继续录入其他学生的成绩 y/n");
		gets(Flag);  
    }while(strcmp(Flag,"y")==0||strcmp(Flag,"Y")==0);
    system("cls");
    Grade();
}
void Credit_Judgment()//学分判断 
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
void Add_Student()//添加学生信息 
{
	int i,j,n,a,k,p,f;
	char Mark[5];
	do
	{
		system("cls");
		n=load(1);
		f=1;
		printf("请输入你要添加的学生信息的个数：");
		scanf("%d",&a);
		getchar();
		for(i=n;i<n+a;i++)
		{
			printf("第%d个学生\n",f);
	    	printf("学号：");
			gets(stu[i].num);
			for(k=0;k<n-1;k++)
			{
				if(strcmp(stu[k].num,stu[i].num)==0)
				{
					printf("学号重复！请重新输入...\n");
					p=1;
					i--;
					break;
				}
				else
				   p=0;
			}
			if(p==1) continue;
			printf("姓名："); 
			gets(stu[i].name);
			printf("性别：");
			gets(stu[i].sex);
			printf("出生日期：");
			gets(stu[i].birthday);
			printf("身份证号：");
			gets(stu[i].ID);
			printf("入学时间：");
			gets(stu[i].time);
			printf("所属院系：");
			gets(tea[i].courtyard);
			printf("政治面貌：");
			gets(stu[i].politics);
			printf("家庭住址：");
			gets(stu[i].site);
			printf("籍贯：");
			gets(stu[i].place);
			printf("邮政编号：");
			gets(stu[i].post);
			printf("民族：");
			gets(stu[i].nation);
			stu[i].Class=-1; 
		    stu[i].Required_credits=15;
		    stu[i].Revised_credits=0;
			strcpy(stu[i].Diploma_Number,"无");
			for(j=0;j<5;j++)
			{
				stu[i].cou[j].grade=-1;
				strcpy(stu[i].cou[j].Mark,"无");
			}
			strcpy(stu[i].cou[0].Name,"语文");
			strcpy(stu[i].cou[0].ID,"J10001");
			strcpy(stu[i].cou[1].Name,"微积分");
			strcpy(stu[i].cou[1].ID,"J10002");
			strcpy(stu[i].cou[2].Name,"英语");
			strcpy(stu[i].cou[2].ID,"J10003");
			strcpy(stu[i].cou[3].Name,"C语言");
			strcpy(stu[i].cou[3].ID,"J10004");
			strcpy(stu[i].cou[4].Name,"JAVA");
			strcpy(stu[i].cou[4].ID,"J10005");
			f++;
			system("cls");
		}
		save(a,1);
		printf("添加成功！\n");
		printf("是否继续添加其他学生 y/n \n");
		gets(Mark) ;
    }while(strcmp(Mark,"y")==0||strcmp(Mark,"Y")==0);
	system("cls");
    Add_Information1();
 } 
void Add_Teacher()//添加教师信息 
{
	int i,n,a,k,p,f;
	char Mark[5];
	do
	{
		system("cls"); 
		n=load(2);
		f=1;
		printf("请输入你要你要添加的教师信息的个数：");
		scanf("%d",&a);
		getchar();
		for(i=n;i<n+a;i++)
		{
			printf("第%d个教师\n",f);
			printf("教工号：");
			gets(tea[i].ID);
			for(k=0;k<n;k++)
			{
				if(strcmp(tea[k].ID,tea[i].ID)==0)
				{
					printf("教工号重复！请重新输入...");
					p=1;
					i--;
					break;
				}
				else
				   p=0;
			}
			if(p==1) continue;
			printf("姓名："); 
			gets(tea[i].name);
			printf("性别：");
			gets(tea[i].sex);
			printf("职称："); 
			gets(tea[i].title);
			printf("所属院系：");
			gets(tea[i].courtyard);
			printf("电话号码：");
			gets(tea[i].phone);
			strcpy(tea[i].C_ID,"无");
			f++;
			system("cls");
		}
		save(a,2);
		printf("添加成功！\n");
		printf("是否继续添加他教师 y/n \n");
		gets(Mark) ;
    }while(strcmp(Mark,"y")==0||strcmp(Mark,"Y")==0);
	system("cls");
    Add_Information1();
}
void Add_Class()//学生班级分配 
{
	FILE *fp;
	int i,j,n,f,k,num;
	char Mark[20],Flag[5];
	struct student S[n];
	do
	{
		n=load(1);
		printf("请输入班级号(从1-5班选择)：");
		scanf("%d",&f);
		getchar();
    	printf("当前共有%d个学生信息\n",n-1);
		printf("请输入要分配到此班级的学生的个数：");
		scanf("%d",&num);
		getchar();
		int flag[num],mark[num];
		printf("请依次输入你要分配班到此级的学生的学号：\n");
		for(i=0;i<num;i++)
		{
			printf("第%d个学生的学号：",i+1);
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
					printf("学号为%s的学生已存在班级，是否修改到此班级 y/n：",stu[flag[j]].num);
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
	   	    printf("分配成功！"); 
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
				printf("无学号为%s的学生! \n",S[mark[j]].num);
			}
	   }
		printf("是否继续分配 y/n");
		gets(Flag);
    }while(strcmp(Flag,"y")==0||strcmp(Flag,"Y")==0);
    system("cls"); 
    Class(); 
}
void Add_Class_T()//教师班级分配 
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
			printf("请输入要分配教师的班级号：");
			scanf("%d",&k);
			getchar();
			printf("请输入你要分配到此班级的教师的教工号："); 
			gets(Mark);
			for(i=0;i<n-1;i++)
			{
				if(strcmp(tea[i].ID,Mark)==0)
					f=i;
			}
			if(f==-1)
			{
				printf("暂无该教师！\n");
				printf("是否重新输入 （y/n）：");
				gets(Flag);
				continue;
			}
			else
			{
				if(strcmp(tea[f].C_ID,"无")==0)
					f=-1;
				if(f==-1)
				{
					printf("该教师暂未任课！");
					printf("是否重新输入 （y/n）：");
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
			printf("该班暂无学生！");
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
				if(strcmp(stu[mark[0]].cou[j].Mark,"无")!=0)
				{
					printf("该班的%s课程已有老师授课！",stu[mark[0]].cou[j].Name);
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
					printf("分配成功！");
				 }
		    }
		}
		printf("是否继续分配 y/n \n");
		gets(Flag);
    }while(strcmp(Mark,"y")==0||strcmp(Mark,"Y")==0);
    system("cls"); 
    Class(); 
}
void Class()//班级管理界面 
{
	system("cls");
	int a,w;
	if(m==3)
	{
		do
		{
			puts("\t\t★★★★★★★★★★★★★★★★★★★★★");
			puts("\t\t★                                      ★");
			puts("\t\t★           1.学生班级分配             ★");
			puts("\t\t★                                      ★");
			puts("\t\t★           2.教师班级分配             ★");
			puts("\t\t★                                      ★");
			puts("\t\t★           3.学生班级修改             ★");
			puts("\t\t★                                      ★");
			puts("\t\t★           4.教师班级修改             ★");
			puts("\t\t★                                      ★");
			puts("\t\t★           5.返        回             ★");
			puts("\t\t★★★★★★★★★★★★★★★★★★★★★");
			printf("请选择服务类型(1-5) : [ ]\b\b");
			scanf("%d",&a);
			getchar();
			if(a<1||a>5)
			{
			    system("cls");
			    printf("选择错误!  请重新选择!\n");
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
    	printf("你没有权限！\n");
		system("pause");
		system("cls");
		menu();
    }
 } 
void Add_Course_T()//教师课程分配
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
				printf("暂无教师信息！\n");
				system("pause");
				break;
			}
	    	printf("请输入要分配课程的教师的教工号：\n");
			gets(Mark);
			system("cls");
			for(i=0;i<n-1;i++)
			{
				if(strcmp(Mark,tea[i].ID)==0)
			    {
			    	Course_Choice();
			        printf("请从以上课程分配：\n");
			    	gets(Mark);
			    	strcpy(tea[i].C_ID,Mark);
		    		f=1;
		    		if((fp=fopen(FILE_Teacher,"wb"))==NULL) //只打开或建立一个二进制文件，只允许写数据
					{
						printf("\nCan not open file!\n");
					}
				    for(i=0;i<n-1;i++)
				      //if(stu[i].name[0]!='\0')
				         if(fwrite(&tea[i],sizeof(struct teacher),1,fp)!=1) //将一批数据作为一个整体一次性写入磁盘文件
				            printf("文件写入错误!\n");
				    fclose(fp);
				    printf("录入成功！\n");
					system("pause");
				}
			}
			printf("是否继续录入 y/n");
			gets(Flag);
	    }while(strcmp(Flag,"y")==0||strcmp(Flag,"Y")==0);
    }
    else
    {
    	printf("你没有权限！\n");
    	system("pause");
	}
	system("cls");
    Add_Information2(); 
}
void Add_Information1()//添加基本信息 
{
	system("cls");
	int w,m1;
	do
	{
		puts("\t\t★★★★★★★★★★★★★★★★★★★★★");
	    puts("\t\t★                                      ★");
	    puts("\t\t★        1.学生基本信息录入            ★");
	    puts("\t\t★                                      ★");
	    puts("\t\t★        2.教师基本信息录入            ★");
	    puts("\t\t★                                      ★");
	    puts("\t\t★        3.返            回            ★");
	    puts("\t\t★★★★★★★★★★★★★★★★★★★★★");
		printf("请选择你要添加的信息类型(1-3) : [ ]\b\b");
		scanf("%d",&m1);
		getchar();
		if(m1<1||m1>3)
	    {
		    system("cls");
		    printf("选择错误!  请重新选择!\n");
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
void Add_Information2() //教师课程管理界面 
{
	system("cls");
	int w,m1;
	do
	{ 
		puts("\t\t★★★★★★★★★★★★★★★★★★★★★");
	    puts("\t\t★                                      ★");
	    puts("\t\t★            1.教师课程分配            ★");
	    puts("\t\t★                                      ★");
	    puts("\t\t★            2.教师课程修改            ★");
	    puts("\t\t★                                      ★");
	    puts("\t\t★            3.教师课程删除            ★");
	    puts("\t\t★                                      ★");
	    puts("\t\t★            4.返        回            ★");
	    puts("\t\t★★★★★★★★★★★★★★★★★★★★★");
	    printf("请选择服务类型(1-4) : [ ]\b\b");
	    scanf("%d",&m1);
	    getchar();
	    if(m1<1||m1>4)
	   {
		   system("cls");
		   printf("选择错误!  请重新选择!\n");
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
void Search_Information_S()//学生基本信息查询 
{
	int i,j,n,f;
	char Mark[20],Flag[5];
	n=load(1);
	do
	{
		do
		{
			f=-1;
			printf("请输入你要查询信息的学生的学号：");
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
			    printf("无该学生！\n");
			    printf("是否重新输入 y/n :");
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
			printf("学号：");
			puts(stu[f].num);
			printf("姓名：");
			puts(stu[f].name);
			printf("性别");
			puts(stu[f].sex);
			printf("出生年月：");
			puts(stu[f].birthday);
			printf("身份证号：");
			puts(stu[f].ID);
			printf("入学时间：");
			puts(stu[f].time);
			printf("政治面貌：");
			puts(stu[f].politics);
			printf("家庭住址：");
			puts(stu[f].site);
			printf("籍贯：");
			puts(stu[f].place);
			printf("邮政编号：");
			puts(stu[f].post);
			printf("民族：");
			puts(stu[f].nation);
		}
		printf("是否继续查询其他学生信息 y/n：");
		gets(Flag);
    }while(strcmp(Flag,"y")==0||strcmp(Flag,"Y")==0);
    system("cls");
    Search();
} 
void Search_Information_T()//教师基本信息查询
{
	int i,j,n,f=-1;
	char Mark[20],Flag[5];
	n=load(2);
	do
	{
		do
		{
			printf("请输入你要查询信息的教师的教工号：");
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
			    printf("无该教师！\n");
			    printf("是否重新输入 y/n :");
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
			printf("教工号：");
			puts(tea[f].ID);
			printf("姓名："); 
			puts(tea[f].name);
			printf("性别：");
			puts(tea[f].sex);
			printf("职称："); 
			puts(tea[f].title);
			printf("所属院系：");
			puts(tea[f].courtyard);
			printf("电话号码：");
			puts(tea[f].phone);
		}
		printf("是否继续查询其他教师信息 y/n：");
		gets(Flag);
    }while(strcmp(Flag,"y")==0||strcmp(Flag,"Y")==0);
    system("cls");
    Search();
} 
void Search_Grade()//成绩查询 
{
	int i,j,n,f;
	char Mark[20],Flag[5];
	n=load(1); 
	do
	{
		do
		{
			f=-1; 
			printf("请输入你要查找成绩的学号：");
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
			    printf("无该学生！\n");
			    printf("是否重新输入 y/n :");
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
				printf("该学生成绩暂未录入！\n");
				f=0; 
			}
			else
				for(j=0;j<5;j++)
				{
					printf("%s成绩：",stu[f].cou[j].Name);
				    printf("%d\n",stu[f].cou[j].grade);
				}
		}
		printf("是否重新查询其他学生的成绩 y/n :");
		gets(Flag);
	}while(strcmp(Flag,"y")==0||strcmp(Flag,"Y")==0);
	system("cls");
	Search();
}
void Search_Course_T()//教师课程查询 
{
	int i,j,n,f;
	char Mark[20],Flag[5];
	n=load(2);
	do
	{
		do
		{
			f=-1; 
			printf("请输入你要查询任课信息的教师的教工号：");
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
			    printf("无该教师！\n");
			    printf("是否重新输入 y/n :");
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
			if(strcmp(tea[f].C_ID,"无")==0)
				printf("该教师暂未分配课程！\n");
			else
				printf("该教师在授课课程号%s的课程 \n",tea[f].C_ID); 
		}
		printf("是否继续查询其他教师信息 y/n：");
		gets(Flag);
    }while(strcmp(Flag,"y")==0||strcmp(Flag,"Y")==0);
    system("cls");
    Search();
}
void Search_Name_S()//按姓名查找 
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
			printf("请输入待查找学生姓名：");
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
				printf("无该学生！\n");
			    printf("是否重新输入 y/n :");
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
			printf("姓名为%s的学生共有%d个，分别为\n",Mark,f);
			for(i=0;i<f;i++)
			{
				printf("第%d个学生：\n",i+1);
				printf("姓名:%s\n",stu[mark[i]].name);
	            printf("性别：%s\n",stu[mark[i]].sex);
	            printf("出生日期：%s\n",stu[mark[i]].birthday);
	            printf("入学时间：%s\n",stu[mark[i]].time);
	            printf("所属院系：%s\n",tea[mark[i]].courtyard);
	            printf("政治面貌：%s\n",stu[f].politics);
            }
		}
		printf("是否继续查询其学生信息 y/n：");
		gets(Flag);
	}while(strcmp(Flag,"y")==0||strcmp(Flag,"Y")==0);
    system("cls");
    Search1();
}
void Search_ID_num()//身份证号查询 
{
	int i,j,f,n;
	char Mark[20],Flag[5];
	n=load(1);
	do
	{
		do
		{
			f=-1;
			printf("请输入待查找学生身份证号：");
			gets(Mark);
			for(i=0;i<n-1;i++)
			{
				if(strcmp(Mark,stu[i].ID)==0)
				f=i;
			}
			if(f==-1)
			{
				printf("无该学生！\n");
			    printf("是否重新输入 y/n :");
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
	    	printf("姓名：%s\n",stu[f].name);
            printf("家庭住址：%s\n",stu[f].site);
            printf("邮政编码：%s\n",stu[f].post);
            printf("民族：%s\n",stu[f].nation);
            printf("籍贯：%s\n",stu[f].place);
		}
		printf("是否继续查询其学生身份信息 y/n：");
		gets(Flag);	
	}while(strcmp(Flag,"y")==0||strcmp(Flag,"Y")==0);
    system("cls");
    Search1();
}
void Search_Graduation_num()//毕业证号查询 
{
	int i,j,f,n;
	char Mark[20],Flag[5];
	n=load(1);
	do
	{
		f=-1;
		do
		{
			printf("请输入要查询的毕业证号：");
			gets(Mark);
			for(i=0;i<n-1;i++)
			{
				if(strcmp(Mark, stu[i].Diploma_Number)==0)
				f=i;
			} 
			if(f==-1)
			{
				printf("无该毕业证信息！\n");
			    printf("是否重新输入 y/n :");
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
		  printf("姓名：\n",stu[f].name);
		  printf("学号：\n",stu[f].num);
		  printf("入学时间：\n",stu[f].time);
		  printf("所属院系：\n",stu[f].courtyard);
		  printf("毕业证号：\n",stu[f].Diploma_Number);
		} 
		printf("是否继续查询y/n :");
        gets(Flag); 
    }while(strcmp(Flag,"y")==0||strcmp(Flag,"Y")==0);
    system("cls");
    Search1();
}
void Search_Course_num()//课程号查询 
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
			printf("请输入要查询相关信息的课程号：");
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
				printf("无该课程的任课教师！\n");
			    printf("是否重新输入 y/n :");
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
	    	printf("该课程的任课教师的个数为%d个，分别为\n",f);
	    	for(i=0;i<f;i++)
	    	{
	    		printf("第%d个教师：\n",i+1);
		    	printf("该课程的课程名为：%s\n",stu[0].cou[k].Name);
				printf("该课程的任课教师姓名：%s\n",tea[mark[i]].name);
				printf("该课程的任课教师电话：%s\n",tea[mark[i]].phone);
				printf("该课程的任课教师教工号；%s\n",tea[mark[i]].ID);
		    }
		} 
		printf("是否继续查询y/n :");
		gets(Flag); 
	}while(strcmp(Flag,"y")==0||strcmp(Flag,"Y")==0);
    system("cls");
    Search1();
}
void Search()//查询统计界面 
{
	system("cls");
	int a,w;
	do
	{
		puts("\t\t★★★★★★★★★★★★★★★★★★★★★");
		puts("\t\t★                                      ★");
		puts("\t\t★         1.学生基本信息查询           ★");
		puts("\t\t★         2.学生考试成绩查询           ★");
		puts("\t\t★         3.教师基本信息查询           ★");
		puts("\t\t★         4.教师任课信息查询           ★");
		puts("\t\t★         5.其他查询方式               ★");
		puts("\t\t★         6.成绩排序                   ★");
		puts("\t\t★         7.返            回           ★");
		puts("\t\t★★★★★★★★★★★★★★★★★★★★★");
		printf("请选择服务类型(1-7) : [ ]\b\b");
		scanf("%d",&a);
		getchar();
		if(a<1||a>7)
		{
		    system("cls");
		    printf("选择错误!  请重新选择!\n");
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
void Search1()//其他查询界面 
{
	system("cls");
	int a,w;
	do
	{
		puts("\t\t★★★★★★★★★★★★★★★★★★★★★");
		puts("\t\t★                                      ★");
		puts("\t\t★            1.学      号              ★");
		puts("\t\t★            2.姓      名              ★");
		puts("\t\t★            3.身份证号                ★");
		puts("\t\t★            4.毕业证编号              ★");
		puts("\t\t★            5.教工号                  ★");
		puts("\t\t★            6.课程号                  ★");
		puts("\t\t★            7.返      回              ★");
		puts("\t\t★★★★★★★★★★★★★★★★★★★★★");
		printf("请选择你要查找的方式(1-7) : [ ]\b\b");
		scanf("%d",&a);
		getchar();
		if(a<1||a>7)
		{
		    system("cls");
		    printf("选择错误!  请重新选择!\n");
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
void Grade_Sort()//成绩排序界面 
{
	system("cls");
	int a,w;
	do
	{
		puts("\t\t★★★★★★★★★★★★★★★★★★★★★");
		puts("\t\t★                                      ★");
		puts("\t\t★           1.总成绩排序               ★");
		puts("\t\t★                                      ★");
		puts("\t\t★           2.各班平均成绩排序         ★");
		puts("\t\t★                                      ★");
		puts("\t\t★           3.班内总成绩排序           ★");
		puts("\t\t★                                      ★");
		puts("\t\t★           4.班内单科成绩排序         ★");
		puts("\t\t★                                      ★");
		puts("\t\t★           5.返          回           ★");
		puts("\t\t★★★★★★★★★★★★★★★★★★★★★");
		printf("请选择服务类型(1-5) : [ ]\b\b");
		scanf("%d",&a);
		getchar();
		if(a<1||a>5)
		{
		    system("cls");
		    printf("选择错误!  请重新选择!\n");
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
void Total_Grade_Sort()//总成绩排序
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
	printf("请选择排序方式（1、从大到小 2、从小到大）：");
	scanf("%d",&a);
	getchar();
	j=1;
	if(a==1)
		for(i=0;i<n-1;i++)
		{
			if(s[i].grade>=0)
			{
				printf("第%d名：",j);
				printf("姓名%s ",s[i].name);
				printf("班级%d ",s[i].Class);
				printf("总成绩为：%d\n",s[i].grade);
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
				printf("第%d名：",j);
				printf("姓名%s ",s[i].name);
				printf("班级%d ",s[i].Class);
				printf("总成绩为：%d\n",s[i].grade);
				j--;
			}
		}
	}
 } 
void Total_Grade_In()//班内总成绩排序 
{
	system("cls");
	int a,i,j,n,f,k=0,num=0;
	n=load(1);
	struct score s[n],mark;
	printf("请输入要查询总成绩排序的班号：");
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
		printf("该班级暂无学生！");
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
		printf("请选择排序方式（1、从大到小 2、从小到大）：");
		scanf("%d",&a);
		getchar();
		j=1;
		if(a==1)
			for(i=0;i<num;i++)
			{
				if(s[i].grade>=0)
				{
					printf("第%d名：",j);
					printf("%s ",s[i].name);
					printf("总成绩为：%d\n",s[i].grade);
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
					printf("第%d名：",num);
					printf("%s ",s[i].name);
					printf("总成绩为：%d\n",s[i].grade);
					j--;
				}
			}
		}
	}
}
void Average_Grade()//平均成绩排序
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
		printf("请选择排序方式（1、从大到小 2、从小到大）：");
		scanf("%d",&a);
		getchar();
		j=1;
		if(a==1)
			for(i=0;i<5;i++)
			{
				if(s[i].grade!=-1)
				{
					printf("第%d名：",j);
					printf("班级%d ",s[i].Class);
					printf("平均成绩为：%d\n",s[i].grade);
					j++; 
				}
			}
		else
		    for(i=5-1;i>=0;i--)
			{
				if(s[i].grade!=-1)
				{ 
					printf("第%d名：",j);
					printf("班级%d ",s[i].Class);
					printf("平均成绩为：%d\n",s[i].grade);
					j++;
			    }
			}
 } 
void Single_Grade_In()//班内单科成绩排序
{
	system("cls");
	int a,i,j,n,f,p,k=0,num=0;
	char Mark[20]; 
	n=load(1);
	struct score s[n],mark;
	printf("请输入要查询成绩排序的班号：");
	scanf("%d",&f);
	getchar();
	Course_Choice();
	printf("请从以上课程中选择你要查询成绩排序的课程号：");
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
		printf("该班级暂无学生！");
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
		printf("请选择排序方式（1、从大到小 2、从小到大）：");
		scanf("%d",&a);
		getchar();
		j=1;
		if(a==1)
			for(i=0;i<num;i++)
			{
				if(s[i].grade>=0)
				{
					printf("第%d名：",j);
					printf("%s ",s[i].name);
					printf("成绩为：%d\n",s[i].grade);
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
					printf("第%d名：",i+1);
					printf("%s ",s[i].name);
					printf("成绩为：%d\n",s[i].grade);
					j--;
				}
			}
		}
	}
 } 
void Modify_Student()//修改学生信息 
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
			printf("请输入你要修改的学生的学号：\n");
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
		    	printf("无该学生！\n");
		    	printf("是否重新输入 y/n \n");
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
			printf("存在学号为%s的学生，是否修改 y/n\n",stu[f].num);
			gets(Flag);
			if(strcmp(Flag,"y")==0||strcmp(Flag,"Y")==0)
			{
				printf("修改姓名为："); 
				gets(stu[f].name);
				printf("修改性别为：");
				gets(stu[f].sex);
				printf("修改出生日期为：");
				gets(stu[f].birthday);
				printf("修改身份证号为：");
				gets(stu[f].ID);
				printf("修改入学时间为：");
				gets(stu[f].time);
				printf("修改所属院系为：");
				gets(tea[f].courtyard);
				printf("修改政治面貌为：");
				gets(stu[f].politics);
				printf("修改家庭住址为：");
				gets(stu[f].site);
				printf("修改籍贯为：");
				gets(stu[f].place);
				printf("修改邮政编号为：");
				gets(stu[f].post);
				printf("修改民族为：");
				gets(stu[f].nation);
				fp=fopen(FILE_Student,"wb");
		    	for(i=0;i<n-1;i++)
		    	   fwrite(&stu[i],sizeof(struct student),1,fp);
		    	fclose(fp);
		    	printf("修改成功！\n");
		    	system("pause");
			}
		}
		printf("是否继续修改其他学生信息 y/n \n");
		gets(Flag);
	}while(strcmp(Flag,"y")==0||strcmp(Flag,"Y")==0);
	system("cls");
	Modify();
}
void Modify_Teacher()//修改教师信息 
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
			printf("请输入你要修改的教师的教工号：\n");
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
		    	printf("无该教师！\n");
		    	printf("是否重新输入 y/n \n");
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
			printf("存在教工号为%s的教师，是否修改 y/n\n",stu[f].num);
			gets(Flag);
			if(strcmp(Flag,"y")==0||strcmp(Flag,"Y")==0)
			{
				printf("修改姓名为："); 
				gets(tea[f].name);
				printf("修改性别为：");
				gets(tea[f].sex);
				printf("修改职称为："); 
				gets(tea[f].title);
				printf("修改所属院系为：");
				gets(tea[f].courtyard);
				printf("修改电话号码为：");
				gets(tea[f].phone);
				fp=fopen(FILE_Teacher,"wb");
		    	for(i=0;i<n-1;i++)
		    	   fwrite(&tea[i],sizeof(struct teacher),1,fp);
		    	fclose(fp);
		    	printf("修改成功！\n");
		    	system("pause");
			}
		}
		printf("是否继续修改其他教师信息 y/n \n");
		gets(Flag);
	}while(strcmp(Flag,"y")==0||strcmp(Flag,"Y")==0);
	system("cls");
	Modify();
}
void Modify_Grade()//修改成绩 
{
	FILE *fp;
	int i,j,n,f=0,num;
	char Mark[5];
	n=load(1);
	struct student S[n];
	do
	{
		n=load(1);
		printf("当前共有%d个学生信息\n",n-1);
		printf("请输入你要修改的学生成绩的个数：");
		scanf("%d",&num);
		getchar();
		int flag[num],mark[num];
		printf("请依次输入你要修改成绩的学生的学号：\n");
		for(i=0;i<num;i++)
		{
			printf("第%d个学生的学号：",i+1);
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
				printf("存在学号为%s的学生! \n",stu[flag[j]].num);
				printf("是否修改 y/n :");
				gets(Mark);
				if(strcmp(Mark,"y")==0||strcmp(Mark,"Y")==0)
				{
					for(i=0;i<5;i++)
					{
					    printf("修改%s的成绩为：",stu[flag[j]].cou[i].Name);
					    scanf("%d",&stu[flag[j]].cou[i].grade);
						getchar();
				    }
					fp=fopen(FILE_Student,"wb");
					for(i=0;i<n-1;i++)
					{
						fwrite(&stu[i],sizeof(struct student),1,fp);
					}
					fclose(fp);
					printf("成功修改学号为%s的学生的成绩！\n",S[flag[j]].num);
				}
			}
			else
			{
				printf("无学号为%s的学生! \n",S[mark[j]].num);
				system("pause"); 
			}
	   }		
		printf("是否继续修改其他学生的成绩 y/n: \n");
		gets(Mark) ;
    }while(strcmp(Mark,"y")==0||strcmp(Mark,"Y")==0);
	system("cls");
    Grade();
}
void Modify_Course_T()//修改教师课程
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
			printf("请输入你要修改课程的教师的教工号：");
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
		    	printf("无该教师！\n");
		    	printf("是否重新输入 y/n \n");
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
			printf("存在教工号为%s的教师，是否修改 y/n\n",stu[f].num);
			gets(Flag);
			if(strcmp(Flag,"y")==0||strcmp(Flag,"Y")==0)
			{
				Course_Choice();
				printf("请从以上课程选择修改\n");
				printf("修教师所任课程为：");
				gets(tea[f].C_ID);
				fp=fopen(FILE_Teacher,"wb");
		    	for(i=0;i<n-1;i++)
		    	   fwrite(&tea[i],sizeof(struct teacher),1,fp);
		    	fclose(fp);
		    	printf("修改成功！\n");
		    	system("pause");
			}
		}
		printf("是否继续修改其他教师的课程 y/n \n");
		gets(Flag);
    }while(strcmp(Flag,"y")==0||strcmp(Flag,"Y")==0);
    system("cls");
	Add_Information2();
}
void Modify_Class_S()//学生班级修改
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
			printf("请输入你要修改的学生的学号：\n");
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
		    	printf("无该学生！\n");
		    	printf("是否重新输入 y/n \n");
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
			printf("存在学号为%s的学生，是否修改 y/n\n",stu[f].num);
			gets(Flag);
			if(strcmp(Flag,"y")==0||strcmp(Flag,"Y")==0)
			{
				printf("请输入班级号（1-5）：");
				scanf("%d",&k);
				getchar();
				stu[f].Class=k;
				fp=fopen(FILE_Student,"wb");
		    	for(i=0;i<n-1;i++)
		    	   fwrite(&stu[i],sizeof(struct student),1,fp);
		    	fclose(fp);
		    	printf("修改成功！\n");
		    	system("pause");
			}
		}
		printf("是否继续修改其他学生的班级 y/n \n");
		gets(Flag);
	}while(strcmp(Flag,"y")==0||strcmp(Flag,"Y")==0);
	system("cls");
    Class();
} 
void Modify_Class_T()//教师班级修改
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
			printf("请输入你要修改的教师的教工号：\n");
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
		    	printf("无该教师！\n");
		    	printf("是否重新输入 y/n \n");
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
			printf("存在学号为%s的教师，是否修改 y/n\n",stu[f].num);
			gets(Flag);
			if(strcmp(Flag,"y")==0||strcmp(Flag,"Y")==0)
			{
				printf("请输入班级号（1-5）：");
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
					printf("该班暂无学生！\n");
				}
				else
				{
					for(i=0;i<5;i++)
					{
						if(strcmp(tea[f].C_ID,stu[mark[0]].cou[i].ID)==0)
							j=i;
					}
					if(strcmp(stu[mark[0]].cou[j].Mark,"无")!=0)
					{
						printf("该班的%s课程已有老师授课！\n",stu[mark[0]].cou[j].Name);
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
			    	    printf("修改成功！\n");
			    	    system("pause");
			    	}
		        }
			}
		}
		printf("是否继续修改其他学生的班级 y/n \n");
		gets(Flag);
	}while(strcmp(Flag,"y")==0||strcmp(Flag,"Y")==0);
	system("cls");
	Class();
 } 
void Modify()//修改界面 
{
	system("cls");
	int w,m1;
	do
	{
		puts("\t\t★★★★★★★★★★★★★★★★★★★★★");
	    puts("\t\t★                                      ★");
	    puts("\t\t★           1.修改学生信息             ★");
	    puts("\t\t★                                      ★");
	    puts("\t\t★           2.修改教师信息             ★");
	    puts("\t\t★                                      ★");
	    puts("\t\t★           3.返        回             ★");
	    puts("\t\t★★★★★★★★★★★★★★★★★★★★★");
		printf("请选择你要修改的信息类型(1-3) : [ ]\b\b");
		scanf("%d",&m1);
		getchar();
		if(m1<1||m1>3)
	    {
		    system("cls");
		    printf("选择错误!  请重新选择!\n");
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
void Delete_Student()//删除学生信息 
{
	FILE *fp;
	int i,j,n,num;
	char Mark[5];
	n=load(1);
	struct student S[n];
	do
	{
		n=load(1);
		printf("当前共有%d个学生信息\n",n-1);
		printf("请输入你要删除的学生的个数：");
		scanf("%d",&num);
		getchar();
		int flag[num],mark[num];
		printf("请依次输入你要删除的学生的学号：\n");
		for(i=0;i<num;i++)
		{
			printf("第%d个学生的学号：",i+1);
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
				printf("存在学号为%s的学生! \n",S[flag[j]].num);
				printf("是否删除 y/n :");
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
					printf("成功删除学号为%s的学生！\n",S[flag[j]].num);
				}
			}
			else
			{
				printf("无学号为%s的学生! \n",S[mark[j]].num);
				system("pause"); 
			}
	   }		
		printf("是否继续删除其他学生信息 y/n \n");
		gets(Mark) ;
    }while(strcmp(Mark,"y")==0||strcmp(Mark,"Y")==0);
	system("cls");
    Delete();
}
void Delete_Teacher()//删除教师信息 
{
	FILE *fp;
	int i,j,n,num;
	char Mark[5];
	n=load(2);
	struct teacher T[n];
	do
	{
		n=load(2);
		printf("当前共有%d个教师信息\n",n-1);
		printf("请输入你要删除的教师的个数：");
		scanf("%d",&num);
		getchar();
		int flag[num],mark[num];
		printf("请依次输入你要删除的教师的教工号：\n");
		for(i=0;i<num;i++)
		{
			printf("第%d个教师的教工号：",i+1);
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
				printf("存在教工号为%s的教师! \n",T[flag[j]].ID);
				printf("是否删除 y/n :");
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
					printf("成功删除教工号为%s的教师！\n",T[flag[j]].ID);
				}
			}
			else
			{
				printf("无教工号为%s的教师! \n",T[mark[j]].ID);
				system("pause"); 
			}
	   }		
		printf("是否继续删除其他教师信息 y/n \n");
		gets(Mark) ;
    }while(strcmp(Mark,"y")==0||strcmp(Mark,"Y")==0);
	system("cls");
    Delete();
}
void Delete_Grade()//删除成绩 
{
	FILE *fp;
	int i,j,n,num;
	char Mark[5];
	n=load(1);
	struct student S[n];
	do
	{
		n=load(1);
		printf("当前共有%d个学生信息\n",n-1);
		printf("请输入你要删除学生成绩的个数：");
		scanf("%d",&num);
		getchar();
		int flag[num],mark[num];
		printf("请依次输入你要删除成绩的学生的学号：\n");
		for(i=0;i<num;i++)
		{
			printf("第%d个学生的学号：",i+1);
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
				printf("存在学号为%s的学生! \n",stu[flag[j]].num);
				printf("是否删除 y/n :");
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
					printf("成功删除学号为%s的学生！\n",stu[flag[j]].num);
				}
			}
			else
			{
				printf("无学号为%s的学生! \n",stu[mark[j]].num);
				system("pause"); 
			}
	   }		
		printf("是否继续删除其他学生 y/n \n");
		gets(Mark) ;
    }while(strcmp(Mark,"y")==0||strcmp(Mark,"Y")==0);
	system("cls");
    Grade();
}
void Delete_Course_T()//删除教师课程
{
	FILE *fp;
	int i,j,n,num;
	char Mark[5];
	n=load(2);
	struct teacher T[n];
	do
	{
		n=load(2);
		printf("当前共有%d个教师信息\n",n-1);
		printf("请输入你要删除的教师的个数：");
		scanf("%d",&num);
		getchar();
		int flag[num],mark[num];
		printf("请依次输入你要删除的教师的教工号：\n");
		for(i=0;i<num;i++)
		{
			printf("第%d个教师的教工号：",i+1);
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
				printf("存在教工号为%s的教师! \n",tea[flag[j]].ID);
				printf("是否删除 y/n :");
				gets(Mark);
				if(strcmp(Mark,"y")==0||strcmp(Mark,"Y")==0)
				{
					strcpy(tea[flag[j]].C_ID,"无");
					fp=fopen(FILE_Teacher,"wb");
					for(i=0;i<n-1;i++)
					{
						fwrite(&tea[i],sizeof(struct teacher),1,fp);
					}
					fclose(fp);
					printf("成功删除教工号为%s的教师的课程！\n",tea[flag[j]].ID);
				}
			}
			else
			{
				printf("无教工号为%s的教师! \n",T[mark[j]].ID);
				system("pause"); 
			}
	   }		
		printf("是否继续删除其他教师的课程 y/n \n");
		gets(Mark) ;
    }while(strcmp(Mark,"y")==0||strcmp(Mark,"Y")==0);
	system("cls");
    Add_Information2();
 } 
void Delete()//删除界面 
{
	system("cls");
	int w,m1;
	do
	{
		puts("\t\t★★★★★★★★★★★★★★★★★★★★★");
	    puts("\t\t★                                      ★");
	    puts("\t\t★           1.删除学生信息             ★");
	    puts("\t\t★                                      ★");
	    puts("\t\t★           2.删除教师信息             ★");
	    puts("\t\t★                                      ★");
	    puts("\t\t★           3.返        回             ★");
	    puts("\t\t★★★★★★★★★★★★★★★★★★★★★");
		printf("请选择你要删除的信息类型(1-3) : [ ]\b\b");
		scanf("%d",&m1);
		getchar();
		if(m1<1||m1>3)
	    {
		    system("cls");
		    printf("选择错误!  请重新选择!\n");
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
void Graduate_Judgement()//毕业判断
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
			printf("请输入学生的学号：");
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
				printf("无该学生！");
			}
			else
			{
				if(strcmp(stu[f].Diploma_Number,"无")==0)
				{
					if(stu[f].Revised_credits>=stu[f].Required_credits)
					{
						printf("该生满足毕业条件！");
						printf("请输入其毕业证编号：");
						gets(stu[f].Diploma_Number);
						fp=fopen(FILE_Student,"wb");
						for(i=0;i<n-1;i++)
						{
							fwrite(&stu[i],sizeof(struct student),1,fp);
						}
						fclose(fp);
						printf("录入成功！");
					}
					else
					    printf("该生不满足毕业条件！");
				}
				else
					printf("该生已录入毕业证编号！");
			}
			printf("是否继续 y/n \n");
			gets(Flag) ;
	    }while(strcmp(Flag,"y")==0||strcmp(Flag,"Y")==0);
	}
	else
    {
    	printf("你没有权限！\n");
		system("pause");
		system("cls");
		Graduate_Imformation();
    }
	system("cls");
	Graduate_Imformation();
 } 
void Search_Gradute()//毕业信息查询
{
	int i,j,n,f;
	char Mark[20],Flag[5];
	n=load(1);
	do
	{
		do
		{
			f=-1;
			printf("请输入你要查询的学号：");
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
			    printf("无该学生！\n");
			    printf("是否重新输入 y/n :");
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
			if(strcmp(stu[f].Diploma_Number,"无")==0)
			{
				printf("该学暂未录入毕业证编号！\n");
			}
			else
			{
				printf("毕业证编号为：");
				puts(stu[f].Diploma_Number);
			}
		}
		printf("是否继续查询其他学生 y/n :");
		gets(Flag);
    }while(strcmp(Flag,"y")==0||strcmp(Flag,"Y")==0);
	system("cls");
	Graduate_Imformation();
 } 
void Graduate_Imformation()//毕业生信息管理界面
{
	system("cls");
	int a,w;
	do
	{
		puts("\t\t★★★★★★★★★★★★★★★★★★★★★");
		puts("\t\t★                                      ★");
		puts("\t\t★            1.毕业编号输入            ★");
		puts("\t\t★                                      ★");
		puts("\t\t★            2.毕业信息查询            ★");
		puts("\t\t★                                      ★");
		puts("\t\t★            3.返        回           ★");
		puts("\t\t★★★★★★★★★★★★★★★★★★★★★");
		printf("请选择你要查找的方式(1-3) : [ ]\b\b");
		scanf("%d",&a);
		getchar();
		if(a<1||a>3)
		{
		    system("cls");
		    printf("选择错误!  请重新选择!\n");
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
void Login()//登录注册 
{
	int a,i;
	char Mark[20];
	printf("请输入管理员验证码：");
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
		printf("验证成功\n");
		m=3;
	}
	else
	{
		system("cls");
		printf("验证码错误！\n");
	}
	system("pause");
	system("cls");
	menu();
 } 
void exit()//退出 
{
	printf("欢迎下次使用!");
	exit(0);
}
void face()//访问页面
{
	printf("\n\t    ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★\n\n");
	puts("\t    ※※※※※※※※※※※※※※※※※※※※※※※※※※※");
	puts("\t    ※※                                              ※※");
	puts("\t    ※※                                              ※※");
	puts("\t    ※※                                              ※※");
	puts("\t    ※※                                              ※※");
	puts("\t    ※※           欢迎访问学生学籍管理系统!          ※※");
	puts("\t    ※※                                              ※※");
	puts("\t    ※※                                              ※※");
	puts("\t    ※※                                              ※※");
	puts("\t    ※※                                              ※※");
    puts("\t    ※※                                              ※※");
	puts("\t    ※※※※※※※※※※※※※※※※※※※※※※※※※※※");
	printf("\n\tPress [ Enter ] key to continue……\n");
	getchar();
	system("cls");
}
void menu()//主菜单 
{
	system("cls");
	int n,n1,w1,w2;
	if(m==-1)
	{
	    do
		{
		   printf("\n\t\t\t欢迎使用学生学籍管理系统!\n");
	       printf("\n");
		   puts("\t\t★★★★★★★★★  菜单  ★★★★★★★★");
		   puts("\t\t★               1.用  户               ★");
		   puts("\t\t★                                      ★");
		   puts("\t\t★               2.管理员               ★");
		   puts("\t\t★                                      ★");
		   puts("\t\t★               3.退  出               ★");
		   puts("\t\t★★★★★★★★★★★★★★★★★★★★★");
		   printf("请选择使用类型(1-3) : [ ]\b\b");
		   scanf("%d",&n);
		   if(n<1||n>3)
		   {
			   system("cls");
			   printf("选择错误!  请重新选择!\n");
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
		   puts("\t\t★★★★★★★★★  菜单  ★★★★★★★★");
		   puts("\t\t★           1.基本信息管理             ★");
		   puts("\t\t★           2.学生成绩管理             ★");
		   puts("\t\t★           3.班级信息管理             ★");
		   puts("\t\t★           4.信息查询统计             ★");
		   puts("\t\t★          5.毕业生信息管理            ★");
		   puts("\t\t★           6.返        回             ★");
		   puts("\t\t★           7.退        出             ★");
		   puts("\t\t★★★★★★★★★★★★★★★★★★★★★");
		   printf("请选择服务种类(1-7) : [ ]\b\b");
		   scanf("%d",&n1);
		   if(n1<1||n1>7)
		   {
			   system("cls");
			   printf("选择错误!  请重新选择!\n");
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
