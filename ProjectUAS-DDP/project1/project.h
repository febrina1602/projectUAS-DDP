#include "header.h"
// HALAMAN AWAL DAN LOADING
void halamanAwal(){
	createLineX(60, 112, 12  , 10, '-');
	createLineX(60, 112, 14  , 10, '-');
	createLineY(12, 14 , 59  , 10, '|' );
	createLineY(12, 14 , 113 , 10, '|' );
	createText(74, 13, "S E L A M A T  D A T A N G ");
	loading(78, 16);
}

// data base
void dataBase(){
	ofstream data;
	string id;
	linexy(85, 14);
	cin >> id;
	string pin;
	linexy(80, 17);
	cin >> pin;
	data.open("userAkun.txt", ios::app);
	data << id;
	data << pin <<endl;
	data.close();
	system("cls");
	
}

// login berhasil
void transisi(){
	system("cls");
	system("color A");
	createLineX(60, 112, 12  , 10, '-');
	createLineX(60, 112, 14  , 10, '-');
	createLineY(12, 14 , 59  , 10, '|' );
	createLineY(12, 14 , 113 , 10, '|' );
	createText(74, 13, "L O G I N  B E R H A S I L ");
	loading(78, 16);
}


// pilihan buat akun
void createAkun(){
	system("color 3e");
	system("cls");
	createLineY(12, 21 , 59  , 1);
	createLineY(12, 21 , 113 , 1);
	createLineX(60, 112, 21, 1);
	createLineX(60, 112, 12, 1);
	createText(62, 14, "MASUKAN USERNAME ANDA : ");
	createText(62, 15, "FORMAT user_name ");
	createText(62, 17, "MASUKAN PIN ANDA : ");
	createText(62, 18, "FORMAT PIN BERUPA ANGKA");
	dataBase();

}
// pilihan dari login
void login(){
	string output;
	system("cls");
	system("color 3e");
	createLineY(12, 21 , 59  , 1);
	createLineY(12, 21 , 113 , 1);
	createLineX(60, 112, 21, 1);
	createLineX(60, 112, 12, 1);
	createText(62, 15, "Masukan id user :");
	createText(62, 18, "Masukan pw user :");
	linexy(80, 15);
	string id;cin>>id;
	linexy(80, 18);
	string pw;cin>>pw;

	ifstream cekData;
	cekData.open("userAkun.txt");

    while(true){
        cekData >> output;
        if(output == id+pw){
			transisi();
            break;
        }
		if(cekData.eof()){
			createText(60, 10, "LOGIN GAGAL COBA LAGI!");
			delay(10000);
			system("cls");
			login();
			break;
		}
    }
	cekData.close();
	
}

//tampilan awal login
void opsiLogin(){
	createLineY(12, 21 , 59  , 1);
	createLineY(12, 21 , 113 , 1);
	createLineX(60, 112, 21, 1);
	createLineX(60, 112, 12, 1);
	createText(77,14, "P I L I H  O P S I");
	createText(62,16, "1. Login");
	createText(62,17, "2. Buat Akun");
	createText(62,18, "3. Keluar");

	// pilihan login
	createText(62, 20, "Jawaban anda : ");
	int jawab; cin >> jawab;
	switch(jawab){
		case 1 :
		login();
		break;

		case 2 :
		createAkun();
		login();
		break;

		default :
		system("cls"); 
		return;

	}

}



