#ifndef COIN
#define COIN

#include <boost/random.hpp> // Convenience header file
#include <iostream>
#include <ctime>			// std::time
#include <vector>

using namespace std;

void Coin(long times,double p)//p: Probability of head
{
	// A. Define the lagged Fibonacci and Normal objects
	boost::lagged_fibonacci607 rng;
	rng.seed(static_cast<boost::uint32_t> (std::time(0)));
	boost::uniform_real<> uni(0.0, 1.0);

	boost::variate_generator<boost::lagged_fibonacci607&, boost::uniform_real<> >
		uniRng(rng, uni);

	vector<int> Coin_Store;
	Coin_Store.reserve(200);

	vector<int> blank = Coin_Store;

	int total_times = 0;

	for (int i = 0; i < times; i++)
	{
		Coin_Store = blank;

		for (int n = 0; n < 10000; n++)
		{
			double outcome = uniRng();

			if (outcome <= p)
			{
				Coin_Store.push_back(1);
			}

			if (outcome <= 1.0 && outcome > p)
			{
				Coin_Store.push_back(0);
			}


			if (n >= 1)
			{
				if (Coin_Store[n] == Coin_Store[n - 1] && Coin_Store[n] == 1)
				{
					total_times = total_times + n + 1;
					break;
				}
			}

		}
	}

	std::cout << "Expection: " << double(total_times) / double(times) << endl;

}



#endif
