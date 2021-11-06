/*
 * BitHelper test 1
 * Write and read test
 * Also an example how to use it.
 */

#include <iostream>
#include <fstream>
#include <vector>
#include "BitHelper.h"

typedef double value_type;

void WriteTestData(bool reverseOrder, const std::vector<value_type>& data)
{
    std::fstream *_file = new std::fstream("test.bin", std::ios::out | std::ios::binary);
    _file -> exceptions(std::ios_base::badbit | std::ios_base::failbit);
    if (!_file -> is_open())
    {
        std::cout << "Could not open file" << std::endl;
        exit(-1);
    }
    for (std::vector<value_type>::size_type i = 0; i < data.size(); i++)
    {
        if(reverseOrder)
        {
            bithelper::reverse::WriteData<value_type>(_file, data[i]);
        }
        else
        {
            bithelper::WriteData<value_type>(_file, data[i]);
        }
    }
    _file -> close();
}

std::vector<value_type> ReadTestData(bool reverseOrder, std::vector<value_type>::size_type n)
{
    std::fstream *_file = new std::fstream("test.bin", std::ios::in | std::ios::binary);
    std::vector<value_type> v;
    value_type val = 0;
    _file -> exceptions(std::ios_base::badbit | std::ios_base::failbit);
    if (!_file -> is_open())
    {
        std::cout << "Could not open file" << std::endl;
        exit(-1);
    }
    while(!_file -> eof())
    {
        //Read n values from file
        if(v.size() == n)
        {
            break;
        }
        if (reverseOrder)
        {
            val = bithelper::reverse::ReadData<value_type>(_file);
        }
        else
        {
            val = bithelper::ReadData<value_type>(_file);
        }
        v.push_back(val);
    }
    _file -> close();
    return v;
}

int main(int argc, char **argv)
{
    int failCount = 0;
    std::vector<value_type> testVector {
        0, 423, 312, 6456, 41234, 32, 564, 123, 6456, 10, 6, 0, 645, 1521, 45, 5626, 963, 142, 1654, 85692
    };

    try
    {
        WriteTestData(false, testVector);
        std::vector<value_type> readData = ReadTestData(false, testVector.size());
        if (readData != testVector)
        {
            std::cout << "Writing and reading test in normal order failed." << std::endl;
            failCount++;
        }
        readData = ReadTestData(true, testVector.size());
        if (readData == testVector)
        {
            std::cout << "Writing in normal order and reading in reverse test failed." << std::endl;
            failCount++;
        }

        WriteTestData(true, testVector);
        readData = ReadTestData(true, testVector.size());
        if (readData != testVector)
        {
            std::cout << "Writing and reading test in reverse order failed." << std::endl;
            failCount++;
        }
        readData = ReadTestData(false, testVector.size());
        if (readData == testVector)
        {
            std::cout << "Writing in reverse order and reading in normal test failed." << std::endl;
            failCount++;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "Passed: " << 4 - failCount << "/4" << std::endl;
    
}