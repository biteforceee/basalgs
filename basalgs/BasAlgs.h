#pragma once
#include <string>
using namespace std;

int basalg1(int* a, int n)
{
    int sum;
    sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
    }
    return sum;
}

void basalg2(int* a, int n, int& min, int& l)
{
    min = a[0];
    l = -1;

    for (int i = 0; i < n; i++)
    {
        if (a[i] < min)
        {
            min = a[i];
            l = i;
        }
    }
}

void basalg3(string* name, int n, int& k, string* best) {
    k = 0;
    for (int i = 0; i < n; i++){
        if (name[i][0] == 'F'){
            best[k] = name[i];
            k++;
        }
    }
}

int basalg4(string* name, int n, string ctrl) {
    int k = 0;
    int l = -1;
    while ((l == -1) && (k < n)){
        if (name[k] == ctrl){
            l = k;
        }
        k++;
    }
    return l;
}
int basalg5(string* name, int n, string ctrl) {
    int start = 0;
    int mid = 0;
    int ind = -1;
    int end=n-1;
    int cmp = 0;
    while ((ind == -1) && (start <= end)){
        mid = (start + end) / 2;
        if (name[mid] == ctrl) { ind = mid; }
        if (name[mid][0] < ctrl[0]) { start = mid + 1; }
        if (name[mid][0] > ctrl[0]) { end = mid - 1; }
    }
    return ind;
}
void basalg61(int n, string* name, string* list, int& k) {
    k = 0;
    for (int i = 0; i < n; i++){
        int j = 0;
        int l = -1;
        while ((l == -1) && (j < k)){
            if (name[i] == list[j])
            {
                l = j;
            }
            j++;
        }
        if (l == -1)
        {
            list[k] = name[i];
            k++;
        }
    }
}

void basalg62(int n, string* name, string* list, int* rate, int& k) {
    k = 0;

    for (int i = 0; i < n; i++)
    {
        int l = -1;
        int j = 0;
        while ((l == -1) && (j < k))
        {
            if (name[i] == list[j])
            {
                l = j;
            }
            j++;
        }
        if (l == -1)
        {
            list[k] = name[i];
            rate[k] = 1;
            k++;
        }
        else
        {
            rate[l]++;
        }
    }
}

void basalg63(int n, int* ch, string* name, int& k, string* list, int*& sum) {

    k = 0;
    for (int i = 0; i < n; i++)
    {
        int l = -1;
        int j = 0;
        while ((l == -1) && (j < k))
        {
            if (name[i] == list[j])
            {
                l = j;
            }
            j++;
        }
        if (l == -1)
        {
            list[k] = name[i];
            sum[k] = ch[i];
            k++;
        }
        else
        {
            sum[l] += ch[i];
        }
    }
}
void basalg9(string str, int& k, string* w) {
    k = 0;
    str = str + " ";
    while (str.length() > 0) {
        int l = str.find(" ");
        if (l > 0) {
            w[k++] = str.substr(0, l);
        }
        str.erase(0, l + 1);
    }
}
void basalg10(string str, int& k, string* w)//парсер
{
    string zn = ",!?;.";
    k = 0;
    str += " ";
    for (int i = 0; i < str.length(); i++) {
        int l = zn.find(str[i]);
        if (l >= 0 && l < zn.length()) {
            if (w[k].length() > 0) {
                k++;
            }
            w[k] = str[i];
            w[++k] = "";
        }
        else {
            if (str[i] == ' ') {
                if (w[k].length() > 0) {
                    w[++k] = "";
                }
            }
            else {
                w[k] = w[k] + str[i];
            }
        }
    }
}