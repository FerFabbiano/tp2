#include "CounterThread.h"

void CharCounter::run() {
	int result_temp = 0;
	printf("Busco '%c' sobre %s\n", this->countChar, this->filename.c_str());
	FILE* fd = fopen(this->filename.c_str(), "r");
	char readChar;
	while (fread(&readChar, 1, 1, fd)){
		if (readChar == this->countChar) {
			result_temp ++;
		}
	}
	result.inc(result_temp);
	fclose(fd);
}

CharCounter::CharCounter(const char* filename, char countChar, ResultProtected &result) :
	filename(filename), countChar(countChar), result(result){}

/*
void CharCounter::printResult() const {
	printf("%s tiene %d letras '%c'\n", this->filename.c_str(), this->result, this->countChar);
}
*/

/*
int CharCounter::getResult() const {
	return this->result;
}
*/