int
main() {
  int                a, b, c ; /* definisco le variabili intere a, b, c */
  long  int          d, e, f ; /* interi "lunghi" */
  short int          g, h    ; /* interi "corti" */
  unsigned int       i ; /* interi senza segno */
  unsigned short int j ; /* interi "corti" senza segno */
  
  unsigned
  long 
  int k ; /* interi "lunghi" senza segno */

  float r = 0.5f;       /* numero con virgola piccolo*/
  double g = 0.3;      /* numero con virgola grande */
  long double t = 0.00001; /* numero con virgola grande "lunghi" */

  char c = 'r'; /* Singolo carattere */

  /* si possono usare le forme contratte 
   unsigned int       = unsigned
   long int           = long
   short int          = short
   signed int         = int
   unsigned long int  = unsigned long
   unsigned short int = unsigned short
  */

  /* operazioni sugli interi */
  a = b + c ; /* somma */
  a = b - c ; /* differenza */
  a = b * c ; /* prodotto */
  a = b / c ; /* divisione intera  10/4 ==> 2 */
  a = b % c ; /* resto della divisione 20 % 3 ==> 2 
                 infatti 20 = 3*6 + 2 */
  
  /* Operazioni logiche*/
  a = 2;
  b = 0;
  c = (a && b); // c = 0 - AND logico
  c = (a || b); // c = 1 - OR logio
  c = (!a);     // c = 0 - NOT logico

    // Esempio complesso di utilizzo delle condizioni logiche
    d = 3;
    e = 12;
    c = (d < e) && (a > b); // c = 1
    c = !(d < e) && (a > b); // c = equivalente a (d >= e) && (a> b)


  return 0 ; 
}

/*
  per compilarlo uso su macchine UNIX
  > gcc esempio2.c -o esempio2
*/