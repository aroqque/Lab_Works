#include "Header.h"
int count_words(const string& str) // считаем кол-во слов
{
    int count = 0;

    bool word = false;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == ' ')
        {
            if (word)
                count++;

            word = false;
        }
        else
            word = true;
    }
    //обработать конец строки
    if (word)
        count++;

    return count;
}


int stretch(string& output, const string& input, const int target_size)
{
    int istr_size = input.size();
    if (istr_size < target_size) // case 1 check
    {
        const int quant_words = count_words(input);
        if (quant_words > 1) // case 2 check
        {
            int quant_AddSpaces = target_size - istr_size; // сколько пробелов добавлять
            int SpacBetweenTwoW = quant_AddSpaces / (quant_words - 1); // считаем сколько пробелов между каждыми словами поравну (-1 ибо после последнего слова не нужно)
            int remainder = quant_AddSpaces - SpacBetweenTwoW * (quant_words - 1); // высчитаем остаток чтобы дополнять там где не удается поровну посчитать 

            bool word = false;
            for (int i = 0; i < istr_size; i++) //реализация заполнения пробелами
            {
                output += input[i];
                if (input[i] == ' ')
                {
                    if (word)
                    {
                        int add = 0;
                        if (remainder > 0) // проверка остатка и реализация его добавления
                        {
                            add = 1;
                            remainder--;
                        }
                        output.insert(output.size(), SpacBetweenTwoW + add, ' ');
                    }

                    word = false;
                }
                else
                    word = true;
            }
        }
        else
            return 2;
    }
    else
        return 1;

    return 0;
}