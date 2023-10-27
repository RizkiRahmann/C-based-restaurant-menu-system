#include <iostream>
#include <stdlib.h>
#define max 10
using namespace std;

//STRUCT STACK 
struct Tumpukan
{
	int atas;
	int data[max];
}T;

//STRUCT LINGKED LIST
struct Node
{
	int data;
	Node *next;
};

//BAGIAN LINGKED LIST
Node *headNode = NULL;
Node *currentNode = NULL;
bool isEmpty();
void insertNode(int data);
void deleteFromFront();
void deleteFromEnd();
void deleteAll();
void printNode();

//BAGIAN STACK
void awal();
int kosong();
int penuh();
void input(int data);
void hapus();
void tampil();
void bersih();

//BAGIAN SORT & SEARCH serta POINTER
void urut_murah();
void urut_mahal();

//--------------------------------MAIN MENU------------------------------------
int main()
{
	string username, nim, jwb;
	int pilihan, harga, uang, kembalian, n, data, pilih, pilihanMenu;
	int resto[9]={25000,20000,40000,5000,10000,8000,20000,15000,15000};
	harga = 0;
	T.atas=-1;
	
	cout<<"			NIM 		: "; cin>>nim;
	cout<<"			Username	: "; 
		cin.ignore();
		getline (cin,username) ;
		system("cls");
	
	menu:
	cout<<"MENU UTAMA : "<<endl;
	cout<<"1. CEK DAFTAR MENU DAN HARGA"<<endl;
	cout<<"2. BUAT PESANAN"<<endl;
	cout<<"3. TOTAL PESANAN"<<endl;
	cout<<"4. HAPUS PESANAN"<<endl;
	cout<<"5. BOOKING TEMPAT"<<endl;
	cout<<"6. EXIT"<<endl;
	cout<<"Masukan pilihan anda : "; cin>>pilihan;
	system("cls");
	
	switch(pilihan)
	{
		//PILIHAN 1
		case 1:
		cout<<"    DAFTAR MENU DAN HARGA "<<endl;
		cout<<"==========================="<<endl;
		cout<<"==========================="<<endl;
		cout<<"| NO |	|      MENU      |"<<endl;
		cout<<"==========================="<<endl;
		cout<<"| 1  |	|     MAKANAN    |"<<endl;
		cout<<"| 2  |	|     MINUMAN    |"<<endl;
		cout<<"| 3  |	| MAKANAN PENUTUP|"<<endl;
		cout<<"==========================="<<endl;
		cout<<endl;
				cout<<"============================================"<<endl;
				cout<<"Ini pilihan menu nya "<<username<<endl;
				cout<<"============================================"<<endl;
				cout<<"| NO |	|     MENU    |	|      HARGA      |"<<endl;
				cout<<"============================================"<<endl;
		        cout<<"| 1  |	|   Nasi ayam |	|      25.000     |"<<endl;
		        cout<<"| 2  |	|   Nasi ikan |	|      20.000     |"<<endl;
		        cout<<"| 3  |	| Nasi seafood|	|      40.000     |"<<endl;
				cout<<"============================================"<<endl;
		        cout<<endl;
				cout<<"============================================"<<endl;
				cout<<"| NO |	|     MENU    |	|      HARGA      |"<<endl;
				cout<<"============================================"<<endl;
			    cout<<"| 4  |	|    Es teh   |	|      5.000      |"<<endl;
			    cout<<"| 5  |	|  Jus mangga |	|      10.000     |"<<endl;
			    cout<<"| 6  |	|   Es jeruk  |	|      8.000      |"<<endl;
				cout<<"============================================"<<endl;
			    cout<<endl;
				cout<<"============================================"<<endl;
				cout<<"| NO |	|     MENU    |	|      HARGA      |"<<endl;
				cout<<"============================================"<<endl;
			    cout<<"| 7  |	|  Roti bakar |	|      20.000     |"<<endl;
			    cout<<"| 8  |	|Buah semangka|	|      15.000     |"<<endl;
			    cout<<"| 9  |	|    Es krim  |	|      15.000     |"<<endl;
				cout<<"============================================"<<endl;
			    cout<<endl;
				urut_murah();
				cout<<endl;
				urut_mahal();
				cout<<endl;
				
			cin.ignore();	
			cout<<"KLIK ENTER UNTUK KEMBALI";
			cin.get();
			system("cls");
			goto menu;
		
		//MENU 2
		case 2:
				cout<<"==============================================================="<<endl;
				cout<<"Ini pilihan menu nya "<<username<<" silahkan membuat pesanan :)"<<endl;
				cout<<"==============================================================="<<endl;
				cout<<"| NO |	|     MENU    |	|      HARGA      |"<<endl;
				cout<<"==============================================================="<<endl;
				cout<<"| 1  |	|   Nasi ayam |	|      25.000     |"<<endl;
		        cout<<"| 2  |	|   Nasi ikan |	|      20.000     |"<<endl;
		        cout<<"| 3  |	| Nasi seafood|	|      40.000     |"<<endl;
				cout<<"==============================================================="<<endl;
		        cout<<endl;
				cout<<"==============================================================="<<endl;
				cout<<"| NO |	|     MENU    |	|      HARGA      |"<<endl;
				cout<<"==============================================================="<<endl;
			    cout<<"| 4  |	|    Es teh   |	|      5.000      |"<<endl;
			    cout<<"| 5  |	|  Jus mangga |	|      10.000     |"<<endl;
			    cout<<"| 6  |	|   Es jeruk  |	|      8.000      |"<<endl;
				cout<<"==============================================================="<<endl;
			    cout<<endl;
				cout<<"==============================================================="<<endl;
				cout<<"| NO |	|     MENU    |	|      HARGA      |"<<endl;
				cout<<"==============================================================="<<endl;
				cout<<"| 7  |	|  Roti bakar |	|      20.000     |"<<endl;
			    cout<<"| 8  |	|Buah semangka|	|      15.000     |"<<endl;
			    cout<<"| 9  |	|    Es krim  |	|      15.000     |"<<endl;
				cout<<"==============================================================="<<endl;
			    cout<<endl;
				
			menu2:
			cout<<"==============================================================="<<endl;
				cout<<"MAU PESAN BERAPA BANYAK ?";cin>>n;
			cout<<"==============================================================="<<endl;	
				for(int i=0;i<n;i++)
				{
					cout<<"MAU PESAN NOMOR BERAPA ?";cin>>data;
					input(data);
					cout<<"\n===============================================================\n"<<endl;	
				}
			cout<<endl;
			cout<<"MAU PESAN LAGI ?(Y/T) ";cin>>jwb;
				if((jwb == "y") || (jwb == "Y"))
				{
					cin.ignore();	
					goto menu2;
				}else
				{
					cin.ignore();	
					cout<<"KLIK ENTER UNTUK KEMABLI KE MENU DAN LANJUT PEMBAYARAN ^_^";
					cin.get();
					system("cls");
					goto menu3;
				}
		
		//MENU 3
		case 3:
		menu3:
		if (T.atas>=0)
		{
			cout<<"============================================================"<<endl;
			cout<<"TOTAL PESANAN KAK "<<username<<" DENGAN NIM "<<nim<<" (^-^)"<<endl;
			cout<<"============================================================"<<endl;
			tampil();
			cout<<endl;
			for(int i=T.atas; i>=0; i--)
			{
				harga += resto[T.data[i]-1];  
			}
			cout<<"\nTOTAL PESANAN : "<<harga<<endl<<endl;
			//MENU BAYAR
			bayar:
			cout<<"---------------------------------------------"<<endl;
			cout<<"UANG YANG AKAN KAKAK BAYARKAN : ";cin>>uang;
			cout<<"---------------------------------------------"<<endl;
			if(uang>=harga)
			{
				kembalian = uang - harga;
				cout<<"\n||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl;
				cout<<"| KEMBALIAN KAK "<<username<<" SEBESAR "<<kembalian<<endl;
				cout<<"| TERIMA KASIH SUDAH MEMESAN KAK "<<username<<" (^_^) (^_^) (^_^)"<<endl;
				cout<<"||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl;
				cout<<"\n---KLIK ENTER---"<<endl;
			}else
			{
				cout<<"\nYAH UANG NYA KURANG KAK :("<<endl;
				cout<<"MAU UBAH PEMBAYARAN ? (Y/T) ";cin>>jwb;
				if((jwb == "y") || (jwb == "Y"))
				{
					cin.ignore();	
					goto bayar;
				}else
				{
					cin.ignore();
					cout<<"\nKLIK ENTER UNTUK KEMBALI KAK "<<username<<" ^_^ ^_^"<<endl;
					cin.get();
					system("cls");
					goto menu;
				}
			}
		}else
		{
			cout<<"MAAF YAH KAK, KAKAK TUH BELUM PESAN APAPUN :("<<endl;			
			cout<<"PESAN DULU YAH KAK DIJAMIN MENU NYA ENAK KOK (^_^)\n\n";
			cout<<"============================================================"<<endl;
			cout<<"KLIK ENTER UNTUK KEMABLI KE MENU YAH KAK, TERIMA KASIH ^_^\n";
			cout<<"============================================================"<<endl;
		}
			bersih();
			cin.ignore();
			cin.get();
			system("cls");
			goto menu;
			
		//PILIHAN 4
		case 4:
		if (T.atas>=0)
		{
			cout<<"====================================================================="<<endl;
			cout<<"PENGHAPUSAN BERHASIL DILAKUKAN"<<endl;
			cout<<"====================================================================="<<endl;
				hapus();
				cout<<"\nKLIK ENTER UNTUK KEMABLI KAK "<<username<<" ^_^ ^_^"<<endl;
				cin.ignore();
				cin.get();
				system("cls");
				goto menu;
		}else
		{
			cout<<"MAAF YAH KAK, KAKAK TUH BELUM PESAN APAPUN :("<<endl;			
			cout<<"PESAN DULU YAH KAK DIJAMIN MENU NYA ENAK KOK (^_^)\n\n";
			cout<<"============================================================"<<endl;
			cout<<"KLIK ENTER UNTUK KEMABLI KE MENU YAH KAK, TERIMA KASIH ^_^\n";
			cout<<"============================================================"<<endl;
		}
			cin.ignore();
			cin.get();
			system("cls");
			goto menu;
			
		//MENU 5	
		case 5: 
			do
			{
			menu5:
			cout << ">>> SILAHKAN PILIH KAK "<<username<<" MENU UNTUK AMBIL NOMOR KURSI <<<"<<endl<<endl;
			cout << "1. Ambil Tempat"<<endl;
			cout << "2. Menghapus Tempat Pertama" << endl;
			cout << "3. Menghapus Tempat Terakhir" << endl;
			cout << "4. Mengosongkan Tempat" << endl;
			cout << "5. Menampilkan Nomor kursi yang sudah dipesan" << endl;
			cout << "6. Selesai" << endl;
			cout << "Masukkan pilihan anda : ";cin>>pilihanMenu;
			cout<<endl;
			
				switch (pilihanMenu)
				{
					case 1:
						cout << "MASUKKAN BANYAK ORANG : ";cin >> data;
						insertNode(data);
						cin.ignore();
						cout<<"---KLIK ENTER---"<<endl;
						cin.get();
						system("cls");
						goto menu5;
						break;
						
					case 2:
						if(isEmpty())
						{
							cout << "Belum ambil tempat, ambil dulu :):):) " <<endl<<endl;
							cin.ignore();
							cout<<"---KLIK ENTER---"<<endl;
							cin.get();
							system("cls");
							goto menu5;
						}
						else 
						{
							deleteFromFront();
							cin.ignore();
							cout<<"---KLIK ENTER---"<<endl;
							cin.get();
							system("cls");
							goto menu5;
						}
						break;
						
					case 3:
						if(isEmpty())
						{
							cout << "Belum ambil tempat, ambil dulu :):):) " <<endl<<endl;
							cin.ignore();
							cout<<"---KLIK ENTER---"<<endl;
							cin.get();
							system("cls");
							goto menu5;
						}
						else 
						{
							deleteFromEnd();
							cin.ignore();
							cout<<"---KLIK ENTER---"<<endl;
							cin.get();
							system("cls");
							goto menu5;
						}
						break;
					
					case 4:
						if(isEmpty())
						{
							cout << "Belum ambil tempat, ambil dulu :):):) " <<endl<<endl;
							cin.ignore();
							cout<<"---KLIK ENTER---"<<endl;
							cin.get();
							system("cls");
							goto menu5;
						}
						else 
						{
							deleteAll();
							cin.ignore();
							cout<<"---KLIK ENTER---"<<endl;
							cin.get();
							system("cls");
							goto menu5;
						}
						break;
						
					case 5:
						if(isEmpty())
						{
							cout << "Belum ambil tempat, ambil dulu :):):) " <<endl<<endl;
							cin.ignore();
							cout<<"---KLIK ENTER---"<<endl;
							cin.get();
							system("cls");
							goto menu5;
						}
						else 
						{
							printNode();
							cin.ignore();
							cout<<"---KLIK ENTER---"<<endl;
							cin.get();
							system("cls");
							goto menu5;
						}
						break;
						
					case 6:
						break;
						
					default:
						cout << "Menu yang Anda pilih tidak terdaftar"<<endl<<endl;
						cin.ignore();
						cout<<"---KLIK ENTER---"<<endl;
						cin.get();
						system("cls");
						goto menu5;
						break;
				}
			} while (pilihanMenu != 6);
			cout << endl;
			system("pause");
			cin.ignore();
			cout<<"KLIK ENTER UNTUK KEMBALI KE MENU KAK ^-^"<<endl;
			cin.get();
			system("cls");
			goto menu;
					
		//MENU 5	
		case 6: 
		//EXIT
			cin.ignore();
			break;
		
		//Pilihan tidak ada atau salah input//
		default :
		cin.ignore();
		cout<<"Pilihan Tidak Ada Coba Yang Lain Kak ^-^"<<endl;
		cin.get();
		system("cls");
		goto menu;
	}
}

//----------------------------------------------SELURUH VOID YANG ADA--------------------------------------------------------------------

//STACK
void awal()
{
	T.atas=-1;
}

int kosong()
{
	if(T.atas==-1)
		return 1;
	else 
		return 0;
}

int penuh()
{
	if (T.atas==max-1)
		return 1;
	else
		return 0;
}

void input(int data)
{
	if(kosong()==1)
	{
		T.atas++;
		T.data[T.atas]=data;
		cout<<"Menu "<<T.data[T.atas]<<" masuk ke Pesanan ^_^";
	}
	else if(penuh()==0)
	{
		T.atas++;
		T.data[T.atas]=data;
		cout<<"Menu "<<T.data[T.atas]<<" masuk ke Pesanan ^_^";
	}
	else
		cout<<"Yah pesanannya penuh maaf yah kak :(";
}

void hapus()
{
	if (kosong()==0)
	{
		cout << "PESANAN KAKAK BERHASIL DIHAPUS ^-^" <<endl<<endl;
		T.atas--;
	}
	else	
		cout<<"Pesanan kosong silahkan pesan dulu :)";
}

void tampil()
{
	if(kosong()==0)
	{
		for(int i=T.atas;i>=0;i--)
		{
			cout<<"\nPesanan ke "<<i+1<<" = "<<T.data[i];
		}
	}
	else
		cout<<"Pesanan kosong silahkan pesan dulu :)";
}

void bersih()
{
	T.atas=-1;
}

//------SORT DAN SEARCH---------
void urut_murah()
{
	int resto[9]={25000,20000,40000,5000,10000,8000,20000,15000,15000};
	int *urut,i,j,temp;
	int cari, ditemukan=0, hasilcari[10];
	string jwb;
	urut = resto;
				//INSERT SORT MURAH
				for(i=0 ; i<9 ; i++)
				{
					temp = resto[i];
					j = i-1;
					
					while(resto[j]>temp && j>=0){
					resto[j+1] = resto[j];
					j--;
					}
					resto[j+1] = temp;
				}
				//SETELAH DI URUT MURAH
				cout<<"PENGURUTAN TERMURAH : \n";
				for(i=0;i<9;i++){
					cout<<"["<<i+1<<"] "<<*(urut+i)<<"\n";
				}
				cout<<endl;
		
		//BINARY SEARCH MURAH
		cout<<"MAU CEK HARGA DI TERMURAH KAK :) ? (Y/T) ";cin>>jwb;
		search1:
		if((jwb == "y") || (jwb == "Y"))
		{
			cout<<endl;
			cout<<"MASUKKAN HARGA : ";
			cin>>cari;
			for (int i=0; i<9; i++){
				if (resto[i] == cari){
					ditemukan++;
					hasilcari[ditemukan]=i;
				}
			}
			if(ditemukan==0){
				cout<<"HARGA TIDAK ADA KAK :(";
				cout<<endl;
			} else {
				for (int i=1; i<=ditemukan; i++){
					cout<<"HARGA PADA PERINGKAT "<<hasilcari[i]+1;
					cout<<endl;
				}
			}
			cout<<endl;
			cout<<"*********************"<<endl;
			cout<<"MAU CEK LAGI ? (Y/T) ";cin>>jwb;
			cout<<"*********************"<<endl;
			if((jwb == "y") || (jwb == "Y"))
			{
				cin.ignore();
				ditemukan=0;
				goto search1;
			}	
		}
}

//------SORT DAN SEARCH---------
void urut_mahal()
{
	int resto[9]={25000,20000,40000,5000,10000,8000,20000,15000,15000};
	int *urut,i,j,temp;
	int cari, ditemukan=0, hasilcari[10];
	string jwb;
	urut = resto;

				//INSERT SORT MAHAL
				for(i=0 ; i<9 ; i++)
				{
					temp = resto[i];
					j = i-1;
					
					while(resto[j]<temp && j>=0){
					resto[j+1] = resto[j];
					j--;
					}
					resto[j+1] = temp;
				}
				//SETELAH DI URUT MAHAL
				cout<<"PENGURUTAN TERMAHAL : \n";
				for(i=0;i<9;i++){
					cout<<"["<<i+1<<"] "<<*(urut+i)<<"\n";
				}
				cout<<endl;	
				
		//BINARY SEARCH MAHAL
		cout<<"MAU CEK HARGA DI TERMAHAL KAK :) ? (Y/T) ";cin>>jwb;
		search2:
		if((jwb == "y") || (jwb == "Y"))
		{
			cout<<endl;
			cout<<"MASUKKAN HARGA : ";
			cin>>cari;
			for (int i=0; i<9; i++){
				if (resto[i] == cari){
					ditemukan++;
					hasilcari[ditemukan]=i;
				}
			}
			if(ditemukan==0){
				cout<<"HARGA TIDAK ADA KAK :(";
				cout<<endl;
			} else {
				for (int i=1; i<=ditemukan; i++){
					cout<<"HARGA PADA PERINGKAT "<<hasilcari[i]+1;
					cout<<endl;
				}
			}
			cout<<endl;
			cout<<"*********************"<<endl;
			cout<<"MAU CEK LAGI ? (Y/T) ";cin>>jwb;
			cout<<"*********************"<<endl;
			if((jwb == "y") || (jwb == "Y"))
			{
				cin.ignore();
				ditemukan=0;
				goto search2;
			}	
		}
}

//----------------------------LINGKED LIST----------------------------------
bool isEmpty()
{
	return (headNode == NULL);
}

void insertNode(int data)
{
	Node *newNode = NULL;
	newNode = new Node;
	newNode->data = data;
	if(isEmpty())
	{
		headNode = newNode;
	}
	else
	{
		currentNode->next = newNode;
	}
	currentNode = newNode;
	currentNode->next = NULL;
	cout << "NOMOR KURSI BERHASIL DIAMBIL" << endl << endl;
}

void deleteFromFront()
{
	if (!isEmpty())
	{
		Node *hapusNode = headNode;
		headNode = headNode->next;
		delete hapusNode;
		cout << "TEMPAT PERTAMA BERHASIL DIHAPUS" << endl <<endl;
	}
}

void deleteFromEnd()
{
	if (headNode == currentNode)
	{
		headNode = NULL;
		currentNode = NULL;
		return;
	}
	Node *bantu = headNode;
	Node *hapusNode = currentNode;
	while (bantu->next != currentNode)
	{
		bantu = bantu->next;
	}
	currentNode = bantu;
	currentNode->next = NULL;
	delete hapusNode;
	cout << "TEMPAT TERAKHIR BERHASIL DIHAPUS" <<endl<<endl;
}

void deleteAll()
{
	Node *bantu, *hapusNode;
	bantu = headNode;
	while (bantu->next != currentNode)
	{
		hapusNode = bantu;
		bantu = bantu->next;
		delete hapusNode;
	}
	headNode = NULL;
	currentNode = NULL;
	cout << "SELURUH TEMPAT BERHASIL DIHAPUS" <<endl<<endl;
}

void printNode()
{
	Node *awalNode = headNode;
	int i = 1;
	while (awalNode != NULL)
	{
		cout << "DATA NOMOR KURSI #" <<i<<" - "<<awalNode->data<<" ORANG"<<endl;
		awalNode = awalNode->next;
		i++;
	}
	cout << endl;
}