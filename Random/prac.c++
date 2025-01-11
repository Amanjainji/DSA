#include <iostream>
#include <string>

void printAllSubstrings(const std::string& str) {
    int n = str.length();
    
    // Generate all possible substrings
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            std::cout << str.substr(i, j - i) << std::endl;
        }
    }
}

int main() {
    std::string input="Hist";

    std::cout << "All possible substrings:" << std::endl;
    printAllSubstrings(input);

    return 0;
}

/*
#include <iostream>
#include <unordered_map>
#include<string>

int romanToInt(const std::string& s) {
    // Map to hold the Roman numeral values
    std::unordered_map<char, int> romanMap = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

    int total = 0;
    int prevValue = 0;

    // Iterate through each character in the string
    for (char ch : s) {
        int currentValue = romanMap[ch];

        // If the previous value is less than the current value, we need to subtract
        if (prevValue < currentValue) {
            total += (currentValue - 2 * prevValue); // Adjust the total by subtracting the previous value twice
        } else {
            total += currentValue;
        }

        // Update previous value
        prevValue = currentValue;
    }

    return total;
}

int main() {
    std::string roman="IX";


    int integerValue = romanToInt(roman);

    std::cout << "The integer value is: " << integerValue << std::endl;

    return 0;
}
*/
/*
#include <iostream>
#include<string>

void reverseWords(char str[]) {
    int start = 0;
    int end = 0;

    // First, reverse the entire string
    while (str[end] != '\0') {
        end++;
    }
    end--; // Move to the last character

    // Reverse the entire string
    for (int i = 0; i < end; i++, end--) {
        std::swap(str[i], str[end]);
    }

    // Reverse each word in the reversed string
    end = 0;
    while (str[end] != '\0') {
        if (str[end] == ' ') {
            end++;
            continue;
        }

        start = end;
        while (str[end] != ' ' && str[end] != '\0') {
            end++;
        }

        // Reverse the current word
        int wordEnd = end - 1;
        for (int i = start; i < wordEnd; i++, wordEnd--) {
            std::swap(str[i], str[wordEnd]);
        }
    }
}

int main() {
    const int maxLength = 100; // Maximum length of the input string
    char input[maxLength]="I love programming";
    reverseWords(input);
    std::cout << "Reversed order of words: " << input << std::endl;

    return 0;
}

*/
/*
#include<iostream>
using namespace std;

int Linear(int *arr,int size,int key){
    if(size==0){
        return -1;
    }

    if(arr[size-1]==key){
        return size-1;
    }
    else{
        return Linear(arr,size-1,key);
    }
}

int* merge(int *arr1,int n1,int *arr2,int n2){
    int i=0,j=0,k=0;
    int* ans=new int[n1+n2];
    while(i<n1 && j<n2){
        if(arr1[i]<arr2[j]){
            ans[k++]=arr1[i++];
        }
        else {
            ans[k++]=arr2[j++];
        }
    }

    while(i<n1){
        ans[k++]=arr1[i++];
    }
    while(j<n2){
        ans[k++]=arr2[j++];
    }

    return ans;
}


void rotate(int *arr,int n,int k){
    while(k>0){
    int temp=arr[n-1];
    int i=n-1;
    while(i>0){
        arr[i]=arr[i-1];
        i--;
    }
    arr[0]=temp;
    k--;
    }
}

bool anagram(string s1,string s2){
    
    int hash[26]={0};
    for(int i=0;i<s1.length();i++){
        if(s1[i]==' '){
            continue;
        }
        int k=s1[i]-'a';
        hash[k]=hash[k]+1;
    }

    for(int i=0;i<s2.length();i++){
        if(s1[i]==' '){
            continue;
        }
        int k=s2[i]-'a';
        hash[k]=hash[k]-1;
    }

    for(int i=0;i<26;i++){
        if(hash[i]!=0){
           return false;
        }
    }

return true;
}
int main(){
    int arr[4]={1,2,5,6};
    int arr2[3]={3,4,7};
    //cout<<Linear(arr,6,2);

    //int *arr3=merge(arr,4,arr2,3);

    string s1="anagram";
    string s2="ganpmar";
    cout<<anagram(s1,s2);

    //rotate(arr,4,2);
    
}*/