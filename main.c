        #include <stdio.h>
        #include <stdlib.h>
        #include <string.h>

        struct contact
        {
            long long int  mobile_no;
            char  name[30],email[30],adress[30];
        }c;

        void Remove();
        void display();
        void addContact();
        void search();
        void Delete();
        int gmail(char a[]);
        void edit();
        int check(char a[]);
        int count_length();
        int same(char n[]);
        int length();
        void back();
        int m_check(long long );

                //==========================================================================G-mail record=========================
        int mail(char ch[])
        {
            int i=0,l=0;
            char df[10]="@gmail.com";
            char mail[10]="@yahoo.com";

            while(ch[i]!='\0')
            {
                if(ch[i]==df[l] || ch[i]==mail[l] )
                {
                    l++;
                }
                else
                {
                    l=0;
                }
                i++;
            }
            return l;
        }
        //==========================================================================m_b_count record=========================
        int mobile_count(long long int d)
        {
            if(d>999,999,999 && d<10,000,000,000)
            {
                return 1;
            }
            return 0;
        }
//======================================
        int same(char n[])
        {
            FILE *s;
            struct contact d;

            s=fopen("contact","r");

            while(fread(&d,sizeof(d),1,s))
            {
                if((strcm,p(n,d.name))==0)
                {
                    fclose(s);
                    return 1;
                    break;
                }
            }
            fclose(s);

            return 0;
        }
        //================================
int m_check(long long p)
{
    FILE *fp;
    struct contact d;
    fp=fopen("contact","r");

    while(fread(&d,sizeof(d),1,fp))
    {
        if(p==d.mobile_no)
        {
            fclose(fp);
            printf("\n this number is already there......\n");
            return 1;
        }
    }
    fclose(fp);
    return 0;
}
                //==========================================================================add record=========================
        void addContact()
        {
            FILE *fp;
            long long int m;
            char n[20];

                fp=fopen("contact","a");
                if(fp==NULL)
                {
                    printf("file can't open \n");
                }
                            do{
                                        do{
                                        printf("\n ENTER PHONE NUMBER : ");
                                        fflush(stdin);
                                        scanf("%lld",&c.mobile_no);
                                        }while(mobile_count(c.mobile_no)==0);
                                        m=c.mobile_no;
                            }while(m_check(m)==1);

                                do{
                                        printf(" ENTER NAME : ");
                                        fflush(stdin);
                                        scanf("%[^\n]s",c.name);
                                       }while(same(c.name)==1);


                                do{
                                        printf(" ENTER EMAIL_ID : ");
                                        fflush(stdin);
                                        scanf("%[^\n]s",c.email);
                                }while(mail(c.email)!=10);

                                        printf(" ENTER ADRESS: ");
                                        fflush(stdin);
                                        scanf("%[^\n]s",c.adress);

                fwrite(&c,sizeof(c),1,fp);
                fclose(fp);
        }

        //==========================================================================count length =========================
        int length()
        {
             FILE *fp;
             int l=0;
                fp=fopen("contact","r");
                        while(fread(&c,sizeof(c),1,fp))
                        {
                                        l++;
                        }
                fclose(fp);
             return l;
        }
        //==========================================================================display record=========================
        void dispaly()
        {
            FILE *fp,*fp1;
            int i=0,j,n;
            char r='0';
            struct contact s[n=length()],t;
            fp=fopen("contact","r");
            printf("\n---------------------------------------------------------------------------------------------TOTAL CONTACT =[%d]",n);
                            while(fread(&c,sizeof(c),1,fp))
                            {
                                            s[i]=c;
                                            i++;
                            }
                fclose(fp);
                            for(i=0;i<n;i++)
                            {
                                    for(j=i+1;j<n;j++)
                                     {
                                                if(strcmp(s[i].name,s[j].name)>0)
                                                {
                                                    t=s[i];
                                                    s[i]=s[j];
                                                    s[j]=t;
                                                }
                                        }
                            }
                    fp=fopen("contact","w");

                                for(i=0;i<n;i++)
                                {
                                    fwrite(&s[i],sizeof(s[i]),1,fp);

                                                if(r!=s[i].name[0])
                                                {
                                                            printf("\n -------------------------------------------------------------[%c]--\n",s[i].name[0]);
                                                }
                                                else
                                                {
                                                    printf("\n -----------------------------------------\n");
                                                }
                                            printf("\n PHONE NO. = %lld ",s[i].mobile_no);
                                            printf("\n NAME      = %s ",s[i].name);
                                            printf("\n EMAIL     =  %s ",s[i].email);
                                            printf(" \n ADRESS    =  %s ",s[i].adress);
                                            r=s[i].name[0];
                                }
                fclose(fp);
        }
                //==========================================================================check  =========================
        int check(char a[])
        {
            FILE *fp;
            char n[20];

            fp=fopen("contact","r");

                        while(fread(&c,sizeof(c),1,fp))
                        {
                            strcpy(n,c.name);
                                if(strcmp(a,n)==0)
                                {
                                    fclose(fp);
                                    return 1;
                                }
                        }
                fclose(fp);
            return 0;
        }

        //==========================================================================search record=========================
        void search()
        {
            FILE *fp;
            int i;
            char  s_name[30],n[30];
                printf("enter name which you want to search ");
                fflush(stdin);
                gets(s_name);

            if(check(s_name)==1)
            {
                            fp=fopen("contact","r");
                                    if(fp==NULL)
                                    {
                                                printf("file can't open \n");
                                    }
                                while(fread(&c,sizeof(c),1,fp))
                                {
                                                    strcpy(n,c.name);
                                                            if(strcmp(s_name,n)==0)
                                                            {
                                                                        printf("\n PHONE: %lld \n NAME: %s \n EMAIL: %s \n ADRESS:%s",c.mobile_no,c.name,c.email,c.adress);
                                                                        break;
                                                            }
                                }
                        fclose(fp);
                }
            else
            {
                printf("\n you did not add this contact!!!!! \n");
                printf("\n do you want to add this contact? [ YES(1)  NO(0) ]\n");
                scanf("%d",&i);
                if(i==1)
                    addContact();
                else
                    printf("\n you do not want to add this number !!!!! \n");
            }
        }
        //==========================================================================delete record=========================
        void Delete()
        {
            FILE *fp,*fp1,*p;
            char name[30];
            int i;

            printf("\n ENTER NAME WHICH YOU WANT TO DELETE \n");
            fflush(stdin);
            scanf("%[^\n]s",name);

            i=check(name);
                if(i==1)
                {
                                printf("\n are you sure you want to delete this contact ?  \t [ YES(1)  NO(0)] ");
                                scanf("%d",&i);
                                if(i==0)
                                {
                                        printf("you don't want to delete \n");
                                }
                                else
                                {

                                    fp=fopen("contact","r");
                                    fp1=fopen("second","w");
                                    p=fopen("store","a");

                                        while(fread(&c,sizeof(c),1,fp))
                                        {
                                            if(strcmp(c.name,name)!=0)
                                                        fwrite(&c,sizeof(c),1,fp1);
                                            else
                                                fwrite(&c,sizeof(c),1,p);
                                        }
                                fclose(p);
                                fclose(fp);
                                fclose(fp1);

                                fp=fopen("contact","w");
                                fp1=fopen("second","r");

                                        while(fread(&c,sizeof(c),1,fp1))
                                        {
                                                    fwrite(&c,sizeof(c),1,fp);
                                        }
                                    printf("\n CONTACT SUCESSFULLY DELETED FROM YOUR DEVICE    \n");

                                fclose(fp);
                                fclose(fp1);
                                }
                }//main else
                else
                {
                    printf("\n can not find \n");
                }
        }
        //==========================================================================edit record=========================
        void edit()
        {
            FILE *fp,*fp1;
            int a, i=1;
            long long int m;
            char s[30];

            printf("\n enter \"name \" which you want to update \n");
            fflush(stdin);
            gets(s);

            if(check(s))
            {
                        fp=fopen("contact","r");
                        fp1=fopen("second","w");

                while(fread(&c,sizeof(c),1,fp))
                {
                            if(strcmp(c.name,s)!=0)
                            {
                                    fwrite(&c,sizeof(c),1,fp1);
                            }
                            else
                            {
                                    printf("\n +++++++++++++++++++++++++++++++\n");
                                    printf("\n 1.NAME \n 2.PHONE NUMBER \n 3.EMAIL \n 4.ADRESS \n 5.ALL\n");
                                    printf("\n +++++++++++++++++++++++++++++++\n");
                                        while(i==1)
                                        {
                                                printf("enter your choice ");
                                                fflush(stdin);
                                                scanf("%d",&a);

                                                            switch(a)
                                                            {
                                                                case  1:
                                                                                do{
                                                                                    printf(" ENTER NAME : ");
                                                                                    fflush(stdin);
                                                                                    scanf("%[^\n]s",c.name);
                                                                                }while((same(c.name))==1);
                                                                                break;
                                                                case 2:
                                                                    do{
                                                                    do{
                                                                            printf("enter phone number");
                                                                            fflush(stdin);
                                                                            scanf("%LLd",&c.mobile_no);
                                                                            }while(mobile_count(c.mobile_no)==0);
                                                                            m=c.mobile_no;
                                                                }while(m_check(m)==1);

                                                                            break;
                                                                case 3:
                                                                            do{
                                                                                            printf("enter  email");
                                                                                            fflush(stdin);
                                                                                            scanf("%[^\n]s",c.email);
                                                                                    }while(mail(c.email)!=10);
                                                                                    break;
                                                                case 4:
                                                                            printf("enter adress");
                                                                            fflush(stdin);
                                                                            scanf("%[^\n]s",c.adress);
                                                                            break;
                                                                    case 5:
                                                                        do{
                                                                                do{
                                                                                            printf("enter phone number");
                                                                                            fflush(stdin);
                                                                                            scanf("%lld",&c.mobile_no);
                                                                                    }while(mobile_count(c.mobile_no)==0);
                                                                                    m=c.mobile_no;
                                                                            }while(m_check(m)==1);


                                                                                    do{
                                                                                    printf("enter name");
                                                                                    fflush(stdin);
                                                                                    scanf("%[^\n]s",c.name);
                                                                                    }while((check(c.name))==1);

                                                                            do{
                                                                                        printf("enter  email");
                                                                                        fflush(stdin);
                                                                                        scanf("%[^\n]s",c.email);
                                                                                    }while(mail(c.email)!=10);

                                                                                    printf("enter adress");
                                                                                    fflush(stdin);
                                                                                    scanf("%[^\n]s",c.adress);
                                                                                    i=0;
                                                                                    break;
                                                                    default:
                                                                        printf("\n please enter valid choice !!!!!!!!\n");
                                                                        i=1;
                                                                }
                                                                            if(a==1 || a==2 || a==3 || a==4)
                                                                            {
                                                                                        printf("\n DO YOU WANT TO CHANGE ANY OTHER DETAIL? [YSE=1] [NO=0] \n  ");
                                                                                        scanf("%d",&i);
                                                                            }
                                      }

                                                fwrite(&c,sizeof(c),1,fp1);
                  }
            }
                            fclose(fp);
                            fclose(fp1);

                fp=fopen("contact","w");
                fp1=fopen("second","r");

                while(fread(&c,sizeof(c),1,fp1))
                {
                            fwrite(&c,sizeof(c),1,fp);
                }
                fclose(fp1);
                fclose(fp);

                printf("\n number is edited");
            }
            else
            {
                    printf("\n this name can not found \n");
            }
        }
        //==========================================================================back function=========================
        void back()
        {
            FILE *fp,*fp1,*fp2;
            int a=0;
            char s_name[20];

                printf("\n enter name which you want restore ");
                fflush(stdin);
                gets(s_name);

                fp=fopen("store","r");
                fp2=fopen("second","w");

                while(fread(&c,sizeof(c),1,fp))
                {
                            fwrite(&c,sizeof(c),1,fp2);
                }
                fclose(fp2);
                fclose(fp);

                fp=fopen("store","w");
                fp2=fopen("second","r");

                while(fread(&c,sizeof(c),1,fp2))
                {
                    if(strcmp(s_name,c.name)==0)
                    {
                        fp1=fopen("contact","a");
                        fwrite(&c,sizeof(c),1,fp1);
                        printf("\n this contact is added \n");
                        a=1;
                        fclose(fp1);
                        //break;
                    }
                    else
                    {
                            fwrite(&c,sizeof(c),1,fp);
                    }
                }
                if(a==0)
                {
                    printf("\n this contact is not there \n");
                }
                fclose(fp);
        }
        //==========================================================================main function=========================
        int main()
        {
                int a,b;

                        printf("\n\n \t \t \t \t CONTACT MANAGMENT SYSTEM \n");

        do{
                                printf("\n \t\t==========================================================\n");
                                printf("\t\t\t\t MENU \t");
                                printf("\n \t\t==========================================================\n");

                                printf("\t\t\t1.add contact information \n");
                                printf(" \t\t\t2.display contact information \n ");
                                printf(" \t\t\t3.search contact \n ");
                                printf("\t\t\t4.edit contact information  \n");
                                printf("\t\t\t5.delete contact information \n");
                                printf("\t\t\t6.restore  contact from phone\n");
                                printf("\n \t\t==========================================================\n");

                                printf("\n enter option number");
                                scanf("%d",&b);

                    switch(b)
                    {
                    case 1:
                            printf("\n \t \t::***************************ADD CONTECT *****************************::\n");
                            addContact();
                            break;
                    case 2 :
                             printf("\n \t \t***************************** ALL CONTECT  *****************************::\n");
                            dispaly();
                            break;

                    case 3:
                            printf("\n \t \t::***************************SEARCH CONTECT *****************************::\n");
                            search();
                            break;
                  case 4:
                            printf("\n \t \t::***************************EDIT CONTECT *****************************::\n");
                            edit();
                            break;
                    case 5:
                            printf("\n \t \t::***************************DELETE CONTECT *****************************::\n");
                            Delete();
                            break;
                    case 6:
                        printf("\n \t \t::***************************RESTORE CONTECT *****************************::\n");
                        back();
                        break;
                    default :
                                printf("\n invalid option \n");
                        }

                        printf("\n\t\t\t+++++++++++++++++++++++++++++++\n");
                        printf("\t\t\t WHAT YOU WANT ?\n \t\t\t\t [1]=MENU \n \t\t\t\t [0]=EXIT ");
                        printf("\n\t\t\t+++++++++++++++++++++++++++++++\n");
                        scanf("%d",&a);
                        while(a>1)
                        {
                            printf("\n please enter valid choice");
                            scanf("%d",&a);
                        }
        }while(a==1);


        return 0;
        }
