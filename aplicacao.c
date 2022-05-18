/* aplicacao.c
./aplicacao < file.in > file.out
*/

#include <stdio.h>
#include <stdlib.h>

#include "aplicacao.h"
#include "types.h"
#include "color_queue.h"


#define INPUT_CHAR_MAX_SIZE    30U

/******************************/
/*        Static data         */
/******************************/

p_color_queue_t p_color_queue_materials[COLOR_N];
p_color_queue_t p_color_queue_mold;
p_color_queue_t p_color_queue_pieces_good;
p_color_queue_t p_color_queue_pieces_bad;

int materials_count[COLOR_N];
int mold_count;

/******************************/
/* Local functions prototypes */
/******************************/

/* Factory setup procedure */
int factory_setup( void );

/* Print factory output */
void factory_print(void);

/* Print color string code */
void color_string_code_print(color_t color);

/* Get color from string code */
int string_code_color_get(char * string_code, color_t * color);

/* Get color string code from color*/
int color_string_code_get(color_t color, char * out);


/***********************/
/* Main implementation */
/***********************/

int main (int argc, char **argv) {
    printf("PC = [pam1 pam2 paz3 pam4 paz5 pve6 pvo7 pvo8 pve9 pvo10 pve11 pam12 pve13 pve14 pam15 pvo16 pve17 pam18 pvo19 pve20]\n");
    printf("PD = [d_1 d_2 d_3 d_4 d_5 d_6 d_7 d_8 d_9 d_10 d_11 d_12 d_13 d_14 d_15 d_16 d_17 d_18 d_19 d_20 d_21 d_22 d_23 d_24 d_25 d_26 d_27 d_28 d_29 d_30 d_31 d_32 d_33 d_34 d_35 d_36 d_37 d_38 d_39 d_40 d_41 d_42 d_43 d_44 d_45 d_46 d_47 d_48 d_49 d_50]\n");
}

/***********************************/
/* Local functions implementations */
/***********************************/

/* Factory setup procedure */
int factory_setup( void ){

    /* Create all color queues */
    int total_material_count = 0;
    for(uint16_t color_id=0; color_id<COLOR_N; color_id++){
        if(FAIL == color_queue_init(&(p_color_queue_materials[color_id]), materials_count[color_id]) return FAIL;
        total_material_count += materials_count[color_id];
    }

    if(FAIL == color_queue_init(&p_color_queue_mold, mold_count) return FAIL;
    if(FAIL == color_queue_init(&p_color_queue_pieces_good, total_material_count) return FAIL;
    if(FAIL == color_queue_init(&p_color_queue_pieces_bad, total_material_count) return FAIL;
}

/* Print factory output */
void factory_print(void){}

/* Print color string code */
void color_string_code_print(color_t color){
    char color_string[3];

    if(SUCCESS == color_string_code_get(color, color_string)){
        printf("%s",color_string);
    }
}

/* Get color from string code */
int string_code_color_get(char * string_code, color_t * color){
    if(     string_code[0] == 't' && string_code[1] == ' ') *color = COLOR_TEMP;
    else if(string_code[0] == 'a' && string_code[1] == 'z') *color = COLOR_AZUL;
    else if(string_code[0] == 'a' && string_code[1] == 'm') *color = COLOR_AMARELO;
    else if(string_code[0] == 'a' && string_code[1] == 'n') *color = COLOR_ANIL;
    else if(string_code[0] == 'p' && string_code[1] == 'r') *color = COLOR_PRETO;
    else if(string_code[0] == 'b' && string_code[1] == 'r') *color = COLOR_BRANCO;
    else if(string_code[0] == 'v' && string_code[1] == 'e') *color = COLOR_VERDE;
    else if(string_code[0] == 'v' && string_code[1] == 'o') *color = COLOR_VERMELHO;
    else if(string_code[0] == 'l' && string_code[1] == 'i') *color = COLOR_LILAS;
    else if(string_code[0] == 'r' && string_code[1] == 'o') *color = COLOR_ROSA;
    else if(string_code[0] == 'l' && string_code[1] == 'a') *color = COLOR_LARANJA;
    else return FAIL;

    return SUCCESS;
}

/* Get color string code from color*/
int color_string_code_get(color_t color, char * out){
    if(     COLOR_TEMP     == color) strcpy(out, "t");
    else if(COLOR_AZUL     == color) strcpy(out, "az");
    else if(COLOR_AMARELO  == color) strcpy(out, "am");
    else if(COLOR_ANIL     == color) strcpy(out, "an");
    else if(COLOR_PRETO    == color) strcpy(out, "pr");
    else if(COLOR_BRANCO   == color) strcpy(out, "br");
    else if(COLOR_VERDE    == color) strcpy(out, "ve");
    else if(COLOR_VERMELHO == color) strcpy(out, "vo");
    else if(COLOR_LILAS    == color) strcpy(out, "li");
    else if(COLOR_ROSA     == color) strcpy(out, "ro");
    else if(COLOR_LARANJA  == color) strcpy(out, "la");
    else return FAIL;

    return SUCCESS;
}