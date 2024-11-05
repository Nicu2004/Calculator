#include <stdio.h>
//se va determina lungimea sirului pentru a putea fi ulterior parcurs
int string_Len(char* str) {
	int length = 0;
	while (*str != '\0') {
		length++;
		str++;
	}
	return length;
}

int main() {
	char str[101];

	fgets(str, sizeof(str), stdin);	
										//aici se va citi sirul iindiferent daca este sanu nu spatiu gin.get in cpp
	int length = string_Len(str);
	int a, s = 0;
	char operator = '+';				// se va initializa cu + ca defailt pentru a aduna numerele la s.

	for (int i = 0; i < length; i++) {
		// se parcurge sirul caracter cu acaracter
		if (str[i] >= '0' && str[i] <= '9') {
			a = str[i] - '0';			//se va converti numar cracter in integer
			int j = i + 1;				//in caz ca sunt mai multe numere dupa primul se va parcuve cu alta variabila j=i+1, de la umramtorul adic 
			while (j < length && str[j] >= '0' && str[j] <= '9') {
				a = a * 10 + (str[j] - '0');
				j++;					//aici numarul se constrieetse, daca este mai mare de o cifra
			}
			i = j - 1;					// i se actualizeaza pentru a putea parcurge mai departe.

				// aici de utilizeaza operatorul de operatie.
			switch (operator) {
			case '+': s += a; break;
			case '-': s -= a; break;
			case '*': s *= a; break;
			case '/': s = (a != 0) ? s / a : 0; break;
			}
		}

		//aici se verifica care este urmatorul operator si se va folosi in switch.
		if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {
			operator = str[i];
		}
	}

	printf("%d\n", s);
	return 0;
}
