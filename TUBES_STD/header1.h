#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include<iostream>
#include<string.h>

#define first(L) L.first
#define next(p) p->next
#define prev(p) p->prev
#define info(p) p->info

using namespace std;

//juri SLL first last
struct infotype_juri {
    string uname, pass;
};
typedef struct elm_juri *address_juri;
struct elm_juri {
    infotype_juri info;
    address_juri next;
};
struct list_juri {
    address_juri first, last;
};


//peserta SLL first last
struct infotype_peserta {
    string nama;
    float nilai; //nilai total = ratarata nilai yang diberikan tiap juri
    float i; //banyak juri yang sudah memberi nilai
};
typedef struct elm_peserta *address_peserta;
struct elm_peserta {
    infotype_peserta info;
    address_peserta next;
};
struct list_peserta {
    address_peserta first, last;
};


//relasi CDLL first
typedef struct elm_relasi *address_relasi;
struct elm_relasi {
    float info;         //nilai yang diberi juri untuk peserta
    address_juri juri;
    address_peserta peserta;
    address_relasi next, prev;
};
struct list_relasi {
    address_relasi first;
};

// stack temporer
typedef struct elm_temp *address;
struct elm_temp {
    string info;
    address next;
};
struct list_temp {
    address first;
};

//Create list dan elemen :
void createListJ(list_juri &J);
void createListP(list_peserta &P);
void createListR(list_relasi &R);
void createElm_juri(string unm, string pass, address_juri &p);
void createElm_peserta(string x, address_peserta &p);
void createElm_relasi(float x, address_juri p, address_peserta &q, address_relasi &r);

//search :
address_juri searchJuri(list_juri J, string cari);
address_peserta searchPeserta(list_peserta P, string cari);
address_relasi searchRelasi(list_relasi R, string juri, string peserta);
address_relasi search_juri_diRelasi(list_relasi R, string juri);
address_relasi search_peserta_diRelasi(list_relasi R, string peserta);

//insert :
void insert_Peserta(list_peserta &P, address_peserta q);    //insert last
void insert_first_Juri(list_juri &J, address_juri p);
void insert_last_Juri(list_juri &J, address_juri p);
void insert_after_Juri(address_juri prec, address_juri p);
void add_Juri(list_juri &J, address_juri p);
void insert_Relasi(list_relasi &R, address_relasi p);         //insert first

//delete :
void delete_elm_Juri(list_juri &J, list_peserta &P, list_relasi &R, address_juri &p, string unameJuri);
void delete_elm_peserta(list_juri &J, list_peserta &P, list_relasi &R, address_peserta &p, string nama);
void delete_elm_Relasi(list_juri &J, list_peserta &P, list_relasi &R, address_relasi &p, string uname_juri, string nama_peserta); // menghapus elemen list relasi berdasarkan username juri dan nama peserta

//Print :
void print_Juri(list_juri J);
void print_Peserta(list_peserta P);
void print_Relasi(list_relasi R);


void MainMenu(list_juri &J, list_peserta &P, list_relasi &R);
void LoginMenu(list_juri &J, list_peserta &P, list_relasi &R);
void LoginAdmin(list_juri &J, list_peserta &P, list_relasi &R);
void LoginJuri(list_juri &J, list_peserta &P, list_relasi &R);
bool cekJuri(list_juri J, string uName, string pass);
void MenuAdmin(list_juri &J, list_peserta &P, list_relasi &R);
void MenuJuri(list_juri &J, list_peserta &P, list_relasi &R, address_juri j);
int hitung_peserta (list_peserta P);
int hitung_juri(list_juri J);
int hitung_relasi(list_relasi R);
void descending_peserta(list_peserta P);

//Opsi menu admin
void TambahJuri(list_juri &J);
void EditDataJuri(list_juri &J);
void HapusDataJuri(list_juri &J, list_peserta &P, list_relasi &R);
void TambahPeserta(list_peserta &P);
void EditDataPeserta(list_peserta &P);
void HapusDataPeserta(list_juri &J, list_peserta &P, list_relasi &R);
void detail_nilai(list_peserta P, list_relasi R, list_juri J);
void detail_penilaian(list_peserta P, list_relasi R, list_juri J);

// Opsi menu juri
void beri_nilai(list_relasi &R, list_peserta &P, address_juri j);
void ubah_nilai(list_relasi &R, list_peserta &P, address_juri j);
void input_nilai(list_relasi &R, list_peserta &P, list_juri J, address_juri j);
void view_peserta_sudah_dinilai(list_relasi &R, list_peserta &P, address_juri j);
void view_peserta_belum_dinilai(list_relasi &R, list_peserta &P, address_juri j);
void hapus_nilai(list_relasi &R, list_peserta &P, list_juri J, address_juri j);


void TambahNilai(address_peserta &p, float nilai); //panggil setiap tambah relasi
void KurangNilai(address_peserta &p, float nilai); //panggil setiap hapus relasi

#endif // HEADER_H_INCLUDED
