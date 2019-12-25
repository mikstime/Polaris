#ifndef DATA_H
#define DATA_H

#include <cstdio>
#include <cstdlib>
#include <cstring>

class Data
{
public:
    enum { header_length = 4 };
    enum { max_length = 1024 };

    Data();
    char* GetData();
    size_t GetLength() const;
    char* GetBody();
    size_t GetBodyLength() const;
    void SetBodyLength(size_t new_length);
    bool Decode();
    void Encode();

private:
    char data[header_length + max_length];
    size_t body_length;
};

#endif // DATA_H
