#include <stdio.h>
#include <stdio.h>

#define MAX 30

/* ===== FUNGSI REKURSIF ===== */
int faktorial(int n) {
    if (n <= 1)
        return 1;
    return n * faktorial(n - 1);
}

int fibonacci(int n) {
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

/* ===== MENU ===== */
void menu() {
    printf("\n=== MENU UTAMA ===\n");
    printf("1. Tampilkan Data\n");
    printf("2. Tambah Data\n");
    printf("3. Ubah Data\n");
    printf("4. Hapus Data\n");
    printf("5. Olah Nilai\n");
    printf("6. Rekursif\n");
    printf("7. Keluar\n");
    printf("Pilih: ");
}

int main() {
    int nim[MAX];
    float nilai[MAX][3];
    int jumlah = 0;
    int pilih, i, j, cari;

    do {
        menu();
        scanf("%d", &pilih);

        switch (pilih) {

        case 1:
            printf("\nNIM\tTugas\tUTS\tUAS\n");
            for (i = 0; i < jumlah; i++) {
                printf("%d\t%.2f\t%.2f\t%.2f\n",
                       nim[i], nilai[i][0], nilai[i][1], nilai[i][2]);
            }
            break;

        case 2:
            if (jumlah >= MAX) {
                printf("Data penuh!\n");
                break;
            }
            printf("NIM           : ");
            scanf("%d", &nim[jumlah]);
            printf("Nilai Tugas   : ");
            scanf("%f", &nilai[jumlah][0]);
            printf("Nilai UTS     : ");
            scanf("%f", &nilai[jumlah][1]);
            printf("Nilai UAS     : ");
            scanf("%f", &nilai[jumlah][2]);
            jumlah++;
            break;

        case 3:
            printf("Masukkan NIM: ");
            scanf("%d", &cari);
            for (i = 0; i < jumlah; i++) {
                if (nim[i] == cari) {
                    printf("Nilai Tugas baru: ");
                    scanf("%f", &nilai[i][0]);
                    printf("Nilai UTS baru  : ");
                    scanf("%f", &nilai[i][1]);
                    printf("Nilai UAS baru  : ");
                    scanf("%f", &nilai[i][2]);
                    break;
                }
            }
            break;

        case 4:
            printf("Masukkan NIM: ");
            scanf("%d", &cari);
            for (i = 0; i < jumlah; i++) {
                if (nim[i] == cari) {
                    for (j = i; j < jumlah - 1; j++) {
                        nim[j] = nim[j + 1];
                        nilai[j][0] = nilai[j + 1][0];
                        nilai[j][1] = nilai[j + 1][1];
                        nilai[j][2] = nilai[j + 1][2];
                    }
                    jumlah--;
                    printf("Data dihapus\n");
                    break;
                }
            }
            break;

        case 5: {
            float rata, max, min;
            int idxMax = 0, idxMin = 0;

            max = min = (nilai[0][0] + nilai[0][1] + nilai[0][2]) / 3;

            for (i = 0; i < jumlah; i++) {
                rata = (nilai[i][0] + nilai[i][1] + nilai[i][2]) / 3;
                if (rata > max) {
                    max = rata;
                    idxMax = i;
                }
                if (rata < min) {
                    min = rata;
                    idxMin = i;
                }
            }

            printf("Nilai Tertinggi: NIM %d (%.2f)\n", nim[idxMax], max);
            printf("Nilai Terendah : NIM %d (%.2f)\n", nim[idxMin], min);
            break;
        }

        case 6:
            printf("Faktorial (%d) = %d\n", jumlah, faktorial(jumlah));
            printf("Fibonacci: ");
            for (i = 0; i < jumlah; i++)
                printf("%d ", fibonacci(i));
            printf("\n");
            break;

        case 7:
            printf("Program selesai.\n");
            break;

        default:
            printf("Pilihan salah!\n");
        }

    } while (pilih != 7);

    return 0;
}
