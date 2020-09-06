#include <iostream>
#include"header1.h"

using namespace std;

int main()
{
    cout << "Copyright Alifya Aisyah & Rayhan Zanzabila\n\n\n";
    list_juri J; list_peserta P; list_relasi R;
    createListJ(J); createListP(P); createListR(R);

    address_peserta p;
    address_juri j;
    address_relasi r;


    createElm_peserta("Dina", p);
    insert_Peserta(P, p);
    createElm_peserta("Indra", p);
    insert_Peserta(P, p);
    createElm_peserta("Andi", p);
    insert_Peserta(P, p);
    createElm_peserta("Indah", p);
    insert_Peserta(P, p);
    createElm_peserta("Raya", p);
    insert_Peserta(P, p);
    createElm_peserta("Doni", p);
    insert_Peserta(P, p);

    createElm_juri("Dewi", "123", j);
    add_Juri(J, j);
    createElm_juri("Ana", "231", j);
    add_Juri(J, j);
    createElm_juri("Fran", "456", j);
    add_Juri(J, j);

    j = searchJuri(J, "Dewi");
    p = searchPeserta(P, "Raya");
    createElm_relasi(62.7, j, p, r);
    insert_Relasi(R, r);
    p = searchPeserta(P, "Indra");
    createElm_relasi(88, j, p, r);
    insert_Relasi(R, r);
    p = searchPeserta(P, "Indah");
    createElm_relasi(51, j, p, r);
    insert_Relasi(R, r);
    p = searchPeserta(P, "Doni");
    createElm_relasi(60.2, j, p, r);
    insert_Relasi(R, r);

    j = searchJuri(J, "Ana");
    p = searchPeserta(P, "Dina");
    createElm_relasi(76, j, p, r);
    insert_Relasi(R, r);
    p = searchPeserta(P, "Indra");
    createElm_relasi(50.5, j, p, r);
    insert_Relasi(R, r);

    j = searchJuri(J, "Fran");
    p = searchPeserta(P, "Andi");
    createElm_relasi(91.5, j, p, r);
    insert_Relasi(R, r);
    p = searchPeserta(P, "Indah");
    createElm_relasi(87.5, j, p, r);
    insert_Relasi(R, r);
    p = searchPeserta(P, "Dina");
    createElm_relasi(82.3, j, p, r);
    insert_Relasi(R, r);
    p = searchPeserta(P, "Raya");
    createElm_relasi(75, j, p, r);
    insert_Relasi(R, r);
    p = searchPeserta(P, "Indra");
    createElm_relasi(64.5, j, p, r);
    insert_Relasi(R, r);
    p = searchPeserta(P, "Doni");
    createElm_relasi(78.3, j, p, r);
    insert_Relasi(R, r);



    cout << endl << "==================================================" << endl;
    cout << "         SELAMAT DATANG DI TALENT CONTEST" << endl;
    cout << "==================================================\n" << endl;
    MainMenu(J, P, R);

    cout << "\n=================================================" << endl;
    cout << "  Terima kasih telah mengunjungi Talent Contest" << endl;
    cout << "       Kami tunggu kedatangannya kembali" << endl;
    cout << "=================================================" << endl;
    return 0;
}
