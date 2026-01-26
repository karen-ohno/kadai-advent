#include <stdio.h>

int main() {
    int i;
    // 変数の宣言（画像のスタイルに合わせました）
    double t = 0.0;
    double x = 0.1;      // 初期値 (Caseによってここを変更: 0.1 や 12.0 など)
    double dxdt;         // 増殖速度 (画像の v1 に相当)
    
    // パラメータ設定
    double r = 0.5;      // 増殖率
    double k = 10.0;     // 環境収容力
    double dt = 0.01;    // 時間刻み

    // ファイル保存の準備（これがないとデータが消えてしまうため残しています）
    FILE *fp;
    fp = fopen("data1.csv", "w");
    

    // ヘッダー（Excelで分かりやすくするため）
    fprintf(fp, "time, x\n");
    
#include <stdio.h>

int main() {
    int i;
    // 変数の宣言（画像のスタイルに合わせました）
    double t = 0.0;
    double x = 10;      // 初期値 (Caseによってここを変更: 0.1 や 12.0 など)
    double dxdt;         // 増殖速度 (画像の v1 に相当)
    
    // パラメータ設定
    double r = 0.25;      // 増殖率
    double k = 10.0;     // 環境収容力
    double dt = 0.01;    // 時間刻み

    // ファイル保存の準備（これがないとデータが消えてしまうため残しています）
    FILE *fp;
    fp = fopen("data1.csv", "w");
    
    if (fp == NULL) {
        printf("ファイルを作成できませんでした。\n");
        return 1;
    }

    // ヘッダー（Excelで分かりやすくするため）
    fprintf(fp, "time, x\n");

    // ループ処理 (20秒分計算するので 20 ÷ 0.01 = 2000回)
    for (i = 0; i <= 2000; i++) {
        
        // 1. まず現在の値を記録・表示 (画像の printf の位置と同じ)
        fprintf(fp, "%lf, %lf\n", t, x);
        
        // 2. 変化量(速度)を計算 (画像の v1 = ... の部分)
        // 式： dx/dt = r*x*(1 - x/k) - x^2/(1 + x^2)
        dxdt = r * x * (1.0 - x / k) - (x * x) / (1.0 + x * x);

        // 3. 次の時刻の値を計算 (画像の s1 = s1 - v1*dt ... の部分)
        x = x + dxdt * dt;
        
        // 4. 時刻を進める
        t = t + dt;
        
        // マイナスにならないよう補正（生物なので0以下はありえないため）
        if (x < 0) x = 0;
    }

    fclose(fp);
    //printf("計算終了: data.csv に結果を保存しました。\n");

    return 0;
}
    // ループ処理 (20秒分計算するので 20 ÷ 0.01 = 2000回)
    for (i = 0; i <= 2000; i++) {
        
        // 1. まず現在の値を記録・表示 (画像の printf の位置と同じ)
        fprintf(fp, "%lf, %lf\n", t, x);
        
        // 2. 変化量(速度)を計算 (画像の v1 = ... の部分)
        // 式： dx/dt = r*x*(1 - x/k) - x^2/(1 + x^2)
        dxdt = r * x * (1.0 - x / k) - (x * x) / (1.0 + x * x);

        // 3. 次の時刻の値を計算 (画像の s1 = s1 - v1*dt ... の部分)
        x = x + dxdt * dt;
        
        // 4. 時刻を進める
        t = t + dt;
        
        // マイナスにならないよう補正（生物なので0以下はありえないため）
        if (x < 0) x = 0;
    }

    fclose(fp);
    //printf("計算終了: data.csv に結果を保存しました。\n");

    return 0;
}