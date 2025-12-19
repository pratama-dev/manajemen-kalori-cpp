#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void kata(){
    cout << "Selamat datang di Aplikasi Manajemen Kalori Harian"<<endl;
    cout << "Aplikasi ini digunakan untuk mengatur jumlah kalori harian agar kesehatan anda lebih optimal";
    cout << endl;
}

void tampilanMenu(){
    cout << "=======================" << endl;
    cout << " MENU MANAJEMEN KALORI " << endl;
    cout << "=======================" << endl;
    cout << "0. Keluar" << endl;
    cout << "1. Input Data Pengguna" << endl;
    cout << "2. Input Kalori" << endl;
    cout << "3. Perhitungan BMR" << endl;
    cout << "4. Tampilkan Hasil" << endl;
    cout << "=======================" << endl;
    cout << "Masukkan Pilihan Anda (0-4): ";
}

void inputPengguna(double &berat, double &tinggi, int &umur, char &gender, int &aktivitas, int &tujuan){
    
    cout << endl;
    cout << "===================================" << endl;
    cout << "        INPUT DATA PENGGUNA        " << endl;
    cout << "===================================" << endl;
    cout << "Masukkan Berat Badan Anda (kg) : ";
    cin >> berat;
    cout << "Masukkan Tinggi Badan Anda (cm) : ";
    cin >> tinggi;
    cout << "Masukkan Umur Anda (tahun) : ";
    cin >> umur;
    cout << "Masukkan Gender Anda (L/P): ";
    cin >> gender; 
    cout << "Masukkan Aktivitas Anda : " << endl;
    cout << "1. Berat" << endl;
    cout << "2. Sedang" << endl;
    cout << "3. Ringan" << endl;
    cout << "4. Tidak Pernah" << endl;
    cout << "Pilih Aktivitas (1-4): ";
    cin >> aktivitas; 
    cout << "Masukkan Tujuan Anda : " << endl;
    cout << "1. Menurunkan Berat Badan" << endl;
    cout << "2. Menstabilkan Berat Badan" << endl;
    cout << "3. Meningkatkan Berat Badan" << endl;
    cout << "Pilih Tujuan (1-3): ";
    cin >> tujuan;
    cout <<"==================================="<<endl;
    cout <<"Berat Badan Anda adalah " << berat << endl;
    cout << "Tinggi Badan Anda adalah " << tinggi << endl;
    cout << "Umur Anda adalah " << umur << endl;
    cout << "Jenis Kelamin Anda adalah ";
    if (gender =='L' || gender == 'l') {
        cout << "Laki - laki" << endl;
    } else  if (gender == 'P' || gender == 'p') {
        cout << "Perempuan" << endl;
    }
    cout << "Intensitas Aktivitas Anda adalah ";
    if (aktivitas == 1) {
        cout << "Berat" << endl;
    } else if (aktivitas == 2) {
        cout << "Sedang" << endl;
    } else if (aktivitas == 3) {
        cout << "Ringan" << endl;
    } else if (aktivitas == 4) {
        cout << "Tidak Pernah" << endl;
    }
    cout << "Tujuan Perhitungan Kalori Anda adalah ";
    if (tujuan == 1) {
        cout << "Menurunkan Berat Badan" << endl;
    } else if (tujuan == 2) {
        cout << "Menstabilkan Berat Badan" << endl;
    } else if (tujuan == 3) {
        cout << "Meningkatkan Berat Badan" << endl;
    }
}

void inputKalori(vector<double> &kaloriMasuk, double berat){
    if (berat == 0){
        cout << "Silahkan input data anda terlebih dahulu (Menu 1)." << endl;
        return;
    }
    cout << endl;
    cout << "===================================" << endl;
    cout << "        INPUT KALORI HARIAN        " << endl;
    cout << "===================================" << endl;
    int i = 1;
    int kalori;
    cout << "Masukkan jumlah kalori yang Anda konsumsi (masukkan -1 untuk berhenti): ";
    while (true) {
        cout << "Kalori makan ke-" << i << " : ";
        cin >> kalori;
        if (kalori == -1) {
            break;
        }
        kaloriMasuk.push_back(kalori);
        i++;
    }
}

void BMR(double berat,double tinggi,double &kaloriHarian,double &kebutuhanKalori,int umur,int tujuan,char gender,int aktivitas){
    if (berat == 0){
        cout << "Silahkan input data anda terlebih dahulu (Menu 1)." << endl;
        return;
    }

    double bmr = 0;
    cout << endl;
    cout <<"==============================================================="<<endl;
    cout <<"Pada menu ini kami akan menampilkan hasil perhitungan BMR anda "<<endl;
    cout <<"==============================================================="<<endl;
    
    if( gender =='L' || gender == 'l'){
        bmr = (10 * berat) + (6.25 * tinggi) - (5 * umur) + 5;
    } else if (gender == 'P' || gender == 'p'){
        bmr = (10 * berat) + (6.25 * tinggi) - (5 * umur) - 161;
    }
    if (aktivitas == 1) {
        kaloriHarian = bmr * 1.725;
    } else if (aktivitas == 2) {
        kaloriHarian = bmr * 1.55;
    } else if (aktivitas == 3) {
        kaloriHarian = bmr * 1.375;
    } else if (aktivitas == 4) {
        kaloriHarian = bmr * 1.2;
    }

    if (tujuan == 1) {
        kebutuhanKalori = kaloriHarian - 400;
    } else if (tujuan == 2) {
        kebutuhanKalori = kaloriHarian;
    } else if (tujuan == 3) {
        kebutuhanKalori = kaloriHarian + 400;
    }

    cout <<"Jadi kebutuhan kalori harian anda adalah " << kebutuhanKalori <<endl;
    cout <<"==========================================" << endl;
}

void tampilkanhasil(vector<double> &kaloriMasuk, double kebutuhanKalori,int tujuan){
    if (kaloriMasuk.empty()){
        cout << "Silahkan input kalori anda hari ini terlebih dahulu (Menu 2)." << endl;
        return;
    }
    if (kebutuhanKalori == 0.0){
        cout << "Silahkan lakukan perhitungan BMR terlebih dahulu (Menu 3)." << endl;
        return;
    }
    
    double totalkonsumsi = 0;
    for (int jmlkalori : kaloriMasuk){
        totalkonsumsi += jmlkalori;
    }
    double selisih = totalkonsumsi - kebutuhanKalori;
    double bataswajar = kebutuhanKalori * 0.10;
    string namaTujuan;
    if (tujuan == 1){
        namaTujuan = "Menurunkan berat badan";
    } else if (tujuan == 2){
        namaTujuan = "Menstabilkan berat badan";
    } else if (tujuan == 3){
        namaTujuan = "Meningkatkan berat badan";
    }

    cout << endl;
    cout << "===================================" << endl;
    cout << "       Evaluasi Kalori Harian      " << endl;
    cout << "===================================" << endl;
    cout << "Total kalori Anda hari ini: " << totalkonsumsi << " kalori" << endl;
    cout << "Kebutuhan kalori harian Anda:" << kebutuhanKalori << " kalori" << endl;
    cout << "Batas wajar selisih (±10%): " << bataswajar << endl;
    cout << "Evaluasi = ";
    if (selisih >= -bataswajar && selisih <= bataswajar){
        cout << "Kalori Anda sesuai target untuk " << namaTujuan << "." << endl;
    } else if (selisih < -bataswajar){
        cout << "Kalori Anda kurang " << selisih*-1 << " dari target " << namaTujuan << ". Kurangnya kalori dapat menyebabkan terganggunya kesehatan fisik, hormon, hingga mental." << endl;
    } else {
        string saran;
        if (tujuan == 3){
            saran = ", cocok untuk meningkatkan berat badan.";
        } else {
            saran = ", terlalu berlebih dan tidak cocok untuk " + namaTujuan + ". Kalori berlebih dapat menyebabkan penyakit obesitas, stroke, hingga penyakit jantung dan kanker.";
        }

        cout << "Kalori Anda berlebih " << selisih << saran << endl;
    }
}

int main(){
    double tinggi = 0;
    double kaloriHarian = 0;
    double berat = 0;
    double kebutuhanKalori = 0;
    vector<double> kaloriMasuk;
    int umur, tujuan;
    char gender;
    int aktivitas;
    int menu;
    bool keluar=false;
    kata();
    while(keluar==false){
    tampilanMenu();
    cin>>menu;
    
    switch(menu){
        case 0:
            cout << "Terima kasih. Sampai jumpa 👋";
            keluar=true;
            break;
        case 1:
            inputPengguna(berat, tinggi, umur, gender, aktivitas, tujuan);
            break;
        case 2:
            inputKalori(kaloriMasuk, berat);
            break;
        case 3:
            BMR(berat, tinggi, kaloriHarian, kebutuhanKalori, umur, tujuan, gender, aktivitas);
            break;
        case 4:
            tampilkanhasil(kaloriMasuk, kebutuhanKalori, tujuan);
            break;
        default:
            cout<<"Pilihan tidak tersedia, silakan coba lagi."<<endl;
            break;
        }
    }
    return 0;
} 
