#include <iostream>
using namespace std;

struct Node {
    char nama[100]; // nama siswa (C-string)
    int nilai;      // nilai siswa
    Node *next;     // pointer ke node berikutnya
};

void copyStr(char dest[], const char src[]) {
    int i = 0;
    while (src[i] != '\0' && i < 99) { // salin karakter
        dest[i] = src[i];
        ++i;
    }
    dest[i] = '\0'; // akhiri string
}

void insertLast(Node **head, const char nama[], int nilai) {
    Node *baru = new Node;       // alokasi node baru
    copyStr(baru->nama, nama);   // isi nama
    baru->nilai = nilai;         // isi nilai
    baru->next = nullptr;        // akhir list

    if (*head == nullptr) {      // jika list kosong
        *head = baru;
    } else {
        Node *p = *head;
        while (p->next != nullptr) p = p->next; // cari akhir
        p->next = baru;        // sambung node baru
    }
}

void printList(Node *head) {
    if (head == nullptr) {      // cek kosong
        cout << "List kosong.\n";
        return;
    }
    cout << "Data siswa:\n";
    int index = 1;
    Node *p = head;
    while (p != nullptr) {      // traversal
        cout << index << ". " << p->nama << " - " << p->nilai << '\n';
        p = p->next;
        ++index;
    }
}

int main() {
    Node *head = nullptr; // awal list
    int pilihan;

    do {
        cout << "\nMenu:\n";
        cout << "1. Tambah data siswa\n";
        cout << "2. Tampilkan semua data\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;
        cin.ignore(); // buang newline

        if (pilihan == 1) {
            char nama[100];
            int nilai;
            cout << "Masukkan nama: ";
            cin.getline(nama, 100); // input nama (max 100 karakter)
            cout << "Masukkan nilai: ";
            cin >> nilai;
            cin.ignore();

            insertLast(&head, nama, nilai); // tambah di akhir
            cout << "Data ditambah.\n";
        } else if (pilihan == 2) {
            printList(head); // tampilkan semua data
        } else if (pilihan == 0) {
            cout << "Selesai.\n";
        } else {
            cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 0);

    return 0;
}
