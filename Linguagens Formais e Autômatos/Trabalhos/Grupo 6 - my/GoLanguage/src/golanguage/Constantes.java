package golanguage;

public interface Constantes {

    enum Token {
        NUM, ATRIB, IDENT, EOF, PTOVIRG, VAZIO, INT, FLOAT, COLON,
        ADD, SUB, MUL, QUO, AND, OR, LSS, GTR, ASSIGN, NOT, LPAREN,
        RPAREN, LBRACK, RBRACK, LBRACE, RBRACE, COMMA, PT, SEMICOLON,
        EQL, NEQ, LEQ, GEQ, DEFINE, FOR, IF, VAR;
    };
    String  DIGITOS = "0123456789",
            LETRAS = "abcdefghijklmnopqrstuvwxyzQWERTYUIOPASDFGHJKLZXCVBNM_",
            EQL = "==",
            NEQ = "!=",
            LEQ = "<=",
            GEQ = ">=",
            DEFINE = ":=",
            FOR = "for",
            IF = "if",
            EXPOENTE = "eE",
            //VAR = "var",
            VARIABLE = "0123456789abcdefghijklmnopqrstuvwxyzQWERTYUIOPASDFGHJKLZXCVBNM_",
            VAZIOS = " \r\n\t";

    char    EOL = '\\',
            COLON = ':',
            ADD = '+',
            SUB = '-',
            MUL = '*',
            QUO = '/',
            AND = '&',
            OR = '|',
            LSS = '<',
            GTR = '>',
            ASSIGN = '=',
            NOT = '!',
            LPAREN = '(',
            RPAREN = ')',
            LBRACK = '[',
            RBRACK = ']',
            LBRACE = '{',
            RBRACE = '}',
            COMMA = ',',
            PT = '.',
            SEMICOLON = ';',
            CHAR_I = 'i',
            CHAR_F = 'f',
            CHAR_O = 'o',
            CHAR_R = 'r';
    String NOME_DEFAULT_ARQUIVO_ENTRADA = "entrada.txt";
}
