#include<string.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>
#include <conio.h>

//Create structure for node
struct Hospital
{
    int Patient_Id;
    char P_Firstname[150];
    char P_Lastname[150];
    char NIC[100];
    char Gender[100];
    char P_phonenum[100];
    char disease[150];
    struct Hospital *next;
}*head;

void create(int Patient_Id,char* P_phonenum,char*P_Firstname,char*P_Lastname,char*NIC,char*Gender,char*disease)
{
    struct Hospital *hospital=(struct Hospital*)malloc(sizeof(struct Hospital));
      if(hospital==NULL)
      {
          printf("\nOut of Memory Space:\n");
          return;
      }
      hospital->Patient_Id=Patient_Id;
      strcpy(hospital->P_Firstname,P_Firstname);
      strcpy(hospital->P_Lastname,P_Lastname);
      strcpy(hospital->NIC,NIC);
      strcpy(hospital->Gender,Gender);
      strcpy(hospital->P_phonenum,P_phonenum);
      strcpy(hospital->disease,disease);
      hospital->next=NULL;

     if (head==NULL)
     {
         head=hospital;
     }
     else
     {
         hospital->next=head;
         head =hospital;
     }
      printf("\n\n");
      printf("\t\t\t\tPress any key to continue!!!!");
}

void display()
{
    struct Hospital *hospital=head;
    if (hospital==NULL)
    {
      printf("\t\t\t\tPatient ID %d is not found\n",hospital->Patient_Id);
      exit(0);
    }

    while(hospital!=NULL)
    {

            printf("\t\t\t\tPatient ID          :%d\n",hospital->Patient_Id);
            printf("\t\t\t\tPatient First Name  :%s\n",hospital->P_Firstname);
            printf("\t\t\t\tPatient Last Name   :%s\n",hospital->P_Lastname);
            printf("\t\t\t\tPatient NIC         :%s\n",hospital->NIC);
            printf("\t\t\t\tPatient Gender      :%s\n",hospital->Gender);
            printf("\t\t\t\tPatient Phone Number:%s\n",hospital->P_phonenum);
            printf("\t\t\t\tPatient Disease     :%s\n",hospital->disease);
            printf("\t\t\t\t---------------------------\n");
            printf("\n");
            hospital=hospital->next;
    }
     printf("\n\n");
    printf("\t\t\t\tPress any key to continue!!!!");
}
//Function for insert a node into front of the list
void insert_begin(int Patient_Id,char* P_phonenum,char*P_Firstname,char*P_Lastname,char*NIC,char*Gender,char*disease)
{
   struct Hospital *hospital=(struct Hospital*)malloc(sizeof(struct Hospital));
      if(hospital==NULL)
      {
          printf("\t\t\t\t\nOut of Memory Space:\n");
          return;
      }
      hospital->Patient_Id=Patient_Id;
      strcpy(hospital->P_Firstname,P_Firstname);
      strcpy(hospital->P_Lastname,P_Lastname);
      strcpy(hospital->NIC,NIC);
      strcpy(hospital->Gender,Gender);
      strcpy(hospital->P_phonenum,P_phonenum);
      strcpy(hospital->disease,disease);
      hospital->next=NULL;

     if (head==NULL)
     {
         head=hospital;
     }
     else
     {
         hospital->next=head;
         head =hospital;
     }
      printf("\n\n");
    printf("\t\t\t\tPress any key to continue!!!!");
}
//Function for insert a node into end of the list
void insert_end(int Patient_Id,char* P_phonenum,char*P_Firstname,char*P_Lastname,char*NIC,char*Gender,char*disease)
{
   struct Hospital *hospital,*ptr;
   hospital=(struct Hospital*)malloc(sizeof(struct Hospital));
      if(hospital==NULL)
      {
          printf("\t\t\t\t\nOut of Memory Space:\n");
          return;
      }
      hospital->Patient_Id=Patient_Id;
      strcpy(hospital->P_Firstname,P_Firstname);
      strcpy(hospital->P_Lastname,P_Lastname);
      strcpy(hospital->NIC,NIC);
      strcpy(hospital->Gender,Gender);
      strcpy(hospital->P_phonenum,P_phonenum);
      strcpy(hospital->disease,disease);
      hospital->next=NULL;

     if (head==NULL)
     {
         head=hospital;
     }
     else
     {
         ptr=head;
         while(ptr->next!=NULL)
         {
             ptr=ptr->next;
         }
         ptr->next=hospital;
     }
      printf("\n\n");
      printf("\t\t\t\tPress any key to continue!!!!");
}
//Function for insert node into middle position in the list
void insert_position(int Patient_Id,char* P_phonenum,char*P_Firstname,char*P_Lastname,char*NIC,char*Gender,char*disease)
{
    struct Hospital*ptr,*hospital;
    int i,position;
    hospital=(struct Hospital*)malloc(sizeof(struct Hospital));
    if(hospital==NULL)
    {
      printf("\t\t\t\t\nOut of Memory Space:\n");
          return;
    }
      hospital->Patient_Id=Patient_Id;
      printf("\t\t\t\t\nEnter the position for the new node to be insert:");
      scanf("%d",&position);
      printf("\n");
      strcpy(hospital->P_Firstname,P_Firstname);
      strcpy(hospital->P_Lastname,P_Lastname);
      strcpy(hospital->NIC,NIC);
      strcpy(hospital->Gender,Gender);
      strcpy(hospital->P_phonenum,P_phonenum);
      strcpy(hospital->disease,disease);
      hospital->next=NULL;
    if (position==0)
    {
        hospital->next=head;
        head=hospital;
    }
    else
    {
        for(i=0,ptr=head;i<position-1;i++)
        {
            ptr=ptr->next;
            if(ptr==NULL)
            {
                printf("\t\t\t\t\n Position not found:\n");
                 printf("\n\n");
                 printf("\t\t\t\tPress any key to continue!!!!");
                return;
            }
        }
        hospital->next=ptr->next;
        ptr->next=hospital;
    }
     printf("\n\n");
    printf("\t\t\t\tPress any key to continue!!!!");
}

void discharge(int Patient_Id)
{
    struct Hospital*hospital1=head;
    struct Hospital*hospital2=head;
    while(hospital1 !=NULL)
    {
        if(hospital1->Patient_Id==Patient_Id)
        {
           printf("\t\t\t\tRecord with ID  %d Found !!!\n", Patient_Id);
           printf("\n\n");


           if(hospital1==hospital2)
            {
            head = head->next;
            free(hospital1);
           }
           else
           {
               hospital2->next=hospital1->next;
               free(hospital1);
           }
           printf("\t\t\t\tRecord Successfully Removed !!!\n");
            printf("\n\n");
            printf("\t\t\t\tPress any key to continue!!!!");

			return;

        }
        hospital2=hospital1;
        hospital1=hospital1->next;
    }
    printf("\t\t\t\tPatient with ID %d is not found !!!\n", Patient_Id);
     printf("\n\n");
    printf("\t\t\t\tPress any key to continue!!!!");

}

void search(int Patient_Id)
{

    struct Hospital*hospital=head;
    while(hospital!=NULL){
        if(hospital->Patient_Id==Patient_Id)
        {

            printf("\t\t\t\t---------------------------\n");
            printf("\n");
            printf("\t\t\t\tPatient ID          :%d\n",hospital->Patient_Id);
            printf("\t\t\t\tPatient First Name  :%s\n",hospital->P_Firstname);
            printf("\t\t\t\tPatient Last Name   :%s\n",hospital->P_Lastname);
            printf("\t\t\t\tPatient NIC         :%s\n",hospital->NIC);
            printf("\t\t\t\tPatient Gender      :%s\n",hospital->Gender);
            printf("\t\t\t\tPatient Phone Number:%s\n",hospital->P_phonenum);
            printf("\t\t\t\tPatient Disease     :%s\n",hospital->disease);
            printf("\n");
            printf("\t\t\t\t---------------------------\n");
            printf("\n\n");
            printf("\t\t\t\tPress any key to continue!!!!");
            return;
        }
        hospital=hospital->next;

    }
    printf("\t\t\t\tPatient ID %d is not found\n",Patient_Id);
    printf("\n\n");
    printf("\t\t\t\tPress any key to continue!!!!");
}

void update(int Patient_Id)
{
    int up_record;
    struct Hospital*hospital=head;
     while (hospital!=NULL)
     {
           if(hospital->Patient_Id==Patient_Id)
        {

            printf("\t\t\t\t---------------------------\n");
            printf("\n");
            printf("\t\t\t\t\n Record with patient ID %d found!!\n",Patient_Id);
            printf("---------------------------\n");
            printf("\n");
            printf("\t\t\t\tPatient ID          :%d\n",hospital->Patient_Id);
            printf("\t\t\t\tPatient First Name  :%s\n",hospital->P_Firstname);
            printf("\t\t\t\tPatient Last Name   :%s\n",hospital->P_Lastname);
            printf("\t\t\t\tPatient NIC         :%s\n",hospital->NIC);
            printf("\t\t\t\tPatient Gender      :%s\n",hospital->Gender);
            printf("\t\t\t\tPatient Phone Number:%s\n",hospital->P_phonenum);
            printf("\t\t\t\tPatient Disease     :%s\n",hospital->disease);
            printf("\t\t\t\t---------------------------\n");
            printf("\n");
            printf("\t\t\t\tEnter the Number of Records you want to update\n");
            printf("\t\t\t\t---------------------------\n");
            printf("\n");
           printf("\t\t\t\t1.Patient First Name     :\n") ;
           printf("\t\t\t\t2.Patient Last Name      :\n") ;
           printf("\t\t\t\t3.Patient NIC            :\n") ;
           printf("\t\t\t\t4.Patient Gender         :\n") ;
           printf("\t\t\t\t5.Patient Phone Number   :\n") ;
           printf("\t\t\t\t6.Patient Disease        :\n") ;
           printf("\t\t\t\t7.Nothing to update              :\n") ;
           printf("\t\t\t\t---------------------------\n") ;

           printf("\t\t\t\t\n Enter your Choice:");
           scanf("%d",&up_record);
           printf("\n");
           switch(up_record)
           {
           case 1 :
            printf("\t\t\t\tEnter New  First Name :\t");
            scanf("%s",hospital->P_Firstname);
            printf("\t\t\t\tUpdated Successfully!\n");
            break;
           case 2 :
            printf("\t\t\t\tEnter New  Last Name  :\t");
            scanf("%s",hospital->P_Lastname);
            printf("\t\t\t\tUpdated Successfully!\n");
            break;
           case 3 :
            printf("\t\t\t\tEnter New  NIC        :\t");
            scanf("%s",hospital->NIC);
            printf("\t\t\t\tUpdated Successfully!\n");
            break;
           case 4 :
            printf("\t\t\t\tEnter New  Gender      :\t");
            scanf("%s",hospital->Gender);
            printf("\t\t\t\tUpdated Successfully!\n");
            break;
           case 5 :
            printf("\t\t\t\tEnter New  Phone Number:\t");
            scanf("%s",hospital->P_phonenum);
            printf("\t\t\t\tUpdated Successfully!\n");
            break;
           case 6 :
            printf("\t\t\t\tEnter New  Disease     :\t");
            scanf("%s",hospital->disease);
            printf("\t\t\t\tUpdated Successfully!\n");
            break;
           case 7 :
            exit(0);
            break;
           default:
            printf("\t\t\t\t\n Wrong Choice         :\n");
            break;

           }

           printf("\t\t\t\t---------------------------\n");
            printf("\n");
            printf("\t\t\t\tPatient ID          :%d\n",hospital->Patient_Id);
            printf("\t\t\t\tPatient First Name  :%s\n",hospital->P_Firstname);
            printf("\t\t\t\tPatient Last Name   :%s\n",hospital->P_Lastname);
            printf("\t\t\t\tPatient NIC         :%s\n",hospital->NIC);
            printf("\t\t\t\tPatient Gender      :%s\n",hospital->Gender);
            printf("\t\t\t\tPatient Phone Number:%s\n",hospital->P_phonenum);
            printf("\t\t\t\tPatient Disease     :%s\n",hospital->disease);
            printf("\n");
            printf("---------------------------\n");
            printf("\n\n");
            printf("\t\t\t\tPress any key to continue!!!!");
            return;

        }
        hospital=hospital->next;

     }
     printf("\t\t\t\tPatient with ID %d is not found !!\n",Patient_Id);
     printf("\n\n");
     printf("\t\t\t\tPress any key to continue!!!!");
}

int main()
{
    head=NULL;

    int choice;
    int up_record;
    int Patient_Id;
    char P_Firstname[150];
    char P_Lastname[150];
    char NIC[100];
    char Gender[100];
    char P_phonenum[100];
    char disease[150];


    do
    {

        int x; double y;
        system("cls");
        system("COLOR 3D");
       char text1[]=    "\n \t\t\t\t                 Queensbery Hospital\n ";
       char text2[]=    "\n \t\t\t\t **************************************************** \n";
       char text3[]=    "\n \t\t\t\t                         MENU                  \n";
       char text4[]=    "\n \t\t\t\t****************************************************\n";
       char text5[]=    "\n \t\t\t\t1.Enter a Patient    \n";
       char text6[]=    "\n \t\t\t\t2.Display  the list of Patients \n";
       char text7[]=    "\n \t\t\t\t3.Insert Patient at the beginning  \n";
       char text8[]=    "\n \t\t\t\t4.Insert Patient at the end \n";
       char text9[]=    "\n \t\t\t\t5.Insert Patient at selected position\n";
       char text10[]=    "\n \t\t\t\t6.Discharge a Patient\n";
       char text11[]=    "\n \t\t\t\t7.Search for a Patient\n";
       char text12[]=    "\n \t\t\t\t8.Update a Patient\n";
       char text13[]=    "\n \t\t\t\t9.Exit\n";
       char text14[]=    "\n\n \t\t\t\tEnter any key to continue!!!!";


       for(x=0; text1[x]!=NULL; x++)
            {

             printf("%c",text1[x]);
           for(y=0; y<=8888888; y++)
            {
            }
           }


       for(x=0; text2[x]!=NULL; x++)
          {
            printf("%c",text2[x]);
            for(y=0; y<=8888888; y++)
           {
           }
          }

       for(x=0; text3[x]!=NULL; x++)
         {

            printf("%c",text3[x]);
           for(y=0; y<=8888888; y++)
          {
          }
         }

      for(x=0; text4[x]!=NULL; x++)
       {
          printf("%c",text4[x]);
         for(y=0; y<=8888888; y++)
         {
         }
       }

      for(x=0; text5[x]!=NULL; x++)
       {
          printf("%c",text5[x]);
          for(y=0; y<=8888888; y++)
         {
         }
       }

      for(x=0; text6[x]!=NULL; x++)
       {
          printf("%c",text6[x]);
         for(y=0; y<=8888888; y++)
         {
         }
       }

      for(x=0; text7[x]!=NULL; x++)
       {
         printf("%c",text7[x]);
         for(y=0; y<=8888888; y++)
         {
         }
       }

      for(x=0; text8[x]!=NULL; x++)
       {
         printf("%c",text8[x]);
        for(y=0; y<=8888888; y++)
         {
         }
       }

     for(x=0; text9[x]!=NULL; x++)
       {
         printf("%c",text9[x]);
         for(y=0; y<=8888888; y++)
         {
         }
       }

     for(x=0; text10[x]!=NULL; x++)
       {
         printf("%c",text10[x]);
         for(y=0; y<=8888888; y++)
         {
         }
       }
     for(x=0; text11[x]!=NULL; x++)
       {
         printf("%c",text11[x]);
         for(y=0; y<=8888888; y++)
         {
         }
       }

     for(x=0; text12[x]!=NULL; x++)
       {
         printf("%c",text12[x]);
         for(y=0; y<=8888888; y++)
          {
          }
        }
     for(x=0; text13[x]!=NULL; x++)
       {
         printf("%c",text13[x]);
         for(y=0; y<=8888888; y++)
          {
          }
        }
      for(x=0; text14[x]!=NULL; x++)
       {
         printf("%c",text14[x]);
         for(y=0; y<=8888888; y++)
          {
          }
        }
      getch();

                 printf("\n\n");
                printf("\t\t\t\tEnter your choice:\t");
                scanf("%d",&choice);
                printf("\n");


                switch(choice)
                {
                case 1:
                    system("cls");
                    system("COLOR 5A");
                    printf("\n\n\n");
                    printf("\t\t\t\tEnter Patient ID        :\t");
                    scanf("%d",&Patient_Id);
                    printf("\t\t\t\tEnter First Name        :\t");
                    scanf("%s",&P_Firstname);
                    printf("\t\t\t\tEnter Last Name         :\t");
                    scanf("%s",&P_Lastname);
                    printf("\t\t\t\tEnter NIC               :\t");
                    scanf("%s",&NIC);
                    printf("\t\t\t\tEnter Gender            :\t");
                    scanf("%s",&Gender);
                    printf("\t\t\t\tEnter Phone Number      :\t");
                    scanf("%s",&P_phonenum);
                    printf("\t\t\t\tEnter Disease           :\t");
                    scanf("%s",&disease);
                 create(Patient_Id,P_phonenum,P_Firstname,P_Lastname,NIC,Gender,disease);
                 getch();
                     system("cls");
                 break;
                case 2:
                    system("cls");
                    system("COLOR 0A");
                    printf("\n\n\n");
                    printf("\t\t\tPatient list");
                    printf("\n\n\n");
                     display();
                     getch();
                     system("cls");

                    break;
                case 3:
                    system("cls");
                    system("COLOR 0C");
                    printf("\n\n\n");
                     printf("\t\t\t\tEnter Patient ID       :\t");
                    scanf("%d",&Patient_Id);
                    printf("\t\t\t\tEnter First Name        :\t");
                    scanf("%s",&P_Firstname);
                    printf("\t\t\t\tEnter Last Name         :\t");
                    scanf("%s",&P_Lastname);
                    printf("\t\t\t\tEnter NIC               :\t");
                    scanf("%s",&NIC);
                    printf("\t\t\t\tEnter Gender            :\t");
                    scanf("%s",&Gender);
                    printf("\t\t\t\tEnter Phone Number      :\t");
                    scanf("%s",&P_phonenum);
                    printf("\t\t\t\tEnter Disease           :\t");
                    scanf("%s",&disease);
                 insert_begin(Patient_Id,P_phonenum,P_Firstname,P_Lastname,NIC,Gender,disease);
                 getch();
                 system("cls");
                 break;

                case 4:
                    system("cls");
                    system("COLOR 0D");
                     printf("\n\n\n");
                     printf("\t\t\t\tEnter Patient ID       :\t");
                    scanf("%d",&Patient_Id);
                    printf("\t\t\t\tEnter First Name        :\t");
                    scanf("%s",&P_Firstname);
                    printf("\t\t\t\tEnter Last Name         :\t");
                    scanf("%s",&P_Lastname);
                    printf("\t\t\t\tEnter NIC               :\t");
                    scanf("%s",&NIC);
                    printf("\t\t\t\tEnter Gender            :\t");
                    scanf("%s",&Gender);
                    printf("\t\t\t\tEnter Phone Number      :\t");
                    scanf("%s",&P_phonenum);
                    printf("\t\t\t\tEnter Disease           :\t");
                    scanf("%s",&disease);
                 insert_end(Patient_Id,P_phonenum,P_Firstname,P_Lastname,NIC,Gender,disease);
                 getch();
                 system("cls");
                 break;
                case 5:
                    system("cls");
                    system("COLOR 0E");
                     printf("\n\n\n");
                    printf("\t\t\t\tEnter Patient ID        :\t");
                    scanf("%d",&Patient_Id);
                    printf("\t\t\t\tEnter First Name        :\t");
                    scanf("%s",&P_Firstname);
                    printf("\t\t\t\tEnter Last Name         :\t");
                    scanf("%s",&P_Lastname);
                    printf("\t\t\t\tEnter NIC               :\t");
                    scanf("%s",&NIC);
                    printf("\t\t\t\tEnter Gender            :\t");
                    scanf("%s",&Gender);
                    printf("\t\t\t\tEnter Phone Number      :\t");
                    scanf("%s",&P_phonenum);
                    printf("\t\t\t\tEnter Disease           :\t");
                    scanf("%s",&disease);
                 insert_position(Patient_Id,P_phonenum,P_Firstname,P_Lastname,NIC,Gender,disease);
                 getch();
                 system("cls");
                 break;
                case 6:
                     system("cls");
                     system("COLOR 9C");
                    printf("\n\n\n");
                    printf("\t\t\t\tEnter patient ID to discharge:\t");
                    scanf("%d",&Patient_Id);
                   discharge(Patient_Id);
                   getch();
                    system("cls");
                   break;
                case 7:
                    system("cls");
                    system("COLOR 0D");
                    printf("\n\n\n");
                    printf("\t\t\t\tEnter patient ID to search:\t");
                    scanf("%d",&Patient_Id);
                   search(Patient_Id);
                   getch();
                     system("cls");
                   break;
                case 8:
                    system("cls");
                    system("COLOR 1C");
                     printf("\n\n\n");
                    printf("\t\t\t\tEnter patient ID to Update:\t");
                    scanf("%d",&Patient_Id);
                   update(Patient_Id);
                   getch();
                   system("cls");
                   break;
                case 9:
                    system("cls");
                    system("COLOR 0D");
                     printf("\n\n\n");
                    exit(0);
                    getch();
                   system("cls");
                    break;
            default:


                    printf("\n\t\t\t\t Invalid choice:\n");
                    getch();

                    break;
                }

}
    while(choice!=0);


}





