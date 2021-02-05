#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream input("INPUT.txt");
    if (!input)
    {
        exit(1);
    }
    int N, K;
    input >> N >> K;
    input.close();
    int place;
    if (N < 10)
    {
        place = K;
    }
    else if (N < 100)
    {
        place = 1;
        if (K >= 10)
        {
           place += K % 10 + 1 + (K / 10 - 1) * 11;
        }
        else
        {
            if (K <= N / 10)
            {
                place += (K - 1) * 11;
            }
            else {
                place += (N / 10 - 1) * 11 + N % 10 + 1 + K - (N / 10);
            }
        }
    }
    else if (N < 1000)
    {
        place = 1;
        if (K >= 100)
        {
            place += K % 10 + 1 + ((K / 10) % 10) * 11 + 1 + (K / 100 - 1) * 111;
        }
        else if (K >= 10)
        {
            if (K <= N / 10)
            {
                place += (K % 10) * 11 + 1 + ((K / 10) % 10 - 1) * 111;
            }
            else {
                place += (N / 100 - 1) * 111 + ((N / 10) % 10) * 11 + 1 + N % 10 + 1 + K - (N / 10) + K / 10 - (N / 100);
            }
        }
        else {
            if (K <= N / 100)
            {
               place += (K - 1) * 111;
            }
            else {
               place += (N / 100 - 1) * 111 + ((N / 10) % 10) * 11 +  1 + N % 10 + K * 10 - (N / 10) + K - (N / 100);
            }
        }
    }
    else
    {
        place = 1;
        if (K == 10000)
        {
            place = 5;
        }
        else if (K >= 1000)
        {
            place += K % 10 + 1 + ((K / 10) % 10) * 11 + 1 + ((K / 100) % 10) * 111 + 1 + (K / 1000 - 1) * 1111;
            if (N == 10000 && K > 1000)
            {
                place++;
            }
        }
        else if (K >= 100)
        {
            if (K <= N / 10)
            {
                place += (K % 10) * 11 + 1 + ((K / 10) % 10) * 111 + 1 + (K / 100 - 1) * 1111;
                if (N == 10000 && K > 100)
                {
                    place++;
                }
            }
            else {
                place += (N / 1000 - 1) * 1111 + ((N / 100) % 10) * 111 + 1 + ((N / 10) % 10) * 11 + 1 + N % 10 + 1 + K - (N / 10)
                + K / 10 - (N / 100) + K / 100 - (N / 1000);

            }
        }
        else if (K >= 10)
        {
           if (K <= N / 100)
           {
               place += (K % 10) * 111 + 1 + (K / 10 - 1) * 1111;
               if (N == 10000 && K > 10)
               {
                   place++;
               }
           }
           else {
                place += (N / 1000 - 1) * 1111 + ((N / 100) % 10) * 111 + 1 + ((N / 10) % 10) * 11 + 1 + N % 10
                + K * 10 - (N / 10) + K - (N / 100) + K / 10 - (N / 1000);
           }
        }
        else {
                if (K <= N / 1000)
                {
                    place += (K - 1) * 1111;
                    if (N == 10000 && K > 1)
                    {
                        place++;
                    }
                }
                else {
                    place += (N / 1000 - 1) * 1111 + ((N / 100) % 10) * 111 + ((N / 10) % 10) * 11 + 1 + N % 10
                    + K * 100 - (N / 10) + K * 10 - (N / 100) + K - (N / 1000);
                }

        }
    }
    ofstream output("OUTPUT.txt");
    if (!output)
    {
        exit(2);
    }
    output << place;
    output.close();

    return 0;
}
