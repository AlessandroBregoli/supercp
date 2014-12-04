class Copia{
	public:
		void ciao();
		Copia(char in[], char out[]);
	private:
		char* in;
		char* out;
		int dimFile;
		bool outIsCartella;
		bool valida();
};
