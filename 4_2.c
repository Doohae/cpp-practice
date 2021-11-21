int my_strcmp(char* s, char* t) {   
	if (strlen(s) != strlen(t)) {
		return 1; 
	}

	while ((*s != '\0' && *t != '\0') && *s == *t) {
		s++;
		t++;
	}

	if (*s == *t) {
		return 0; 
	}

	else {
		return 1;
	}
}