#ifndef BITHELPER_H
#define BITHELPER_H

namespace bithelper
{
  /*
  * This function helps you read a specific data type
  * from an std::fstream
  */
  template <typename T>
  inline T ReadData(std::fstream* f)
  {
    unsigned short nbytes = sizeof(T);
    unsigned char *n = new unsigned char[nbytes];
    T ret;
    unsigned char *pret = (unsigned char*)&ret;
    for(unsigned short i = 0; i < nbytes; i++)
    {
      f->read((char*)&n[i],1);
      pret[i] = n[i];
    }
    delete[] n;
    return ret;
  }

  /*
  * This function helps you write a specific data type
  * to an std::fstream.
  */
  template <typename T>
  inline void WriteData(std::fstream* f, T data)
  {
    unsigned short nbytes = sizeof(T);
    unsigned char *pdata = (unsigned char*)&data;
    for(short i = 0; i < nbytes; i++)
    {
      f->write((char*)&pdata[i],1);
    }
  }

  namespace reverse
  {
    /*
      * This function helps you read a specific data type
      * from an std::fstream in reverse byte order.
      * For example from Little Endian to Big Endian or vice versa.
      */
      template <typename T>
      inline T ReadData(std::fstream* f)
      {
        unsigned short nbytes = sizeof(T);
        unsigned char *n = new unsigned char[nbytes];
        T ret;
        unsigned char *pret = (unsigned char*)&ret;
        for(unsigned short i = 0; i < nbytes; i++)
        {
          f->read((char*)&n[i],1);
          pret[nbytes-1-i] = n[i];
        }
        delete[] n;
        return ret;
      }

      /*
      * This function helps you write a specific data type
      * to an std::fstream in reverse byte order.
      * For example from Little Endian to Big Endian or vice versa.
      */
      template <typename T> 
      inline void WriteData(std::fstream* f, T data)
      {
        unsigned short nbytes = sizeof(T);
        unsigned char *pdata = (unsigned char*)&data;
        for(short i = nbytes-1; i >= 0; i--)
        {
          f->write((char*)&pdata[i],1);
        }
      }
    } // namespace reverse

} // namespace bithelper

#endif /* end of BITHELPER_H */