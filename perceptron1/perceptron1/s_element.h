#include <iostream>
#include <vector>

class Neuron {
private:
	std::vector <double> input_val;
	std::vector <double> weights;
	double ref_val = 0.8;
	bool activate_flag;
	short out_val;

public:
	Neuron(std::vector <double> input,bool flag, short out) :
		input_val(input),
		activate_flag(flag),
		out_val(out)
	{}
	
	void get_weights(short N) {
		weights.resize(N);
		for (auto& i : weights) i = 0.5;
		return;
	}

	double multiplie() {
		double res = 0;

		for (auto& i : input_val)
		for (auto& j : weights) {
			res += i*j;
		}

		return res;
	}

	bool activate(double val) {
		double res = 1 / (1 + exp(-1 * val));

		if (activate_flag) return res > ref_val;
		else return res <= ref_val;
	}

	void output(bool flag) {
		if (flag) {
			if (activate_flag) std::cout << 1;
			else std::cout << 0;
		}

		return;
	}
};