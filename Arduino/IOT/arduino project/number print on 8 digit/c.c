int botao1 = A0; // Pino do botao1
int botao2 = A1;
int j = 0; // Variável usada como contador
int estadobotao1 = 0; // Variada usada para verificar se o botao1 foi pressionado
int estadobotao2 = 0;
// Matriz de bits para representar os números de 0 a 9:
int numero[11][8] = { { 1,1,1,1,1,1,0 },  //DIGITO 0
                                 { 0,1,1,0,0,0,0 },  //DIGITO 1
                                 { 1,1,0,1,1,0,1 },  //DIGITO 2
                                 { 1,1,1,1,0,0,1 },  //DIGITO 3
                                 { 0,1,1,0,0,1,1 },  //DIGITO 4
                                 { 1,0,1,1,0,1,1 },  //DIGITO 5
                                 { 1,0,1,1,1,1,1 },  //DIGITO 6
                                 { 1,1,1,0,0,0,0 },  //DIGITO 7
                                 { 1,1,1,1,1,1,1 },  //DIGITO 8
                                 { 1,1,1,0,0,1,1 }  //DIGITO 9
                                 };
// Configurar os pinos digitais associados a cada segmento:
const int segmentos[8] = { 2,3,4,5,6,7,8,9 };
// 2 = segmento a
// 3 = segmento b
// 4 = segmento c
// 5 = segmento d
// 6 = segmento e
// 7 = segmento f
// 8 = segmento g
// 9 = ponto decimal
void setup() {
  pinMode(botao1, INPUT);
  pinMode(botao2, INPUT);
 // Configurando os pinos de cada segmento para saída:
 for (int i = 0; i <= 7; i++) {
   pinMode(segmentos[i], OUTPUT);
 }
  mostraNumero(0); // exibe o número 0
}
void loop() {
  estadobotao1 = digitalRead(botao1); // vrifica o estado do botao1
  estadobotao2 = digitalRead(botao2);
  if (estadobotao1 != 1) { // caso o botao1 foi pressionado
    j = j + 1;         //  incrementa o contador j
  }
  if (estadobotao2 != 1) {
    j = j - 1;
  }
  if (j > 9) { j = 0;} // evita que o j fique maior que 9
  mostraNumero(j);     // exibe o número armazenado no contador
  delay(100);     // aguarda um décimo de segundo
}

// Implementando a função mostraNumero, que exibe os numeros em sequência a cada 1 segundo:
void mostraNumero(int valor) { // valor é a linha da matriz (número a mostrar)
 int pino = 2; // começar contagem no pino 2
 for (int i = 0; i < 8; i++) {
 digitalWrite(pino, numero[valor][i]); // fixa na linha e aciona os bits de cada coluna (0 ou 1)
 pino++;
 }
}
