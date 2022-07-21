#include<bits/stdc++.h>
string writeAsYouSpeak(int n) 
{
    string num = "1";
	for(int i=1; i<n; i++){
        int len = num.size();
        string newnum = "";
        for(int i=0; i<len; i++){
            int count = 1;
            while(num[i] == num[i+1]){
                i++;
                count++;
            }
            newnum += to_string(count);
            newnum += num[i];
        }
        num = newnum;
    }
    return num;
}