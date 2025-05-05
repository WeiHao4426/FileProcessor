#include <stdio.h>
#include <stdlib.h>

#define M 10
#define N 35

typedef struct{
    char content[N];
    int length;
} String;

void setRandomString(String s);
void sortString(String sArray[]);

int main()
{
    srand(time(NULL));
    String sArray[M];
    int n = 0;
    for(;n < M;n ++)
    {
      setRandomString(sArray[n]);
    }
    sortString(sArray);
    for(;n < M;n ++)
    {
      int p = 0;
      printf("{");
      for(;p < sArray[n].length;p ++)
      {
          printf("%c",sArray[n].content[p]);
      }
      printf("},");
    }
    return 0;
}

void setRandomString(String s)
{
    s.length = rand()%(N-1)+1;
    int i = 0;
    int min = 'a';
    int max = 'z';
    for(;i < s.length;i ++)
    {
        s.content[i] = rand()%(max-min+1)+min;
        printf("%c",s.content[i]);
    }
    printf("\n");
    return;
}

void sortString(String sArray[])
{
    int i = 0;
    for(;i < M;i ++)
    {
        int n = 0;
        for(;n < M-i;n ++)
        {
            if(sArray[n].content[0] > sArray[n+1].content[0])
            {
                char a[sArray[n].length];
                int q = sArray[n].length;
                int c = 0;
                for(;c < sArray[n+1].length;c++)
                {
                    sArray[n].content[c] = sArray[n+1].content[c];
                }
                for(c = 0;c < sArray[n].length;c++)
                {
                    sArray[n+1].content[c] = a[c];
                }
                sArray[n].length =sArray[n+1].length;
                sArray[n=1].length = q;
            }
            else if(sArray[n].content[0] == sArray[n+1].content[0] && sArray[n].length > sArray[n+1].length)
            {
                char a[sArray[n].length];
                int q = sArray[n].length;
                int c = 0;
                for(;c < sArray[n+1].length;c++)
                {
                    sArray[n].content[c] = sArray[n+1].content[c];
                }
                for(c = 0;c < sArray[n].length;c++)
                {
                    sArray[n+1].content[c] = a[c];
                }
                sArray[n].length =sArray[n+1].length;
                sArray[n=1].length = q;
            }
        }
    }
    return;
}
