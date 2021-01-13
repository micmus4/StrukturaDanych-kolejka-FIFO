#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;


class Queue{

private:

    int* Q;
    int tail;
    int head;
    int wielkosc;

public:

    Queue(int rozmiar){
        Q = new int[rozmiar + 1];
        tail = -1;
        head = -1;
        wielkosc = rozmiar;
    }

    int getSize(){
        return wielkosc;
    }

    bool isFull(){

        if(head == 0 && tail == wielkosc - 1){
            return true;
        } else if (head == tail + 1){
            return true;
        }
        return false;
    }

    bool isEmpty(){

        if(head == -1){
            return true;
        }
        return false;
    
    }

    bool Enqueue(int value){

        if(isFull()){
            return false;
        }

        if(head == -1){
            head = 0;
            tail = 0;
        } else {
            if(tail == wielkosc - 1){
                tail = 0;
            } else {
                tail++;
            }
        }
        Q[tail] = value;
        return true;
    }

    int Dequeue(){
        
        if(isEmpty()){
            return NULL;
        }

        int value = Q[head];

        if(head == tail){
            head = -1;
            tail = -1;
        } else{
            if(head == wielkosc - 1){
                head = 0;
            } else {
                head++;
            }
        }
        return value;
    }

    void Display(){
        if(isEmpty()){
            printf("Kolejka jest pusta.\n");
            return;
        }
        printf("Elementy kolejki od pierwszego do ostatniego: ");
        if(head < tail){
            for (int i = head; i <= tail; i++){
                printf("%d ", Q[i]);
            }
        } else if (head == tail){
            printf("%d ", Q[head]);
        } else {
            for(int i = head; i < wielkosc; i++){
                printf("%d ", Q[i]);
            }
            for(int i = 0; i <= tail; i++){
                printf("%d ", Q[i]);
            }
        }
        printf("\n");
    }

    int howMany(){
        if(isFull()){
            return wielkosc;
        } else if (isEmpty()) {
            return 0;
        } else {
            if (head < tail){
                return tail - head + 1;
            } else if (head == tail) {
                return 1;
            } else {
                return wielkosc - head + tail - 1;
            }
        }
    }
};




int main(){

    int n, rozmiar, value;
    string operacja;
    while(true){
        printf("Wybierz wielkosc kolejki: ");
        scanf("%d", &n);
        if(n < 1){
            printf("Wybierz wartosc wieksza od 0.\n");
            continue;
        }
        break;
    }
    Queue kolejka(n);
    rozmiar = kolejka.getSize();
    printf("Stworzyles kolejke o wielkosci: %d  (jej elementy znajduja sie na indeksach <0 ; %d>)\n", rozmiar, rozmiar - 1);
    printf("Dostepne operacje:\n\n");
    printf("\t - ENQUEUE -> Dodaje element na koniec kolejki.\n");
    printf("\t - DEQUEUE -> Pobiera element z poczatku kolejki.\n");
    printf("\t - ISEMPTY -> Sprawdza czy kolejka jest pusta.\n");
    printf("\t - ISFULL -> Sprawdza czy kolejka jest pelna.\n");
    printf("\t - HOWMANY -> Zwraca ilosc elementow w kolejce.\n");
    printf("\t - DISPLAY -> Wypisuje kolejke od pierwszego do ostatniego elementu.\n\n");

    while(true){
    printf("Operacja: ");
    cin >> operacja;
    if (operacja == "ENQUEUE"){
        printf("Wartosc liczbowa: ");
        cin >> value;
        if(!kolejka.Enqueue(value)){
            printf("Kolejka jest pelna. Nie mozna dodac nowego elementu.\n");
        } else {
            printf("Dodano wartosc %d do kolejki.\n", value);
        }
    }

    if (operacja == "DEQUEUE"){
        value = kolejka.Dequeue();
        if(value == NULL){
            printf("Kolejka jest pusta. Nie mozna usunac z niej elementow.\n");
        } else {
            printf("Usunieto wartosc %d z kolejki.\n", value);
        }
    }

    if(operacja == "ISEMPTY"){
        if(kolejka.isEmpty()){
            printf("Kolejka jest pusta.\n");  
        } else {
            printf("Kolejka nie jest pusta.\n");
        }
    }

     if(operacja == "ISFULL"){
        if(kolejka.isFull()){
            printf("Kolejka jest pelna.\n");
        } else {
            printf("Kolejka nie jest pelna.\n");
        }
    }

    if(operacja == "HOWMANY"){
        printf("Ilosc elementow w kolejce: %d\n", kolejka.howMany());
    }

    

    if(operacja == "DISPLAY"){
        kolejka.Display();
    }

    if (operacja == "END"){
        break;
    }
}



    return 0;


}