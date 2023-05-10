#include <iostream>

class Screen {
public:
    typedef std::string::size_type pos;
    
    Screen() = default;
    Screen(pos ht, pos wd, char c): height(ht), width(wd), contents(ht * wd, c) {}
    
    char get() const {
        return contents[cursor];
    }
    
    int getCursor() const {
        return cursor;
    }
    Screen &move(pos r, pos c); 
    Screen &set(char);
    Screen &set(pos, pos, char);
    Screen &display(std::ostream &os) {
        do_display(os);
        return *this;
    }
    const Screen &display(std::ostream &os) const {
        do_display(os);
        std::cout << "display" << std::endl;
        return *this;
    }
private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
    void do_display(std::ostream &os) const {
        os << contents << std::endl;
    }
};

inline Screen &Screen::move(pos r, pos c) {
    pos row = r * width;
    cursor = row + c; 
    return *this;
}

inline Screen &Screen::set(char c) {
    contents[cursor] = c;
    return *this;
}

inline Screen &Screen::set(pos r, pos col, char c) {
    contents[r * width + col] = c;
    return *this;
}

int main(int argc, char const *argv[])
{
    Screen sc(5, 5, 'b');
    sc.set('a');
    std::cout << sc.get() << std::endl;
    std::cout << sc.getCursor() << std::endl;
    std::cout << "---" << std::endl;
    sc.move(0, 1);
    sc.set('c');
    sc.display(std::cout);
    std::cout << sc.getCursor() << std::endl;
    sc.display(std::cout);
    std::cout << "---" << std::endl;
    return 0;
}