class Copia{
	public:
		void ciao();
		Copia(char in[], char out[]);
		bool superCopia();
		long DIMBUFFER;
	private:
		char* in;
		char* out;
		size_t dimFile;
		bool outIsCartella;
		bool valida();		
		char* bufferone;			
		long dimBufferone;
};
