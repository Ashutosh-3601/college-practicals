#include<stdio.h>

int my_strlen(const char array[]){
  int i;
  for(i = 0; array[i] != '\0'; i++);
  return i;
}

void my_strcpy(char  * final, const char * source){
  int i;
  for(i = 0; source[i] != '\0'; i++){
    final[i] = source[i];
  }
  final[i] = '\0';
}

void my_strncpy(char  * final, const char * source, const int num){
  int i;
  for(i = 0; i < num; i++){
    final[i] = source[i];
  }
  final[i] = '\0';
}

void my_strcat(char * first, char const * second){
  int i, len = my_strlen(first);
  for(i = 0; second[i] != '\0'; i++){
    first[len + i] = second[i];
  }
  first[len+i] = '\0'; 
}

int main()
{
char str[20], pat[20], repstr[20], temp[20];
int m, n, i, j, flag, len;
printf("Enter the main string\n");
scanf("%[^\n]s", str);
getchar();
printf("Enter the pattern string\n");
scanf("%[^\n]s", pat); // use scanf
getchar(); 
printf("Enter the replace string\n");
scanf("%[^\n]s", repstr);
getchar();  // use scanf
m = my_strlen(pat);
flag= 0;
i=0;
while( str[i]!= '\0')
{
for(j =0;j <m;j++)
{
if(str[i+j] != pat[j])
 break;
}       // end of for
if(j==m)
{
flag++;
my_strncpy(temp, str, i);      
my_strcat(temp, repstr);
i=i +m;
len= my_strlen(temp);
my_strcat(temp, str+ i);
my_strcpy(str, temp);
i = len;
}  // end of if

else
   {
	i=i+1;
   }
}   // end of while
if( flag == 0)
  printf( "Pattern not found in main string\n");
else
   {
    printf ( "Pattern found %d times in main   string\n" ,flag);
   printf("The resultant string after replacing is  %s\n", str);
   }  // end of else
  }  // end of main
