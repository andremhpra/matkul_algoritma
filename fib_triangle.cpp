#include <iostream>
#include <math.h>

#define PADDING_CHAR '*'
#define ull unsigned long long

using namespace std;

typedef struct
{
        int incrementing_rows;
        int amount_numbers_in_peak;
} triangle;

void generate_fib(ull fib[], int n)
{
        fib[0] = 0;
        if (n > 1)
                fib[1] = 1;
        if (n > 2)
                fib[2] = 1;
        for (int i = 3; i < n; i++)
        {
                fib[i] = fib[i - 1] + fib[i - 2];
        }
}

/**
 * Berapa banyak digit dalam sebuah angka bulat.
 *
 * @param x angka yang digitnya akan dihitung.
 */
int digits(ull x)
{
        int d = 1;
        while (x >= 10)
        {
                x /= 10;
                d++;
        }
        return d;
}

triangle get_triangle_info(int n)
{
        triangle t = {0, n};

        if (n <= 3)
        {
                t.incrementing_rows = 0;
                t.amount_numbers_in_peak = n;
                return t;
        }

        // bilangan tertinggi `x` dimana `x*x` dibawah atau sama dengan `n`.
        // contonya 1*1 (1), 2*2 (4), 3*3 (9), 4*4 (16).
        int nearest_perfect_square = (int)floor(sqrt(n));

        // jika `n` tidak kuadrat sempurna, maka sisanya akan ditambahkan ke puncak segitiga.
        int remainder = n - (nearest_perfect_square * nearest_perfect_square);

        t.incrementing_rows = nearest_perfect_square - 1;
        t.amount_numbers_in_peak = nearest_perfect_square + remainder;

        return t;
}

// print integer dengan padding di depannya supaya jumlah digitnya minimal `min_digits`.
void print_padded_int(int n, int min_digits)
{
        int num_digits = digits(n);
        for (int i = 0; i < min_digits - num_digits; i++)
        {
                cout << PADDING_CHAR;
        }
        cout << n;
}

int main()
{
        while (true)
        {
                int n;
                cout << "\nN: ";
                cin >> n;
                if (n <= 0)
                        return 0;

                ull fib[1000];
                generate_fib(fib, n);

                // angka yang jumlah digitnya dibawah ini, akan di-padding supaya jumlah digit sama dengan ini.
                int min_digits = digits(fib[n - 1]);

                auto triangle = get_triangle_info(n);
                int fib_index = 0;
                // bagian segitiga yang naik
                for (int i = 1; i <= triangle.incrementing_rows; i++)
                {
                        for (int j = 0; j < i; j++)
                        {
                                print_padded_int(fib[fib_index], min_digits);
                                cout << " ";
                                fib_index++;
                        }
                        cout << "\n";
                }

                // puncak segitiga
                for (int i = 0; i < triangle.amount_numbers_in_peak; i++)
                {
                        print_padded_int(fib[fib_index], min_digits);
                        cout << " ";
                        fib_index++;
                }
                cout << "\n";

                // bagian segitiga yang turun
                for (int i = triangle.incrementing_rows; i > 0; i--)
                {
                        for (int j = 0; j < i; j++)
                        {
                                print_padded_int(fib[fib_index], min_digits);
                                cout << " ";
                                fib_index++;
                        }
                        cout << "\n";
                }
        }

        return 0;
}
