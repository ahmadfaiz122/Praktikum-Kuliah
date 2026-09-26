# # names = ["a", "b", "c"] 
# # values = [1, 2, 3] 
# # for name, value in zip(names, values): 
# #     print(name, value) 

# # FOR LOOP
# # soal no 3
# mataKuliah = [
#     "Kalkulus", "Pemrograman", "Statistika",
#     "Arsitektur Komputer", "Bahasa Indonesia",
#     "Bahasa Inggris", "Agama", "Pancasila", "Olahraga"
# ]

# for x in mataKuliah:
#     print(x)

# # soal no 4
# for x in range(2, 21, 2):
#     print(x, end=" ")

# # soal no 5
# list1 = [10, 20, 30, 40, 50]

# for x in list1[::-1]:
#     print(x, end=" ")

# while loop
# x = input('Masukkan sembarang angka : ')
# x = int(x)

# while x != 2:
#     x = input('Masukkan sembarang angka : ')
#     x = int(x)
# print(x)

x = input('input angka : ')
x = int(x)

while x % 2 != 0:
    print('GANJIL')
    x = input('input angka : ')
    x = int(x)
print('GENAP')