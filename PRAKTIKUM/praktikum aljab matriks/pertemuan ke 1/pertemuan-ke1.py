# kontrol seleksi if else

# berat_badan = float(input("Masukkan berat badan (kg): "))
# tinggi_badan = float(input("Masukkan tinggi badan (m): "))

# # Menghitung BMI (Rumus: berat / tinggi pangkat 2)
# bmi = berat_badan / (tinggi_badan ** 2)

# # Membulatkan hasil BMI menjadi 2 angka di belakang koma
# bmi_dibulatkan = round(bmi, 2)
# print(f"Nilai BMI Anda adalah: {bmi_dibulatkan}")

# print(2 < 3 and 3 > 1)
# print(2 < 3 or 3 > 1)
# print(2 < 3 or not 3 > 1)
# print(2 < 3 and not 3 > 1)

# nilai = 79
# Mk_Lulus = 0
# Mk_Belum_lulus = 0
# if nilai >= 80 :
#  Mk_Lulus += 1
#  print("Nilai Pemograman Dasar Kamu %d (A)" %(nilai))
#  print("Selamat kamu lulus Pemograman Dasar")
# elif nilai >= 70 :
#  Mk_Lulus += 1
#  print("Nilai Pemograman Dasar Kamu %d (B)" %(nilai))
#  print("Selamat kamu lulus Pemograman Dasar")
# elif nilai >= 60 :
#  Mk_Lulus += 1
#  print("Nilai Pemograman Dasar Kamu %d (C)" %(nilai))
#  print("Selamat kamu lulus Pemograman Dasar")
# else:
#  Mk_Belum_lulus += 1
#  print("Kamu belum lulus, semangat mengulang!")

# suka_pedas = input("Suka pedas (Y/T)? ")
# tanggal_tua = input("Tanggal tua (Y/T)? ")
# if suka_pedas == "Y":
#  if tanggal_tua == "Y":
#  print("Rekomendasi menu: Nasi sambal")
#  else:
#  print("Rekomendasi menu: Nasi rica-rica iga sapi")
#  if tanggal_tua == "Y":
#   print("Rekomendasi menu: Nasi sambal")
#  else:
#   print("Rekomendasi menu: Nasi rica-rica iga sapi")
# else:
#  if tanggal_tua == "Y":
#  print("Rekomendasi menu: Nasi kecap")
#  else:
#  print("Rekomendasi menu: Nasi ayam kecap")

# x = int(input("Masukan angka: \n"))
# while x < 0:
#  print("Masukan angka positif")
#  x = int(input("Masukan angka: \n"))
# print(f"{x}")



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

