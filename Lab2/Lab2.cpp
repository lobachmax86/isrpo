#include <iostream>
#include <cctype>
#include <cwctype>
#include <windows.h>

// ansi
void mystrlwr(char* s) {
    for (; *s; s++) *s = std::tolower((unsigned char)*s);
}

char* mystrrchr(const char* s, int ch) {
    const char* last = nullptr;
    for (; *s; s++) if (*s == ch) last = s;
    return (char*)last;
}

BOOL isstringsame(const char* a, const char* b) {
    for (; *a && *b; a++, b++)
        if (std::tolower((unsigned char)*a) != std::tolower((unsigned char)*b))
            return FALSE;
    return (*a == '\0' && *b == '\0');
}

//unicode
void mystrlwr(wchar_t* s) {
    for (; *s; s++) *s = std::towlower(*s);
}

wchar_t* mystrrchr(const wchar_t* s, wchar_t ch) {
    const wchar_t* last = nullptr;
    for (; *s; s++) if (*s == ch) last = s;
    return (wchar_t*)last;
}

BOOL isstringsame(const wchar_t* a, const wchar_t* b) {
    for (; *a && *b; a++, b++)
        if (std::towlower(*a) != std::towlower(*b))
            return FALSE;
    return (*a == L'\0' && *b == L'\0');
}

int main() {
    setlocale(LC_ALL, "RUSSIAN");


    std::cout << "ANSI\n\n";

    char str1[50] = "HeLLo WoRLD";
    std::cout << "Исходная строка: " << str1 << "\n";
    mystrlwr(str1);
    std::cout << "После mystrlwr:   " << str1 << "\n\n";

    const char* path = "C:/folder/subfolder/file.txt";
    std::cout << "Строка пути: " << path << "\n";
    char* last = mystrrchr(path, '/');
    std::cout << "Последний '/': " << (last ? last : "не найден") << "\n\n";

    std::cout << "Сравнение \"Hello\" и \"heLLo\": "
        << (isstringsame("Hello", "heLLo") ? "совпадают" : "разные") << "\n";
    std::cout << "Сравнение \"ABC\" и \"ABD\": "
        << (isstringsame("ABC", "ABD") ? "совпадают" : "разные") << "\n\n";


    std::wcout << L"\nUNICODE\n\n";

    wchar_t wstr1[50] = L"HeLLo WoRLD";
    std::wcout << L"Исходная строка: " << wstr1 << L"\n";
    mystrlwr(wstr1);
    std::wcout << L"После mystrlwr:   " << wstr1 << L"\n\n";

    const wchar_t* wpath = L"C:/folder/subfolder/file.txt";
    std::wcout << L"Строка пути: " << wpath << L"\n";
    wchar_t* wlast = mystrrchr(wpath, L'/');
    std::wcout << L"Последний '/': " << (wlast ? wlast : L"не найден") << L"\n\n";

    std::wcout << L"Сравнение \"Hello\" и \"heLLo\": "
        << (isstringsame(L"Hello", L"heLLo") ? L"совпадают" : L"разные") << L"\n";
    std::wcout << L"Сравнение \"ABC\" и \"ABD\": "
        << (isstringsame(L"ABC", L"ABD") ? L"совпадают" : L"разные") << L"\n";

    return 0;
}