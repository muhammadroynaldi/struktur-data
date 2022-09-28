#include<iostream>
#include<conio.h>
#include<windows.h>
#define MAX 5

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}


using namespace std;
struct paket
{
    char jenis_brg[30];
    int berat;
    char kota[30];
};

struct paket kirim[100];

/*******************************************/
void bersihlayar()
{
    for(int a=0;a<80;a++)
    {
        for(int b=0;b<=24;b++)
        {
            gotoxy(a,b);cout<<" ";
        }
    }
}

void pushdata(int x)
{
    gotoxy(20,15);cout<<"Inputkan Jenis Barang    :";
    cin>>kirim[x].jenis_brg;
    gotoxy(20,16);cout<<"Inputkan Berat           :";
    cin>>kirim[x].berat;
    gotoxy(20,17);cout<<"Inputkan Kota Tujuan     :";
    cin>>kirim[x].kota;
}

void printdata(int x)
{
    gotoxy(40,10);cout<<"Daftar Kiriman Paket"<<endl;
    for(int a=1; a<x; a++)
    {
        gotoxy(40,19-a);
        cout<<a<<" ";
        cout<<kirim[a].jenis_brg<<" ";
        cout<<kirim[a].berat<<" ";
        cout<<kirim[a].kota<<endl;
    }
    gotoxy(40,20);
    cout<<"Press Any Key...";
    getch();
    /*harus Ijin --> #include<conio.h>*/
}

void popdata(int x)
{
    gotoxy(40,12);cout<<"Data Terakhir yang anda Hapus Adalah :"<<endl;
    gotoxy(40,13);cout<<kirim[x].jenis_brg<<" ";
    cout<<kirim[x].berat<<" Kg ";
    cout<<kirim[x].kota<<endl<<endl;

    gotoxy(40,15);cout<<"Press Any Key...";
    getch();


}

int main()
{
    int pilih;
    int top = 1;
    do
    {
        bersihlayar();
        gotoxy(1,1);cout<<"MENU UTAMA";
        gotoxy(1,2);cout<<"1. PUSH DATA";
        gotoxy(1,3);cout<<"2. POP DATA Terakhir"<<endl;
        gotoxy(1,4);cout<<"3. PRINT DATA"<<endl;
        gotoxy(1,5);cout<<"4. KELUAR"<<endl;

        gotoxy(1,7);cout<<"Pilihan Anda [1-4] : ";
        cin>>pilih;
        switch(pilih){
            case 1 :
                if(top > MAX){
                        gotoxy(40,12);cout << "Sorry Stack is full" << endl;
                        gotoxy(40,15);cout<<"Press Any Key...";
                        getch();
                    }
                else {
                    /*Menambah data baru diletakan di top*/
                        pushdata(top);
                        top++;
                }
                break;
            case 2 :
                if(top == 1){
                        gotoxy(40,12);cout << "Sorry Stack is empty" << endl;
                        gotoxy(40,15);cout<<"Press Any Key...";
                        getch();
                    }
                else { /*Menghapus Data Terakhir (top-1*/
                    popdata(top-1);
                    top--;
                }
                break;
            case 3 :

                if(top == 1) {
                        cout << "Sorry stack is empty" << endl;
                        gotoxy(40,15);cout<<"Press Any Key...";
                        getch();
                }
                else {
                    /*Menampilkan Data mulai
                                data ke-1 hingga top*/
                    printdata(top);
                }
                break;
            case 4 :
                cout << "Keluar......" << endl;
                break;
            default :
                cout << "tidak ada pilihan yan tersedia " << endl;
        }
    }
    while(pilih!=4);
    return 0;
}
