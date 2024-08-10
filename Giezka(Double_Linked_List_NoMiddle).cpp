#include <iostream>
using namespace std;

// deklarasi double linked list
struct ListTugas {
  string namaTugas;
  int nomorTugas;
  string deadlineTugas;
  ListTugas *sebelumnya;
  ListTugas *selanjutnya;
};

ListTugas *kepala, *ekor, *saat_ini, *nodeBaru, *hapus;

// Buat Double Linked List
void buatDoubleLinkedList(string namaTugas, int nomorTugas, string deadlineTugas) {
  kepala = new ListTugas();
  kepala->namaTugas = namaTugas;
  kepala->nomorTugas = nomorTugas;
  kepala->deadlineTugas = deadlineTugas;
  kepala->sebelumnya = NULL;
  kepala->selanjutnya = NULL;
  ekor = kepala;
}

// hitung Double Linked List
int hitungDoubleLinkedList() {
  if (kepala == NULL) {
    cout << "Double Linked List belum dibuat!!!" << endl;
    return 0;
  } else {
    saat_ini = kepala;
    int jumlah = 0;
    while (saat_ini != NULL) {
      jumlah++;
      saat_ini = saat_ini->selanjutnya;
    }
    return jumlah;
  }
}

// Tambah Awal
void tambahAwal(string namaTugas, int nomorTugas, string deadlineTugas) {
  if (kepala == NULL) {
    cout << "Double Linked List belum dibuat!!!" << endl;
  } else {
    nodeBaru = new ListTugas();
    nodeBaru->namaTugas = namaTugas;
    nodeBaru->nomorTugas = nomorTugas;
    nodeBaru->deadlineTugas = deadlineTugas;
    nodeBaru->sebelumnya = NULL;
    nodeBaru->selanjutnya = kepala;
    kepala->sebelumnya = nodeBaru;
    kepala = nodeBaru;
  }
}

// Tambah Akhir
void tambahAkhir(string namaTugas, int nomorTugas, string deadlineTugas) {
  if (kepala == NULL) {
    cout << "Double Linked List belum dibuat!!!" << endl;
  } else {
    nodeBaru = new ListTugas();
    nodeBaru->namaTugas = namaTugas;
    nodeBaru->nomorTugas = nomorTugas;
    nodeBaru->deadlineTugas = deadlineTugas;
    nodeBaru->sebelumnya = ekor;
    nodeBaru->selanjutnya = NULL;
    ekor->selanjutnya = nodeBaru;
    ekor = nodeBaru;
  }
}

// hapus Awal
void hapusAwal() {
  if (kepala == NULL) {
    cout << "Double Linked List belum dibuat!!!" << endl;
  } else {
    hapus = kepala;
    kepala = kepala->selanjutnya;
    if (kepala != NULL) {
      kepala->sebelumnya = NULL;
    }
    delete hapus;
  }
}

// hapus Akhir
void hapusAkhir() {
  if (kepala == NULL) {
    cout << "Double Linked List belum dibuat!!!" << endl;
  } else {
    hapus = ekor;
    ekor = ekor->sebelumnya;
    if (ekor != NULL) {
      ekor->selanjutnya = NULL;
    }
    delete hapus;
  }
}

// Ubah Data di Posisi Pertama
void changeFirst(string namaTugas, int nomorTugas, string deadlineTugas) {
  if (kepala == NULL) {
    cout << "Double Linked List belum dibuat!!!" << endl;
  } else {
    kepala->namaTugas = namaTugas;
    kepala->nomorTugas = nomorTugas;
    kepala->deadlineTugas = deadlineTugas;
  }
}

// Ubah Data di Posisi Terakhir
void changeLast(string namaTugas, int nomorTugas, string deadlineTugas) {
  if (kepala == NULL) {
    cout << "Double Linked List belum dibuat!!!" << endl;
  } else {
    ekor->namaTugas = namaTugas;
    ekor->nomorTugas = nomorTugas;
    ekor->deadlineTugas = deadlineTugas;
  }
}

// Cetak Double Linked List
void cetakDoubleLinkedList() {
  if (kepala == NULL) {
    cout << "Double Linked List belum dibuat!!!" << endl;
  } else {
    cout << "Jumlah Data : " << hitungDoubleLinkedList() << endl;
    cout << "Isi Data : " << endl;
    saat_ini = kepala;
    while (saat_ini != NULL) {
      cout << "Nama Tugas: " << saat_ini->namaTugas << endl;
      cout << "Nomor Tugas: " << saat_ini->nomorTugas << endl;
      cout << "Deadline Tugas: " << saat_ini->deadlineTugas << "\n" << endl;
      saat_ini = saat_ini->selanjutnya;
    }
  }
}

int main() {
  buatDoubleLinkedList("Tugas Matematika", 1, "2024-06-01");
  cetakDoubleLinkedList();

  tambahAwal("Tugas Fisika", 2, "2024-06-02");
  cetakDoubleLinkedList();

  tambahAkhir("Tugas Kimia", 3, "2024-06-03");
  cetakDoubleLinkedList();

  changeFirst("Tugas Sejarah", 1, "2024-06-05");
  cetakDoubleLinkedList();

  changeLast("Tugas Seni", 3, "2024-06-07");
  cetakDoubleLinkedList();

  hapusAwal();
  cetakDoubleLinkedList();

  hapusAkhir();
  cetakDoubleLinkedList();
}