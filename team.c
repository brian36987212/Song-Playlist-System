#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

typedef struct
{
	char song[100];
	char singer[100];
	char time[20];
}list;
list data[800];  //最多存取800首歌
int total=0;  //紀錄總共多少歌曲

void Menu();
void Sort(list *s);
void Add();
void Delete();
void Modify();
void Search();
void Show(list *a, int s);
void Random();

int main()
{
	int i;
	int index=0;  //0.1.2 紀錄現在讀取歌曲、歌手、時間
	char temp[200];  //接收讀檔內容	
	char *tok;
	FILE *fp=fopen("歌單.csv","rt");
	if(!fp)
	{
		printf("open failed\n");
		exit(1);
	}
	while(!feof(fp))
	{
		total++;
		fgets(temp,200,fp);
		tok=strtok(temp,",");  //strtok(要分解甚麼，以甚麼來當作分解) 分解 
		while(tok!=0)
		{
			if(index==0)  //輸入歌名
			{
				strcpy(data[total].song, tok);  //strcpy(複製內容樣複製到哪，從哪裡複製) 複製 
				tok=strtok(0,",");
				index++;
			}
			else if(index==1)  //輸入演唱者
			{
				strcpy(data[total].singer, tok);
				tok=strtok(0,",");
				index++;
			}
			else  //輸入時間
			{
				strcpy(data[total].time, tok);
				tok=strtok(0,",");
				index=0;
			}
		}
	}
	fclose(fp);
	Menu();
}

void Menu()
{
	int menuchoice;
	printf("\n----------Service----------\n");
	printf("1:Add\n");
	printf("2:Delete\n");
	printf("3:Modify\n");
	printf("4:Search\n");
	printf("5:Show\n");
	printf("6:Random\n");
	printf("7:Exit\n");

	printf("Enter choice from 1~7:\n");
	scanf("%d",&menuchoice);
	switch(menuchoice)
	{
		case 1:
			Add();
			break;
		case 2:
			Delete();
			break;
		case 3:
			Modify();
			break;
		case 4:
			Search();
			break;
		case 5:
			Show(data,1);
			break;
		case 6:
			Random();
			break;
		case 7:
			exit(1);
			break;
		default:
			break;
	}
}

void Sort(list *s)  //氣泡排序法 
{
	char a[1],b[1],temp[100];
	int i,j;
	for(i=1; i<total-1; i++)
	{
		for(j=i+1; j<total; j++)
		{
			strncpy(a,&s[i].song[0],1);  //strncpy(複製到哪裡，複製的起點，要複製幾個) 
			strncpy(b,&s[j].song[0],1);
			if(a[0]>b[0])  //ASCII Code 
			{
				strcpy(temp, s[i].song);  //交換歌名 
				strcpy(s[i].song, s[j].song);
				strcpy(s[j].song, temp);
				
				strcpy(temp, s[i].singer);  //交換演唱者 
				strcpy(s[i].singer, s[j].singer);
				strcpy(s[j].singer, temp);
				
				strcpy(temp, s[i].time);  //交換歌曲長度 
				strcpy(s[i].time, s[j].time);
				strcpy(s[j].time, temp);
			}
		}
	}
}

void Show(list *a,int s)
{
	int i;
	if(s==1)  //判斷是否需要排序 s=0不用 s=1需要 
		Sort(a);
	for(i=1; i<total; i++)
	{
		printf("Song[%4d] song:%-70s, singer:%-40s time:%-4s\n",i, data[i].song, data[i].singer, data[i].time);
	}
	Menu();
}

void Add()
{
	char a[100];
	printf("輸入要新增的歌曲資訊(歌名、演唱者、歌曲長度):\n");
	gets(a);
	gets(data[total].song);
	gets(data[total].singer);
	gets(data[total].time);
	total++;
	printf("新增成功\n");
	Menu();
}

void Delete()
{
	int i,temp=0;
	char a[100],song[100],singer[100],time[20];
	printf("輸入要刪除的歌曲資訊(歌名、演唱者、歌曲長度):\n");
	gets(a);
	gets(song);
	gets(singer);
	gets(time);
	for(i=1; i<total; i++)
	{
		if(strcmp(song, data[i].song)==0)  //strcmp(字串1,字串2)==0：相同 >0：字串1比較長　＜０：字串１比較短  
		{
			temp=i;
		}
		for(; temp<total; temp++)
		{
			strcpy(data[temp].song, data[temp+1].song);
			strcpy(data[temp].singer, data[temp+1].singer);
			strcpy(data[temp].time, data[temp+1].time);
		}
	}
	total--;
	if(temp!=0) 
		printf("刪除成功\n");
	else if(temp==0)
		printf("沒有這首歌");
	Menu();
}

void Modify()
{
	int i,temp,choice;
	char song[100],singer[100],time[20];  //197.197 
	char song_change[100],singer_change[100],time_change[20];
	printf("輸入要修改的歌曲資訊(歌名、演唱者、歌曲長度):\n");
	scanf("%s %s %s",&song, &singer, &time);
	printf("需要修改的內容：\n1:歌名 2:演唱者 3:歌曲長度\n");
	scanf("%d",&choice);
	for(i=1; i<total; i++)
	{
		if(strcmp(song, data[i].song)==0)
		{
			temp=i;
			switch(choice)
			{
				case 1:
					printf("要更改為：\n");
					scanf("%s",&song_change);
					strcpy(data[i].song, song_change);
					break;
				case 2:
					printf("要更改為：\n");
					scanf("%s",&singer_change);
					strcpy(data[i].singer, singer_change);
					break;
				case 3:
					printf("要更改為：\n");
					scanf("%s",&time_change);
					strcpy(data[i].time, time_change);
					break;
				default:
					break;
			}
			break;
		}
	}
	printf("修改成功 song:%-70s, singer:%-40s, time:%-4s\n",data[temp].song, data[temp].singer, data[temp].time);
	Menu();
}

void Search()
{
	int i,count=1;
	char singer[100];
	printf("請輸入要搜尋演唱者:\n");
	scanf("%s",&singer);
	Sort(data);
	for(i=1; i<total; i++)
	{
		if(strcmp(singer, data[i].singer)==0)
		{
			printf("Song[%4d] song:%-70s, singer:%-40s time:%-4s\n",i, data[i].song, data[i].singer, data[i].time);
			count++;
		}
	}
	printf("%s 的歌曲有 %d 首歌：\n",singer,count-1);
	if(count==1)
		printf("無");
	Menu();
}

void Random()
{
	int a,count=1,i;
	int record[total];
	for(i=0; i<total; i++)
	{
		record[i]=0;
	}
	srand(time(NULL));
	while(count<=20)
	{
		a=(rand()%total)+1;
		if(record[a]==0)
		{
			printf("Song[%4d] song:%-70s, singer:%-40s time:%-4s\n",count, data[a].song, data[a].singer, data[a].time);
			record[a]=1;
			count++;
		}
	}
	Menu();
}
