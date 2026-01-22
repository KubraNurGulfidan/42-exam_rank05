# Proje Hakkında (TR)
Bu repository, 42 Exam Rank 05 seviyesindeki sınav projelerinin kapsamlı çözümlerini içerir. Bu aşama, hem C++ ile Nesne Yönelimli Programlama (OOP) mimarisini hem de C dili ile karmaşık veri yapıları ve algoritmaları (Dinamik Programlama, Simülasyon) çözme yeteneğini ölçmektedir.

## Öne Çıkan Projeler ve Kazanımlar1.
### BigInt (C++)
- SIZE_MAX değerinden büyük sayıları herhangi bir hassasiyet kaybı olmadan işleyebilen bir sınıf.
- Operatör Aşırı Yükleme: +, +=, <<, >>, ++, -- ve tüm karşılaştırma operatörlerinin implementasyonu.
- Digitshift: Sayıyı 10 tabanında kaydıran (<< n ile 10^n ile çarpma gibi) özel lojik.
### Vect2 (C++)
- 2D matematiksel vektör sınıfı.
- Skaler Çarpım: Vektörün bir skaler ile çarpılması ve toplama/çıkarma işlemleri.
- Array Access: [] operatörü ile bileşenlere erişim ve << ile formatlı çıktı.
### PolySet (C++)
- Bu proje, soyut sınıflar ve kalıtım hiyerarşisi kullanılarak bir "Set" (Küme) yapısının nasıl inşa edileceğini gösterir.
- Kalıtım (Inheritance): array_bag ve tree_bag sınıflarından miras alan, arama özellikli searchable_array_bag ve searchable_tree_bag sınıflarının implementasyonu.
- Wrapper Design Pattern: set sınıfının, herhangi bir searchable_bag nesnesini sarmalayarak küme (benzersiz eleman) kurallarını uygulaması.
- Veri Yapıları: İkili Arama Ağacı (Binary Search Tree) ve Diziler (Array) üzerinde polimorfik operasyonlar.
## Life (C)
- Conway'in "Game of Life" simülasyonunun standart girdi üzerinden komutlarla yönetilen versiyonu.
- Pen Logic: w, a, s, d ve x komutlarıyla başlangıç haritasını çizme algoritması.
- Simulation: Iterasyon bazlı hücre yaşam döngüsü kuralları.
### BSQ - Biggest Square (C)
- Engellerle dolu bir harita üzerinde bulunabilecek en büyük boş kareyi bulma algoritması.
- Dinamik Programlama: $O(n \times m)$ karmaşıklığında en büyük kareyi tespit etme.
- Parsing: Harita formatını doğrulama ve hata yönetimi (map error).

## Sınav Başarısı ve Durum
- Vect2: 42 Sınavı sırasında test edilmiş ve başarıyla geçmiştir. (22.08.2025)
- Life: 42 Sınavı sırasında test edilmiş ve başarıyla geçmiştir. (05.09.2025)
- BigInt & Polyset & BSQ: Bu çözümler sınav hazırlık aşamasında geliştirilmiş olup, mantıksal olarak doğrulanmıştır ancak resmi sınav ortamında henüz denenmemiştir.

---

# About the Project (EN)
This repository contains comprehensive solutions for 42 Exam Rank 05. This stage evaluates both Object-Oriented Programming (OOP) in C++ and advanced algorithm design (Dynamic Programming, Simulations) in C.

## Project Breakdown
### BigInt: 
- An arbitrary precision unsigned integer class that handles numbers larger than SIZE_MAX.
- Supports addition, full comparison operators, and base-10 digit shifting.
### Vect2: 
 - A 2 dimension mathematical vector class with operator overloading for scalar multiplication, addition, and formatted output.
### PolySet
- Advanced Inheritance & Abstraction: Implements a set structure using multiple inheritance and polymorphic operations across Arrays and Binary Search Trees.
- Wrapper Design Pattern: Utilizes a wrapper class to enforce element uniqueness while adhering strictly to the Orthodox Canonical Form.
### Life: 
- A C implementation of the "Game of Life".
- It features a unique pen-based drawing system (wasd and x commands) for initial configurations.
### BSQ: 
- A high-performance algorithm to find the largest square in a given map while avoiding obstacles, optimized using dynamic programming.

## Exam Status & Success
- Vect2: Tested and successfully passed during the 42 Exam. (2025.08.22)
- Life: Tested and successfully passed during the 42 Exam. (2025.09.05)
- BigInt & Polyset & BSQ: These solutions were developed during the preparation phase and have been logically verified, but they have not yet been tested in an official exam environment.
