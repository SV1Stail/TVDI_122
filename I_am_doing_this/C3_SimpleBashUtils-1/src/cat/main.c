#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FLAGS "benstETv"
#define FLAGS_GNU "number-nonblanknumbersqueeze-blank"
#define MAX 200
void flag_s();
void flag_T();
void flag_E();
void flag_n();
void flag_b();
void flag_v();

void print_result();
void delete_first_str_for_s();
void which_flags_we_have(char *flags_mas[], int flags_len, int *flag_b_holder, int *flag_n_holder, int *flag_s_holder ,int *flag_e_holder , int *flag_E_holder, int *flag_t_holder, int *flag_T_holder);
void print_mas_char( char *mas[], int size);
int try_to_find_incorrect_flags(char *flags_mas[MAX], int flags_len);
void separate_flags_and_paths(char *path_mas[], char *flags_mas[], int argc,  char *argv[], int* path_len, int* flags_len );
int remove_first_two_chars(char *str);
int remove_first_one_chars(char *str);
int check_flagovost(char *str);
//  1      2      3
// cat [OPTION] [FILE]...
int main (int argc, char *argv[]){
    if (argc < 4  || strcmp(argv[1], "cat")){
        printf("ошибка ввода данных, проверьте название функции и количество параметров\n");
        // printf("%d %s %s\n", argc, argv[0], argv[1]);
        return 0;
    }

char *path_mas[MAX];
char *flags_mas[MAX];
int path_len = 0, flags_len = 0;
separate_flags_and_paths(path_mas, flags_mas, argc, argv, &path_len, &flags_len);
if (try_to_find_incorrect_flags(flags_mas, flags_len)) {
    int flag_b_holder = 0, flag_n_holder = 0, flag_s_holder = 0, flag_e_holder = 0, flag_E_holder = 0, flag_t_holder = 0, flag_T_holder = 0; 
    which_flags_we_have(flags_mas, flags_len, &flag_b_holder, &flag_n_holder, &flag_s_holder, &flag_e_holder, &flag_E_holder, &flag_t_holder, &flag_T_holder);
    if (flag_b_holder && flag_n_holder) flag_n_holder = 0;
    if (flag_t_holder && flag_T_holder) flag_T_holder = 0;
    if (flag_e_holder && flag_E_holder) flag_E_holder = 0;
// printf (" flag_b_holder %d\n flag_n_holder %d\n flag_s_holder %d\n flag_e_holder %d\n flag_E_holder %d\n flag_t_holder %d\n flag_T_holder %d\n ", flag_b_holder, flag_n_holder, flag_s_holder,flag_e_holder,flag_E_holder,flag_t_holder, flag_T_holder);
    
    for (int i = 0; i < path_len; i++)
    {
        FILE *file = fopen(path_mas[i], "r");
        if (file != NULL){
        // printf("kk\n");
            FILE *tmp_file = fopen("test_new_brainy_kingsblood", "w");  
                if (tmp_file == NULL) {  // если файл не открылся, выходим с ошибкой
                    perror("File open error");
                    exit(EXIT_FAILURE);
                }else {
                    int c;
                     while ((c = fgetc(file)) != EOF) {
                        fputc((char)c, tmp_file);
                    } 
                }
            fclose(file);
            fclose(tmp_file);
            if (flag_s_holder){
                //дуйствие
                flag_s() ;
                delete_first_str_for_s();
            }
            if (flag_t_holder){
                flag_v();
                flag_T();
            }
            if (flag_T_holder){
                //дуйствие
                flag_T(); 
            }
            if (flag_e_holder){
                //дуйствие
                flag_v();
                flag_E();
            }
            if (flag_E_holder){
                //дуйствие
                flag_E();
            }
            if (flag_b_holder){
                //дуйствие
                flag_b();
            }
            if (flag_n_holder){
                //дуйствие
                flag_n();
            }
            print_result();
            remove("test_new_brainy_kingsblood");
        } else {
            printf ("путь не найден: %s ", path_mas[i]);
        }
    }

} else printf("некорректно введены флаги\n ");
return 1;
}


//определить какие сть флаги
void which_flags_we_have(char *flags_mas[], int flags_len, int *flag_b_holder, int *flag_n_holder, int *flag_s_holder ,int *flag_e_holder , int *flag_E_holder, int *flag_t_holder, int *flag_T_holder)
{
    for (int i = 0; i < flags_len; i++){
        if (strcmp(flags_mas[i], "number-nonblank") == 0) *flag_b_holder = 1;
        else if (strcmp(flags_mas[i], "number") == 0) *flag_n_holder = 1;
        else if (strcmp(flags_mas[i], "squeeze-blank") == 0) *flag_s_holder = 1;
        else{
            for(int j = 0; j < (int)strlen(flags_mas[i]); j++){
                if (strchr("b",flags_mas[i][j]) != 0) *flag_b_holder = 1;
                else if (strchr("e", flags_mas[i][j]) != 0) *flag_e_holder = 1;
                else if (strchr("E", flags_mas[i][j]) != 0) *flag_E_holder = 1;
                else if (strchr("n", flags_mas[i][j]) != 0) *flag_n_holder = 1;
                else if (strchr("s", flags_mas[i][j]) != 0) *flag_s_holder = 1;
                else if (strchr("t", flags_mas[i][j]) != 0) *flag_t_holder = 1;
                else if (strchr("T", flags_mas[i][j]) != 0) *flag_T_holder = 1;
            }
        }
    }
}

//вывести чаровый массив
void print_mas_char(char *mas[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%s ", mas[i]);
}

//проверяет введенные флаги на корректрость. Если все верны то вернёт 1 иначе 0
int try_to_find_incorrect_flags(char *flags_mas[MAX], int flags_len)
{
    int flag = 1;
    for (int i = 0; i < flags_len; i++){
        if (strcmp(flags_mas[i], "number-nonblank") != 0 && strcmp(flags_mas[i], "number") != 0 && strcmp(flags_mas[i], "squeeze-blank") != 0 ){
            for(int j = 0; j < (int)strlen(flags_mas[i]); j++){
                if (strchr(FLAGS, flags_mas[i][j]) == NULL){
                    flag = 0;
                    // printf("2 %c \n", flags_mas[i][j]);
                    break;
                }
            }
        }
    }
    return flag;
}

//отделим флаги от путей
void separate_flags_and_paths(char *path_mas[], char *flags_mas[], int argc,  char *argv[], int* path_len, int* flags_len )
{
    for (int i = 2; i < argc; i++){
        if (check_flagovost(argv[i])){
            flags_mas[*flags_len] = argv[i];
            *flags_len+=1;
            // printf("%s ",argv[i]);
        }else{
            path_mas[*path_len] = argv[i];
            *path_len+=1;
        }
    }
}

//пронумерновать только не пустые строки -b (GNU: --number-nonblank)
void flag_b()
{
    FILE *file = fopen("test_new_brainy_kingsblood", "r");  
    FILE* tmp_file = fopen("brainy_kingsblood_tmp", "w");

    int line_number = 1;
    char* line = NULL;
    size_t line_length = 0;
    while (getline(&line, &line_length, file) != -1) {
        // Записываем номер строки в выходной файл
        if (line[0] != '\n' && line[0] != '$') {
            if(line_number < 10)
                fprintf(tmp_file, "    %d ", line_number);
            else if (line_number < 100 && line_number > 9)
                fprintf(tmp_file, "   %d ", line_number);
            else if (line_number < 1000 && line_number > 999)
                fprintf(tmp_file, "  %d ", line_number);
            else if (line_number < 10000 && line_number > 9999)
                fprintf(tmp_file, " %d ", line_number);
            else if (line_number < 100000 && line_number > 99999)
                fprintf(tmp_file, "%d ", line_number);
            // Записываем содержимое строки в выходной файл
            fputs(line, tmp_file);
            ++line_number;
        } else fputs(line, tmp_file);
        // Увеличиваем счетчик номера строки
    }
    free(line);
    
    fclose(file);
    fclose(tmp_file);
    remove("test_new_brainy_kingsblood");
    rename("brainy_kingsblood_tmp", "test_new_brainy_kingsblood");
}
//пронумерновать все строки -n (GNU: --number)
void flag_n()
{
    FILE *file = fopen("test_new_brainy_kingsblood", "r");  
    FILE* tmp_file = fopen("brainy_kingsblood_tmp", "w");

    int line_number = 1;
    char* line = NULL;
    size_t line_length = 0;

    // Считываем строки из входного файла
    while (getline(&line, &line_length, file) != -1) {
        // Записываем номер строки в выходной файл
        if(line_number < 10)
            fprintf(tmp_file, "    %d ", line_number);
        else if (line_number < 100 && line_number > 9)
            fprintf(tmp_file, "   %d ", line_number);
        else if (line_number < 1000 && line_number > 99)
            fprintf(tmp_file, "  %d ", line_number);
        else if (line_number < 10000 && line_number > 999)
            fprintf(tmp_file, " %d ", line_number);
        else if (line_number < 100000 && line_number > 9999)
            fprintf(tmp_file, "%d ", line_number);
        // Записываем содержимое строки в выходной файл
        fputs(line, tmp_file);
        // Увеличиваем счетчик номера строки
        ++line_number;
    }

    // Освобождаем память, занятую строкой
    free(line);

    fclose(file);
    fclose(tmp_file);
    remove("test_new_brainy_kingsblood");
    rename("brainy_kingsblood_tmp", "test_new_brainy_kingsblood");
}
// отображает символы конца строки как $ -e GNU only: -E
void flag_E() 
{
    FILE *file = fopen("test_new_brainy_kingsblood", "r");  
    FILE* tmp_file = fopen("brainy_kingsblood_tmp", "w");
        int c;
        while ((c = fgetc(file)) != EOF) {
            if (c == '\n') {
                fputs("$\n", tmp_file);
                // printf("$\n");
            } else {
                fputc(c, tmp_file);
                // printf("%c", c);
            }
        }
    fclose(file);
    fclose(tmp_file);
    remove("test_new_brainy_kingsblood");
    rename("brainy_kingsblood_tmp", "test_new_brainy_kingsblood");


}
// сжимает несколько смежных пустых строк -s (GNU: --squeeze-blank)
void flag_s() 
{
    FILE *file = fopen("test_new_brainy_kingsblood", "r");  
    FILE* tmp_file = fopen("brainy_kingsblood_tmp", "w");
    int last_was_blank = 0;
    int c;
    while ((c = fgetc(file)) != EOF) {
        if (c == '\n') {
            if (!last_was_blank) {
                last_was_blank = 1;
                fputc(c, tmp_file);
            } else {
                // последовательность пустых строк
                fputc('\n', tmp_file);
                while ((c = fgetc(file)) == '\n') {
                    // пропустить все пустые строки
                }
                if (c != EOF) {
                    // записать первую строку не пустую строку
                    fputc(c, tmp_file);
                }
                last_was_blank = 0;
            }
        } else {
            last_was_blank = 0;
            fputc(c, tmp_file);
        }
    }
    fclose(file);
    fclose(tmp_file);
    remove("test_new_brainy_kingsblood");
    rename("brainy_kingsblood_tmp", "test_new_brainy_kingsblood");
}

void delete_first_str_for_s(){
    FILE *file = fopen("test_new_brainy_kingsblood", "r");  
    FILE* tmp_file = fopen("brainy_kingsblood_tmp", "w");
    char line[MAX];
    int line_count = 0;
    while (fgets(line, sizeof(line), file) != NULL) {
        line_count++;
        // Skip the first line if both first and second lines are empty
        if (line_count == 1 && (strlen(line) == 1 || fgets(line, sizeof(line), file) == NULL || strlen(line) == 1)) {
            continue;
        }
        // Write the line to the temporary file
        fputs(line, tmp_file);
    }
    fclose(file);
    fclose(tmp_file);
    remove("test_new_brainy_kingsblood");
    rename("brainy_kingsblood_tmp", "test_new_brainy_kingsblood");
}

//  отображает табы как ^I -t GNU: -T 
void flag_T()
{
    FILE *file = fopen("test_new_brainy_kingsblood", "r");  
    FILE* tmp_file = fopen("brainy_kingsblood_tmp", "w");
        int c;
        while ((c = fgetc(file)) != EOF) {
            if (c == '\t') {
                fputs("^I", tmp_file);
            } else {
                fputc(c, tmp_file);
            }
        }
    fclose(file);
    fclose(tmp_file);
    remove("test_new_brainy_kingsblood");
    rename("brainy_kingsblood_tmp", "test_new_brainy_kingsblood");

}

void flag_v(){
    FILE *file = fopen("test_new_brainy_kingsblood", "r");  
    FILE* tmp_file = fopen("brainy_kingsblood_tmp", "w");
    int c;
    while ((c = fgetc(file)) != EOF) {
    if (0 <= c && c <= 31 && c != '\t' && c != '\n') {
        c += 64;
        fputs("^", tmp_file);
        fputc(c, tmp_file);
    } else if (c == 127) {
        c = '?';
        fputs("^", tmp_file);
        fputc(c, tmp_file);
    } else {
        fputc(c, tmp_file);
    }
    }
    fclose(file);
    fclose(tmp_file);
    remove("test_new_brainy_kingsblood");
    rename("brainy_kingsblood_tmp", "test_new_brainy_kingsblood");
}

void print_result(){
    FILE *file = fopen("test_new_brainy_kingsblood", "r");
    int c;
    while ((c = fgetc(file)) != EOF){
        printf("%c", c);
    }
    fclose (file);
}

//проверка на флаговость | если есть - / -- и они первые и после них идет символ -> флаг
int check_flagovost(char *str) //если ret = 1 то флаг, иначе путь или просто хуйня
{ 
    int flag = 0;
if (strlen(str)  > 2 && str[0] == '-' && str[1] == '-' && str[2] != '-'){
    remove_first_two_chars(str);
    flag = 1;
}else if (strlen(str) > 1 && str[0] == '-' && str[1] != '-'){
    remove_first_one_chars (str);
    flag = 1;
}else flag = 0;
// printf("kk");
return flag;
}


int remove_first_two_chars(char *str) {
    if (str == NULL || strlen(str) < 2) {
        return 0;
    }
    memmove(str, str + 2, strlen(str) - 1);
    str[strlen(str)] = '\0';
    return 1;
}
int remove_first_one_chars(char *str) {
    if (str == NULL || strlen(str) < 1) {
        return 0;
    }
    memmove(str, str + 1, strlen(str));
    str[strlen(str)] = '\0';
    return 1;
}
