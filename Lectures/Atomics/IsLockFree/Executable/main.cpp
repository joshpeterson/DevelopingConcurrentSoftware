#include <iostream>
#include <atomic>
#include <string>

#define DISPLAY_LOCK_FREE_STATUS(type) display_lock_free_status<type>(#type)

template<typename T>
void display_lock_free_status(std::string type_name)
{
    std::string lock_free_message = std::atomic<T>().is_lock_free() ? "" : " not";
    std::cout << "The type std::atomic<" << type_name << "> is" << lock_free_message << " lock-free.\n";
}

struct LockFreeType
{
    int a;
    int b;
};

struct NotLockFreeType
{
    int a;
    int b;
    int c;
};

int main()
{
    DISPLAY_LOCK_FREE_STATUS(bool);
    DISPLAY_LOCK_FREE_STATUS(char);
    DISPLAY_LOCK_FREE_STATUS(signed char);
    DISPLAY_LOCK_FREE_STATUS(unsigned char);
    DISPLAY_LOCK_FREE_STATUS(int);
    DISPLAY_LOCK_FREE_STATUS(unsigned);
    DISPLAY_LOCK_FREE_STATUS(short);
    DISPLAY_LOCK_FREE_STATUS(unsigned short);
    DISPLAY_LOCK_FREE_STATUS(long);
    DISPLAY_LOCK_FREE_STATUS(unsigned long);
    DISPLAY_LOCK_FREE_STATUS(long long);
    DISPLAY_LOCK_FREE_STATUS(unsigned long long);
    DISPLAY_LOCK_FREE_STATUS(char16_t);
    DISPLAY_LOCK_FREE_STATUS(char32_t);
    DISPLAY_LOCK_FREE_STATUS(wchar_t);
    DISPLAY_LOCK_FREE_STATUS(float);
    DISPLAY_LOCK_FREE_STATUS(double);
    DISPLAY_LOCK_FREE_STATUS(std::string);
    DISPLAY_LOCK_FREE_STATUS(LockFreeType);
    DISPLAY_LOCK_FREE_STATUS(NotLockFreeType);

    std::cout << "Press any key to continue...\n";
    std::getchar();
}