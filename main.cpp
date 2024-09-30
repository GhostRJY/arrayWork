#include<iostream>

int randomValue(int min, int max);                    //рандом значение
void fillArray(int *const arr, const int size);       //заполнение массива
void showArray(const int *const arr, const int size); //показ массива

void copyArray(int *&arr, int *arr2, int &size, const int &size2);  //копирование массива
void pushBack(int *&arr, int &size, const int value);               //добавляю в конец(еще один путь реализации через делегирование функции добавление в конкретную позицию)
void popBack(int *&arr, int &size);                                 //выбрасываю с конца(еще один путь реализации через делегирование функции удаление в конкретной позицию)
void pushTop(int *&arr, int &size, const int value);                //добавляю в начало(еще один путь реализации через делегирование функции добавление в конкретную позицию)
void popTop(int *&arr, int &size);                                  //выбрасываю с начала(еще один путь реализации через делегирование функции удаление в конкретной позицию)

//по сути две фун-ии которые нужны для реализации задания
void pushIn(int *&arr, int &size, const int pos, const int value);  //внедрить
void popIn(int *&arr, int &size, const int pos);                    //извлечь

int main() {
    setlocale(LC_ALL, "ru");

    srand(time(NULL));
    rand();

    int size1 = 10, size2 = 7;
    int *firstArr = new int[size1];
    int *secondArr = new int[size2];

    fillArray(firstArr, size1);
    fillArray(secondArr, size2);

    std::cout << "Первый динамический массив\n";
    showArray(firstArr, size1);

    std::cout << "Второй динамический массив\n";
    showArray(secondArr, size2);
    std::cout << "=============================================================\n";
    
    copyArray(firstArr, secondArr, size1, size2);

    std::cout << "Первый динамический массив\n";
    showArray(firstArr, size1);

    std::cout << "Второй динамический массив\n";
    showArray(secondArr, size2);

    delete[] firstArr;
    delete[] secondArr;
    
    int sizeReduct = 7;

    int *ReductArr = new int[sizeReduct];

    std::cout << "Редактирование динамического массива\n";
    fillArray(ReductArr, sizeReduct);
    showArray(ReductArr, sizeReduct);

    pushBack(ReductArr, sizeReduct, 11);
    std::cout << "\nДобавил в конец элемент динамического массива";
    showArray(ReductArr, sizeReduct);

    popBack(ReductArr, sizeReduct);
    std::cout<< "\nудалил последний элемент динамического массива";
    showArray(ReductArr, sizeReduct);

    pushTop(ReductArr, sizeReduct, 12);
    std::cout << "\nДобавил в начало элемент динамического массива";
    showArray(ReductArr, sizeReduct);

    popTop(ReductArr, sizeReduct);
    std::cout << "\nУдалил в начале элемент динамического массива";
    showArray(ReductArr, sizeReduct);

    pushIn(ReductArr, sizeReduct, 3, 13);
    std::cout << "\nДобавил элемент в позицию динамического массива";
    showArray(ReductArr, sizeReduct);

    popIn(ReductArr, sizeReduct, 2);
    std::cout << "\nУдалил элемент в позицие динамического массива";
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