typedef struct string *String;
String StringInit(char *);
void StringDestroy(String);
int StringCmp(String, String);
String StringCat(String, String);
String StringCopy(String, String);
int StringLen(String);
void StringPrint(String);
