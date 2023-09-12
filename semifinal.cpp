#include<iostream>
#include<cstring>
#include<cstdlib>
#include<fstream>
#include<conio.h>
#include<windows.h>
#include <string>
#include <sstream>
#include<cmath>
#include <ctime>
#include<bits/stdc++.h>
using namespace std;

struct node
{
    string name1;
    string ID1;
    string DoB1;
    string fathers_name1;
    string mothers_name1;
    string flagl;
    string locationl;
    string mnol;
    string admitl;
    struct node *next;
};
struct node *head2=NULL, *curr2, *tail2, *temp_a, *temp_a2,*sear,*temp1,*sea;
int ko;
int haspass;


#define NODE 1000
#define INF 1000005
int n,e;
int dis[NODE];
int vis[NODE];
int val,mn=INF,pos;
vector<int>adj[NODE],adjw[NODE];
struct Element
{
    int node;
    int path_cost;

    Element(int _node,int _path_cost)
    {
        node=_node;
        path_cost=_path_cost;

    }
    bool operator<(const Element&a)const
    {
        return path_cost<a.path_cost;
    }
    bool operator>(const Element&a)const
    {
        return path_cost>a.path_cost;
    }

};

priority_queue<Element,vector<Element>,greater<Element> >pq;


void initial(){

    string i,n,d,f,m,r,l,mn,ad;
    fstream infile;
    infile.open("new.txt", ios::in);
    while(infile.eof()!=true)
    {
            getline(infile, i);
            getline(infile, n);
            getline(infile, d);
            getline(infile, f);
            getline(infile, m);
            getline(infile, r);
            getline(infile, mn);
            getline(infile, l);
            getline(infile, ad);
            curr2=new node;
            curr2->name1=n;
            curr2->ID1=i;
            curr2->DoB1=d;
            curr2->fathers_name1=f;
            curr2->mothers_name1=m;
            curr2->flagl=r;
            curr2->mnol=mn;
            curr2->locationl=l;
            curr2->admitl=ad;
            curr2->next=NULL;

            //Base case:
            if(head2==NULL)
            {
                head2=curr2;
                tail2=curr2;
            }
            else
            {
                tail2->next=curr2;
                tail2=curr2;
            }

        }
    infile.close();

}




//show patientlist in admil panel.

void patientlist(){
     system("cls");
    cout<<"\t\t\t\t ======================================================================== "<<endl;

    cout<<"\t\t\t\t ======================================================================== "<<endl;
    cout<<"\t\t\t\t\t\t\t\tPATIENT LIST"<<endl;
    cout<<"\t\t\t\t ======================================================================== "<<endl;

    cout<<"\t\t\t\t ======================================================================== "<<endl<<endl<<endl;
    int i=0;
    curr2=head2;
    while(curr2!=NULL)
    {
        cout<<"\t [ "<<i+1<<" ] "<<endl;
        cout<<"\t Name          : "<<curr2->name1<<endl;
        cout<<"\t Patient ID    : "<<curr2->ID1<<endl;
        cout<<"\t Date of Birth : "<<curr2->DoB1<<endl;
        cout<<"\t Father's Name : "<<curr2->fathers_name1<<endl;
        cout<<"\t Mother's Name : "<<curr2->mothers_name1<<endl;
        cout<<"\t Mobile Number : "<<curr2->mnol<<endl;
        cout<<"\t Location      : "<<curr2->locationl<<endl;
        cout<<"\t Admit Time    : "<<curr2->admitl<<endl;
        if(curr2->flagl=="1")
        {
        cout<<"\t Covid Status  : Positive"<<endl;
        }
        else
        {
        cout<<"\t Covid Status  : Negative!"<<endl;
        }
        cout<<endl<<endl;
        Sleep(200);
        curr2=curr2->next;
        i++;
    }
    cout<<endl<<endl<<"\t\t\t\t PRESS ENTER TO BACK "<<endl;

}


void deleteList(node** head_ref)
{

    /* deref head_ref to get the real head */
    node* current = *head_ref;
    node* next = NULL;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }

    /* deref head_ref to affect the real head back
        in the caller. */
    *head_ref = NULL;
}







void newpatient(){
    system("cls");
     cout<<"\t\t\t\t========================================================================"<<endl;
    cout<<"\t\t\t\t\t\t\tCOVID PATIENT ADDING: ENTER YOUR INFORMATION "<<endl;
    cout<<"\t\t\t\t========================================================================"<<endl<<endl<<endl;
     string name,fathername,mothername,birthdate,mobile_number,adress;


     cout<< "\t\tEnter your Name                        : ";
     cin>> name;
     cout<< "\t\tEnter fathers Name                     : ";
     cin>>fathername;
     cout<< "\t\tEnter Mother Name                      : ";
     cin>>mothername;
     cout<< "\t\tEnter Your Date of Birth(dd-mm-year)   : ";
     cin>>birthdate;
     mon:
     cout<< "\t\tEnter Mobile Number(should be 11 digit): ";
     cin>> mobile_number;

    if(mobile_number.length()!=11){
        cout<<"\n\n\t\tyour number should be 11 digit . Please try  again.";
         ion:
        int ok;
        cout<<"\n\t\tPress '1' to try again or '2' for menu:\n";
        cin>>ok;
        if(ok==1){
                goto mon;

        }
        else if(ok==2){
                cout<<endl<<endl<<"\t\t\t\t PRESS ENTER TO BACK "<<endl;
                return;
            }
        else{
            cout<<"\n\n\t\tYour selected option is incorrect. TRY AGAIN.";
            goto ion;
        }

     }
     cout<<"\t\tPlease Input Your Address(just city)   :";
     cin>> adress;
     time_t t = time(NULL);
     tm* tPtr = localtime(&t);
     ofstream myfile("new.txt",std::ios::app);

     if(myfile == NULL)
        {cout<< "we can't find any data";
        return;}
    sea = tail2;
    string nid= sea->ID1;
   int m= atoi(nid.c_str())+1;
   myfile<<endl<<m;
   myfile<<endl<<name;
   myfile<<endl<<birthdate;
   myfile<<endl<<fathername;
   myfile<<endl<<mothername;
   myfile<<endl<<"1";
   myfile<<endl<<mobile_number;
   myfile<<endl<<adress;
   myfile<<endl<<(tPtr->tm_mday)<<"-"<<(tPtr->tm_mon)+1 <<"-"<< (tPtr->tm_year)+1900<< "   ::  " <<(tPtr->tm_hour)<< ":" <<(tPtr->tm_min)<<":"<<(tPtr->tm_sec);
   myfile.close();


   deleteList(&head2);


   initial();

   sear = tail2;
      //int check=0;


   /*if(temp_a->ID1== geek)
        {*/
            system("cls");
            cout<<"\n\n\t\t\tYour information is successfully saved. "<<endl;
//            check=1;
            cout<<"\n\t\t\t\t Your information:"<<endl<<endl;
            cout<<"\t\t\t\t PATIENT ID No : "<<sear->ID1<<endl;
            cout<<"\t\t\t\t NAME          : "<<sear->name1<<endl;
            cout<<"\t\t\t\t DATE OF BIRTH : "<<sear->DoB1<<endl;
            cout<<"\t\t\t\t FATHER'S NAME : "<<sear->fathers_name1<<endl;
            cout<<"\t\t\t\t MOTHER'S NAME : "<<sear->mothers_name1<<endl;
            cout<<"\t\t\t\t Mobile Number : "<<sear->mnol<<endl;
            cout<<"\t\t\t\t Location      : "<<sear->locationl<<endl;
            if(sear->flagl=="1")
            {
            cout<<"\t\t\t\t Covid Status  : Positive"<<endl;
            }
            else if(sear->flagl=="0")
            {
            cout<<"\t\t\t\t Covid Status  : Negative!"<<endl;
            }
                cout<<endl<<endl<<endl<<endl;

            //}

    /*if(check==0){
        printf("\n\tYour information is not added successfully. \n\tPlease try again or Contact with athority ");
    }*/
   cout<<endl<<endl<<"\t\t\t\t PRESS ENTER TO BACK "<<endl;
}


void admin_searchpatient(){
 id:
    string id;
    int check=0;
    system("cls");
    cout<<endl;

    cout<<"\t\t\t\t========================================================================"<<endl;
    cout<<"\t\t\t\t\t\t\t ENTER YOUR INFORMATION "<<endl;
    cout<<"\t\t\t\t========================================================================"<<endl<<endl<<endl;

    cout<<"\t\t\tENTER YOUR PATIENT ID NUMBER(should be 6digit(sample: 110001)   "<<endl<<endl;
    cout<<"\t\t\t\t";
    cin>>id;
    temp_a=head2;

    while(temp_a!=NULL)
    {
        if(temp_a->ID1==id)
        {
            check=1;
            cout<<"\t\t\t\t PATIENT ID No.: "<<temp_a->ID1<<endl;
            cout<<"\t\t\t\t NAME          : "<<temp_a->name1<<endl;
            cout<<"\t\t\t\t DATE OF BIRTH : "<<temp_a->DoB1<<endl;
            cout<<"\t\t\t\t FATHER'S NAME : "<<temp_a->fathers_name1<<endl;
            cout<<"\t\t\t\t MOTHER'S NAME : "<<temp_a->mothers_name1<<endl;
            cout<<"\t\t\t\t Mobile Number : "<<temp_a->mnol<<endl;
            cout<<"\t\t\t\t Location      : "<<temp_a->locationl<<endl;
            cout<<"\t\t\t\t Admit Time    : "<<curr2->admitl<<endl;

            if(temp_a->flagl=="1")
            {
            cout<<"\t\t\t\t Covid Status  : Positive"<<endl;
            }
            else if(temp_a->flagl=="0")
            {
            cout<<"\t\t\t\t Covid Status  : Negative!"<<endl;
            }
                cout<<endl<<endl<<endl<<endl;
            break;
            }

        temp_a=temp_a->next;

    }
    if(check==0){
            cout<<"\n\t\tYOUR ID NO IS WRONG.";
    option:
        int ok;
        cout<<"\n\tPress '1' to try again or '2' for menu:\n";
        cin>>ok;
        if(ok==1){
                goto id;

        }
        else if(ok==2){
                return;
            }
        else{
            cout<<"\n\n\t\tYour selected option is incorrect. TRY AGAIN.";
            goto option;
        }
    }

}

void searchpatient(){
 id:
    string id;
    int check=0;
    system("cls");
    cout<<endl;

    cout<<"\t\t\t\t========================================================================"<<endl;
    cout<<"\t\t\t\t\t\t\t ENTER YOUR INFORMATION "<<endl;
    cout<<"\t\t\t\t========================================================================"<<endl<<endl<<endl;

    cout<<"\t\t\tENTER YOUR PATIENT ID NUMBER(should be 6digit(sample: 110001)   "<<endl<<endl;
    cout<<"\t\t\t\t";
    cin>>id;
    temp_a=head2;

    while(temp_a!=NULL)
    {
        if(temp_a->ID1==id)
        {
            check=1;
            cout<<"\t\t\t\t PATIENT ID No.: "<<temp_a->ID1<<endl;
            cout<<"\t\t\t\t NAME          : "<<temp_a->name1<<endl;
            cout<<"\t\t\t\t Location      : "<<temp_a->locationl<<endl;
            if(temp_a->flagl=="1")
            {
            cout<<"\t\t\t\t Covid Status  : Positive"<<endl;
            }
            else if(temp_a->flagl=="0")
            {
            cout<<"\t\t\t\t Covid Status  : Negative!"<<endl;
            }
                cout<<endl<<endl<<endl<<endl;
            break;
            }

        temp_a=temp_a->next;

    }
    if(check==0){
            cout<<"\n\t\tYOUR ID NO IS WRONG.";
    option:
        int ok;
        cout<<"\n\tPress '1' to try again or '2' for menu:\n";
        cin>>ok;
        if(ok==1){
                goto id;

        }
        else if(ok==2){
                return;
            }
        else{
            cout<<"\n\n\t\tYour selected option is incorrect. TRY AGAIN.";
            goto option;
        }
    }

}


void recovered(){

system("cls");
    cout<<"\t\t\t\t ======================================================================== "<<endl;

    cout<<"\t\t\t\t ======================================================================== "<<endl;
    cout<<"\t\t\t\t\t\t\t\tCOVID RECOVERD LIST"<<endl;
    cout<<"\t\t\t\t ======================================================================== "<<endl;

    cout<<"\t\t\t\t ======================================================================== "<<endl<<endl<<endl;
    int i=0;
    curr2=head2;
    while(curr2!=NULL)
    {
        if(curr2->flagl=="0"){
        cout<<"\t [ "<<i+1<<" ] "<<endl;
        cout<<"\t Name          : "<<curr2->name1<<endl;
        cout<<"\t Patient ID    : "<<curr2->ID1<<endl;
        cout<<"\t Date of Birth : "<<curr2->DoB1<<endl;
        cout<<"\t Father's Name : "<<curr2->fathers_name1<<endl;
        cout<<"\t Mother's Name : "<<curr2->mothers_name1<<endl;
        cout<<"\t Mobile Number : "<<curr2->mnol<<endl;
        cout<<"\t Location      : "<<curr2->locationl<<endl;
        cout<<"\t Admit Time    : "<<curr2->admitl<<endl;
        }
        cout<<endl<<endl;
        Sleep(200);
        curr2=curr2->next;
        i++;
    }
    cout<<endl<<endl<<"\t\t\t\t PRESS ENTER TO BACK "<<endl;



}


void infected(){
    system("cls");
    cout<<"\t\t\t\t ======================================================================== "<<endl;

    cout<<"\t\t\t\t ======================================================================== "<<endl;
    cout<<"\t\t\t\t\t\t\t\tCOVID INFECTED LIST"<<endl;
    cout<<"\t\t\t\t ======================================================================== "<<endl;

    cout<<"\t\t\t\t ======================================================================== "<<endl<<endl<<endl;
    int i=0;
    curr2=head2;
    while(curr2!=NULL)
    {
        if(curr2->flagl=="1"){
        cout<<"\t [ "<<i+1<<" ] "<<endl;
        cout<<"\t Name          : "<<curr2->name1<<endl;
        cout<<"\t Patient ID    : "<<curr2->ID1<<endl;
        cout<<"\t Date of Birth : "<<curr2->DoB1<<endl;
        cout<<"\t Father's Name : "<<curr2->fathers_name1<<endl;
        cout<<"\t Mother's Name : "<<curr2->mothers_name1<<endl;
        cout<<"\t Mobile Number : "<<curr2->mnol<<endl;
        cout<<"\t Location      : "<<curr2->locationl<<endl;
        cout<<"\t Admit Time    : "<<curr2->admitl<<endl;
        }
        cout<<endl<<endl;
        Sleep(200);
        curr2=curr2->next;
        i++;
    }
    cout<<endl<<endl<<"\t\t\t\t PRESS ENTER TO BACK "<<endl;

}



void init(int src)
{
    for(int i=1; i<=n; i++)
    {
        dis[i]=INF;
        vis[i]=0;

    }
    dis[src]=0;
    pq.push(Element(src,0));
}


void dijktra(int src)
{
    init(src);
    int v,w,u;
    while(!pq.empty())
    {
        u=pq.top().node;
        pq.pop();
        if(vis[u]==1)
            continue;
        vis[u]=1;
        for(int i=0; i<adj[u].size(); i++)
        {
            v=adj[u][i];
            w=adjw[u][i];
            if((dis[u]+w)<dis[v])
            {

                dis[v]=dis[u]+w;
                pq.push(Element(v,dis[v]));
            }
        }

    }
}
char hospital[][20]={" "," ","Covid","Vartual","Central","Special Covid","Square","Bardem"};

void addValue()
{
    n=7,e=11;
    int u[]={1,1,1,7,7,3,4,7,6,5,2};
    int v[]={7,3,5,3,4,4,6,6,5,2,3};
    int w[1000];
    //={3,4,7,2,2,5,2,2,4,8,6};


    srand (time(NULL));
    for(int j=0; j<11;j++){
        w[j]= rand()%15+5;
    }

    for(int i=0; i<e; i++)
    {
        adj[u[i]].push_back(v[i]);
        adj[v[i]].push_back(u[i]);
        adjw[u[i]].push_back(w[i]);
        adjw[v[i]].push_back(w[i]);
    }
}
void schHospital(){


    addValue();

    dijktra(1);

    for(int i=2; i<=n; i++)
    {

       printf("\n\t\t\tDistance from current position  to ''%s hospital'' is %d km\n",hospital[i],dis[i]);
    }
    for(int i=0;i<=n;i++)
    {
        val=min(dis[i],dis[i+1]);
        if(mn>val && val !=0){
            mn=val;
            pos=i+1;
        }

    }
     printf("\n\n\t\tAmong them nearest ons is ''%s hospital'' which is %d km away\n",hospital[pos],mn);


}




string hasing(string password){
haspass =0;
    for(int i=0; i<password.length(); i++)
    {
        haspass+=(password[i]-'a'+1)*i;
    }
    ostringstream pas;
    pas << haspass;
    string hasspass = pas.str();

return hasspass;

}





void passwordchange(){
pa:
    cout<<"\n\t\tENTER YOUR CURRENT PASSWORD:   ";
    fstream pass;
    string p,pin,hpin;
    pass.open("password");
    getline(pass, p);
    pass.close();
    cin>>pin;
    hpin = hasing(pin);
    if(hpin==p){
        ofstream passch;
        string changepass,haschapass;
        passch.open("password",ios::out);
        cout<<"\n\t\tWRITE YOUR NEW PASSWORD and PRESS 'enter' key:  ";
        cin>>changepass;
        haschapass = hasing(changepass);
        passch<<haschapass;
        cout<<"\n\t\tPASSWORD CHANGED SUCCESSFULLY !!!";
        passch.close();

    }
    else{
            op:
            int ok;
        cout<<"\n\t\tYour password is wrong.\n\t\tPress '1' to try again or '2' for menu:";
        cin>>ok;
        if(ok==1){
                goto pa;

        }
        if(ok==2){
            }
        else{
            cout<<"\n\t\tYour selected option is incorrect. TRY AGAIN.";
            goto op;
        }
    }
}


void forgetpassword(){

    fagn:
    cout<< "\n\t\tPLESE WRITE OUR SECURITY CODE   :";
    string fp;
    cin>>fp;
    if(fp=="SIR"){
        ofstream myfile("password",ios::out);
        string p,np,sp;
        cout<< "\n\t\tPlease Enter your new password   :";
        cin>> np;
        sp = hasing(np);
        myfile<<sp;
        cout<<"\n\t\tYour Password is successfully reset  .";
    }
    else{
        option:
        int ok;
        cout<<"\n\t\tYour security code is wrong.\n\n\t\tPress '1' to try again or '2' for menu:\n";
        cin>>ok;
        if(ok==1){
                goto fagn;

        }
        if(ok==2){
            }
        else{
            cout<<"\n\n\t\tYour selected option is incorrect. TRY AGAIN.";
            goto option;
        }
    }

}

void editfile(){

    temp_a=head2;
     ofstream myfile("new.txt",ios::out);
    while(temp_a!=NULL){
            if(temp_a->next == NULL){
                myfile<<temp_a->ID1<<endl;
                myfile<<temp_a->name1<<endl;
                myfile<<temp_a->DoB1<<endl;
                myfile<<temp_a->fathers_name1<<endl;
                myfile<<temp_a->mothers_name1<<endl;
                myfile<<temp_a->flagl<<endl;
                myfile<<temp_a->mnol<<endl;
                myfile<<temp_a->locationl<<endl;
                myfile<<temp_a->admitl;
                return;
            }
        myfile<<temp_a->ID1<<endl;
        myfile<<temp_a->name1<<endl;
        myfile<<temp_a->DoB1<<endl;
        myfile<<temp_a->fathers_name1<<endl;
        myfile<<temp_a->mothers_name1<<endl;
        myfile<<temp_a->flagl<<endl;
        myfile<<temp_a->mnol<<endl;
        myfile<<temp_a->locationl<<endl;
        myfile<<temp_a->admitl<<endl;

        temp_a= temp_a->next;

    }
    myfile.close();
    initial();

}


void recovery(){
    id:
    string id;
    int check=0;
    system("cls");
    cout<<endl;

    cout<<"\t\t\t\t========================================================================"<<endl;
    cout<<"\t\t\t\t\t\t\t ENTER YOUR INFORMATION "<<endl;
    cout<<"\t\t\t\t========================================================================"<<endl<<endl<<endl;

    cout<<"\t\t\tENTER YOUR PATIENT ID NUMBER(should be 6digit(sample: 110001)   "<<endl<<endl;
    cout<<"\t\t\t\t";
    cin>>id;
    temp_a=head2;

    while(temp_a!=NULL)
    {
        if(temp_a->ID1==id)
        {
            check=1;
            cout<<"\t\t\t\t PATIENT ID No.: "<<temp_a->ID1<<endl;
            cout<<"\t\t\t\t NAME          : "<<temp_a->name1<<endl;
            cout<<"\t\t\t\t Location      : "<<temp_a->locationl<<endl;
            cout<<"\t\t\t\t FATHER'S NAME : "<<temp_a->fathers_name1<<endl;
            cout<<"\t\t\t\t MOTHER'S NAME : "<<temp_a->mothers_name1<<endl;
            optin:
            cout<<"\n\n\t\t Please match the information and press 1 when covid negative or back 2 main menu press 2:  ";

            cin>>ko;
        if(ko==1){
               temp_a->flagl = '0';

        }
        else if(ko==2){
                return;
            }
        else{
            cout<<"\n\n\t\tYour selected option is incorrect. TRY AGAIN.";
            goto optin;

            }}

        temp_a=temp_a->next;

    }
    if(check==0){
            cout<<"\n\t\tYOUR ID NO IS WRONG.";
    option:
        int ok;
        cout<<"\n\tPress '1' to try again or '2' for menu:\n";
        cin>>ok;
        if(ok==1){
                goto id;

        }
        else if(ok==2){
                return;
            }
        else{
            cout<<"\n\n\t\tYour selected option is incorrect. TRY AGAIN.";
            goto option;
        }
    }
    editfile();
    cout<<endl<<endl<<"\t\tPRESS ANY KEY TO BACK"<<endl<<endl<<endl;
                getch();



}



void admin(){
system("cls");
    cout<<"\t\t\t\t ======================================================================== "<<endl;

    cout<<"\t\t\t\t ======================================================================== "<<endl;
    cout<<"\t\t\t\t\t\t\t\tADMIN PANEL"<<endl;
    cout<<"\t\t\t\t ======================================================================== "<<endl;

    cout<<"\t\t\t\t ======================================================================== "<<endl<<endl<<endl;
    cout<<"\t\t\t\t\t\tENTER PASSWORD TO ENTER ADMIN PANEL "<<endl<<endl<<endl;
    string password;
    cout<<"\t\t\t\t\t";
    cin>>password;

    fstream pass;
    string p;
    pass.open("password");
    getline(pass, p);
    string hasspass = hasing(password);
    if(hasspass==p)
    {
        while(1)
        {

            system("cls");

            cout<<"\t\t\t\t ======================================================================== "<<endl;

            cout<<"\t\t\t\t ======================================================================== "<<endl;
            cout<<"\t\t\t\t\t\t\t\tADMIN PANEL"<<endl;
            cout<<"\t\t\t\t ======================================================================== "<<endl;

            cout<<"\t\t\t\t ======================================================================== "<<endl<<endl<<endl<<endl;
            cout<<"\t\t\t\t [1] SHOW ALL PATIENT LIST "<<endl<<endl;
            cout<<"\t\t\t\t [2] ADD A NEW PATIENT LIST "<<endl<<endl;
            cout<<"\t\t\t\t [3] SEARCH A INDIVIDUAL PATIENT "<<endl<<endl;
            cout<<"\t\t\t\t [4] SHOW PATIENT LIST WHO RECOVERED "<<endl<<endl;
            cout<<"\t\t\t\t [5] SHOW PATIENT LIST WHO INFECTED"<<endl<<endl;
            cout<<"\t\t\t\t [6] SEARCH NEAREST HOSPITAL "<<endl<<endl;
            cout<<"\t\t\t\t [7] CHANCE THE PASSWORD "<<endl<<endl;
            cout<<"\t\t\t\t [8] RECOVERY PATIEN"<<endl<<endl;
            cout<<"\t\t\t\t [9] EXIT ADMIN PANEL "<<endl<<endl;

            int n;
            cout<<"\t\t\t\t ENTER YOUR CHOICE : ";
            cin>>n;
            if(n==1)
            {
                patientlist();
                getch();
            }
            else if(n==2){
                newpatient();
                getch();
            }

            else if(n==3)
            {   admin_searchpatient();
                getch();
            }
            else if(n==4){

                recovered();
                getch();

            }

            else if(n==5)
            {
                infected();
                getch();
            }


            if(n==6)
            {
                schHospital();
                getch();
            }

            if(n==7){
                passwordchange();
                cout<<endl<<endl<<"\t\t\t PRESS ANY KEY "<<endl;
                getch();
                break;

            }
            if(n==8){
                recovery();
                getch;
            }


            if(n==9)
            {
               cout<<endl<<endl<<"\t\t\t PRESS ANY KEY "<<endl;
               break;
            }
        }
    }
    else
    {
        cout<<endl<<endl<<"\t\t\t WRONG PASSWORD!!!\n\t\t\tTRY AGAIN."<<endl;
    }

}



void canteen(){

    system("cls");

 float weight[1000];
    float calorie[1000];
    string item[10000];
    float x[1000];
    float y[1000];

    int n=6;
    char food[][20]={"Rice","Fish","Vegetable","chicken","Beef","Mutton"};
    cout<< "\n\t\t***** Food Item with weight and calorie*****\n\n "<<endl;
    srand (time(NULL));
    for(int i = 0;i<n;i++)
    {
        cout<< "\t\t\t For "<<food[i]<<  ":" <<endl;

        calorie[i] = rand()%300;
        cout<<"\t\t\t\tcalorie :"<<calorie[i]<<endl;
        weight[i]=rand()%150;
        cout<<"\t\t\t\tweight  :"<<weight[i]<<endl;

        }

    cout<<endl;
    int cap;
    cout<<"\t\t** Please Input Your Weight Capacity: ";
    cin>>cap;
    for(int i = 0; i<n; i++)
        {
            int max = i;
            for(int j =i+0;j<=n;j++)
            {
                if(calorie[j]/weight[j] > calorie[max]/weight[max])
                {
                    max = j;
                }
            }
            swap(calorie[max], calorie[i]);
            swap(weight[max],weight[i]);


        }

        int u = cap;
        int i;
        for(i=0;i<n;i++)
        {
            if(weight[i]>u)
                break;
            x[i] = 1;
            y[i] = weight[i];
            u = u-weight[i];
        }
        if(i<=n)
        {
            x[i] = u/weight[i];
            y[i]=u;

        }









    cout<<"\n\t\tAfter Sorting gm per calorie: "<<endl;
    cout<<"\n\n\t\tcalorie: ";
    for(int i =0;i<n;i++)
        cout<<calorie[i]<<" ";

    cout<<"\n\n\t\tWeight : ";
    for(int i = 0;i<n;i++)
        cout<<weight[i]<<" ";
    cout<<endl;
    cout<<"\n\t\tYou can take the items respectively portion of:";
    for(int i = 0;i<n;i++)
        cout<<x[i]<<" ";
    cout<<endl;


    cout<<"\n\n\t\tTotal calorie is: ";
    float sum = 0;
        for(int i = 0;i<n;i++)
            sum += x[i]*calorie[i];
        cout<<sum;
    cout<<"\n\n\t\tTotal weight you take is: ";
       sum = 0;
        for(int i = 0;i<n;i++)
            sum += y[i];
        cout<<sum;



    return;
}





void home_page(){
    home_page:
    while(1)
    {

        system("cls");
        cout<<endl;

        cout<<"\t\t\t\t ======================================================================== "<<endl;

        cout<<"\t\t\t\t ======================================================================== "<<endl;

        cout<<"\t\t\t\t\t\t\t COVID PATIENT BANK "<<endl;

        cout<<"\t\t\t\t ======================================================================== "<<endl;

        cout<<"\t\t\t\t ======================================================================== "<<endl<<endl<<endl;

        cout<<"\t\t\t\t [1]  ADMIN PANEL "<<endl<<endl;
        cout<<"\t\t\t\t [2]  FORGET YOUR ADMIN PANEL PASSWORD "<<endl<<endl;
        cout<<"\t\t\t\t [3]  SEARCH YOUR INFORMATION "<<endl<<endl;
        cout<<"\t\t\t\t [4]  CANTEEN "<<endl<<endl;

        cout<<"\t\t\t\t [5]  EXIT "<<endl<<endl;
        int choice;

        cout<<endl<<"\t\t\t\t CHOOSE YOUR OPTION : ";
        cin>>choice;

        if(choice==1)
        {
            admin();
            getch();
        }

        if(choice==2){
            forgetpassword();
            cout<<"\n\t\t\t\tPRESS ANY KEY TO BACK MAIN MENU "<<endl;
            getch();

        }

        if(choice==3){
            searchpatient();
             cout<<"\n\t\t\t\tPRESS ANY KEY TO BACK MAIN MENU "<<endl;
            getch();
        }

        if(choice==4){
            canteen();
            cout<<"\n\t\t\t\tPRESS ANY KEY TO BACK MAIN MENU "<<endl;
            getch();
        }

        if(choice==5)
        {
            int ext;
            system("cls");
            cout<<endl<<endl<<"\t\t\t\t *****ARE YOU SURE YOU WANT TO EXIT? *****"<<endl<<endl<<endl<<"\t\t [1] YES"<<endl<<endl<<"\t\t [2] NO"<<endl;
            cout<<endl<<endl<<"\t\tCHOOSE YOUR OPTION :  ";
            cin>>ext;
            if(ext==1)
            {
                cout<<"\n\t\t***THANKS FOR USING***\n\n";
                Sleep(650);
                exit(1);
            }
            else
            {
                cout<<endl<<endl<<"\t\tPRESS ANY KEY TO BACK"<<endl<<endl<<endl;
                getch();
            }
        }

        else
        {

            home_page();
            getch();
        }
    }

}


int main()
{
    char arrshow[]={'W','E','L','C','O','M','E',' ','T','O',' ','C','O','V','I','D',' ','P','A','T','I','E','N','T',' ','B','A','N','K'};
	cout<<"\n\n\n\n\t\t\t";
	for(int i=0;i<29;i++)
	{
		cout<<arrshow[i];
		Sleep(75);

    }
    cout<<"\n\n\n\t\t\tLETS GO_ _ _ _";
    initial();
    getch();
    home_page();
}

