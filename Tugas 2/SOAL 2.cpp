#include <iostream>
using namespace std;

struct Node {
    char nama[100]; // nama (C-string)
    int nilai;      // nilai
    Node *next;     // link ke node berikut
};

void copyStr(char dest[], const char src[]) { // salin string
    int i = 0;
    while (src[i] != '\0' && i < 99) { dest[i] = src[i]; ++i; }
    dest[i] = '\0';
}

void insertSorted(Node **head, const char nama[], int nilai) { // insert ascending by nilai
    Node *baru = new Node;
    copyStr(baru->nama, nama);
    baru->nilai = nilai;
    baru->next = nullptr;

    if (*head == nullptr || (*head)->nilai > nilai) { // jadi head
        baru->next = *head;
        *head = baru;
        return;
    }

    Node *p = *head;
    while (p->next != nullptr && p->next->nilai <= nilai) p = p->next;
    baru->next = p->next;
    p->next = baru;
}

void printList(Node *head) { // tampilkan semua
    if (head == nullptr) { cout << "List kosong.\n"; return; }
    int idx = 1;
    for (Node *p = head; p != nullptr; p = p->next, ++idx)
        cout << idx << ". " << p->nama << " - " << p->nilai << '\n';
}

int main() {
    Node *head = nullptr;
    int pilihan;

    do {
        cout << "\nMenu:\n1. Insert (tersorting)\n2. Tampilkan semua\n0. Keluar\nPilih: ";
        cin >> pilihan; cin.ignore();

        if (pilihan == 1) {
            char nama[100]; int nilai;
            cout << "Masukkan nama: ";
            cin.getline(nama, 100);
            cout << "Masukkan nilai: ";
            cin >> nilai; cin.ignore();

            insertSorted(&head, nama, nilai);
            cout << "Data tersisip.\n";
        } else if (pilihan == 2) {
            printList(head);
        } else if (pilihan == 0) {
            cout << "Selesai.\n";
        } else {
            cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 0);

    return 0;
}
