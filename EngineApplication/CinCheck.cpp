#include "CinCheck.h"
#include <iostream>
#include <conio.h>
#include <string>

using namespace std;
//Функция проверки ввода на наличие символов
string CinCheck(string Name) 
{
    int Value = 0;
    string StringValue;

    while (true)
    {
        cin >> Name;

        //Названия исключений можно посмотреть в сообщениях об ошибке
        try
        {
            Value = stoi(Name);
        }
        catch (std::invalid_argument)
        {
            //Говорим, что можно вводить только числа
            cout << "Возможен ввод только чисел!\n";
        }
        catch (std::out_of_range)
        {
            //Говорим, что число слишком большое
            cout << "Слишком большое число! \n";
        }
        catch (...)
        {
            //Если будет выброшено какое-то исключение, которое не обработано выше, то говорим, что возникла неизвестная ошибка
            cout << "Оказия! \n";
        }

        if (Value > 0)
        {
            //Преобразование числа в строку и возврат её
            StringValue = std::to_string(Value);
            return StringValue;
        }
        else
        {
            cout << "Попробуйте ещё раз! \n";
        }
    }
}
