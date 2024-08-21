#include <stdio.h> 
#include <math.h>
typedef struct datetime { 
 int date; // 1-31 
 int month; // 1-12 
 int year; // 1970++ 
 int dayOfWeek; // 0-6 
 int hour; // 0-23 
 int minute; // 0-59 
 int second; // 0-59 
} datetime_t; 
/// from 1 jan 1970 00:00  
datetime_t createDate(int num) { 
    int mnDAY ; 
    datetime_t rs ; 
    rs.date=1 ;
    rs.month = 0 ;
    rs.year = 1970 ;
    ///find how many days first  /// 
    mnDAY = floor(num/(60*60*24)) ;
    num -= mnDAY*60*60*24;
    rs.hour = floor(num/(60*60)) ; 
    num -= rs.hour*60*60; 
    rs.minute = floor(num/(60)) ;
    num -= rs.minute*60;
    rs.second = num ; 
    rs.dayOfWeek = mnDAY%7 ; 
    ///find year /// 
    while(mnDAY>366){
        if((rs.year%4==0 && rs.year%100!= 0) || rs.year%400==0) {
            mnDAY-=366;
            rs.year+=1;
        }
        else{
            mnDAY-=365;
            rs.year+=1;
        }
    }
    
    ///find month ////
    for(int i=1;i<13;i++){
        if(i==1 ||i==3 ||i==5 ||i==7 ||i==8 ||i==10 ||i==12){
            if(mnDAY-31<0){
                rs.month = i ;
                break;
            }
            else{
                mnDAY -=31 ;
            }
        }
        else if (i==4 ||i==6 ||i==9 ||i==11){
           if(mnDAY-30<0){
                rs.month = i ;
                break;
            }
            else{
                mnDAY -=30 ;
            }
        }
        else{
            if((rs.year%4==0 && rs.year%100!= 0) || rs.year%400==0){
                if(mnDAY-29<0){
                    rs.month = 2 ;
                    break;
                 }
                else{
                    mnDAY -=29 ;
                }
            }
            else{
                if(mnDAY-28<0){
                    rs.month = 2 ;
                    break;
                }
                else{
                    mnDAY -=28 ;
                }
            }
        }
        
    }
    //////////////
    rs.date +=mnDAY ; 

    return rs ; 

} 
void printDate(datetime_t rr) { 
    //// pattern Thu 7 JUN 2018 12:30:28 /// 
    char days[7][10] = {"Thu","Fri","Sat","Sun","Mon","Tue","Wed"} ; 
    char month[13][10]={" ","JAN","FEB","MAR","APR","MAY","JUN","JUL","AUG","SEP","OCT","NOV","DEC"};
    printf("%s %d %s %d %02d:%02d:%02d",days[rr.dayOfWeek],rr.date,month[rr.month],rr.year, rr.hour ,rr.minute,rr.second);
} 
int main(void) { 
 datetime_t inputDate; 
 int timestamp; 
 scanf("%d", &timestamp); 
 inputDate = createDate(timestamp);  printDate(inputDate); 
 return 0; 
}

