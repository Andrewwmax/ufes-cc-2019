package golanguage;

public class MyAnalisadorLexico extends AnalisadorLexico {

    public MyAnalisadorLexico(String _nomeArquivoEntrada) {
        super(_nomeArquivoEntrada);
    }

    public void s0() {
        if (this.proxCaractere == ADD) {
            leProxCaractere();
            this.tokenReconhecido = Token.ADD;
        } else if (this.proxCaractere == SUB) {
            leProxCaractere();
            this.tokenReconhecido = Token.SUB;
        } else if (this.proxCaractere == MUL) {
            leProxCaractere();
            this.tokenReconhecido = Token.MUL;
        } else if (this.proxCaractere == QUO) {
            leProxCaractere();
            this.tokenReconhecido = Token.QUO;
        } else if (this.proxCaractere == AND) {
            leProxCaractere();
            this.tokenReconhecido = Token.AND;
        } else if (this.proxCaractere == OR) {
            leProxCaractere();
            this.tokenReconhecido = Token.OR;
        } else if (this.proxCaractere == LPAREN) {
            leProxCaractere();
            this.tokenReconhecido = Token.LPAREN;
        } else if (this.proxCaractere == RPAREN) {
            leProxCaractere();
            this.tokenReconhecido = Token.RPAREN;
        } else if (this.proxCaractere == LBRACE) {
            leProxCaractere();
            this.tokenReconhecido = Token.LBRACE;
        } else if (this.proxCaractere == RBRACE) {
            leProxCaractere();
            this.tokenReconhecido = Token.RBRACE;
        } else if (this.proxCaractere == COMMA) {
            leProxCaractere();
            this.tokenReconhecido = Token.COMMA;
        } else if (this.proxCaractere == PT) {
            leProxCaractere();
            this.tokenReconhecido = Token.PT;
        } else if (this.proxCaractere == SEMICOLON) {
            leProxCaractere();
            this.tokenReconhecido = Token.SEMICOLON;
        } else if (this.proxCaractere == ASSIGN) {
            leProxCaractere();
            sASSIGN();
        } else if (this.proxCaractere == COLON) {
            leProxCaractere();
            sCOLON();
        } else if (this.proxCaractere == LSS) {
            leProxCaractere();
            sLSS();
        } else if (this.proxCaractere == GTR) {
            leProxCaractere();
            sGTR();
        } else if (this.proxCaractere == NOT) {
            leProxCaractere();
            sNOT();
        } else if (this.proxCaractere == CHAR_I) {
            leProxCaractere();
            sIFf();
        } else if (this.proxCaractere == CHAR_F) {
            leProxCaractere();
            sFORo();
        } else if (this.proxCaractereIs(LETRAS)) {
            leProxCaractere();
            sLETRA();
        } else if (this.proxCaractere == EOL) {
            leProxCaractere();
            sEOF();
        } else if (this.proxCaractereIs(DIGITOS)) {
            leProxCaractere();
            sINT();
        } else if (this.proxCaractereIs(VAZIOS)) {
            leProxCaractere();
            s0();
        } else {
            throw new ErroLexico(this.proxCaractere, VARIABLE + VAZIOS);
        }
    }

    public void sINT() {
        this.tokenReconhecido = Token.INT;
        if (this.proxCaractereIs(DIGITOS)) {
            leProxCaractere();
            sINT();
        } else if (this.proxCaractere == PT) {
            leProxCaractere();
            sFLOAT();
        } else if (this.proxCaractereIs(EXPOENTE)) {
            leProxCaractere();
            sFLOATE();
        }
    }

    public void sFLOAT() {
        this.tokenReconhecido = Token.FLOAT;
        if (this.proxCaractereIs(DIGITOS)) {
            leProxCaractere();
            sFLOAT();
        } else if (this.proxCaractereIs(EXPOENTE)) {
            leProxCaractere();
            sFLOATE();
        }
    }

    public void sFLOATE() {
        this.tokenReconhecido = Token.FLOAT;
        if (this.proxCaractereIs(DIGITOS)) {
            leProxCaractere();
            sFLOATE();
        } else if (this.proxCaractere == ADD || this.proxCaractere == SUB) {
            leProxCaractere();
            sFLOATS();
        }
    }

    public void sFLOATS() {
        this.tokenReconhecido = Token.FLOAT;
        if (this.proxCaractereIs(DIGITOS)) {
            leProxCaractere();
            sFLOATS();
        }
    }

    public void sLETRA() {
        this.tokenReconhecido = Token.VAR;
        if (this.proxCaractere == CHAR_I) {
            leProxCaractere();
            sIFf();
        } else if (this.proxCaractere == CHAR_F) {
            leProxCaractere();
            sFORo();
        } else {
            leProxCaractere();
            sVARIABLE();
        }
    }

    public void sASSIGN() {
        this.tokenReconhecido = Token.ASSIGN;
        if (this.proxCaractere == ASSIGN) {
            leProxCaractere();
            sEQL();
        }
    }

    public void sEQL() {
        this.tokenReconhecido = Token.EQL;
    }

    public void sLSS() {
        this.tokenReconhecido = Token.LSS;
        if (this.proxCaractere == ASSIGN) {
            leProxCaractere();
            sLEQ();
        }
    }

    public void sLEQ() {
        this.tokenReconhecido = Token.LEQ;
    }

    public void sGTR() {
        this.tokenReconhecido = Token.GTR;
        if (this.proxCaractere == ASSIGN) {
            leProxCaractere();
            sGEQ();
        }
    }

    public void sGEQ() {
        this.tokenReconhecido = Token.GEQ;
    }

    public void sNOT() {
        this.tokenReconhecido = Token.NOT;
        if (this.proxCaractere == ASSIGN) {
            leProxCaractere();
            sNEQ();
        }
    }

    public void sNEQ() {
        this.tokenReconhecido = Token.NEQ;
    }

    public void sCOLON() {
        this.tokenReconhecido = Token.COLON;
        if (this.proxCaractere == ASSIGN) {
            leProxCaractere();
            sDEFINE();
        }
    }

    public void sDEFINE() {
        this.tokenReconhecido = Token.DEFINE;
    }

    public void sIFi() {
        if (this.proxCaractere == CHAR_I) {
            leProxCaractere();
            sIFf();
        } else if (this.proxCaractereIs(VARIABLE)) {
            leProxCaractere();
            sVARIABLE();
        }
    }

    public void sIFf() {
        if (this.proxCaractere == CHAR_F) {
            leProxCaractere();
            sIF();
        } else if (this.proxCaractereIs(VARIABLE)) {
            leProxCaractere();
            sVARIABLE();
        }
    }

    public void sIF() {
        if (!this.proxCaractereIs(VAZIOS)) {
            leProxCaractere();
            sVARIABLE();
        } else {
            this.tokenReconhecido = Token.IF;
        }
    }

    public void sFORf() {
        if (this.proxCaractere == CHAR_F) {
            leProxCaractere();
            sFORo();
        } else if (this.proxCaractereIs(VARIABLE)) {
            leProxCaractere();
            sVARIABLE();
        }
    }

    public void sFORo() {
        if (this.proxCaractere == CHAR_O) {
            leProxCaractere();
            sFORr();
        } else if (this.proxCaractereIs(VARIABLE)) {
            leProxCaractere();
            sVARIABLE();
        }
    }

    public void sFORr() {
        if (this.proxCaractere == CHAR_R) {
            leProxCaractere();
            sFOR();
        } else if (this.proxCaractereIs(VARIABLE)) {
            leProxCaractere();
            sVARIABLE();
        }
    }

    public void sFOR() {
        if (!this.proxCaractereIs(VAZIOS)) {
            leProxCaractere();
            sVARIABLE();
        } else {
            this.tokenReconhecido = Token.FOR;
        }
    }

    public void sVARIABLE() {
        this.tokenReconhecido = Token.VAR;
        if (this.proxCaractereIs(VARIABLE)) {
            leProxCaractere();
            sVARIABLE();
        }
    }

    public void sEOF() {
        this.tokenReconhecido = Token.EOF;
    }
}
