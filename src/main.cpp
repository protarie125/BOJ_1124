#include <iostream>
#include <vector>

using namespace std;

using vb = vector<bool>;
using vi = vector<int>;

constexpr auto maxN = int{ 100001 };
auto sieve = vb(maxN, true);
auto primes = vi{};

void initSieve() {
	primes.reserve(maxN);

	sieve[0] = false;
	sieve[1] = false;

	for (int i = 2; i < maxN; ++i) {
		if (sieve[i]) {
			primes.push_back(i);

			auto j = i + i;
			while (j < maxN) {
				sieve[j] = false;

				j += i;
			}
		}
	}
}

bool isUnderprime(int i) {
	auto f = vi{};
	f.reserve(20);

	while (1 < i) {
		for (const auto& p : primes) {
			if (0 == i % p) {
				f.push_back(i);
				i /= p;
				break;
			}
		}
	}

	return sieve[f.size()];
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	initSieve();

	int a, b;
	cin >> a >> b;

	auto ans = int{ 0 };
	for (int i = a; i <= b; ++i) {
		if (isUnderprime(i)) {
			++ans;
		}
	}

	cout << ans;

	return 0;
}