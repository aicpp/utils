#pragma once

#include <string>

class Scheme
{
public:
    Scheme();
    ~Scheme();

public:
    bool Load(std::wstring const& filePath);
    bool Save(std::wstring const& filePath);

private:


};

