#include <stdio.h>


/* 構造体の宣言は、struct (構造体タグ名) で行う。
 * 構造体とは、オブジェクトのようなもの。
 * 複数の変数や関数をまとめたデータの塊で、同様の内容を持つものを複数扱う場合に利用する。
 */
struct student{
    int year;
    char homeroom[100];
    int number;
    char name[100];
    double stature;
    double weight;
};

/* 構造体は、typedefを利用することで新しい方として宣言することができる。
 * typedef (宣言する型の内容、データセット) (宣言する型の名称) の形式で宣言する。
 */
typedef struct teacher_tag{
    char name[100];
    char subject[100];
} teacher;


int main(void){

    /* 構造体を実際に利用するには、構造体変数を生成しなければならない。
     * 構造体変数とは、ようするにインスタンスのこと。
     * 構造体変数は、 struct (構造体タグ名) (構造体変数名) で宣言する。
     */
    struct student student1;
    
    /* 構造体変数の中身のデータ(プロパティやメソッド)を参照するには、
     * (構造体変数名).(プロパティ名/メソッド名)と表記する。
     */
    student1.year = 15;
    sprintf(student1.name, "Harry Potter");
    sprintf(student1.homeroom, "Gryffindor");

    /* 構造体変数は、それ自体が変数なので他の変数に丸ごとコピーできる
     */
    struct student student2;
    student2 = student1;
    sprintf(student2.name, "Ronald Bilius Weasley");

    printf("student1: %s\n", student1.name);
    printf("homeroom: %s\n", student1.homeroom);
    printf("year: %d\n\n", student1.year);

    printf("student2: %s\n", student2.name);
    printf("homeroom: %s\n", student2.homeroom);
    printf("year: %d\n\n", student2.year);

    /* typedef で型として宣言された構造体は、structを付けずに構造体変数を作成できる。 */
    teacher teacher1;
    sprintf(teacher1.name, "Albus Percival Wulfric Brian Dumbledore");

    printf("teacher1: %s\n", teacher1.name);
}