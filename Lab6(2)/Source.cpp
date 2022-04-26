#include "Header.h"
int count_words(const string& str) // ������� ���-�� ����
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
    //���������� ����� ������
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
            int quant_AddSpaces = target_size - istr_size; // ������� �������� ���������
            int SpacBetweenTwoW = quant_AddSpaces / (quant_words - 1); // ������� ������� �������� ����� ������� ������� ������� (-1 ��� ����� ���������� ����� �� �����)
            int remainder = quant_AddSpaces - SpacBetweenTwoW * (quant_words - 1); // ��������� ������� ����� ��������� ��� ��� �� ������� ������� ��������� 

            bool word = false;
            for (int i = 0; i < istr_size; i++) //���������� ���������� ���������
            {
                output += input[i];
                if (input[i] == ' ')
                {
                    if (word)
                    {
                        int add = 0;
                        if (remainder > 0) // �������� ������� � ���������� ��� ����������
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