#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void display_first_screen();
void display_second_screen(char *);

struct ad
{
    char name[30];
    char disease[30];
    int cabin, phone, age;
} x[100];

int n, i, j = 0, a = 0, sum = 0, g, flag, num;

void read();
void add();
void view();
void search();
void edit();
void del();
void show();
void write();
void addRecord_Vaccine();
void Edit_rec();
void Exit();
void Certificate();
void Mainmenu();

struct patient
{
    int age;
    int nooftimesvaccinated;
    char Gender;
    char First_Name[20];
    char Last_Name[20];
    char Contact_no[15];
    char Address[30];
    char Email[30];
    char Vaccine_Name[20];
    char Doctor[20];
    char Problem[20];
    char Aaadhar[12];
};

struct patient p;

void gotoxy(short x, short y)
{
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

// Welcome screen
void display_first_screen()
{
    char *your_name = (char *)calloc(100, sizeof(char));
    system("cls");
    time_t t;

    char password_entered[20];
    char password_real[20] = "RGIPTEC2021";
    time(&t);
    printf("************************************************************************************\n");
    printf("**                                                                                **\n");
    printf("**                       ...... RGIPT HOSPITAL ......                             **\n");
    printf("**                                                                                **\n");
    printf("************************************************************************************\n");
    printf("                            %s\n", ctime(&t));
    printf("\n");
    printf("PLEASE ENTER USERID(NAME) = ");
    gets(your_name);
    printf("ENTER YOUR PASSWORD = ");
    scanf("%s", &password_entered);

    if (!(strcmp(password_real, password_entered)))
    {
        printf("  ACESS GRANTED  ");
        system("cls");
        display_second_screen(your_name);
    }
    else
    {
        printf("Incorrect Password");
    }
}

void display_second_screen(char *name)
{
    printf("*********************************************************************************\n");
    printf("**                                WELCOME                                      **\n");
    printf("**                              %s                                         **\n", name);
    printf("*********************************************************************************\n");
    printf("\n");
    printf("***********************************MENU******************************************\n");
    Mainmenu();
}

// main menu
void vaccination(void)
{
    printf("YOU CHOOSE FOR VACCINATION\n\t");
    int choose;
    printf(" Now Choose from 1,2,3\n");
    printf("\t 1.Add Record\n");
    printf("\t 2.Edit patient Status\n");
    printf("\t 3.Generate hospital Certificate\n");
    scanf("%i", &choose);
    switch (choose)
    {
    case 1:
        addRecord_Vaccine();
        break;
    case 2:
        Edit_rec();
        break;
    case 3:
        Certificate();
        break;
    default:
        printf("You Have choosen Wrong Option\n");
    }
}
void covid_patient_treat(void)
{
    printf("YOU CHOOSE FOR TREATMENT\t\n");
    int choose;
    printf(" Now Choose From 1,2,3\n");
    printf("\t 1.Add Record\n");
    printf("\t 2.Edit Record\n");
    printf("\t 3.Search Record\n");
    printf("\t 4.Delete Record\n");
    printf("\t 5.View Record\n");
    scanf("%i", &choose);
    switch (choose)
    {
    case 1:
        add();
        break;
    case 2:
        edit();
        break;
    case 3:
        search();
        break;
    case 4:
        del();
        break;
    case 5:
        view();
        break;
    default:
        printf("You Have choosen Wrong Option\n");
    }
}
void Mainmenu()
{
    int select;
    int choose;
    printf(" 1.Vaccination\n");
    printf(" 2.Covid Patient Treatment\n");
    printf(" 3.Exit\n");
    printf(" Please select 1 or 2 or 3\n");
    scanf("%i", &select);
    switch (select)
    {
    case 1:
        vaccination();
        break;
    case 2:
        noncovid();
        break;
    case 3:
        Exit();
        break;
    default:
        printf("\t\t\tError. Please select right option :-");
        getch();
        Mainmenu();
    }
}

// noncovid patient
int noncovid()
{
    read();
    int c, i, q;
    int m, n;
    for (m = 1; m <= 4; m++)
    {
        for (n = 1; n <= 5; n++)
            printf(" ");
        for (n = 1; n <= m - 1; n++)
        {
            printf(" ");
        }
        for (n = 1; n <= 4 - m + 1; n++)
        {
            if (n == 4 - m + 1 || m == 1 || m == 4)
                printf("*");
            else
                printf(" ");
        }
        for (n = 1; n <= 4 - m + 1; n++)
        {
            if (n == 1 || m == 1 || m == 4)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
    while (c != 6)
    {

        printf("**Enter your choice**\n\n1. Add Information\n2. View Information\n3. Search\n4. Edit Information\n5. Delete Information\n6. Exit\n\nOption=");
        scanf("%d", &c);
        fflush(stdin);
        if (c == 1)
        {
            system("cls");
            add();
        }
        else if (c == 2)
        {
            system("cls");
            view();
        }
        else if (c == 3)
        {
            system("cls");
            search();
        }
        else if (c == 4) // edit
        {
            system("cls");
            edit();
        }
        else if (c == 5) // delete
        {
            system("cls");
            del();
        }
        else if (c == 6)
        {
            write();
            Mainmenu();
            return 0;
        }
        else
        {
            system("cls");
            printf("\n\nInvalid input , try again by using valid inputs");
        }
        printf("\n\n");
    }
}

void add()
{
    printf("\n\n");
    printf("Already data inputed on the database =%d\n\n", num); // how many inputs
    printf("How many entry do you want to add=\n");
    scanf("%d", &n);
    sum = n + num;

    for (i = num, j = 0; i < sum; i++)
    {
        printf("\n");
        fflush(stdin);
        printf("Enter patient's Name = ");
        gets(x[i].name);
        fflush(stdin);
        printf("Enter disease = ");
        gets(x[i].disease);
        fflush(stdin);
        printf("Enter the age = ");
        scanf("%d", &x[i].age);
        fflush(stdin);
        printf("Enter cabin no = ");
        scanf("%d", &x[i].cabin);
        fflush(stdin);
        printf("Enter phone number = ");
        scanf("%d", &x[i].phone);
        fflush(stdin);
        printf("\n");
        j++;
        a++;
        num++;
    }
    // Mainmenu();
}

void view()
{
    for (i = 0; i < num; i++)
    {
        printf("\n");
        printf("Serial Number=%d\n", i);
        printf("Name = ");
        puts(x[i].name);
        printf("Disease = ");
        puts(x[i].disease);
        printf("Cabin no = %d\nPhone number = 0%d\nAge=%d", x[i].cabin, x[i].phone, x[i].age);
        printf("\n\n");
    }
    // Mainmenu();
}
void edit()
{
    int q, p;
    fflush(stdin);
    printf("What do you want to edit ?\n");
    printf("Enter your option\n");
    printf("1.Name\n2.Disease\n3.Age\n4.Cabin\n5.Phone no.\n");
    printf("Option=");
    scanf("%d", &q);
    if (q <= 5)
    {
        printf("Enter the serial no of that patient= (0 - %d)=", num - 1);
        scanf("%d", &p);
        if (p < num)
        {
            if (q == 1)
            {
                fflush(stdin);
                printf("Enter the new name=");
                gets(x[p].name);
            }
            else if (q == 2)
            {
                fflush(stdin);
                printf("Enter the new Disease=");
                gets(x[p].disease);
            }
            else if (q == 3)
            {
                fflush(stdin);
                printf("Enter the new Age=");
                scanf("%d", &x[p].age);
            }

            else if (q == 4)
            {
                fflush(stdin);
                printf("Enter the new Cabin no=");
                scanf("%d", &x[p].cabin);
            }

            else if (q == 5)
            {
                fflush(stdin);
                printf("Enter the new Phone no =");
                scanf("%d", &x[p].phone);
            }
        }
        else
        {
            printf("\n\nInvalid Serial \nTry Again !!\n\n");
        }
    }
    else
    {
        printf("\n\nInvalid option\nTry Again!!\n\n");
    }
    // Mainmenu();
}
void search()
{
    int s, h, f;
    char u[100];
    printf("By what do you want to search ?\n");
    printf("1.Serial no.\n2.Name\n3.Disease\n4.Cabin no.\n5.Phone no.\n6.Age\n\nOption = ");
    scanf("%d", &h);
    if (h == 1)
    {
        printf("Enter Serial number of the patient=");
        scanf("%d", &s);
        if (s < num)
        {
            printf("\n");
            printf("Serial Number=%d\n", s);
            printf("Name = ");
            puts(x[s].name);
            printf("Disease = ");
            puts(x[s].disease);
            printf("Cabin no = %d\nPhone number = 0%d\nAge = %d", x[s].cabin, x[s].phone, x[s].age);
            printf("\n\n");
        }
        else
            printf("\n\nNot Found\n\n");
    }
    else if (h == 2)
    {
        int f = 1;
        fflush(stdin);
        printf("Enter your name=");
        gets(u);
        fflush(stdin);
        for (g = 0; g < num; g++)
        {
            if (strcmp(u, x[g].name) == 0)
            {
                printf("\n");
                printf("Serial Number=%d\n", g);
                printf("Name = ");
                puts(x[g].name);
                printf("Disease = ");
                puts(x[g].disease);
                printf("Cabin no = %d\nPhone number = 0%d\nAge = %d", x[g].cabin, x[g].phone, x[g].age);
                printf("\n\n");
                f = 0;
            }
        }
        if (f == 1)
            printf("\nNot Found\n");
    }
    else if (h == 3)
    {
        int f = 1;
        fflush(stdin);
        printf("Enter Disease = ");
        gets(u);
        fflush(stdin);
        for (g = 0; g < num; g++)
        {
            if (strcmp(u, x[g].disease) == 0)
            {
                printf("\n");
                printf("Serial Number=%d\n", g);
                printf("Name = ");
                puts(x[g].name);
                printf("Disease = ");
                puts(x[g].disease);
                printf("Cabin no = %d\nPhone number = 0%d\nAge = %d", x[g].cabin, x[g].phone, x[g].age);
                printf("\n\n");
                f = 0;
            }
        }
        if (f == 1)
            printf("\nNot Found\n");
    }
    else if (h == 4)
    {
        int f = 1;
        printf("Enter Cabin number = ");
        scanf("%d", &f);
        for (g = 0; g < num; g++)
        {
            if (f == x[g].cabin)
            {
                printf("\n");
                printf("Serial Number=%d\n", g);
                printf("Name = ");
                puts(x[g].name);
                printf("Disease = ");
                puts(x[g].disease);
                printf("Cabin no = %d\nPhone number = 0%d\nAge = %d", x[g].cabin, x[g].phone, x[g].age);
                printf("\n\n");
                f = 0;
            }
        }
        if (f == 1)
            printf("Not Found\n\n");
    }
    else if (h == 5)
    {
        int f = 1;
        printf("Enter Phone number = ");
        scanf("%d", &f);
        for (g = 0; g < num; g++)
        {
            if (f == x[g].phone)
            {
                printf("\n");
                printf("Serial Number=%d\n", g);
                printf("Name = ");
                puts(x[g].name);
                printf("Disease = ");
                puts(x[g].disease);
                printf("Cabin no = %d\nPhone number = 0%d\nAge = %d", x[g].cabin, x[g].phone, x[g].age);
                printf("\n\n");
                f = 0;
            }
        }
        if (f == 1)
            printf("Not Found");
    }
    else if (h == 6)
    {
        int f = 1;
        printf("Enter Age = ");
        scanf("%d", &f);
        for (g = 0; g < num; g++)
        {
            if (f == x[g].age)
            {
                printf("\n");
                printf("Serial Number=%d\n", g);
                printf("Name = ");
                puts(x[g].name);
                printf("Disease = ");
                puts(x[g].disease);
                printf("Cabin no = %d\nPhone number = 0%d\nAge = %d", x[g].cabin, x[g].phone, x[g].age);
                printf("\n\n");
                f = 0;
            }
        }
        if (f == 1)
            printf("Not Found\n\n");
    }
    else
        printf("\n\nInvalid input\n\n");

    Mainmenu();
}
void del()
{
    int f, h;
    printf("Enter the serial number of the patient that you want to delete=");
    scanf("%d", &f);
    if (f < num)
    {
        printf("What do you want ?\n");
        printf("1.Remove the whole record\n2.Remove Name\n3.Remove Disease\n4.Remove age\n5.Remove Cabin\n6.Remove phone number\nOption = ");
        scanf("%d", &h);
        if (h == 1)
        {
            while (f < num)
            {
                strcpy(x[f].name, x[f + 1].name);
                strcpy(x[f].disease, x[f + 1].disease);
                x[f].age = x[f + 1].age;
                x[f].cabin = x[f + 1].cabin;
                x[f].phone = x[f + 1].phone;
                f++;
            }
            num--;
        }
        else if (h == 2)
        {
            strcpy(x[f].name, "Cleared");
        }
        else if (h == 3)
        {
            strcpy(x[f].disease, "Cleared");
        }
        else if (h == 4)
        {
            x[f].age = 0;
        }
        else if (h == 5)
        {
            x[f].cabin = 0;
        }
        else if (h == 6)
        {
            x[f].phone = 0;
        }
    }
    else
        printf("\n\nInvalid Serial number\n");
    // Mainmenu();
}
void read()
{
    FILE *fp = fopen("patient.txt", "r");
    if (fp == NULL)
    {
        fp = fopen("patient.txt", "w");
        fclose(fp);
        printf("File does not exist, I JUST CREATED IT, exiting...\n\n\n");
    }

    num = fread(x, sizeof(struct ad), 100, fp);
    fclose(fp);
}
void write()
{
    FILE *fp = fopen("patient.txt", "w");
    if (fp == NULL)
    {
        printf("Error");
        exit(1);
    }
    fwrite(x, sizeof(struct ad), num, fp);

    fclose(fp);
}

// vaccination

void addRecord_Vaccine()
{
    system("cls");
    printf("You choose for Add record\n");
    printf("Record will be added soon\n");
    char ans;
    FILE *ek;
    int valid;
    ek = fopen("Record2.dat", "a");
    printf("\n\n\t\t\t           Add Patients Record         \n");

A:
    printf("\n\t\tEnter Name: in this format Name_Surname: ");
    scanf("%s", p.First_Name);
    p.First_Name[0] = toupper(p.First_Name[0]);
    for (int i = 0; i < strlen(p.First_Name); i++)
    {
        if (isalpha(p.First_Name[i]) || p.First_Name[i] == '_')
        {
            valid = 1;
        }
        else
        {
            valid = 0;
            break;
        }
    }
    if (valid == 0)
    {
        printf("Enter the first name again as the previous entered value is invalid:");
        goto A;
    }

B:
    printf("\n\t\tEnter Aadhar Number (12 charecters):");
    scanf("%s", p.Last_Name);
    p.Last_Name[0] = toupper(p.Last_Name[0]);
    if (strlen(p.Last_Name) != 12)
    {
        printf("Enter the Aadhar number again as it cannot be greater than 12 digits:");
        goto B;
    }

    do
    {
        printf("\n\t\tGender[F/M]: ");
        scanf(" %c", &p.Gender);
        if (toupper(p.Gender) == 'M' || toupper(p.Gender) == 'F')
        {
            valid = 1;
        }
        else
        {
            valid = 0;
        }
        if (valid == 0)
        {
            printf("\n\t\t Gender contain Invalid character :(  Enter either F or M :)");
        }
    } while (!valid);

    printf("\n\t\tEnter Age:");
    scanf("%i", &p.age);
    if (p.age < 18)
    {
        printf("The entered age <18 and is not valid for vaccination");
    }

    printf("\n\t\tEnter Address: ");
    scanf("%s", p.Address);
    p.Address[0] = toupper(p.Address[0]);

    printf("\n\t\tEnter your email: ");
    scanf("%s", p.Email);

D:
    printf("\n\t\tEnter your Contact no: ");
    scanf("%s", p.Contact_no);
    if (strlen(p.Contact_no) > 10 || strlen(p.Contact_no) != 10)
    {
        printf("\n\t Invalid. Contact no. must contain 10 numbers. Enter again :)");
        goto D;
    }
    else
    {
        for (int b = 0; b < strlen(p.Contact_no); b++)
        {
            if (!isalpha(p.Contact_no[b]))
            {
                valid = 1;
            }
            else
            {
                valid = 0;
                break;
            }
        }
        if (!valid)
        {
            printf("\n\t\t Contact no. is Invalid character try again");
            goto D;
        }
    }
    do
    {
    E:
        printf("\n\t\tEnter the name of the vaccine: ");
        scanf("%s", p.Vaccine_Name);
        p.Vaccine_Name[0] = toupper(p.Vaccine_Name[0]);
        if ((strcmp(p.Vaccine_Name, "COVISHIELD") == 0) || (strcmp(p.Vaccine_Name, "COVAXIN") == 0))
        {
            valid = 1;
        }
        else
        {
            valid = 0;
        }
        if (valid == 0)
        {
            printf("\n\t\t Vaccine Name doesnot match enter again ");
            goto E;
        }
    } while (!valid);

    printf("\n\t\tEnter no of vaccination doses:");
    scanf(" %i", &p.nooftimesvaccinated);
    if ((p.nooftimesvaccinated > 2) && (p.nooftimesvaccinated < 0))
    {
        printf("You cannot be vaccinated more than 2 times");
    }

    fprintf(ek, " %s %s %c %i %s %s %s %s %i \n", p.First_Name, p.Last_Name, p.Gender, p.age, p.Address, p.Contact_no, p.Email, p.Vaccine_Name, p.nooftimesvaccinated);
    printf("\n\n\t\t\t  Information Record Successful  \n ");
    fclose(ek);
    Mainmenu();
}

void Edit_rec(void)
{

    FILE *ek, *ft;
    int i, b, valid = 0;

    char name[20];

    system("cls");
    printf("You choose for Edit Record\n");
    printf("no record found\n");
    ft = fopen("temp2.dat", "w+");
    ek = fopen("Record2.dat", "r");
    if (ek == NULL)
    {
        printf("\n\t Can not open file!! ");
        getch();
    }
    printf("\n\n\t\t\t!!!!!!!!!!!!!! Edit Patients Record !!!!!!!!!!!!!\n");
    gotoxy(12, 13);
    printf("Enter the 12 digit Aadhar number : ");
    scanf(" %s", name);
    fflush(stdin);
    name[0] = toupper(name[0]);
    gotoxy(12, 15);

    if (ft == NULL)
    {
        printf("\n Can not open file");
        getch();
    }
    while (fscanf(ek, "%s %s %c %i %s %s %s %s %s\n", p.First_Name, p.Last_Name, &p.Gender, &p.age, p.Address, p.Contact_no, p.Email, p.Problem, p.Doctor) != EOF)
    {
        if (strcmp(p.Last_Name, name) == 0)
        {
            valid = 1;
            gotoxy(25, 17);
            printf("*** Existing Record ***");
            gotoxy(10, 19);
            printf("%s \t%s \t%c \t%i \t%s \t%s \t%s \t%s \t%s\n", p.First_Name, p.Last_Name, p.Gender, p.age, p.Address, p.Contact_no, p.Email, p.Problem, p.Doctor);
            gotoxy(12, 22);
            printf("Enter New Name in format of Name_Surname: ");
            scanf("%s", p.First_Name);
            gotoxy(12, 24);
            printf("Enter Aadhar Number: ");
            scanf("%s", p.Last_Name);
            gotoxy(12, 26);
            printf("Enter Gender: ");
            scanf(" %c", &p.Gender);
            p.Gender = toupper(p.Gender);
            gotoxy(12, 28);
            printf("Enter age: ");
            scanf(" %i", &p.age);
            gotoxy(12, 30);
            printf("Enter Address: ");
            scanf("%s", p.Address);
            p.Address[0] = toupper(p.Address[0]);
            gotoxy(12, 32);
            printf("Enter Contact no: ");
            scanf("%s", p.Contact_no);
            gotoxy(12, 34);
            printf("\n\t\t\tEnter New email: ");
            scanf("%s", p.Email);
            gotoxy(12, 36);
            printf("\n\t\t\tEnter Name of vaccine: ");
            scanf("%s", p.Problem);
            p.Problem[0] = toupper(p.Problem[0]);
            gotoxy(12, 38);
            printf("\n\t\t\tEnter no of times vaccinated: ");
            scanf("%s", p.Doctor);
            p.Doctor[0] = toupper(p.Doctor[0]);
            fprintf(ft, "%s %s %c %i %s %s %s %s %s\n", p.First_Name, p.Last_Name, p.Gender, p.age, p.Address, p.Contact_no, p.Email, p.Problem, p.Doctor);
            printf("\n\n\t\t\tPatient record updated successfully...");
        }
        else
        {
            fprintf(ft, "%s %s %c %i %s %s %s %s %s\n", p.First_Name, p.Last_Name, p.Gender, p.age, p.Address, p.Contact_no, p.Email, p.Problem, p.Doctor);
        }
    }
    if (!valid)
    {
        printf("\n\t\tNO RECORD FOUND...\n");
        Mainmenu();
    }
    fclose(ft);
    fclose(ek);
    remove("Record2.dat");
    rename("temp2.dat", "Record2.dat");
    getch();
    Mainmenu();
}
void Certificate()
{
    printf("\n\n\t\t\t!!!!!!!!!!!!!! Generating Certificate !!!!!!!!!!!!!\n");
    FILE *ek;
    int valid = 0;
    char namesearch[30];
    ek = fopen("Record2.dat", "r");
    if (ek == NULL)
    {
        printf("NO RECORDS FOUND\n");
    }
    else
    {
        printf("\t\t\tEnter Aaadhar Number: ");
        scanf("%s", namesearch);
        namesearch[0] = toupper(namesearch[0]);

        while (fscanf(ek, "%s %s %c %i %s %s %s %s %s \n", p.First_Name, p.Last_Name, &p.Gender, &p.age, p.Address, p.Contact_no, p.Email, p.Problem, p.Doctor) != EOF)
        {

            if (strcmp(p.Last_Name, namesearch) == 0)
            {
                valid = 1;
                system("cls");
                printf("\t\t\t*********************************************************************\n\n");
                printf("\t\t\t\t\t\t\tCERTIFICATE\n\n");
                printf("\t\t\t*********************************************************************\n\n");
                printf("\t\t\t\t\tName\t:");
                for (int i = 0; i < strlen(p.First_Name); i++)
                {
                    if (p.First_Name[i] == '_')
                    {
                        printf(" ");
                    }
                    else
                    {
                        printf("%c", p.First_Name[i]);
                    }
                }
                printf("\t\n\n");
                printf("\t\t\t\t\tAadhar Number:\t%s\n\n", p.Last_Name);
                printf("\t\t\t\t\tGender:\t\t%c\n\n", p.Gender);
                printf("\t\t\t\t\tAge:\t\t%d\n\n", p.age);
                printf("\t\t\t\t\tAddress:\t%s\n\n", p.Address);
                printf("\t\t\t\t\tContact_No:\t%s\n\n", p.Contact_no);
                printf("\t\t\t\t\tEmail:\t\t%s\n\n", p.Email);
                printf("\t\t\t\t\tVaccine_Name:\t%s\n\n", p.Problem);
                printf("\t\t\t\t\tNo_of_doses:\t%s\n\n", p.Doctor);
                printf("\t\t\t********************************************************************\n\n");
            }
        }
        if (valid = 0)
        {
            system("cls");
            printf("Record NOT Found");
        }
        fclose(ek);
    }
    Mainmenu();
}

// exit function
void Exit()
{
    printf("\n\n\n\n\n\t\t\tTHANK YOU FOR VISITING :)");
}
void main()
{
    display_first_screen();
}