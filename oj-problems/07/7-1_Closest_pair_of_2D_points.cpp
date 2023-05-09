#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>

using namespace std;

typedef pair<int, int> Point;

/**
 * @brief 計算兩點之間的距離
 *
 * @param p1
 * @param p2
 * @return double
 */
double euclidean_distance(const Point &p1, const Point &p2)
{
    return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
}

/**
 * @brief 處理點數小於等於 3 的情況
 *
 * @param points
 * @return double
 */
double brute_force(const vector<Point> &points)
{
    double min_distance = numeric_limits<double>::max();
    for (size_t i = 0; i < points.size(); ++i)
    {
        for (size_t j = i + 1; j < points.size(); ++j)
        {
            min_distance = min(min_distance, euclidean_distance(points[i], points[j]));
        }
    }
    return min_distance;
}

/**
 * @brief 處理兩個點分別在左右兩邊的情況
 *
 * @param px
 * @param py
 * @param delta
 * @return double
 */
double closest_split_pair(const vector<Point> &px, const vector<Point> &py, double delta)
{
    int mid_x = px[px.size() / 2].first;
    vector<Point> sy;
    for (const auto &point : py)
    {
        if (mid_x - delta <= point.first && point.first <= mid_x + delta)
        {
            sy.push_back(point);
        }
    }
    double best = delta;
    for (size_t i = 0; i < sy.size() - 1; ++i)
    {
        for (size_t j = i + 1; j < min(i + 7, sy.size()); ++j)
        {
            best = min(best, euclidean_distance(sy[i], sy[j]));
        }
    }
    return best;
}

/**
 * @brief 分治法求最近點對
 *
 * @param px
 * @param py
 * @return double
 */
double closest_pair_rec(const vector<Point> &px, const vector<Point> &py)
{
    if (px.size() <= 3)
    {
        return brute_force(px);
    }
    size_t mid = px.size() / 2;
    vector<Point> qx(px.begin(), px.begin() + mid);
    vector<Point> rx(px.begin() + mid, px.end());
    vector<Point> qy, ry;
    for (const auto &point : py)
    {
        if (find(qx.begin(), qx.end(), point) != qx.end())
        {
            qy.push_back(point);
        }
        else
        {
            ry.push_back(point);
        }
    }
    double delta = min(closest_pair_rec(qx, qy), closest_pair_rec(rx, ry));
    return closest_split_pair(px, py, delta);
}

/**
 * @brief 計算最近點對的距離
 *
 * @param points
 * @return double
 */
double closest_pair(const vector<Point> &points)
{
    vector<Point> px = points, py = points;
    sort(px.begin(), px.end(), [](const Point &p1, const Point &p2)
         { return p1.first < p2.first; });
    sort(py.begin(), py.end(), [](const Point &p1, const Point &p2)
         { return p1.second < p2.second; });
    return closest_pair_rec(px, py);
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int m;
        cin >> m;
        vector<Point> points(m);
        for (int j = 0; j < m; ++j)
        {
            cin >> points[j].first >> points[j].second;
        }
        printf("%.3f\n", closest_pair(points));
    }
    return 0;
}
