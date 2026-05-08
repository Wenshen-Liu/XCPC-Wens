#include<stdio.h>
#include<string.h>

int main(){
    char key[100];
    if(!fgets(key,sizeof(key),stdin))return 0;

    char ring[100];
    int ring_size=0;
    int used[128]={0};

    for(int i=0;key[i]!='\0';++i){
        if(32<=key[i]&&key[i]<=126){
            if(!used[(int)key[i]]){
                used[(int)key[i]]=1;
                ring[ring_size++]=key[i];
            }
        }
    }

    for(int i=32;i<=126;++i){
        if(!used[i])ring[ring_size++]=i;
    }

    char map[128]={0};
    int curr_index=0;
    char plain=ring[0];
    char first_char=plain;

    for(int step=0;step<94;++step){
        int asc=plain;

        for(int i=curr_index;i<ring_size-1;++i){
            ring[i]=ring[i+1];
        }
        --ring_size;

        curr_index=(curr_index+asc-1)%ring_size;
        char cipher=ring[curr_index];

        map[(int)plain]=cipher;
        plain=cipher;
    }

    map[(int)ring[0]]=first_char;

    FILE *fin=fopen("in.txt","r");
    FILE *fout=fopen("in_crpyt.txt","w");
    if(!fin||!fout)return 0;

    int ch;
    while((ch=fgetc(fin))!=EOF){
        if(32<=ch&&ch<=126)fputc(map[ch],fout);
        else fputc(ch,fout);
    }

    fclose(fin);
    fclose(fout);
    return 0;
}