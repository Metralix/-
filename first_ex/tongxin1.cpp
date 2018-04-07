/*
��һ��ʵ��Դ����
Designed by �����
���룺��
����������жϽ��������Լ������
Ҫ����Դ�������ڵ��ļ����д��data��PSS�ļ���
*/
#include <bits/stdc++.h>
#define LL long long
using namespace std;

FILE *fp;
int data_num=48;
char PSS_name[][15]={"PSS0.txt","PSS1.txt","PSS2.txt"};
float PSS_data[3][50000];
float file_data[50][50000][2];
float file_data_line[50][50000];
int max_data;
int max_power; 
//float max_relate[5][50];

struct str1{
	float power;
	int tag;
}power_data[50];

struct str2{
	float max_num;
	int tag;
	
}max_relate[5];

int cmp(struct str1 a,struct str1 b){
	return a.power>b.power;
}
int cmp1(struct str2 a,struct str2 b){
	return a.max_num>b.max_num;
}
int main(){
	//��ȡdata�ļ�
	for(int i=0;i<data_num;i++){
		char file_name[10]="data";
		char b[10];
		memset(b,0,sizeof(b));
		itoa(i,b,10);
		strcat(file_name,b);
		strcat(file_name,".txt");
		//puts(file_name);
		fp=fopen(file_name,"r+");
		if(fp==NULL){
			printf("connot open~\n");
		}else{
			for(int j=0;j<15000;j++){
				fscanf(fp,"%f",&file_data[i][j][0]);
				fscanf(fp,"%f",&file_data[i][j][1]);
			}
		}
		
	}
	for(int i=0;i<data_num;i++){
		char file_name[10]="data";
		char b[10];
		memset(b,0,sizeof(b));
		itoa(i,b,10);
		strcat(file_name,b);
		strcat(file_name,".txt");
		//puts(file_name);
		fp=fopen(file_name,"r+");
		if(fp==NULL){
			printf("connot open~\n");
		}else{
			for(int j=0;j<30000;j++){
				fscanf(fp,"%f",&file_data_line[i][j]);
			}
		}
		
	}
	
	//���㹦�ʴ�С
	for(int i=0;i<data_num;i++){
		float res_temp1=0;
		for(int j=0;j<15000;j++){
			res_temp1+=sqrt(file_data[i][j][0]*file_data[i][j][0]+file_data[i][j][1]*file_data[i][j][1]);
		}
		power_data[i].power=res_temp1;
		power_data[i].tag=i;
	} 
	
	//�Թ�������,�ҵ����Ĺ���
	sort(power_data,power_data+data_num,cmp);
	max_data=power_data[0].tag;
	max_power=power_data[0].power;
	
	for(int i=0;i<data_num;i++){
		printf("data%d\t ����Ϊ��%f\t\n",power_data[i].tag,power_data[i].power);
	}
	
	//���㻬�����
	for(int i=0;i<3;i++){
		fp=fopen(PSS_name[i],"r+");
		if(fp==NULL){
			printf("connot open PSS~\n");
		}else{
			for(int j=0;j<4096;j++){
				fscanf(fp,"%f",&PSS_data[i][j]);
			}
		}
	}
	//ѭ��ÿһ��pss 
	for(int i=0;i<3;i++){
		float max_temp2=-9999;
		float max_temp3=-9999;
		int max_tag2=0;
		//ѭ��ÿһ��data 
		for(int j=0;j<48;j++){
			float res_temp2=0;
			max_temp2=-9999;
			//����k 
			for(int k=0;k<30000-4096;k+=2){
				//��ƥ��� 
				res_temp2=0;
				for(int g=k;g<k+4096;g++){
					res_temp2+=file_data_line[j][g]*PSS_data[i][g-k];	
				} 
				max_temp2=max(max_temp2,res_temp2);
			}
			//printf("%d %f\n",j,max_temp2);
			max_temp3=max(max_temp3,max_temp2);
			
			if(max_temp3==max_temp2) max_tag2=j;
		}
		max_relate[i].tag=max_tag2;
		max_relate[i].max_num=max_temp3;
	}
	//sort(max_relate,max_relate+3,cmp1);
	for(int i=0;i<3;i++){
		printf("PSS%d\t�������������data%d \t���ֵΪ%f\t \n",i,max_relate[i].tag,max_relate[i].max_num);
	}
	return 0;
}

