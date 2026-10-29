#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_VALUES 32 //Cchange depending on vvalues

typedef struct {
    char type;
    int  values[MAX_VALUES]; //to store the parsed data
    int  count;
} Record;

/* Parses "C;92;237;...;0;" into rec. Returns true on success. */
bool parse_record(const char *str, Record *rec)
{
    rec->count = 0;

    if (str[0] == '\0' || str[1] != ';') {
        return false;                 /* need "X;" at the start */
    }
    rec->type = str[0];

    const char *p = str + 2;          /* first number */
    while (*p != '\0' && rec->count < MAX_VALUES) {
        char *end;
        long value = strtol(p, &end, 10);
        if (end == p) {
            break;                    /* no number here: stop */
        }
        rec->values[rec->count++] = (int)value;
        p = (*end == ';') ? end + 1 : end;
    }
    return true;
}

int main(void)
{
    Record rec;
    if (parse_record("C;92;237;76;236;76;241;101;310;92;160;11;52;0;0;0;0;0;0;1;", &rec)) {
        printf("Type %c, %d values\n", rec.type, rec.count);
        for (int i = 0; i < rec.count; i++) {
            printf("%d ", rec.values[i]);
        }
        printf("\n");
    }
    return 0;
}


/* 
//  Example Usage on Device
//-----------------------------------------------

    String line = Serial.readStringUntil('\n');
    Record rec;
    if (parse_record(line.c_str(), &rec)) {
        // use rec.type, rec.values[i], rec.count
    }

*/