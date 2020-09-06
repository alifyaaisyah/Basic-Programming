#include<iostream>
#include"header1.h"

using namespace std;

// CREATE :
void createListJ(list_juri &J){
    first(J) = NULL;
    J.last = NULL;
}
void createListP(list_peserta &P){
    first(P) = NULL;
    P.last = NULL;
}
void createListR(list_relasi &R){
    first(R) = NULL;
}

void createElm_juri(string unm, string pass, address_juri &p){
    p = new elm_juri;
    info(p).uname = unm;
    info(p).pass = pass;
    next(p) = NULL;
}
void createElm_peserta(string x, address_peserta &p){
    p = new elm_peserta;
    info(p).nama = x;
    info(p).nilai = 0;
    info(p).i = 0;
    next(p) = NULL;
}
void createElm_relasi(float x, address_juri p, address_peserta &q, address_relasi &r){
    r = new elm_relasi;
    info(r) = x;
    r->juri = p;
    r->peserta = q;
    TambahNilai(q, x);
    next(r) = NULL;
}

// INSERT :
void insert_Peserta(list_peserta &P, address_peserta q){
    if (first(P) == NULL){
        first(P) = q;
        P.last = q;
    } else {
        next(P.last) = q;
        P.last = q;
    }
}   //insert last

void insert_first_Juri(list_juri &J, address_juri p){
    if (first(J) == NULL){
        first(J) = p;
        J.last = p;
    } else {
        next(p) = first(J);
        first(J) = p;
    }
}
void insert_last_Juri(list_juri &J, address_juri p){
    if (first(J)==NULL){
        first(J) = p;
        J.last = p;
    } else {
        next(J.last) = p;
        J.last = p;
    }
}
void insert_after_Juri(address_juri prec, address_juri p){
    next(p) = next(prec);
    next(prec) = p;
}
void add_Juri(list_juri &J, address_juri p){ // urut ascending berdasarkan uname
    bool found = (searchJuri(J, info(p).uname)) != NULL;

    if (!found){
        if (first(J)==NULL){
            insert_first_Juri(J, p);
        } else if (info(first(J)).uname > info(p).uname){
            insert_first_Juri(J, p);
        } else if(info(J.last).uname < info(p).uname) {
            insert_last_Juri(J, p);
        } else {
            address_juri prec = first(J);
            while (info(next(prec)).uname < info(p).uname){
                prec = next(prec);
            }
            insert_after_Juri(prec, p);
        }
    }
}
void insert_Relasi(list_relasi &R, address_relasi p){ //insert first CDLL
    if (first(R) == NULL){
        first(R) = p;
        next(p) = p;
        prev(p) = p;
    } else {
        next(p) = first(R);
        prev(p) = prev(first(R));
        prev(first(R)) = p;
        next(prev(p)) = p;
        first(R) = p;
    }
}

// PRINT :
void print_Juri(list_juri J){
    cout << "Daftar Juri:\n";
    if(first(J)==NULL){
        cout << "Tidak tersedia.\n";
    } else {
        int i = 1;
        address_juri p = first(J);
        while (p != NULL){
            cout<<"   ["<<i<<"] "<<info(p).uname<<" "<<info(p).pass<<"\n";
            p = next(p);
            ++i;
        }
    }
    cout << endl;
}
void print_Peserta(list_peserta P){
    cout << "Daftar Peserta:\n";
    if (first(P)==NULL){
        cout << "Tidak tersedia.\n";
    } else {
        int i = 1;
        address_peserta p = first(P);
        while (p != NULL){
            cout<<"   ["<<i<<"] "<<info(p).nama<<" "<<info(p).nilai<<"\n";
            p = next(p);
            ++i;
        }
    }
    cout<<endl;
}

void print_Relasi(list_relasi R){
    cout << "Daftar nilai:\n";
    if (first(R) == NULL){
        cout << "Tidak tersedia.\n";
    } else {
        int i = 1;
        address_relasi p = first(R);
        do {
            cout<<"   ["<<i<<"] "<<info(p->peserta).nama<<" dinilai oleh "<<info(p->juri).uname<<": "<<info(p)<<endl;
            p = next(p);
        } while (p != first(R));

    }
    cout<<endl;
}

// SEARCH :
address_juri searchJuri(list_juri J, string cari){
    address_juri p = first(J);
    while (p!=NULL){
        if (info(p).uname == cari) {
            return p;
        }
        p = next(p);
    }
    return p;
}
address_peserta searchPeserta(list_peserta P, string cari){
        address_peserta p = first(P);
        while (p!=NULL){
            if (info(p).nama == cari){
                return p;
            }
            p = next(p);
        }
        return p;
}
address_relasi searchRelasi(list_relasi R, string juri, string peserta){
    if (first(R)==NULL){
        return NULL;
    }
    address_relasi p = first(R);
    if (info(p->juri).uname==juri && info(p->peserta).nama==peserta){
            return p;
    }
    p = next(p);
    while (p!=first(R)){
        if (info(p->juri).uname==juri && info(p->peserta).nama==peserta){
            return p;
        }
        p = next(p);
    }
    return NULL;
}
address_relasi search_juri_diRelasi(list_relasi R, string juri){
    if(first(R)==NULL){
        return NULL;
    } else if (info(first(R)->juri).uname==juri){
        return first(R);
    }
    address_relasi p = next(first(R));
    while (p!=first(R)){
        if (info(p->juri).uname==juri){
            return p;
        }
        p = next(p);
    }
    return NULL;
}
address_relasi search_peserta_diRelasi(list_relasi R, string peserta){
    if(first(R)==NULL){
        return NULL;
    } else if (info(first(R)->peserta).nama == peserta){
        return first(R);
    }
    address_relasi p = next(first(R));
    while (p!=first(R)){
        if (info(p->peserta).nama == peserta){
            return p;
        }
        p = next(p);
    }
    return NULL;
}



// DELETE :
void delete_elm_Juri(list_juri &J, list_peserta &P, list_relasi &R, address_juri &p, string unameJuri){
    p = searchJuri(J, unameJuri);
    if (p != NULL){
        if (p == first(J)){
            first(J) = next(first(J));
            if (p == J.last){
                J.last = NULL;
            }
        } else {
            address_juri q = first(J);
            while (info(next(q)).uname != unameJuri){
                q = next(q);
            }
            next(q) = next(p);
            if (p == J.last){
                J.last = q;
            }
        }
        next(p) = NULL;
    }
    address_relasi r = search_juri_diRelasi(R, unameJuri);
    while (r!=NULL){
        KurangNilai(r->peserta, info(r));

        if (r == first(R)){
            if(next(r)==r){
                first(R) = NULL;
            } else {
                first(R) = next(r);
                next(prev(r)) = first(R);
                prev(first(R)) = prev(r);
            }
        } else {
            address_relasi prec = first(R);
            while (next(prec)!=r){
                prec = next(prec);
            }
            next(prec) = next(r);
            prev(next(r)) = prec;
        }
        next(r) = NULL;
        prev(r) = NULL;
        r = search_juri_diRelasi(R, unameJuri);
    }
}

void delete_elm_peserta(list_juri &J, list_peserta &P, list_relasi &R, address_peserta &p, string nama){
    p = searchPeserta(P, nama);
    if (p != NULL){
        if (p == first(P)){
            first(P) = next(first(P));
            if (p == P.last){
                P.last = NULL;
            }
        } else {
            address_peserta q = first(P);
            while (next(q) != p){
                q = next(q);
            }
            next(q) = next(p);
            if (p == P.last){
                P.last = q;
            }
        }
        next(p) = NULL;
    }

    address_relasi r = search_peserta_diRelasi(R, nama);
    while (r!=NULL){
        if (r == first(R)){
            if(next(r)==r){
                first(R) = NULL;
            } else {
                first(R) = next(r);
                next(prev(r)) = first(R);
                prev(first(R)) = prev(r);
            }
        } else {
            address_relasi prec = first(R);
            while (next(prec)!=r){
                prec = next(prec);
            }
            next(prec) = next(r);
            prev(next(r)) = prec;
        }
        next(r) = NULL;
        prev(r) = NULL;
        r = search_juri_diRelasi(R, nama);
    }
}
void delete_elm_Relasi(list_juri &J, list_peserta &P, list_relasi &R, address_relasi &p, string uname_juri, string nama_peserta){
    p = searchRelasi(R, uname_juri, nama_peserta);
    if (p!=NULL){
        if (p == first(R)){
            if(next(p)==p){
                first(R) = NULL;
            } else {
                first(R) = next(p);
                next(prev(p)) = first(R);
                prev(first(R)) = prev(p);
            }
        } else {
            address_relasi prec = first(R);
            while (next(prec)!=p){
                prec = next(prec);
            }
            next(prec) = next(p);
            prev(next(p)) = prec;
        }
        next(p) = NULL;
        prev(p) = NULL;
    }
}

void MainMenu(list_juri &J, list_peserta &P, list_relasi &R){
    int pil;
    cout << "\n--------------------------------------------------";
    cout << "\nMENU UTAMA:" << endl;
    cout << "[1] Lihat data peserta" << endl; //terurut berdasarkan total nilai
    cout << "[2] Login" << endl;
    cout << "[3] Keluar" << endl;
    cout << "Masukkan pilihan Anda: ";
    cin >> pil;
    while (pil!=1 && pil!=2 && pil!=3){
        cout << "Input tidak valid. Tolong masukkan pilihan Anda kembali.\n";
        cout << "Masukkan pilihan Anda: ";
        cin >> pil;
    }
    if (pil==1){
        cout << endl;
        if(hitung_juri(J)==0 || hitung_peserta(P)==0){
            cout << "Perolehan nilai tidak tersedia." << endl;
        } else if(hitung_relasi(R) == hitung_juri(J) * hitung_peserta(P)){
            cout << "Perolehan Nilai Akhir" << endl;
            descending_peserta(P);
        } else {
            cout << "Perolehan Nilai Sementara" << endl;
            descending_peserta(P);
        }
        cout << "Mengembalikan ke menu utama..." << endl;
        MainMenu(J, P, R);
    } else if (pil==2){
        LoginMenu(J, P, R);
    }
}

int hitung_peserta (list_peserta P){
    address_peserta q = first(P);
    int i = 0;
    while (q != NULL){
        ++i;
        q = next(q);
    }
    return i;
}
int hitung_juri(list_juri J){
    address_juri p = first(J);
    int i = 0;
    while (p!=0){
        ++i;
        p = next(p);
    }
    return i;
}
int hitung_relasi(list_relasi R){
    if(first(R)==NULL){
        return 0;
    }
    address_relasi p = first(R);
    int i = 0;
    do {
        ++i;
        p = next(p);
    } while(p!=first(R));
    return i;
}

void descending_peserta(list_peserta P){
    list_peserta Q;
    createListP(Q);
    address_peserta p, pMax;
    int n = hitung_peserta(P);
    for (int i=0; i<n; ++i){
        pMax = NULL;
        p = first(P);
        while(pMax==NULL && p!=NULL){
            if(searchPeserta(Q, info(p).nama) == NULL){
                pMax = p;
            }
            p = next(p);
        }
        p = first(P);
        while(p!=NULL){
            if(info(p).nilai>=info(pMax).nilai && searchPeserta(Q, info(p).nama)==NULL){
                pMax = p;
            }
            p = next(p);
        }
        createElm_peserta(info(pMax).nama, p);
        info(p).nilai = info(pMax).nilai;
        insert_Peserta(Q, p);
    }
    print_Peserta(Q);
}

void LoginMenu(list_juri &J, list_peserta &P, list_relasi &R){
    int pil;
    cout << "\nMenu:" << endl;
    cout << "[1] Login admin" << endl;
    cout << "[2] Login juri" << endl;
    cout << "[3] Kembali ke menu awal" << endl;
    cout << "Masukkan pilihan Anda: ";
    cin >> pil;
    while (pil!=1 && pil!=2 && pil!=3){
        cout << "Input tidak valid. Tolong masukkan pilihan Anda kembali.\n";
        cout << "Masukkan pilihan Anda: ";
        cin >> pil;
    }
    if (pil==1){
        LoginAdmin(J, P, R);
    } else if (pil==2){
        LoginJuri(J, P, R);
    } else {
        MainMenu(J, P, R);
    }
}

void LoginAdmin(list_juri &J, list_peserta &P, list_relasi &R){
    string uName, pass;
    int tries = 1;
    cout << "\nLOGIN ADMIN\n";
    cout << "Username: ";
    cin >> uName;
    cout << "Password: ";
    cin >> pass;
    while ((uName!="adminTC" || pass!="sukseskankontes") && (tries<3)){
        cout << "Username atau password tidak valid." << endl;
        cout << "\nUsername: ";
        cin >> uName;
        cout << "Password: ";
        cin >> pass;
        ++tries;
    }
    if (tries==3 && (uName!="adminTC" || pass!="sukseskankontes")) {
        cout << "Login admin gagal.\nMengembalikan ke menu utama...\n\n";
        MainMenu(J, P, R);
    } else {
        cout << "Login berhasil.\n\n";
        MenuAdmin(J, P, R);
    }
}

void MenuAdmin(list_juri &J, list_peserta &P, list_relasi &R){
    int pil;
    cout << "\n--------------------------"<<endl;
    cout << "MENU ADMIN:\n";
    cout << "  [1] Tambah juri baru" << endl;
    cout << "  [2] Lihat data juri" << endl;
    cout << "  [3] Edit data juri" << endl;
    cout << "  [4] Hapus data juri" << endl;
    cout << "  [5] Tambah peserta baru" << endl;
    cout << "  [6] Lihat data peserta" << endl;
    cout << "  [7] Edit data peserta" << endl;
    cout << "  [8] Hapus data peserta" << endl;
    cout << "  [9] Lihat nilai setiap peserta" << endl;
    cout << " [10] Lihat detail penilaian tiap juri" << endl;
    cout << " [11] Logout\n" << endl;
    cout << "Masukkan pilihan Anda:";
    cin >> pil;

    while (pil<1 || pil>11){
        cout << "Input tidak valid. Tolong masukkan pilihan anda kembali.\n";
        cout << "Masukkan pilihan Anda: ";
        cin >> pil;
    }
    switch(pil){
        case 1:
            TambahJuri(J);
            MenuAdmin(J, P, R);
            break;
        case 2:
            print_Juri(J);
            MenuAdmin(J, P, R);
            break;
        case 3:
            EditDataJuri(J);
            MenuAdmin(J, P, R);
            break;
        case 4:
            HapusDataJuri(J, P, R);
            MenuAdmin(J, P, R);
            break;
        case 5:
            TambahPeserta(P);
            MenuAdmin(J, P, R);
            break;
        case 6:
            print_Peserta(P);
            MenuAdmin(J, P, R);
            break;
        case 7:
            EditDataPeserta(P);
            MenuAdmin(J, P, R);
            break;
        case 8:
            HapusDataPeserta(J, P, R);
            MenuAdmin(J, P, R);
            break;
        case 9:
            detail_nilai(P,R,J);
            MenuAdmin(J, P, R);
            break;
        case 10:
            detail_penilaian(P,R,J);
            MenuAdmin(J, P, R);
            break;
        case 11:
            cout << "Logout berhasil. Mengembalikan ke menu utama...\n\n";
            MainMenu(J, P, R);
            break;
    }
}
void LoginJuri(list_juri &J, list_peserta &P, list_relasi &R){
    string uName, pass;
    bool found;
    int tries = 1;
    cout << "\nLOGIN JURI\n";
    cout << "Username: ";
    cin >> uName;
    cout << "Password: ";
    cin >> pass;
    found = cekJuri(J, uName, pass);
    while (tries<3 && !found){
        cout << "Username atau password tidak valid." << endl;
        cout << "\nUsername: ";
        cin >> uName;
        cout << "Password: ";
        cin >> pass;
        ++tries;
        found = cekJuri(J, uName, pass);
    }
    if (tries > 3) {
        cout << "Login juri gagal.\nMengembalikan ke menu utama...\n\n";
        MainMenu(J, P, R);
    } else {
        address_juri j = searchJuri(J, uName);
        cout << "Login berhasil.\n\n";
        MenuJuri(J, P, R, j);
    }
}

bool cekJuri(list_juri J, string uName, string pass){
    address_juri p = searchJuri(J, uName);
    if (p != NULL){
        if (info(p).pass == pass){
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

void MenuJuri(list_juri &J, list_peserta &P, list_relasi &R, address_juri j){
    int pil;
    cout << "\n---------------------------------"<<endl;
    cout << "  MENU JURI:\n";
    cout << "  [1] Input nilai peserta" << endl;
    cout << "  [2] Tampilkan nilai peserta" << endl; //tampilkan peserta yang sudah dinilai
    cout << "  [3] Tampilkan peserta yang belum dinilai" << endl;
    cout << "  [4] Hapus nilai peserta" << endl;
    cout << "  [5] Lihat profil" << endl;
    cout << "  [6] Logout\n" << endl;

    cout << "Masukkan pilihan Anda: ";
    cin >> pil;
    while (pil<1 || pil>6){
        cout << "Input tidak valid. Tolong masukkan pilihan Anda kembali.\n";
        cout << "Masukkan pilihan Anda: ";
        cin >> pil;
        cout<<endl;
    }
    switch(pil){
        case 1:
            input_nilai(R, P, J, j);
            MenuJuri(J,P,R,j);
            break;
        case 2:
            view_peserta_sudah_dinilai(R,P,j);
            MenuJuri(J,P,R,j);
            break;
        case 3:
            view_peserta_belum_dinilai(R,P,j);
            MenuJuri(J,P,R,j);
            break;
        case 4:
            hapus_nilai(R,P,J,j);
            MenuJuri(J,P,R,j);
            break;
        case 5:
            cout << "Username: " << info(j).uname << endl;
            cout << "Password: " << info(j).pass << endl;
            MenuJuri(J, P, R, j);
            break;
        case 6:
            cout << "Logout berhasil. Mengembalikan ke menu utama...\n\n";
            MainMenu(J, P, R);
            break;
    }
}

void TambahJuri(list_juri &J){
    string uname, pass;
    cout << "Data Juri Baru\n";
    cout << "Username: ";
    cin >> uname;
    cout << "Password: ";
    cin >> pass;
    address_juri p;
    if (searchJuri(J, uname) == NULL){
        createElm_juri(uname, pass, p);
        add_Juri(J, p);
        cout << "Insert data juri berhasil.";
    } else {
        cout << "Data juri sudah ada.";
    }
}

void EditDataJuri(list_juri& J){
    string uname, pass;
    cout << "Masukkan data juri yang akan diedit\n";
    cout << "Username: ";
    cin >> uname;
    cout << "Password: ";
    cin >> pass;
    bool found = cekJuri(J, uname, pass);
    if (found){
        address_juri p = searchJuri(J, uname);
        cout << "Username baru: ";
        cin >> uname;
        cout << "Password baru: ";
        cin >> pass;
        info(p).uname = uname;
        info(p).pass = pass;
        cout << "Data juri berhasil diedit. Mengembalikan ke menu admin...\n";
    } else {
        cout << "Data juri tidak ditemukan. Mengembalikan ke menu admin...\n";
    }
}

void HapusDataJuri(list_juri& J, list_peserta& P, list_relasi& R){
    int pil;
    cout << "[1] Hapus semua data juri" << endl;
    cout << "[2] Hapus data juri pilihan" << endl;
    cout << "[3] Kembali ke menu admin" << endl;
    cout << "Masukkan pilihan Anda: ";
    cin >> pil;
    while (pil!=1 && pil!=2 && pil!=3){
        cout << "Input tidak valid. Tolong masukkan pilihan Anda kembali.\n";
        cout << "Masukkan pilihan Anda: ";
        cin >> pil;
        cout<<endl;
    }
    if (pil==1){
        address_juri p = first(J);
        while(p!=NULL){
            delete_elm_Juri(J, P, R, p, info(p).uname);
            p = first(J);
        }
        cout << "Seluruh data juri berhasil dihapus.\nMengembalikan ke menu admin...\n";
    } else if (pil==2){
        string uname, pass;
        cout << "Masukkan data juri yang akan dihapus\n";
        cout << "Username: ";
        cin >> uname;
        cout << "Password: ";
        cin >> pass;
        bool found = cekJuri(J, uname, pass);
        if (found){
            address_juri p;
            delete_elm_Juri(J, P, R, p, uname);
            cout << "Data juri berhasil dihapus.\nMengembalikan ke menu admin...\n";
        } else {
            cout << "Data juri tidak ditemukan.\nMengembalikan ke menu admin...\n";
        }
    }
}

void TambahPeserta(list_peserta& P){
    string nama;
    cout << "Nama peserta: ";
    cin >> nama;
    address_peserta p;
    createElm_peserta(nama, p);
    insert_Peserta(P, p);
    cout << "Data peserta berhasil ditambah.\nMengembalikan ke menu admin...\n";
}

void EditDataPeserta(list_peserta& P){
    int pil;
    cout << "Data peserta yang akan diedit\n";
    cout << "[1] Nama peserta\n";
    cout << "[2] Nilai peserta\n";
    cout << "[3] Kembali ke menu admin\n";
    cout << "Masukkan pilihan Anda: ";
    cin >> pil;
    while (pil!=1 && pil!=2 && pil!=3){
        cout << "Input tidak valid. Tolong masukkan pilihan Anda kembali.\n";
        cout << "Masukkan pilihan Anda: ";
        cin >> pil;
    }
    if(pil==1){
        string nama;
        cout << "Nama peserta yang akan diedit: ";
        cin >> nama;
        address_peserta p = searchPeserta(P, nama);
        if (p!=NULL){
            cout << "Nama peserta baru: ";
            cin >> nama;
            info(p).nama = nama;
            cout << "Nama peserta berhasil diedit." << endl;
            cout << "Mengembalikan ke menu admin...";
        } else {
            cout << "Tidak ditemukan peserta dengan nama " << nama << "." << endl;;
            cout << "Mengembalikan ke menu admin...";
        }
    } else if (pil==2){
        cout << "Anda tidak memiliki izin untuk mengubah data nilai." << endl;
        cout << "Mengembalikan ke menu admin..." << endl;
    }
}

void HapusDataPeserta(list_juri& J, list_peserta& P, list_relasi& R){
    int pil;
    cout << "[1] Hapus semua data peserta" << endl;
    cout << "[2] Hapus data peserta pilihan" << endl;
    cout << "[3] Kembali ke menu admin" << endl;
    cout << "Masukkan pilihan Anda: ";
    cin >> pil;
    while (pil!=1 && pil!=2 && pil!=3){
        cout << "Input tidak valid. Tolong masukkan pilihan Anda kembali.\n";
        cout << "Masukkan pilihan Anda: ";
        cin >> pil;
        cout<<endl;
    }

    if(pil==1){
        address_peserta p = first(P);
        while(p!=NULL){
            delete_elm_peserta(J, P, R, p, info(p).nama);
            p = first(P);
        }
        cout << "Seluruh data peserta berhasil dihapus.\nMengembalikan ke menu admin...\n";
    } else if(pil==2){
        string nama;
        cout << "Nama peserta yang akan dihapus: ";
        cin >> nama;
        address_peserta p = searchPeserta(P, nama);
        if (p!=NULL){
            delete_elm_peserta(J, P, R, p, nama);
            cout << "Data peserta berhasil dihapus.\nMengembalikan ke menu admin...\n";
        } else {
            cout << "Data peserta tidak ditemukan.\nMengembalikan ke menu admin...\n";
        }
    }
}

void TambahNilai(address_peserta &p, float nilai){ //panggil setiap menambah relasi
    info(p).nilai = info(p).nilai * info(p).i;
    info(p).i = info(p).i + 1;
    info(p).nilai = (info(p).nilai + nilai) / info(p).i;
}

void KurangNilai(address_peserta& p, float nilai){ //panggil setiap menghapus relasi
    if (info(p).i==1){
        info(p).i = 0;
        info(p).nilai = 0;
    } else {
        info(p).nilai = info(p).nilai * info(p).i;
        info(p).i = info(p).i - 1;
        info(p).nilai = (info(p).nilai - nilai) / info(p).i;
    }
}
void detail_nilai(list_peserta P, list_relasi R, list_juri J){
    address_peserta p = first(P);
    while (p != NULL){
        cout<<" Peserta "<<info(p).nama<<" total nilainya "<<info(p).nilai<<endl;
        address_juri j = first(J);
        while (j != NULL){
            if (searchRelasi(R,info(j).uname, info(p).nama) != NULL){
                cout<<"  Juri "<<info(j).uname<<" memberi nilai "<<info(searchRelasi(R,info(j).uname, info(p).nama))<<endl;
            }
            j = next(j);
        }
        p = next(p);
    }
}
void detail_penilaian(list_peserta P, list_relasi R, list_juri J){
    address_juri j = first(J);
    while (j != NULL){
        cout<<" Juri "<<info(j).uname<<" memberi : "<<endl;
        address_peserta p = first(P);
        while (p != NULL){
            if (searchRelasi(R,info(j).uname, info(p).nama) != NULL){
                cout<<"  Peserta "<<info(p).nama<<" nilai "<<info(searchRelasi(R,info(j).uname, info(p).nama))<<endl;
            }
            p = next(p);
        }
        j = next(j);
    }
}
void input_nilai(list_relasi &R, list_peserta &P, list_juri J, address_juri j){
    int pil;
    cout << "\n\nInput nilai :\n";
    cout << "   [1] Beri nilai\n";
    cout << "   [2] Ubah nilai\n";
    cout << "   [3] Kembali ke menu juri\n";
    cout << "Masukkan pilihan Anda: ";
    cin >> pil;
    while (pil!=1 && pil!=2 && pil!=3){
        cout << "Input tidak valid. Tolong masukkan pilihan Anda kembali.\n";
        cout << "Masukkan pilihan Anda: ";
        cin >> pil;
    }
    if (pil==1){
        beri_nilai(R, P,j);
        input_nilai(R,P,J,j);
    } else if (pil==2){
        ubah_nilai(R, P,j);
        input_nilai(R,P,J,j);
    }
}

void beri_nilai(list_relasi &R, list_peserta &P, address_juri j){
    string peserta;
    float nilai;
    cout<<"Masukkan nama peserta yang ingin dinilai : ";
    cin>>peserta;
    address_peserta p = searchPeserta(P, peserta);
    address_relasi r = searchRelasi(R, info(j).uname, peserta);
    if (r != NULL){
       cout<<"Peserta sudah Anda nilai.\nMengembalikan ke menu juri...\n";
    } else if (p != NULL){
        cout<<"Masukkan nilai : ";
        cin>>nilai;
        address_relasi r;
        createElm_relasi(nilai, j, p, r);
        insert_Relasi(R, r);
    } else if (p == NULL) {
        cout<<"Nama peserta tidak ditemukan.\nMengembalikan ke menu juri...\n";
    }
}
void ubah_nilai(list_relasi &R, list_peserta &P, address_juri j) {
    string peserta;
    float nilai;
    cout<<"Masukkan nama peserta yang ingin diubah nilainya : ";
    cin>>peserta;
    address_peserta p = searchPeserta(P, peserta);
    if (p != NULL){
        address_relasi r = searchRelasi(R, info(j).uname, peserta);
        if (r != NULL){
            cout<<"Masukkan nilai baru : ";
            cin>>nilai;
            KurangNilai(p, info(p).nilai);
            TambahNilai(p, nilai);
            info(r) = nilai;
        } else {
            cout<<"Peserta belum pernah Anda nilai.\nMengembalikan ke menu juri...\n";
        }
    } else {
        cout<<"Nama peserta tidak ditemukan.\nMengembalikan ke menu juri...\n";
    }
}

void view_peserta_sudah_dinilai(list_relasi &R, list_peserta &P, address_juri j){
    address_relasi p = first(R);
    int i = 0;
    if (search_juri_diRelasi(R, info(j).uname) == NULL){
        cout<<"Anda belum menilai semua peserta"<<endl;
    } else {
        cout<<"Anda sudah menilai :"<<endl;
        if (info(p->juri).uname == info(j).uname){
            cout<<"1). "<<info(p->peserta).nama<<" dengan nilai "<<info(p)<<endl;
        }
        p = next(p);
        while(p != first(R)) {
            if (info(p->juri).uname == info(j).uname){
                i = i + 1;
                cout<<"["<<i<<"] "<<info(p->peserta).nama<<" dengan nilai "<<info(p)<<endl;
            }
            p = next(p);
        }
    }
}
void view_peserta_belum_dinilai(list_relasi &R, list_peserta &P, address_juri j){
    address_peserta p = first(P);
    int i = 0;
    cout<<"Anda belum menilai : "<<endl;
    while (p != NULL){
        if (searchRelasi(R,info(j).uname, info(p).nama) == NULL){
            i = i + 1;
            cout<<"["<<i<<"] "<<info(p).nama<<endl;
        }
        p = next(p);
    }
    if (i == 0){
        cout<<"Tidak ada peserta yang belum Anda nilai, Anda sudah menilai semua peserta."<<endl;
    }
}
void hapus_nilai(list_relasi &R, list_peserta &P, list_juri J, address_juri j){
    string peserta;
    cout<<"Masukkan nama peserta yang ingin dihapus nilainya: ";
    cin>>peserta;
    address_peserta p = searchPeserta(P, peserta);
    if (p != NULL){
        address_relasi r = searchRelasi(R, info(j).uname, peserta);
        if (r != NULL){
            address_relasi x;
            delete_elm_Relasi(J, P, R, x, info(j).uname, peserta);
            KurangNilai(p, info(x));
        } else {
            cout<<"Peserta belum pernah Anda nilai.\nMengembalikan ke menu juri...\n";
        }
    } else {
        cout<<"Nama peserta tidak ditemukan.\nMengembalikan ke menu juri...\n";
    }
}





