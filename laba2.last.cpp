//Работа с типизированным файлом
//база данных "БПЛА"

#include <stdio.h>
#include <conio.h>
#include <iostream>
//#include <locale.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

//тип данных для БПЛА
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

//тип данных для имени БПЛА
typedef char TName[25];
//тип данных для файловой переменной
typedef FILE TFile;
//переменная для БПЛА
TBpla Bpla;
//переменная для имени файла
TName NameFile;
//файловая переменная
TFile *f;
//флаг выбора файла для работы
int flag=0;

//** вывод меню ************************************************************
void menu(void)
{ system("cls");
  cout<<"******** М Е Н Ю ********\n\n"
      <<"[1]-Создание/открытие базы БПЛА\n"
      <<"[2]-Добавление БПЛА в базу\n"
      <<"[3]-Удаление БПЛА из базы\n"
      <<"[4]-Просмотр всей базы\n"
      <<"[5]-Обновление записи с заданным номером\n"
      <<"[6]-Выполнение задания. Поиск БПЛА по названию.\n"
      <<"[ ESC ]-Выход\n";
}
//** ввод БПЛА **************************************************
void InputBpla(TBpla &Bpla)
{
     cin.clear(); //очистить поток и затем выставить позиционирование в 0
while (!isspace(cin.get())) //Избавиться от результатов неверного ввода
      continue;
cout<<"Добавление БПЛА:\n";
cout<<"Наименование БПЛА ->"; //gets(Tovar.name);
cin.getline(Bpla.firm,25);

cout<<"\nдата изготовления:\n";
cout<<"День->";                cin>>Bpla.data.D;
cout<<"Месяц->";               cin>>Bpla.data.M;
cout<<"Год->";                 cin>>Bpla.data.G;

	cout << "Введите количество датчиков у БПЛА --> ";
	cin >> Bpla.sensors;
	cin.sync();
	cout << "Введите название камеры --> ";
	cin.getline(Bpla.namesensors.camera, 25);
	cout << "Введите название лидара --> ";
	cin.getline(Bpla.namesensors.lidar, 25);
	cout << "Введите название гироскопа --> ";
	cin.getline(Bpla.namesensors.gyroscope, 25);
	cout << "Введите название акселерометра --> ";
	cin.getline(Bpla.namesensors.accelerometer, 25);
	cout << "Введите название ультразвукового дальномера --> ";
	cin.getline(Bpla.namesensors.dalult, 25);
	cout << "Введите название лазерного дальномера --> ";
	cin.getline(Bpla.namesensors.dallaz, 25);
	cout << "Введите название gps --> ";
	cin.getline(Bpla.namesensors.gps, 25);
	////////////////////////////////////
	cout << "Введите массу БПЛА --> ";
	cin >> Bpla.mass;
cin.clear(); //очистить поток и затем выставить позиционирование в 0
while (!isspace(cin.get()))
      continue;            //Избавиться от результатов неверного ввода

cout<<"Производитель ->";     gets(Bpla.madein);

}
//** вывод товара на экран ************************************************
void OutputBpla(TBpla Bpla)
{
	cout << endl;
	cout << "Наименование БПЛА:" << endl;
	
cout 	<< "Фирма БПЛА --> " << Bpla.firm << endl
		<< "Количество датчиков у БПЛА --> " << Bpla.sensors << endl
		<< "Название камеры --> " << Bpla.namesensors.camera << endl
		<< "Название лидара --> " << Bpla.namesensors.lidar << endl
		<< "Название гироскопа --> " << Bpla.namesensors.gyroscope << endl
		<< "Название акселерометра --> " << Bpla.namesensors.accelerometer << endl
		<< "Название ультразвукового дальномера --> " << Bpla.namesensors.dalult << endl
		<< "Название лазерного дальномера --> " << Bpla.namesensors.dallaz << endl
		<< "Название gps --> " << Bpla.namesensors.gps << endl
		<< "Масса БПЛА --> " << Bpla.mass << " килограммов(ма,м)" << endl;
cout	<<"Дата изготовления товара: "
     	<<Bpla.data.D<<":"<<Bpla.data.M<<":"<<Bpla.data.G<<"\n"
     	<<"Производитель: "<<Bpla.madein<<"\n";
}
//** создание/открытие файла базы данных ********************************
void CreateOpenFile( TName &NameFile,int &flag )
{
 char ch;
 flag=0;
 cout<<"Введите имя файла для работы-->";
 //scanf("%s",&NameFile);
 gets(NameFile);
 f=fopen(NameFile,"r");
 if (f==NULL)
    do
     {
     system("cls");
     cout<<"ФАЙЛА с именем "
         <<NameFile
         <<" НЕТ.\n\n"
         <<"Создать файл с именем "
         <<NameFile;
     cout<<"Нажмите [ Y ] / [ N ]\n";
     ch=getch();
     if (ch=='Y'||ch=='y')
	{
	  f=fopen(NameFile,"w");
	  cout<<"Файл с именем " <<NameFile<<" создан.\n"
          <<"\n\nДля продолжения нажмите любую клавашу\n";
	  getch();
	  flag=1;
	}
     if (ch=='N'||ch=='n')
	{
	  cout<< "Файл не создан.\n"
	      <<"\n\nДля продолжения нажмите любую клавашу\n";
	  getch();
	}
     }
     while ( ! (ch =='Y' || ch=='y' || ch=='N'  || ch=='n'));
    else
	{flag=1;
	cout<<"Файл успешно открыт\n"
	    <<"\nДля продолжения нажмите любую клавашу\n";
	getch();
	}
fclose(f);
}

//** добавление записи (БПЛА) в файл (в базу данных) **********
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
      cout<<"\nВыберите файл для работы.\n"
          <<"Нажмите [ 1 ] в разделе М Е Н Ю.";
      getch();
    }
}
//** вывод файла (базы данных) на экран *****************
void VivodFile()
{

  int i=0;
  if (flag)
    {
  f=fopen(NameFile,"r+");

  cout<<"********  Вывод файла на экран  ********\n"
      <<"****************************************\n";
      while (fread(&Bpla,sizeof(Bpla),1,f)  )
	{
	 //printf("%d",ftell(f));
	 cout<<"Номер записи = "<<i+1<<"\n\n";
	 OutputBpla(Bpla);
	 cout<<"****************************************"<<sizeof(Bpla)<<"\n";
	 i++;
	 if (i % 3 == 0)  //вывод по несколько записей (товаров)
		{
		getch();
		system("cls");
		cout<<"********  Вывод файла на экран  ********\n"
		    <<"****************************************\n";
		}
	}
      getch();
      fclose(f);
    }
    else
    {
      cout<<"\nВыберите файл для работы.\n"
          <<"Нажмите [ 1 ] в разделе М Е Н Ю.";
      getch();
    }

}
//** размер файла *****************************
long filesize(TFile *f)
{
   long curpos, length;

   curpos = ftell(f);		//запоминаем текущее положение
   fseek(f, 0L, SEEK_END);	//перемещаем на конец файла
   length = ftell(f);		//запоминаем положение в конце файла
   fseek(f, curpos, SEEK_SET);	//перемещаем на старое положение
   return length;
}


//** обновление записи с заданным номером ******
void UpdateBpla(TName NameFile, TBpla &Bpla, int flag)
{
  long i=0;
  if (flag)
    {
	f=fopen(NameFile,"r+");

	cout<<"********  Обновление записи с заданным номером  ********\n\n"
	    <<"********************************************************\n\n"
	    <<"Введите номер записи для обновления "
	    <<"из "
	    <<(filesize(f)/sizeof(Bpla))
	    <<" --> ";
	cin>>i;
	//long q;
    fpos_t q;
	//перемещаемся на запись с номером i
	fseek(f, (i-1) * sizeof(Bpla) ,SEEK_CUR);
	//запоминаем текущее положение
	fgetpos(f,&q);

	fread(&Bpla,sizeof(Bpla),1,f);
	OutputBpla(Bpla);
	cout<<"****************************************\n";

	char ch;
	cout<<"Обновить данные?\nНажмите [ Y ] / [ N ]\n";
	do
	   {
	   //clrscr();
	   ch=getch();
	   if (ch=='Y'||ch=='y')
		{
		//вводим новые значения
		InputBpla(Bpla);
		//fseek(f, (i-1) * sizeof(Tovar) ,SEEK_CUR);
		//переходим на старое место
		fsetpos(f,&q);
		//записываем новые значения
		fwrite(&Bpla,sizeof(Bpla),1,f);
		cout<<"Данные обновлены.\n";
		}
	   if (ch=='N'||ch=='n')
		{
		cout<<"Данные не обновленны.\n";
		}
	   }
	while ( ! (ch =='Y' || ch=='y' || ch=='N'  || ch=='n'));
    cout<<"\nДля продолжения нажмите любую клавашу\n";
    getch();
    fclose(f);
    }
    else
    {
      cout<<"\nВыберите файл для работы.\n"
          <<"Нажмите [ 1 ] в разделе М Е Н Ю.";
      getch();
    }
}
//** удаление товара из базы **********************************
void DeleteBpla(TName NameFile, TBpla &Bpla, int flag)
{
  long i=0,k=0;
  TFile *g;
  if (flag)
    {
	f=fopen(NameFile,"r+");

	cout<<"********  Удаление записи с заданным номером  ********\n\n"
	    <<"********************************************************\n\n"
	    <<"Введите номер записи для удаления "
	    <<"из "
	    <<(filesize(f)/sizeof(Bpla))
	    <<" --> ";
	cin>>i;

	//перемещаемся на запись с номером i
	fseek(f, (i-1) * sizeof(Bpla) ,SEEK_CUR);
	fread(&Bpla,sizeof(Bpla),1,f);
	OutputBpla(Bpla);
	cout<<"****************************************\n";

	char ch;
	cout<<"Удалить данные?\nНажмите [ Y ] / [ N ]\n";
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
		cout<<"Данные обновлены.\n";
		fclose(g);
		fclose(f);
		remove(NameFile); 	//удаляем старый файл
		rename("Temp",NameFile);//переименовываем временный файл
		}
	   if (ch=='N'||ch=='n')
		{
		cout<<"Данные не обновленны.\n";
		}
	   }
	while ( ! (ch =='Y' || ch=='y' || ch=='N'  || ch=='n'));
    cout<<"\nДля продолжения нажмите любую клавашу\n";
    getch();
    //fclose(f);
    }
    else
    {
      cout<<"\nВыберите файл для работы.\n"
          <<"Нажмите [ 1 ] в разделе М Е Н Ю.";
      getch();
    }
}
//******************** моя функция *****************
void SearchBpla()
{
 int i=0;
  if (flag)
    {
  f=fopen(NameFile,"r");
  char search[15];
  cout<<"Введите имя товара для поиска --> ";
  cin.getline(search, 15);

  cout<<"********  Поиск товара в базе данных  ********\n"
      <<"****************************************\n";
  while (fread(&Bpla,sizeof(Bpla),1,f)  )
	{

	 
	 if ( strcmp(search, Bpla.firm) == 0 )
	 {
	 	cout<<"Номер записи = "<<i+1<<"\n\n";
	    OutputBpla(Bpla);
	    cout<<"****************************************"<<sizeof(Bpla)<<"\n";
	    i++;
	 	if (i % 3 == 0)  //вывод по несколько записей (товаров)
		{
			getch();
			system("cls");
			cout<<"********  Поиск товара в базе данных  ********\n"
		    	<<"****************************************\n";
		}
	 } 
	}
    
	getch();
    fclose(f);
    }
    else
    {
      cout<<"\nВыберите файл для работы.\n"
          <<"Нажмите [ 1 ] в разделе М Е Н Ю.";
      getch();
    }	
}



//Начало программы

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
		CreateOpenFile(NameFile,flag); //создание и открытие файла базы данных
		break;
    case '2':   system("cls");
		RecordBpla(NameFile,Bpla,flag); //запись данных в файл
		//getch();
		break;
    case '3':   system("cls"); // Удаление товара из базы данных
		cout<<"Удаление товара из базы данных\n";
		DeleteBpla(NameFile,Bpla,flag);
		getch();
		break;
    case '4':   system("cls");	// вывод файла на экран
		VivodFile();
		break;
    case '5':   system("cls");		//Обновление записи с заданным номером
		//printf("Обновление записи с заданным номером\n");
		UpdateBpla(NameFile,Bpla,flag);
		//getch();
		break;
    case '6':	
		system("cls");
		cout<<"Выполнение задания в соответствии с вариантом:\nПоиск необходимого товара в базе данных\n";
		SearchBpla();
		getch();
		
		break;
//    case '8':	exit(1);
   }
  }
  while	( ch!=27 ) ;
  return 0;
}
