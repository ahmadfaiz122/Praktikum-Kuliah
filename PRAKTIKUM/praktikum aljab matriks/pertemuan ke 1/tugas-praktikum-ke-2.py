# Nomor 4
# Tidak terjadi error karena kondisi x == 2 bernilai False, sehingga
# blok else dijalankan dan Python mencoba mencetak y.
# Jika kode ini dijalankan, akan muncul NameError karena y belum didefinisikan.

# Nomor 5
x = 2
if x == 2:
 print(x)
else:
 x += 2

# Output 2 sudah ditampilkan oleh print() di dalam blok if.
# Tidak ada print() tambahan setelah blok if-else.

# # Nomor 6
# angka = float(input("Masukkan sebuah angka: "))
# if angka > 0:
#  print("Positif")
# elif angka < 0:
#  print("Negatif")
# else:
#  print("Nol")

# # Nomor 7
# angka_positif = float(input("Masukkan angka positif: "))
# while angka_positif <= 0:
#  angka_positif = float(input("Input tidak valid. Masukkan angka positif: "))
# print("Nilai absolut:", abs(angka_positif))

# # Nomor 8
# nilai_ujian = float(input("Masukkan nilai ujian (0-100): "))
# if nilai_ujian >= 85:
#  print("A")
# elif nilai_ujian >= 70:
#  print("B")
# elif nilai_ujian >= 60:
#  print("C")
# elif nilai_ujian >= 50:
#  print("D")
# else:
#  print("E")