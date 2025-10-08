#include <iostream>

#include <string>

using namespace std;



void watermark() {

    cout << "=== PROGRAM PENGELOLA NILAI | KELOMPOK 13 SHIFT 2 ===\n";

}



char hurufMutu(double n) {

    if (n >= 85) return 'A';

    else if (n >= 70) return 'B';

    else if (n >= 60) return 'C';

    else if (n >= 50) return 'D';

    return 'E';

}



class Kelas {

private:

    static const int MAX = 50;

    string nama[MAX];

    double nilai[MAX];

    int jumlah = 0;



public:

    void header() {

        cout << "\n--- Data Nilai Siswa ---\n";

    }



    void tambah(string n, double s) {

        if (jumlah >= MAX) {

            cout << "Kapasitas penuh!\n";

            return;

        }

        if (s < 0 || s > 100) {

            cout << "Nilai harus 0..100\n";

            return;

        }

        nama[jumlah]  = n;

        nilai[jumlah] = s;

        jumlah++;

        cout << "Data ditambahkan.\n";

    }



    int banyakData() {

        return jumlah;

    }



    double ambilNilai(int i) {

        if (i < 0 || i >= jumlah) return -1;

        return nilai[i];

    }



    void tampil() {

        if (jumlah == 0) {

            cout << "(Belum ada data)\n";

            return;

        }

        for (int i = 0; i < jumlah; i++) {

            cout << i + 1 << ". " << nama[i]

                 << " -> " << nilai[i]

                 << " (" << hurufMutu(nilai[i]) << ")\n";

        }

    }



    double rataRata() {

        if (jumlah == 0) return 0;

        double sum = 0;

        for (int i = 0; i < jumlah; i++) sum += nilai[i];

        return sum / jumlah;

    }



    double maksimum() {

        if (jumlah == 0) return 0;

        double m = nilai[0];

        for (int i = 1; i < jumlah; i++)

            if (nilai[i] > m) m = nilai[i];

        return m;

    }



    double minimum() {

        if (jumlah == 0) return 0;

        double m = nilai[0];

        for (int i = 1; i < jumlah; i++)

            if (nilai[i] < m) m = nilai[i];

        return m;

    }

};



int main() {

    watermark();



    Kelas k;

    int menu;

    do {

        cout << "\nMenu:\n"

             << "1. Tambah data nilai\n"

             << "2. Tampilkan semua data\n"

             << "3. Lihat ringkasan (rata-rata/maks/min)\n"

             << "0. Keluar\n"

             << "Pilih: ";

        cin >> menu;



        if (cin.fail()) {

            cin.clear();

            cin.ignore(1000, '\n');

            cout << "Input tidak valid.\n";

            continue;

        }



        if (menu == 1) {

            string n; double s;

            cout << "Nama  : ";

            cin.ignore();

            getline(cin, n);

            cout << "Nilai : ";

            cin >> s;

            k.tambah(n, s);

        }

        else if (menu == 2) {

            k.header();

            k.tampil();

            cout << "Total data: " << k.banyakData() << "\n";

        }

        else if (menu == 3) {

            if (k.banyakData() == 0) {

                cout << "Belum ada data.\n";

            } else {

                double r = k.rataRata();

                double mx = k.maksimum();

                double mn = k.minimum();

                cout << "Rata-rata: " << r

                     << " (" << hurufMutu(r) << ")\n";

                cout << "Maksimum : " << mx << "\n";

                cout << "Minimum  : " << mn << "\n";

            }

        }

        else if (menu == 0) {

            cout << "Terima kasih.\n";

        }

        else {

            cout << "Menu tidak dikenal.\n";

        }

    } while (menu != 0);



    return 0;

}
