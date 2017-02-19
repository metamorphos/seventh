#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int wro=0,rig=0,flag=0;
int main()
{
	void zero(int arr[4]);
    int sum,language,i,swit,num[4],j;
	srand((unsigned int)time(NULL)); //设置随机数种子 
	printf("欢迎使用四则运算练习程序！\n");
	printf("Welcome to the program of operation practice!\n");
	printf("******************************************************************************\n\n");
	printf("请选择您所使用的语言/Please choose the language your use:\n1.中文/Chinese     2.英文/English\n");
	scanf("%d",&language);  //语言切换
	if(language==1)
		printf("请输入您所需要的题目数：");
	else
		printf("Please input the number you need:");
	scanf("%d",&sum);
	for(i=1;i<=sum;)
	{
		for(j=1;j<=4;j++)
		{
			num[j]=rand()%10+1;
		}
		swit=1;
		switch(swit)
		{
		   case 1:zero(num);break;  //输出含0个括号的式子
		}
		if(flag==0)
			i++;
		flag=0;   //用flag检测是否输出了题目
	}
	if(language==1)
	{
		printf("您的正确题数为：%4d\n",rig);
		printf("您的错误题数为：%4d\n",wro);
		printf("欢迎再次使用！\n");
	}
	else
	{
		printf("The number of questions you did right is:%4d\n",rig);
		printf("The number of questions you did wrong is:%4d\n",wro);
		printf("Welcome to use again!\n");
	}
	return 0;
}


//输出含0个括号的式子的函数
void zero(int arr[4])  
{
	srand((unsigned int)time(NULL)); //设置随机数种子 
	int input,sign[4],i,test;
	float temp[5],arr2[4];
	char sig[4];
	for(i=1;i<=4;i++)
	{
		arr2[i]=arr[i];
	}
	temp[1]=arr2[1];
	sig[0]='*';
	temp[0]=1;
	for(i=1;i<=3;i++)
	{
		sign[i]=rand()%4+1;
		if(sign[i]==1)
		{
			sig[i]='+';
		    temp[i+1]=temp[i]+arr2[i+1];
	    }
		if(sign[i]==2)
		{
			sig[i]='-';
			temp[i+1]=temp[i]-arr2[i+1];
		}	
		if(sign[i]==3)
		{
			sig[i]='*';
			if(sig[i-1]=='-')
			temp[i+1]=temp[i-1]-arr2[i]*arr2[i+1];
			else if(sig[i-1]=='+')
	    	temp[i+1]=temp[i-1]+arr2[i]*arr2[i+1];
			else
			temp[i+1]=temp[i]*arr2[i+1];
		}
		
		if(sign[i]==4)
		{
			sig[i]='/';
			if(sig[i-1]=='-')
			temp[i+1]=temp[i-1]-arr2[i]/arr2[i+1];
		    else if(sig[i-1]=='+')
	    	temp[i+1]=temp[i-1]+arr2[i]/arr2[i+1];
			else
			temp[i+1]=temp[i]/arr2[i+1];
		}
	}
	test=temp[4];
	if(temp[4]==test&&temp[4]>=0)     //用test作为检测量，检查随机式子结果是否为非负整数，控制难度
	{
		printf("%d%c%d%c%d%c%d=",arr[1],sig[1],arr[2],sig[2],arr[3],sig[3],arr[4]);

printf("%d",test);

		scanf("%d",&input);
		if(input==test)
			rig++;
		else
			wro++;
	}
	else
		flag=1;     //用flag检测是否输出了题目
}