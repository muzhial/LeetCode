#include "../common.hpp"
using std::vector;

/**
* [desc]
* 有 N 个 信 和 信封，它们被打乱，求错误装信方式的数量。
* [分析]
* 错排是指每个都在错误位置
* dp[n] = (n - 1) * dp[n - 1] + (n - 1) * dp[n - 2]
*/
