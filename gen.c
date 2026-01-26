#include <stdio.h>

int main() {
    int i;
    // 変数の宣言
    double t = 0.0;
    double x = 10;      // 初期値 (Caseによってここを変更)
    double dxdt;         // 増殖速度
    
    // パラメータ設定
    double r = 0.70;      // 増殖率
    double k = 10.0;     // 環境収容力
    double dt = 0.01;    // 時間刻み

    // ファイル保存の準備
    FILE *fp;
    fp = fopen("data2.csv", "w"); // data.csv という名前で保存します
    
    if (fp == NULL) {
        printf("ファイルを作成できませんでした。\n");
        return 1;
    }

    // ヘッダー書き込み
    fprintf(fp, "time, x\n");

    // ループ処理 (2000ステップ)
    for (i = 0; i <= 2000; i++) {
        
        // 1. ファイルに現在の値を記録
        fprintf(fp, "%lf, %lf\n", t, x);
        
        // 2. 増殖速度 dx/dt を計算
        dxdt = r * x * (1.0 - x / k) - (x * x) / (1.0 + x * x);

        // 3. 次の時刻の個体数 x を計算 (オイラー法)
        x = x + dxdt * dt;
        
        // 4. 時刻を進める
        t = t + dt;
        
        // マイナス補正
        if (x < 0) x = 0;
    }

    // ファイルを閉じる
    fclose(fp);
    
    // 終了メッセージ
    printf("計算終了: data2.csv に結果を保存しました。\n");

    return 0;
}