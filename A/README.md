# Flawless Run Speedrun Prediction

## Deskripsi
Kamu adalah seorang speedrunner yang sangat kompetitif dalam game **"undead-cells"**. Setelah menaklukkan mode hard dan very hard, kini kamu berusaha menaklukkan mode final, yaitu **"inferno"**. Tantangan utama di mode ini adalah memperkirakan jumlah refill potion heal secara efisien untuk menyelesaikan speedrun tanpa meningkatkan durasi waktu secara signifikan.

## Spesifikasi
- **Batas Waktu:** 3 detik
- **Batas Memori:** 256 MB

![Foto](/img-Src/final-boss.png/) <br>
**Foto : You vs The guy she told you not to worry about (final boss)** <br>
## Tujuan
Tugas utama kamu adalah memprediksi waktu refill potion heal yang efisien agar bisa menyelesaikan run dengan waktu minimal.

## Catatan Penting
- Healing potion dapat diisi ulang, tetapi akan meningkatkan waktu yang dibutuhkan untuk menyelesaikan speedrun.
- Tiap area memiliki durasi sebanyak 3 detik untuk refill potion.
- Jika prediksi jumlah refill lebih kecil dari kebutuhan sebenarnya, output akan berupa pesan kesalahan.

![Foto1](/img-Src/refill.png/) <br>
**Foto : Healing potion refill** <br>

Kamu memikirkan macam-macam strategi sebelum melanjutkan ke difficulty ini.<br>
Kemudian kamu berpikir untuk membuat sebuah code untuk memprediksi<br>
jumlah waktu minimum refill heal potion yang dapat kamu gunakan dalam run ini<br>
tanpa compromise waktu/durasi speedrun yang kamu jalani. <br>

## Format Input
1. **n:** Jumlah area
2. **m:** Jumlah jalur
3. **k:** Kapasitas maksimal healing potion yang bisa dibawa
4. **e:** Estimasi awal jumlah refill
5. **a, b:** Area
6. **p:** Jumlah healing potion yang digunakan untuk menyebrangi antar area

### Contoh Format Input
```
4 4 3 10
1 2 3
1 3 3
3 4 3
2 4 3
```

## Format Output
Waktu minimum refill yang efisien atau pesan kesalahan jika estimasi prediksi lebih kecil daripada jumlah hasil kode.

### Contoh Format Output
```
9
```
atau
```
muak gweh, butuh heal lagi
```

## Constraints
- 1 ≦ n, m, k, e ≦ 10
- 1 ≦ a, b, p ≦ 20

## Contoh Kasus
### Sample Input 0
```
4 4 3 10
1 2 3
1 3 3
3 4 3
2 4 3
```
### Sample Output 0
```
9
```
#### Penjelasan
Kapasitas maksimum healing potion adalah 3. Pada tiap area, kita bisa melakukan refill +1 heal potion dengan durasi 3 detik. Untuk mencapai area tujuan (area ke-4), diperlukan 3 kali refill dengan total waktu 9 detik.

### Sample Input 1
```
4 4 3 8
1 2 3
1 3 3
3 4 3
2 4 3
```
### Sample Output 1
```
muak gweh, butuh heal lagi
```
#### Penjelasan
Estimasi awal adalah 8, sedangkan hasil sebenarnya adalah 9. Karena estimasi kurang dari hasil, output adalah pesan kesalahan.

## Hint
- Dijkstra bisa membantu
- Mungkin perlu memodifikasi graph
```
