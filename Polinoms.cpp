#include <iostream>
#include <string>
#include "Polinom.h"

int main()
{
    setlocale(LC_ALL, "ru");
    try
    {
        std::string v = "yes";

        while (v == "yes")
        {
            int n = 0;
            std::cout << "Введите 1 для сложения двух полиномов" << std::endl;
            std::cout << "Введите 2 для вычисления разности двух полиномов" << std::endl;
            std::cout << "Введите 3 для вычисления произведения двух полиномов" << std::endl;

            do
            {
                std::cin >> n;
            } while (n != 1 && n != 2 && n != 3);

            Polinom<int> pol1, pol2;

            std::cout << "Введите коэффициент, а затем степень (трёхзначное число)" << std::endl;
            std::cout << "Если вы хотите закончить ввод полинома, то введите любую букву" << std::endl;

            bool isd = true;

            while (isd == true)
            {
                int coef = 0, degree = 0;
                char strC[256], * p = strC;
                std::cin >> strC;
                while (*p)
                    if (!isdigit(*p++))
                    {
                        isd = false;
                        break;
                    }
                if (isd)
                    coef = atoi(strC);
                else
                    break;

                char strD[256], * pD = strD;
                std::cin >> strD;
                while (*pD)
                    if (!isdigit(*pD++))
                    {
                        isd = false;
                        break;
                    }
                if (isd)
                    degree = atoi(strD);
                else
                    break;

                if (degree >= 0 && degree <= 999)
                {
                    pol1.push_back(coef, degree);
                }
                else
                {
                    throw "Invalid values";
                }
            }

            std::cout << "Введите коэффициент, а затем степень (трёхзначное число)" << std::endl;
            std::cout << "Если вы хотите закончить ввод полинома, то введите любую букву" << std::endl;

            isd = true;
            while (isd == true)
            {
                int coef = 0, degree = 0;
                char strC[256], * p = strC;
                std::cin >> strC;
                while (*p)
                    if (!isdigit(*p++))
                    {
                        isd = false;
                        break;
                    }
                if (isd)
                    coef = atoi(strC);
                else
                    break;

                char strD[256], * pD = strD;
                std::cin >> strD;
                while (*pD)
                    if (!isdigit(*pD++))
                    {
                        isd = false;
                        break;
                    }
                if (isd)
                    degree = atoi(strD);
                else
                    break;

                if (degree >= 0 && degree <= 999)
                {
                    pol2.push_back(coef, degree);
                }
                else
                {
                    throw "Invalid values";
                }
            }

            Polinom<int> result;

            CompressionPolinom(pol1);
            RemoveZeros(pol1);
            CompressionPolinom(pol2);
            RemoveZeros(pol2);

            switch (n)
            {
            case 1:
                MergePolinoms(pol1, pol2, result);
                result.Show();
                break;
            case 2:
                SubtractPolinoms(pol1, pol2, result);
                result.Show();
                break;
            case 3:
                MultiplyPolinoms(pol1, pol2, result);
                result.Show();
                break;
            }


            std::cout << "Хотите ли вы повторить вычисления? (yes/no)" << std::endl;

            std::cin.get();

            std::cin >> v;
        }
    }
    catch (char* er) {
        std::cout << er << std::endl;
    }

    return 0;
}