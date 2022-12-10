//###########################################
//###    blackjack Game by LEFTERIS       ###
//###  GAME TO SPEND YOUR TIME FUNNY      ###
//###########################################
#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std ;

int Random();
bool Ask();
void PrintCard(int arr[], int arrSize);
void SumCards(int arr[], int ArrSize, int &sum, int &sum2);
void PrintSum(int sum, int sum2 );
bool GameStop(int sum, int sum2);
bool DealerLogic(int Dsum , int Psum);
void PrintDealerCard(int arr[], int arrsize);

int main(){
    srand ((unsigned) time(NULL));
    
    int arr[50] , PlaerArrSize = 0, start , Psum=0, Psum2=0 ;
    int Darr[50] ;
    
    cout << "Do you want to play? 1=yes 0=no" << endl;
    cin >> start;
    if(start == 0){
        return 0 ;
    }

    cout << "Your first 2 cards " ;
    for(PlaerArrSize = 0; PlaerArrSize < 2; PlaerArrSize++){ // for first 2 cards 
        arr[PlaerArrSize] = Random();
        cout << arr[PlaerArrSize] << " " ;
    }
    cout << endl;
    SumCards(arr, PlaerArrSize, Psum, Psum2);

    Darr[0] = Random();
    cout << "The dealer cards is " << Darr[0] << " XX " << endl;    

    while(Ask()){ //If the player want more than 2 cards 
        Psum = 0, Psum2 = 0;
        arr[PlaerArrSize] = Random(); // gemerate the random number
        PlaerArrSize++;
        //cout <<"ARRzise: " << PlaerArrSize << endl;
        PrintCard(arr, PlaerArrSize);
        SumCards(arr, PlaerArrSize, Psum, Psum2);
        PrintSum(Psum, Psum2);

        if(GameStop(Psum, Psum2) == false){
            return false;
        }
    }

    int Dsum=0, DealerArrSize=0, Dsum2  ;
    
    while(DealerLogic(Dsum , Psum)){
        Dsum = 0 ;
        DealerArrSize++;
        Darr[DealerArrSize] = Random();
        PrintDealerCard(Darr, DealerArrSize);
        SumCards(Darr, DealerArrSize, Dsum, Dsum2);
        PrintSum(Dsum, Dsum2);
    }

}

int Random(){
    int a ;
	a = 1 + (rand()%13);
	return a ;
}

bool Ask(){
    int a ;
    cout << "Do you want another card yes=1 or no=0" << endl;
    cin >> a;
    if(a == 1)
        return true;
    else{
        return false;
    }
}

void PrintCard(int arr[], int arrSize){
    cout << "Your card is: " << endl;
    //cout << "ARR SIZE " << arrSize << endl;
    for(int i = 0; i < arrSize; i++){
        cout << arr[i] << " " ;
    }
    //cout << endl;
}

void PrintDealerCard(int arr[], int arrsize){
    cout << "Dealer cards is: " << endl;
    for(int i =0; i < arrsize; i++){
        cout << arr[i] << " " ;
    }
    cout << endl;
}

void SumCards(int arr[], int ArrSize, int &sum, int &sum2){

    int ArrForSum[ArrSize];

    for(int i = 0 ; i < ArrSize; i++){ //changing all nums > 9 to 10
        ArrForSum[i] = arr[i] ;
        if(ArrForSum[i] > 9)
            ArrForSum[i] = 10;
    }    

    for(int i = 0; i < ArrSize; i++){
        sum += ArrForSum[i];
        if(ArrForSum[i] == 1){
            ArrForSum[i] = 11;
        }
        sum2 += ArrForSum[i];
    }
}

void PrintSum(int sum, int sum2 ){
    cout << "The sum of the card is: " << sum << endl;
    if(sum2 < 21)
        cout << "The sum2 of the card is: " << sum2 << endl;
}

bool GameStop(int sum, int sum2){
    if(sum > 21){
        cout << "You lose the game " << endl;
        return false;
    }
    if(sum == 21 || sum2 == 21){
        cout << "You win the game " << endl;
        return false;
    }
    else{
        return true ;
    }
}

bool DealerLogic(int Dsum , int Psum){
    
    if(Dsum > 21){
        cout << "You win " << endl;
        return false;
    }
    else if(Psum < Dsum){
        cout << "You Lose " << endl; //The Dealer win
        return false;
    }
    else if(Dsum == 21){
        cout << "You Lose " << endl;
        return false;
    }
    
}