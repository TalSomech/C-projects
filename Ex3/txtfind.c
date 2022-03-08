#include <stdio.h>
#include <string.h>

#define line 256
#define word 30

int get_line(char s[]) {
    if(fgets(s, line, stdin)==NULL)
        return -1;
    return strlen(s);
}

int getword(char w[]) {
    char temp;
    for (int i = 0; i < word; ++i) {
        temp = fgetc(stdin);
        if(temp == EOF){
            return -1;
        }
        if (temp=='\n'||temp== ' '|| temp == '\t') {
            w[i]='\0';
            break;
        }
        w[i] = temp;
    }
    return strlen(w);
}

int substring(char *sen1, char *str2) {
    int cmp = 0;
    char wrd[30];
    int k=0;
    if (strlen(str2) > strlen(sen1))
        return 0;
    for (int i = 0, j = 0; i < strlen(sen1); i++) {
        if(sen1[i]==' '||sen1[i]=='\r'||sen1[i]=='\n'){
            wrd[k]='\0';
            if(strlen(str2)==(strlen(wrd)-1)||strlen(str2)==(strlen(wrd)))
                return 1;
            cmp=0;
            wrd[0]='\0';
            j=k=0;
        }
        if (sen1[i] == str2[j]) {
            cmp++;
            j++;
        }
        if(cmp>0){
            wrd[k]=sen1[i];
            k++;
        }
    }
    return 0;
}

int similar(char *s, char *t, int n){
    int cmp = 0;
    if (strlen(t) > strlen(s))
        return 0;
    for(int i = 0, j = 0; i < strlen(s) && cmp < strlen(t); i++) {
        if(s[i]==' '||s[i]=='\t'){
            cmp=0;
        }
        if (s[i] == t[j]) {
            cmp++;
            j++;
        }
    }
    if(s[strlen(s)-1]=='\r'){
        s[strlen(s)-1]='\0';
    }
    if(cmp!=strlen(t))
        return 0;
    if(cmp==strlen(s))
        return 1;
    return (cmp==strlen(s)-n)?1 : 0;
}

void print_lines(char *str){
    char text[line];
    while(get_line(text)!=-1){
        if(substring(text,str))
            printf("%s",text);
    }
}

void print_similar_words(char *str){
    char wrd[word];
    while(getword(wrd)!=-1){
        if(similar(wrd,str,1))
            printf("%s \n",wrd);
    }
}

char splitFirst (char* wrd){
    char fl[34];
    fgets(fl,34,stdin);
    int i=0;
    while(fl[i]!=' '){
        wrd[i]= (char) fl[i];
        i++;
    }
    wrd[i]='\0';
    return (char) fl[i + 1];
}
int main(){
    char wrd[34];
    char oper=splitFirst(wrd);
    if(oper=='a'){
        print_lines(wrd);
    }
    if(oper=='b'){
        print_similar_words(wrd);
    }
    return 0;
}