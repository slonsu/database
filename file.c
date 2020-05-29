#include <stdio.h>
#include <string.h>



int QueryValidator (char arr[100], int type) {

    /*
    0 = select
    1 = update
    2 = insert
    3 = create
    4 = delete    
    5 = drop
    */

    // Select from employees where 

    char *select = "SELECT";
    char *from = "FROM";
    //char update[12] = "UPDATE Customers SET ContactName = 'Alfred Schmidt', City= 'Frankfurt';
    char *delete = "DELETE";
    char *drop = "DROP";
    char insert[83] = "INSERT INTO table_name (column1, column2, column3) VALUES (value1, value2, value3)";
    char create[52] = "CREATE TABLE table_name (column1, column2, column3)";

    char *where = "WHERE";
    char *and = "AND";
    char *or = "OR";

    char conditionpart1[100];
    char conditionpart2[100];
    char conditionpart3[100];

    char tablename[100];
//    printf("%d\n",strlen(arr));
//   printf("%d\n",strlen(select));

    char delim[] = " ";
    char *ptr = strtok(arr, delim);
        
        switch (type)
        {
        case 0:
            ; //не удалять
            

            for (int i = 0; ptr != NULL; i++){
                if (i == 0 && strcmp(select, ptr) != 0){
                    //printf("hereerror2");
                    return 0;//ошибка
                }
                if (i == 1 && strcmp(from, ptr) != 0){
                    //printf("hereerrorss3");
                    return 0;//ошибка
                }
                if (i == 2){
                    memcpy (tablename, ptr, 20);
                    //printf("hereerrorss4");
                }                
                if (i == 3 && strcmp(where, ptr) != 0){
                    //printf("hereerrorss5");
                    ptr = strtok(NULL, delim);                    
                    return 0;                    
                }                
                if (i == 4){
                    //printf("hereerrorss6");
                    memcpy (conditionpart1, ptr, 20);
                }
                if (i == 5 && (strcmp("=",ptr) || strcmp(">",ptr) || strcmp("<",ptr))){
                    //printf("hereerrorss7");
                    memcpy (conditionpart2, ptr, 20);
                }
                if (i == 6){
                    //printf("hereerrorss8");
                    memcpy (conditionpart3, ptr, 20);
                }
                //printf("'%s'\n", ptr);
                ptr = strtok(NULL, delim);

                if (i >= 3 && i <= 5 && ptr == NULL){
                    printf("Where condition is incorrect");
                    return 0;
                }
            }
        
            break;
        
        case 1:
            /* code */
            break;
        
        case 2:
            /* code */
            break;
        
        case 3:
            /* code */
            break;
        
        case 4:
            ; //не удалять

            for (int i = 0; ptr != NULL; i++) {
                if (i == 0 && strcmp(drop, ptr) != 0){
                    //printf("hereerror2");
                    return 0;//ошибка
                }
                if (i == 1){
                    memcpy (tablename, ptr, 20);
                    //printf("hereerrorss4");
                }  

                //printf("'%s'\n", ptr);
                ptr = strtok(NULL, delim);
            }
            break;
        
        case 5:
            ; //не удалять

            for (int i = 0; ptr != NULL; i++){
                if (i == 0 && strcmp(delete, ptr) != 0){
                    //printf("hereerror2");
                    return 0;//ошибка
                }
                if (i == 1 && strcmp(from, ptr) != 0){
                    //printf("hereerrorss3");
                    return 0;//ошибка
                }
                if (i == 2){
                    memcpy (tablename, ptr, 20);
                    //printf("hereerrorss4");
                }                
                if (i == 3 && strcmp(where, ptr) != 0){
                    //printf("hereerrorss5");
                    ptr = strtok(NULL, delim);                    
                    return 0;                    
                }                
                if (i == 4){
                    //printf("hereerrorss6");
                    memcpy (conditionpart1, ptr, 20);
                }
                if (i == 5 && (strcmp("=",ptr) || strcmp(">",ptr) || strcmp("<",ptr))){
                    //printf("hereerrorss7");
                    memcpy (conditionpart2, ptr, 20);
                }
                if (i == 6){
                    //printf("hereerrorss8");
                    memcpy (conditionpart3, ptr, 20);
                }
                //printf("'%s'\n", ptr);
                ptr = strtok(NULL, delim);

                if (i >= 3 && i <= 5 && ptr == NULL){
                    printf("Where condition is incorrect");
                    return 0;
                }
            }

            break;
        }
        //
        //    Добавить чеки валидности
        //
    
    printf("Your table: %s\n", tablename);
    printf("Your condition: %s", conditionpart1);
    printf("%s", conditionpart2);
    printf("%s\n", conditionpart3);
    
    return 0;
}
int main (void) {
    char array[100];
    printf("Enter a string\n");
    scanf("%[^'\n']s", array);

    int type;
    for (int i = 0; i < 2; i++) {
        if (i == 0){
            if (array[i] == 'S'){
                type = 0;
            }
            else if (array[i] == 'U'){
                type = 1;
            }
            else if (array[i] == 'I'){
                type = 2;
            }            
            else if (array[i] == 'C'){
                type = 3;
            }
            else if (array[i] == 'D' && array[i+1] == 'R'){
                type = 4;
            }
            else if (array[i] == 'D' && array[i+1] == 'E'){
                type = 5;
            }
            else {
                printf("Wrong input!");
                return 0;
            }
        }
        if (array[i] == ' ') {
            
        }
    }
    if (QueryValidator(array,type) == 0 ){
        printf("Something went wrong Querry Exception");
    };

    //printf("Your string: %s\n", array);
    return 0;
}