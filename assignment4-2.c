int my_strcmp (char* s, char* t) {
    if (strlen(s) != strlen(t)) return 1;
    
    while (*s != '\0' || *t != '\0') {
        *s++;
        *t++;
        if (*s == *t) continue;
        else return 1;
        }
    return 0;
}
