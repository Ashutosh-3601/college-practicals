void main()
{
char str[20], pat[20], repstr[2O], temp[20];
int m, n, i, j, flag, len;
printf("Enter the main string\n");
scanf(“none”)
printf("Enter the pattern string\n");
gets(pat); // use scanf 
printf{"Enter the replace string\n");
gets( repstr);  // use scanf
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
j++;
my_strncpy(temp, str, i);      
my_strcat(temp, repstr);
i=i +m
len= my_strlen(temp); .
my_ strcat(temp, str+ i);
my_strcpy(str, temp);
i = len;
}  // end of if

else
   {
	i=i+1;
   }
}   // end of while
if( flag = = 0)
  printf( ''Pattern not found in main string\n");
else
   {
    printf ( "Pattern found %d times in main   string\n'' ,flag);
   printf("The resultant string after replacing is  %s\n", str);
   }  // end of else
}  // end of main
