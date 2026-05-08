#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define Maxs 1005

void del_newline(char *s){
    int len=strlen(s);
    while(len>0&&(s[len-1]=='\n'||s[len-1]=='\r')){
        s[len-1]='\0';
        --len;
    }
}

void make_lower(const char *src,char *dst){
    int len=strlen(src);
    for(int i=0;i<len;++i){
        dst[i]=(char)tolower((unsigned char)src[i]);
    }
    dst[len]='\0';
}

int main(){
    FILE *fin=fopen("filein.txt","r");
    FILE *fout=fopen("fileout.txt","w");
    char olds[Maxs],news[Maxs];

    if(fin==NULL||fout==NULL){
        if(fin!=NULL)fclose(fin);
        if(fout!=NULL)fclose(fout);
        return 0;
    }

    if(fgets(olds,Maxs,stdin)==NULL){
        fclose(fin);
        fclose(fout);
        return 0;
    }
    if(fgets(news,Maxs,stdin)==NULL){
        fclose(fin);
        fclose(fout);
        return 0;
    }

    del_newline(olds);
    del_newline(news);

    int old_len=strlen(olds);
    int new_len=strlen(news);

    if(old_len==0){
        int ch;
        while((ch=fgetc(fin))!=EOF){
            fputc(ch,fout);
        }
        fclose(fin);
        fclose(fout);
        return 0;
    }

    fseek(fin,0,SEEK_END);
    long file_len=ftell(fin);
    rewind(fin);

    char *src=(char*)malloc((file_len+1)*sizeof(char));
    char *low=(char*)malloc((file_len+1)*sizeof(char));

    if(src==NULL||low==NULL){
        free(src);
        free(low);
        fclose(fin);
        fclose(fout);
        return 0;
    }

    long real_len=fread(src,1,file_len,fin);
    src[real_len]='\0';
    make_lower(src,low);

    char *old_low=(char*)malloc((old_len+1)*sizeof(char));
    if(old_low==NULL){
        free(src);
        free(low);
        fclose(fin);
        fclose(fout);
        return 0;
    }
    make_lower(olds,old_low);

    int i=0;
    while(i<real_len){
        int ok=1;
        if(i+old_len>real_len){
            ok=0;
        }else{
            for(int j=0;j<old_len;++j){
                if(low[i+j]!=old_low[j]){
                    ok=0;
                    break;
                }
            }
        }

        if(ok){
            fwrite(news,1,new_len,fout);
            i+=old_len;
        }else{
            fputc(src[i],fout);
            ++i;
        }
    }

    free(src);
    free(low);
    free(old_low);
    fclose(fin);
    fclose(fout);
    return 0;
}