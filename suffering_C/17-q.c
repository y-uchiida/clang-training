#include <stdio.h>

int main(void){

    FILE *fp;
    char list[4][100+1];
    int i;

    sprintf(list[0], "1,野比のび太,0");
    sprintf(list[1], "2,源静香,90");
    sprintf(list[2], "3,剛田武,40");
    sprintf(list[3], "4,骨川スネ夫,70");

    fp = fopen("./aset/17-q_testResult.csv", "w");

    fprintf(fp, "番号,名前,テストの平均点\n");
    for(i=0; i<4; i++){
        fprintf(fp, "%s\n", list[i]);
    }

}