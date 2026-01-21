#include <stdio.h>

int main() {
    int i;
    double t = 0.0;
    double x = 0.1;     // 初期値（ここを変えてCase1,2,3を試す）
    double dt = 0.01;
    double r = 0.5;     // 増殖率
    double k = 10.0;    // 環境収容力

    // ★変更点1：ファイルを扱うための変数を準備
    FILE *fp; 
    
    // ★変更点2： "data.csv" という名前のファイルを書き込み用("w")で開く
    // 注意：同じ場所に同名のファイルがあると上書きされます
    fp = fopen("data.csv", "w"); 

    if (fp == NULL) {
        printf("ファイルを開けませんでした。\n");
        return 1;
    }

    // ★変更点3：画面ではなく、ファイル(fp)に向かって書き込む
    fprintf(fp, "time, x\n"); 

    // 2000ステップ計算
    for (i = 0; i <= 2000; i++) {
        // ★変更点4：ここも fprintf に変えてファイルに書き込む
        fprintf(fp, "%lf, %lf\n", t, x);

        // 竹コースの微分方程式
        double dxdt = r * x * (1.0 - x / k) - (x * x) / (1.0 + x * x);

        // オイラー法更新
        x = x + dxdt * dt;
        t = t + dt;

        if (x < 0) x = 0;
    }

    // ★変更点5：使い終わったファイルを閉じる（超重要）
    fclose(fp); 

    // 終わったことがわかるように画面に一言だけ出す
    printf("計算が終わり、data.csv に結果を保存しました。\n");

    return 0;
}