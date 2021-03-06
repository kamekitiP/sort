﻿/* バブルソート 作成日:2018/05/07 作成者:D1410 川上健吾 */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 10 //データ数

//関数のプロトタイプ宣言
void print_data(int *pdata);

//メイン関数
int main(void)
{
	//変数と配列の宣言
	int D[N];
	int i,j,imin,temp;
	clock_t start,end;//clock_t型の変数
	double jikan;//処理時間を格納する変数
	
	
	//データの生成
	srand(time(NULL)); //実行時の時刻で乱数系列を初期化
	for(i=0; i<N; i++){
		D[i]=(rand()*rand())%(10*N); //0以上(10*N)未満の乱数を生成
	}
	
	//データの表示
	printf("ソート前: \n");
	print_data(D);
	
	//計測開始
	start=clock();
	
	//バブルソート
	for(i=0; i<N-1; i++){
		for(j=0; j<N-i-1; j++){
			//要素の比較
			if(D[j] > D[j+1]){
				//要素の交換（D[j]とD[j+1]を交換する）
				temp=D[j];
				D[j]=D[j+1];
				D[j+1]=temp;
			}
		}
	}
	
	//計測終了
	end=clock();
	
	//データの表示
	printf("ソート後: \n");
	print_data(D);
	
	//処理時間を表示
	jikan=(double)(end-start)/CLOCKS_PER_SEC;
	printf("処理時間=%.3f[s] \n",jikan);//小数点以下三桁で表示
	
	return 0;
}

//関数print_dataの定義（配列データを表示する関数）
void print_data(int *pdata)
{
	int i;
	
	//配列の各要素を表示する
	for(i=0; i<N; i++){
		printf("%d ", *(pdata+i));
	}
	printf("\n"); //改行
}