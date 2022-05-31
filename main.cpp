#include <iostream>
#include <vector>
#include "sort1.h"
#include "test.hpp"
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <windows.h>
#include "STLtest.hpp"

using namespace std;

void printArray(int num, int* array){
    for (int i = 0; i < num; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void startTimeCounterUs(LARGE_INTEGER* f, LARGE_INTEGER* bTime){
    QueryPerformanceFrequency(f);
    QueryPerformanceCounter(bTime);
}
double getTimeCounterUs(LARGE_INTEGER* f, LARGE_INTEGER* bTime, LARGE_INTEGER* eTime){
    QueryPerformanceCounter(eTime);
    double time;
    time = (double)(eTime->QuadPart - bTime->QuadPart)/(double)f->QuadPart;
    return time*1000;
}

//ursprünlich
//von klein bis groß
void bubbleSortOri(int* array, int len){
    for (int i = 0; i < len - 1; ++i) {
        for (int j = 0; j < len - 1 - i; ++j) {
            if (array[j+1] < array[j]){
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}
//optimierte, feststellen ob array in einem großen Zyklus bereits geordnet ist
void bubbleSortOpt_flag(int* array, int len){
    for (int i = 0; i < len - 1; ++i) {
        bool isSorted = true;
        for (int j = 0; j < len - 1 - i; ++j) {
            if (array[j+1] < array[j]){
                isSorted = false;
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
        if (isSorted)
            break;
    }
}
//weiter optimierte, die geordnete Elemente werden nicht nochmal sortiert
void bubbleSortOpt_flag_part(int* array, int len){
    int lastExchangeIndex = 0;//letzte Index von Umtauschen ablagen
    int border = len - 1;//jeder Sortierungszyklus beendet hier
    for (int i = 0; i < len - 1; ++i) {
        bool isSorted = true;
        for (int j = 0; j < border; ++j) {
            if (array[j+1] < array[j]){
                isSorted = false;
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
                lastExchangeIndex = j;
            }
        }
        border = lastExchangeIndex;
        if(isSorted)
            break;
    }
}

void testSort(){
    srand(time(NULL));
    int num = 5000;
    int* array = new int[num];
    LARGE_INTEGER HWfrequence, beginTime, endTime;
    startTimeCounterUs(&HWfrequence,&beginTime);//Zähler fängt an
    for (int i = 0; i < num; ++i) {
        array[i] = rand() % 500;
    }
    random_shuffle(array,array+num);

    //bubbleSortOri(array,num);
    //bubbleSortOpt_flag(array,num);
    bubbleSortOpt_flag_part(array,num);

    //cout << (endTime.QuadPart - beginTime.QuadPart) << endl;//Zeit Zyklus bekommen
    double time_ms = getTimeCounterUs(&HWfrequence,&beginTime,&endTime);//Zähler beendt
    cout << time_ms << "ms" << endl;
    delete[] array;
}

int main() {
    //testSort();
    //testVector();
    //testMap();
    testMultiMap();



    return 0;
}
