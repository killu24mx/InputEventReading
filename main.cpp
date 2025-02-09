#include <iostream>
#include <time.h>
#include <fstream>
#include <map>

struct input_event {
	timeval time;
	unsigned short type;
	unsigned short code;
	unsigned int value;
};

 std::map<unsigned short,std::string> codes{
    {0, "KEY_RESERVED"},
    {1, "KEY_ESC"},
    {2, "KEY_1"},
    {3, "KEY_2"},
    {4, "KEY_3"},
    {5, "KEY_4"},
    {6, "KEY_5"},
    {7, "KEY_6"},
    {8, "KEY_7"},
    {9, "KEY_8"},
    {10, "KEY_9"},
    {11, "KEY_0"},
    {12, "KEY_MINUS"},
    {13, "KEY_EQUAL"},
    {14, "KEY_BACKSPACE"},
    {15, "KEY_TAB"},
    {16, "KEY_Q"},
    {17, "KEY_W"},
    {18, "KEY_E"},
    {19, "KEY_R"},
    {20, "KEY_T"},
    {21, "KEY_Y"},
    {22, "KEY_U"},
    {23, "KEY_I"},
    {24, "KEY_O"},
    {25, "KEY_P"},
    {26, "KEY_LEFTBRACE"},
    {27, "KEY_RIGHTBRACE"},
    {28, "KEY_ENTER"},
    {29, "KEY_LEFTCTRL"},
    {30, "KEY_A"},
    {31, "KEY_S"},
    {32, "KEY_D"},
    {33, "KEY_F"},
    {34, "KEY_G"},
    {35, "KEY_H"},
    {36, "KEY_J"},
    {37, "KEY_K"},
    {38, "KEY_L"},
    {39, "KEY_SEMICOLON"},
    {40, "KEY_APOSTROPHE"},
    {41, "KEY_GRAVE"},
    {42, "KEY_LEFTSHIFT"},
    {43, "KEY_BACKSLASH"},
    {44, "KEY_Z"},
    {45, "KEY_X"},
    {46, "KEY_C"},
    {47, "KEY_V"},
    {48, "KEY_B"},
    {49, "KEY_N"},
    {50, "KEY_M"},
    {51, "KEY_COMMA"},
    {52, "KEY_DOT"},
    {53, "KEY_SLASH"},
    {54, "KEY_RIGHTSHIFT"},
    {55, "KEY_KPASTERISK"},
    {56, "KEY_LEFTALT"},
    {57, "KEY_SPACE"},
    {58, "KEY_CAPSLOCK"},
    {59, "KEY_F1"},
    {60, "KEY_F2"},
    {61, "KEY_F3"},
    {62, "KEY_F4"},
    {63, "KEY_F5"},
    {64, "KEY_F6"},
    {65, "KEY_F7"},
    {66, "KEY_F8"},
    {67, "KEY_F9"},
    {68, "KEY_F10"},
    {69, "KEY_NUMLOCK"},
    {70, "KEY_SCROLLLOCK"},
    {71, "KEY_KP7"},
    {72, "KEY_KP8"},
    {73, "KEY_KP9"},
    {74, "KEY_KPMINUS"},
    {75, "KEY_KP4"},
    {76, "KEY_KP5"},
    {77, "KEY_KP6"},
    {78, "KEY_KPPLUS"},
    {79, "KEY_KP1"},
    {80, "KEY_KP2"},
    {81, "KEY_KP3"},
    {82, "KEY_KP0"},
    {83, "KEY_KPDOT"},

};
std::pair<bool,input_event> read_event(std::ifstream& file){
    input_event event;
    if(file.read(reinterpret_cast<char*>(&event),sizeof(event))){
        return std::make_pair(true,event);
    }
    return std::make_pair(false,event);
}

int main(int argc,char** argv){
    const std::string path = "/dev/input/event4";
    std::ifstream file(path);

    if(file.is_open()){
        while(true){
            auto pair = read_event(file);
            if(pair.first){
                input_event event = pair.second;
                if(codes.find(event.code) != codes.end() && event.type == 1){
                    std::cout << codes[event.code] << "\n";
                }
                if(codes[event.code] == "KEY_Q"){
                    break;
                }
            }
        }
    }
    else
        throw std::runtime_error("error opening file");
    
}