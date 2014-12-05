class Copia{
	public:
		void ciao();
		Copia(char in[], char out[]);
		bool superCopia();
		long DIMBUFFER;
	private:
		char* in;
		char* out;
		long dimFile;
		bool outIsCartella;
		bool valida();		
		char* bufferone;			
		size_t dimBufferone;
};
