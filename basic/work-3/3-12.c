#include <stdio.h>

#define THRESHOLD 150.0f  // limit

// net damage
static float net_damage(int atk, int armor) {
    float red = (armor >= 50) ? 0.40f : 0.20f; // reduction
    return (atk * 10.0f) * (1.0f - red);       // apply
}

int main(void) {
    int cases = 0;         // test count
    if (scanf("%d", &cases) != 1 || cases < 0) return 1; // bad input

    for (int i = 0; i < cases; ++i) {
        int atk = 0;          // atk lvl
        int enemy = 0;        // enemy lvl (unused)
        int armor = 0;        // armor
        float dmg = 0.0f;     // result

        // read one
        if (scanf("%d %d %d", &atk, &enemy, &armor) != 3) return 1;

        dmg = net_damage(atk, armor); // compute

        if (dmg >= THRESHOLD) // check
            printf("SUCCESS! Net Damage: %.2f\n", dmg);
        else
            printf("FAIL. Deficit: %.2f\n", THRESHOLD - dmg);
    }

    return 0; // ok
}
