#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
int CharCount(char file[]);//�ַ���ͳ�ƺ��� 
int WordCount(char file[]);//������ͳ�ƺ��� 
int LineCount(char file[]);//����ͳ�ƺ��� 
int ComplexCount(char file[]); 
int main(){//������ 
	char input[10],File[200];
	while(1){
	    printf("�������û����wc.exe-");
	    scanf("%s",&input);
	    if(input[0]=='c'){
		   printf("�������ļ�����");
	       scanf("%s",&File);
		   int charcount=0;
		   charcount=CharCount(File);
		   printf("�ļ����ַ���Ϊ��%d\n",charcount);
		   continue;	
		}
	    if(input[0]=='w'){
			printf("�������ļ�����");
			scanf("%s",&File); 
			int wordcount=0;
		    wordcount=WordCount(File);
		    printf("�ļ��Ĵ���Ϊ��%d\n",wordcount);
		    continue;
		}
		if(input[0]=='l'){
			printf("�������ļ���:");
			scanf("%s",&File); 
			int linecount=0;
		    linecount=LineCount(File);
		    printf("�ļ�������Ϊ��%d\n",linecount);
		    continue;	
		}
		if(input[0]=='a'){
			printf("�������ļ�����");
			scanf("%s",&File); 
		    ComplexCount(File);
		    continue;
		}
	}
    system("pause");
	return 0;
}
int CharCount(char file[]){//�ַ���ͳ�ƺ��� 
	FILE *pf=NULL;
	int ccount=0;
	pf=fopen(file,"r");
	if(pf==NULL){
		printf("Ѱ���ļ�ʧ��\n");
		exit(-1);
	}
    char mychar;
    mychar = fgetc(pf);
	while(mychar!=EOF){
        mychar = fgetc(pf);
		ccount++;
	}
    fclose(pf);
    return ccount;
}
int WordCount(char file[]){//������ͳ�ƺ��� 
	FILE *pf=NULL;
	int wcount=0;
	pf=fopen(file,"r");
	if(pf==NULL){
		printf("Ѱ���ļ�ʧ��\n");
		exit(-1);
	}
    char mychar;
    mychar = fgetc(pf);
    while(mychar!=EOF){
        if(mychar>='a'&&mychar<='z'||mychar>='A'&&mychar<='Z'||mychar>='0'&&mychar<='9'){
        	while(mychar>='a'&&mychar<='z'||mychar>='A'&&mychar<='Z'||mychar>='0'&&mychar<='9'||mychar=='_'){
        		mychar=fgetc(pf);
			}
			wcount++;
			mychar=fgetc(pf);
		}
		mychar=fgetc(pf);
	}
	fclose(pf);
    return wcount;
}
int LineCount(char file[]){//����ͳ�ƺ��� 
	FILE *pf=NULL;
	int lcount=0;
	pf=fopen(file,"r");
	if(pf==NULL){
		printf("Ѱ���ļ�ʧ��\n");
		exit(-1);
	}
    char mychar;
    mychar = fgetc(pf);
    while(mychar!=EOF){
		if(mychar=='\n'){
		    lcount++;
		    mychar = fgetc(pf);
		}
		else{
		    mychar = fgetc(pf);
		}
	}
	
	fclose(pf);
    return lcount+1;
}
int ComplexCount(char file[]){
	FILE *pf=NULL;
	int spacecount=0;
	pf=fopen(file,"r");
	if(pf==NULL){
		printf("Ѱ���ļ�ʧ��\n");
		exit(-1);
	}
	char mychar;
    mychar = fgetc(pf);
    while(mychar!=EOF){
		if(mychar=='\n'){
			mychar=fgetc(pf);
			if(mychar=='\n' ){
				spacecount++;
				mychar=fgetc(pf);
			}
		}
		else if(mychar=='}'){
			mychar=fgetc(pf);
			if(mychar=='\n'){
				spacecount++;
				mychar=fgetc(pf);
			}
		}
		else mychar=fgetc(pf);
	}
	printf("�ļ�������Ϊ%d\n",spacecount);
	return 0;
}
