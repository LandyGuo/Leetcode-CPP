```cpp
    #include<iostream>
    #include<sstream>
    using namespace std;
    /************************************************************************/
    /* 
    Sample Input
    2
    1 5
    10 20
    Sample Output
    6
    30                                                                     */
    /************************************************************************/
    
    
    int main()
    {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);//输入流重定向
        freopen("output.txt", "wt", stdout);//输出流重定向
    #endif
        int rows;
        cin >> rows;//从流中读取第一个一定要用cin，因为ACM的测试用例的文件可能数据前面会有很多空行
        cin.ignore();//这里跳过换行符
        while (rows--)
        {
            string curLine;
            getline(cin, curLine);
            istringstream ins(curLine);
            int a, b;
            ins >> a >> b;
            cout << a + b << endl;
        }
    }
```
