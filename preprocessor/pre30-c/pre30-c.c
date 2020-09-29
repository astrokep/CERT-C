/**
 * PRE30-C: 
 * Do not create a universal character name through concatenation.
 * 
 * Risk:
 * Creating a universal character through token concatenation 
 * results in undefined behavior.
 * 
 * Severity: LOW
 * Likelihood: UNLIKELY
 * Cost: MED
 * 
 * Priority: P2
 * Level: L3
**/
#define RUN_BAD_EXAMPLE     0
#define RUN_GOOD_EXAMPLE    1

/**
 * BAD EXAMPLE
**/
#if RUN_BAD_EXAMPLE
#define assign(uc1, uc2, val) uc1##uc2 = val
int bad_example(){
    int \u0401;
    assign(\u4, 01, 4);
}
#endif

/**
 * GOOD EXAMPLE
**/
#if RUN_GOOD_EXAMPLE
#define assign(ucn, val) ucn = val;
int good_example(){
    int \u0401;
    assign(\u0401, 4);
}
#endif

/**
 * Test Bench:
**/
int main(){
#if RUN_BAD_EXAMPLE
    bad_example();
#endif
#if RUN_GOOD_EXAMPLE
    good_example();
#endif
}
