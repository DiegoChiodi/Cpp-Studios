#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    const int MAXV = 100000;
    int freq[MAXV + 1] = {0};

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        freq[x]++;
    }

    // encontrar os dois valores mais frequentes
    int max1 = -1, max2 = -1;
    for (int i = 0; i <= MAXV; i++) {
        if (freq[i] > 0) {
            if (max1 == -1 || freq[i] > freq[max1] ||
               (freq[i] == freq[max1] && i < max1)) {
                max2 = max1;
                max1 = i;
            } else if (max2 == -1 || freq[i] > freq[max2] ||
                      (freq[i] == freq[max2] && i < max2)) {
                max2 = i;
            }
        }
    }

    long long best_qtd = -1;
    int best_a = 0, best_b = 0;

    for (int i = 0; i <= MAXV; i++) {
        if (freq[i] >= 2) {
            long long qtd = 1LL * freq[i] * (freq[i] - 1) / 2;
            if (qtd > best_qtd ||
               (qtd == best_qtd && (i < best_a || (i == best_a && i < best_b)))) {
                best_qtd = qtd;
                best_a = best_b = i;
            }
        }

        int j = (i == max1 ? max2 : max1);
        if (j != -1 && freq[i] > 0 && freq[j] > 0 && i < j) {
            long long qtd = 1LL * freq[i] * freq[j];
            if (qtd > best_qtd ||
               (qtd == best_qtd && (i < best_a || (i == best_a && j < best_b)))) {
                best_qtd = qtd;
                best_a = i;
                best_b = j;
            }
        }
    }

    cout << best_a << " " << best_b << " " << best_qtd << "\n";
    return 0;
}
