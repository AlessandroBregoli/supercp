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
		long offsetFile;
		bool outIsCartella;
		bool valida();		
		char* bufferone;			
		long dimBufferone;
};
