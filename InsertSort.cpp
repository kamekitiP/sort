/* 挿入ソート 作成日:2018/04/16 作成者:D1410 川上健吾 */

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
	int i,j,x;
	clock_t start,end;//clock_t型の変数
	double jikan;//処理時間を格納する変数
	
	printf("挿入ソートで昇順に並び替えます。\n");
	
	//データの生成
	srand(time(NULL)); //実行時の時刻で乱数系列を初期化
	for(i=0; i<N; i++){
		D[i]=(rand()*rand())%(10*N); //0～(10*N)-1 の乱数を生成
	}
	
	//データの表示
	printf("ソート前: ");
	print_data(D); //配列Dの先頭アドレスを渡す
	
	//計測開始
	start=clock();
	
	//挿入ソート
	for(i=1; i<N; i++){ //未整列の要素について
		x=D[i]; //x: 挿入する値
		j=i;     //j: 挿入する場所の要素番号
		while( D[j-1]>x && j>0 ){ //挿入する値xと整列済みデータD[j-1]を比較
			D[j]=D[j-1]; //D[j-1]の方が大きければ，その値を右にずらす
			j--; //jを左にずらす
		}
		D[j]=x; //xを挿入する
		//printf("i=%d, 挿入する値 x=%d, 途中経過: ",i,x);
		//print_data(D); //配列Dの先頭アドレスを渡す
	}
	
	//計測終了
	end=clock();
	
	//データの表示
	printf("ソート後: ");
	print_data(D); //配列Dの先頭アドレスを渡す
	
	//処理時間を表示
	jikan=(double)(end-start)/CLOCKS_PER_SEC;
	printf("処理時間=%.3f[s] \n",jikan);//小数点以下三桁で表示
	
	return 0;
}

void print_data(int *pdata)
{
	int i;
	
	for(i=0;i<N;i++){
		printf("%d ",*(pdata+i));
	}
	printf("\n");
}
