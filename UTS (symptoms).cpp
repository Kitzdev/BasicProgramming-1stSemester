#include<iostream>
#include<iomanip>
#include<string>
#include<ctype.h>
using namespace std;

//Untuk menampilkan header dari tabel hasil akhir dan untuk memudahkan debugging
void header_tabel()
{
    cout << setw(3) << "No " << setw(7) << "Nama" << setw(10) << "Umur" << setw(15) <<"Hasil";
    cout << "\n----------------------------------------------\n";
}

//Untuk menampilkan body dari tabel hasil akhir dan untuk memudahkan debugging
void body_tabel(int jumlah, string nama[], string umur[], string hasil[])
{
    for(int i = 0; i < jumlah; i++)
    {
    cout << setw(2) << i + 1 << setw(8) << nama[i] << setw(9) << umur[i] << setw(20) << hasil[i] << "\n";
    }
}

//Fungsi untuk memeriksa apakah input huruf dari user sudah tepat atau belum
bool cek_huruf(string namacek)   
{
    bool value;
    for(int i = 0; namacek[i] != '\0'; i++)
    {
       if(namacek[i] == '0' || namacek[i] == '1' || namacek[i] == '2' || namacek[i] == '3' || namacek[i] == '4' || namacek[i] == '5' || namacek[i] == '6' ||  namacek[i] == '7' || namacek[i] == '8' || namacek[i] == '9')
       {
           value = true;
       } 
    } 
    return value;
}
    
//Fungsi untuk memeriksa apakah input huruf dari user sudah tepat atau belum
bool cek_angka(string angkacek)
{
    bool value;
    for(int i = 0; angkacek[i] != '\0'; i++)
    {   
        if(angkacek[i] == '0' || angkacek[i] == '1' || angkacek[i] == '2' || angkacek[i] == '3' || angkacek[i] == '4' || angkacek[i] == '5' || angkacek[i] == '6' ||  angkacek[i] == '7' || angkacek[i] == '8' || angkacek[i] == '9')
        {
           value = false;

        } else
        {
           value = true;
        }
    } 
    return value;
}

int main()
{
    int jumlah;
    
    //Deklarasi array untuk menyimpan penyakit dan jawaban dari user
    string sakit[11] = {"batuk kering", "batuk lendir", "bersin", "pilek", "sakit tubuh", "kelemahan otot", "demam ringan", "demam tinggi", "nyeri tubuh", "kesulitan bernapas", "hilang indra pengecap dan perasa"};
    char symptoms[11];
    
    cout << "Selamat datang di program analisis gejala COVID-19 !!\n\n";
    cout << "Berapa jumlah pasien yang ingin diperiksa? : ";
    cin >> jumlah;
    
    string umur[jumlah];                     // Deklarasi variabel untuk menyimpan data
    string nik;                              //
    string nama[jumlah], alamat;             // 
    string notelp;                           //
    string hasil[jumlah];                    //
    string ceknama, cekumur;                 //

        cout << "=============================================\n\n";

    for(int i = 0; i < jumlah; i++)
    {
        for(int j = 0; j < 1; j++)
        {
            cout << "Masukkan data pasien ke-" << i + 1 << " :\n";
            cin.ignore();

            //Menyimpan data pasien
            do  
            {
                cout << "Nama : "; getline(cin, nama[i]); 
                ceknama = nama[i];
                if(cek_huruf(ceknama))
                {
                    cout << "Nama yang dimasukkan hanya boleh berisi huruf!\n";
                }

            } while (cek_huruf(ceknama));

            do
            {
                cout << "Umur : "; cin >> umur[i];
                cekumur = umur[i];
                if(cek_angka(cekumur))
                {
                    cout << "Umur yang dimasukkan hanya boleh berisi angka!\n";
                }
            } while (cek_angka(cekumur));
            
            do
            {
                cout << "NIK  : "; cin.ignore(); getline(cin, nik);
                if(cek_angka(nik) || nik.size() > 16) 
                {
                    cout << "NIK yang dimasukkan hanya boleh berisi 16 digit angka!\n";
                }
            } while (cek_angka(nik));
            
            cout << "Alamat  : "; cin.ignore(); getline(cin, alamat);   

            do
            {
                cout << "Nomor Telepon : "; cin >> notelp;
                if(cek_angka(notelp))
                {
                    cout << "Nomor Telepon yang dimasukkan hanya boleh berisi angka!\n";
                } 
            } while (cek_angka(notelp));
                  
            cout << "\n";
        }

        //Menanyakan kondisi pasien
        cout << "Silahkan isi dengan Y/y untuk ya dan T/t untuk tidak!\n";

        for(int k = 0; k < 11; k++)
        {
          cout << "Apakah " << nama[i] << " " << sakit[k] << " ? : "; 
          cin >> symptoms[k]; 
          symptoms[k] = toupper(symptoms[k]);
        }
        
        if(symptoms[0] == 'Y' && symptoms[2] == 'Y')
        {
            if(symptoms[8] == 'Y' && symptoms[5] == 'Y' && symptoms[7] == 'Y' && symptoms[9] == 'Y' && symptoms
               [10] == 'Y')
            {
                hasil[i] = "Covid-19";

            } else
            {
                hasil[i] = "Polusi Udara";

            }
        } else if(symptoms[1] == 'Y' && symptoms[2] == 'Y' && symptoms[3] == 'Y')
        {
            if(symptoms[4] == 'Y' && symptoms[5] == 'Y' && symptoms[6] == 'Y' )
            {
                hasil[i] = "Sakit Flu";

            } else 
            {
                hasil[i] = "Pilek Biasa";
            }
        } else
        {
            hasil[i] = "Sakit Biasa";
        }
        
        cout << "Hasil analisis menunjukan " << nama[i] << " terkena penyakit " << hasil[i] << ".\n\n";
    }

    cout << "=============================================================\n\n";

    cout << "Hasil analisis seluruh pasien dari gejala yang dialami oleh pasien\n\n";

    header_tabel(); //Memanggil header tabel
    body_tabel(jumlah, nama, umur, hasil);  //Memanggil body tabel
                                            //Menampilkan umur untuk antisipasi ada yang namanya sama

    cin.get();
}
