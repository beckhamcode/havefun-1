#include <iostream>
#include<stdlib.h>
#include<time.h>
#include "winpro.h"
#include "trans.h"
using namespace std;

//transform pai
int transform(char*a)
{

   int i=0;
   if(a[0]==0) return 0;
   while(a[i]!=32) {i++;}
   if(a[i+2]==0)return trans[a[0]]+numberadd[a[i+1]];
   else return trans[a[0]]+8;
}
int transform2(char *a)
{
       int i=1;
	   int num=0;
	if(a[0]==0) return 0;
        num=a[0]-48;
		while(a[i]!=0){
			num=num*10;
		     num=num+a[i]-48;
			 i++;
		}
		return num;
}
//0~check  1~call 2~raise 3~all_in  4~fold
int Strategy(double RR)
{
          
           srand((int)time(0));
           int random=rand()%100;
		   if(RR<0.8) {
		        if(random>=5) return 4;
				else return 2;
		   }
		   else if(RR<1.0) {
		         if(random>=20) return 4;
				 else if(random>=15) return 1;
				 else return 2;
		   }
		   else if(RR<1.3){
				 if(random>=40) return 1;
				 else return 2;
		   }
		   else{
		       if(random>=30) return 2;
				 else return 1;
		   }
}

void Action()
{

	int n;             //��������	
	int playn;     //�����Լ��������


    int  total_pot = transform2(Pot);
             for(int i=0;i<20;i++) Pot[i]=0;      // �ص��ܽ��
    int thisturn = transform2(callNum);
				for(int i=0;i<10;i++) callNum[i]=0;     //���ҪͶע���

	int b[2];     //����
	int a[5];     //����

	b[0]=transform(card_hold0); 
	b[1]=transform(card_hold1);
	a[0]=transform(card_flop0);
	a[1]=transform(card_flop1);
	a[2]=transform(card_flop2);
	a[3]=transform(turn_card);
	a[4]=transform(river_card);
    
        for(int i=0;i<20;i++) card_hold0[i]=0;
	    for(int i=0;i<20;i++) card_hold1[i]=0;
		for(int i=0;i<20;i++) card_flop0[i]=0;
        for(int i=0;i<20;i++) card_flop1[i]=0;
		for(int i=0;i<20;i++) card_flop2[i]=0;
		for(int i=0;i<20;i++) turn_card[i]=0;
		for(int i=0;i<20;i++) river_card[i]=0;  //����

	cout << winpro(b, a, n, playn) << endl;
	
	int power=winpro(b, a, n, playn);   //���Ƶ�����
	int pot=0; //�ص׽��ر���
	int RR=0;   //Ӱ����ߵ�ֵ

   pot= thisturn/total_pot;
   RR=power/pot;

   int action = Strategy(RR);

   switch(action)       //0~check  1~call 2~raise 3~all_in  4~fold  ����actionֵѡ��send��ͬ���ԣ��ӱ��ͼ�thisturn��ô���num
   {
       case 0: 
	   case 1
	   case 2
	   case 3
	   case 4
   }
   return ;
}
