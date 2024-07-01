/****************************************************************************
**					SAKARYA ÜNİVERSİTESİ
**			         BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				    BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				          PROGRAMLAMAYA GİRİŞİ DERSİ
**
**				ÖDEV NUMARASI: Proje
**				ÖĞRENCİ ADI: Ahmet Tarık Türkmen
**				ÖĞRENCİ NUMARASI: G221210087
**				DERS GRUBU: 2.Öğretim C Grubu
****************************************************************************/


#include <iostream>
#include <fstream>
#include <locale.h>
#include <string>
#include <iomanip>

using namespace std;

class Futbolcu {
public:
    string tcNo;
    string FutbolcuAdi;
    string FutbolcuSoyadi;
    int lisansNo, takimNo;
    string konumu;
    double ucret;
    string dogumTarihi;
    string tcDenetleme;

    void futbolcuEkle()
    {
        ofstream FutbolcuDosyaYaz;
        FutbolcuDosyaYaz.open("Futbolcu.txt", ios::app);
        //Dosya açılamazsa hata yazdırır.
        if (!FutbolcuDosyaYaz.is_open())
        {
            cout << "Dosya açma hatası!" << endl;
            return;
        }

        cout << "Futbolcu Tc No: ";
        cin >> tcNo;

        cout << "Futbolcu Adı: ";
        cin >> FutbolcuAdi;

        cout << "Futbolcu Soyadı: ";
        cin >> FutbolcuSoyadi;

        cout << "Futbolcu Lisans No: ";
        cin >> lisansNo;

        cout << "Oyuncu Konumu: ";
        cin >> konumu;

        cout << "Futbolcu Ücreti[Milyon TL]: ";
        cin >> ucret;

        cout << "Doğum Tarihi(Gün.Ay.Yıl): ";
        cin >> dogumTarihi;

        takimNo = 0; // İlk Başta Kimsenin Takımı Olmadığından Takım Nosunu otomatik 0 olarak ayarlar.

        FutbolcuDosyaYaz << tcNo << setw(20) << FutbolcuAdi << setw(20) << FutbolcuSoyadi << setw(20) << lisansNo << setw(20) << konumu << setw(20) << ucret << setw(20) << dogumTarihi << setw(20) << takimNo << endl;

        FutbolcuDosyaYaz.close();

        cout << endl << tcNo << " TC Numaralı Futbolcu Oluşturuldu" << endl;
        system("pause");

    }

    void futbolcuSil()
    {
        cout << "Silmek İstediğiniz Futbolcu Tc Numarasını Giriniz: ";
        cin >> tcDenetleme;

        ifstream FutbolcuDosyaOku("Futbolcu.txt"); // Bilgi almak için
        //Dosya açılamazsa hata yazdırır.
        if (!FutbolcuDosyaOku.is_open())
        {
            cout << "Dosya açma hatası!" << endl;
            return;
        }

        ofstream GeciciDosyaYaz("Gecici.txt"); // Gecici dosya açtık
        //Dosyadaki tüm satırları sırasıyla okur. 
        while (FutbolcuDosyaOku >> tcNo >> FutbolcuAdi >> FutbolcuSoyadi >> lisansNo >> konumu >> ucret >> dogumTarihi >> takimNo) {
            //Eğer alınan tc ile dosyadaki tc eşitse 'tc silindi' yazdırır.Değilse Gecici dosyaya aynen yazar.
            if (tcDenetleme == tcNo)
            {
                cout << endl << tcDenetleme << " Tc Numaralı Futbolcu Silindi" << endl;
            }
            else
            {
                GeciciDosyaYaz << tcNo << setw(20) << FutbolcuAdi << setw(20) << FutbolcuSoyadi << setw(20) << lisansNo << setw(20) << konumu << setw(20) << ucret << setw(20) << dogumTarihi << setw(20) << takimNo << endl;
            }
        }

        FutbolcuDosyaOku.close();
        GeciciDosyaYaz.close();

        remove("Futbolcu.txt");
        rename("Gecici.txt", "Futbolcu.txt");

        system("pause");
    }

    void futbolcuGuncelle()
    {
        cout << "Güncellemek İstediğiniz Futbolcu Tc Numarasını Giriniz: ";
        cin >> tcDenetleme;

        ifstream FutbolcuDosyaOku("Futbolcu.txt"); // Bilgi almak için
        //Dosya açılamazsa hata yazdırır.
        if (!FutbolcuDosyaOku.is_open())
        {
            cout << "Dosya açma hatası!" << endl;
            return;
        }
        ofstream GeciciDosyaYaz("Gecici.txt"); // Gecici dosya açtık

        //Dosyadaki tüm satırları sırasıyla okur. 
        while (FutbolcuDosyaOku >> tcNo >> FutbolcuAdi >> FutbolcuSoyadi >> lisansNo >> konumu >> ucret >> dogumTarihi >> takimNo)
        {
            //Eğer alınan tc ile dosyadaki tc eşitse Güncellenecek bilgileri alır ve gecici dosyaya yeni bilgileri yazar.Değilse değiştirmeden Gecici dosyaya yazar.
            if (tcDenetleme == tcNo)
            {
                cout << "Güncellemek İstediğiniz Bilgileri Giriniz: " << endl;

                cout << "Futbolcu Tc No: ";
                cin >> tcNo;

                cout << "Futbolcu Adı: ";
                cin >> FutbolcuAdi;

                cout << "Futbolcu Soyadı: ";
                cin >> FutbolcuSoyadi;

                cout << "Futbolcu Lisans No: ";
                cin >> lisansNo;

                cout << "Oyuncu Konumu: ";
                cin >> konumu;

                cout << "Futbolcu Ücreti[Milyon TL]: ";
                cin >> ucret;

                cout << "Doğum Tarihi(Gün.Ay.Yıl): ";
                cin >> dogumTarihi;

                cout << endl << tcDenetleme << " Tc Numaralı Futbolcu Güncellendi" << endl;

                GeciciDosyaYaz << tcNo << setw(20) << FutbolcuAdi << setw(20) << FutbolcuSoyadi << setw(20) << lisansNo << setw(20) << konumu << setw(20) << ucret << setw(20) << dogumTarihi << setw(20) << takimNo << endl;
            }
            else
            {
                GeciciDosyaYaz << tcNo << setw(20) << FutbolcuAdi << setw(20) << FutbolcuSoyadi << setw(20) << lisansNo << setw(20) << konumu << setw(20) << ucret << setw(20) << dogumTarihi << setw(20) << takimNo << endl;
            }
        }

        FutbolcuDosyaOku.close();
        GeciciDosyaYaz.close();

        remove("Futbolcu.txt");
        rename("Gecici.txt", "Futbolcu.txt");

        system("pause");
    }

    void futbolculariListele() {
        ifstream FutbolcuDosyaOku("Futbolcu.txt");  // Büyük harfle açılmalı
        //Dosya açılamazsa hata yazdırır.
        if (!FutbolcuDosyaOku.is_open())
        {
            cout << "Dosya açma hatası!" << endl;
            return;
        }

        cout << setw(70) << "----- FUTBOLCULAR -----" << endl << endl;
        cout << setw(15) << "TC No" << setw(15) << "Adı" << setw(15) << "Soyadı"
            << setw(15) << "Lisans No" << setw(15) << "Konumu"
            << setw(20) << "Ücret[Milyon TL]" << setw(15) << "Doğum Tarihi" << setw(10) << "Takımı" << endl;

        //Dosyadaki tüm satırları sırasıyla okur ve listeler. 
        while (FutbolcuDosyaOku >> tcNo >> FutbolcuAdi >> FutbolcuSoyadi >> lisansNo >> konumu >> ucret >> dogumTarihi >> takimNo)
        {
            cout << setw(15) << tcNo << setw(15) << FutbolcuAdi << setw(15) << FutbolcuSoyadi
                << setw(15) << lisansNo << setw(15) << konumu << setw(15) << fixed << setprecision(2) << ucret
                << setw(18) << dogumTarihi << setw(10) << takimNo << endl;
        }

        FutbolcuDosyaOku.close();
        system("pause");
    }
};

class Takim :public Futbolcu
{
public:
    int tcNo, takimPuani, takimNo, oyuncuSayisi, tcNoDosyadaki, takimNoDosyadaki, takimNoDenetleme;
    int takimSayilari[100] = { 0 }; // 100 takımı geçmeyecek varsayalım
    string takimAdi;
    string adresi;
    string telefon;
    string yoneticiIsmi;

    void takimOlustur()
    {
        ofstream TakımDosyaYaz;
        TakımDosyaYaz.open("Takım.txt", ios::app);
        //Dosya açılamazsa hata yazdırır.
        if (!TakımDosyaYaz.is_open())
        {
            cout << "Dosya açma hatası!" << endl;
            return;
        }

        cout << "Takım Numarası: ";
        cin >> takimNo;

        cout << "Takım Adı: ";
        cin >> takimAdi;

        cout << "Takım Adresi: ";
        cin >> adresi;

        cout << "Takım Telefonu: ";
        cin >> telefon;

        cout << "Yönetici İsmi: ";
        cin >> yoneticiIsmi;

        oyuncuSayisi = 0; // İlk Başta Kimsenin Takımı Olmadığından Takım Nosunu otomatik 0 olarak ayarlar.
        takimPuani = 0;
        TakımDosyaYaz << takimNo << setw(20) << takimAdi << setw(20) << adresi << setw(20) << telefon << setw(20) << oyuncuSayisi << setw(20) << yoneticiIsmi << setw(20) << takimPuani << endl;

        TakımDosyaYaz.close();

        cout << endl << takimNo << " Numaralı Takım Oluşturuldu" << endl;
        system("pause");
    }

    void takimSil()
    {
        cout << "Silmek İstediğiniz Takım Numarasını Giriniz: ";
        cin >> takimNoDenetleme;

        ifstream TakımDosyaOku("Takım.txt"); // Bilgi almak için
        //Dosya açılamazsa hata yazdırır.
        if (!TakımDosyaOku.is_open())
        {
            cout << "Dosya açma hatası!" << endl;
            return;
        }

        ofstream GeciciDosyaYaz("Gecici.txt"); // Gecici dosya açtık

        //Dosyadaki tüm satırları sırasıyla okur. 
        while (TakımDosyaOku >> takimNo >> takimAdi >> adresi >> telefon >> oyuncuSayisi >> yoneticiIsmi >> takimPuani)
        {
            //Eğer alınan takım no ile dosyadaki takım no eşitse 'takım silindi' yazdırır.Değilse Gecici dosyaya aynen yazar.
            if (takimNoDenetleme == takimNo) {
                cout << endl << takimNoDenetleme << " Numaralı Takım Silindi" << endl;
            }
            else {
                GeciciDosyaYaz << takimNo << setw(20) << takimAdi << setw(20) << adresi << setw(20) << telefon << setw(20) << oyuncuSayisi << setw(20) << yoneticiIsmi << setw(20) << takimPuani << endl;
            }
        }

        TakımDosyaOku.close();
        GeciciDosyaYaz.close();

        remove("Takım.txt");
        rename("Gecici.txt", "Takım.txt");

        system("pause");
    }

    void takimaFutbolcuEkle()
    {
        cout << "Futbolcu TC No: ";
        cin >> tcNo;

        cout << "Hangi takıma eklemek istiyorsunuz? Takım No: ";
        cin >> takimNo;

        ifstream FutbolcuDosyaOku("Futbolcu.txt");
        //Dosya açılamazsa hata yazdırır.
        if (!FutbolcuDosyaOku.is_open())
        {
            cout << "Dosya açma hatası!" << endl;
            return;
        }
        ofstream GeciciDosyaYaz("Gecici.txt");

        //Dosyadaki tüm satırları sırasıyla okur. 
        while (FutbolcuDosyaOku >> tcNoDosyadaki >> FutbolcuAdi >> FutbolcuSoyadi >> lisansNo >> konumu >> ucret >> dogumTarihi >> takimNoDosyadaki)
        {
            //Eğer alınan tc ile dosyadaki tc eşitse o oyuncunun takım numarası güncellenir Gecici dosyaya yazılır.Değilse aynen Gecici dosyaya yazılır.
            if (tcNo == tcNoDosyadaki)
            {
                // Futbolcu bulundu, takımı güncelle
                GeciciDosyaYaz << tcNoDosyadaki << setw(20) << FutbolcuAdi << setw(20) << FutbolcuSoyadi
                    << setw(20) << lisansNo << setw(20) << konumu
                    << setw(20) << fixed << setprecision(2) << ucret << setw(20) << dogumTarihi << setw(20) << takimNo << endl;
            }
            else
            {
                // Futbolcu bulunamadı, geçici dosyaya yaz
                GeciciDosyaYaz << tcNoDosyadaki << setw(20) << FutbolcuAdi << setw(20) << FutbolcuSoyadi
                    << setw(20) << lisansNo << setw(20) << konumu
                    << setw(20) << fixed << setprecision(2) << ucret << setw(20) << dogumTarihi << setw(20) << takimNoDosyadaki << endl;
            }
        }

        FutbolcuDosyaOku.close();
        GeciciDosyaYaz.close();

        remove("Futbolcu.txt");
        rename("Gecici.txt", "Futbolcu.txt");

        cout << endl << tcNo << " TC Numaralı Futbolcunun Takımı Güncellendi" << endl;
        system("pause");
    }

    void takimdanFutbolcuSil()
    {

        cout << "Hangi takımdan silmek istiyorsunuz? Takım No: ";
        cin >> takimNo;

        cout << "Silmek istediğiniz futbolcunun TC No'sunu giriniz: ";
        cin >> tcNo;

        ifstream FutbolcuDosyaOku("Futbolcu.txt");
        //Dosya açılamazsa hata yazdırır.
        if (!FutbolcuDosyaOku.is_open())
        {
            cout << "Dosya açma hatası!" << endl;
            return;
        }

        ofstream GeciciDosyaYaz("Gecici.txt");

        //Dosyadaki tüm satırları sırasıyla okur. 
        while (FutbolcuDosyaOku >> tcNoDosyadaki >> FutbolcuAdi >> FutbolcuSoyadi >> lisansNo >> konumu >> ucret >> dogumTarihi >> takimNoDosyadaki)
        {
            //Eğer alınan tc ile dosyadaki tc ve alınan takım no ile dosyadaki takım no eşitse takımı 0 yapılır (takımdan silinir) Gecici dosyaya yazılır.Değilse Gecici dosyaya aynen yazıldı.
            if (tcNo == tcNoDosyadaki && takimNo == takimNoDosyadaki)
            {
                // Futbolcu bulundu ve takımı güncelle (takımNo'yu 0 yap)
                GeciciDosyaYaz << tcNoDosyadaki << setw(20) << FutbolcuAdi << setw(20) << FutbolcuSoyadi
                    << setw(20) << lisansNo << setw(20) << konumu
                    << setw(20) << fixed << setprecision(2) << ucret << setw(20) << dogumTarihi << setw(20) << 0 << endl;
                cout << endl << tcNo << " TC Numaralı Futbolcu, " << takimNo << " Numaralı Takımdan Silindi" << endl;
            }
            else
            {
                // Futbolcu bulunamadı veya takım eşleşmesi olmadı, geçici dosyaya yaz
                GeciciDosyaYaz << tcNoDosyadaki << setw(20) << FutbolcuAdi << setw(20) << FutbolcuSoyadi
                    << setw(20) << lisansNo << setw(20) << konumu
                    << setw(20) << fixed << setprecision(2) << ucret << setw(20) << dogumTarihi << setw(20) << takimNoDosyadaki << endl;
            }
        }

        FutbolcuDosyaOku.close();
        GeciciDosyaYaz.close();

        remove("Futbolcu.txt");
        rename("Gecici.txt", "Futbolcu.txt");

        system("pause");
    }

    void takimBilgileriniGüncelle()
    {
        cout << "Güncellemek İstediğiniz Takım Numarasını Giriniz: ";
        cin >> takimNoDenetleme;

        ifstream TakımDosyaOku("Takım.txt"); // Bilgi almak için
        //Dosya açılamazsa hata yazdırır.
        if (!TakımDosyaOku.is_open())
        {
            cout << "Dosya açma hatası!" << endl;
            return;
        }
        ofstream GeciciDosyaYaz("Gecici.txt"); // Gecici dosya açtık

        //Dosyadaki tüm satırları sırasıyla okur. 
        while (TakımDosyaOku >> takimNo >> takimAdi >> adresi >> telefon >> oyuncuSayisi >> yoneticiIsmi >> takimPuani)
        {
            //Eğer alınan takım no ile dosyadaki eşitse takımla ilgili yeni bilgiler alınır ve Gecici dosyaya yazılır.Değilse takım bilgileri değiştirilmeden aynen Gecici dosyaya yazılır.
            if (takimNoDenetleme == takimNo)
            {
                cout << "Güncellemek İstediğiniz Bilgileri Giriniz: " << endl;
                cout << "Takım Numarası: ";
                cin >> takimNo;

                cout << "Takım Adı: ";
                cin >> takimAdi;

                cout << "Takım Adresi: ";
                cin >> adresi;

                cout << "Takım Telefonu: ";
                cin >> telefon;

                cout << "Yönetici İsmi: ";
                cin >> yoneticiIsmi;

                oyuncuSayisi = 0; // İlk Başta Kimsenin Takımı Olmadığından Takım Nosunu otomatik 0 olarak ayarlar.
                takimPuani = 0;

                cout << endl << takimNoDenetleme << " Numaralı Takım Güncellendi" << endl;

                GeciciDosyaYaz << takimNo << setw(20) << takimAdi << setw(20) << adresi << setw(20) << telefon << setw(20) << oyuncuSayisi << setw(20) << yoneticiIsmi << setw(20) << takimPuani << endl;
            }
            else
            {
                GeciciDosyaYaz << takimNo << setw(20) << takimAdi << setw(20) << adresi << setw(20) << telefon << setw(20) << oyuncuSayisi << setw(20) << yoneticiIsmi << setw(20) << takimPuani << endl;
            }
        }

        TakımDosyaOku.close();
        GeciciDosyaYaz.close();

        remove("Takım.txt");
        rename("Gecici.txt", "Takım.txt");

        system("pause");
    }

    void takimdakiFutbolculariGüncelle()
    {

        cout << "Hangi takımdaki futbolcuyu güncellemek istiyorsunuz? Takım No: ";
        cin >> takimNo;

        cout << "Güncellemek istediğiniz futbolcunun TC No'sunu giriniz: ";
        cin >> tcNo;

        ifstream FutbolcuDosyaOku("Futbolcu.txt");
        //Dosya açılamazsa hata yazdırır.
        if (!FutbolcuDosyaOku.is_open())
        {
            cout << "Dosya açma hatası!" << endl;
            return;
        }

        ofstream GeciciDosyaYaz("Gecici.txt");

        //Dosyadaki tüm satırları sırasıyla okur.
        while (FutbolcuDosyaOku >> tcNoDosyadaki >> FutbolcuAdi >> FutbolcuSoyadi >> lisansNo >> konumu >> ucret >> dogumTarihi >> takimNoDosyadaki)
        {
            //Eğer alınan tc ile dosyadaki ve takım no ile dosyadaki takım no eşitse futbolcucun güncel bilgileri alınır ve Geciciye yazılır.Değilse bir şey değişmeden aynen yazılır.
            if (tcNo == tcNoDosyadaki && takimNo == takimNoDosyadaki)
            {
                cout << "Güncel bilgileri giriniz: " << endl;

                cout << "Futbolcu Lisans No: ";
                cin >> lisansNo;

                cout << "Oyuncu Konumu: ";
                cin >> konumu;

                cout << "Futbolcu Ücreti[Milyon TL]: ";
                cin >> ucret;

                GeciciDosyaYaz << tcNoDosyadaki << setw(20) << FutbolcuAdi << setw(20) << FutbolcuSoyadi << setw(20) << lisansNo << setw(20) << konumu << setw(20) << ucret << setw(20) << dogumTarihi << setw(20) << takimNoDosyadaki << endl;
                cout << endl << tcNoDosyadaki << " TC Numaralı Futbolcu Güncellendi" << endl;
            }
            else
            {
                GeciciDosyaYaz << tcNoDosyadaki << setw(20) << FutbolcuAdi << setw(20) << FutbolcuSoyadi << setw(20) << lisansNo << setw(20) << konumu << setw(20) << ucret << setw(20) << dogumTarihi << setw(20) << takimNoDosyadaki << endl;
            }
        }

        FutbolcuDosyaOku.close();
        GeciciDosyaYaz.close();

        remove("Futbolcu.txt");
        rename("Gecici.txt", "Futbolcu.txt");

        system("pause");
    }

    void takimdakiFutbolculariListele()
    {
        while (true)
        {

            cout << "Takım Numarasını Giriniz: ";
            cin >> takimNo;

            ifstream FutbolcuDosyaOku("Futbolcu.txt");
            //Dosya açılamazsa hata yazdırır.
            if (!FutbolcuDosyaOku.is_open())
            {
                cout << "Dosya açma hatası!" << endl;
                return;
            }

            cout << setw(40) << "----- " << takimNo << " NUMARALI TAKIMDAKİ FUTBOLCULAR -----" << endl;
            cout << setw(15) << "TC No" << setw(15) << "Adı" << setw(15) << "Soyadı"
                << setw(15) << "Lisans No" << setw(15) << "Konumu"
                << setw(20) << "Ücret[Milyon TL]" << setw(15) << "Doğum Tarihi" << setw(10) << "Takımı" << endl;

            //Dosyadaki tüm satırları sırasıyla okur. 
            while (FutbolcuDosyaOku >> tcNoDosyadaki >> FutbolcuAdi >> FutbolcuSoyadi >> lisansNo >> konumu >> ucret >> dogumTarihi >> takimNoDosyadaki)
            {
                //Eğer alınan takım no ile dosyadaki eşitse o takım nosu olan satırı listeler.
                if (takimNo == takimNoDosyadaki)
                {
                    cout << setw(15) << tcNoDosyadaki << setw(15) << FutbolcuAdi << setw(15) << FutbolcuSoyadi
                        << setw(15) << lisansNo << setw(15) << konumu << setw(15) << fixed << setprecision(2) << ucret
                        << setw(18) << dogumTarihi << setw(10) << takimNoDosyadaki << endl;
                }
            }

            FutbolcuDosyaOku.close();

            cout << endl << endl << "Başka bir takımın futbolcularını listelemek ister misiniz? (E/H): ";
            char cevap;
            cin >> cevap;

            if (cevap != 'E' && cevap != 'e')
            {
                break; // E veya e dışında bir şey girildiyse döngüden çık
            }
        }
    }

    void takimlarıListele()
    {


        ifstream FutbolcuDosyaOku("Futbolcu.txt");
        //Dosya açılamazsa hata yazdırır.
        if (!FutbolcuDosyaOku.is_open())
        {
            cout << "Dosya açma hatası!" << endl;
            return;
        }

        /*Futbolcu.txt dosyasını açar ve futbolcuların bilgilerini okur. Her futbolcunun takım numarasını takimSayilari adlı bir dizi içinde ilgili takımın oyuncu sayısını artırır.*/

        while (FutbolcuDosyaOku >> tcNoDosyadaki >> FutbolcuAdi >> FutbolcuSoyadi >> lisansNo >> konumu >> ucret >> dogumTarihi >> takimNoDosyadaki)
        {
            takimSayilari[takimNoDosyadaki]++;
        }

        FutbolcuDosyaOku.close();

        // Takım dosyasını okuyarak her takımın bilgisini yazdır
        ifstream TakımDosyaOku("Takım.txt");
        //Dosya açılamazsa hata yazdırır.
        if (!TakımDosyaOku.is_open())
        {
            cout << "Dosya açma hatası!" << endl;
            return;
        }

        cout << setw(70) << "----- TAKIMLAR -----" << endl << endl;
        cout << setw(15) << "Takım No" << setw(15) << "Takım Adı" << setw(15) << "Adresi"
            << setw(15) << "Telefonu" << setw(15) << "Oyuncu Sayısı"
            << setw(15) << "Yönetici İsmi" << setw(15) << "Takım Puanı" << endl;

        /*Takım.txt dosyasını açar ve takımların genel bilgilerini listeleyerek ekrana yazdırır. Bu sırada, her takımın oyuncu sayısını takimSayilari dizisinden alarak ekrana yazdırır.*/
        while (TakımDosyaOku >> takimNo >> takimAdi >> adresi >> telefon >> oyuncuSayisi >> yoneticiIsmi >> takimPuani)
        {
            cout << setw(15) << takimNo << setw(15) << takimAdi << setw(15) << adresi
                << setw(15) << telefon << setw(15) << takimSayilari[takimNo] << setw(15) << yoneticiIsmi << setw(15) << takimPuani << endl;
        }
        TakımDosyaOku.close();
        system("pause");
    }
};

class Lig :public Takim
{
    int takimNo1, takimNo2;


public:
    void ligİçinTakimdakiFutbolculariListele(int takimNo)
    {
        ifstream FutbolcuDosyaOku("Futbolcu.txt");
        //Dosya açılamazsa hata yazdırır.
        if (!FutbolcuDosyaOku.is_open())
        {
            cout << "Dosya açma hatası!" << endl;
            return;
        }

        cout << setw(40) << "----- " << takimNo << " NUMARALI TAKIMDAKİ FUTBOLCULAR -----" << endl << endl;
        cout << setw(15) << "TC No" << setw(15) << "Adı" << setw(15) << "Soyadı"
            << setw(15) << "Lisans No" << setw(15) << "Konumu"
            << setw(20) << "Ücret[Milyon TL]" << setw(15) << "Doğum Tarihi" << setw(10) << "Takımı" << endl;

        //Dosyadaki tüm satırları sırasıyla okur. 
        while (FutbolcuDosyaOku >> tcNoDosyadaki >> FutbolcuAdi >> FutbolcuSoyadi >> lisansNo >> konumu >> ucret >> dogumTarihi >> takimNoDosyadaki)
        {
            //Eğer alınan takım no ile dosyadaki eşitse o takım nosu olan satırı listeler.
            if (takimNo == takimNoDosyadaki)
            {
                cout << setw(15) << tcNoDosyadaki << setw(15) << FutbolcuAdi << setw(15) << FutbolcuSoyadi
                    << setw(15) << lisansNo << setw(15) << konumu << setw(15) << fixed << setprecision(2) << ucret
                    << setw(18) << dogumTarihi << setw(10) << takimNoDosyadaki << endl;
            }
        }
        FutbolcuDosyaOku.close();
    }

    void macSimulasyonu()
    {
        cout << "Maç yapacak iki takım numarasını giriniz:" << endl;
        cout << "Takım 1: ";
        cin >> takimNo1;
        cout << "Takım 2: ";
        cin >> takimNo2;

        // Takım 1 oyuncularını listeleme

        ligİçinTakimdakiFutbolculariListele(takimNo1);
        cout << endl;
        // Takım 2 oyuncularını listeleme

        ligİçinTakimdakiFutbolculariListele(takimNo2);

        srand(time(0));
        int skorTakim1 = rand() % 6;  // 0 ile 5 arasında random skor üretir.
        int skorTakim2 = rand() % 6;

        cout << "Maç bitti! Sonuç: " << takimNo1 << " " << skorTakim1 << " - " << skorTakim2 << " " << takimNo2 << endl;

        // Kazanan belirleme ve puanları güncelleme
        if (skorTakim1 > skorTakim2)
        {
            // Takım 1 kazandı
            cout << takimNo1 << " NUMARALI TAKIM KAZANDI!" << endl;
            // Takım 1'in puanını artır
            // Dosyadan takım bilgilerini okuma ve güncelleme
            ifstream TakımDosyaOku("Takım.txt");
            ofstream GeciciDosyaYaz("Gecici.txt");
            Takim takim;
            while (TakımDosyaOku >> takim.takimNo >> takim.takimAdi >> takim.adresi >> takim.telefon >> takim.oyuncuSayisi >> takim.yoneticiIsmi >> takim.takimPuani)
            {
                if (takim.takimNo == takimNo1)
                {
                    takim.takimPuani += 3; // Kazanan takımın puanını 3 artır
                }
                GeciciDosyaYaz << takim.takimNo << setw(20) << takim.takimAdi << setw(20) << takim.adresi << setw(20) << takim.telefon << setw(20) << takim.oyuncuSayisi << setw(20) << takim.yoneticiIsmi << setw(20) << takim.takimPuani << endl;
            }
            TakımDosyaOku.close();
            GeciciDosyaYaz.close();
            remove("Takım.txt");
            rename("Gecici.txt", "Takım.txt");
        }
        else if (skorTakim1 < skorTakim2)
        {
            // Takım 2 kazandı
            cout << takimNo2 << " NUMARALI TAKIM KAZANDI!" << endl;
            // Takım 2'nin puanını artır
            // Dosyadan takım bilgilerini okuma ve güncelleme
            ifstream TakımDosyaOku("Takım.txt");
            ofstream GeciciDosyaYaz("Gecici.txt");
            Takim takim;
            while (TakımDosyaOku >> takim.takimNo >> takim.takimAdi >> takim.adresi >> takim.telefon >> takim.oyuncuSayisi >> takim.yoneticiIsmi >> takim.takimPuani)
            {
                if (takim.takimNo == takimNo2)
                {
                    takim.takimPuani += 3; // Kazanan takımın puanını 3 artır
                }
                GeciciDosyaYaz << takim.takimNo << setw(20) << takim.takimAdi << setw(20) << takim.adresi << setw(20) << takim.telefon << setw(20) << takim.oyuncuSayisi << setw(20) << takim.yoneticiIsmi << setw(20) << takim.takimPuani << endl;
            }
            TakımDosyaOku.close();
            GeciciDosyaYaz.close();
            remove("Takım.txt");
            rename("Gecici.txt", "Takım.txt");
        }
        else
        {
            // Berabere
            cout << "MAÇ BERABERE BİTTİ!" << endl;
            // Beraberlik durumunda her iki takımın puanını 1 artır
            // Dosyadan takım bilgilerini okuma ve güncelleme
            ifstream TakımDosyaOku("Takım.txt");
            ofstream GeciciDosyaYaz("Gecici.txt");
            Takim takim;
            while (TakımDosyaOku >> takim.takimNo >> takim.takimAdi >> takim.adresi >> takim.telefon >> takim.oyuncuSayisi >> takim.yoneticiIsmi >> takim.takimPuani)
            {
                if (takim.takimNo == takimNo1 || takim.takimNo == takimNo2)
                {
                    takim.takimPuani += 1; // Beraberlik durumunda her iki takımın puanını 1 artır
                }
                GeciciDosyaYaz << takim.takimNo << setw(20) << takim.takimAdi << setw(20) << takim.adresi << setw(20) << takim.telefon << setw(20) << takim.oyuncuSayisi << setw(20) << takim.yoneticiIsmi << setw(20) << takim.takimPuani << endl;
            }
            TakımDosyaOku.close();
            GeciciDosyaYaz.close();
            remove("Takım.txt");
            rename("Gecici.txt", "Takım.txt");
        }
        system("pause");
    }

    void puanDurumuGoster()
    {

        ifstream FutbolcuDosyaOku("Futbolcu.txt");
        ifstream TakımDosyaOku("Takım.txt");
        //Dosya açılamazsa hata yazdırır.
        if (!FutbolcuDosyaOku.is_open() || !TakımDosyaOku.is_open())
        {
            cout << "Dosya açma hatası!" << endl;
            return;
        }

        // Futbolcu.txt dosyasını açar ve futbolcuların bilgilerini okur. Her futbolcunun takım numarasını (takimNoDosyadaki) kullanarak, takimSayilari adlı bir dizi içinde ilgili takımın oyuncu sayısını artırır.
        while (FutbolcuDosyaOku >> tcNoDosyadaki >> FutbolcuAdi >> FutbolcuSoyadi >> lisansNo >> konumu >> ucret >> dogumTarihi >> takimNoDosyadaki)
        {
            takimSayilari[takimNoDosyadaki]++;
        }

        FutbolcuDosyaOku.close();

        cout << setw(70) << "----- PUAN DURUMU -----" << endl << endl;
        cout << setw(15) << "Takım No" << setw(15) << "Takım Adı" << setw(15) << "Oyuncu Sayısı" << setw(15) << " Lig Puanı" << endl;
        // Takım.txt dosyasını açar ve takımların genel bilgilerini listeleyerek ekrana yazdırır. Bu sırada, her takımın oyuncu sayısı takimSayilari dizisinden alınarak kullanılır.
        while (TakımDosyaOku >> takimNoDosyadaki >> takimAdi >> adresi >> telefon >> oyuncuSayisi >> yoneticiIsmi >> takimPuani)
        {
            cout << setw(15) << takimNoDosyadaki << setw(15) << takimAdi << setw(15) << takimSayilari[takimNoDosyadaki] << setw(15) << takimPuani << endl;
        }

        TakımDosyaOku.close();
        system("pause");
    }
};

int main()
{
    setlocale(LC_ALL, "Turkish");
    Takim takim;
    Futbolcu futbolcu;
    Lig lig;

    while (true)
    {
        system("CLS");
        // Ana Menüyü ekrana yazdır
        cout << "----- ANA MENÜ -----" << endl;
        cout << "1- Takım Menüsü" << endl;
        cout << "2- Oyuncu Menüsü" << endl;
        cout << "3- Lig Menüsü" << endl;
        cout << "0- Programdan Çık" << endl;

        int anaSecim;
        cin >> anaSecim;

        switch (anaSecim)
        {
        case 1:

            system("CLS");
            cout << "----- TAKIM MENÜSÜ -----" << endl;
            cout << "1- Takım Oluşturma" << endl;
            cout << "2- Takım Silme" << endl;
            cout << "3- Takım Bilgilerini Güncelle" << endl;
            cout << "4- Takıma futbolcu ekleme" << endl;
            cout << "5- Takımdan futbolcu silme" << endl;
            cout << "6- Takımdaki Bir Futbolcuyu Güncelleme" << endl;
            cout << "7- Takımdaki Futbolcuları Listeleme" << endl;
            cout << "8- Takımları Listeleme" << endl;
            cout << "0- Ana Menüye Dön" << endl;

            int takimSecim;
            cin >> takimSecim;

            switch (takimSecim)
            {
            case 1:
                system("CLS");
                takim.takimOlustur();
                break;
            case 2:
                system("CLS");
                takim.takimSil();
                break;
            case 3:
                system("CLS");
                takim.takimBilgileriniGüncelle();
                break;
            case 4:
                system("CLS");
                takim.takimaFutbolcuEkle();
                break;
            case 5:
                system("CLS");
                takim.takimdanFutbolcuSil();
                break;
            case 6:
                system("CLS");
                takim.takimdakiFutbolculariGüncelle();
                break;
            case 7:
                system("CLS");
                takim.takimdakiFutbolculariListele();
                break;
            case 8:
                system("CLS");
                takim.takimlarıListele();
                break;
            case 0:
                break;
            default:
                cout << "Geçersiz seçim. Tekrar deneyin." << endl;
            }
            break;

        case 2:

            system("CLS");
            cout << "----- OYUNCU MENÜSÜ -----" << endl;
            cout << "1- Oyuncu Ekleme" << endl;
            cout << "2- Oyuncu Silme" << endl;
            cout << "3- Oyuncuları Güncelleme" << endl;
            cout << "4- Oyuncu Listeleme" << endl;
            cout << "0- Ana Menüye Dön" << endl;

            int oyuncuSecim;
            cin >> oyuncuSecim;

            switch (oyuncuSecim)
            {
            case 1:
                system("CLS");
                futbolcu.futbolcuEkle();
                break;
            case 2:
                system("CLS");
                futbolcu.futbolcuSil();
                break;
            case 3:
                system("CLS");
                futbolcu.futbolcuGuncelle();
                break;
            case 4:
                system("CLS");
                futbolcu.futbolculariListele();
                break;
            case 0:
                break;
            default:
                cout << "Geçersiz seçim. Tekrar deneyin." << endl;
            }
            break;

        case 3:
            system("CLS");
            cout << "----- LIG MENÜSÜ -----" << endl;
            cout << "1- Maç Simülasyonu" << endl;
            cout << "2- Puan Durumu Göster" << endl;
            cout << "3- Geri Dön" << endl;

            int ligSecim;
            cin >> ligSecim;

            switch (ligSecim)
            {
            case 1:
                lig.macSimulasyonu();
                break;
            case 2:
                lig.puanDurumuGoster();
                break;
            case 3:
                break;
            default:
                cout << "Geçersiz seçim. Tekrar deneyin." << endl;
            }
            break;

        case 0:
            return 0;
            break;

        default:
            cout << "Geçersiz seçim. Tekrar deneyin." << endl;
        }
    }
    return 0;
}
