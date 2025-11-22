#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void insertString(char *str, const char *insert, int pos) {
    char buffer[8192];

    strncpy(buffer, str, pos);
    buffer[pos] = '\0';

    strcat(buffer, insert);

    strcat(buffer, str + pos);

    strcpy(str, buffer);
}

int main(){
    FILE *fp = fopen("quine.java", "w");
    if (fp == NULL) {
        perror("Error opening file");
        return -1;
    }
    char c_code_orig[] = "#include <stdio.h>\\\\n#include <string.h>\\\\n#include <stdlib.h>\\\\n\\\\nvoid insertString(char *str, const char *insert, int pos) {\\\\n    char buffer[8192];\\\\n\\\\n    strncpy(buffer, str, pos);\\\\n    buffer[pos] = '\\\\\\\\0';\\\\n\\\\n    strcat(buffer, insert);\\\\n\\\\n    strcat(buffer, str + pos);\\\\n\\\\n    strcpy(str, buffer);\\\\n}\\\\n\\\\nint main(){\\\\n    FILE *fp = fopen(\\\\\\\"quine.java\\\\\\\", \\\\\\\"w\\\\\\\");\\\\n    if (fp == NULL) {\\\\n        perror(\\\\\\\"Error opening file\\\\\\\");\\\\n        return -1;\\\\n    }\\\\n    char c_code_orig[] = \\\\\\\"\\\\\\\";\\\\n    char python_code_orig[] = \\\\\\\"import json\\\\\\\\\\\\\\\\n\\\\\\\\\\\\\\\\ndef escape_for_layer(text):\\\\\\\\\\\\\\\\n    return json.dumps(text)[1:-1]\\\\\\\\\\\\\\\\n\\\\\\\\\\\\\\\\nc_code = \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\"\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\"\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\"\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\"\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\"\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\"\\\\\\\\\\\\\\\\n\\\\\\\\\\\\\\\\nc_code_escaped = c_code\\\\\\\\\\\\\\\\n\\\\\\\\\\\\\\\\nextra_layers = 3 \\\\\\\\\\\\\\\\n\\\\\\\\\\\\\\\\nfor i in range(extra_layers):\\\\\\\\\\\\\\\\n    c_code_escaped = escape_for_layer(c_code_escaped)\\\\\\\\\\\\\\\\n\\\\\\\\\\\\\\\\nc_code_final = c_code[:453] + c_code_escaped + c_code[453:]\\\\\\\\\\\\\\\\n\\\\\\\\\\\\\\\\nwith open(\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\"quine2.c\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\", \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\"w\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\") as f:\\\\\\\\\\\\\\\\n    f.write(c_code_final)\\\\\\\";\\\\n    char java_code_orig[] = \\\\\\\"import java.io.FileWriter;\\\\\\\\nimport java.io.IOException;\\\\\\\\npublic class quine {\\\\\\\\n    public static void main(String[] args) throws IOException {\\\\\\\\n        String python_code = \\\\\\\\\\\\\\\"\\\\\\\\\\\\\\\"; \\\\\\\\n        FileWriter writer = new FileWriter(\\\\\\\\\\\\\\\"quine.py\\\\\\\\\\\\\\\"); \\\\\\\\n        writer.write(python_code); \\\\\\\\n        writer.close();\\\\\\\\n    }\\\\\\\\n}\\\\\\\";\\\\n    char *c_code = malloc(8192);\\\\n    char *python_code = malloc(8192);\\\\n    char *java_code = malloc(8192);\\\\n    strcpy(java_code, java_code_orig);\\\\n    strcpy(python_code, python_code_orig);\\\\n    strcpy(c_code, c_code_orig);\\\\n    insertString(python_code, c_code, 96);\\\\n    insertString(java_code, python_code, 170);\\\\n    fprintf(fp, \\\\\\\"%s\\\\\\\", java_code);\\\\n    fclose(fp);\\\\n    return 0;\\\\n}";
    char python_code_orig[] = "import json\\n\\ndef escape_for_layer(text):\\n    return json.dumps(text)[1:-1]\\n\\nc_code = \\\"\\\"\\\"\\\"\\\"\\\"\\n\\nc_code_escaped = c_code\\n\\nextra_layers = 3 \\n\\nfor i in range(extra_layers):\\n    c_code_escaped = escape_for_layer(c_code_escaped)\\n\\nc_code_final = c_code[:453] + c_code_escaped + c_code[453:]\\n\\nwith open(\\\"quine2.c\\\", \\\"w\\\") as f:\\n    f.write(c_code_final)";
    char java_code_orig[] = "import java.io.FileWriter;\nimport java.io.IOException;\npublic class quine {\n    public static void main(String[] args) throws IOException {\n        String python_code = \"\"; \n        FileWriter writer = new FileWriter(\"quine.py\"); \n        writer.write(python_code); \n        writer.close();\n    }\n}";
    char *c_code = malloc(8192);
    char *python_code = malloc(8192);
    char *java_code = malloc(8192);
    strcpy(java_code, java_code_orig);
    strcpy(python_code, python_code_orig);
    strcpy(c_code, c_code_orig);
    insertString(python_code, c_code, 96);
    insertString(java_code, python_code, 170);
    fprintf(fp, "%s", java_code);
    fclose(fp);
    return 0;
}