#include<stdio.h>

int main()
{FILE *fp,*fp1;
char ch;
fp=fopen("map.txt","r");
fp1 = fopen("viewer.js","w");
int l=0;
while((ch=fgetc(fp))!=EOF)
l++;
close(fp);
fp=fopen("map.txt","r");
int i=0;
fputs("var map=[\"\0",fp1);
while((ch=fgetc(fp))!=EOF)
{i++;
if(ch=='\n')
{if(i!=l)
fputs("\",\"",fp1);
}
else
fputc(ch,fp1);
}
fputs("\"];\n",fp1);
close(fp);

fp=fopen("map.txt","r");
i=0;
fputs("var map2=[\"\0",fp1);
while((ch=fgetc(fp))!=EOF)
{i++;
if(ch=='\n')
{if(i!=l)
fputs("\",\"",fp1);
}
else
fputc(ch,fp1);
}
fputs("\"];\n",fp1);
fputs("var reverse_trace = [\n[",fp1);
fp=fopen("trace.txt","r");
l=0;
while((ch=fgetc(fp))!=EOF)
l++;
i=0;
fp=fopen("trace.txt","r");
while((ch=fgetc(fp))!=EOF)
{i++;
if(ch==' ')
fputc(',',fp1);
if(ch=='\n')
{if(i!=l)
fputs("],\n[",fp1);
}
else
fputc(ch,fp1);
}
fputs("]\n];\n",fp1);
fclose(fp);
fp=fopen("viewer_code.js","r");
while((ch=fgetc(fp))!=EOF)
{fputc(ch,fp1);
}
close(fp);
close(fp1);

}




