#include <Matrix/matrix.hpp>

using namespace std;


int main(){

    while(1){
        cout<<"1 - macierz niekwadratowa(zaprezentowane operatory: +  -  *  << )"<<endl;
        cout<<"2 - stworz macierz kwadratowa(zaprezentowane metody get, subtract, multiply, print) "<<endl;
        cout<<"3 - wczytaj macierz z pliku"<<endl;
        cout<<"4 - zakoncz program"<<endl;

        int choice = 0;
        cin >> choice;

        switch(choice){
            case 1: {
                Matrix macierz1(4, 6);
                cout<<"Ustawianie wartosci macierzy: "<<endl;
                for(int i = 0; i < macierz1.rows(); i++){
                    for(int j = 0; j < macierz1.cols(); j++){
                         macierz1.set(i, j, 1);
                     }
                }
                macierz1.print();
                cout<<"Tworze druga macierz"<<endl;
                Matrix m2(4, 6);
                m2.set(1, 1, 3.2);
                m2.set(3, 5, 2);
                m2.set(2, 2, 7);
                m2.print();
                Matrix m_sum_wynik = macierz1 + m2;
                cout<<"Wynik dodawania: m1 + m2 "<<endl;
                m_sum_wynik.print();
                Matrix m_sub_wynik = macierz1 - m2;
                cout<<"Wynik odejmowania: m1 - m2 "<<endl;
                m_sub_wynik.print();
                Matrix dzialania(4);
                dzialania.set(0,0,3);
                dzialania.set(1,3,2);
                dzialania.print();
                Matrix kwadratowa(4);
                kwadratowa.set(3, 1,  2.2);
                kwadratowa.set(0, 0, 8);
                kwadratowa.print();
                Matrix m_mul_wynik = dzialania * kwadratowa;
                cout<<"Wynik mnozenia: m1 * m2 "<<endl;
                m_mul_wynik.print();
                ofstream file;
                file.open("operator", ofstream::out);
                file<<m_mul_wynik;
                cout<<"Zapisano wynik mnozenia w pliku 'operator'"<<endl;
                Matrix fromoperator("operator");
                fromoperator.print();
                break;
                }
            case 2: {
                Matrix kwadratowa(4);
                kwadratowa.print();
                kwadratowa.set(1, 3, 2.2);
                kwadratowa.print();
                cout<<"Pobieranie elementu 1x3"<<endl;
                double element = kwadratowa.get(1, 3);
                cout<<"Element ten to: "<<element<<endl;
                cout<<"Tworzymy macierz która nam posłuży do odejmowania i mnożenia: "<<endl;
                Matrix dzialania(4);
                dzialania.set(0,0,3);
                dzialania.set(1,3,2);
                dzialania.set(3, 3, 2.2);
                dzialania.print();
                cout<<"Wynik odejmowania: "<<endl;
                //kwadratowa.subtract(dzialania).print();
                cout<<"Wynik mnozenia: "<<endl;
                //kwadratowa.multiply(dzialania).print();
                break;
                }
            case 3: {
                cout<<"Wczytanie macierzy z pliku msumfile z katalogu biezacego"<<endl;
                Matrix zpliku("./msumfile"); 
                zpliku.print();
                break;
                }
            case 4: return 0;
            default: {
                cout<<"Brak opcji."<<endl;
                break;
            } 


        }

    }
}
