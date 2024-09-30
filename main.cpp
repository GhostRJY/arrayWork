#include<iostream>

int randomValue(int min, int max);                    //������ ��������
void fillArray(int *const arr, const int size);       //���������� �������
void showArray(const int *const arr, const int size); //����� �������

void copyArray(int *&arr, int *arr2, int &size, const int &size2);  //����������� �������
void pushBack(int *&arr, int &size, const int value);               //�������� � �����(��� ���� ���� ���������� ����� ������������� ������� ���������� � ���������� �������)
void popBack(int *&arr, int &size);                                 //���������� � �����(��� ���� ���� ���������� ����� ������������� ������� �������� � ���������� �������)
void pushTop(int *&arr, int &size, const int value);                //�������� � ������(��� ���� ���� ���������� ����� ������������� ������� ���������� � ���������� �������)
void popTop(int *&arr, int &size);                                  //���������� � ������(��� ���� ���� ���������� ����� ������������� ������� �������� � ���������� �������)

//�� ���� ��� ���-�� ������� ����� ��� ���������� �������
void pushIn(int *&arr, int &size, const int pos, const int value);  //��������
void popIn(int *&arr, int &size, const int pos);                    //�������

int main() {
    setlocale(LC_ALL, "ru");

    srand(time(NULL));
    rand();

    int size1 = 10, size2 = 7;
    int *firstArr = new int[size1];
    int *secondArr = new int[size2];

    fillArray(firstArr, size1);
    fillArray(secondArr, size2);

    std::cout << "������ ������������ ������\n";
    showArray(firstArr, size1);

    std::cout << "������ ������������ ������\n";
    showArray(secondArr, size2);
    std::cout << "=============================================================\n";
    
    copyArray(firstArr, secondArr, size1, size2);

    std::cout << "������ ������������ ������\n";
    showArray(firstArr, size1);

    std::cout << "������ ������������ ������\n";
    showArray(secondArr, size2);

    delete[] firstArr;
    delete[] secondArr;
    
    int sizeReduct = 7;

    int *ReductArr = new int[sizeReduct];

    std::cout << "�������������� ������������� �������\n";
    fillArray(ReductArr, sizeReduct);
    showArray(ReductArr, sizeReduct);

    pushBack(ReductArr, sizeReduct, 11);
    std::cout << "\n������� � ����� ������� ������������� �������";
    showArray(ReductArr, sizeReduct);

    popBack(ReductArr, sizeReduct);
    std::cout<< "\n������ ��������� ������� ������������� �������";
    showArray(ReductArr, sizeReduct);

    pushTop(ReductArr, sizeReduct, 12);
    std::cout << "\n������� � ������ ������� ������������� �������";
    showArray(ReductArr, sizeReduct);

    popTop(ReductArr, sizeReduct);
    std::cout << "\n������ � ������ ������� ������������� �������";
    showArray(ReductArr, sizeReduct);

    pushIn(ReductArr, sizeReduct, 3, 13);
    std::cout << "\n������� ������� � ������� ������������� �������";
    showArray(ReductArr, sizeReduct);

    popIn(ReductArr, sizeReduct, 2);
    std::cout << "\n������ ������� � ������� ������������� �������";
    showArray(ReductArr, sizeReduct);



    delete[] ReductArr;

    return 0;
}

int randomValue(int min = 0, int max = 100) {


    int result = max - min + 1;
    return (rand() % result + min);
}

void fillArray(int * arr, const int size) {
    for(int i{0}; i < size; ++i) {
        arr[i] = randomValue();
    }
}

void showArray(const int *const arr, const int size) {
    for(int i{0}; i < size; ++i) {
        if(i < size - 1)
            std::cout << '[' << arr[i] << "], ";
        else
            std::cout << '[' << arr[i] << "] ";
    }
    std::cout << '\n';
}

void copyArray(int *&arr, int *arr2, int& size, const int& size2) {
    
    delete[]arr;

    size = size2;

    arr = new int[size];
    for(int i{0}; i < size; ++i) {
        arr[i] = arr2[i];
    }
}

void pushBack(int *&arr, int &size, const int value) {
    int *newArr = new int[size + 1];
    for(int i{0}; i < size; ++i) {
        newArr[i] = arr[i];
    }

    newArr[size++] = value;
    delete[] arr;
    arr = newArr;
}

void popBack(int *&arr, int &size) {
    
    int *newArr = new int[--size];
    for(int i{0}; i < size; ++i) {
        newArr[i] = arr[i];
    }
    delete[] arr;
    arr = newArr;
}

void pushTop(int *&arr, int &size, const int value) {
    
    int *newArr = new int[++size];
    newArr[0] = value;
    for(int i{1}; i < size; ++i) {
        newArr[i] = arr[i - 1];
    }

    delete[] arr;

    arr = newArr;
}

void popTop(int *&arr, int &size) {
    int *newArr = new int[size - 1];
    for(int i{1}; i < size; ++i) {
        newArr[i - 1] = arr[i];
    }

    --size;
    delete[] arr;
    arr = newArr;
}

void pushIn(int *&arr, int &size, const int pos, const int value) {
 
    int *newArr = new int[++size];
    for(int i{0}; i < size; ++i) {
        if(i == pos) {
            newArr[i] = value;
        }
        if(i < pos) {
            newArr[i] = arr[i];
        }
        if(i > pos) {
            newArr[i] = arr[i - 1];
        }
    }

    delete[] arr;
    arr = newArr;
}

void popIn(int *&arr, int &size, const int pos) {

    int *newArr = new int[--size];
    for(int i{0}; i < size; ++i) {
        if(i<pos) {
            newArr[i] = arr[i];
        }
        if(i >= pos) {
            newArr[i] = arr[i + 1];
        }
        
    }

    delete[] arr;
    arr = newArr;
}