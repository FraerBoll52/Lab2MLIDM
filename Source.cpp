#include <iostream>
#include <vector>
#include <string>
#include <locale.h>

using namespace std;

void inputMatrix(vector<vector<int>>& arr, int size) {
    string element;

    cout << "������� �������� ��� ������� 0 ��� 1" << endl;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            bool norm = false;
            while (norm == false) {
                cin >> element;
                if (element == "0") {
                    arr[i][j] = 0;
                    norm = true;
                }
                else if (element == "1") {
                    arr[i][j] = 1;
                    norm = true;
                }
                else {
                    cout << "������� �� 0 ��� 1" << endl;
                }
            }
        }
    }
}


void refleks(vector<vector<int>>& arr, int size) {
    bool reflex = true;

    for (int i = 0; i < size; i++) {
        if (arr[i][i] != 1) {
            reflex = false;
            break;
        }
    }

    if (reflex==true) {
        cout << "�������������� ����" << endl;
    }
    else {
        cout << "�������������� ���" << endl;
    }
}

void simmetrik(vector<vector<int>>& arr, int size) {
    bool sim = true;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (arr[i][j] != arr[j][i]) {
                sim = false;
                break;
            }
        }
        
    }

    if (sim == true) {
        cout << "�������������� ����" << endl;
    }
    else {
        cout << "�������������� ���" << endl;
    }

   
}

void antisimmetrik(vector<vector<int>>& arr, int size) {
    bool antisim = true;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i != j && arr[i][j] == 1 && arr[j][i] == 1 ) {
                antisim = false;
                
            }
            
        }
        if (antisim == false) {
            break;
        }
        
    }

    if (antisim==true) {
        cout << "������������������ ����" << endl;
    }
    else {
        cout << "������������������ ���" << endl;
    }

}

void tranzit(vector<vector<int>>& arr, int size) {
    bool tranzit = true;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (arr[i][j] == 1) {
                for (int k = 0; k < size; k++) {
                    if (arr[j][k] == 1) {
                        if (arr[i][k] != 1) {
                            tranzit = false;
                            break;
                        }
                    }
                }
                 
            }
        }
        if (tranzit == false) {
            break;
        }
    }

    if (tranzit == true) {
        cout << "�������������� ����" << endl;
    }
    else {
        cout << "�������������� ���" << endl;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    int size;
    cout << "������� ������ : ";
    cin >> size;

    vector<vector<int>> arr(size, vector<int>(size));

    inputMatrix(arr, size);

    cout << "��������:" << endl;

    refleks(arr, size);
    simmetrik(arr, size);
    antisimmetrik(arr, size);
    tranzit(arr, size);
   

    return 0;
}