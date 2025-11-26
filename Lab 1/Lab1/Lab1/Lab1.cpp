#include <windows.h>
#include <iostream>
#include <locale>

#define UNLEN 256
#define MAX_COMPUTERNAME_LENGTH 15

int main()
{
    setlocale(LC_ALL, "Russian");
    ULONGLONG ticks = GetTickCount64();
    std::cout << "Система работает уже: " << ticks << " миллисекунд." << std::endl;

    ULONGLONG total_seconds = ticks / 1000;

    ULONGLONG total_minutes = total_seconds / 60;
    ULONGLONG seconds = total_seconds % 60;

    ULONGLONG total_hours = total_minutes / 60;
    ULONGLONG minutes = total_minutes % 60;

    ULONGLONG days = total_hours / 24;
    ULONGLONG hours = total_hours % 24;

    std::cout << "Форматированное время: ";
    std::cout << days << "д. " << hours << "ч. " << minutes << "м. " << seconds 
        << "с. " << std::endl;

    wchar_t computerName[MAX_COMPUTERNAME_LENGTH + 1] = { 0 };
    wchar_t userName[UNLEN + 1] = { 0 };
    DWORD size = MAX_COMPUTERNAME_LENGTH + 1;

    // Получаем данные
    GetComputerNameW(computerName, &size);
    size = UNLEN + 1;
    GetUserNameW(userName, &size);

    // Выводим в консоль
    std::wcout << L"\nИмя компьютера: " << computerName << std::endl;
    std::wcout << L"Имя пользователя: " << userName << std::endl;


    // Получаем текущее системное время
    SYSTEMTIME st;
    GetLocalTime(&st); // Получаем локальное время

    // Форматируем строку с датой и временем
    wchar_t buffer[256];
    swprintf(buffer, sizeof(buffer) / sizeof(buffer[0]),
        L"Текущая дата и время:\n"
        L"%02d.%02d.%04d %02d:%02d:%02d",
        st.wDay, st.wMonth, st.wYear,
        st.wHour, st.wMinute, st.wSecond);

    // Выводим в MessageBox
    MessageBoxW(NULL, buffer, L"Текущее время", MB_OK | MB_ICONINFORMATION);

    return 0;

}

