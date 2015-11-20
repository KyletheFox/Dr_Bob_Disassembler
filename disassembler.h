#define MEMSIZE    1000       /* 1000 words of memory                 */
#define WORDSIZE      4       /* each word is 4 digits                */
#define WORDLIMIT  9999       /* change this if you change WORDSIZE   */
#define MAXCNT     1000       /* limit execution to 1000 instructions */

/* SIM1 operation codes (plus JMP) with format naaa where       */
/* aaa is a 3-digit address and n is as follows:                */
#define HALT       0          /* halt processor                 */
#define LD         1          /* load %r0 (%r0=M[aaa])          */
#define ST         2          /* store %r0 (M[aaa]=%r0)         */
#define ADD        3          /* add to %r0 (%r0=%r0+M[aaa])    */
#define SUB        4          /* sub from %r0 (%r0=%r0-M[aaa])  */
#define LDA        5          /* load address (%r0=aaa)         */
#define JMP        6          /* jump (branch) to address       */
#define SKIPSET    7          /* skip instructions              */
#define ONEREG     8          /* one register instructions      */
#define TWOREG     9          /* two register instructions      */

/* SIM2 skip operation codes with format 7n0r where r is a general    */
/* register and n is as follows:                                      */
#define SKIP       0          /* unconditional skip                   */
#define SKEQ       1          /* skip if %r equals 0                  */
#define SKNE       2          /* skip if %r not equal to 0            */
#define SKGT       3          /* skip if %r greater than 0            */
#define SKGE       4          /* skip if %r greater or equal to  0    */
#define SKLT       5          /* skip if %r less than 0               */
#define SKLE       6          /* skip if %r less than or equal to 0   */

/* One register operation codes (format 8n0r, where r is a general    */
/* register (%r0 to %r9) and n is as follows:                         */
#define IN         0          /* input a 4-digit number into %r       */
#define OUT        1          /* output the 4-digit number from %r    */
#define CLR        2          /* clear register r (%r = 0)            */
#define INC        3          /* increment (add 1) to %r (%r++)       */
#define DEC        4          /* decrement (subtract 1) from %r       */
#define NEG        5          /* negate %rn (%r = -%r)                */
#define SHFTL      6          /* shift %r left (%r=%r*10)             */
#define SHFTR      7          /* shift %r right (%r=%r/10)            */
                              /* return is (pop %r9)                  */
/* Two register operation codes %r0 to %r9 (%r0=acc,%r7=sp,%r8=lk,%r9=ip)  */
/* with format 9nsd, where:                                                */
                              /* s is the first (source) general register  */
                              /* d is the second (destination) register    */
                              /* n is as follows                           */
#define MVRR       0          /* load from register, Rs => Rd              */
#define MVMR       1          /* load using reg addr, memory(Rs) => Rd     */
#define MVRM       2          /* store using reg adr, Rs => memory(Rd)     */
#define EXCH       3          /* exchange values in Rs and Rd, Rs <=> Rd   */
#define ADDR       4          /* add register, Rs + Rd => Rd               */
#define SUBR       5          /* subtract register, Rd - Rs => Rd          */
