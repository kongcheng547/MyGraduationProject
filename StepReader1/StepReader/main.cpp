# include <iostream>
# include <fstream>
# include <string>
using namespace std;
int main() {
	int n = 0;
    char s[200];
	fstream infile;
	infile.open("E:\\ѧϰ����\\��ҵ���\\step�ļ���ȡ\\cube.STEP", ios::in);
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