//BinaryTree_ne
#include<iostream>  
#include<cstdio>  
#include<sstream>  
#include<cstring>  
using namespace std;  
  
const int maxn = 110;  
const int maxm = 710;  
struct node {  
    int left, right;  
    int left_s, right_s;  
    int v, id, ak;  //v����value���洢����ֵ, ak�洢�ַ�����a�ĳ���   
    char a[10]; //��value��ֵת��Ϊ�ַ���   
}Nodes[maxn];  
  
char map[maxn][maxn];  
char a = '.', b = '-', c = '|', d = '\0';  
  
void BinaryTree_set(int rt, int k) {  //set,��Ϊ������������� ��rt��ʾ���ڵ�   
    if(Nodes[k].v > Nodes[rt].v) {  
        Nodes[rt].right_s++;          //s,sum��д����ʾ�˽���������������   
        if(Nodes[rt].right != -1) {   //�����������������   
            BinaryTree_set(Nodes[rt].right, k);  //�ݹ�������������бȽ�   
        }  
        else {  
            Nodes[rt].right = k;     //���������û�������������¼��������±�   
        }  
    }  
    else {                             
        Nodes[rt].left_s++;          //�����ڣ���������������������������+1   
        if(Nodes[rt].left != -1) {   //���м�¼�������ĸ��ڵ��λ��   
            BinaryTree_set(Nodes[rt].left, k); //�ݹ������һ����бȽ�   
        }  
        else {  
            Nodes[rt].left = k;      //��û�У���¼�ýڵ���±�   
        }  
    }  
}  
  
void Id_set(int rid, int k) {                  //id��ʾ���Ӧ���ڵڼ��У���Ϊͼ�Ĺ���Ϊ����������������Ϊ��Ҫ�øĽ����������Ľ��������м���   
    Nodes[k].id = rid + Nodes[k].right_s + 1; //��������Ǹ��ڵ��id�����������Ľ�����+1��+1��Ϊ�˲���map[0]   
    if(Nodes[k].right != -1) {               //��������������������ݹ������һ����м���   
        Id_set(rid, Nodes[k].right);  
    }  
    if(Nodes[k].left != -1) {                //��������������������ݹ������һ����м���   
        Id_set(Nodes[k].id, Nodes[k].left);  
    }  
}  
  
void Map_set(int k, int index) {            //ͼ�Ĺ��� ,index��λ�ַ�����β'\0'��λ��   
    for(int i = 0; i < Nodes[k].ak; i++) {  
        map[ Nodes[k].id ][index + i] = Nodes[k].a[Nodes[k].ak - 1 - i]; //���н���ֵ�����   
    }  
    index += Nodes[k].ak; //�ַ����Ľ����±�Ҫ��ֵ�ĺ��棬����Ҫ�����ַ�����a�ĳ���   
    if(Nodes[k].left != -1 || Nodes[k].right != -1) { //���������������������������   
        map[Nodes[k].id][index++] = b;                //����Ӧ�����'\0'��λ�����'-'������index����ֵ+1   
        int max, min;  
        max = min = Nodes[k].id;                    //���ֵ��Сֵ��Ϊ�����Ӧ�ô�ӡ������   
        if(Nodes[k].left != -1) {                   //�����������������   
            max = Nodes[Nodes[k].left].id;          //���ֵΪ�����������ͼʱ�����к�,��Ϊ�������ڸ��ڵ������,Ϊ�������������кŵ������   
            map[Nodes[Nodes[k].left].id][index + 1] = b; //�ý����������������index+1�ĵط����'-'   
            Map_set(Nodes[k].left, index + 2);          //�����������ĵݹ�,�������'-'֮��������飬����index+2��   
        }  
        if(Nodes[k].right != -1) {                 //�����������Ϊ�գ�ԭ��ͬ��   
            min = Nodes[Nodes[k].right].id;  
            map[Nodes[Nodes[k].right].id][index + 1] = b;  
            Map_set(Nodes[k].right, index + 2);  
        }  
        for(int i = min; i <= max; i++) {       //�������������е������������е�index��λ�ö����'|'�ַ�   
            map[i][index] = c;  
        }  
        map[Nodes[k].id][index + 1] = d;       //����ַ���������־'\0'   
    }  
    else {  
        map[Nodes[k].id][index] = d;          //����ַ���������־'\0'   
        return;  
    }  
}  
  
int main() {  
    int n = 0, e, A[maxn];  
    string s;  
    getline(cin, s);  
    istringstream ss(s);  
    while(ss >> e) {  
        A[n++] = e;  
    }   
    for(int i = 0; i < n; i++) {  
        e = A[i];  
        Nodes[i].left = Nodes[i].right = -1;  
        Nodes[i].left_s = Nodes[i].right_s = 0;  
        Nodes[i].ak = 0;       
        Nodes[i].v = e;     //v��ʱvalue����ʾ�������ֵ   
        while(e) {  
            Nodes[i].a[Nodes[i].ak++] = e % 10 + '0';  
            e /= 10;  
        }   
    }   
    for(int i = 1; i < n; i++) {  
        BinaryTree_set(0, i);  
    }  
    Id_set(0, 0);  
    for(int i = 1; i <= n; i++) {  
        for(int j = 0; j < maxm; j++) {  
            map[i][j] = a;     //ȫ�����Ϊ '.'   
        }  
    }  
    Map_set(0, 0);  
    for(int i = 1; i <=n; i++) {  
        printf("%s\n", map[i]);  
    }  
    return 0;  
}  
