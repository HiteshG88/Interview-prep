#include <iostream>
#include <string>
using namespace std;

void piRecursion(char a[], int i){

    if(a[i] == '\0' and a[i+1] == '\0')
        return;

    // look for pi in current location.
    if(a[i] == 'p' and a[i+1] == 'i'){

        int j = i+2;

        // take j to the last char index.
        while(a[j] != '\0')
            j++;

        // shift all char after i to 2 places ahead.
        while(j >= i+2){
            a[j+2] =  a[j];
            j--;
        }

        a[i] = '3';
        a[i+1] = '.';
        a[i+2] = '1';
        a[i+3] = '4';

        piRecursion(a,i+4);
    }
    else{
        piRecursion(a,i+1);
    }
    return;
}

int main(){
    char ch[] = "axcpicdfpibghpiapi";
    piRecursion(ch,0);

    cout << ch;
    return 0;
}
