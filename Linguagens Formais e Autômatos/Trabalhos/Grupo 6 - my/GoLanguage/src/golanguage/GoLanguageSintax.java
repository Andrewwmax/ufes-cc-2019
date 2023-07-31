package golanguage;

import javax.swing.JOptionPane;
public class GoLanguageSintax {

    static public MyAnalisadorSintatico parser;

    public static void main(String[] args) {
        try {
            String s = (String) JOptionPane.showInputDialog(null, "Analisador Sintático", "Digite o Nome do Arquivo", JOptionPane.QUESTION_MESSAGE, null, null, "a.txt");

            parser = new MyAnalisadorSintatico(s);
            parser.inicio();

            JOptionPane.showMessageDialog(null, "Análise realizada com sucesso no arquivo " + parser.nomeArquivoEntrada, "Resultado", JOptionPane.INFORMATION_MESSAGE);
        } catch (ErroLexico e) {
            JOptionPane.showMessageDialog(null, "Erro Léxico: \n" + e.toString(), "Resultado", JOptionPane.ERROR_MESSAGE);
        } catch (ErroSintatico e) {
            JOptionPane.showMessageDialog(null, "Erro Sintático: \n" + e.toString(), "Resultado", JOptionPane.ERROR_MESSAGE);
        } catch (RuntimeException e) {
            JOptionPane.showMessageDialog(null, "Erro\n" + e.getMessage(), "Resultado", JOptionPane.ERROR_MESSAGE);
        }
    }
}
