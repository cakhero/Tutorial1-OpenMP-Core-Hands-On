# The OpenMP Common Core: A hands on exploration
<br/>Assalamu'alaikum Wr. Wb.

<p align="justify">Dalam repositori ini saya menyajikan kode program perhitungan matematika untuk mengetahui nilai pi ($\pi$) menggunakan bahasa pemrograman C. Terdapat dua jenis kode program yang ditulis, yaitu yang pertama berupa kode program yang diproses secara seri (single thread), dan yang kedua berupa kode program yang diproses secara paralel (multi thread) dengan OpenMP. Tujuannya adalah untuk mengetahui pengaruh directive OpenMP yang diterapkan dalam kode program terhadap durasi waktu eksekusi program di komputer.</p><br/>

## Hasil Uji Eksekusi Kode Program

<p align="justify">Uji eksekusi kode program menggunakan komputer dengan spesifikasi prosesor:</p>

```sh
cakhero@ubuntu:~$ lscpu
...
Architecture : x86_64
CPU(s)       : 4
Model name   : 11th Gen Intel(R) Core(TM) i5-11300H @ 3.10GHz
...
```

<br/><p align="justify">Hasil uji eksekusi kode program pi.c:</p>

```sh
cakhero@ubuntu:~/pi$ gcc -fopenmp pi.c -o pi && time ./pi
pi = 3.141593 in 2.216518 seconds

real    2.22s
user    2.21s
sys     0.01s
cpu     99%
```

<br/><p align="justify">Hasil uji eksekusi kode program pi1.c:</p>

```sh
cakhero@ubuntu:~/pi$ gcc -fopenmp pi1.c -o pi1 && time ./pi1
pi = 3.141593 in 3.407841 seconds

real    3.41s
user    6.70s
sys     0.02s
cpu     197%
```

<br/><p align="justify">Hasil uji eksekusi kode program pi2.c:</p>

```sh
cakhero@ubuntu:~/pi$ gcc -fopenmp pi2.c -o pi2 && time ./pi2
pi = 3.141593 in 1.340447 seconds

real    1.34s
user    2.68s
sys     0.00s
cpu     199%
```

<br/><p align="justify">Hasil uji eksekusi kode program pi3.c:</p>

```sh
cakhero@ubuntu:~/pi$ gcc -fopenmp pi3.c -o pi3 && time ./pi3
pi = 3.141593 in 1.108535 seconds

real    1.11s
user    2.21s
sys     0.00s
cpu     199%
```

<br/><p align="justify">Hasil uji eksekusi kode program pi4.c:</p>

```sh
cakhero@ubuntu:~/pi$ gcc -fopenmp pi4.c -o pi4 && time ./pi4
pi = 3.141593 in 0.604840 seconds

real    0.61s
user    2.39s
sys     0.01s
cpu     395%
```
<br/><p align="justify">Catatan: durasi waktu eksekusi kode program dapat berbeda tergantung performa prosesor komputer.</p><br/>

### Referensi
https://openmpcon.org/wp-content/uploads/openmpcon2017/Tutorial1-OpenMP-Core-Hands-On.pdf
