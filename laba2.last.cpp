//������ � �������������� ������
//���� ������ "����"

#include <stdio.h>
#include <conio.h>
#include <iostream>
//#include <locale.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

//��� ������ ��� ����
class TBpla	// int, float, char, ..., TAvto, ...
{
	public:
	char firm[25];	
	string sensors;	
	string mass;
	char madein[50];
	struct TDate
	{
		int D;
		int M;
		int G;

	}data;
	struct TSensors
	{
		char camera[25];
		char lidar[25];
		char gyroscope[25];
		char accelerometer[25];
		char dalult[25];
		char dallaz[25];
		char gps[25];
		
	}namesensors;
	
};

//��� ������ ��� ����� ����
typedef char TName[25];
//��� ������ ��� �������� ����������
typedef FILE TFile;
//���������� ��� ����
TBpla Bpla;
//���������� ��� ����� �����
TName NameFile;
//�������� ����������
TFile *f;
//���� ������ ����� ��� ������
int flag=0;

//** ����� ���� ************************************************************
void menu(void)
{ system("cls");
  cout<<"******** � � � � ********\n\n"
      <<"[1]-��������/�������� ���� ����\n"
      <<"[2]-���������� ���� � ����\n"
      <<"[3]-�������� ���� �� ����\n"
      <<"[4]-�������� ���� ����\n"
      <<"[5]-���������� ������ � �������� �������\n"
      <<"[6]-���������� �������. ����� ���� �� ��������.\n"
      <<"[ ESC ]-�����\n";
}
//** ���� ���� **************************************************
void InputBpla(TBpla &Bpla)
{
     cin.clear(); //�������� ����� � ����� ��������� ���������������� � 0
while (!isspace(cin.get())) //���������� �� ����������� ��������� �����
      continue;
cout<<"���������� ����:\n";
cout<<"������������ ���� ->"; //gets(Tovar.name);
cin.getline(Bpla.firm,25);

cout<<"\n���� ������������:\n";
cout<<"����->";                cin>>Bpla.data.D;
cout<<"�����->";               cin>>Bpla.data.M;
cout<<"���->";                 cin>>Bpla.data.G;

	cout << "������� ���������� �������� � ���� --> ";
	cin >> Bpla.sensors;
	cin.sync();
	cout << "������� �������� ������ --> ";
	cin.getline(Bpla.namesensors.camera, 25);
	cout << "������� �������� ������ --> ";
	cin.getline(Bpla.namesensors.lidar, 25);
	cout << "������� �������� ��������� --> ";
	cin.getline(Bpla.namesensors.gyroscope, 25);
	cout << "������� �������� ������������� --> ";
	cin.getline(Bpla.namesensors.accelerometer, 25);
	cout << "������� �������� ��������������� ���������� --> ";
	cin.getline(Bpla.namesensors.dalult, 25);
	cout << "������� �������� ��������� ���������� --> ";
	cin.getline(Bpla.namesensors.dallaz, 25);
	cout << "������� �������� gps --> ";
	cin.getline(Bpla.namesensors.gps, 25);
	////////////////////////////////////
	cout << "������� ����� ���� --> ";
	cin >> Bpla.mass;
cin.clear(); //�������� ����� � ����� ��������� ���������������� � 0
while (!isspace(cin.get()))
      continue;            //���������� �� ����������� ��������� �����

cout<<"������������� ->";     gets(Bpla.madein);

}
//** ����� ������ �� ����� ************************************************
void OutputBpla(TBpla Bpla)
{
	cout << endl;
	cout << "������������ ����:" << endl;
	
cout 	<< "����� ���� --> " << Bpla.firm << endl
		<< "���������� �������� � ���� --> " << Bpla.sensors << endl
		<< "�������� ������ --> " << Bpla.namesensors.camera << endl
		<< "�������� ������ --> " << Bpla.namesensors.lidar << endl
		<< "�������� ��������� --> " << Bpla.namesensors.gyroscope << endl
		<< "�������� ������������� --> " << Bpla.namesensors.accelerometer << endl
		<< "�������� ��������������� ���������� --> " << Bpla.namesensors.dalult << endl
		<< "�������� ��������� ���������� --> " << Bpla.namesensors.dallaz << endl
		<< "�������� gps --> " << Bpla.namesensors.gps << endl
		<< "����� ���� --> " << Bpla.mass << " �����������(��,�)" << endl;
cout	<<"���� ������������ ������: "
     	<<Bpla.data.D<<":"<<Bpla.data.M<<":"<<Bpla.data.G<<"\n"
     	<<"�������������: "<<Bpla.madein<<"\n";
}
//** ��������/�������� ����� ���� ������ ********************************
void CreateOpenFile( TName &NameFile,int &flag )
{
 char ch;
 flag=0;
 cout<<"������� ��� ����� ��� ������-->";
 //scanf("%s",&NameFile);
 gets(NameFile);
 f=fopen(NameFile,"r");
 if (f==NULL)
    do
     {
     system("cls");
     cout<<"����� � ������ "
         <<NameFile
         <<" ���.\n\n"
         <<"������� ���� � ������ "
         <<NameFile;
     cout<<"������� [ Y ] / [ N ]\n";
     ch=getch();
     if (ch=='Y'||ch=='y')
	{
	  f=fopen(NameFile,"w");
	  cout<<"���� � ������ " <<NameFile<<" ������.\n"
          <<"\n\n��� ����������� ������� ����� �������\n";
	  getch();
	  flag=1;
	}
     if (ch=='N'||ch=='n')
	{
	  cout<< "���� �� ������.\n"
	      <<"\n\n��� ����������� ������� ����� �������\n";
	  getch();
	}
     }
     while ( ! (ch =='Y' || ch=='y' || ch=='N'  || ch=='n'));
    else
	{flag=1;
	cout<<"���� ������� ������\n"
	    <<"\n��� ����������� ������� ����� �������\n";
	getch();
	}
fclose(f);
}

//** ���������� ������ (����) � ���� (� ���� ������) **********
void RecordBpla(TName NameFile, TBpla &Bpla, int flag)
{
  if (flag)
    {
      f=fopen(NameFile,"a");
      InputBpla(Bpla);
      fwrite(&Bpla,1,sizeof(Bpla),f);
      fclose(f);
    }
    else
    {
      cout<<"\n�������� ���� ��� ������.\n"
          <<"������� [ 1 ] � ������� � � � �.";
      getch();
    }
}
//** ����� ����� (���� ������) �� ����� *****************
void VivodFile()
{

  int i=0;
  if (flag)
    {
  f=fopen(NameFile,"r+");

  cout<<"********  ����� ����� �� �����  ********\n"
      <<"****************************************\n";
      while (fread(&Bpla,sizeof(Bpla),1,f)  )
	{
	 //printf("%d",ftell(f));
	 cout<<"����� ������ = "<<i+1<<"\n\n";
	 OutputBpla(Bpla);
	 cout<<"****************************************"<<sizeof(Bpla)<<"\n";
	 i++;
	 if (i % 3 == 0)  //����� �� ��������� ������� (�������)
		{
		getch();
		system("cls");
		cout<<"********  ����� ����� �� �����  ********\n"
		    <<"****************************************\n";
		}
	}
      getch();
      fclose(f);
    }
    else
    {
      cout<<"\n�������� ���� ��� ������.\n"
          <<"������� [ 1 ] � ������� � � � �.";
      getch();
    }

}
//** ������ ����� *****************************
long filesize(TFile *f)
{
   long curpos, length;

   curpos = ftell(f);		//���������� ������� ���������
   fseek(f, 0L, SEEK_END);	//���������� �� ����� �����
   length = ftell(f);		//���������� ��������� � ����� �����
   fseek(f, curpos, SEEK_SET);	//���������� �� ������ ���������
   return length;
}


//** ���������� ������ � �������� ������� ******
void UpdateBpla(TName NameFile, TBpla &Bpla, int flag)
{
  long i=0;
  if (flag)
    {
	f=fopen(NameFile,"r+");

	cout<<"********  ���������� ������ � �������� �������  ********\n\n"
	    <<"********************************************************\n\n"
	    <<"������� ����� ������ ��� ���������� "
	    <<"�� "
	    <<(filesize(f)/sizeof(Bpla))
	    <<" --> ";
	cin>>i;
	//long q;
    fpos_t q;
	//������������ �� ������ � ������� i
	fseek(f, (i-1) * sizeof(Bpla) ,SEEK_CUR);
	//���������� ������� ���������
	fgetpos(f,&q);

	fread(&Bpla,sizeof(Bpla),1,f);
	OutputBpla(Bpla);
	cout<<"****************************************\n";

	char ch;
	cout<<"�������� ������?\n������� [ Y ] / [ N ]\n";
	do
	   {
	   //clrscr();
	   ch=getch();
	   if (ch=='Y'||ch=='y')
		{
		//������ ����� ��������
		InputBpla(Bpla);
		//fseek(f, (i-1) * sizeof(Tovar) ,SEEK_CUR);
		//��������� �� ������ �����
		fsetpos(f,&q);
		//���������� ����� ��������
		fwrite(&Bpla,sizeof(Bpla),1,f);
		cout<<"������ ���������.\n";
		}
	   if (ch=='N'||ch=='n')
		{
		cout<<"������ �� ����������.\n";
		}
	   }
	while ( ! (ch =='Y' || ch=='y' || ch=='N'  || ch=='n'));
    cout<<"\n��� ����������� ������� ����� �������\n";
    getch();
    fclose(f);
    }
    else
    {
      cout<<"\n�������� ���� ��� ������.\n"
          <<"������� [ 1 ] � ������� � � � �.";
      getch();
    }
}
//** �������� ������ �� ���� **********************************
void DeleteBpla(TName NameFile, TBpla &Bpla, int flag)
{
  long i=0,k=0;
  TFile *g;
  if (flag)
    {
	f=fopen(NameFile,"r+");

	cout<<"********  �������� ������ � �������� �������  ********\n\n"
	    <<"********************************************************\n\n"
	    <<"������� ����� ������ ��� �������� "
	    <<"�� "
	    <<(filesize(f)/sizeof(Bpla))
	    <<" --> ";
	cin>>i;

	//������������ �� ������ � ������� i
	fseek(f, (i-1) * sizeof(Bpla) ,SEEK_CUR);
	fread(&Bpla,sizeof(Bpla),1,f);
	OutputBpla(Bpla);
	cout<<"****************************************\n";

	char ch;
	cout<<"������� ������?\n������� [ Y ] / [ N ]\n";
	do
	   {
	   //clrscr();
	   ch=getch();
	   if (ch=='Y'||ch=='y')
		{
		fseek(f,0L,SEEK_SET);
		cout<<"****"<<ftell(f);
		g=fopen("Temp","w");
		while (fread(&Bpla,sizeof(Bpla),1,f)  )
		  {
		  if (k != (i-1) ) fwrite(&Bpla,sizeof(Bpla),1,g);
		  k++;
		  }
		cout<<"������ ���������.\n";
		fclose(g);
		fclose(f);
		remove(NameFile); 	//������� ������ ����
		rename("Temp",NameFile);//��������������� ��������� ����
		}
	   if (ch=='N'||ch=='n')
		{
		cout<<"������ �� ����������.\n";
		}
	   }
	while ( ! (ch =='Y' || ch=='y' || ch=='N'  || ch=='n'));
    cout<<"\n��� ����������� ������� ����� �������\n";
    getch();
    //fclose(f);
    }
    else
    {
      cout<<"\n�������� ���� ��� ������.\n"
          <<"������� [ 1 ] � ������� � � � �.";
      getch();
    }
}
//******************** ��� ������� *****************
void SearchBpla()
{
 int i=0;
  if (flag)
    {
  f=fopen(NameFile,"r");
  char search[15];
  cout<<"������� ��� ������ ��� ������ --> ";
  cin.getline(search, 15);

  cout<<"********  ����� ������ � ���� ������  ********\n"
      <<"****************************************\n";
  while (fread(&Bpla,sizeof(Bpla),1,f)  )
	{

	 
	 if ( strcmp(search, Bpla.firm) == 0 )
	 {
	 	cout<<"����� ������ = "<<i+1<<"\n\n";
	    OutputBpla(Bpla);
	    cout<<"****************************************"<<sizeof(Bpla)<<"\n";
	    i++;
	 	if (i % 3 == 0)  //����� �� ��������� ������� (�������)
		{
			getch();
			system("cls");
			cout<<"********  ����� ������ � ���� ������  ********\n"
		    	<<"****************************************\n";
		}
	 } 
	}
    
	getch();
    fclose(f);
    }
    else
    {
      cout<<"\n�������� ���� ��� ������.\n"
          <<"������� [ 1 ] � ������� � � � �.";
      getch();
    }	
}



//������ ���������

int main()
{
setlocale(0,"");
char ch;
  system("cls");
  do
  {
  menu();
  ch=getch();
  switch (ch)
   {
    case '1':   system("cls");
		CreateOpenFile(NameFile,flag); //�������� � �������� ����� ���� ������
		break;
    case '2':   system("cls");
		RecordBpla(NameFile,Bpla,flag); //������ ������ � ����
		//getch();
		break;
    case '3':   system("cls"); // �������� ������ �� ���� ������
		cout<<"�������� ������ �� ���� ������\n";
		DeleteBpla(NameFile,Bpla,flag);
		getch();
		break;
    case '4':   system("cls");	// ����� ����� �� �����
		VivodFile();
		break;
    case '5':   system("cls");		//���������� ������ � �������� �������
		//printf("���������� ������ � �������� �������\n");
		UpdateBpla(NameFile,Bpla,flag);
		//getch();
		break;
    case '6':	
		system("cls");
		cout<<"���������� ������� � ������������ � ���������:\n����� ������������ ������ � ���� ������\n";
		SearchBpla();
		getch();
		
		break;
//    case '8':	exit(1);
   }
  }
  while	( ch!=27 ) ;
  return 0;
}
