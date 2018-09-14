#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
int CharCount(char file[]);//字符数统计函数 
int WordCount(char file[]);//单词数统计函数 
int LineCount(char file[]);//行数统计函数 
int ComplexCount(char file[]); 
int main(){//主函数 
	char input[10],File[200];
	printf("请输入用户命令：wc.exe-");
	scanf("%s",&input);
	while(1){
	    if(input[0]=='c'){
		   printf("请输入文件名：");
	       scanf("%s",&File);
		   int charcount=0;
		   charcount=CharCount(File);
		   printf("文件的字符数为：%d",charcount);
		   break;	
		}
	    if(input[0]=='w'){
			printf("请输入文件名：");
			scanf("%s",&File); 
			int wordcount=0;
		    wordcount=WordCount(File);
		    printf("文件的词数为：%d",wordcount);
		    break;	
		}
		if(input[0]=='l'){
			printf("请输入文件名:");
			scanf("%s",&File); 
			int linecount=0;
		    linecount=LineCount(File);
		    printf("文件的行数为：%d",linecount);
		    break;	
		}
		if(input[0]=='a'){
			printf("请输入文件名：");
			scanf("%s",&File); 
		    ComplexCount(File);
		    break;	
		}
	}
    system("pause");
	return 0;
}
int CharCount(char file[]){//字符数统计函数 
	FILE *pf=NULL;
	int ccount=0;
	pf=fopen(file,"r");
	if(pf==NULL){
		printf("寻找文件失败\n");
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
int WordCount(char file[]){//单词数统计函数 
	FILE *pf=NULL;
	int wcount=0;
	pf=fopen(file,"r");
	if(pf==NULL){
		printf("寻找文件失败\n");
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
	}
	fclose(pf);
    return wcount;
}
int LineCount(char file[]){//行数统计函数 
	FILE *pf=NULL;
	int lcount=0;
	pf=fopen(file,"r");
	if(pf==NULL){
		printf("寻找文件失败\n");
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
	int notecount=0;
	int codecount=0;
	int s;
	pf=fopen(file,"r");
	if(pf==NULL){
		printf("寻找文件失败\n");
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
			else if(mychar=='}'){
				mychar=fgetc(pf);
			    if(mychar=='\n'){
				    spacecount++;
				    mychar=fgetc(pf);
			    }
		    } 
		//else if(mychar=='}'){
		
		//	}
		}
		else mychar=fgetc(pf);
	}
	printf("文件空行数为%d\n",spacecount);
	return 0;
}
