#include <iostream>
#include <fstream>
#include <cstring>
#include <stack>
#include <map>
#include <iomanip>
#include <cmath>
#include <algorithm>
using namespace std;

const int maxn = 1000005;
const int add = 10001, mul = 10002;

void pause() {
    puts("请按任意键继续...");
    system("stty raw");
    getchar();
    getchar();
    system("stty cooked");
}

class ChemAssistant {
private:
    double *data1, *data2;
    string formula;
    stack<double> a, b;
    map<string, double> mass;
    map<int, int> pri;
public:
    ChemAssistant();
    ~ChemAssistant();
    int show();
    int getOpt();

    int fun1();
    int fun2();
    void trans(string arr[], int &cnt);
    int fun3();

    void clear();
} assistant;

ChemAssistant::ChemAssistant():
    data1(new double[maxn + 5]), data2(new double[maxn + 5]), formula("") {
    ifstream ifs("mass.in", ios::in);//从文件中读取相对原子质量
    string tmp;
    double m;
    for(int i = 0; i < 85; ++i) {//数据文件中共85条
        ifs >> tmp >> m;
        mass[tmp] = m;
    }
    ifs.close();
    pri[add] = 1;
    pri[mul] = 2;
}

ChemAssistant::~ChemAssistant() {
    delete []data1;
    delete []data2;
}

int ChemAssistant::show() {
    puts("用户你好，欢迎使用化学助手");
    puts("输入相应数字进行选择");
    puts("0. 退出");
    puts("1. 计算一组数据的线性回归方程");
    puts("2. 计算一组数据的均值、误差、偏差及t值");
    puts("3. 计算一个物质的相对分子质量");
    return getOpt();
}

int ChemAssistant::getOpt() {
    int opt = 0;
    cin >> opt;
    switch (opt) {
        case 0:
            puts("欢迎下次使用");
            return 1;
        case 1:
            return fun1();
        case 2:
            return fun2();
        case 3:
            return fun3();
        default:
            puts("请输入正确的选项");
            break;
    }
    return 0;
}

int ChemAssistant::fun1() {
    clear();
    int n;
    puts("请输入一共多少组数据（最多1000000），输入0以退出");
    while(1) {
        cin >> n;
        if(n == 0) return 0;
        else if(n > 1000000 || n < 0) {
            puts("请输入正确格式的数字");
        } else break;
    }
    double r = 0, a = 0, b = 0;
    double sumx, sumy;
    printf("请输入%d个数据代表自变量x，以空格或回车符隔开\n", n);
    for(int i = 1; i <= n; ++i) {
        cin >> data1[i];
        sumx += data1[i];
    }
    printf("请输入%d个数据代表因变量y，以空格或回车符隔开\n", n);
    for(int i = 1; i <= n; ++i) {
        cin >> data2[i];
        sumy += data2[i];
    }

    double meanx = sumx / n, meany = sumy / n;
    double dx = 0, dy = 0, proXY = 0;
    for (int i = 1; i <= n; ++i) {
        proXY += (data1[i] - meanx) * (data2[i] - meany);
        dx += (data1[i] - meanx) * (data1[i] - meanx);
        dy += (data2[i] - meany) * (data2[i] - meany);
    }
    b = proXY / dx;
    a = meany - b * meanx;
    r = b * sqrt(dx / dy);
    cout << "该组数据的一元线性回归方程为" << "y=" << a;
    if(b >= 0) cout << "+" << b << "x" << "。" << endl;
    cout << "其r值为" << r << "。";
    pause();
    return 0;
}

int ChemAssistant::fun2() {
    clear();
    int n;
    double xt, sum = 0;
    puts("请输入一共多少组数据（最多1000000），以及真值，输入0以退出");
    while(1) {
        cin >> n;
        if(n == 0) return 0;
        else if(n > 1000000 || n < 0) {
            puts("请输入正确格式的数字");
        } else {
            cin >> xt;
            break;
        }
    }
    int r = 0, a = 0, b = 0;
    printf("请输入%d个数据，以空格或回车符隔开\n", n);
    for(int i = 1; i <= n; i++) {
        cin >> data1[i];
        sum += data1[i];
    }
    double mean = sum / n;
    double error = mean - xt;
    double s = 0;
    for (int i = 1; i <= n; i++) {
        s += ((data1[i] - mean) * (data1[i] - mean));
    }
    s = sqrt(s / (n - 1));
    double t = fabs(xt - mean) / s * sqrt(n);
    cout << "平均值为" << mean << "。" << endl
         << setprecision(2)
         << "绝对误差为 " << error << "。" << endl
         << "相对误差为 " << error / xt * 100 << "%。" << endl
         << "标准偏差为 " << s << "。" << endl
         << "该组数据的t值为" << t << "。" << endl;
    pause();
    return 0;
}
void ChemAssistant::trans(string arr[], int &cnt) {
    string s, tmp[1005];
    int tcnt = 0;
    for(int i = 0; i < formula.length(); ++i) {
        if(isalpha(formula[i])) {
            s += formula[i];
            if(islower(formula[i + 1])) {
                ++i;
                s += formula[i];
            }
            tmp[tcnt++] = s;
            s.clear();
        } else if(isdigit(formula[i])) {
            tmp[tcnt] = formula[i];
            while(isdigit(formula[i + 1])) {
                ++i;
                tmp[tcnt] += formula[i];
            }
            ++tcnt;
        } else {
            tmp[tcnt++] = formula[i];
        }
    }

    for(int i = 0; i < tcnt; ++i) {
        if(isalpha(tmp[i][0])) {
            arr[cnt++] = tmp[i];
            if(isalpha(tmp[i + 1][0]) || tmp[i + 1][0] == '(') {
                arr[cnt++] = "+";
            }
        } else if(isdigit(tmp[i][0])) {
            arr[cnt++] = "*";
            arr[cnt++] = tmp[i];
            if(isalpha(tmp[i + 1][0]) || tmp[i + 1][0] == '(') {
                arr[cnt++] = "+";
            }
        } else arr[cnt++] = tmp[i];
    }
}
int ChemAssistant::fun3() {
    clear();
    puts("请输入分子式，括号请一律使用小括号，严格区分大小写，输入0以退出");
    cin >> formula;
    if(formula == "0") return 0;
    string exp[1005];
    int cnt = 0;
    trans(exp, cnt);

    for(int i = 0; i < cnt; ++i) {
        if(isalpha(exp[i][0])) {
            if(mass[exp[i]] <= 1e-8) {
                puts("您输入的分子有误，或包含了未记录的原子，请重新输入");
                pause();
                return 0;
            }
            a.push(mass[exp[i]]);
        } else if(isdigit(exp[i][0])) {
            a.push(stod(exp[i]));
        } else {
            if(exp[i] == "(") b.push('(');
            else if(exp[i] == ")") {
                while(!b.empty() && b.top() != '(') a.push(b.top()), b.pop();
                b.pop();
            } else {
                int sym = 0;
                if(exp[i] == "+") sym = add;
                else if(exp[i] == "*") sym = mul;
                while(!b.empty() && pri[b.top()] >= pri[sym]) a.push(b.top()), b.pop();
                if(sym) b.push(sym);
            }
        }
    }
    while(!b.empty()) a.push(b.top()), b.pop();
    while(!a.empty()) b.push(a.top()), a.pop();

    while(!b.empty()) {
        if(b.top() < 10000) a.push(b.top());
        else {
            double t1, t2;
            t2 = a.top(), a.pop();
            t1 = a.top(), a.pop();
            if(b.top() == add) a.push(t1 + t2);
            else if(b.top() == mul) a.push(t1 * t2);
        }
        b.pop();
    }
    cout << "该分子的相对分子质量是：" << a.top() << endl;
    pause();
    return 0;
}

void ChemAssistant::clear() {
    cout << setprecision(6);
    memset(data1, 0, sizeof(data1));
    memset(data2, 0, sizeof(data2));
    formula.clear();
}

void mainloop() {
    while(1) {
        system("clear");
        if(assistant.show()) break;
    }
}

int main() {
    mainloop();
    return 0;
}