/* クイックソート 作成日:2018/5/1 作成者:d1410 川上健吾 */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define  N  10 // データ数

// 関数のプロトタイプ宣言
void print_data(int *pdata);
void quicksort(int *pdata, int left, int right);

// メイン関数
int main(void)
{
    	// 変数と配列の宣言
	int i;
    	int D[N];
	clock_t start,end;
	double jikan;	
    
   	// データの生成
	srand(time(NULL)); // 実行時の時刻で乱数系列を初期化
	for(i=0; i<N; i++){
		D[i]=(rand()*rand())%(10*N); // 0～(10*N)-1 の乱数を生成
	}
	
	// データの表示
	printf("ソート前: ");
	print_data(D);
	printf("*************************\n");
	
	// 計測開始
	start=clock();
	
	// クイックソート
	quicksort(D, 0, N-1); // D[0]～D[N-1]を整列
	
	// 計測終了
	end=clock();
	
	// データの表示
	printf("*************************\n");
	printf("ソート後: ");
	print_data(D);
	
	// 処理時間を表示
	jikan=(double)(end-start)/CLOCKS_PER_SEC;
	printf("処理時間=%.3f[s]\n",jikan);//小数点以下三桁で表示
	
	return 0;
}

//関数quicksortの定義
void quicksort(int *pdata, int left, int right)
{
	int pl=left;  // plは左カーソルを表す
	int pr=right; // prは右カーソルを表す
	int pivot=*(pdata+left); // 基準値は先頭の要素とする *(pdata+left)はD[left]を表す
	int i,temp;
	
	// 途中経過の出力
	printf("途中経過: ");
	print_data(pdata);
	printf("pivot=%d\n", pivot);
	
	//左右のグループに分割する
	do{
		// 左カーソルが指す値D[pl]が基準値より小さい間
		while( *(pdata+pl) < pivot ){ 
			pl++; // 左カーソルを右に進める
		}
		
		// 右カーソルが指す値D[pr]が基準値より大きい間
		while( *(pdata+pr) > pivot ){ 
			pr--; // 右カーソルを左に進める
		}
		
		// 左カーソルが右カーソルより左にあるとき両方を交換する
		if( pl <= pr ){
			// 途中経過の出力
			printf("%dと%dを交換する\n", *(pdata+pl), *(pdata+pr)); 
			
			// 要素の交換
			// plが指す要素*(pdata+pl)とprが指す要素*(pdata+pr)を交換する
			temp = *(pdata+pl);
			*(pdata+pl) = *(pdata+pr);
			*(pdata+pr) = temp;
			
			// 左右のカーソルを進める
			pl++; // 左カーソルを右に進める
			pr--; // 右カーソルを左に進める
		}
	}while( pl <= pr ); // plとprが交叉すれば(pr=pl-1となれば)分割終了
	
	// 再帰呼出し
	if( left < pr ){  // 左側のグループD[left]～D[pr]を整列
		quicksort(pdata,left,pr);
	}
	if( pl < right ){ // 右側のグループD[pl]～D[right]を整列
		quicksort(pdata,pl,right);
	}
}

// 関数print_dataの定義（配列データを表示する関数）
void print_data(int *pdata)
{
	// 変数宣言
	int i;
	
	// 配列の各要素を表示する
	for(i=0; i<N; i++){
		printf("%d ", *(pdata+i));
	}
	printf("\n"); // 改行
}