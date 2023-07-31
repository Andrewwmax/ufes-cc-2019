package golanguage;

import javax.swing.JOptionPane;

public class GoLanguage {

    static public MyAnalisadorLexico scanner;

    public static void main(String[] args) {
        try {
            String s = (String) JOptionPane.showInputDialog(null, "Analisador Léxico", "Digite o Nome do Arquivo", JOptionPane.QUESTION_MESSAGE, null, null, "a.txt");
            scanner = new MyAnalisadorLexico(s);
            // chama a máquina de Moore várias vezes até encontrar o fim de arquivo
            String cache = new String();
            do {
                scanner.s0();
                System.out.println(scanner.tokenReconhecido);
                cache = cache + scanner.tokenReconhecido + ", ";
            } while (scanner.tokenReconhecido != Constantes.Token.EOF);
            JOptionPane.showMessageDialog(null, cache, "Resultado", JOptionPane.INFORMATION_MESSAGE);
            JOptionPane.showMessageDialog(null, "Análise lexica realizada com sucesso no arquivo " + scanner.nomeArquivoEntrada, "Resultado", JOptionPane.INFORMATION_MESSAGE);
        } catch (ErroLexico e) {
            JOptionPane.showMessageDialog(null, "Erro Léxico: \n" + e.toString(), "Resultado", JOptionPane.ERROR_MESSAGE);
        } catch (RuntimeException e) {
            JOptionPane.showMessageDialog(null, "Erro\n" + e.getMessage(), "Resultado", JOptionPane.ERROR_MESSAGE);
        }
    }
}
