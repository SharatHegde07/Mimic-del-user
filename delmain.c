//####################################################################################################################################################
//****************************************************************************************************************************************************
//PROGRAMME TO MIMIC THE "deluser" COMMAND IN LINUX USING C...........................................................
/*This programme asks the user for input.input is basically a username
when u give the username as input,the user information from the four files named
passwd,shadow,group,gshadow will be removed.if the username is not present it will
not make anu changes to the file.The files should be present in the C:/PESU folder(not necessarily)
as entioned in the question.*/


/*READ ME BEFORE COMPILING THE PROGRAMME:
1.)The four files as mentioned in the question should be present in the PESU folder inside LOCAL DISK C:
2.)Place all the compiling  files in a new folder in Desktop.
3.)in the command prompt navigate to the folder containing programme files
4.)use "mingw32-make -f makefile.mak" without quotes to execute the programme
5.)After compilation type deluser username to execute the programme successfully*/

//##########################################THANK YOU FOR READING#########################################################//



#include<stdio.h>
#include<string.h>
#include"delserver.h"
void deluser(char username[])                   //Defining the fucntion to mimic the deluser command
{
  char ch1,ch2,ch3,ch4;                        //These characters are for traversing through the 4 files
  int pline=1,sline=1,gline=1,gsline=1,pn=1,sn=1,gn=1,gsn=1,c=0;  //pline,pn,sline,sn etc... thery are for identifying the line where the username comes in the file
  int d=strlen(username),k;
  char s[100],q[100],p[100],a[100];
                                                //s,q,p,a are the strings for reading through filepointers pass,shadow,gshadow and group respectively
  FILE *pass=fopen("C:/PESU/passwd","r");
  FILE *newpass;
  FILE *shadow=fopen("C:/PESU/shadow","r");
  FILE *newshadow;
  FILE *gshadow=fopen("C:/PESU/gshadow","r");
  FILE *newgshadow;
  FILE *group=fopen("C:/PESU/group","r");
  FILE *newgroup;
  while(fgets(s,d+1,pass)!=NULL)                /*This part of the code inlcuding while loop looks
                                                for the line where the username comes and stores it in
                                                pline.this loop is for filepointer pass and the coming
                                                next three loops are for remaning file pointers*/
  {
    k=strlen(s);
    if(s[k-1]=='\n')
    pline++;
    if(strcmp(s,username)==0)
    {
      c=-1;
      break;
    }
  }
  if(c==0)
  {                                                   //This condition is for checking whether the entered user is present in the file or not
  printf("USER NOT FOUND!");
  return;}
  while(fgets(q,d+1,shadow)!=NULL)
  {
    k=strlen(q);
    if(q[k-1]=='\n')
    sline++;
    if(strcmp(q,username)==0)
    break;
  }
  while(fgets(p,d+1,gshadow)!=NULL)
  {
    k=strlen(p);
    if(p[k-1]=='\n')
    gsline++;
    if(strcmp(p,username)==0)
    break;
  }
  while(fgets(a,d+1,group)!=NULL)
  {
    k=strlen(a);
    if(a[k-1]=='\n')
    gline++;
    if(strcmp(a,username)==0)
    break;
  }
  rewind(pass);                                    //The rewind fucntion sets the filepointer to read from beginning and it is done for all four of them
  rewind(shadow);
  rewind(gshadow);
  rewind(group);
  //open new file in write mode
  newpass = fopen("C:/PESU/replica1","w");         //Opening four new filepointers in write mode
  newshadow = fopen("C:/PESU/replica2","w");
  newgshadow=fopen("C:/PESU/replica3","w");
  newgroup= fopen("C:/PESU/replica4","w");
                                                  /*The coming next 4 loops copy the content of existing file
                                                  to a new file except the line in which username comes*/
  while ((ch1=fgetc(pass))!= EOF)
  {
    if (ch1=='\n')
      pn++;
    if (pn!=pline)
    {
      fputc(ch1,newpass);
    }
  }

  while ((ch2=fgetc(shadow))!= EOF)
  {
    if (ch2=='\n')
      sn++;
    if (sn!=sline)
    {
      fputc(ch2,newshadow);
    }
  }

  while ((ch3=fgetc(gshadow))!= EOF)
  {

    if (ch3=='\n')
      gsn++;
    if (gsn!=gsline)
    {
      fputc(ch3,newgshadow);
    }
  }

  while ((ch4=fgetc(group))!= EOF)
  {

    if (ch4=='\n')
      gn++;
    if (gn!=gline)
    {
      fputc(ch4,newgroup);
    }
  }
  fclose(pass);                                     //clsoing all the files
  fclose(newpass);
  fclose(shadow);
  fclose(newshadow);
  fclose(gshadow);
  fclose(newgshadow);
  fclose(group);
  fclose(newgroup);
  remove("C:/PESU/passwd");                      //Removing the original files named as shown in the programme
  remove("C:/PESU/shadow");
  remove("C:/PESU/gshadow");
  remove("C:/PESU/group");
  rename("C:/PESU/replica1","C:/PESU/passwd");  //Now renaming the 4 copied files to the original name
                                                //They contains all the details of the other users excpet the one which you asked to delete for
  rename("C:/PESU/replica2","C:/PESU/shadow");
  rename("C:/PESU/replica3","C:/PESU/gshadow");
  rename("C:/PESU/replica4","C:/PESU/group");
}
