#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <climits>
#include <ctime>
#include "bstream.h"

using namespace std;

class wztime:public tm{
public:
    bool operator >(const wztime& wzt2){
        if(tm_year>wzt2.tm_year && tm_mon>wzt2.tm_mon && tm_mday>wzt2.tm_mday && tm_hour>wzt2.tm_hour && tm_min>wzt2.tm_min && tm_sec>wzt2.tm_sec){
            return true;
        }
        return false;
    } 
};

void generate_file(string input_file, string output_file)
{
    char bytes;
    ifstream ifs(input_file, ifstream::in | ifstream::binary);
    ofstream ofs(output_file, ifstream::out | ifstream::binary);
    while (true) {
        bytes = ifs.get();
        if (ifs.eof())
            break;
        else {
            bytes-=1;
            ofs.put(bytes);
        }
    }
    ifs.close();
    ofs.close();
}

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(false);
    if (argc != 2 && argc != 3) {
        cout << "Error: Invalid argument\n";
        return 0;
    }
    time_t t;//先创建一个time_t类型的变量t
	tm tmp;//创建一个新时间的结构体tmp.也可以时结构体指针 struct tm *p;
	time(&t);//使用该函数就可得到当前系统时间，使用该函数需要将传入time_t类型变量t的地址值。
	localtime_s(&tmp,&t);//由于此时变量t中的系统时间值为日历时间，我们需要调用本地时间函数p=localtime（time_t* t）将t变量中的日历时间转化为本地时间，
    //存入到指针为p的时间结构体中。不改的话，可以参照注意事项手动改。也可以p=localtime(&t);
	int year = tmp.tm_year+1900;//年
	int month = tmp.tm_mon+1;//月
	int mday = tmp.tm_mday;//日   每月的第n天
	int hour = tmp.tm_hour;//时
	int min = tmp.tm_min;//分
	int sec = tmp.tm_sec;//秒
	int wday = tmp.tm_wday;//周n
    // printf("%dyear %dmonth %dday   %dhour%dminute%dsecond week%d\n",year,month,mday,hour,min,sec,wday);//打印

    if (argc == 2)
        generate_file(argv[1], string(argv[1])+"dec");
    else
        generate_file(argv[1], argv[2]);
    return 0;
}
