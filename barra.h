class Barra{
	public:
		static const int STANDARD_CARACHTERS = 6;
		
		Barra(int max);
		bool change_state(int val);
		
	private:
		int max;
		int val;
		int num_states_bar;
		int state_bar;
		void clear_bar();
		void print_bar();
};
