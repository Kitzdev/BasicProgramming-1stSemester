#include <iostream>
#include <fstream>
#include <sstream>
#include <ctype.h>
#include <iomanip>
using namespace std;

struct dbarang  //Tipe data bentukan untuk barang yang dijual
{
    string nbarang; //nama barang
    int hbarang;    //harga barang
};

struct dstruk   //Tipe data bentukan untuk struk pembeli
{
        string nnota;           //nomor nota
        int stotal = 0;         //subtotal
        int diskon;             //diskon
        int pajak;              //pajak
        int gtotal;             //grand total
        int bayar;              //uang yang dibayar
        int kembalian;          //uang kembalian
};

//Prosedur untuk display harga dalam bentuk Rpxxx.xxx.xxx.xxx
//dharga(integer)
void dharga(int harga)
{
    string display = "Rp";
    string container = to_string(harga);
    int count = 0, limit = 3;

    //Untuk menghitung panjang string karena syntax strlen hanya bisa menghitung char
    for(int i = 0; container[i] != '\0'; i++)
    {
        count++;
    }

    int remain = count % 3;

    if(remain == 1)
    {
        display += container[0];
  
        for(int i = 1; i < count; i++)
        {
            if(limit == 3)
            {
                display += ".";
                limit = 0;
            }

            display += container[i];
            limit++;
        }

    } else if(remain == 2)
    {
        display += container[0];
        display += container[1];

        for(int i = 2; i < count; i++)
        {
            if(limit == 3)
            {
                display += ".";
                limit = 0;
            }

            display += container[i];
            limit++;
        }

    } else
    {
        display += container[0];
        display += container[1];
        display += container[2];

        for(int i = 3; i < count; i++)
        {
            if(limit == 3)
            {
                display += ".";
                limit = 0;
            }

            display += container[i];
            limit++;
        }
    }
    cout << display;
}

//Function untuk mengolah string harga dalam bentuk Rpxxx.xxx.xxx.xxx
//dhargaf(integer)
string dhargaf(int harga)
{   
    string display = "Rp";
    string container = to_string(harga);
    int count = 0, limit = 3;

    //Untuk menghitung panjang string karena syntax strlen hanya bisa menghitung char
    for(int i = 0; container[i] != '\0'; i++)
    {
        count++;
    }

    int remain = count % 3;

    if(remain == 1)
    {
        display += container[0];
  
        for(int i = 1; i < count; i++)
        {
            if(limit == 3)
            {
                display += ".";
                limit = 0;
            }

            display += container[i];
            limit++;
        }

    } else if(remain == 2)
    {
        display += container[0];
        display += container[1];

        for(int i = 2; i < count; i++)
        {
            if(limit == 3)
            {
                display += ".";
                limit = 0;
            }

            display += container[i];
            limit++;
        }

    } else
    {
        display += container[0];
        display += container[1];
        display += container[2];

        for(int i = 3; i < count; i++)
        {
            if(limit == 3)
            {
                display += ".";
                limit = 0;
            }

            display += container[i];
            limit++;
        }
    }
    return display;
}

//Prosedur untuk menampilkan output berupa karakter pertama uppercase dan tidak mengubah isi dalam array
//dharga(string)
void dnama (string nama)
{
    cout << (char)toupper(nama[0]);

    for(int i = 1; nama[i] != '\0'; i++)
    {
        cout << (char)tolower(nama[i]);
    }
}

//Karena strcmp hanya bisa compare char jadinya saya buat compare untuk string
//int scomp(string1, string2) 1 <-- string1 > string2 || 0 <-- string1 == string2 || -1 <-- string1 < string2
int scomp(string str1, string str2) //Compare string
{
    int i = 0;
    bool finish = false;
    int num;

    while(finish != true)
    {
        if(str1[i] == '\0')
        {   
            num = 1;
            finish = true;
        } else if (str2[i] == '\0')
        {
            num = -1;
            finish = true;
        }

        int a = (int)str1[i]; 
        int b = (int)str2[i];

        if(a > b)
        {
            num = 1;
            finish = true;

        } else if(a < b)
        {
            num = -1;
            finish = true;

        } else if(a == b)
        {
            i++;
        }
    }

    return num;
}

//Fungsi untuk menukarkan struct
//void sswap(var dbarang, indeks1, indeks2)
void sswap(dbarang barang[], int a, int b)  //struct swap
{
    dbarang cont = barang[a];
    barang[a] = barang[b];
    barang[b] = cont;
}

//Fungsi untuk mencari real posistion setiap nilai / fungsi untuk partitioning
//int rposition(dbarang barang, start, end) <-- return berupa real position dari nilai tengahnya
int rposition(dbarang barang[], int left, int right)
{
    int i = left + 1;
    string pivot = barang[left].nbarang;

    for(int j = left + 1; j <= right; j++)
    {
        if(barang[i].nbarang < pivot)
        {
            sswap (barang, i, j);
            i++;
        }
    }

    sswap(barang, left, (i - 1));
    return i - 1;
}

//Fungsi untuk sorting menggunakan quick sort
//void nbarang_sort(dbarang barang[], start, end)
void nbarang_sort(dbarang barang[], int left, int right)
{
    if(left < right)
    {
        int j = rposition(barang, left, right);
        nbarang_sort(barang, left, j - 1);
        nbarang_sort(barang, j + 1, right);
    }
}

//Fungsi untuk searching menggunakan binary search
//int found(string cont, array/struct, left, right) <-- return berupa posisi barang yang dicari
int find(string key, dbarang barang[], int left, int right)
{
    while(left <= right)
    {
        int mid = (left + right) / 2;

        if(key == barang[mid].nbarang)
        {
            return mid;
            break;

        } else if((scomp(key, barang[mid].nbarang)) > 0)
        {
           left = mid + 1;

        } else if((scomp(key, barang[mid].nbarang)) < 0)
        {
            right = mid - 1;
        }
    }

    return -1;
}

//Fungsi untuk menampilkan jumlah dan menyimpan total harga setiap barang
//int total(harga, jumlah) <-- return berupa total harga dari barang tersebut
void total(int harga, int jumlah)
{
    int total = harga * jumlah;

    cout << "@"; dharga(harga);
    cout << " x " << jumlah << " = "; dharga(total);
}

//Fungsi untuk menghitung subtotal
void subtotal(dstruk struk[], int count, int harga, int jumlah)
{  
    struk[count].stotal += (harga * jumlah);
}

//Fungsi untuk menghitung diskon
//int diskon(harga) <-- return berupa besar diskon dalam rupiah
int diskon(int total)
{
    int potongan;

    if(total > 5000000)
    {
        potongan = 0.3 * total;
    }else if (total > 2000000)
    {
        potongan = 0.15 * total;
    } else
    {
        potongan = 0 * total;
    }

    return potongan;
}

//Fungsi untuk menghitung ppn
//int ppn(harga, diskon) <-- return berupa besar ppn dari total belanjaan user
int ppn(int harga, int diskon)
{
    return (harga - diskon) * 0.1;
}

//Fungsi untuk mengolah struk pelanggan
//void hitung(struct, urutan)
void hitung(dstruk struk[], int count)
{
    struk[count].diskon = diskon(struk[count].stotal);
    struk[count].pajak = ppn(struk[count].stotal, struk[count].diskon);
    struk[count].gtotal = struk[count].stotal - struk[count].diskon + struk[count].pajak;
    struk[count].kembalian = struk[count].bayar - struk[count].gtotal;
}

//Fungsi untuk melakukan rekap ketika pelanggan mencapai 100 orang atau toko telah tutup
//void rekap(array, multiplier, count)
void rekap(dstruk struk[], int multiplier, int count)
{
    dstruk rekap;

    //Memberikan nilai default kepada seluruh isi struct agar tidak error saat dilakukan operasi penambahan
    rekap.stotal = 0;
    rekap.diskon = 0;
    rekap.pajak  = 0;
    rekap.gtotal = 0;
    rekap.bayar  = 0;
    rekap.kembalian = 0;

    for(int i = 0; i < count + 1; i++)
    {
        rekap.stotal += struk[i].stotal;
        rekap.diskon += struk[i].diskon;
        rekap.pajak += struk[i].pajak;
        rekap.gtotal += struk[i].gtotal;
        rekap.bayar += struk[i].bayar;
        rekap.kembalian == struk[i].kembalian;
    }

    int num1, num2;

    if(multiplier > 1)
    {
        num1 = (multiplier - 1) * 100 + 1;
        num2 = multiplier * 100;
    } else
    {
        num1 = 1;
        num2 = 100;
    }
    
    //Untuk display file rekap
    string file1 = to_string(num1);
    string file2 = to_string(num2);

    stringstream kumpul;
    kumpul << "Rekap pelanggan " << file1 << " sampai " << file2 << ".txt";

    ofstream myFile;
    myFile.open(kumpul.str());
    myFile << "---------------------------------------------------------------------------------------\n";
    myFile << "Rekap pelanggan " << num1 << " sampai " << num2 << "\n";
    myFile << "---------------------------------------------------------------------------------------\n";

    myFile << "Total dari Subtotal" << "      : ";
    myFile << dhargaf(rekap.stotal);

    myFile << "\nTotal dari Diskon" << "        : "; 
    myFile << dhargaf(rekap.diskon);

    myFile << "\nTotal dari PPN" << "           : "; 
    myFile << dhargaf(rekap.pajak);

    myFile << "\nTotal dari Grand Total" << "   : "; 
    myFile << dhargaf(rekap.gtotal);

    myFile << "\nTotal dari Bayar" << "         : "; 
    myFile << dhargaf(rekap.bayar);
    myFile << "\n---------------------------------------------------------------------------------------";

    myFile.close();
}

//Fungsi untuk menghitung nama barang paling panjang
//int length(array, jumlah barang)
int mlength(dbarang barang[], int jumlah)
{
    int count = 0, num = 0;

    for(int i = 0; i < jumlah; i++)
    {

        for(int j = 0; barang[i].nbarang[j] != '\0'; j++)
        {
            num++;
        }

        if(num > count)
        {
            count = num;
        }

        num = 0;
    }

    return count;
}

//Fungsi untuk menghitung panjang nama barnag
//int length(string)
int length(string str)
{
    int count = 0;

    for(int i = 0; str[i] != '\0'; i++)
    {
        count++;
    }

    return count;
}

int main()
{
    //jumlah : jumlah barang, count : urutan pelanggan, multiplier : urutan per 100 pelanggan 
    int jumlah, count = 0, multiplier = 0;

    //Variabel boolean dibawah untuk menentukan apakah penginputan berlanjut atau tidak 
    bool go = false, next = true, pass = false, pelanggan;

    //cont : container untuk menyimpan sementara nama barang sebelum dipastikan telah ada di data sebelumnya
    string cont;
    dstruk struk[100];  //Setelah 100 pelanggan akan otomatis mencetak rekap

    //Untuk menyimpan apakah kasir melanjutkan penginputan atau tidak
    char detect;

    cout << "Berapa barang yang akan dijual? : ";
    cin >> jumlah;
    cout << "\n";

    //Deklarasi struct barang
    dbarang barang[jumlah];
    
    //Deklarasi variabel untuk menyimpan jumlah barang dan array untuk menyimpan jumlah barang;
    //Fungsinya agar kasir bisa menambah barnag yang dibeli
    int number, jbarang[jumlah];

    //Looping untuk memberikan nilai default kepada array jbarang agar tidak eror saat dilakukan penambahan 
    for(int i = 0; i < jumlah; i++)
    {
        jbarang[i] = 0;
    }

    //Untuk menyimpan barang di urutan mana saja yang dibeli
    bool order[jumlah];

    //Kasir melakukan input barang
    for(int i = 0; i < jumlah; i++)
    {
        cout << "Masukkan nama barang ke-" << i + 1 << ": ";
        cin >> barang[i].nbarang;

        cout << "Masukkan harga barang ke-" << i + 1 << ": ";
        cin >> barang[i].hbarang;
        
        cout << "\n";
    }

    //Proses sorting barang yang dijual oleh Toko Sumber Makmur
    nbarang_sort(barang, 0, jumlah - 1);

    //Menampilkan hasil sorting
    for(int i = 0; i < jumlah; i++)
    {
        dnama(barang[i].nbarang);
        cout << " @"; 
        dharga(barang[i].hbarang);
        cout << "\n";
    }

    //Proses pembuatan struk pelanggan
    do
    {
        cout << "\nPelanggan ke-" << (count + 1) + (multiplier * 100) << "\n";
        cout << "==============\n";

        cout << "Masukkan nomor nota: ";
        cin >> struk[count].nnota;

        //Kasir melakukan input barang yang dibeli pelanggan
        while(next == true)
        {
            while(go == false)
            {
                cin.ignore(100, '\n');
                cin.clear();
                cout << "\nMasukkan nama barang: ";
                cin >> cont;

                int exist = find(cont, barang, 0, jumlah - 1);
                
                if(exist != -1)
                {
                    order[exist] = true; 
                    cout << "Masukkan jumlah barang yang dibeli: ";
                    cin >> number;
                    jbarang[exist] += number; //Fungsinya agar kasir bisa menambah barang yang dibeli
                    cin.ignore(100, '\n');

                    total(barang[exist].hbarang, jbarang[exist]);   //Untuk menampilkan total
                    subtotal(struk, count, barang[exist].hbarang, jbarang[exist]) ;  //Untuk menghitung total
                    go = true;

                } else
                {
                    cout << "Nama barang yang dicari tidak ditemukan!\n";
                    go = false;
                }
            }
        
            cout << "\n\nMasukkan 'y' untuk lanjut dan 'selain y' untuk berhenti!: ";
            cin >> detect;

            //Untuk mendeteksi apakah lanjut atau tidak
            if(detect == 'y')
            {
                next = true;
                go = false;
            } else 
            {
                next = false;
            }
        }

        hitung(struk, count);  //Untuk mengolah struk pelanggan

        cout << "Total harga adalah: "; dharga(struk[count].gtotal); cout << "\n";

        //Untuk menyimpan uang yang dibayarkan dan mendeteksi apakah ada kekurangan bayar atau tidak
        while(pass == false)
        {
            cin.ignore(100, '\n');
            cin.clear();
            cout << "\nMasukkan uang yang dibayar pelanggan: ";
            cin >> struk[count].bayar;

            if(struk[count].bayar < struk[count].gtotal)
            {
                cout << "Uang yang dibayarkan kurang!\n";
                pass = false;
            } else
            {
                pass = true;
            }
        }
        
        struk[count].kembalian = struk[count].bayar - struk[count].gtotal;
        cout << "Kembalian: "; dharga(struk[count].kembalian); cout << "\n";

        //Untuk menyimpan ukuran dari nama barang terpanjang
        int size = mlength(barang, jumlah);

        //Memulai proses pencetakan struk
        stringstream nota, file;
        nota << struk[count].nnota << ".txt";

        ofstream myFile;
        myFile.open(nota.str());

        myFile << "---------------------------------------------------------------------------------------";
        myFile << "\nTOKO SUMBER MAKMUR";
        myFile << "\nJl. Lengkong Gudang No. 61, Serpong, Kota, Tanggerang Selatan";
        myFile << "\nTelp. 021-563478 ";
        myFile << "\n---------------------------------------------------------------------------------------";
        myFile << "\nNama Barang" << "    " << "Jumlah" << "   " << "Harga Satuan" << "       " <<  "Total"; 
        myFile << "\n";

        for(int i = 0; i < jumlah; i++)
        {
            int slength;    //Untuk menyimpan panjang string 
            if(order[i] == true)
            {
                slength = 11 - length(barang[i].nbarang);

                myFile << barang[i].nbarang; 
                
                for(int i = 0; i < slength; i++)
                {
                    myFile << " ";
                }

                myFile << setw(8) << jbarang[i] << setw(14) << barang[i].hbarang << setw(15) << jbarang[i] * barang[i].hbarang << "\n";
            }
        }
        
        myFile << "\n---------------------------------------------------------------------------------------";
        myFile << "\nSubtotal" << "      : ";
        myFile << dhargaf(struk[count].stotal);

        myFile << "\nDiskon" << "        : "; 
        myFile << dhargaf(struk[count].diskon);

        myFile << "\nPPN" << "           : "; 
        myFile << dhargaf(struk[count].pajak);

        myFile << "\nGrand Total" << "   : "; 
        myFile << dhargaf(struk[count].gtotal);

        myFile << "\nBayar" << "         : "; 
        myFile << dhargaf(struk[count].bayar);

        myFile << "\nKembalian" << "     : "; 
        myFile << dhargaf(struk[count].kembalian);

        myFile << "\n---------------------------------------------------------------------------------------";
        myFile << "\nTerima Kasih Atas Kunjungan Anda";
        myFile << "\n---------------------------------------------------------------------------------------";
        myFile.close();

        //Untuk menentukan apakah kasir melanjutkan penginputan atau sudah selesai
        cin.ignore(100, '\n');
        cin.clear();
        cout << "Masukkan 'y' jika masih ada pelanggan dan 'selain y' untuk tutup toko: ";
        cin >> detect;

        if(detect == 'y')
        {
            pelanggan = true;
            count++;
        }else
        {
            cout << "Toko telah tutup!" << "\n";
            cout << "Selamat beristirahat dan bertemu di esok hari :)";
            rekap(struk, multiplier, count);
            cout << "\nRekap berhasil dicetak!";

            pelanggan = false;
        }

        //Jika sudah mencapai 100 pelanggan, maka akan otomatis mencetak rekap per 100 pelanggan
        if(count == 99)
        {
            multiplier++;
            rekap(struk, multiplier, count);
            cout << "\nRekap berhasil dicetak!";
            count = 0;
        }

    } while (pelanggan == true);
    
    return 0;
}