class Copia{
	public:
		void ciao();
		Copia(char in[], char out[]);
		bool superCopia();
		const int dimBuffer = 4096;
	private:
		char* in;
		char* out;
		int dimFile;
		bool outIsCartella;
		bool valida();
		unsigned char* bufferone;
};
