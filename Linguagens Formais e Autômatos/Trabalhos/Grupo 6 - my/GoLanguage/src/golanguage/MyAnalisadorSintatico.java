package golanguage;

public class MyAnalisadorSintatico extends AnalisadorSintatico {

    public MyAnalisadorSintatico(String _nomeArquivoEntrada) {
        super(_nomeArquivoEntrada);
    }

    public void inicio() {
        corpo();
        reconhece(Token.EOF);
    }

    public void corpo() {
        if (proxTokenIs(Token.IDENT)) {
            comandoAtribuicao();
            reconhece(Token.PTOVIRG);
            corpo();
        } else if (proxTokenIs(Token.EOF)); 
            else {
                Token[] tokensEsperados = {Token.IDENT, Token.EOF};
                throw new ErroSintatico(this.scanner.tokenReconhecido, tokensEsperados);
        }
    }

    public void comandoAtribuicao() {
        reconhece(Token.IDENT);
        reconhece(Token.ATRIB);
        exp();
    }

    public void exp() {
        if (proxTokenIs(Token.NUM)) {
            leProxToken();
        } else if (proxTokenIs(Token.IDENT)) {
            leProxToken();
        } else {
            Token[] tokensEsperados = {Token.NUM, Token.IDENT};
            throw new ErroSintatico(this.scanner.tokenReconhecido, tokensEsperados);
        }
    }
}