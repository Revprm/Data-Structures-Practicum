#include <iostream>
#include <cmath>
#include <climits>
#include <vector>
#include <float.h>
#include <iomanip>
#define Fast ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double PI = acos(-1);

int main() {
    Fast
    cout << fixed << setprecision(3);
    int n;
    while (cin >> n) {
        if (n == -1) return 0;
        double x[n], y[n], r[n];

        for (int i = 0; i < n; i++) {
            cin >> x[i] >> y[i] >> r[i];
        }

        vector<double> weight(n + 1, DBL_MAX);
        vector<bool> visited(n + 1, 0);

        weight[0] = 0;
        double ans = 0;

        while (1) {
            int tmp = -1;
            double tmpmax = DBL_MAX;

            for (int i = 0; i < n; i++) {
                if (!visited[i] && weight[i] < tmpmax) {
                    tmpmax = weight[i];
                    tmp = i;
                }
            }
            if (tmp == -1) break; visited[tmp] = 1;
    
            for (int j = 0; j < n; j++) {
                if (tmp == j || visited[j]) continue;

                double nx = x[tmp] - x[j];
                double ny = y[tmp] - y[j];
                double adn = sqrt((nx * nx) + (ny * ny));
                double selisih = r[tmp] - r[j];
                double singgung = sqrt(adn * adn - (selisih * selisih));
                double alf = asin(abs(selisih) / adn);
                double lenWire = PI * (r[tmp] + r[j]) + 2 * singgung + 2 * alf * abs(selisih);

                if (lenWire < weight[j]) weight[j] = lenWire;
            }
        }

        for (int i = 0; i < n; i++) {
            ans += weight[i];
        }
        cout << ans << '\n';
    }

    return 0;
}
