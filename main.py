import numpy as np
import matplotlib.pyplot as plt
import japanize_matplotlib

# 関数定義
def g(x):
    return x / (1 + x**2)

def f(x, r, k):
    return r * (1 - x / k)

# xの範囲
x = np.linspace(0, 12, 400)
k = 10  # 環境収容力は固定

# パラメータ設定
r_values = [0.3, 0.52, 0.8] # 低い、中くらい（3点）、高い
titles = ["パターンA: 沈静期 (r=0.3)", "パターンB: 複数平衡点 (r=0.52)", "パターンC: アウトブレイク (r=0.8)"]
intersections_counts = ["交点: 1つ (低密度)", "交点: 3つ (低・中・高)", "交点: 1つ (高密度)"]

plt.figure(figsize=(15, 5))

for i, r in enumerate(r_values):
    plt.subplot(1, 3, i+1)
    
    # プロット
    plt.plot(x, g(x), label='捕食: x/(1+x^2)', color='steelblue', linewidth=2)
    plt.plot(x, f(x, r, k), label=f'増殖: {r}(1-x/{k})', color='darkorange', linewidth=2, linestyle='--')
    
    # グラフ装飾
    plt.ylim(0, 0.6)
    plt.xlim(0, 11)
    plt.title(titles[i], fontsize=14, fontweight='bold')
    plt.xlabel('昆虫の個体数 x')
    if i == 0:
        plt.ylabel('率 (Rate)')
    plt.grid(True, linestyle=':', alpha=0.6)
    plt.legend()
    
    # 説明テキスト
    plt.text(5, 0.5, intersections_counts[i], fontsize=12, 
             bbox=dict(facecolor='white', alpha=0.8))

plt.tight_layout()
plt.show()