#include <iostream> coin1
#include <climits>
using namespace std;

int Values[105];
int memo[105][105];
char pTable[105][105];

const int NEG_INF = INT_MIN / 4; 

void initMemo(int M,int N){
    for(int i=0;i<=M;i++){
        for(int j=0;j<=N;j++){
            if(i==0) memo[i][j]=0;        
            else if(j==0) memo[i][j]=NEG_INF; 
            else memo[i][j]=NEG_INF;
            pTable[i][j]='?';
        }
    }
}

void printMemo(int M,int N){
    cout<<"***********memo*********************"<<endl;
    for(int i=0;i<=N;i++){
        for(int j=0;j<=M;j++){
            if(memo[j][i]==NEG_INF) cout<<INT_MIN<<"\t"; 
            else cout<<memo[j][i]<<"\t";
        }
        cout<<endl;
    }
    cout<<"\n***********memo*********************"<<endl;
}

int CoinChange(int M, int N){
    if(M==0) return 0;
    if(N==0) return NEG_INF;

    if(memo[M][N]!=NEG_INF) return memo[M][N];

    int notTaken = CoinChange(M, N-1);
    int taken = NEG_INF;

    if(M-Values[N] >= 0){
        int prev = CoinChange(M-Values[N], N-1);
        if(prev!=NEG_INF) taken = prev + 1;
    }

    if(taken >= notTaken){
        memo[M][N] = taken;
        pTable[M][N] = 'T';
    }else{
        memo[M][N] = notTaken;
        pTable[M][N] = 'N';
    }
    return memo[M][N];
}

void printCoins(int M,int N){
    if(M==0 || N==0) return;
    if(pTable[M][N]=='T'){
        cout<<"Coin number "<<N<<" (Tk"<<Values[N]<<") was taken\n";
        printCoins(M-Values[N], N-1);
    }else{
        printCoins(M, N-1);
    }
}

void bottomUp(int M, int N){
    for(int i=0;i<=M;i++){
        for(int j=0;j<=N;j++){
            CoinChange(i,j);
        }
    }
}

int main(){
    int M, N;
    cout<<"Enter the bill\n";
    cin>>M;
    cout<<"Enter the number of coins\n";
    cin>>N;

    cout<<"Enter the coin values\n";
    for(int i=1;i<=N;i++) cin>>Values[i];

    initMemo(M,N);

    int result = CoinChange(M,N);
    bottomUp(M,N);
    printMemo(M,N);

    if(result<=NEG_INF/2){
        cout<<"Payment not possible with the coins you have\n";
    }else{
        cout<<"Number of coins used to make the payment "<<result<<"\n";
        printCoins(M,N);
    }
    return 0;
}
















#include <bits/stdc++.h> mid
using namespace std;

bool isPresentInsideString(char name[], int nlen, char c) {
    c = tolower(c);
    for (int i = 0; i < nlen; i++) {
        if (tolower(name[i]) == c) return true;
    }
    return false;
}

int countNameCharacters(char name[], int nlen, char s[], int i, int j) {
    if (i > j) return 0;
    if (i == j) {
        if (isPresentInsideString(name, nlen, s[i])) {
            cout << "Found the character " << s[i] << " from your name\n";
            return 1;
        }
        return 0;
    }
    int mid = (i + j) / 2;
    int left = countNameCharacters(name, nlen, s, i, mid);
    int right = countNameCharacters(name, nlen, s, mid + 1, j);
    return left + right;
}

int main() {
    char name[105], s[105];
    cout << "Enter your name\n";
    cin.getline(name, 105);
    cout << "Enter the any string\n";
    cin.getline(s, 105);

    cout << "You entered\n";
    cout << "Name:" << name << "\n";
    cout << "String:" << s << "\n";

    int nlen = strlen(name);
    int slen = strlen(s);
    int total = countNameCharacters(name, nlen, s, 0, slen - 1);

    cout << "The number of characters in the entered string, which are also present in your name is " << total << "\n";
    return 0;
}



















#include<iostream> k0
using namespace std;

int P[100];
int W[100];
string names[100];
int expired[100];
int memo[100][100];
char pTable [100][100];

void initMemo(int C,int N){
    for(int i=0;i<=C;i++){
        for(int j=0;j<=N;j++){
            if(i==0||j==0){
                memo[i][j]=0;
            }else{
                memo[i][j]=-1;
            }
        }
    }
}

void printMemo(int C,int N){
    cout<<"*********memo***********"<<endl;
    for(int i=0;i<=C;i++){
        for(int j=0;j<=N;j++){
            cout<<memo[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<"\n*********memo***********"<<endl;
}

int knapsack(int C, int i){
    if(C==0||i==0){
        return 0;
    }
    if(memo[C][i]!=-1){
        return memo[C][i];
    }
    int taken, notTaken;

    notTaken = 0+knapsack(C,i-1);
    if(C>=W[i]){
        taken = P[i]+knapsack(C-W[i],i-1);
    }else{
        taken=0;
    }

    if(notTaken>=taken){
        pTable[C][i]='N';
        memo[C][i]=notTaken;
        return notTaken;
    }else{
        pTable[C][i]='T';
        memo[C][i]=taken;
        return taken;
    }


}

int knapsack2(int C, int i){
    if(C==0||i==0){
        return 0;
    }
    if(memo[C][i]!=-1){
        return memo[C][i];
    }

    if(expired[i]==1){
        int profit = 0+knapsack2(C,i-1);
        memo[C][i]=profit;
        pTable[C][i]='N';
        return profit;
    }


    int taken, notTaken;

    notTaken = 0+knapsack(C,i-1);
    if(C>=W[i]){
        taken = P[i]+knapsack(C-W[i],i-1);
    }else{
        taken=0;
    }

    if(notTaken>=taken){
        pTable[C][i]='N';
        memo[C][i]=notTaken;
        return notTaken;
    }else{
        pTable[C][i]='T';
        memo[C][i]=taken;
        return taken;
    }


}



void bottomUp(int C, int N){
    for(int i=1;i<=C;i++){
        for(int j=1;j<=N;j++){
            knapsack(i,j);
        }
    }

}

void printItems(int C,int i){
    if(C==0||i==0) return;
    if(pTable[C][i]=='N'){
        //cout<<"n"
        printItems(C,i-1);
    }else{
        cout<<names[i]<<" was taken"<<endl;
        printItems(C-W[i],i-1);
    }


}


void bottomUp2(int C, int N){
    for(int i=1;i<=C;i++){
        for(int j=1;j<=N;j++){
            knapsack2(i,j);
        }
    }

}



int main(){
    cout<<"Enter the capacity and number of items"<<endl;
    int C,N;
    cin>>C>>N;
    cout<<"Enter the name, price, weight and expired flag"<<endl;
    for(int i=1;i<=N;i++){
        cin>>names[i];
        cin>>P[i];
        cin>>W[i];
        cin>>expired[i];
    }


    cout<<"You entered"<<endl;
    for(int i=1;i<=N;i++){
        cout<<names[i]<<" "<<P[i]<<" "<<W[i]<<" "<<expired[i]<<endl;
    }

    initMemo(C,N);
    bottomUp(C,N);
    printMemo(C,N);
    printItems(C,N);
    cout<<"Total profit = "<<memo[C][N]<<endl;

    initMemo(C,N);
    bottomUp2(C,N);
    printMemo(C,N);
    printItems(C,N);
    cout<<"Total profit = "<<memo[C][N]<<endl;

    return 0;
}

/*
5
4
SilverCoin 3 2 0
BronzeStatue 4 3 1
AncientScroll 5 4 0
JeweledCrown 6 5 1
*/


















#include<iostream> k1
using namespace std;
string names[100];
int W[100];
int P[100];

int memo[100][100];
char pTable[100][100];

void initMemo(int C,int N){
    for(int i=0;i<=C;i++){
        for(int j=0;j<=N;j++){
            if(i==0||j==0){
                memo[i][j]=0;
            }else{
                memo[i][j]=-1;
            }
        }
    }

}

void printMemo(int C,int N){
    for(int i=0;i<=C;i++){
        for(int j=0;j<=N;j++){
            cout<<memo[i][j]<<"\t";
        }
        cout<<"\n";
    }

}


int knapsack(int C, int i){
    if(C==0||i==0){
        return 0;
    }

    if(memo[C][i]!=-1){
        return memo[C][i];
    }

    int taken,notTaken;
    notTaken = 0+knapsack(C,i-1);
    if(C>=W[i]){
        taken=P[i]+knapsack(C-W[i],i-1);
    }else{
        taken = 0;
    }

    if(notTaken>=taken){
        memo[C][i]=notTaken;
        pTable[C][i]='N';
        return notTaken;
    }else{
        memo[C][i]=taken;
        pTable[C][i]='T';
        return taken;
    }
}

void bottomUP(int C, int N){
    for(int i=1;i<=C;i++){
        for(int j=1;j<=N;j++){
            knapsack(i,j);
        }
    }

}

void printItems(int C,int N){
    if(C==0||N==0) return;

    if(pTable[C][N]=='N'){
        //cout<<""
        printItems(C,N-1);
    }else{
        cout<<names[N]<<" was taken"<<endl;
        printItems(C-W[N],N-1);
    }

}

int knapsack2(int C, int i){
    if(C==0||i==0){
        return 0;
    }


    if(memo[C][i]!=-1){
        return memo[C][i];
    }

    if(names[i][0]=='A'||names[i][0]=='E'||names[i][0]=='I'
       ||names[i][0]=='O'||names[i][0]=='U'||names[i][0]=='a'
       ||names[i][0]=='e'||names[i][0]=='i'||names[i][0]=='o'
       ||names[i][0]=='u'){
            int value = 0+knapsack(C,i-1);
            memo[C][i]=value;
            pTable[C][i]='N';
            return value;

       }


    int taken,notTaken;
    notTaken = 0+knapsack(C,i-1);
    if(C>=W[i]){
        taken=P[i]+knapsack(C-W[i],i-1);
    }else{
        taken = 0;
    }

    if(notTaken>=taken){
        memo[C][i]=notTaken;
        pTable[C][i]='N';
        return notTaken;
    }else{
        memo[C][i]=taken;
        pTable[C][i]='T';
        return taken;
    }
}

void bottomUP2(int C, int N){
    for(int i=1;i<=C;i++){
        for(int j=1;j<=N;j++){
            knapsack2(i,j);
        }
    }

}


int main(){
    cout<<"Enter the Capacity and Items"<<endl;
    int C, N;
    cin>>C>>N;

    cout<<"Enter the names, prices and weights\n";
    for(int i=1;i<=N;i++){
        cin>>names[i]>>P[i]>>W[i];
    }

    cout<<"You entered:\n";
    for(int i=1;i<=N;i++){
        cout<<names[i]<<" "<<P[i]<<" "<<W[i]<<endl;
    }
    cout<<"Solution using the basic knapsack function\n";
    initMemo(C,N);
    bottomUP(C,N);
    printMemo(C,N);
    printItems(C,N);
    cout<<"Total profit = "<<memo[C][N]<<endl;
    cout<<"Solution using the MODIFIED knapsack function\n";
    initMemo(C,N);
    bottomUP2(C,N);
    printMemo(C,N);
    printItems(C,N);
    cout<<"Total profit = "<<memo[C][N]<<endl;

    return 0;
}

/*
5 4
RubyRing 3 2
Emerald 4 3
Amulet 5 4
GoldenIdol 6 5
*/












#include<iostream> r0
using namespace std;
int P[100]; 
int memo[100];
int pTable[100];

void initMemo(){
    memo[0]=0;
    for(int i=1;i<=99;i++){
        memo[i]=-1;
    }
}
void printMemo(int L){
    cout<<"********************"<<endl;
    for(int i=0;i<=L;i++){
        cout<<memo[i]<<" ";
    }
    cout<<"\n********************"<<endl;
}

void printPtable(int L){
    cout<<"********************"<<endl;
    for(int i=0;i<=L;i++){
        cout<<pTable[i]<<" ";
    }
    cout<<"\n********************"<<endl;
}

void printCuts(int L){

}

int RodCutting(int L){
    if(L==0) return 0;
    if (memo[L]!=-1) return memo[L];

    int maxValue = INT_MIN;
    int maxValueCut;
    for(int i=1;i<=L;i++){
        int value = P[i]+RodCutting(L-i);
        if(value>maxValue){
            maxValue=value;
            maxValueCut = i;
        }
    }
    memo[L]=maxValue;
    pTable[L]=maxValueCut;
    return maxValue;
}

void bottomUp(int L){
    
}

int main(){
    cout<<"Enter the rod length"<<endl;
    int L;
    cin>>L;
    for(int i=1;i<=L;i++){
        cin>>P[i];
    }
    initMemo();
    printMemo(L);

    int result = RodCutting(L);
    printMemo(L);
    printPtable(L);
    return 0;
}

/*
4
1 2 8 9
*/













#include <stdio.h>
#include <ctype.h>

char *digitWords[]={"zero","one","two","three","four","five","six","seven","eight","nine"};

void transform(char s[],int i){
    if(s[i]=='\0'){
        printf("\n");
        return;
    }
    if(isalpha(s[i])){
        printf("%c",s[i]);
        transform(s,i+1);
    }
    else if(isdigit(s[i])){
        int d=s[i]-'0';
        printf("%c%s",s[i],digitWords[d]);
        transform(s,i+1);
    }
    else transform(s,i+1);
}

int main(){
    char s[100];
    scanf("%[^\n]",s);
    transform(s,0);
    return 0;
}













#include <stdio.h>
#include <ctype.h>

int upperCount=0, lowerCount=0;

void countCase(char a[],int l,int r){
    if(l>r) return;
    if(l==r){
        if(isupper(a[l])) upperCount++;
        else if(islower(a[l])) lowerCount++;
        return;
    }
    int m=(l+r)/2;
    countCase(a,l,m);
    countCase(a,m+1,r);
}

int main(){
    int n; 
    scanf("%d",&n);
    char a[100];
    for(int i=0;i<n;i++) scanf(" %c",&a[i]);
    countCase(a,0,n-1);
    printf("Number Of Uppercase Letters:%d\n",upperCount);
    printf("Number Of Lowercase Letters:%d\n",lowerCount);
    return 0;
}
















#include <stdio.h>
#include <ctype.h>

void reverseString(char s[], int i){
    if(s[i]=='\0') return;
    reverseString(s,i+1);
    char ch = s[i];
    if(ch>='A' && ch<='Z') ch = ch + 32;
    printf("%c", ch);
}

int main(){
    char s[200];
    scanf("%[^\n]",s);
    reverseString(s,0);
    printf("\n");
    return 0;
}












#include <stdio.h>
#include <ctype.h>

int specialCount=0, numCount=0;

void countChars(char a[],int l,int r){
    if(l>r) return;
    if(l==r){
        if(isdigit(a[l])) numCount++;
        else if(!isalpha(a[l]) && !isdigit(a[l])) specialCount++;
        return;
    }
    int m=(l+r)/2;
    countChars(a,l,m);
    countChars(a,m+1,r);
}

int main(){
    int n; 
    scanf("%d",&n);
    char a[200];
    for(int i=0;i<n;i++) scanf(" %c",&a[i]);
    countChars(a,0,n-1);
    printf("Number Of special characters : %d\n",specialCount);
    printf("Number Of numerical characters : %d\n",numCount);
    return 0;
}












#include<iostream>
using namespace std;

int values[100];
int memo[100][100];
char pTable [100][100];

void initMemo(int M,int N){
    for(int i=0;i<=M;i++){
        for(int j=0;j<=N;j++){
            if(i==0){
                memo[i][j]=0;
            }else if(j==0){
                memo[i][j]=INT_MAX;
            }else{
                memo[i][j]=-1;
            }
        }
    }
}

void printMemo(int M,int N){
    cout<<"*********memo***********"<<endl;
    for(int i=0;i<=M;i++){
        for(int j=0;j<=N;j++){
            cout<<memo[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<"\n*********memo***********"<<endl;
}

int CoinChange(int M, int N){
    if(M<0){
        return INT_MAX;
    }
    if(M>0 && N==0){
        return INT_MAX;
    }
    if(M==0){
        return 0;
    }

    if(memo[M][N]!=-1){
        return memo[M][N];
    }

    int taken,notTaken;

    notTaken = 0+CoinChange(M,N-1);
    int retValue = CoinChange(M-values[N],N-1);

    if(retValue==INT_MAX){
        taken=retValue;
    }else{
        taken = 1+retValue;
    }

    if(notTaken<=taken){
        memo[M][N]= notTaken;
        pTable[M][N]='N';
        return notTaken;
    }else{
        memo[M][N]= taken;
        pTable[M][N]='T';
        return taken;
    }

}

void bottomUp(int M, int N){
    for(int i=1;i<=M;i++){
        for(int j=1;j<=N;j++){
            CoinChange(i,j);
        }
    }

}

void printCoins(int M,int N){
    if(M==0||N==0) return;

    if(pTable[M][N]=='N'){
        cout<<"coin no "<<N<<" ("<<values[N]<<") was NOT taken"<<endl;
        printCoins(M,N-1);
    }else{
        cout<<"coin no "<<N<<" ("<<values[N]<<") was taken"<<endl;
        printCoins(M-values[N],N-1);
    }


}

int main(){
    int M,N;
    cout<<"Enter the money you want to pay and the number of coins\n";
    cin>>M>>N;
    cout<<"Enter the coin values(denominations)\n";
    for(int i=1;i<=N;i++){
        cin>>values[i];
    }
    cout<<"You entered the coin values\n";
    for(int i=1;i<=N;i++){
        cout<<values[i]<<" ";
    }

    initMemo(M,N);


    bottomUp(M,N);
    printMemo(M,N);
    printCoins(M,N);

    return 0;
}

/*

*/

