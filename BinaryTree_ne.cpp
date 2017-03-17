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
    int v, id, ak;  //v便是value，存储结点的值, ak存储字符数组a的长度   
    char a[10]; //将value的值转化为字符串   
}Nodes[maxn];  
  
char map[maxn][maxn];  
char a = '.', b = '-', c = '|', d = '\0';  
  
void BinaryTree_set(int rt, int k) {  //set,即为构造二叉排序树 ，rt表示根节点   
    if(Nodes[k].v > Nodes[rt].v) {  
        Nodes[rt].right_s++;          //s,sum简写，表示此结点的右子树结点个数   
        if(Nodes[rt].right != -1) {   //如果这个结点有右子树   
            BinaryTree_set(Nodes[rt].right, k);  //递归进入右子树进行比较   
        }  
        else {  
            Nodes[rt].right = k;     //如果这个结点没有右子树，则记录这个结点的下标   
        }  
    }  
    else {                             
        Nodes[rt].left_s++;          //若大于，则进入左子树，左子树结点数量+1   
        if(Nodes[rt].left != -1) {   //若有记录左子树的根节点的位置   
            BinaryTree_set(Nodes[rt].left, k); //递归进入下一层进行比较   
        }  
        else {  
            Nodes[rt].left = k;      //若没有，记录该节点的下标   
        }  
    }  
}  
  
void Id_set(int rid, int k) {                  //id表示这个应该在第几行，因为图的构造为右中左的中序遍历，为此要用改结点的右子树的结点个数进行计算   
    Nodes[k].id = rid + Nodes[k].right_s + 1; //标记数量是根节点的id加上右子树的结点个数+1，+1是为了不用map[0]   
    if(Nodes[k].right != -1) {               //如果这个结点有右子树，递归进入下一层进行计算   
        Id_set(rid, Nodes[k].right);  
    }  
    if(Nodes[k].left != -1) {                //如果这个结点有左子树，递归进入下一层进行计算   
        Id_set(Nodes[k].id, Nodes[k].left);  
    }  
}  
  
void Map_set(int k, int index) {            //图的构造 ,index定位字符串结尾'\0'的位置   
    for(int i = 0; i < Nodes[k].ak; i++) {  
        map[ Nodes[k].id ][index + i] = Nodes[k].a[Nodes[k].ak - 1 - i]; //进行结点的值的填充   
    }  
    index += Nodes[k].ak; //字符串的结束下标要在值的后面，所以要加上字符数组a的长度   
    if(Nodes[k].left != -1 || Nodes[k].right != -1) { //如果这个结点有左子树或者右子树   
        map[Nodes[k].id][index++] = b;                //就在应该填充'\0'的位置填充'-'，并将index的数值+1   
        int max, min;  
        max = min = Nodes[k].id;                    //最大值最小值都为这个数应该打印的行数   
        if(Nodes[k].left != -1) {                   //如果这个结点有左子树   
            max = Nodes[Nodes[k].left].id;          //最大值为这个左子树构图时所在行号,因为左子树在根节点的下面,为此左子树所在行号的数会大   
            map[Nodes[Nodes[k].left].id][index + 1] = b; //该结点左子树的行数在index+1的地方填充'-'   
            Map_set(Nodes[k].left, index + 2);          //进行左子树的递归,在填充完'-'之后填充数组，即在index+2处   
        }  
        if(Nodes[k].right != -1) {                 //如果右子树不为空，原理同上   
            min = Nodes[Nodes[k].right].id;  
            map[Nodes[Nodes[k].right].id][index + 1] = b;  
            Map_set(Nodes[k].right, index + 2);  
        }  
        for(int i = min; i <= max; i++) {       //在右子树所在行到左子树所在行的index的位置都填充'|'字符   
            map[i][index] = c;  
        }  
        map[Nodes[k].id][index + 1] = d;       //填充字符串结束标志'\0'   
    }  
    else {  
        map[Nodes[k].id][index] = d;          //填充字符串结束标志'\0'   
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
        Nodes[i].v = e;     //v即时value，表示这个结点的值   
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
            map[i][j] = a;     //全都填充为 '.'   
        }  
    }  
    Map_set(0, 0);  
    for(int i = 1; i <=n; i++) {  
        printf("%s\n", map[i]);  
    }  
    return 0;  
}  
