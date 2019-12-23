#include "../include/data.h"

Data::Data(): body_length(0) {}

char* Data::GetData()
{
    return data;
}

size_t Data::GetLength() const
{
    return header_length + body_length;
}

char* Data::GetBody()
{
    return data + header_length;
}

size_t Data::GetBodyLength() const
{
    return body_length;
}

void Data::SetBodyLength(size_t new_length)
{
    body_length = new_length;
    if (body_length > max_length)
        body_length = max_length;
}

bool Data::Decode()
{
    char header[header_length + 1] = "";
    std::strncat(header, data, header_length);
    body_length = std::atoi(header);
    if (body_length > max_length)
    {
        body_length = 0;
        return false;
    }
    return true;
}

void Data::Encode()
{
    char header[header_length + 1] = "";
    std::sprintf(header, "%4d", static_cast<int>(body_length));
    std::memcpy(data, header, header_length);
}
