#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <exception>

using namespace std;


class Matrix{
    public:
        Matrix(int n, int m); // konstruktor dla macierzy niekwadratowej
        Matrix(int n); // kostruktor dla macierzy kwadratowej
        Matrix(string path) noexcept(false) ; // konstruktor dla macierzy z pliku
        void print() noexcept(false); // metoda do wyśweitlania macierzy
        double get(int n, int m) noexcept(false); // metoda pobierająca element (n, m)
        void set(int n, int m, double val) noexcept(false); // metoda do ustawiania wart. elementu (n, m) na val
        int cols(); // metoda zwracająca liczbę kolumn
        int rows(); // metoda zwracająca liczbę wierszy
        Matrix operator+(Matrix &m2)noexcept(false); // metoda dodająca dwie macierze do siebie
        Matrix operator-(Matrix &m2) noexcept(false); // odejmowanie dwóch macierzy
        Matrix operator*(Matrix &m2) noexcept(false); // mnożenie dwóch macierzy
        friend void operator<<(ofstream& file, Matrix &macierz) noexcept(false); // operator wyjścia służący do wypisywania macierzy
        bool operator==( Matrix & m );//porównywanie
        bool operator!=( Matrix & m );
        void operator[](int row_index) noexcept(false); // operator do wypisania wiersza 
        void operator++();
        void operator--();
        void store(string filename, string path) noexcept(false); // zapisywanie do pliku
        ~Matrix(); // destruktor

    private:
        vector<vector<double>>matrix; // wektor dwuwymiarowy
        int row; // liczba wierszy
        int columns; // liczba kolumn
};

#endif