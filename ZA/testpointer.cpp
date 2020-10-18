/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :testpointer.cpp
 * @Created Time:2020-04-13 23:08:56
 * @E-mail      :lwftx@outlook.com
 * @GitHub      :https://github.com/vimday
 */
#include <bits/stdc++.h>
using namespace std;
void debug() {
#ifdef LOCAL
    freopen("E:\\Cpp\\in.txt", "r", stdin);
    freopen("E:\\Cpp\\out.txt", "w", stdout);
#endif
}

// char* p = "hello";虽然赋给一个char*，但实际上还是常量

// 我觉得你用老一些的编译器应该是可以的

// 举个例子如果你写 const int i = 1; int* p = &i;实际上是通不过的

// 一定要改的话 用const_cast转一下，或许可以

char* strcpy(char* strDest, const char* strSrc) {
    assert((strDest != NULL) && (strSrc != NULL));
    char* address = strDest;
    while ((*strDest++ = *strSrc++) != '\0')
        ;
    return address;
}
void changeppoi(char** a) {
    char* p = *a;
    p[0] = 'A';
}
void changepoi(char* a) {
    a = new char[10];
    a[0] = '1';
}
void changeref(char*& a) {
    a[0] = 'C';
}
int main(int argc, char const* argv[]) {
    //long a = (long)(((int*)0) + 4);
    //cout << a << endl;

    string s("abcdabcda");
    cout << sizeof(s) << endl;
    char c = 'a';
    cout << sizeof c << endl;
    // char* b = new char[3];
    // b[0] = b[1] = b[2] = 'a';
    // changepoi(b);
    // changeref(b);
    // cout << b << endl;
    // char** pb = &b;
    // changeppoi(pb);
    // cout << b << endl;
    // cout << "------------" << endl;

    // string s;

    return 0;
}
