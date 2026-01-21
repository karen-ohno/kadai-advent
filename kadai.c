#include <stdio.h>

int main() {
    int i;
    double t = 0.0;
    double x = 10;     // 昆虫の初期個体数（0より大きい値）
    double dt = 0.01;   // 時間刻み幅
    
    // パラメータの設定（ここを色々変えて考察する）
    double r = 0.5;     // 増殖率
    double k = 10.0;    // 環境収容力

    printf("time, x\n"); // ヘッダー

    // 2000ステップ計算（t = 20.0まで）
    for (i = 0; i <= 2000; i++) {
        // 現在のtとxを表示
        printf("%lf, %lf\n", t, x);

        // 竹コースの微分方程式
        // dxdt = 増殖項 - 捕食項
        double dxdt = r * x * (1.0 - x / k) - (x * x) / (1.0 + x * x);

        // オイラー法による更新
        x = x + dxdt * dt;
        t = t + dt;

        // 個体数がマイナスにならないよう保護（念のため）
        if (x < 0) x = 0;
    }

    return 0;
}