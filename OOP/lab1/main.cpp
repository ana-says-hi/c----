#include <iostream>
#include <vector>

using namespace std;

//!a.
bool rel_prim(int a, int b) {
    for (int div = 2; div <= min(a, b); div++)
        if (a % div == 0 and b % div == 0)
            return false;
    return true;
}

/*!
a. Bestimmen Sie die ersten n natürlichen Zahlen (x1, x2, ..., x10) größer als 2 mit der folgenden Eigenschaft:
Alle natürlichen Zahlen kleiner als xi und die mit xi relativ prim sind.
*/
void n_rel_prim(int n, int xi) {
    for (int i = xi - 1; i > 2; i--)
        if (rel_prim(i, xi) and n != 0) {
            n--;
            cout << i << ' ';
        }
    if (n != 0) {
        cout << endl << "Es gibt nicht mehrere Zahlen" << endl;
    }
}

//!Eingabe n_rel_prim
void aufgabe0_a() {
    int xi, n;
    cout << "a. Die Zahlen mussen kleiner als xi sein.\n xi= ";
    cin >> xi;
    cout << "Wie viele Zahlen sollen gezeigt werden?";
    cin >> n;
    n_rel_prim(n, xi);

}

//!b.
bool selbe_ziff(int a, int b) {
    int vek_a[10] = {0};
    int vek_b[10] = {0};

    while (a) {
        vek_a[a % 10]=1;
        a /= 10;
    }

    while (b) {
        vek_b[b % 10]=1;
        b /= 10;
    }

    for (int zif = 0; zif <= 9; zif++)
        if (vek_a[zif]!=vek_b[zif])
            return false;
    return true;
}

/*!
b. Geben Sie die längste zusammenhängende Zahlenvektor so an, dass alle
        aufeinanderfolgenden Elemente dieselben Ziffern enthalten.
*/


void max_folge(int zahlen[], int n) {
    int l_curent = 1, l_max = -1;
    int first_ind = -1, curent_first_ind = 0;

    for (int i = 0; i < n - 1; i++) {
        //clog << i << ' ' << zahlen[i] << "  ->  " <<selbe_ziff(zahlen[i], zahlen[i + 1])<<endl;
        if (selbe_ziff(zahlen[i], zahlen[i + 1])) {
            l_curent++;
        } else {
            if (l_curent > l_max) {
                l_max = l_curent;
                first_ind = curent_first_ind;
            }
            l_curent = 1;
            curent_first_ind = i + 1;
        }
    }
    if (l_curent > l_max) {
        l_max = l_curent;
        first_ind = curent_first_ind;
    }

    for (int i = first_ind; i < (first_ind + l_max); i++)
        cout << zahlen[i] << ' ';
    cout << endl;
    //clog<<mnhv;
}

void aufgabe0_b() {
    int zahlen[101] = {0};

    //! Lesen
    int n;
    cout << "b. Wie viele Zahlen möchten Sie lesen?";
    cin >> n;
    cout << "Die Folge ist gebildet aus:" << endl;
    for (int i = 0; i < n; i++)
        cin >> zahlen[i];

    //!Algorithmus
    max_folge(zahlen, n);
}

int main() {
    std::cout << "Hello, World!" << std::endl;

    aufgabe0_a();
    cout << endl << "----------------" << endl;
    aufgabe0_b();

//    cout << endl;
//    int liste[5] = {11, 13, 1111, 111, 33};
//    max_folge(liste, 5);

    return 0;
}
