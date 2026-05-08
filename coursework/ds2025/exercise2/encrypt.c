#include<stdio.h>
#include<string.h>

#define Maxn 105

char keys[Maxn];
char mp[30];
int vis[30];

int main(){
    scanf("%s",keys);
    int len=strlen(keys),tot=0;
    for(int i=0;i<len;++i){
        int x=keys[i]-'a';
        if(!vis[x]){
            vis[x]=1;
            mp[tot++]=keys[i];
        }
    }
    for(char c='z';c>='a';--c){
        int x=c-'a';
        if(!vis[x]){
            vis[x]=1;
            mp[tot++]=c;
        }
    }

    FILE *fin=fopen("encrypt.txt","r");
    FILE *fout=fopen("output.txt","w");
    if(fin==NULL||fout==NULL){
        if(fin!=NULL)fclose(fin);
        if(fout!=NULL)fclose(fout);
        return 0;
    }

    int ch;
    while((ch=fgetc(fin))!=EOF){
        if(ch>='a'&&ch<='z')fputc(mp[ch-'a'],fout);
        else fputc(ch,fout);
    }

    fclose(fin);
    fclose(fout);
    return 0;
}