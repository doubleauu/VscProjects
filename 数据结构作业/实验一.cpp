#include  <iostream>
using namespace std;

typedef int ElemType;
typedef int Status;
#define MAXSIZE 100  // 顺序表的最大长度

// 线性表两个元素：起始地址和长度
typedef struct {
    ElemType *elem;
    int length;
}SqList;

// 创建新的顺序表,初始化函数
Status InitList(SqList &L) {
    L.elem = new ElemType[MAXSIZE];
    L.length = 0;
    return 1;
}

// 销毁顺序表
void DestroyList(SqList &L) {
    if(L.elem) delete[] L.elem;
    L.length = 0;
    L.elem = NULL;
}



// 菜单
void show_help() {
    cout << "1----清空线性表" << endl;
    cout << "2----判断线性表是否为空" << endl;
    cout << "3----求线性表长度" << endl;
    cout << "4----获取线性表指定位置元素" << endl;
    cout << "5----获取线性表指定元素位置" << endl;
    cout << "6----求前驱" << endl;
    cout << "7----求后继" << endl;
    cout << "8----在线性表指定位置插入一个元素" << endl;
    cout << "9----删除线性表指定位置元素" << endl;
    cout << "10----显示线性表" << endl;
    cout << "a----与给出集合取交" << endl;
    cout << "b----与给出集合取并" << endl;
    cout << "c----与给出集合取补" << endl;
    cout << "      退出，输入0!    " << endl;
}

// 1. 清空顺序表
void ClearList(SqList& L) {
    L.length = 0;
}

// 2. 判断线性表是否为空
bool ListEmpty(SqList L) {
    return L.length == 0;
}

// 3. 求线性表长度
int ListLength(SqList L) {
    return L.length;
}

// 4. 获取线性表指定位置元素
Status GetElem(SqList L, int i, ElemType& e) {
    if(i<1 || i>L.length) {
        cout << "不存在!" << endl;
        return 0;
    }
    e = L.elem[i-1];
    cout << "该元素为：" << e << endl;
    return 2;
}

// 5. 获取顺序表指定元素位置（首次出现）（传指针形式然后解引用）
int LocateElem(SqList L, int* e) {
    int w = 100;
    for(int i = 0; i < L.length; i++) {
        if(L.elem[i]==*e) {
            w = 1;
            return i+1;
            break;
        }
    }
    if(w==100) return w;  // 标识未找到
    return w;
}

// 6. 求前驱
bool PriorElem(SqList L, int* currentElem, int* PreElem) {
    int p = 0;
    int temp = LocateElem(L,currentElem);  // 当前元素位置
    if(*currentElem==L.elem[0]) { // 使用 temp==1 ?
        cout << "第一个元素没有前驱" << endl;
        return 0;
    }
    for(int i = 0; i < L.length; i++) {
        if(*currentElem==L.elem[i]) {
            p = 1;
        }
    }
    if(p==0) {
        cout <<"不存在该元素!" << endl;
        return 0;
    }
    if(temp==100) {  // 第5个函数中返回的100，标识未找到，应该不会出现
        return 0;
    }else {
        *PreElem = L.elem[temp-2]; // LocateElem 返回从1开始的位置
        cout << "前驱为：" << *PreElem << endl;
        return 0;
    }
}

// 7. 求后继
bool NextElem(SqList L, int* currentElem, int* NextE) {
    int p = 0; // 标识是否找到该元素
    int temp = LocateElem(L, currentElem); // 指定元素位置；
    if(*currentElem==L.elem[L.length-1]) {
        cout << "最后一个元素没有后继!" << endl;
        return 0;
    }
    for(int i = 0; i < L.length; i++) {
        if(*currentElem == L.elem[i]) {
            p = 1; // 标识找到
        }
    }
    if(p==0) {
        cout << "不存在该元素！"<< endl;
        return 0;
    }
    if(temp==100) {
        return 0;
    }else {
        *NextE = L.elem[temp];
        cout << "后继为：" << *NextE << endl;
        return 0;
    }
}

// 8. 在线性表指定位置插入一个元素
Status ListInsert(SqList& L, int i, ElemType e) {
    if(i<1 || i>L.length+1) { // length or length+1,应该是+1，可以插入到后面
        cout << "输入元素位置不合法" << endl;
        return 0;
    }
    if(L.length==MAXSIZE) return 2; // 为什么返回 2?
    for(int j = L.length-1; j >= i-1; j--) {
        L.elem[j+1] = L.elem[j];
    }
    L.elem[i-1] = e;
    L.length++;
    return 1;
}

// 9. 删除线性表指定位置元素
Status ListDelete(SqList& L, int i, ElemType e) {
    if(i<1 || i>L.length) {
        cout << "输入元素位置不合法" << endl;
        return 0;
    }
    e = L.elem[i-1];
    for(int j =  i; j <= L.length-1; j++) {
        L.elem[j-1] = L.elem[j];
    }
    L.length--;
    return 1;
}

// 10. 显示线性表
void Display_List(SqList L) {
    for(int i = 0; i < L.length; i++) {
        cout << L.elem[i] << " ";
    }
    cout << endl;
}

// a. 与给出集合取交(两个集合中都有的元素)
void Intersection(SqList L1, SqList L2, SqList& Result) {
    Result.length = 0;
    for(int i = 0; i < L1.length; i++) {
        for(int j = 0; j < L2.length; j++) {
            if(L1.elem[i] == L2.elem[j]) {
                Result.elem[Result.length] = L1.elem[i];
                Result.length++;
                break;
            }
        }
    }
}

// b. 与给出集合取并(合并两个集合，去重)
void Union(SqList L1, SqList L2, SqList& Result) {
    Result.length = 0;
    for(int i = 0; i < L1.length; i++) {
        Result.elem[Result.length] = L1.elem[i];
        Result.length++;
    }
    for(int i = 0; i < L2.length; i++) {
        bool found = false;
        for(int j = 0; j < L1.length; j++) {
            if(L2.elem[i] == L1.elem[j]) {
                found = true;
                break;
            }
        }
        if(!found) {
            Result.elem[Result.length] = L2.elem[i];
            Result.length++;
        }
    }
}

// c. 与给出集合取差(第一个集合中有但是第二个集合中没有的元素)
void Complement(SqList L1, SqList L2, SqList& Result) {
    Result.length = 0;
    for(int i = 0; i < L1.length; i++) {
        bool found = false;
        for(int j = 0; j < L2.length; j++) {
            if(L1.elem[i] == L2.elem[j]) {
                found = true;
                break;
            }
        }
        if(!found) {
            Result.elem[Result.length] = L1.elem[i];
            Result.length++;
        }
    }
}

int main() {
    int operate_code; // 操作码
    show_help();
    SqList L;
    InitList(L);
    ElemType e; // 用来存储函数结果；
    int i;
    int x, y;
    while(1) {
        cout << "请输入操作代码: ";
        cin >> operate_code;
        // if(operate_code <= 0) {
        //     cout << "感谢使用" << endl;
        //     return 0;
        // }
        switch(operate_code) {
            case 1: {
                cout << "The length of the lise is: 0" << endl;
                ClearList(L);
                break;
            }
            case 2: {
                if(ListEmpty(L)) {
                    cout << "The list is empty" << endl;
                }else {
                    cout << "The lise is not empty" << endl;
                }
                break;
            }
            case 3: {
                cout << "The length of the list is: " << ListLength(L) << endl;
                break;
            }
            case 4: {
                cout << "请输入指定位置：";
                cin >> i;
                GetElem(L,i,e); // 函数内输出；
                break;
            }
            case 5: {
                cout << "请输入该元素：";
                cin >> e;
                if(LocateElem(L,&e)!=100) {
                    cout << "该元素位置为： " << LocateElem(L,&e) << endl;
                }else {
                    cout << "该元素不存在" << endl;
                }
                break;
            }
            case 6: {
                cout << "请输入当前元素：";
                cin >> i;
                PriorElem(L,&i,&y);
                break;
            }
            case 7: {
                cout << "请输入当前元素：";
                cin >> i;
                NextElem(L,&i,&y);
                break;
            }
            case 8: {
                cout << "请输入插入位置及该元素：";
                cin >> i >> e;
                ListInsert(L,i,e);
                break;
            }
            case 9: {
                cout << "请输入删除元素及其位置" << endl;
                cin >> i >> e;;
                ListDelete(L,i,e);
                break;
            }
            case 10: {
                cout << "The elements of the list are: " << endl;
                Display_List(L);
                break;
            }
            case 'a': {
                SqList L2, Result;
                InitList(L2);
                InitList(Result);
                cout << "请输入第二个集合的元素个数：";
                cin >> x;
                for(int k = 0; k < x; k++) {
                    cin >> e;
                    L2.elem[k] = e;
                }
                L2.length = x;
                Intersection(L, L2, Result);
                cout << "交集为：" << endl;
                Display_List(Result);
                DestroyList(L2);
                DestroyList(Result);
                break;
            }
            case 'b': {
                SqList L2, Result;
                InitList(L2);
                InitList(Result);
                cout << "请输入第二个集合的元素个数：";
                cin >> x;
                for(int k = 0; k < x; k++) {
                    cin >> e;
                    L2.elem[k] = e;
                }
                L2.length = x;
                Union(L, L2, Result);
                cout << "并集为：" << endl;
                Display_List(Result);
                DestroyList(L2);
                DestroyList(Result);
                break;
            }
            case 'c': {
                SqList L2, Result;
                InitList(L2);
                InitList(Result);
                cout << "请输入第二个集合的元素个数：";
                cin >> x;
                for(int k = 0; k < x; k++) {
                    cin >> e;
                    L2.elem[k] = e;
                }
                L2.length = x;
                Complement(L, L2, Result);
                cout << "差集为：" << endl;
                Display_List(Result);
                DestroyList(L2);
                DestroyList(Result);
                break;
            }
            case 0: {
                cout << "感谢使用！！！" << endl;
                return 0;
            }
            default: {
                cout << "\n操作码有误!!!" << endl;
                show_help();
            }
        }
    }
}


