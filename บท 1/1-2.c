#include <stdio.h>

int main() {

int score;
int ok;

ok = scanf("%d",&score);

if(ok!=1){
    printf("Error");
    return 0;
}

if(score<0 || score>100){
    printf("Error");
    return 0;
}

if(score>=80){
    printf("Grade A");
}
else if(score>=70){
    printf("Grade B");
}
else if(score>=60){
    printf("Grade C");
}
else if(score>=50){
    printf("Grade D");
}
else{
    printf("Grade F");
}

return 0;
}