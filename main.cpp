#include <iostream>
#include<cstring>
#include<fstream>
#include <sstream>
#include<stdlib.h>
#include<strstream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

struct Books
{
    char ISBN[6];
    char Title[50];
    char AUTHOR_NAME[50];
    double Price;
    int year;
    int NumOfPages;
};
string int_to_string(string x)
{
    int num=x.length();
    string y="";
    if(num<10)
        y="0";
    stringstream converter;
    converter<<num;
    y+=converter.str();
    return y;
}
int string_to_int(string x)
{
    int y=atoi(x.c_str());
    return y;
}
void AddRecord(Books &record)
{

    cout << "Enter ISBN: ";
    cin.getline(record.ISBN,6) ;
    cout << "Enter Title: ";
    cin.getline(record.Title,50);
    cout << "Enter Author Name: ";
    cin.getline(record.AUTHOR_NAME,50);
    cout << "Enter Price: ";
    cin>>record.Price;
    cout << "Enter Year: ";
    cin>>record.year;
    cout << "Enter Number of pages: ";
    cin>>record.NumOfPages;
    cin.ignore();
}

void write(fstream&in,Books &record)
{
    char buffer[200];
    string y=record.ISBN;
    int num=y.length();
    string x="";
    if(num<10)
        x="0";
    stringstream converter;
    converter<<num;
    x+=converter.str();
    strcpy(buffer,"|");
    strcat(buffer,x.c_str());
    strcat(buffer,record.ISBN);

    y=record.Title;
    num=y.length();
    converter.str("");
    x="";
    if(num<10)
        x="0";
    converter<<num;
    x+=converter.str();
    strcat(buffer,x.c_str());
    strcat(buffer,record.Title);

    y=record.AUTHOR_NAME;
    num=y.length();
    converter.str("");
    x="";
    if(num<10)
        x+="0";
    converter<<num;
    x+=converter.str();
    strcat(buffer,x.c_str());
    strcat(buffer,record.AUTHOR_NAME);

    converter.str("");
    converter<<record.Price;
    x="";
    x=converter.str();
    int ppp=converter.str().length();
    cout<<ppp;
    stringstream converter2;
    converter2<<x.length();
    if(x.length()<10)
        x="0"+converter2.str();
    else
        x=converter2.str();
    strcat(buffer,x.c_str());
    x=converter.str();
    strcat(buffer,x.c_str());

    converter.str("");
    converter<<record.year;
    x="";
    x=converter.str();
    converter2.str("");
    converter2<<x.length();
    if(x.length()<10)
        x="0"+converter2.str();
    else
        x=converter2.str();
    strcat(buffer,x.c_str());
    x=converter.str();
    strcat(buffer,x.c_str());

    converter.str("");
    converter<<record.NumOfPages;
    x="";
    x=converter.str();
    converter2.str("");
    converter2<<x.length();
    if(x.length()<10)
        x="0"+converter2.str();
    else
        x=converter2.str();
    strcat(buffer,x.c_str());
    x=converter.str();
    strcat(buffer,x.c_str());
    in.write(buffer,strlen(buffer));
}

void print(Books &b)
{
    cout << "ISBN: "<<b.ISBN<<endl;
    cout << "Title: "<<b.Title<<endl;
    cout << "Author Name: "<<b.AUTHOR_NAME<<endl;
    cout << "Price: "<<b.Price<<endl;
    cout << "Year: "<<b.year<<endl;
    cout << "Number of pages: "<<b.NumOfPages<<endl<<endl;
}
void readall(fstream & f)
{
    //f.seekg(0);
    //int num=6,i=1;
    //while(i<num)
    //i++;
    char size1[2];
    size1[2]='\0';
    f.read(size1,sizeof(size1));
    cout<<size1;
    string g;
    g=size1;
    int x=atoi(g.c_str());
    string ss;
    f.read((char*)&ss,5);
    /*char tit[100];
    if(all==1)
    {
        cout<<"enter title: ";
        cin.getline(tit,100,'\n');
    }
    Books record;
    in.seekg(0, ios::end);
    int len=in.tellg();
    char buffer[len];
    in.seekg(0,ios::beg);
    in.read(buffer,len);
    string field_len="",temp="";
    int total_rec=0;
    int countt=0;
    for(int i=0; i<len; i+=total_rec+2)
    {
        if(buffer[i]=='*')
        {
            countt=6;
            i++;
        }
        if(buffer[i]=='|')
        {
            i++;
            countt=0;
        }
        field_len=buffer[i];
        field_len+=buffer[i+1];
        total_rec=string_to_int(field_len);
        field_len="";
        for(int j=i+2; j<i+total_rec+2; j++)
        {
            temp+=buffer[j];
        }
        if(countt==0)
            strcpy(record.ISBN,temp.c_str());
        if(countt==1)
            strcpy(record.Title,temp.c_str());
        if(countt==2)
            strcpy(record.AUTHOR_NAME,temp.c_str());
        if(countt==3)
            record.Price=string_to_int(temp);
        if(countt==4)
            record.year=string_to_int(temp);
        if(countt==5)
        {
            record.NumOfPages=string_to_int(temp);
            if(all==0)
                print(record);
        }
        if(all==1&&countt==5&&strcmp(tit,record.Title)==0)
        {
            cout<<"the book is: "<<'\n';
            print(record);
            break;
        }
        countt++;
        temp="";
    }
    in.clear();*/
}
void Delete (fstream & out)
{
    string isbn;
    cout<<"Enter ur ISBN: ";
    cin>>isbn;
    while(isbn.length()>5)
    {
        cout<<"ISBN should be atmost five characters: ";
        cin>>isbn;
    }
    cin.ignore();
    out.seekg(0,ios::end);
    int siz=out.tellg();
    out.seekg(0);
    char buff[siz];
    out.read(buff,siz);

    string field_len="",temp="";
    int total_rec=0;
    int countt=0;


    for(int i=0; i<siz; i++)
    {
        if (buff[i]=='|')
        {
            field_len=buff[i+1];
            field_len+=buff[i+2];
            total_rec=string_to_int(field_len);
            field_len="";
            for(int j=i+3; j<i+total_rec+3; j++)
            {
                temp+=buff[j];
            }
        }
        if(temp==isbn)
        {
            buff[i]='*';
        }
        temp="";
    }
    out.close();
    out.open("Books.txt",ios::out);
    out<<"";
    out.write(buff,siz);
}

void update(fstream &out)
{
    out.seekg(0, ios::end);
    int len=out.tellg();
    char buffer[len];
    out.seekg(0,ios::beg);
    out.read(buffer,len);
    vector<string>rec;
    int cont=0,cont2=0;
    for(int i=0; i<len; i++)
    {
        if(buffer[i]=='|'||buffer[i]=='*')
            cont++;
    }
    string tmp="";
    for(int i=0; i<cont; i++)
    {
        if(buffer[cont2]=='|'||buffer[cont2]=='*')
        {
            while(true)
            {
                tmp+=buffer[cont2];
                cont2++;
                if(buffer[cont2]=='|'||buffer[cont2]=='*'||cont2==len)
                {
                    rec.push_back(tmp);
                    tmp="";
                    break;
                }
            }
        }
    }
    tmp="";
    string isbn_s="";
    string ss;
    cout<<"Enter ur ISBN: ";
    cin>>ss;
    while(ss.length()>5)
    {
        cout<<"ISBN should be atmost five characters: ";
        cin>>ss;
    }
    cin.ignore();
    string tmp3="";
    double price=0;
    int num=0;
    for(int i=0; i<rec.size(); i++)
    {
        tmp=rec[i];
        if(tmp[0]=='|')
        {
            isbn_s=tmp[2];
            int s=string_to_int(isbn_s);
            string tmp2="",data="";
            for(int j=3; j<s+3; j++)
                tmp2+=tmp[j];
            if(tmp2==ss)
            {
                tmp3="|";
                for(int k=0; k<6; k++)
                {
                    if(k==0)
                        cout<<"Enter ISBN: ";
                    if(k==1)
                        cout<<"Enter Title: ";
                    if(k==2)
                        cout<<"Enter Author Name: ";
                    if(k<3)
                        getline(cin,data,'\n');
                    if(k==3)
                    {
                        cout<<"Enter price: ";
                        cin>>price;
                        stringstream p;
                        p<<price;
                        data=p.str();
                    }
                    if(k==4)
                    {
                        cout<<"Enter year: ";
                        cin>>num;
                        stringstream p;
                        p<<num;
                        data=p.str();
                    }
                    if(k==5)
                    {
                        cout<<"Enter num of pages: ";
                        cin>>num;
                        cin.ignore();
                        stringstream p;
                        p<<num;
                        data=p.str();
                    }
                    tmp3+=int_to_string(data);
                    tmp3+=data;
                }
                rec[i]=tmp3;
                break;
            }
        }
    }
    string new_data;
    for(int i=0; i<rec.size(); i++)
        new_data+=rec[i];
    out.close();
    out.open("Books.txt",ios::out);
    out<<"";
    out.write((char*)&new_data[0],new_data.length());


}
int main()
{
    Books r;

    fstream all;
    all.open("Books.txt",ios::in|ios::out|ios::app|ios::binary);
//
//    readall(all);
//    cout<<endl;
   AddRecord(r);
    write(all,r);
//    cout<<endl;
//
//    readall(all,0);
//    cout<<endl;
//
//    update(all);
//    cout<<endl;
//
//    all.close();
//    all.open("Books.txt",ios::in|ios::out);
//
//    readall(all,0);
//    cout<<endl;
//
//    Delete(all);
//    cout<<endl;
//
//    all.close();
//    all.open("Books.txt",ios::in|ios::out);
//
//    readall(all,0);
//    cout<<endl;
//
//    readall(all,1);
//    cout<<endl;

    all.close();
    return 0;
}
