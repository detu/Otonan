# Otonan
Kalendar saka (terutama Bali) berguna untuk pengingat otonan. Aplikasi ditulis dengan C++ web framework Wt. Artinya dipanggil melalui web browser.
Selain memerlukan library Wt (https://www.webtoolkit.eu/wt), aplikasi ini juga memerlukan library boost (https://www.boost.org/). Aplikasi ini dikembangkan di atas sistem operasi Linux Ubuntu.

Cara menjalankan aplikasi:
./Otonan --docroot . --http-address 0.0.0.0 --http-port 9090 

Lalu buka alamat 0.0.0.0:9090 di web browser.
