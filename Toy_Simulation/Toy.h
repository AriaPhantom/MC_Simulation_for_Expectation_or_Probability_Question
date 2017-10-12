#ifndef TOY
#define TOY

#include <boost/random.hpp> // Convenience header file
#include <iostream>
#include <ctime>			// std::time
#include <vector>

using namespace std;


vector<int> unique_element_in_vector(vector<int> v)
{
	vector<int>::iterator vector_iterator;
	sort(v.begin(), v.end());
	vector_iterator = unique(v.begin(), v.end());
	if (vector_iterator != v.end()) {
		v.erase(vector_iterator, v.end());
	}
	return v;
}


bool is_element_in_vector(vector<int> v, int element) {
	vector<int>::iterator it;
	it = find(v.begin(), v.end(), element);
	if (it != v.end()) {
		return true;
	}
	else {
		return false;
	}
}


void Toy(int times)
{
	// A. Define the lagged Fibonacci and Normal objects
	boost::lagged_fibonacci607 rng;
	rng.seed(static_cast<boost::uint32_t> (std::time(0)));
	boost::uniform_real<> uni(0.0, 4.0);

	boost::variate_generator<boost::lagged_fibonacci607&, boost::uniform_real<> >
		uniRng(rng, uni);

	vector<int> Toy_Store;
	Toy_Store.reserve(200);

	vector<int> blank = Toy_Store;
	
	int total_times = 0;

	for (int i = 0; i < times; i++)
	{
		Toy_Store = blank;

		for (int n = 0; n < 10000; n++)
		{
			double outcome = uniRng();

			if (outcome <= 1.0)
			{
				Toy_Store.push_back(1);
			}

			if (outcome <= 2.0 && outcome > 1.0)
			{
				Toy_Store.push_back(2);
			}

			if (outcome <= 3.0 && outcome > 2.0)
			{
				Toy_Store.push_back(3);
			}

			if (outcome <= 4.0 && outcome > 3.0)
			{
				Toy_Store.push_back(4);
			}

			Toy_Store = unique_element_in_vector(Toy_Store);

			if (Toy_Store.size() == 4)
			{
				total_times = total_times + n + 1;
				break;
			}

		}
	}

	std::cout << "Expection: " << double(total_times) / double(times) << endl;



}

#endif
