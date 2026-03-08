#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define MAX_SIZE 1000
#define MAX_LINE_SIZE 150

typedef struct{
    char name[61];
    char singer[41];
    int len; 
    int miniute;
    int second;
    int favorite;
}Song; 
Song songs[MAX_SIZE];
int idx = 0; 
int i=0;

typedef struct{
    char favorite_list_name[51];
}Favorite_list;
Favorite_list favorite_list[MAX_SIZE];
int favorite_count = 0; 

int SystemFunction(){
    printf("輸入對應數字\n");
    printf("1:新增歌曲, 2:刪除歌曲, 3:修改歌曲, 4:查詢歌曲, 5:加入(編輯)最愛清單, 6:查詢我的最愛清單, 7:隨機播放, 8:離開\n");
    int function_number;
    scanf("%d", &function_number);
    if(function_number == 1){ //新增 
        char name[61];
        char singer[41];
        char c;
        memset(name, 0, sizeof(name));
        memset(singer, 0, sizeof(singer));
        int miniute = 0;
        int second = 0;
        printf("輸入新歌曲的資訊\n");
        printf("輸入歌曲名稱(最多60個字):");
        while ((c = getchar()) != EOF && c != '\n'); 
        scanf("%60[^\n]%*c", name); 
        printf("名稱: %s\n", name);

        printf("輸入歌手名稱(最多40個字):");
        scanf("%40[^\n]%*c", singer);
        printf("歌手: %s\n", singer);

        printf("請輸入歌曲的長度(ex:2:10):");
        scanf("%d:%d", &miniute, &second);
        printf("時間: %d:%d\n", miniute, second);


        strcpy(songs[idx].name, name);
        strcpy(songs[idx].singer, singer);
        songs[idx].len = 60*miniute+second;
        songs[idx].miniute = miniute;
        songs[idx].second = second;
        songs[idx].favorite = -1;
        idx++;
        return 1;
    }
    else if(function_number == 2){ //刪除 
        printf("選擇刪除歌曲名稱或歌手\n");
        printf("1:刪除歌曲名稱, 2:刪除歌手\n");
        int delete_way;
        scanf("%d", &delete_way);
        if(delete_way == 1){ 
            while(1){ 
                printf("輸入要刪除的歌曲名稱:");
                char name[61];
                char c;
                int song_name_exist = 0;
                memset(name, 0, sizeof(name));
                while ((c = getchar()) != EOF && c != '\n');
                scanf("%60[^\n]%*c", name);

                for(i=0; i<idx; i++){
                    if(strcmp(songs[i].name, name) == 0){
                        song_name_exist = 1;
                        printf("歌曲名稱存在\n");
                        printf("刪除 %s\n", name);
                        if(i != idx-1){
                         
                            strcpy(songs[i].name, songs[idx-1].name);
                            strcpy(songs[i].singer, songs[idx-1].singer);
                            songs[i].len = songs[idx-1].len;
                            songs[i].miniute = songs[idx-1].miniute;
                            songs[i].second = songs[idx-1].second;
                            songs[i].favorite = songs[idx-1].favorite;
                        }
                        idx--;
                        break;
                    }
                }
                if(song_name_exist == 1) break;
                else printf("歌曲名稱不存在\n");
            }
        }
        else if(delete_way == 2){
            while(1){ 
                printf("輸入要刪除的歌手:");
                char singer[41];
                char c;
                int singer_name_exist = 0;
                memset(singer, 0, sizeof(singer));
                while ((c = getchar()) != EOF && c != '\n');
                scanf("%40[^\n]%*c", singer);

                for(i=0; i<idx; i++){
                    if(strcmp(songs[i].singer, singer) == 0){
                        singer_name_exist =1;
                        if(i != idx-1){
                          
                            strcpy(songs[i].name, songs[idx-1].name);
                            strcpy(songs[i].singer, songs[idx-1].singer);
                            songs[i].len = songs[idx-1].len;
                            songs[i].miniute = songs[idx-1].miniute;
                            songs[i].second = songs[idx-1].second;
                            songs[i].favorite = songs[idx-1].favorite;
                        }
                        idx--;
                    }
                }

                if(singer_name_exist == 1) {
                    printf("歌手名稱存在\n");
                    printf("刪除 %s\n", singer);
                    break;
                }
                else printf("歌手名稱不存在\n");
            }
        }

        return 1;
    }
    else if(function_number == 3){
        while(1){
            printf("輸入要修改的歌曲名稱:");
            char name[61];
            char singer[41];
            memset(name, 0, sizeof(name));
            memset(singer, 0, sizeof(singer));
            int miniute = 0;
            int second = 0;
            char c;
            int song_name_exist = 0;
            while ((c = getchar()) != EOF && c != '\n');
            scanf("%60[^\n]%*c", name);

            for(i=0; i<idx; i++){
                if(strcmp(songs[i].name, name) == 0){
                    song_name_exist =1;
                    printf("歌曲名稱存在.\n");
                    printf("輸入歌曲名稱(最多60字):");
                    scanf("%60[^\n]%*c", name);
                    printf("名稱: %s\n", name);

                    printf("輸入歌手(最多40字):");
                    scanf("%40[^\n]%*c", singer);
                    printf("歌手: %s\n", singer);

                    printf("輸入歌曲時間(ex.2:10):");
                    scanf("%d:%d", &miniute, &second);
                    printf("時間: %d:%d\n", miniute, second);

                    strcpy(songs[i].name, name);
                    strcpy(songs[i].singer, singer);
                    songs[i].len = 60*miniute+second;
                    songs[i].miniute = miniute;
                    songs[i].second = second;
                    printf("修改成功\n");
                    break;
                }
            }
            if(song_name_exist == 1) break;
            else printf("歌曲名稱不存在\n");
        }

        return 1;
    }
    else if(function_number == 4){ 
        while(1){ 
            printf("輸入要查詢的歌手名稱:");
            char singer[41];
            char c;
            int singer_name_exist = 0;
            memset(singer, 0, sizeof(singer));
            while ((c = getchar()) != EOF && c != '\n');
            scanf("%40[^\n]%*c", singer);

            for(i=0; i<idx; i++){
                if(strcmp(songs[i].singer, singer) == 0){
                    singer_name_exist =1;
                    printf("%-60s, 歌手: %-40s, 時間: %d:%d\n", songs[i].name, songs[i].singer, songs[i].miniute, songs[i].second);
                }
            }

            if(singer_name_exist == 1) break;
            else printf("歌曲名稱不存在\n");
        }
        return 1;
    }
    else if(function_number == 5){ 
        while(1){ 
            printf("輸入要添加到最愛清單的歌曲名稱:");
            char name[61];
            char c;
            int song_name_exist = 0;
            int song_idx;
            memset(name, 0, sizeof(name));
            while ((c = getchar()) != EOF && c != '\n');
            scanf("%60[^\n]%*c", name);

            for(i=0; i<idx; i++){
                if(strcmp(songs[i].name, name) == 0){
                    song_name_exist =1; 
                    printf("歌曲名稱存在\n");
                    printf("現在有%d個最愛清單\n", favorite_count);
                    int j;
                    for(j=0; j<favorite_count; j++){ 
                        printf("最愛清單號碼%d: %s\n\n", j, favorite_list[j].favorite_list_name);
                    }
                    printf("要將歌曲添加到哪個最愛清單\n");
                    printf("輸入最愛清單的號碼 輸入1000建立新的最愛清單\n");
                    int num;
                    scanf("%d", &num);
                    if(num == 1000){
                        printf("輸入新的最愛清單的名稱:");
                        while ((c = getchar()) != EOF && c != '\n');
                        char new_favorite_name[51];
                        scanf("%50[^\n]%*c", new_favorite_name);
                        printf("新增的最愛清單名稱: %s\n", new_favorite_name);
                        strcpy(favorite_list[favorite_count].favorite_list_name, new_favorite_name);
                        songs[i].favorite = favorite_count;
                        printf("新增歌曲到最愛清單的號碼 %d.\n", favorite_count);
                        favorite_count++;
                    }
                    else{
                        songs[i].favorite = num;
                        printf("新增歌曲到最愛清單的號碼 %d.\n", num);      
                    }
                    break;
                }
            }
            if(song_name_exist == 1) break;
            else printf("歌曲名稱不存在\n");
        }

        return 1;
    }
    else if(function_number == 6){ 
        while(1){ 
            printf("輸入最愛清單的名稱:");
            char favorite_list_name[51];
            char c;
            int favorite_exist = 0;
            memset(favorite_list_name, 0, sizeof(favorite_list_name));
            while ((c = getchar()) != EOF && c != '\n');
            scanf("%60[^\n]%*c", favorite_list_name);

            for(i=0; i<favorite_count; i++){
                if(strcmp(favorite_list[i].favorite_list_name, favorite_list_name) == 0){
                    favorite_exist = 1;
                    printf("歌曲在 %s:\n", favorite_list_name);
                    int j;
                    for(j=0; j<idx; j++){
                        if(songs[j].favorite == i){
                            printf("%-60s, 歌手: %-40s, 時間: %d:%d\n", songs[j].name, songs[j].singer, songs[j].miniute, songs[j].second);
                        }
                    }
                    break;
                }
            }
            if(favorite_exist == 1) break;
            else printf("歌曲名稱不存在\n");
        }
        return 1;
    }
    else if(function_number == 7){ 
        srand(time(NULL));
        int visited[idx];
        memset(visited, 0, sizeof(visited));
        printf("隨機選取20首歌:\n");
        for(i=0; i<20; i++){ 
            int r = rand()%idx; 
            if(!visited[r]){
                visited[r] = 1;
                printf("%-60s, 歌手: %-40s, 時間: %d:%d\n", songs[r].name, songs[r].singer, songs[r].miniute, songs[r].second);
            }
        }
        return 1;
    }
    else if(function_number == 8){ 
        printf("---------------------------\n\n");
        printf("結束!\n\n");
        printf("---------------------------\n\n");
        return 0;
    }
    else{
        printf("輸入錯誤\n");
        return 1;
    }
}



int main(){
    /*
    ----- read csv -----
    */
    char file_name[] = "songlist.csv"; 
    FILE *fp;
    fp = fopen(file_name, "r"); //r: can read
    if(fp == NULL){
        printf("Error opening file.\n");
        return 1;
    }

    char line[150];
    memset(line, 0, sizeof(line));
    char tmp[100];
    memset(tmp, 0, sizeof(tmp));
    int line_len = 0;
    int in_double_quote = 0;
    int k=0;
    int is_first = 1;
    while(fgets(line, MAX_LINE_SIZE, fp) != NULL){
        line_len = strlen(line);
        k=0;
        for(i=0; i<line_len; i++){
            if(line[i] == '"'){
                in_double_quote = !in_double_quote;
            }
            else if(line[i] == ',' && !in_double_quote){
                if(is_first){
                    strcpy(songs[idx].name, tmp);
                    is_first = 0;
                }
                else{
                    strcpy(songs[idx].singer, tmp);
                    is_first = 1;
                }

                memset(tmp, 0, sizeof(tmp));
                k=0;
                continue;
            }
            else if(line[i] == '\n'){
                songs[idx].len = atoi(tmp);
                songs[idx].miniute = songs[idx].len/60;
                songs[idx].second = songs[idx].len%60;
                memset(tmp, 0, sizeof(tmp));
                k=0;
                continue;
            }
            tmp[k] = line[i];
            k++;
        }
        memset(line, 0, sizeof(line));
        idx++;


        if(ferror(fp)){
            printf("Error reading file.\n");
            return 1;
        }
    }

    fclose (fp);//close csv

    for(i=0; i<idx; i++){
        songs[i].favorite = -1;
    }
    /*
    ----- system function -----
    */
    while(SystemFunction());


    /*
    ----- write csv -----
    */
    char new_file_name[] = "new-songlist.csv";
    fp = fopen(new_file_name, "w"); //w: can write
    if(fp == NULL){
        printf("Error opening file.\n");
        return 1;
    }

    for(i=0; i<idx; i++){
        fprintf(fp,
                "%s,%s,%d:%02d\n",
                songs[i].name, songs[i].singer, songs[i].miniute, songs[i].second);
        if(ferror(fp)){
            printf("Error writing to file.\n");
            return 1;
        }
    }
    fclose(fp);

    char favorite_file_name[] = "favorite-songlist.csv";
    fp = fopen(favorite_file_name, "w"); //w: can write
    if(fp == NULL){
        printf("Error opening file.\n");
        return 1;
    }

    for(i=0; i<favorite_count; i++){
        int j;
        for(j=0; j<idx; j++){
            if(songs[j].favorite == i){
                fprintf(fp,
                    "Favorite list %d: Song name:%-60s, Singer:%-40s, %d:%02d\n",
                    i, songs[j].name, songs[j].singer, songs[j].miniute, songs[j].second);
            }
        }

        if(ferror(fp)){
            printf("Error writing to file.\n");
            return 1;
        }
    }
    fclose(fp);

    return 0;
}
