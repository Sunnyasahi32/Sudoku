#include "testCommon.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int existErrorCount = 0;
static int totalTestCount = 0;

void testStart(char *mes) { fprintf(stderr, "== Test %s ==\n", mes); }

void testErrorCheck() {
    if (existErrorCount == 0) {
        fprintf(stderr,
                "All tests are Ok. [# of Tests = %d, # of pass = %d (%d%%)]\n",
                totalTestCount, totalTestCount, 100);
    } else {
        int p = totalTestCount - existErrorCount;
        fprintf(stderr,
                "###### Error exist!!!! [# of Tests = %d, # of pass = %d "
                "(%d%%)] ######\n",
                totalTestCount, p, p * 100 / totalTestCount);
        exit(1);
    }
}

void assertEqualsIntFunc(int a, int b, char *fname, int line) {
    totalTestCount++;
    if (a != b)
        messend4("Error in %s(%d): a != b (%d != %d)\n", fname, line, a, b);
}

void assertNotEqualsIntFunc(int a, int b, char *fname, int line) {
    totalTestCount++;
    if (a == b)
        messend4("Error in %s(%d): a == b (%d == %d)\n", fname, line, a, b);
}

void assertEqualsFloatFunc(float a, float b, char *fname, int line) {
    totalTestCount++;
    if (isnan(a) || isnan(b))
        messend4("Error in %s(%d): a(%f) or b(%f) is NaN\n", fname, line, a, b);
    if (fabs(a - b) > DELTA)
        messend4("Error in %s(%d): a != b (%f != %f)\n", fname, line, a, b);
}

void assertEqualsDoubleFunc(double a, double b, char *fname, int line) {
    totalTestCount++;
    if (isnan(a) || isnan(b))
        messend4("Error in %s(%d): a(%f) or b(%f) is NaN\n", fname, line, a, b);
    if (fabs(a - b) > DELTA)
        messend4("Error in %s(%d): a != b (%f != %f)\n", fname, line, a, b);
}

void assertEqualsIntArrayFunc(int *ap, int *bp, int n, char *fname, int line) {
    int i;
    for (i = 0; i < n; i++) {
        totalTestCount++;
        if (ap[i] != bp[i])
            messend6("Error in %s(%d): a[%d] != b[%d] (%d != %d)\n", fname, line, i, i, ap[i], bp[i]);
    }
}

void assertEqualsStringFunc(char *ap, char *bp, char *fname, int line) {
    totalTestCount++;
    if (strcmp(ap, bp) != 0)
        messend4("Error in %s(%d): ap != bp\nap = %s\nbp = %s\n", fname, line, ap, bp);
}

void assertEqualsPointerFunc(void *ap, void *bp, char *fname, int line) {
    totalTestCount++;
    if (ap != bp)
        messend4("Error in %s(%d): ap != bp\nap = %p\nbp = %p\n", fname, line, ap, bp);
}
