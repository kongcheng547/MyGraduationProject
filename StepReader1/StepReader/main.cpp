# include <iostream>
# include <fstream>
# include <string>
using namespace std;
int main() {
	int n = 0;
    char s[200];
	fstream infile;
	infile.open("E:\\学习资料\\毕业设计\\step文件读取\\cube.STEP", ios::in);
    if (!infile)
    {
        cerr << "open failed!" << endl;
        exit(1);
    }
    while (!infile.eof())
    {
        infile.getline(s, sizeof(s));
        cout << s << endl;
    }
    infile.close();
	return 0;
}