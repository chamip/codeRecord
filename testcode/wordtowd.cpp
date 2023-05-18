#include <fstream>
#include <iostream>
#include <map>
#include <new>
#include <sstream>
#include <stdexcept>
#include <string>

class Transword {
public:
    Transword(std::ifstream &m, std::ifstream &i, std::map<std::string, std::string> &mp): map_file(m), in(i), trans_words(mp) {};
    ~Transword();
    std::map<std::string, std::string> build_map() {
        std::map<std::string, std::string> trans_words;
        std::string key, value;
        while (map_file >> key && std::getline(map_file,  value)) {
            if (value.size() > 1) {
                //不要用下标操作，因为如果有多个相同key对应不同值，下标操作保存最后一个
                trans_words.insert({key, value.substr(1)});
            } else {
                throw std::runtime_error("no rule for " + key);
            }
        }
        return trans_words;
    }

    const std::string &get_trans(const std::string &w) {
        auto map_it = trans_words.find(w);
        if (map_it != trans_words.end()) {
            return map_it->second;
        }
        return w;
    }

    void word_transform() {
        auto trans_words = build_map();
        std::string text;
        while (std::getline(in, text)) {
            std::istringstream stream(text);
            std::string word;
            bool firstword = true;
            while (stream >> word) {
                if (firstword) {
                    firstword = false;
                } else {
                    std::cout << " ";
                }
                std::cout << get_trans(word);
            }
            std::cout << std::endl;
        }
        return ;
    }
private:
    std::ifstream &map_file;
    std::ifstream &in;
    std::map<std::string, std::string> trans_words;
};

int main(int argc, char const *argv[])
{
    std::string map_file("map_file.txt");
    std::string in("in.txt");
    std::ifstream map(map_file);
    std::ifstream input(in);
    std::map<std::string, std::string> mp;
    Transword *t = new Transword(map, input, mp);
    t->word_transform();
    return 0;
}