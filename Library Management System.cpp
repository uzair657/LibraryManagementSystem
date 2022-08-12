#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;
/*****************************Constant Variables****************************/
const int name_size=30;const int isbn_size=30;const int publisher_size=30;const int author_size=30;const int un_size=40;const int id_size=30;const int p_size=16;const int total_books=105;const int total_users=32;const int total_issue_books=12;
const char MasterCode[]="abc";
/********************************Global Variables***********************************************/
int c=0, bindex[total_books],BN, uc=0, uindex[total_users],UN, ic=0, iindex[total_issue_books];
char passcheck[p_size];bool f=1;
/***********************************Functions Declarations****************************************/
void title()
{
    cout<<"\n#########################################################\n"
        <<"#                                                         #\n"
        <<"#              Library  Management  System                #\n"
        <<"#                     BY UZAIR                            #\n"
        <<"#########################################################\n";
}
void readfiles();void MENU();void GoBack();void AddNewBook();void BACKADDBOOK();void SearchBook();void SISBN();
void SAUTHOR();void SBOOKNAME();void SPUBLISHER();void SYEAR();void EditBook();void BACKEDITBOOK();void DeleteBook();
void BACKDELETEBOOK();void AddNewUser();void SearchUser();void SUID();void SUNAME();void SUDOB();void EditUser();
void BACKEDITUSER();void DeleteUser();void BACKDELETEUSER();void IssueBook();void DeleteIssueBook();void BACKDELETEISSUEBOOK();
void BACKISSUEBOOK();void DisplayAllIssuedBooks();void DisplayAllUsers();void DisplayAllBooks();
/*****************************Structures****************************/
struct book
{
    char ISBN[isbn_size], Name[name_size], Publisher[publisher_size], Author[author_size];
    int Copies;
    string Issue_Date;
};
struct user
{
    char ID[id_size],Uname[un_size], SorE[9];
    string DOB;
};
struct IBook
{
    string ISBN,IDate,RDate;
    char ID[id_size];
};
/*****************************Structures Variables****************************/
book obj[total_books],temp;
user uobj[total_users],utemp;
IBook iobj[total_issue_books],itemp;
/********************************Main Function*******************************/
int main()
{
    system("color 9b");
    readfiles();
    MENU();
    return 0;
}
void GoBack()
{
    char x;
    while(1)
    {
        cout<<"\nDo you want to go back to Main Menu [Y/N]\n";
        cout<<"\tN means Quit the Program: ";
        cin>>x;
        x=toupper(x);
        if (x=='Y' || x=='N')
            break;
        cout<<"\n\t*{Invalid Input Only press Y or N}*\n";
    }
    if (x=='Y')
        MENU();
    else if (x=='N')
        exit(0);
}
/*******************************Menu Function********************************/
void MENU()
{
    system ("cls");
    title();
    cout<<"\n                      Main Menu                       \n\n"
        <<"\t(1)  Add New Book\n"
        <<"\t(2)  Edit  Book\n"
        <<"\t(3)  Delete  Book\n"
        <<"\t(4)  Search Book\n"
        <<"\t(5)  Add Library  User\n"
        <<"\t(6)  Edit  Library  User\n"
        <<"\t(7)  Delete  Library  User\n"
        <<"\t(8)  Search Library  User\n"
        <<"\t(9)  Issue Book\n"
        <<"\t(10) Delete  Issued Book\n"
        <<"\t(11) Show All Book\n"
        <<"\t(12) Show All Library  User\n"
        <<"\t(13) Show All Issue Book\n"
        <<"\n-1 to quit\n";
    int choice;
    while(1)
    {
        cout<<"\nWhat do You want: ";
        cin>>choice;
        if ((choice==-1) || (choice>=1 && choice<=13))
            break;
        cout<<"\n\t*{Please Enter valid Choice}*\n";
    }
    switch(choice)
    {
    case -1:
        exit(0);
    case 1:
        AddNewBook();
        break;
    case 2:
        EditBook();
        break;
    case 3:
        DeleteBook();
        break;
    case 4:
        SearchBook();
        break;
    case 5:
        system("cls");
        title();
        cout<<"\n\tPlease Enter the Password to proceed :";
        cin.ignore();
        cin.getline(passcheck,p_size);
        if (!strcmp(passcheck,MasterCode))
        {
            AddNewUser();
        }
        else
            cout<<"\n\t*{Password is incorrect}*\n";
        GoBack();
        break;
    case 6:
        system("cls");
        title();
        cout<<"\n\tPlease Enter the Password to proceed :";
        cin.ignore();
        cin.getline(passcheck,p_size);
        if (!strcmp(passcheck,MasterCode))
        {
            EditUser();
        }
        else
            cout<<"\n\t*{Password is incorrect}*\n";
        GoBack();
        break;
    case 7:
        system("cls");
        title();
        cout<<"\n\tPlease Enter the Password to proceed :";
        cin.ignore();
        cin.getline(passcheck,p_size);
        if (!strcmp(passcheck,MasterCode))
        {
            DeleteUser();
        }
        else
            cout<<"\n\t*{Password is incorrect}*\n";
        GoBack();
        break;
    case 8:
        system("cls");
        title();
        cout<<"\n\tPlease Enter the Password to proceed :";
        cin.ignore();
        cin.getline(passcheck,p_size);
        if (!strcmp(passcheck,MasterCode))
        {
            SearchUser();
        }
        else
            cout<<"\n\t*{Password is incorrect}*\n";
        GoBack();
        break;
    case 9:
        system("cls");
        title();
        cout<<"\n\tPlease Enter the Password to proceed :";
        cin.ignore();
        cin.getline(passcheck,p_size);
        if (!strcmp(passcheck,MasterCode))
        {
            IssueBook();
        }
        else
            cout<<"\n\t*{Password is incorrect}*\n";
        GoBack();
        break;
    case 10:
        system("cls");
        title();
        cout<<"\n\tPlease Enter the Password to proceed :";
        cin.ignore();
        cin.getline(passcheck,p_size);
        if (!strcmp(passcheck,MasterCode))
        {
            DeleteIssueBook();
        }
        else
            cout<<"\n\t*{Password is incorrect}*\n";
        GoBack();
        break;
    case 11:
        DisplayAllBooks();
        break;
    case 12:
        system("cls");
        title();
        cout<<"\n\tPlease Enter the Password to proceed :";
        cin.ignore();
        cin.getline(passcheck,p_size);
        if (!strcmp(passcheck,MasterCode))
        {
            DisplayAllUsers();
        }
        else
            cout<<"\n\t*{Password is incorrect}*\n";
        GoBack();
        break;
    case 13:
        system("cls");
        title();
        cout<<"\n\tPlease Enter the Password to proceed :";
        cin.ignore();
        cin.getline(passcheck,p_size);
        if (!strcmp(passcheck,MasterCode))
        {
            DisplayAllIssuedBooks();
        }
        else
            cout<<"\n\t*{Password is incorrect}*\n";
        GoBack();
        break;
    }
}
/*******************************READ Files***********************************/
void readfiles()
{
    ofstream write;
    ifstream read;
    read.open("Books_List.txt");
    if (read)
    {
        while(read.getline(obj[c].Name,name_size,'~') && read.getline(obj[c].ISBN,isbn_size,'~') && read.getline(obj[c].Publisher,publisher_size,'~') && read.getline(obj[c].Author,author_size,'~') && read>>obj[c].Copies && read.ignore() && getline(read,obj[c].Issue_Date))
            c++;
    }
    read.close();
    read.open("Users_List.txt");
    if (read)
    {
        while(read.getline(uobj[uc].Uname,un_size,'~') && read.getline(uobj[uc].ID,id_size,'~') && read.getline(uobj[uc].SorE,9,'~') && read>>uobj[uc].DOB && read.ignore())
            uc++;
    }
    read.close();
    read.open("IssuedBooks_List.txt");
    if (read)
    {
        while(read.getline(iobj[ic].ID,id_size,'~') && getline(read,iobj[ic].ISBN,'~') && getline(read,iobj[ic].IDate,'~') && getline(read,iobj[ic].RDate,'~'))
            ic++;
    }
    read.close();
}
/*******************************Add Book Function****************************/
void AddNewBook()
{
    system("cls");
    title();
    if(c<total_books)
    {
        cout<<"\n                      Add New Book                   \n";
        bool flag=1;
        int i;
        cout<<"\nEnter ISBN number of book: ";
        cin.ignore();
        cin.getline(temp.ISBN,isbn_size);
        for(i=0; i<c; i++)
        {
            if(!strcmp(obj[i].ISBN,temp.ISBN))
            {
                system("cls");
                title();
                cout<<"\n\t*{This Book Already Exists In Database}*\n";
                flag=0;
                break;
            }
        }
        if(flag)
        {
            strcpy(obj[c].ISBN,temp.ISBN);
            cout<<"\n\n\t*{ISBN successfully inserted}*\n\n";
            cout<<"\nEnter Book Name: ";
            cin.getline(obj[c].Name,name_size);
            cout<<"\nEnter Publisher Name: ";
            cin.getline(obj[c].Publisher,publisher_size);
            cout<<"\nEnter Author Name: ";
            cin.getline(obj[c].Author,author_size);
            cout<<"\nEnter Number of Copies: ";
            cin>>obj[c].Copies;
            cout<<"\nEnter Issue Date [DD/MM/YYYY]: ";
            cin>>obj[c].Issue_Date;
            ofstream Write;
            Write.open("Books_List.txt",ios::app);
            Write<<obj[c].Name<<'~'<<obj[c].ISBN<<'~'<<obj[c].Publisher<<'~'<<obj[c].Author<<'~'<<obj[c].Copies<<' '<<obj[c].Issue_Date<<endl;
            c++;
            Write.close();
            system("cls");
            title();
            cout<<"\n\nThe book information  was not duplicate  and the new book information  is successfully added in  the system.\n";
        }
        BACKADDBOOK();
    }
    else
    {
        system("cls");
        title();
        cout<<"\n\n\t*{Note: you have reached limit!\n\t  Please delete or edit some book}*\n\n";
    }
    GoBack();
}
void BACKADDBOOK()
{
    char x;
    while(1)
    {
        cout<<"\nDo you want to Add Another Book [Y/N]: ";
        cin>>x;
        x=toupper(x);
        if (x=='Y' || x=='N')
            break;
        cout<<"\n\t*{Invalid Input Only press Y or N}*\n";
    }
    if(x=='Y')
        AddNewBook();
}
/***************************Search Book Functions****************************/
void SearchBook()
{
    if (c>0)
    {
        int x;
        system("cls");
        title();
        cout<<"\n                      Search Book                     \n\n"
            <<"\t(1) Search through  ISBN Number\n"
            <<"\t(2) Search through  Author Name\n"
            <<"\t(3) Search through  Book Name\n"
            <<"\t(4) Search through  Publisher Name\n"
            <<"\t(5) Search through  Issue Year\n"
            <<"\t(0) Go back to Main Menu\n";
        while(1)
        {
            cout<<"\nWhat do You want: ";
            cin>>x;
            if (x>=0 && x<=5)
                break;
            cout<<"\n\t*{Please Enter valid Choice}*\n";
        }
        switch (x)
        {
        case 1:
            SISBN();
            break;
        case 2:
            SAUTHOR();
            break;
        case 3:
            SBOOKNAME();
            break;
        case 4:
            SPUBLISHER();
            break;
        case 5:
            SYEAR();
            break;
        case 0:
            GoBack();
            break;
        }
    }
    else
    {
        system("cls");
        title();
        cout<<"\n\n\t*{Note: There are no books in Database\n\t  Please Add some Books First}*\n\n";
        GoBack();
    }
}
void SISBN()
{
    bool flag=1;
    int i;BN=0;
    system("cls");
    title();
    cout<<"\n                  Search Book by ISBN                    \n";
    cout<<"\nEnter ISBN number you want to search: ";
    cin.ignore();
    cin.getline(temp.ISBN,isbn_size);
    for(i=0; i<c; i++)
    {
        if(!strcmp(obj[i].ISBN,temp.ISBN))
        {
            bindex[BN]=i;
            cout.setf(ios::left);
            cout<<"\n\nBOOk no. "<<++BN<<setw(20)<<"\n\nBook Name: "<<obj[i].Name<<setw(20)<<"\nBook ISBN: "<<obj[i].ISBN<<setw(20)<<"\nPublisher Name: "<<obj[i].Publisher<<setw(20)<<"\nAuthor Name: "<<obj[i].Author<<setw(20)<<"\nCopies: "<<obj[i].Copies<<setw(20)<<"\nIssue Date: "<<obj[i].Issue_Date<<endl;
            flag=0;
            break;
        }
    }
    if (flag)
    {
        system("cls");
        title();
        cout<<"\n\t\t*{No Match Found}*\n";
    }
    if (f)
    {
        f=1;
        GoBack();
    }
}
void SAUTHOR()
{
    bool flag=1;
    int i;BN=0;
    system("cls");
    title();
    cout<<"\n                  Search Book by Author                    \n";
    cout<<"\nEnter Author name you want to search: ";
    cin.ignore();
    cin.getline(temp.Author,author_size);
    for(i=0; i<c; i++)
    {
        if(!strcmp(obj[i].Author,temp.Author))
        {
            bindex[BN]=i;
            cout.setf(ios::left);
            cout<<"\n\nBOOk no. "<<++BN<<setw(20)<<"\n\nBook Name:  "<<obj[i].Name<<setw(20)<<"\nBook ISBN: "<<obj[i].ISBN<<setw(20)<<"\nPublisher Name: "<<obj[i].Publisher<<setw(20)<<"\nAuthor Name: "<<obj[i].Author<<setw(20)<<"\nCopies: "<<obj[i].Copies<<setw(20)<<"\nIssue Date: "<<obj[i].Issue_Date<<endl;
            flag=0;
        }
    }
    if (flag)
    {
        system("cls");
        title();
        cout<<"\n\t\t*{No Match Found}*\n";
    }
    if (f)
    {
        f=1;
        GoBack();
    }
}
void SBOOKNAME()
{
    bool flag=1;
    int i;BN=0;
    system("cls");
    title();
    cout<<"\n                  Search Book by Name                    \n";
    cout<<"\nEnter Book name you want to search: ";
    cin.ignore();
    cin.getline(temp.Name,name_size);
    for(i=0; i<c; i++)
    {
        if(!strcmp(obj[i].Name,temp.Name))
        {
            bindex[BN]=i;
            cout.setf(ios::left);
            cout<<"\n\nBOOk no. "<<++BN<<setw(20)<<"\n\nBook Name:  "<<obj[i].Name<<setw(20)<<"\nBook ISBN: "<<obj[i].ISBN<<setw(20)<<"\nPublisher Name: "<<obj[i].Publisher<<setw(20)<<"\nAuthor Name: "<<obj[i].Author<<setw(20)<<"\nCopies: "<<obj[i].Copies<<setw(20)<<"\nIssue Date: "<<obj[i].Issue_Date<<endl;
            flag=0;
        }
    }
    if (flag)
    {
        system("cls");
        title();
        cout<<"\n\t\t*{No Match Found}*\n";
    }
    if (f)
    {
        f=1;
        GoBack();
    }
}
void SPUBLISHER()
{
    bool flag=1;
    int i;BN=0;
    system("cls");
    title();
    cout<<"\n                  Search Book by Publisher                    \n";
    cout<<"\nEnter Publisher name you want to search: ";
    cin.ignore();
    cin.getline(temp.Publisher,publisher_size);
    for(i=0; i<c; i++)
    {
        if(!strcmp(obj[i].Publisher,temp.Publisher))
        {
            bindex[BN]=i;
            cout.setf(ios::left);
            cout<<"\n\nBOOk no. "<<++BN<<setw(20)<<"\n\nBook Name:  "<<obj[i].Name<<setw(20)<<"\nBook ISBN: "<<obj[i].ISBN<<setw(20)<<"\nPublisher Name: "<<obj[i].Publisher<<setw(20)<<"\nAuthor Name: "<<obj[i].Author<<setw(20)<<"\nCopies: "<<obj[i].Copies<<setw(20)<<"\nIssue Date: "<<obj[i].Issue_Date<<endl;
            flag=0;
        }
    }
    if (flag)
    {
        system("cls");
        title();
        cout<<"\n\t\t*{No Match Found}*\n";
    }
    if (f)
    {
        f=1;
        GoBack();
    }
}
void SYEAR()
{
    string a,b;
    bool flag=1;
    int i;BN=0;
    system("cls");
    title();
    cout<<"\n                Search Book by Issue Year                    \n";
    cout<<"\nEnter Year you want to search: ";
    cin>>a;
    for(i=0; i<c; i++)
    {
        string b(obj[i].Issue_Date,6,4);
        if(a==b)
        {
            bindex[BN]=i;
            cout.setf(ios::left);
            cout<<"\n\nBOOk no. "<<++BN<<setw(20)<<"\n\nBook Name:  "<<obj[i].Name<<setw(20)<<"\nBook ISBN: "<<obj[i].ISBN<<setw(20)<<"\nPublisher Name: "<<obj[i].Publisher<<setw(20)<<"\nAuthor Name: "<<obj[i].Author<<setw(20)<<"\nCopies: "<<obj[i].Copies<<setw(20)<<"\nIssue Date: "<<obj[i].Issue_Date<<endl;
            flag=0;
        }
    }
    if (flag)
    {
        system("cls");
        title();
        cout<<"\n\t\t*{No Match Found}*\n";
    }
    if (f)
    {
        f=1;
        GoBack();
    }
}
/*****************************Edit Book Function*****************************/
void EditBook()
{
    f=0;
    bindex[0]=-1;
    SearchBook();
    if (bindex[0]!=-1)
    {
        cout<<"\n\n                  Edit Book                    \n";
        int ch,z,i;
        while(1)
        {
            cout<<"\n\nEnter Book no. you want to edit: ";
            cin>>ch;
            if (ch>=1 && ch<=BN)
                break;
            cout<<"\n\t*{Invalid Input!}*\n";
        }
        z=bindex[ch-1];
        bool flag=1;
        system("cls");
        title();
        cout<<"\nEnter New ISBN number of book: ";
        cin.ignore();
        cin.getline(temp.ISBN,isbn_size);
        for(i=0; i<c; i++)
        {
            if(!strcmp(obj[i].ISBN,temp.ISBN))
            {
                system("cls");
                title();
                cout<<"\n\t*{This Book Already Exists In Database\n\t  you have to Enter different ISBN Number}*\n";
                flag=0;
                break;
            }
        }
        if(flag)
        {
            //storing values in structure variables
            strcpy(obj[z].ISBN,temp.ISBN);
            cout<<"\n           ISBN successfully inserted           \n\n";
            cout<<"\nEnter New Book Name: ";
            cin.getline(obj[z].Name,name_size);
            cout<<"\nEnter New Publisher Name: ";
            cin.getline(obj[z].Publisher,publisher_size);
            cout<<"\nEnter New Author Name: ";
            cin.getline(obj[z].Author,author_size);
            cout<<"\nEnter New Number of Copies: ";
            cin>>obj[z].Copies;
            cout<<"\nEnter New Issue Date [DD/MM/YYYY]: ";
            cin>>obj[z].Issue_Date;

            ofstream Write;
            Write.open("Books_List.txt",ios::trunc);
            for (i=0; i<c; i++)
                    Write<<obj[i].Name<<'~'<<obj[i].ISBN<<'~'<<obj[i].Publisher<<'~'<<obj[i].Author<<'~'<<obj[i].Copies<<' '<<obj[i].Issue_Date<<endl;
            Write.close();
            system("cls");
            title();
            cout<<"\n*{The book information  was not duplicate  and the book information  is updated successfully}*\n";
            BACKEDITBOOK();
        }
    }
    GoBack();
}
void BACKEDITBOOK()
{
    char x;
    while(1)
    {
        cout<<"\nDo you want to Edit Another Book [Y/N]: ";
        cin>>x;
        x=toupper(x);
        if (x=='Y' || x=='N')
            break;
        cout<<"\n\t*{Invalid Input Only press Y or N}*\n";
    }
    if(x=='Y')
        EditBook();
}
/****************************Delete Book Function****************************/
void DeleteBook()
{
    f=0;
    bindex[0]=-1;
    SearchBook();
    if (bindex[0]!=-1)
    {
        cout<<"\n\n                   Delete Book                    \n";
        int ch,z,j;
        char s;
        while(1)
        {
            cout<<"\n\nEnter Book no. you want to delete: ";
            cin>>ch;
            if (ch>=1 && ch<=BN)
                break;
            cout<<"\n\t{*Invalid Input!}*";
        }
        while(1)
        {
            cout<<"\n\nAre you sure you want to delete the selected Book [Y/N] : ";
            cin>>s;
            s=toupper(s);
            if (s=='Y' || s=='N')
                break;
            cout<<"\n\t{*Invalid Input! only press Y or N}*";
        }
        if (s=='Y')
        {
            z=bindex[ch-1];
            system("cls");
            title();
            for( ; z<c-1; z++)
            {
                strcpy(obj[z].Name,obj[z+1].Name);
                strcpy(obj[z].ISBN,obj[z+1].ISBN);
                strcpy(obj[z].Publisher,obj[z+1].Publisher);
                strcpy(obj[z].Author,obj[z+1].Author);
                obj[z].Issue_Date=obj[z+1].Issue_Date;
                swap(obj[z].Copies,obj[z+1].Copies);
            }
            ofstream Write;
            Write.open("Books_List.txt",ios::trunc);
            c--;
            for (j=0; j<c; j++)
                Write<<obj[j].Name<<'~'<<obj[j].ISBN<<'~'<<obj[j].Publisher<<'~'<<obj[j].Author<<'~'<<obj[j].Copies<<' '<<obj[j].Issue_Date<<endl;
            Write.close();
            system("cls");
            title();
            cout<<"\n\t*{The book information is successfully Deleted}*\n";
            BACKDELETEBOOK();
        }
    }
    GoBack();
}
void BACKDELETEBOOK()
{
    char x;
    while(1)
    {
        cout<<"\nDo you want to Delete Another Book [Y/N]: ";
        cin>>x;
        x=toupper(x);
        if (x=='Y' || x=='N')
            break;
        cout<<"\n\t*{Invalid Input Only press Y or N}*\n";
    }
    if(x=='Y')
        DeleteBook();
}
/*****************************Add User Function****************************/
void AddNewUser()
{
    char ad='Y';
    while (ad=='Y')
    {
        if(uc<total_users)
        {
            system("cls");
            title();
            cout<<"\n                     Add New User                   \n";
            bool flag=1;
            int i;
            char se;
            cout<<"\nEnter ID number of User: ";
            cin.getline(utemp.ID,id_size);
            for(i=0; i<uc; i++)
            {
                if(!strcmp(uobj[i].ID,utemp.ID))
                {
                    cout<<"\n\t*{The User Already Exists In Database}*\n";
                    flag=0;
                    break;
                }
            }
            if(flag)
            {
                strcpy(uobj[uc].ID,utemp.ID);
                cout<<"\n\t*{ID successfully inserted}*\n\n";
                cout<<"\nEnter User Name: ";
                cin.getline(uobj[uc].Uname,un_size);
                while(1)
                {
                    cout<<"\nIs user a Student or Employee [S/E]: ";
                    cin.get(se);
                    se=toupper(se);
                    if (se=='S' || se=='E')
                        break;
                    cout<<"\n\t*{Invalid Input Only Enter S or E}*\n";
                }
                if (se=='S')
                    strcpy(uobj[uc].SorE,"Student");
                else
                    strcpy(uobj[uc].SorE,"Employer");
                cout<<"\nEnter Date of Birth [DD/MM/YYYY]: ";
                cin>>uobj[uc].DOB;
                ofstream Write;
                Write.open("Users_List.txt",ios::app);
                Write<<uobj[uc].Uname<<'~'<<uobj[uc].ID<<'~'<<uobj[uc].SorE<<'~'<<uobj[uc].DOB<<endl;
                uc++;
                Write.close();
                system("cls");
                title();
                cout<<"\nThe user information was not duplicate and the new user information is successfully added in the system.\n";
            }
            while(1)
            {
                cout<<"\nDo you want to Add Another User [Y/N]: ";
                cin>>ad;
                ad=toupper(ad);
                if (ad=='Y' || ad=='N')
                    break;
                cout<<"\n\t*{Invalid Input Only press Y or N}*\n";
            }
        }
        else
        {
            system("cls");
            title();
            cout<<"\n\n\t*{Note: you have reached limit! \n\t  Please delete or edit some User}*\n\n";
            break;
        }
    }
}
/*****************************Edit User Function****************************/
void EditUser()
{
    f=0;
    uindex[0]=-1;
    SearchUser();
    if (uindex[0]!=-1)
    {
        cout<<"\n\n                 Edit User                    \n";
        char se;
        int ch,z,i;
        while(1)
        {
            cout<<"\n\nEnter User no. you want to edit: ";
            cin>>ch;
            if (ch>=1 && ch<=UN)
                break;
            cout<<"\n\t*{Invalid Input!}*\n";
        }
        z=uindex[ch-1];
        bool flag=1;
        system("cls");
        title();
        cout<<"\nEnter New ID number of User: ";
        cin.ignore();
        cin.getline(utemp.ID,id_size);
        for(i=0; i<uc; i++)
        {
            if(!strcmp(uobj[i].ID,utemp.ID))
            {
                cout<<"\n\t*{This User Already Exists In Database}*\n";
                flag=0;
                break;
            }
        }
        if(flag)
        {
            strcpy(uobj[z].ID,utemp.ID);
            cout<<"\n\t*{ID successfully inserted}*\n\n";
            cout<<"\nEnter User Name: ";
            cin.getline(uobj[z].Uname,un_size);
            while(1)
            {
                cout<<"\nIs user a Student or Employee [S/E]: ";
                cin.get(se);
                se=toupper(se);
                if (se=='S' || se=='E')
                    break;
                cout<<"\n\t*{Invalid Input Only Enter S or E}*\n";
            }
            if (se=='S')
                strcpy(uobj[uc].SorE,"Student");
            else
                strcpy(uobj[uc].SorE,"Employer");
            cout<<"\nEnter Date of Birth [DD/MM/YYYY]: ";
            cin>>uobj[z].DOB;

            ofstream Write;
            Write.open("Users_List.txt",ios::trunc);
            for (i=0; i<uc; i++)
                Write<<uobj[i].Uname<<'~'<<uobj[i].ID<<'~'<<uobj[i].SorE<<'~'<<uobj[i].DOB<<endl;
            Write.close();
            system("cls");
            title();
            cout<<"\nThe user information  was not duplicate  and the user information  is updated successfully.\n";
            BACKEDITUSER();
        }
    }
    GoBack();
}
void BACKEDITUSER()
{
    char x;
    while(1)
    {
        cout<<"\nDo you want to Edit Another User [Y/N]: ";
        cin>>x;
        x=toupper(x);
        if (x=='Y' || x=='N')
            break;
        cout<<"\n\t*{Invalid Input Only press Y or N}*\n";
    }
    if(x=='Y')
        EditUser();
}
/*****************************Delete User Function****************************/
void DeleteUser()
{
    f=0;
    uindex[0]=-1;
    SearchUser();
    if (uindex[0]!=-1)
    {
        cout<<"\n\n                   Delete User                    \n";
        int ch,z,j;
        char s;
        while(1)
        {
            cout<<"\n\nEnter User no. you want to delete: ";
            cin>>ch;
            if (ch>=1 && ch<=UN)
                break;
            cout<<"\n\t*{Invalid Input!}*";
        }
        while(1)
        {
            cout<<"\n\nAre you sure you want to delete the selected User [Y/N] : ";
            cin>>s;
            s=toupper(s);
            if (s=='Y' || s=='N')
                break;
            cout<<"\n\t{*Invalid Input! only press Y or N}*";
        }
        if (s=='Y')
        {
            z=uindex[ch-1];
            system("cls");
            title();
            for( ; z<uc-1; z++)
            {
                strcpy(uobj[z].Uname,uobj[z+1].Uname);
                strcpy(uobj[z].ID,uobj[z+1].ID);
                strcpy(uobj[z].SorE,uobj[z+1].SorE);
                uobj[z].DOB=uobj[z+1].DOB;
            }
            ofstream Write;
            Write.open("Users_List.txt",ios::trunc);
            uc--;
            for (j=0; j<uc; j++)
                Write<<uobj[j].Uname<<'~'<<uobj[j].ID<<'~'<<uobj[j].SorE<<'~'<<uobj[j].DOB<<endl;
            Write.close();
            system("cls");
            title();
            cout<<"\n\t*{The User information is successfully Deleted}*\n";
            BACKDELETEUSER();
        }
    }
    GoBack();
}
void BACKDELETEUSER()
{
    char x;
    while(1)
    {
        cout<<"\nDo you want to Delete Another User [Y/N]: ";
        cin>>x;
        x=toupper(x);
        if (x=='Y' || x=='N')
            break;
        cout<<"\n\t*{Invalid Input Only press Y or N}*\n";
    }
    if(x=='Y')
        DeleteUser();
}
/*****************************Search User Function****************************/
void SearchUser()
{
    if (uc>0)
    {
        int x;
        system("cls");
        title();
        cout<<"\n                      Search User                     \n\n"
            <<"\t(1) Search through  ID Number\n"
            <<"\t(2) Search through  User Name\n"
            <<"\t(3) Search through  Date of Birth [YYYY/MM/DD]\n"
            <<"\t(0) Go back to Main Menu\n";
        while(1)
        {
            cout<<"\nWhat do You want: ";
            cin>>x;
            if (x>=0 && x<=3)
                break;
            cout<<"\n\t*{Please Enter valid Choice}*\n";
        }
        switch (x)
        {
        case 1:
            SUID();
            break;
        case 2:
            SUNAME();
            break;
        case 3:
            SUDOB();
            break;
        case 0:
            GoBack();
            break;
        }
    }
    else
    {
        system("cls");
        title();
        cout<<"\n\n\t*(Note: There are no Users in Database\n\t  Please Add some Users First}*\n\n";
    }
}
void SUID()
{
    bool flag=1;
    int i,UN=0;
    system("cls");
    title();
    cout<<"\n                  Search User by ID                    \n";
    cout<<"\nEnter ID number you want to search: ";
    cin.ignore();
    cin.getline(utemp.ID,id_size);
    for(i=0; i<uc; i++)
    {
        if (!strcmp(uobj[i].ID,utemp.ID))
        {
            uindex[UN]=i;
            cout.setf(ios::left);
            cout<<"\n\nUser no."<<++UN<<setw(20)<<"\n\nUser Name: "<<uobj[i].Uname<<setw(20)<<"\nUser ID: "<<uobj[i].ID<<setw(20)<<"\nStatus:"<<uobj[i].SorE<<setw(20)<<"\nUser DOB: "<<uobj[i].DOB<<endl;
            flag=0;
            break;
        }
    }
    if (flag)
    {
        system("cls");
        title();
        cout<<"\n\t\t*{No Match Found}*\n";
    }
    if (f)
    {
        f=1;
        GoBack();
    }
}
void SUNAME()
{
    bool flag=1;
    int i,UN=0;
    system("cls");
    title();
    cout<<"\n                 Search User by Name                    \n";
    cout<<"\nEnter User name you want to search: ";
    cin.ignore();
    cin.getline(utemp.Uname,un_size);
    for(i=0; i<uc; i++)
    {
        if(!strcmp(uobj[i].Uname,utemp.Uname))
        {
            uindex[UN]=i;
            cout.setf(ios::left);
            cout<<"\n\nUser no."<<++UN<<setw(20)<<"\n\nUser Name: "<<uobj[i].Uname<<setw(20)<<"\nUser ID: "<<uobj[i].ID<<setw(20)<<"\nStatus:"<<uobj[i].SorE<<setw(20)<<"\nUser DOB: "<<uobj[i].DOB<<endl;
            flag=0;
        }
    }
    if (flag)
    {
        system("cls");
        title();
        cout<<"\n\t\t*{No Match Found}*\n";
    }
    if (f)
    {
        f=1;
        GoBack();
    }
}
void SUDOB()
{
    string a;
    bool flag=1;
    int i,UN=0;
    system("cls");
    title();
    cout<<"\n              Search User by Date of Birth                    \n";
    cout<<"\nEnter Date of Birth you want to search [DD/MM/YYYY]: ";
    cin>>a;
    for(i=0; i<uc; i++)
    {
        if(a==uobj[i].DOB)
        {
            uindex[UN]=i;
            cout.setf(ios::left);
            cout<<"\n\nUser no."<<++UN<<setw(20)<<"\n\nUser Name: "<<uobj[i].Uname<<setw(20)<<"\nUser ID: "<<uobj[i].ID<<setw(20)<<"\nStatus:"<<uobj[i].SorE<<setw(20)<<"\nUser DOB: "<<uobj[i].DOB<<endl;
            flag=0;
        }
    }
    if (flag)
    {
        system("cls");
        title();
        cout<<"\n\t\t*{No Match Found}*\n";
    }
    if (f)
    {
        f=1;
        GoBack();
    }
}
/******************************Issue Book Function**********************************/
void IssueBook()
{
    if(c>0 && uc>0)
    {
        if(ic<total_issue_books)
        {
            system("cls");
            title();
            cout<<"\n                     Issue a Book                   \n";
            int i,j;
            bool iuser=1,flag1=0,flag2=0;
            cout<<"\nEnter User ID :";
            cin.ignore();
            cin.getline(itemp.ID,id_size);
            for (j=0; j<ic; j++)
            {
                if (!strcmp(iobj[j].ID,itemp.ID))
                {
                    iuser=0;
                    cout<<"\n\t*{This User has already been Issued a Book\n\t  you can't Issue Another Book to User Id. "<<itemp.ID<<" }*\n\n";
                    break;
                }
            }
            if (iuser)
            {
                for (i=0; i<uc; i++)
                {
                    if (!strcmp(uobj[i].ID,itemp.ID))
                    {
                        cout<<"\n\t*{There is a User in Database with User ID. "<<itemp.ID<<" }*\n\n";
                        flag1=1;
                        break;
                    }
                }
                if (flag1)
                {
                    cout<<"\nEnter ISBN Number of Book :";
                    getline(cin,itemp.ISBN);
                    for (i=0; i<c; i++)
                    {
                        string a(obj[i].ISBN);
                        if (a==itemp.ISBN)
                        {
                            cout<<"\n\t*{There is a Book in Database with Book ISBN. "<<itemp.ISBN<<" }*\n\n";
                            flag2=1;
                            break;
                        }
                    }
                    if(flag2)
                    {
                        cout<<"\nEnter Issue Date [DD/MM/YYYY] :";
                        getline(cin,itemp.IDate);
                        cout<<"\nEnter Return Date [DD/MM/YYYY] :";
                        getline(cin,itemp.RDate);
                    }
                    else
                    {
                        cout<<"\n\t*{There is NO Book in Database with "<<itemp.ID<<" Book ISBN}*\n\n";
                    }
                }
                else
                {
                    cout<<"\n\t*{There is NO User in Database with "<<itemp.ID<<" User ID\n\t  You have Add this In the Database first}*\n\n";
                }
                if (flag1 && flag2)
                {
                    iobj[ic].ISBN=itemp.ISBN;
                    iobj[ic].IDate=itemp.IDate;
                    iobj[ic].RDate=itemp.RDate;
                    strcpy(iobj[ic].ID,itemp.ID);
                    ofstream Write;
                    Write.open("IssuedBooks_List.txt",ios::app);
                    Write<<iobj[ic].ID<<'~'<<iobj[ic].ISBN<<'~'<<iobj[ic].IDate<<'~'<<iobj[ic].RDate<<endl;
                    ic++;
                    Write.close();
                    system("cls");
                    title();
                    cout<<"\n\t*{The book has been Issued}*\n";
                }
            }
            BACKISSUEBOOK();
        }
        else
        {
            system("cls");
            title();
            cout<<"\n\n\t*{Note: you have reached limit! \n\t  You can't Issue anymore Books}*\n\n";
        }
    }
    else
    {
        system("cls");
        title();
        cout << "\n\t*{Note: Add some Books and Users\n\t  Only then you can Issue Book}*\n\n";
    }
}
void BACKISSUEBOOK()
{
    char x;
    while(1)
    {
        cout<<"\nDo you want to Issue another Book [Y/N]: ";
        cin>>x;
        x=toupper(x);
        if (x=='Y' || x=='N')
            break;
        cout<<"\n\t*{Invalid Input Only press Y or N}*\n";
    }
    if (x=='Y')
        IssueBook();
}
/*****************************Delete Issued Book Function***********************/
void DeleteIssueBook()
{
    if (ic>0)
    {
        system("cls");
        title();
        cout<<"\n                  Delete Issued a Book                   \n";
        cout<<"\nEnter user ID:";
        cin.getline(itemp.ID,id_size);
        bool flag=0,flag1=0;
        int i,j;
        char x;
        for (i=0; i<ic; i++)
        {
            if (!strcmp(iobj[i].ID,itemp.ID))
            {
                cout<<"\n\t\t*{User ID Found}*\n";
                for (j=0; j<c; j++)
                {
                    string a(obj[j].ISBN);
                    if(iobj[i].ISBN==a)
                    {
                        cout<<"\n\t\t\tBook Details\n\n";
                        cout.setf(ios::left);
                        cout<<setw(20)<<"\n\nBook Name:  "<<obj[j].Name<<setw(20)<<"\nBook ISBN: "<<obj[j].ISBN<<setw(20)<<"\nPublisher Name: "<<obj[j].Publisher<<setw(20)<<"\nAuthor Name: "<<obj[j].Author<<setw(20)<<"\nCopies: "<<obj[j].Copies<<setw(20)<<"\nIssue Date: "<<obj[j].Issue_Date<<endl;
                        cout<<setw(20)<<"\nDate of Issue: "<<iobj[i].IDate<<setw(20)<<"\nReturn Date: "<<iobj[i].RDate;
                        flag=1;
                        break;
                    }
                }
                break;
            }
            else
            {
                system("cls");
                title();
                cout<<"\n\tThere is NO User in Database with User ID. "<<itemp.ID<<"\n\t  You have Add this In the Database first}*\n\n";
            }
        }
        if (flag)
        {
            while(1)
            {
                cout<<"\n\nAre you sure you want to delete the Issued Book [Y/N] : ";
                cin>>x;
                x=toupper(x);
                if (x=='Y')
                {
                    flag1=1;
                    break;
                }
                else if (x=='N')
                    break;
                cout<<"\n\t*{Invalid Input only press Y or N}*\n";
            }
            if (flag1)
            {
                system("cls");
                title();
                for ( ; i<ic-1; i++)
                {
                    strcpy(iobj[i].ID,iobj[i+1].ID);
                    iobj[i].ISBN=iobj[i+1].ISBN;
                    iobj[i].IDate=iobj[i+1].IDate;
                    iobj[i].RDate=iobj[i+1].RDate;
                }
                ofstream Write;
                Write.open("IssuedBooks_List.txt",ios::trunc);
                ic--;
                for (j=0; j<ic; j++)
                    Write<<iobj[j].ID<<' '<<iobj[j].ISBN<<'~'<<iobj[j].IDate<<'~'<<iobj[j].RDate<<endl;
                system("cls");
                title();
                cout<<"\n\t{*The data of selected Issued book has been Deleted}*\n";
            }
        }
        BACKDELETEISSUEBOOK();
    }
    else
    {
        system("cls");
        title();
        cout<<"\n\t*{Currently,there are no Issued Book}*\n\n";
    }
}
void BACKDELETEISSUEBOOK()
{
    char x;
    while(1)
    {
        cout<<"\nDo you want to Delete Another Issued Book [Y/N]: ";
        cin>>x;
        x=toupper(x);
        if (x=='Y' || x=='N')
            break;
        cout<<"\n\t*{Invalid Input Only press Y or N}*\n";
    }
    if (x=='Y')
        DeleteIssueBook();

}
void DisplayAllBooks()
{
    system("cls");
    title();
    if (c>0)
    {
        cout<<"\n\n                      All Books                     \n";
        int i;
        BN=0;
        for (i=0; i<c; i++)
        {
            cout.setf(ios::left);
            cout<<"\n\nBOOk no. "<<++BN<<setw(20)<<"\n\nBook Name:  "<<obj[i].Name<<setw(20)<<"\nBook ISBN: "<<obj[i].ISBN<<setw(20)<<"\nPublisher Name: "<<obj[i].Publisher<<setw(20)<<"\nAuthor Name: "<<obj[i].Author<<setw(20)<<"\nCopies: "<<obj[i].Copies<<setw(20)<<"\nIssue Date: "<<obj[i].Issue_Date<<endl;
        }
    }
    else
        cout<<"\n\n\t*{Note: There are no books in Database\n\t  Please Add some Books First}*\n\n";
    GoBack();
}
void DisplayAllUsers()
{
    system("cls");
    title();
    if (uc>0)
    {
        cout<<"\n\n                      All Users                     \n";
        int i;
        UN=0;
        for (i=0; i<uc; i++)
        {
            cout.setf(ios::left);
            cout<<"\n\nUser no."<<++UN<<setw(20)<<"\n\nUser Name: "<<uobj[i].Uname<<setw(20)<<"\nUser ID: "<<uobj[i].ID<<setw(20)<<"\nStatus:"<<uobj[i].SorE<<setw(20)<<"\nUser DOB: "<<uobj[i].DOB<<endl;
        }
    }
    else
        cout<<"\n\n\t*{Note: There are no Users in Database\n\t  Please Add some Users First}*\n\n";
    GoBack();
}
void DisplayAllIssuedBooks()
{
    system("cls");
    title();
    if (ic>0)
    {
        cout<<"\n\n                   All Issued Books                     \n";
        int i,j;
        BN=0;
        for (i=0; i<ic; i++)
        {
            for (j=0; j<c; j++)
            {
                string a(obj[j].ISBN);
                if (iobj[i].ISBN==a)
                {
                    cout.setf(ios::left);
                    cout<<"\n\nBOOk no. "<<++BN<<setw(20)<<"\n\nBook Name:  "<<obj[i].Name<<setw(20)<<"\nBook ISBN: "<<obj[i].ISBN<<setw(20)<<"\nPublisher Name: "<<obj[i].Publisher<<setw(20)<<"\nAuthor Name: "<<obj[i].Author<<setw(20)<<"\nCopies: "<<obj[i].Copies<<setw(20)<<"\nIssue Date: "<<obj[i].Issue_Date<<endl;
                    break;
                }
            }
        }
    }
    else
        cout<<"\n\n\t*{Note: There are no Issued Books in Database\n\t  Please Issue some Books First}*\n\n";
    GoBack();
}
