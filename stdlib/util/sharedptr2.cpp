#include <string>
#include <fstream>   // for ofstream
#include <memory>    // for shared_ptr
#include <cstdio>    // for remove()
#include <iostream>

class FileDeleter
{
  private:
    std::string filename;
  public:
    FileDeleter (const std::string& fn)
     : filename(fn) {
        std::cout << "constructor." << std::endl;
    }
    void operator () (std::ofstream* fp) {
        std::cout << "delete file." << std::endl;
        delete fp;                     // close file
        std::remove(filename.c_str()); // delete file
    }
    ~FileDeleter() {
        std::cout << "destructor." << std::endl;
    }
};

int main()
{
    // create and open temporary file:
    std::shared_ptr<std::ofstream> fp(new std::ofstream("tmpfile.txt"),
                                      FileDeleter("tmpfile.txt"));
    //...
    std::cout << "!!!!!" << std::endl;

    //TODO: why call destructor 7 times.
    //notes: Maybe there're some default constructors being called.
}