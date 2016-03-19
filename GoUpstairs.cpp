/*
题目描述

现在有一栋高楼，但是电梯却出了故障，无奈的你只能走楼梯上楼，根据你的腿长，你一次能走1级或2级楼梯，已知你要走n级楼梯才能走到你的目的楼层，请计算你走到目的楼层的方案数，由于楼很高，所以n的范围为int范围内的正整数。

给定楼梯总数n，请返回方案数。为了防止溢出，请返回结果Mod 1000000007的值。

测试样例：
3
返回：3
*/
class GoUpstairs {
    const static int MOD = 1000000007;
public:
    void matMultiply(long long res[][2], long long l[][2], long long r[][2]) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                res[i][j] = 0;
                for (int m = 0; m < 2; m++) {
                    res[i][j] += l[i][m] * r[m][j] % MOD;
                }
            }
        }
    }
 
    void matrixPower(long long res[2][2], long long mat[2][2], int n) {
        res[0][0] = res[1][1] = 1;
        res[0][1] = res[1][0] = 0;
        long long tmp[2][2];
        while (n > 0) {
            if (n % 2 != 0) {
                matMultiply(tmp, res, mat);
                memcpy(res, tmp, 4*sizeof(long long));
            }
            matMultiply(tmp, mat, mat);
            memcpy(mat, tmp, 4*sizeof(long long));
            n /= 2;
        }
    }
    int countWays(int n) {
        int f[2] = { 1, 2 };
        long long t[2][2] = { 0, 1, 1, 1 };
        long long res[2][2];
        matrixPower(res, t, n - 2);
        return (f[0] * res[0][1] + f[1] * res[1][1]) % MOD;
    }
 
};
